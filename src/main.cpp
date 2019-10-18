
#define EVERYTHING 42

#include <ctime>
#include <random>

#include "src/application.h"
#include "src/window.h"

// 32-bit only
static_assert(sizeof(void *) == 4);

// C++17
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

// #include <QtPlugin>
// Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin) // 5.6 / 5.12
// Q_IMPORT_PLUGIN(QGenericEnginePlugin)      // 5.12
// Q_IMPORT_PLUGIN(QWindowsVistaStylePlugin)  // 5.12

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    std::wcout.imbue(std::locale("chs"));
#endif

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Application app(argc, argv);
    if (app.isRunning())
        return -1;

    MainWindow window;
    QObject::connect(&app, &Application::ActivateWindow,
                     &window, &MainWindow::ActivateWindow);

    window.show();

    return app.exec();
}
