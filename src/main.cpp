
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

#include <QSplashScreen>

#include <ctime>
#include <random>

#include "src/application.h"
#include "src/window.h"

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

    Application app(argc, argv);
    if (app.isRunning())
        return -1;

    QPixmap pixmap(":/res/splash.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    // splash.showMessage("Loading...");
    // app.processEvents();

    MainWindow window;
    QObject::connect(&app, &Application::ActivateWindow,
                     &window, &MainWindow::ActivateWindow);

    window.show();

    splash.finish(&window);

    return app.exec();
}
