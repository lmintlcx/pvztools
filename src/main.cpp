
#define EVERYTHING 42

#include <ctime>
#include <random>

#include "src/application.h"
#include "src/window.h"

// static_assert(sizeof(void *) == 4);

using Pt::Application;
using Pt::MainWindow;

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
