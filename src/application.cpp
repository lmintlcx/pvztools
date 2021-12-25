
#include <QApplication>
#include <QLocalSocket>
#include <QLocalServer>
#include <QDate>
#include <QMessageBox>

#include <Windows.h>
#include <WinTrust.h>
#include <SoftPub.h>

#include "src/version.h"
#include "src/application.h"

namespace Pt
{

bool VerifySignature(LPCWSTR pwszSourceFile)
{
    bool isGoodSignature = false;

    WINTRUST_FILE_INFO FileData;
    memset(&FileData, 0, sizeof(FileData));
    FileData.cbStruct = sizeof(WINTRUST_FILE_INFO);
    FileData.pcwszFilePath = pwszSourceFile;
    FileData.hFile = NULL;
    FileData.pgKnownSubject = NULL;

    GUID WVTPolicyGUID = WINTRUST_ACTION_GENERIC_VERIFY_V2;
    WINTRUST_DATA WinTrustData;
    memset(&WinTrustData, 0, sizeof(WinTrustData));
    WinTrustData.cbStruct = sizeof(WinTrustData);
    WinTrustData.pPolicyCallbackData = NULL;
    WinTrustData.pSIPClientData = NULL;
    WinTrustData.dwUIChoice = WTD_UI_NONE;
    WinTrustData.fdwRevocationChecks = WTD_REVOKE_NONE;
    WinTrustData.dwUnionChoice = WTD_CHOICE_FILE;
    WinTrustData.dwStateAction = WTD_STATEACTION_VERIFY;
    WinTrustData.hWVTStateData = NULL;
    WinTrustData.pwszURLReference = NULL;
    WinTrustData.dwUIContext = 0;
    WinTrustData.pFile = &FileData;

    LONG lStatus = WinVerifyTrust(NULL, &WVTPolicyGUID, &WinTrustData);
    // wprintf_s(L"WinVerifyTrust lStatus is: 0x%x.\n", lStatus);

    [[maybe_unused]] bool sig_good = (lStatus == ERROR_SUCCESS || lStatus == CERT_E_CHAINING || lStatus == TRUST_E_COUNTER_SIGNER);
    [[maybe_unused]] bool sig_not_bad = (lStatus != TRUST_E_NOSIGNATURE && lStatus != TRUST_E_BAD_DIGEST);
    isGoodSignature = sig_not_bad; // TODO

    WinTrustData.dwStateAction = WTD_STATEACTION_CLOSE;
    lStatus = WinVerifyTrust(NULL, &WVTPolicyGUID, &WinTrustData);

    if (!isGoodSignature)
        return false;

    HCERTSTORE hStore = NULL;
    HCRYPTMSG hMsg = NULL;
    CryptQueryObject(CERT_QUERY_OBJECT_FILE, pwszSourceFile,     //
                     CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED, //
                     CERT_QUERY_FORMAT_FLAG_BINARY,              //
                     0, NULL, NULL, NULL, &hStore, &hMsg, NULL);

    DWORD dwSignerInfo = 0;
    CryptMsgGetParam(hMsg, CMSG_SIGNER_INFO_PARAM, 0, NULL, &dwSignerInfo);
    PCMSG_SIGNER_INFO pSignerInfo = (PCMSG_SIGNER_INFO)LocalAlloc(LPTR, dwSignerInfo);
    CryptMsgGetParam(hMsg, CMSG_SIGNER_INFO_PARAM, 0, (PVOID)pSignerInfo, &dwSignerInfo);

    CERT_INFO CertInfo;
    memset(&CertInfo, 0, sizeof(CertInfo));
    CertInfo.Issuer = pSignerInfo->Issuer;
    CertInfo.SerialNumber = pSignerInfo->SerialNumber;
    PCCERT_CONTEXT pCertContext =                                                   //
        CertFindCertificateInStore(hStore, X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, //
                                   0, CERT_FIND_SUBJECT_CERT, (PVOID)&CertInfo, NULL);

    const DWORD size = 16;
    if (pCertContext->pCertInfo->SerialNumber.cbData == size)
    {
        char snRead[size + 1];
        for (DWORD i = 0; i < size; i++)
            snRead[i] = pCertContext->pCertInfo->SerialNumber.pbData[size - (i + 1)];
        snRead[size] = 0;
        char snCheck[] = "\x21\x13\x67\x0f\x3b\x6c\x60\xaf\x42\x50\x7f\x07\xd3\x97\xbc\xd6";
        isGoodSignature = strcmp(snRead, snCheck) == 0;
    }
    else
    {
        isGoodSignature = false;
    }

    CertFreeCertificateContext(pCertContext);
    CertCloseStore(hStore, 0);
    CryptMsgClose(hMsg);
    LocalFree(pSignerInfo);

    return isGoodSignature;
}

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv)
{
    if (TEST_VERSION) // time limit for test version
    {
        QDate date_build = QLocale(QLocale::English).toDate(QString(__DATE__).replace("  ", " 0"), "MMM dd yyyy");
        QDate date_limit = date_build.addDays(365);
        QDate date_now = QDate::currentDate();
        if (date_now > date_limit)
        {
            QMessageBox msg_box;
            msg_box.setWindowTitle("Attention!");
            msg_box.setIcon(QMessageBox::Warning);
            msg_box.setText("<style>a {text-decoration: none; color: blue}</style>"
                            "This is a very old beta version, please download new version <a href='https://pvz.lmintlcx.com/tools/'>here</a>."
                            "<br>"
                            "这是很旧很旧的测试版哦, 去 <a href='https://pvz.lmintlcx.com/tools/'>这里</a> 下载最新版吧.");
            msg_box.exec();

            // qApp->quit();
            // return;
        }
    }

    // 防篡改检测
    if (SIGNATURE_CHECK)
    {
        wchar_t exePath[MAX_PATH] = {0};
        GetModuleFileNameW(NULL, exePath, MAX_PATH);
        if (!VerifySignature(exePath))
        {
            if (MessageBoxW(nullptr, L"本程序可能已经感染病毒，请在官方渠道重新下载！", //
                            L"PvZ Tools 防篡改检测", MB_OKCANCEL) == IDOK)
                ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/tools/", //
                              nullptr, nullptr, SW_SHOWNORMAL);
            qApp->quit();
            return;
        }
    }

    QCoreApplication::setOrganizationName(COMPANY_NAME);
    QCoreApplication::setOrganizationDomain(COMPANY_WEBSITE);
    QCoreApplication::setApplicationName(PRODUCT_NAME);
    QCoreApplication::setApplicationVersion(VERSION_NAME);

    QString serverName = QCoreApplication::organizationName() + " / " + QCoreApplication::applicationName();

    QLocalSocket socket;
    socket.connectToServer(serverName);

    if (socket.waitForConnected(500))
    {
        server = nullptr;

        QTextStream stream(&socket);
        stream << "42";
        stream.flush();

        socket.waitForBytesWritten();

        _isRunning = true;
    }
    else
    {
        server = new QLocalServer(this);
        connect(server, &QLocalServer::newConnection,
                this, &Application::NewLocalConnection);

        if (!server->listen(serverName))
        {
            if ((server->serverError() == QAbstractSocket::AddressInUseError))
            {
                QLocalServer::removeServer(server->serverName());
                server->listen(serverName);
            }
        }

        _isRunning = false;
    }
}

Application::~Application()
{
}

bool Application::isRunning()
{
    return _isRunning;
}

void Application::NewLocalConnection()
{
    QLocalSocket *socket = server->nextPendingConnection();
    if (socket->waitForReadyRead(1000))
    {
        QTextStream in(socket);
        QString strValue;
        in >> strValue;

        if (strValue == "42")
            emit ActivateWindow();

        delete socket;
    }
}

} // namespace Pt
