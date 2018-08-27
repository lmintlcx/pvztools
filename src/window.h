/*
 * @Author: lmintlcx 
 * @Date: 2018-07-02 17:55:52 
 * @Description: Main Window.
 */

#pragma once

#include <QMainWindow>

#include "src/pvz.h"
#include "src/pages.h"

class QAction;
class QActionGroup;
class QMenu;
class QToolBar;
class QThread;
class QWidget;
class QListWidget;
class QStackedWidget;
class QHBoxLayout;
class QTranslator;

namespace Pt
{

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  // protected:
  //   void changeEvent(QEvent *);

private:
  std::tuple<double, double> GetDpiScale();
  void CreateActions();
  void CreateMenus();
  void CreateToolBars();
  void CreateStatusBar();
  void ConnectPages();
  void ReadSettings();
  void WriteSettings();
  void SetNavBar(bool);
  void SetLanguage();
  void SetScreenSize();
  void TranslateUI();
  void FindResult(Result);
  void ShowTargetMapPage();
  void ShowCannonLauncherPage();
  void ShowDocumentPage();

private:
  QAction *openFileAction;
  QAction *openFolderAction;
  QAction *restartAction;
  QAction *exitAction;

  QAction *findGameAction;

  QAction *levelPageAction;
  QAction *resourcePageAction;
  QAction *plantsPageAction;
  QAction *zombiesPageAction;
  QAction *spawnPageAction;
  QAction *slotsPageAction;
  QAction *scenePageAction;
  QAction *lineupPageAction;
  QAction *gardenPageAction;
  QAction *vasePageAction;
  QAction *effectPageAction;
  QAction *othersPageAction;
  QAction *statusPageAction;
  QAction *targetMapPageAction;
  QAction *cannonLauncherPageAction;
  QActionGroup *pageGroup;

  QAction *showSidebarAction;
  QAction *switchSpawnLayoutAction;
  QAction *limitSpawnCountAction;
  QAction *saveSpawnAction;
  QAction *muteAction;
  QAction *fontAction;
  QAction *restoreDefaultAction;

  QAction *languageChineseAction;
  QAction *languageEnglishAction;
  QActionGroup *languageGroup;

  QAction *helpDocumentAction;
  QAction *videoDemoAction;
  QAction *visitWebsiteAction;
  QAction *sendFeedbackAction;
  QAction *changeLogAction;
  QAction *checkUpdateAction;
  QAction *aboutAction;
  QAction *aboutQtAction;

  QMenu *fileMenu;
  QMenu *gameMenu;
  QMenu *pageMenu;
  QMenu *settingMenu;
  QMenu *languageMenu;
  QMenu *helpMenu;

  QToolBar *pageToolBar;

  QStatusBar *theStatuBar;
  QLabel *permanentMessage;

  //

  PvZ *pvz;
  QThread *thread;

  QWidget *mainWidget;
  QListWidget *listWidget;
  QStackedWidget *stackedWidget;

  LevelPage *levelPage;
  ResourcePage *resourcePage;
  PlantsPage *plantsPage;
  ZombiesPage *zombiesPage;
  SpawnPage *spawnPage;
  SlotsPage *slotsPage;
  ScenePage *scenePage;
  LineupPage *lineupPage;
  GardenPage *gardenPage;
  VasePage *vasePage;
  EffectPage *effectPage;
  OthersPage *othersPage;
  StatusPage *statusPage;
  TargetMapPage *targetMapPage;
  CannonLauncherPage *cannonLauncherPage;
  DocumentPage *documentPage;

  QHBoxLayout *mainLayout;

  QTranslator *qt_zh_CN;
  QTranslator *widgets_zh_CN;
  QTranslator *pvztools_zh_CN;

public slots:
  void ActivateWindow();
};

} // namespace Pt
