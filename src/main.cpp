
#include <QApplication>
#include <QTranslator>
#include <QString>
#include <QLocale>
#include <QThread>
#include <QDateTime>
#include <QSharedMemory>
#include <QMessageBox>
#include <QDebug>
#include <QFont>
#include <QFontDatabase>

#include <iostream>
#include <windows.h>

#include "src/pvz.h"
#include "src/window.h"

// #include <QtPlugin>
// Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
// Q_IMPORT_PLUGIN(QICOPlugin)

int main(int argc, char *argv[])
{
    QString title = QObject::tr("PvZ Tools 1.12.0");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    // font
    QSysInfo::WinVersion wv = QSysInfo::windowsVersion();
    if (wv == QSysInfo::WV_VISTA || wv == QSysInfo::WV_WINDOWS7 || wv == QSysInfo::WV_WINDOWS8 || wv == QSysInfo::WV_WINDOWS8_1 || wv == QSysInfo::WV_WINDOWS10)
    {
        QFont font = app.font();
        font.setPointSize(9);
        font.setFamily("Microsoft YaHei");
        app.setFont(font);
    }

    // single instance
    QSharedMemory shared_memory;
    shared_memory.setKey("42");
    if (shared_memory.attach())
    {
        HWND hwnd_previous_instance = FindWindowA(nullptr, title.toStdString().c_str());
        if (IsIconic(hwnd_previous_instance))
            ShowWindow(hwnd_previous_instance, SW_RESTORE);
        SetForegroundWindow(hwnd_previous_instance);
        SetForegroundWindow(GetLastActivePopup(hwnd_previous_instance));
        return 1; // already running
    }
    else
        shared_memory.create(1);

    // date limit for test version
    QDate date_build(2018, 2, 25);
    QDate date_limit = date_build.addDays(90);
    QDate date_now = QDate::currentDate();
    if (false) // (date_limit < date_now)
    {
        QMessageBox msg_box;
        msg_box.setWindowTitle(QObject::tr("Warning"));
        msg_box.setIcon(QMessageBox::Warning);
        msg_box.setText(QObject::tr("This is a very old beta version."));
        msg_box.setInformativeText(QObject::tr("Check for updates <a href='https://github.com/lmintlcx/PvZTools'>here</a>."));
        msg_box.exec();
        return 2; // expired
    }

    // i18n
    QString locale = QLocale::system().name();
    QTranslator tr_zh_CN;
    tr_zh_CN.load(":/i18n/zh_CN.qm");
    if (true) // (locale == "zh_CN")
        app.installTranslator(&tr_zh_CN);

    MainWindow *window = new MainWindow;
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowTitle(title);
    window->setFixedSize(560, 270);
    window->show();

    return app.exec();
}

// LARGE_INTEGER m_liPerfFreq;
// QueryPerformanceFrequency(&m_liPerfFreq);
// LARGE_INTEGER m_liPerfStart;
// QueryPerformanceCounter(&m_liPerfStart);

// LARGE_INTEGER liPerfNow;
// QueryPerformanceCounter(&liPerfNow);
// int time = (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);
// std::cout << "time " << time << " ms" << std::endl;
