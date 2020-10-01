
#include <QWidget>
#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QTimer>
#include <QLayout>
#include <QThread>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QSettings>
#include <QFontDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QMessageBox>
#include <QLocale>
#include <QDateTime>
#include <QPixmap>
#include <QProcess>
#include <QTranslator>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <string>
#include <array>

#include "src/pvz.h"
#include "src/list.h"
#include "src/pages.h"
#include "src/version.h"
#include "src/window.h"

namespace Pt
{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Worker Thread

    pvz = new PvZ();
    pvz_thread = new QThread(this);
    pak = new PAK();
    pak_thread = new QThread(this);

    // Central Widget

    mainWidget = new QWidget(this);

    listWidget = new QListWidget(mainWidget);
    stackedWidget = new QStackedWidget(mainWidget);

    levelPage = new LevelPage(stackedWidget);
    resourcePage = new ResourcePage(stackedWidget);
    plantsPage = new PlantsPage(stackedWidget);
    zombiesPage = new ZombiesPage(stackedWidget);
    spawnPage = new SpawnPage(stackedWidget);
    slotsPage = new SlotsPage(stackedWidget);
    scenePage = new ScenePage(stackedWidget);
    lineupPage = new LineupPage(stackedWidget);
    gardenPage = new GardenPage(stackedWidget);
    vasePage = new VasePage(stackedWidget);
    effectPage = new EffectPage(stackedWidget);
    othersPage = new OthersPage(stackedWidget);
    statusPage = new StatusPage(stackedWidget);
    spawnCountPage = new SpawnCountPage;
    targetMapPage = new TargetMapPage;
    cannonLauncherPage = new CannonLauncherPage;
    portalPage = new PortalPage;
    izeLineupPage = new IzeLineupPage;
    documentPage = new DocumentPage;

    stackedWidget->addWidget(levelPage);
    stackedWidget->addWidget(resourcePage);
    stackedWidget->addWidget(plantsPage);
    stackedWidget->addWidget(zombiesPage);
    stackedWidget->addWidget(spawnPage);
    stackedWidget->addWidget(slotsPage);
    stackedWidget->addWidget(scenePage);
    stackedWidget->addWidget(lineupPage);
    stackedWidget->addWidget(gardenPage);
    stackedWidget->addWidget(vasePage);
    stackedWidget->addWidget(effectPage);
    stackedWidget->addWidget(othersPage);
    stackedWidget->addWidget(statusPage);

    mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->addWidget(listWidget);
    mainLayout->addWidget(stackedWidget);
    mainLayout->setStretchFactor(listWidget, 1);
    mainLayout->setStretchFactor(stackedWidget, 5);

    setCentralWidget(mainWidget);

    // Menus ToolBars StatusBar

    CreateActions();
    CreateMenus();
    CreateToolBars();
    CreateStatusBar();

    setContextMenuPolicy(Qt::NoContextMenu);

    // Apply Settings

    ReadSettings();

    // Translations

    qt_zh_CN = new QTranslator(this);
    widgets_zh_CN = new QTranslator(this);
    pvztools_zh_CN = new QTranslator(this);

    qt_zh_CN->load(":/translations/qt_zh_CN.qm");
    widgets_zh_CN->load(":/translations/widgets_zh_CN.qm");
    pvztools_zh_CN->load(":/translations/pvztools_zh_CN.qm");

    SetLanguage();
    if (TEST_VERSION) // TODO
        setWindowTitle(tr("Plants vs. Zombies 1.0.0.1051 Toolset") + " " + VERSION_NAME + " " + "beta");
    else
        setWindowTitle(tr("Plants vs. Zombies 1.0.0.1051 Toolset"));

    // Default Page

    listWidget->setCurrentRow(4);
    spawnPageAction->setChecked(true);
    stackedWidget->setCurrentIndex(4);

    // Signals and Slots

    connect(listWidget, &QListWidget::currentRowChanged,
            stackedWidget, &QStackedWidget::setCurrentIndex);

    connect(pageGroup, &QActionGroup::triggered,
            this, [=](QAction *act) {
                QList<QAction *> acts = pageGroup->actions();
                for (int i = 0; i < acts.size(); i++)
                {
                    if (acts[i] == act)
                    {
                        stackedWidget->setCurrentIndex(i);
                        break;
                    }
                }
            });

    connect(stackedWidget, &QStackedWidget::currentChanged,
            this, [=](int index) {
                QList<QAction *> acts = pageGroup->actions();
                acts[index]->setChecked(true);

                listWidget->setCurrentRow(index);
            });

    // // Already called FindPvZ() in next pvz->GameOn().
    // connect(thread, &QThread::started,
    //         pvz, &PvZ::FindPvZ);

    connect(pvz, &PvZ::FindResult,
            this, &MainWindow::FindResult);

    connect(pvz, &PvZ::ShowMessageBox,
            this, &MainWindow::ShowMessageBox);

    connect(pvz, &PvZ::ShowMessageStatusBar,
            this, &MainWindow::ShowMessageStatusBar);

    connect(pak, &PAK::ShowMessageBox,
            this, &MainWindow::ShowMessageBox);

    connect(pak, &PAK::ShowMessageStatusBar,
            this, &MainWindow::ShowMessageStatusBar);

    connect(pvz_thread, &QThread::finished,
            pvz, &QObject::deleteLater);

    connect(pak_thread, &QThread::finished,
            pak, &QObject::deleteLater);

    connect(stackedWidget, &QStackedWidget::currentChanged,
            this, [=](int row) {
                if (statusPage->IsAutoRefresh())
                {
                    if (row == stackedWidget->indexOf(statusPage))
                        statusPage->StartTimer();
                    else
                        statusPage->StopTimer();
                }
            });

    ConnectPages();

    // ...

    QSettings settings;
    bool first_open = settings.value("v2/FirstOpen", true).toBool();
    int lineup_version = settings.value("v2/LineupVersion", 0).toInt();

    if (first_open)
        QTimer::singleShot(1618, documentPage, &QWidget::show);

