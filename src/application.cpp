
#include <QApplication>
#include <QLocalSocket>
#include <QLocalServer>
#include <QDate>
#include <QMessageBox>

#include "src/version.h"
#include "src/application.h"

namespace Pt
{

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
