
#define EVERYTHING 42

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "uuid.lib")
#pragma comment(lib, "odbc32.lib")
#pragma comment(lib, "odbccp32.lib")
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "crypt32.lib")

#include <QSplashScreen>
#include <QSettings>
#include <QFileInfo>

#include <ctime>
#include <random>

#include "src/application.h"
#include "src/window.h"
#include "src/version.h"

// 编译器目标平台限制为 x86
// 因为目标应用 (植物大战僵尸1 PC版) 本身是 x86 的
// 修改器也不需要 x64 的任何优势, 反而增加体积
// 以及 Visual Studio 不支持 x64 内联汇编
static_assert(sizeof(void *) == 4);

// 要求编译器支持 C++17
#ifdef _MSC_VER
static_assert(_MSC_VER >= 1914);
#endif
#ifdef __MINGW32__
static_assert(__GNUC__ >= 7);
#endif
#ifdef __clang__
static_assert(__clang_major__ >= 6);
#endif

using Pt::Application;
using Pt::MainWindow;

#ifdef QT_STATIC
#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin) // 必须
Q_IMPORT_PLUGIN(QWindowsVistaStylePlugin)  // 必须
Q_IMPORT_PLUGIN(QJpegPlugin)               // 必须
Q_IMPORT_PLUGIN(QICOPlugin)                // 非必须
Q_IMPORT_PLUGIN(QGenericEnginePlugin)      // 非必须
#endif

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    std::wcout.imbue(std::locale("chs"));
#endif

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 开启高 DPI 缩放支持
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    Application app(argc, argv);
    if (app.isRunning())
        return -1;

    QString splash_filename = ":/res/logo.ico";
    if (QFileInfo::QFileInfo("splash.jpg").isFile())
        splash_filename = "splash.jpg";
    QImage image = QImage(splash_filename);
    if (TEST_VERSION)
        image = image.convertToFormat(QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(image);
    QSplashScreen splash(pixmap);
    splash.show();
    // splash.showMessage("Loading...");
    // app.processEvents();

    HKEY hKey;
    DWORD ret = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Tools", 0, KEY_READ, &hKey);
    if (ret == ERROR_SUCCESS)
    {
        // 转移并删除旧版本的注册表配置
        // 放在 MainWindow 构造之前, Application 之后
        QSettings settings_old;
        if (settings_old.childGroups().contains("v2"))
        {
            QSettings settings("pvztools.ini", QSettings::IniFormat);
            for (auto k : settings_old.allKeys())
                settings.setValue(k, settings_old.value(k));
            settings_old.remove("v2");
        }

        RegCloseKey(hKey);
    }

    MainWindow window;
    QObject::connect(&app, &Application::ActivateWindow,
                     &window, &MainWindow::ActivateWindow);

    window.show();

    splash.finish(&window);

    return app.exec();
}