    QFile file(":/res/lineup_string.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString content = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(content.toUtf8());
    QJsonObject json_object = document.object();
    int version = json_object["version"].toInt();
    if (version > lineup_version)
    {
        lineupPage->InitLineupString();
        lineupPage->RefreshLineupString(); // page create before string for first time
    }

    // ...

    if (pvz->GameOn())
    {
        // TODO
    }

    pvz->moveToThread(pvz_thread);
    pvz_thread->start();
    pak->moveToThread(pak_thread);
    pak_thread->start();
}

MainWindow::~MainWindow()
{
    pvz_thread->quit();
    pvz_thread->wait();
    pak_thread->quit();
    pak_thread->wait();

    WriteSettings();
}

// void MainWindow::changeEvent(QEvent *event)
// {
//     if (event->type() == QEvent::LanguageChange)
//         TranslateUI();
//     else
//         QWidget::changeEvent(event);
// }

// std::tuple<double, double> MainWindow::GetDpiScale()
// {
//     double scale_x = 1.0;
//     double scale_y = 1.0;
//     HDC screen = GetDC(nullptr);
//     if (screen != nullptr)
//     {
//         int dpi_x = GetDeviceCaps(screen, LOGPIXELSX);
//         int dpi_y = GetDeviceCaps(screen, LOGPIXELSY);
//         ReleaseDC(nullptr, screen);
//         const double default_dpi = 96.0;
//         scale_x = dpi_x / default_dpi;
//         scale_y = dpi_y / default_dpi;
//     }
//     return {scale_x, scale_y};
// }

void MainWindow::CreateActions()
{
    openFileAction = new QAction(this);
    openFolderAction = new QAction(this);
    restartAction = new QAction(this);
    exitAction = new QAction(this);

    connect(openFileAction, &QAction::triggered,
            this, [=]() {
                stackedWidget->setCurrentWidget(othersPage);
                othersPage->GetFileName();
            });

    connect(openFolderAction, &QAction::triggered,
            this, [=]() {
                stackedWidget->setCurrentWidget(othersPage);
                othersPage->GetFolderName();
            });

    connect(restartAction, &QAction::triggered,
            this, [=]() {
                qApp->quit();
                QProcess::startDetached(QApplication::applicationFilePath(), QStringList());
            });

    connect(exitAction, &QAction::triggered,
            this, [=]() {
                qApp->quit();
            });

    findGameAction = new QAction(this);
    gameTopMostAction = new QAction(this);
    keepSelectedAction = new QAction(this);

    connect(findGameAction, &QAction::triggered,
            pvz, &PvZ::FindPvZ);

    connect(gameTopMostAction, &QAction::triggered,
            pvz, &PvZ::GameWindowTopMost);

    keepSelectedAction->setCheckable(true);

    keepSelectedAction->setChecked(true);

    levelPageAction = new QAction(this);
    resourcePageAction = new QAction(this);
    plantsPageAction = new QAction(this);
    zombiesPageAction = new QAction(this);
    spawnPageAction = new QAction(this);
    slotsPageAction = new QAction(this);
    scenePageAction = new QAction(this);
    lineupPageAction = new QAction(this);
    gardenPageAction = new QAction(this);
    vasePageAction = new QAction(this);
    effectPageAction = new QAction(this);
    othersPageAction = new QAction(this);
    statusPageAction = new QAction(this);
    spawnCountPageAction = new QAction(this);
    targetMapPageAction = new QAction(this);
    cannonLauncherPageAction = new QAction(this);
    portalPageAction = new QAction(this);
    izeLineupPageAction = new QAction(this);

    connect(spawnCountPageAction, &QAction::triggered,
            this, &MainWindow::ShowSpawnCountPage);

    connect(targetMapPageAction, &QAction::triggered,
            this, &MainWindow::ShowTargetMapPage);

    connect(cannonLauncherPageAction, &QAction::triggered,
            this, &MainWindow::ShowCannonLauncherPage);

    connect(portalPageAction, &QAction::triggered,
            this, &MainWindow::ShowPortalPage);

    connect(izeLineupPageAction, &QAction::triggered,
            this, &MainWindow::ShowIzeLineupPage);

    levelPageAction->setCheckable(true);
    resourcePageAction->setCheckable(true);
    plantsPageAction->setCheckable(true);
    zombiesPageAction->setCheckable(true);
    spawnPageAction->setCheckable(true);
    slotsPageAction->setCheckable(true);
    scenePageAction->setCheckable(true);
    lineupPageAction->setCheckable(true);
    gardenPageAction->setCheckable(true);
    vasePageAction->setCheckable(true);
    effectPageAction->setCheckable(true);
    othersPageAction->setCheckable(true);
    statusPageAction->setCheckable(true);

    pageGroup = new QActionGroup(this);
    pageGroup->addAction(levelPageAction);
    pageGroup->addAction(resourcePageAction);
    pageGroup->addAction(plantsPageAction);
    pageGroup->addAction(zombiesPageAction);
    pageGroup->addAction(spawnPageAction);
    pageGroup->addAction(slotsPageAction);
    pageGroup->addAction(scenePageAction);
    pageGroup->addAction(lineupPageAction);
    pageGroup->addAction(gardenPageAction);
    pageGroup->addAction(vasePageAction);
    pageGroup->addAction(effectPageAction);
    pageGroup->addAction(othersPageAction);
    pageGroup->addAction(statusPageAction);

    showSidebarAction = new QAction(this);
    switchSpawnLayoutAction = new QAction(this);
    limitSpawnCountAction = new QAction(this);
    saveSpawnAction = new QAction(this);
    muteAction = new QAction(this);
    fontAction = new QAction(this);
    restoreDefaultAction = new QAction(this);

    showSidebarAction->setCheckable(true);
    switchSpawnLayoutAction->setCheckable(true);
    limitSpawnCountAction->setCheckable(true);
    saveSpawnAction->setCheckable(true);
    muteAction->setCheckable(true);

    limitSpawnCountAction->setChecked(true);
    saveSpawnAction->setChecked(true);

    connect(showSidebarAction, &QAction::triggered,
            this, &MainWindow::SetNavBar);

    connect(switchSpawnLayoutAction, &QAction::triggered,
            spawnPage, &SpawnPage::SwitchLayout);

    connect(limitSpawnCountAction, &QAction::triggered,
            spawnPage, &SpawnPage::LimitSpawnCount);

    connect(fontAction, &QAction::triggered,
            this, [=]() {
                bool ok;
                QFont font = QFontDialog::getFont(&ok, this);
                if (ok)
                {
                    if (font.pointSize() < 9)
                        font.setPointSize(9);
                    if (font.pointSize() > 12)
                        font.setPointSize(12);
                    QApplication::setFont(font);

                    SetScreenSize();
                }
            });

    connect(restoreDefaultAction, &QAction::triggered,
            this, [=]() {
                showSidebarAction->setChecked(false);
                switchSpawnLayoutAction->setChecked(false);
                limitSpawnCountAction->setChecked(true);
                saveSpawnAction->setChecked(true);
                muteAction->setChecked(false);

                emit showSidebarAction->triggered(false);
                emit switchSpawnLayoutAction->triggered(false);
                emit limitSpawnCountAction->triggered(true);
                emit saveSpawnAction->triggered(true);
                emit muteAction->triggered(false);

                QFont font;
                font.setFamily("Microsoft YaHei");
                font.setPointSize(10);
                font.setBold(false);
                font.setItalic(false);
                QApplication::setFont(font);

                SetScreenSize();
            });

    languageChineseAction = new QAction(this);
    languageEnglishAction = new QAction(this);

    languageChineseAction->setCheckable(true);
    languageEnglishAction->setCheckable(true);

    languageGroup = new QActionGroup(this);
    languageGroup->addAction(languageChineseAction);
    languageGroup->addAction(languageEnglishAction);
    languageChineseAction->setChecked(true);

    connect(languageChineseAction, &QAction::triggered,
            this, &MainWindow::SetLanguage);

    connect(languageEnglishAction, &QAction::triggered,
            this, &MainWindow::SetLanguage);

    helpDocumentAction = new QAction(this);
    videoDemoAction = new QAction(this);
    visitWebsiteAction = new QAction(this);
    sendFeedbackAction = new QAction(this);
    changeLogAction = new QAction(this);
    checkUpdateAction = new QAction(this);
    aboutAction = new QAction(this);
    aboutQtAction = new QAction(this);

    connect(helpDocumentAction, &QAction::triggered,
            this, &MainWindow::ShowDocumentPage);

    connect(videoDemoAction, &QAction::triggered,
            this, [=]() {
                QDesktopServices::openUrl(QUrl("https://pvz.lmintlcx.com/pvztoolsdemo/"));
            });

    connect(visitWebsiteAction, &QAction::triggered,
            this, [=]() {
                QDesktopServices::openUrl(QUrl("https://pvz.lmintlcx.com/tools/"));
            });

    connect(sendFeedbackAction, &QAction::triggered,
            this, [=]() {
                QDesktopServices::openUrl(QUrl("mailto:pvztools@lmintlcx.com"));
            });

    connect(changeLogAction, &QAction::triggered,
            this, [=]() {
                QDesktopServices::openUrl(QUrl("https://github.com/lmintlcx/PvZTools/blob/master/CHANGELOG.md"));
            });

    connect(checkUpdateAction, &QAction::triggered,
            this, [=]() {
                QNetworkAccessManager manager;
                QNetworkRequest request;
                request.setUrl(QUrl("https://pvz.lmintlcx.com/getpvztools/version.txt"));
                request.setRawHeader("User-Agent", PRODUCT_NAME "/" VERSION_NAME " "
                                                                "(" COMPANY_NAME ")");
                request.setRawHeader("Accept-Encoding", "deflate"); // no gzip
                request.setRawHeader("Cache-Control", "no-cache");
                QNetworkReply *reply = manager.get(request);

                // while (!reply->isFinished())
                //     qApp->processEvents();
                QEventLoop loop;
                connect(reply, &QNetworkReply::finished,
                        &loop, &QEventLoop::quit);
                loop.exec();

                if (manager.networkAccessible() == QNetworkAccessManager::NotAccessible)
                {
                    QMessageBox::warning(this, tr("Update Check"), tr("Unable to connect to network."), QMessageBox::Ok);
                    reply->deleteLater();
                    return;
                }

                if (reply->error() == QNetworkReply::NoError)
                {
                    int remote_version = QString(reply->readAll()).toInt();
                    int local_version = VERSION_BUILD;
                    //     qDebug() << "remote_version: " << remote_version;
                    //     qDebug() << "local_version: " << local_version;

                    if (remote_version > local_version)
                    {
                        auto ret = QMessageBox::question(this,                                         //
                                                         tr("Update Check"),                           //
                                                         tr("New version detected, download it now?"), //
                                                         QMessageBox::Yes | QMessageBox::No);          //
                        if (ret == QMessageBox::Yes)
                            QDesktopServices::openUrl(QUrl("https://pvz.lmintlcx.com/tools/"));
                    }
                    else
                    {
                        QMessageBox::information(this, tr("Update Check"), tr("This is already the latest release version."), QMessageBox::Ok);
                    }
                }
                else
                {
                    QMessageBox::warning(this, tr("Update Check"), tr("Error while connecting to update server."), QMessageBox::Ok);
                }

                reply->deleteLater();
            });

    connect(aboutAction, &QAction::triggered,
            this, [=]() {
                QString build_date = QLocale(QLocale::English).toDate(QString(__DATE__).replace("  ", " 0"), "MMM dd yyyy").toString("yyyy/MM/dd");
                QString build_time = QTime::fromString(__TIME__, "hh:mm:ss").toString("hh:mm:ss");

                QString compiler = QString("Unknown");
#ifdef _MSC_VER
                QString msvc_version;
                if (_MSC_VER >= 1910 && _MSC_VER < 1920)
                    msvc_version = "2017";
                else if (_MSC_VER >= 1920 && _MSC_VER < 1930)
                    msvc_version = "2019";
                else
                    ; // TODO
                compiler = QString("Visual Studio") + " " + msvc_version + " " + QString::number(_MSC_VER);
#endif
#ifdef __MINGW32__
                compiler = QString("MinGW-w64/GCC") + " " + QString::number(__GNUC__) + "." + QString::number(__GNUC_MINOR__) + "." + QString::number(__GNUC_PATCHLEVEL__);
#endif
#ifdef __clang__
                compiler = QString("LLVM/Clang") + " " + QString::number(__clang_major__) + "." + QString::number(__clang_minor__) + "." + QString::number(__clang_patchlevel__);
#endif

                QString qt_version = QString("Qt") + " " + QT_VERSION_STR;
                QString ssl_version;
                if (QSslSocket::sslLibraryBuildVersionString().contains("OpenSSL"))
                    ssl_version = QString("OpenSSL") + " " + QSslSocket::sslLibraryBuildVersionString().split(" ")[1];
                else
                    ssl_version = QString("Schannel") + " " + QSslSocket::sslLibraryBuildVersionString();

                QString copyright = QString("") + "©" + " " + (build_date.left(4) == QString("2018") ? QString("2018") : QString("2018") + "-" + build_date.left(4)) + " " + "lmintlcx";

                QString info = QString("<p>")                                                                    //
                               + tr("Version") + ":" + "  " + VERSION_NAME_FULL + "<br>"                         //
                               + tr("Date") + ":" + "  " + build_date + "  " + build_time + "<br>"               //
                               + tr("Toolchain") + ":" + "  " + compiler + "<br>"                                //
                               + qt_version + " + " + ssl_version + "<br>"                                       //
                               + tr("Copyright") + ":" + "  " + copyright + "<br>"                               //
                               + tr("Credit") + ":" + "  " + "a418569882" + "  " + "kmtohoem" + "<br>" + "</p>"; //

                QMessageBox msgBox;
                msgBox.setWindowTitle(tr("About"));
                if (TEST_VERSION)
                    msgBox.setIconPixmap(QPixmap::fromImage(QImage(":/res/logo_about.png").convertToFormat(QImage::Format_Grayscale8)));
                else
                    msgBox.setIconPixmap(QPixmap::fromImage(QImage(":/res/logo_about.png")));
                msgBox.setText(tr("<h1>PvZ Tools</h1>"));
                msgBox.setInformativeText(info);
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
                msgBox.exec();
            });

    connect(aboutQtAction, &QAction::triggered,
            this, [=]() {
                QApplication::aboutQt();
            });
}

void MainWindow::CreateMenus()
{
    fileMenu = new QMenu(this);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(openFolderAction);
    fileMenu->addSeparator();
    fileMenu->addAction(restartAction);
    fileMenu->addAction(exitAction);

    gameMenu = new QMenu(this);
    gameMenu->addAction(findGameAction);
    gameMenu->addAction(gameTopMostAction);
    gameMenu->addSeparator();
    gameMenu->addAction(keepSelectedAction);

    pageMenu = new QMenu(this);
    pageMenu->addActions(pageGroup->actions());
    pageMenu->addSeparator();
    pageMenu->addAction(spawnCountPageAction);
    pageMenu->addAction(targetMapPageAction);
    pageMenu->addAction(cannonLauncherPageAction);
    pageMenu->addAction(portalPageAction);
    pageMenu->addAction(izeLineupPageAction);

    settingMenu = new QMenu(this);
    settingMenu->addAction(showSidebarAction);
    settingMenu->addAction(switchSpawnLayoutAction);
    settingMenu->addAction(limitSpawnCountAction);
    settingMenu->addAction(saveSpawnAction);
    settingMenu->addAction(muteAction);
    settingMenu->addSeparator();
    settingMenu->addAction(fontAction);
    settingMenu->addSeparator();
    settingMenu->addAction(restoreDefaultAction);

    languageMenu = new QMenu(this);
    languageMenu->addActions(languageGroup->actions());

    helpMenu = new QMenu(this);
    helpMenu->addAction(helpDocumentAction);
    helpMenu->addAction(videoDemoAction);
    helpMenu->addSeparator();
    helpMenu->addAction(visitWebsiteAction);
    helpMenu->addAction(sendFeedbackAction);
    helpMenu->addAction(changeLogAction);
    helpMenu->addAction(checkUpdateAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(gameMenu);
    menuBar()->addMenu(pageMenu);
    menuBar()->addMenu(settingMenu);
    menuBar()->addMenu(languageMenu);
    menuBar()->addMenu(helpMenu);
}

void MainWindow::CreateToolBars()
{
    pageToolBar = new QToolBar(this);
    pageToolBar->addActions(pageGroup->actions());
    pageToolBar->setMovable(false);
    pageToolBar->setFloatable(false);
    pageToolBar->setAllowedAreas(Qt::TopToolBarArea);

    addToolBar(pageToolBar);
}

void MainWindow::CreateStatusBar()
{
    theStatuBar = statusBar();

    theStatuBar->setSizeGripEnabled(false);

    permanentMessage = new QLabel(this);
    permanentMessage->setOpenExternalLinks(true);
    permanentMessage->setText("<style>a {text-decoration: none; color: black}</style> <a href=\"https://pvz.lmintlcx.com/\">PvZ Tools</a> by <a href=\"https://www.lmintlcx.com/\">L.Mint. LCX</a> ");

    theStatuBar->addPermanentWidget(permanentMessage);
}

void MainWindow::ConnectPages()
{
    // Level

    connect(levelPage, &LevelPage::GetGoldSunflowerTrophy,
            pvz, &PvZ::GetGoldSunflowerTrophy);

    connect(levelPage, &LevelPage::GetAllShopItems,
            pvz, &PvZ::GetAllShopItems);

    connect(levelPage, &LevelPage::UnlockAllMode,
            pvz, &PvZ::UnlockAllMode);

    connect(levelPage, &LevelPage::DirectWin,
            pvz, &PvZ::DirectWin);

    connect(levelPage, &LevelPage::MixMode,
            pvz, &PvZ::MixMode);

    connect(levelPage, &LevelPage::ShowHiddenGames,
            pvz, &PvZ::ShowHiddenGames);

    connect(levelPage, &LevelPage::LockIZE,
            pvz, &PvZ::LockIZE);

    connect(levelPage, &LevelPage::JumpLevel,
            pvz, &PvZ::JumpLevel);

    // Resource

    connect(resourcePage, &ResourcePage::SetSun,
            pvz, &PvZ::SetSun);

    connect(resourcePage, &ResourcePage::SetSunLimit,
            pvz, &PvZ::SetSunLimit);

    connect(resourcePage, &ResourcePage::SetMoney,
            pvz, &PvZ::SetMoney);

    connect(resourcePage, &ResourcePage::SetMoneyLimit,
            pvz, &PvZ::SetMoneyLimit);

    connect(resourcePage, &ResourcePage::SetFallingSun,
            pvz, &PvZ::SetFallingSun);

    connect(resourcePage, &ResourcePage::AutoCollect,
            pvz, &PvZ::AutoCollect);

    connect(resourcePage, &ResourcePage::ZombieNoFalling,
            pvz, &PvZ::ZombieNoFalling);

    connect(resourcePage, &ResourcePage::GetValue,
            pvz, &PvZ::GetValue);

    connect(resourcePage, &ResourcePage::SetValue,
            pvz, &PvZ::SetValue);

    connect(resourcePage, &ResourcePage::GetDamage,
            pvz, &PvZ::GetDamage);

    connect(resourcePage, &ResourcePage::SetDamage,
            pvz, &PvZ::SetDamage);

    connect(resourcePage, &ResourcePage::GetHP,
            pvz, &PvZ::GetHP);

    connect(resourcePage, &ResourcePage::SetHP,
            pvz, &PvZ::SetHP);

    connect(resourcePage, &ResourcePage::GetTime,
            pvz, &PvZ::GetTime);

    connect(resourcePage, &ResourcePage::SetTime,
            pvz, &PvZ::SetTime);

    connect(pvz, &PvZ::Value,
            resourcePage, &ResourcePage::ShowValue);

    connect(pvz, &PvZ::Damage,
            resourcePage, &ResourcePage::ShowDamage);

    connect(pvz, &PvZ::HP,
            resourcePage, &ResourcePage::ShowHP);

    connect(pvz, &PvZ::Time,
            resourcePage, &ResourcePage::ShowTime);

    // Plants

    connect(plantsPage, &PlantsPage::CobCannonNoCD,
            pvz, &PvZ::CobCannonNoCD);

    connect(plantsPage, &PlantsPage::MagnetsNoCD,
            pvz, &PvZ::MagnetsNoCD);

    connect(plantsPage, &PlantsPage::PotatoMineNoCD,
            pvz, &PvZ::PotatoMineNoCD);

    connect(plantsPage, &PlantsPage::ChomperNoCD,
            pvz, &PvZ::ChomperNoCD);

    connect(plantsPage, &PlantsPage::SetPlantStrength,
            pvz, &PvZ::SetPlantStrength);

    connect(plantsPage, &PlantsPage::LockPult,
            pvz, &PvZ::LockPult);

    connect(plantsPage, &PlantsPage::NoCrater,
            pvz, &PvZ::NoCrater);

    connect(plantsPage, &PlantsPage::MushroomsAwake,
            pvz, &PvZ::MushroomsAwake);

    connect(plantsPage, &PlantsPage::StrongBlover,
            pvz, &PvZ::StrongBlover);

    connect(plantsPage, &PlantsPage::StrongPeas,
            pvz, &PvZ::StrongPeas);

    connect(plantsPage, &PlantsPage::SetPlantExplode,
            pvz, &PvZ::SetPlantExplode);

    connect(plantsPage, &PlantsPage::BeghouledFreeMove,
            pvz, &PvZ::BeghouledFreeMove);

    connect(plantsPage, &PlantsPage::AttackSuperposition,
            pvz, &PvZ::AttackSuperposition);

    connect(plantsPage, &PlantsPage::PlantTorchwood,
            pvz, &PvZ::PlantTorchwood);

    connect(plantsPage, &PlantsPage::PlantGarlic,
            pvz, &PvZ::PlantGarlic);

    connect(plantsPage, &PlantsPage::PlantUmbrella,
            pvz, &PvZ::PlantUmbrella);

    connect(plantsPage, &PlantsPage::PlantPaper,
            pvz, &PvZ::PlantPaper);

    // Zombies

    connect(zombiesPage, &ZombiesPage::SetZombieExplode,
            pvz, &PvZ::SetZombieExplode);

    connect(zombiesPage, &ZombiesPage::SetZombieVisibility,
            pvz, &PvZ::SetZombieVisibility);

    connect(zombiesPage, &ZombiesPage::SetZombieStrength,
            pvz, &PvZ::SetZombieStrength);

    connect(zombiesPage, &ZombiesPage::StopSpawning,
            pvz, &PvZ::StopSpawning);

    connect(zombiesPage, &ZombiesPage::ZombiesNoMove,
            pvz, &PvZ::ZombiesNoMove);

    connect(zombiesPage, &ZombiesPage::NoIceSlowDown,
            pvz, &PvZ::NoIceSlowDown);

    connect(zombiesPage, &ZombiesPage::NoButterImmobilize,
            pvz, &PvZ::NoButterImmobilize);

    connect(zombiesPage, &ZombiesPage::No3zGroup,
            pvz, &PvZ::No3zGroup);

    connect(zombiesPage, &ZombiesPage::NoIceTrail,
            pvz, &PvZ::NoIceTrail);

    connect(zombiesPage, &ZombiesPage::NoThrowImp,
            pvz, &PvZ::NoThrowImp);

    connect(zombiesPage, &ZombiesPage::GargantuarEatable,
            pvz, &PvZ::GargantuarEatable);

    connect(zombiesPage, &ZombiesPage::ZombossNoMove,
            pvz, &PvZ::ZombossNoMove);

    connect(zombiesPage, &ZombiesPage::BalloonBurst,
            pvz, &PvZ::BalloonBurst);

    connect(zombiesPage, &ZombiesPage::GatherZombies,
            pvz, &PvZ::GatherZombies);

    connect(zombiesPage, &ZombiesPage::SpawningNextWave,
            pvz, &PvZ::SpawningNextWave);

    connect(zombiesPage, &ZombiesPage::AllZombiesXXX,
            pvz, &PvZ::AllZombiesXXX);

    // Spawn

    connect(spawnPage, &SpawnPage::InternalSpawn,
            pvz, &PvZ::InternalSpawn);

    connect(spawnPage, &SpawnPage::CustomizeSpawn,
            pvz, &PvZ::CustomizeSpawn);

    connect(spawnPage, &SpawnPage::GetRandomSeed,
            pvz, &PvZ::GetRandomSeed);

    connect(spawnPage, &SpawnPage::SetRandomSeed,
            pvz, &PvZ::SetRandomSeed);

    connect(pvz, &PvZ::RandomSeed,
            spawnPage, &SpawnPage::ShowRandomSeed);

    connect(pvz, &PvZ::SpawnList,
            spawnPage, &SpawnPage::ShowGigaWaves);

    connect(spawnPage, &SpawnPage::ShowSpawnCountPage,
            this, &MainWindow::ShowSpawnCountPage);

    // Slots

    connect(slotsPage, &SlotsPage::SetSlotsCount,
            pvz, &PvZ::SetSlotsCount);

    connect(slotsPage, &SlotsPage::HideSlots,
            pvz, &PvZ::HideSlots);

    connect(slotsPage, &SlotsPage::ShowShovel,
            pvz, &PvZ::ShowShovel);

    connect(slotsPage, &SlotsPage::LockShovel,
            pvz, &PvZ::LockShovel);

    connect(slotsPage, &SlotsPage::GetSeedType,
            pvz, &PvZ::GetSeedType);

    connect(slotsPage, &SlotsPage::SetSeedType,
            pvz, &PvZ::SetSeedType);

    connect(slotsPage, &SlotsPage::GetSeedVisible,
            pvz, &PvZ::GetSeedVisible);

    connect(slotsPage, &SlotsPage::SetSeedVisible,
            pvz, &PvZ::SetSeedVisible);

    connect(slotsPage, &SlotsPage::IgnoreSun,
            pvz, &PvZ::IgnoreSun);

    connect(slotsPage, &SlotsPage::SlotsNoCoolDown,
            pvz, &PvZ::SlotsNoCoolDown);

    connect(slotsPage, &SlotsPage::PurpleSeedUnlimited,
            pvz, &PvZ::PurpleSeedUnlimited);

    connect(slotsPage, &SlotsPage::PlantingFreely,
            pvz, &PvZ::PlantingFreely);

    connect(slotsPage, &SlotsPage::BeltNoDelay,
            pvz, &PvZ::BeltNoDelay);

    connect(slotsPage, &SlotsPage::HideMenuButton,
            pvz, &PvZ::HideMenuButton);

    connect(slotsPage, &SlotsPage::GetSpeed,
            pvz, &PvZ::GetSpeed);

    connect(slotsPage, &SlotsPage::SetSpeed,
            pvz, &PvZ::SetSpeed);

    connect(slotsPage, &SlotsPage::GetCost,
            pvz, &PvZ::GetCost);

    connect(slotsPage, &SlotsPage::SetCost,
            pvz, &PvZ::SetCost);

    connect(slotsPage, &SlotsPage::GetRecharge,
            pvz, &PvZ::GetRecharge);

    connect(slotsPage, &SlotsPage::SetRecharge,
            pvz, &PvZ::SetRecharge);

    connect(pvz, &PvZ::SeedType,
            slotsPage, &SlotsPage::ShowSeedType);

    connect(pvz, &PvZ::SeedImitater,
            slotsPage, &SlotsPage::ShowSeedImitater);

    connect(pvz, &PvZ::SeedVisible,
            slotsPage, &SlotsPage::ShowSeedVisible);

    connect(pvz, &PvZ::Speed,
            slotsPage, &SlotsPage::ShowSpeed);

    connect(pvz, &PvZ::Cost,
            slotsPage, &SlotsPage::ShowCost);

    connect(pvz, &PvZ::Recharge,
            slotsPage, &SlotsPage::ShowRecharge);

    // Scene

    connect(scenePage, &ScenePage::Plant,
            pvz, &PvZ::Plant);

    connect(scenePage, &ScenePage::PutZombie,
            pvz, &PvZ::PutZombie);

    connect(scenePage, &ScenePage::PutGrave,
            pvz, &PvZ::PutGrave);

    connect(scenePage, &ScenePage::PutRake,
            pvz, &PvZ::PutRake);

    connect(scenePage, &ScenePage::PutCoin,
            pvz, &PvZ::PutCoin);

    connect(scenePage, &ScenePage::PutLadder,
            pvz, &PvZ::PutLadder);

    connect(scenePage, &ScenePage::AutoLadder,
            pvz, &PvZ::AutoLadder);

    connect(scenePage, &ScenePage::GetBlockType,
            pvz, &PvZ::GetBlockType);

    connect(scenePage, &ScenePage::SetBlockType,
            pvz, &PvZ::SetBlockType);

    connect(scenePage, &ScenePage::GetRowType,
            pvz, &PvZ::GetRowType);

    connect(scenePage, &ScenePage::SetRowType,
            pvz, &PvZ::SetRowType);

    connect(scenePage, &ScenePage::GetScene,
            pvz, &PvZ::GetScene);

    connect(scenePage, &ScenePage::SetScene,
            pvz, &PvZ::SetScene);

    connect(scenePage, &ScenePage::SetMusic,
            pvz, &PvZ::SetMusic);

    connect(scenePage, &ScenePage::ClearItems, // pvz, &PvZ::ClearItems);
            pvz, static_cast<void (PvZ::*)(int)>(&PvZ::ClearItems));

    connect(scenePage, &ScenePage::StartLawnMowers,
            pvz, &PvZ::StartLawnMowers);

    connect(scenePage, &ScenePage::ClearLawnMowers,
            pvz, &PvZ::ClearLawnMowers);

    connect(scenePage, &ScenePage::ResetLawnMowers,
            pvz, &PvZ::ResetLawnMowers);

    connect(scenePage, &ScenePage::ClearAllPlants,
            pvz, &PvZ::ClearAllPlants);

    connect(scenePage, &ScenePage::AllZombiesXXX,
            pvz, &PvZ::AllZombiesXXX);

    connect(pvz, &PvZ::Scene,
            scenePage, &ScenePage::ShowScene);

    connect(pvz, &PvZ::BlockType,
            scenePage, &ScenePage::ShowBlock);

    connect(pvz, &PvZ::RowType,
            scenePage, &ScenePage::ShowRow);

    // Lineup

    connect(lineupPage, &LineupPage::SetQuickLineupMode,
            resourcePage, &ResourcePage::SetQuickLineupMode);

    connect(lineupPage, &LineupPage::SetQuickLineupMode,
            plantsPage, &PlantsPage::SetQuickLineupMode);

    connect(lineupPage, &LineupPage::SetQuickLineupMode,
            zombiesPage, &ZombiesPage::SetQuickLineupMode);

    connect(lineupPage, &LineupPage::SetQuickLineupMode,
            slotsPage, &SlotsPage::SetQuickLineupMode);

    connect(lineupPage, &LineupPage::SetQuickLineupMode,
            effectPage, &EffectPage::SetQuickLineupMode);

    connect(lineupPage, &LineupPage::QuickPass,
            pvz, &PvZ::QuickPass);

    connect(lineupPage, &LineupPage::MixMode,
            pvz, &PvZ::MixMode);

    connect(lineupPage, &LineupPage::ClearAllGraves,
            pvz, &PvZ::ClearAllGraves);

    connect(lineupPage, &LineupPage::LilyPadOnPool,
            pvz, &PvZ::LilyPadOnPool);

    connect(lineupPage, &LineupPage::FlowerPotOnRoof,
            pvz, &PvZ::FlowerPotOnRoof);

    connect(lineupPage, &LineupPage::ClearAllPlants,
            pvz, &PvZ::ClearAllPlants);

    connect(lineupPage, &LineupPage::SetLineup,
            pvz, &PvZ::SetLineup);

    connect(lineupPage, &LineupPage::SetLineup2,
            pvz, &PvZ::SetLineup2);

    connect(lineupPage, &LineupPage::GetLineup,
            pvz, &PvZ::GetLineup);

    connect(pvz, &PvZ::LineupString,
            lineupPage, &LineupPage::ShowLineup);

    connect(lineupPage, &LineupPage::ShowMessageStatusBar,
            this, &MainWindow::ShowMessageStatusBar);

    // Garden

    connect(gardenPage, &GardenPage::FertilizerUnlimited,
            pvz, &PvZ::FertilizerUnlimited);

    connect(gardenPage, &GardenPage::BugSprayUnlimited,
            pvz, &PvZ::BugSprayUnlimited);

    connect(gardenPage, &GardenPage::ChocolateUnlimited,
            pvz, &PvZ::ChocolateUnlimited);

    connect(gardenPage, &GardenPage::TreeFoodUnlimited,
            pvz, &PvZ::TreeFoodUnlimited);

    connect(gardenPage, &GardenPage::SetTreeHeight,
            pvz, &PvZ::SetTreeHeight);

    connect(gardenPage, &GardenPage::GetGardenPlants,
            pvz, &PvZ::GetGardenPlants);

    connect(gardenPage, &GardenPage::SetGardenPlants,
            pvz, &PvZ::SetGardenPlants);

    connect(pvz, &PvZ::GardenPlants,
            gardenPage, &GardenPage::ShowGardenPlants);

    // Vase

    connect(vasePage, &VasePage::GetVases,
            pvz, &PvZ::GetVases);

    connect(vasePage, &VasePage::SetVases,
            pvz, &PvZ::SetVases);

    connect(pvz, &PvZ::Vases,
            vasePage, &VasePage::ShowVases);

    // Effects

    connect(effectPage, &EffectPage::WisdomTreeCode,
            pvz, &PvZ::WisdomTreeCode);

    connect(effectPage, &EffectPage::KonamiCode,
            pvz, &PvZ::KonamiCode);

    connect(effectPage, &EffectPage::ItsRaining,
            pvz, &PvZ::ItsRaining);

    connect(effectPage, &EffectPage::LittleZombie,
            pvz, &PvZ::LittleZombie);

    connect(effectPage, &EffectPage::ColumnLike,
            pvz, &PvZ::ColumnLike);

    connect(effectPage, &EffectPage::ZombieQuick,
            pvz, &PvZ::ZombieQuick);

    connect(effectPage, &EffectPage::WhackZombie,
            pvz, &PvZ::WhackZombie);

    connect(effectPage, &EffectPage::HighGravity,
            pvz, &PvZ::HighGravity);

    connect(effectPage, &EffectPage::GraveDanger,
            pvz, &PvZ::GraveDanger);

    connect(effectPage, &EffectPage::StormyNight,
            pvz, &PvZ::StormyNight);

    connect(effectPage, &EffectPage::BungeeBlitz,
            pvz, &PvZ::BungeeBlitz);

    connect(effectPage, &EffectPage::GetIceTrailX,
            pvz, &PvZ::GetIceTrailX);

    connect(effectPage, &EffectPage::SetIceTrailX,
            pvz, &PvZ::SetIceTrailX);

    connect(effectPage, &EffectPage::FullFog,
            pvz, &PvZ::FullFog);

    connect(effectPage, &EffectPage::NoFog,
            pvz, &PvZ::NoFog);

    connect(effectPage, &EffectPage::SeeVase,
            pvz, &PvZ::SeeVase);

    connect(pvz, &PvZ::IceTrailX,
            effectPage, &EffectPage::ShowIceTrailX);

    // Others

    connect(othersPage, &OthersPage::DisableSaveData,
            pvz, &PvZ::DisableSaveData);

    connect(othersPage, &OthersPage::DisableDeleteData,
            pvz, &PvZ::DisableDeleteData);

    connect(othersPage, &OthersPage::RunningInBackground,
            pvz, &PvZ::RunningInBackground);

    connect(othersPage, &OthersPage::DisablePause,
            pvz, &PvZ::DisablePause);

    connect(othersPage, &OthersPage::OpenDataDir,
            pvz, &PvZ::OpenDataDir);

    connect(othersPage, &OthersPage::DebugMode,
            pvz, &PvZ::DebugMode);

    connect(othersPage, &OthersPage::UnpackPAK,
            pak, &PAK::UnpackPAK);

    connect(othersPage, &OthersPage::PackPAK,
            pak, &PAK::PackPAK);

    connect(pak, &PAK::UnpackFinished,
            othersPage, &OthersPage::UnpackFinished);

    connect(pak, &PAK::PackFinished,
            othersPage, &OthersPage::PackFinished);

    connect(othersPage, &OthersPage::ShowTargetMapPage,
            this, &MainWindow::ShowTargetMapPage);

    connect(othersPage, &OthersPage::ShowCannonLauncherPage,
            this, &MainWindow::ShowCannonLauncherPage);

    connect(othersPage, &OthersPage::ShowPortalPage,
            this, &MainWindow::ShowPortalPage);

    connect(othersPage, &OthersPage::ShowIzeLineupPage,
            this, &MainWindow::ShowIzeLineupPage);

    // Status

    connect(statusPage, &StatusPage::GetStatus,
            pvz, &PvZ::GetStatus);

    connect(pvz, &PvZ::GameStatus,
            statusPage, &StatusPage::ShowStatus);

    // SpawnCount

    connect(spawnCountPage, &SpawnCountPage::GetSpawnList,
            pvz, &PvZ::GetSpawnList);

    connect(pvz, &PvZ::SpawnList,
            spawnCountPage, &SpawnCountPage::UpdateSpawnCount);

    // Target Map

    connect(targetMapPage, &TargetMapPage::GetTargetMap,
            pvz, &PvZ::GetTargetMap);

    connect(targetMapPage, &TargetMapPage::SetTargetMap,
            pvz, &PvZ::SetTargetMap);

    connect(pvz, &PvZ::TargetMap,
            targetMapPage, &TargetMapPage::ShowTargetMap);

    // Cannon Launcher

    connect(cannonLauncherPage, &CannonLauncherPage::GetCobInfo,
            pvz, &PvZ::GetCobInfo);

    connect(cannonLauncherPage, &CannonLauncherPage::GetScene,
            pvz, &PvZ::GetScene);

    connect(cannonLauncherPage, &CannonLauncherPage::LaunchCannon,
            pvz, &PvZ::LaunchCannon);

    connect(cannonLauncherPage, &CannonLauncherPage::LaunchAllCannon,
            pvz, &PvZ::LaunchAllCannon);

    connect(pvz, &PvZ::CobInfo,
            cannonLauncherPage, &CannonLauncherPage::ShowCobInfo);

    connect(pvz, &PvZ::Scene,
            cannonLauncherPage, &CannonLauncherPage::CalculateCoord);

    // Portal

    connect(portalPage, &PortalPage::StartPortal,
            pvz, &PvZ::StartPortal);

    connect(portalPage, &PortalPage::LockPortal,
            pvz, &PvZ::LockPortal);

    connect(portalPage, &PortalPage::SetPortal,
            pvz, &PvZ::SetPortal);

    // I, Zombie Endless

    connect(izeLineupPage, &IzeLineupPage::GetIzeLineup,
            pvz, &PvZ::GetIzeLineup);

    connect(izeLineupPage, &IzeLineupPage::SetIzeLineup,
            pvz, &PvZ::SetIzeLineup);

    connect(pvz, &PvZ::IzeLineup,
            izeLineupPage, &IzeLineupPage::ShowIzeLineup);
}

void MainWindow::ReadSettings()
{
    QSettings settings;

    settings.beginGroup("v2");

    bool keep_selected = settings.value("KeepSelectedFeatures", true).toBool();
    keepSelectedAction->setChecked(keep_selected);
    // emit keepSelectedAction->triggered(keep_selected);

    bool sidebar_visible = settings.value("ShowSidebar", false).toBool();
    showSidebarAction->setChecked(sidebar_visible);
    emit showSidebarAction->triggered(sidebar_visible);

    bool another_layout = settings.value("SwitchAnotherLayout", false).toBool();
    switchSpawnLayoutAction->setChecked(another_layout);
    emit switchSpawnLayoutAction->triggered(another_layout);

    bool limit_count = settings.value("LimitSpawnCount", true).toBool();
    limitSpawnCountAction->setChecked(limit_count);
    emit limitSpawnCountAction->triggered(limit_count);

    bool save_spawn = settings.value("SaveSpawnTypes", true).toBool();
    saveSpawnAction->setChecked(save_spawn);
    // emit saveSpawnAction->triggered(save_spawn);

    if (save_spawn)
    {
        QString brief_zombies_str = settings.value("SpawnTypesBrief", QString("")).toString();
        QString detailed_zombies_str = settings.value("SpawnTypesDetailed", QString("")).toString();
        if (brief_zombies_str.length() == 33 && detailed_zombies_str.length() == 33)
        {
            std::array<bool, 33> brief_zombies = {false};
            std::array<bool, 33> detailed_zombies = {false};
            for (size_t i = 0; i < 33; i++)
            {
                brief_zombies[i] = (brief_zombies_str.at(i) == QString("0") ? false : true);
                detailed_zombies[i] = (detailed_zombies_str.at(i) == QString("0") ? false : true);
            }
            spawnPage->SetBriefZombies(brief_zombies);
            spawnPage->SetDetailedZombies(detailed_zombies);
        }
    }

    bool mute = settings.value("MuteSound", false).toBool();
    muteAction->setChecked(mute);
    // emit muteAction->triggered(mute);

    QString font_family = settings.value("FontFamily", QString("Microsoft YaHei")).toString();
    int font_size = settings.value("FontSize", 10).toInt();
    bool font_bold = settings.value("FontBold", false).toBool();
    bool font_italic = settings.value("FontItalic", false).toBool();

    QFont font;
    font.setFamily(font_family);
    font.setPointSize(font_size);
    font.setBold(font_bold);
    font.setItalic(font_italic);
    QApplication::setFont(font);

    QString language = settings.value("Language", QString("")).toString();
    if (language == QString("简体中文"))
        languageChineseAction->setChecked(true);
    else if (language == QString("English"))
        languageEnglishAction->setChecked(true);
    else // first run
    {
        QString locale = QLocale::system().name();
        if (locale.left(2) == "zh")
            languageChineseAction->setChecked(true);
        else
            languageEnglishAction->setChecked(true);
    }

    settings.endGroup();
}

void MainWindow::WriteSettings()
{
    QSettings settings;

    settings.beginGroup("v2");

    settings.setValue("FirstOpen", false);

    settings.setValue("KeepSelectedFeatures", keepSelectedAction->isChecked());

    settings.setValue("ShowSidebar", showSidebarAction->isChecked());

    settings.setValue("SwitchAnotherLayout", switchSpawnLayoutAction->isChecked());

    settings.setValue("LimitSpawnCount", limitSpawnCountAction->isChecked());

    settings.setValue("SaveSpawnTypes", saveSpawnAction->isChecked());

    if (saveSpawnAction->isChecked())
    {
        auto brief_zombies = spawnPage->GetBriefZombies();
        auto detailed_zombies = spawnPage->GetDetailedZombies();
        QString brief_zombies_str;
        QString detailed_zombies_str;
        for (size_t i = 0; i < 33; i++)
        {
            brief_zombies_str += (brief_zombies[i] ? "1" : "0");
            detailed_zombies_str += (detailed_zombies[i] ? "1" : "0");
        }
        settings.setValue("SpawnTypesBrief", brief_zombies_str);
        settings.setValue("SpawnTypesDetailed", detailed_zombies_str);
    }

    settings.setValue("MuteSound", muteAction->isChecked());

    settings.setValue("FontFamily", QApplication::font().family());
    settings.setValue("FontSize", QApplication::font().pointSize());
    settings.setValue("FontBold", QApplication::font().bold());
    settings.setValue("FontItalic", QApplication::font().italic());

    QString language;
    if (languageChineseAction->isChecked())
        language = "简体中文";
    else
        language = "English";
    settings.setValue("Language", language);

    settings.endGroup();
}

void MainWindow::SetNavBar(bool show_sidebar)
{
    if (show_sidebar)
    {
        listWidget->setVisible(true);
        pageToolBar->setVisible(false);
    }
    else
    {
        listWidget->setVisible(false);
        pageToolBar->setVisible(true);
    }

    SetScreenSize();
}

void MainWindow::SetLanguage()
{
    // Hack 1/2
    auto zombie = spawnPage->GetDetailedZombies();

    QList<QTranslator *> trs = this->findChildren<QTranslator *>(QString(), Qt::FindDirectChildrenOnly);
    for (int i = 0; i < trs.size(); i++)
        qApp->removeTranslator(trs[i]);

    if (languageChineseAction->isChecked()) // 简体中文
    {
        qApp->installTranslator(qt_zh_CN);
        qApp->installTranslator(widgets_zh_CN);
        qApp->installTranslator(pvztools_zh_CN);
    }
    else
    {
        // TODO
    }

    // Call TranslateUI() manually
    // instead of using QEvent::LanguageChange
    List::Get().Init();
    TranslateUI();
    levelPage->TranslateUI();
    resourcePage->TranslateUI();
    plantsPage->TranslateUI();
    zombiesPage->TranslateUI();
    spawnPage->TranslateUI();
    slotsPage->TranslateUI();
    scenePage->TranslateUI();
    lineupPage->TranslateUI();
    gardenPage->TranslateUI();
    vasePage->TranslateUI();
    effectPage->TranslateUI();
    othersPage->TranslateUI();
    statusPage->TranslateUI();
    spawnCountPage->TranslateUI();
    targetMapPage->TranslateUI();
    cannonLauncherPage->TranslateUI();
    portalPage->TranslateUI();
    izeLineupPage->TranslateUI();
    documentPage->TranslateUI();

    // Hack 2/2
    spawnPage->SetDetailedZombies(zombie);

    SetScreenSize();
}

void MainWindow::SetScreenSize()
{
    int x, y;
    // auto [scale_x, scale_y] = GetDpiScale();
    auto [scale_x, scale_y] = std::tuple<double, double>{1.0, 1.0};
    double font_scale = qApp->font().pointSize() / 10.0;
    bool sidebar_visible = showSidebarAction->isChecked();

    if (languageChineseAction->isChecked())
    {
        x = (610 + (sidebar_visible ? 80 : 0)) * scale_x * font_scale;
        y = (380 + (sidebar_visible ? -25 : 0)) * scale_y * font_scale;
        this->setFixedSize(x, y);
        x = 720 * scale_x * font_scale;
        y = 430 * scale_y * font_scale;
        spawnCountPage->setFixedWidth(x);
        spawnCountPage->setMinimumHeight(y);
        x = 940 * scale_x * font_scale;
        y = 250 * scale_y * font_scale;
        targetMapPage->setFixedSize(x, y);
        x = 380 * scale_x * font_scale;
        y = 150 * scale_y * font_scale;
        cannonLauncherPage->setFixedSize(x, y);
        x = 400 * scale_x * font_scale;
        y = 120 * scale_y * font_scale;
        portalPage->setFixedSize(x, y);
        x = 540 * scale_x * font_scale;
        y = 280 * scale_y * font_scale;
        izeLineupPage->setFixedSize(x, y);
        x = 610 * scale_x * font_scale;
        y = 420 * scale_y * font_scale;
        documentPage->setFixedSize(x, y);
    }
    else if (languageEnglishAction->isChecked())
    {
        x = (900 + (sidebar_visible ? 100 : 0)) * scale_x * font_scale;
        y = (380 + (sidebar_visible ? -25 : 0)) * scale_y * font_scale;
        this->setFixedSize(x, y);
        x = 820 * scale_x * font_scale;
        y = 430 * scale_y * font_scale;
        spawnCountPage->setFixedWidth(x);
        spawnCountPage->setMinimumHeight(y);
        x = 1280 * scale_x * font_scale;
        y = 250 * scale_y * font_scale;
        targetMapPage->setFixedSize(x, y);
        x = 400 * scale_x * font_scale;
        y = 150 * scale_y * font_scale;
        cannonLauncherPage->setFixedSize(x, y);
        x = 450 * scale_x * font_scale;
        y = 120 * scale_y * font_scale;
        portalPage->setFixedSize(x, y);
        x = 690 * scale_x * font_scale;
        y = 280 * scale_y * font_scale;
        izeLineupPage->setFixedSize(x, y);
        x = 600 * scale_x * font_scale;
        y = 420 * scale_y * font_scale;
        documentPage->setFixedSize(x, y);
    }
}

void MainWindow::TranslateUI()
{
    if (listWidget->count() == 0)
        listWidget->addItems(List::Get().pageList);
    else
        for (int i = 0; i < listWidget->count(); i++)
            listWidget->item(i)->setText(List::Get().pageList[i]);

    openFileAction->setText(tr("Open File"));
    openFolderAction->setText(tr("Open Folder"));
    restartAction->setText(tr("Restart"));
    exitAction->setText(tr("Exit"));

    findGameAction->setText(tr("Find Game Again"));
    gameTopMostAction->setText(tr("Game Window Top Most"));
    keepSelectedAction->setText(tr("Keep Selected Features"));

    levelPageAction->setText(List::Get().pageList[0]);
    resourcePageAction->setText(List::Get().pageList[1]);
    plantsPageAction->setText(List::Get().pageList[2]);
    zombiesPageAction->setText(List::Get().pageList[3]);
    spawnPageAction->setText(List::Get().pageList[4]);
    slotsPageAction->setText(List::Get().pageList[5]);
    scenePageAction->setText(List::Get().pageList[6]);
    lineupPageAction->setText(List::Get().pageList[7]);
    gardenPageAction->setText(List::Get().pageList[8]);
    vasePageAction->setText(List::Get().pageList[9]);
    effectPageAction->setText(List::Get().pageList[10]);
    othersPageAction->setText(List::Get().pageList[11]);
    statusPageAction->setText(List::Get().pageList[12]);
    spawnCountPageAction->setText(tr("Spawning Counting"));
    targetMapPageAction->setText(tr("Target Map Modify"));
    cannonLauncherPageAction->setText(tr("Cannon Launcher"));
    portalPageAction->setText(tr("Portal"));
    izeLineupPageAction->setText(tr("I, Zombie Endless"));

    showSidebarAction->setText(tr("Show Sidebar"));
    switchSpawnLayoutAction->setText(tr("Switch Spawn Layout"));
    limitSpawnCountAction->setText(tr("Limit Spawn Species"));
    saveSpawnAction->setText(tr("Save Selected Species"));
    muteAction->setText(tr("Mute"));
    fontAction->setText(tr("Font") + "...");
    restoreDefaultAction->setText(tr("Restore Default Setting"));

    languageChineseAction->setText("简体中文");
    languageEnglishAction->setText("English");

    helpDocumentAction->setText(tr("Help Document"));
    videoDemoAction->setText(tr("Video Demo"));
    visitWebsiteAction->setText(tr("Visit Website"));
    sendFeedbackAction->setText(tr("Send Feedback"));
    changeLogAction->setText(tr("Change Log"));
    checkUpdateAction->setText(tr("Check Update"));
    aboutAction->setText(tr("About PvZ Tools"));
    aboutQtAction->setText(tr("About Qt"));

    fileMenu->setTitle(tr("&File"));
    gameMenu->setTitle(tr("&Game"));
    pageMenu->setTitle(tr("&Page"));
    settingMenu->setTitle(tr("&Setting"));
    languageMenu->setTitle(tr("&Language"));
    helpMenu->setTitle(tr("&Help"));

    pageToolBar->setWindowTitle(tr("Page"));
}

void MainWindow::FindResult(Result result)
{
    if (result == Result::OK)
    {
        ShowMessageStatusBar(tr("Game Found."));

        resourcePage->UpdateGameData();
        slotsPage->UpdateGameData();

        if (keepSelectedAction->isChecked())
        {
            othersPage->KeepSelectedFeatures(); // first
            lineupPage->KeepSelectedFeatures(); // first
            levelPage->KeepSelectedFeatures();
            resourcePage->KeepSelectedFeatures();
            plantsPage->KeepSelectedFeatures();
            zombiesPage->KeepSelectedFeatures();
            slotsPage->KeepSelectedFeatures();
            gardenPage->KeepSelectedFeatures();
            effectPage->KeepSelectedFeatures();
        }
    }
    else if (result == Result::WrongVersion)
    {
        ShowMessageStatusBar(tr("Unsupported game version."));
        statusPage->StopTimer(true);
    }
    else if (result == Result::NotFound)
    {
        ShowMessageStatusBar(tr("Game window not found."));
        statusPage->StopTimer(true);
    }
    else if (result == Result::OpenError)
    {
        ShowMessageStatusBar(tr("Open game process error."));
        statusPage->StopTimer(true);
    }
}

void MainWindow::ShowSpawnCountPage()
{
    if (spawnCountPage->isVisible())
    {
        spawnCountPage->hide();
    }
    else
    {
        spawnCountPage->show();
        Sleep(20);
        emit spawnCountPage->GetSpawnList();
    }
}

void MainWindow::ShowTargetMapPage()
{
    if (targetMapPage->isVisible())
    {
        targetMapPage->hide();
    }
    else
    {
        targetMapPage->show();
    }
}

void MainWindow::ShowCannonLauncherPage()
{
    if (cannonLauncherPage->isVisible())
    {
        cannonLauncherPage->hide();
    }
    else
    {
        cannonLauncherPage->show();
    }
}

void MainWindow::ShowPortalPage()
{
    if (portalPage->isVisible())
    {
        portalPage->hide();
    }
    else
    {
        portalPage->show();
    }
}

void MainWindow::ShowIzeLineupPage()
{
    if (izeLineupPage->isVisible())
    {
        izeLineupPage->hide();
    }
    else
    {
        izeLineupPage->show();
    }
}

void MainWindow::ShowDocumentPage()
{
    if (documentPage->isVisible())
    {
        documentPage->hide();
    }
    else
    {
        documentPage->show();
    }
}

void MainWindow::ActivateWindow()
{
    showNormal();
    raise();
    activateWindow();
}

void MainWindow::ShowMessageBox(QString msg)
{
    QMessageBox::information(this, tr("Message"), msg, QMessageBox::Ok);
}

void MainWindow::ShowMessageStatusBar(QString msg)
{
    const int display_time = 0x1437;
    statusBar()->showMessage(msg, display_time);
    if (!muteAction->isChecked())
        QApplication::beep();
}

} // namespace Pt
