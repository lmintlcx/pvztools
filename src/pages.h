/*
 * @Author: lmintlcx 
 * @Date: 2018-07-01 17:41:29 
 * @Description: Pages.
 */

#pragma once

#include <QWidget>
#include <QStackedWidget>

#include "src/pvz.h"

class QListWidget;
class QPushButton;
class QAbstractButton;
class QCheckBox;
class QLabel;
class QComboBox;
class QRadioButton;
class QSpinBox;
class QDoubleSpinBox;
class QLineEdit;
class QPlainTextEdit;
class QTextBrowser;
class QSpacerItem;
class QTimer;
class QSlider;
class QHBoxLayout;
class QGridLayout;
class QTableWidget;
class QMenu;

namespace Pt
{

// Level

class LevelPage : public QWidget
{
    Q_OBJECT

public:
    LevelPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetGoldSunflowerTrophy();
    void GetAllShopItems();
    void UnlockAllMode(bool);
    void DirectWin();
    void MixMode(int, int);
    void ShowHiddenGames(bool);
    void LockIZE(bool, int);
    void JumpLevel(int);

public slots:
    void KeepSelectedFeatures();

private:
    QPushButton *getGoldSunflowerTrophyButton;
    QPushButton *getAllShopItemsButton;
    QCheckBox *unlockAllModeCheckBox;
    QPushButton *directWinButton;
    QRadioButton *adventureRadioButton;
    QRadioButton *miniGamesRadioButton;
    QRadioButton *puzzleRadioButton;
    QRadioButton *survivalRadioButton;
    QComboBox *adventureCombo;
    QComboBox *miniGamesCombo;
    QComboBox *puzzleCombo;
    QComboBox *survivalCombo;
    QPushButton *mixmodeButton;
    QCheckBox *showHiddenGamesCheckBox;
    QComboBox *izeArrayCombo;
    QCheckBox *lockIzeArrayCheckBox;
    QLineEdit *levelLineEdit;
    QPushButton *jumpLevelButton;
    QGridLayout *mainLayout;
};

// Resources

class ResourcePage : public QWidget
{
    Q_OBJECT

public:
    ResourcePage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void SetSun(int);
    void SetSunLimit(int);
    void SetMoney(int);
    void SetMoneyLimit(int);
    void SetFallingSun(Sun);
    void AutoCollect(bool);
    void ZombieNoFalling(bool);
    void GetValue(int);
    void SetValue(int, int);
    void GetDamage(int);
    void SetDamage(int, int);
    void GetHP(int);
    void SetHP(int, int);
    void GetTime(int);
    void SetTime(int, int);

public slots:
    void ShowValue(int);
    void ShowDamage(int);
    void ShowHP(int);
    void ShowTime(int);
    void UpdateGameData();
    void SetQuickLineupMode(bool);
    void KeepSelectedFeatures();

private:
    QLabel *sunLabel;
    QLineEdit *sunLineEdit;
    QPushButton *sunButton;
    QLabel *sunLimitLabel;
    QLineEdit *sunLimitLineEdit;
    QPushButton *sunLimitButton;
    QLabel *moneyLabel;
    QLineEdit *moneyLineEdit;
    QPushButton *moneyButton;
    QLabel *moneyLimitLabel;
    QLineEdit *moneyLimitLineEdit;
    QPushButton *moneyLimitButton;
    QCheckBox *manyFallingSunCheckBox;
    QCheckBox *noFallingSunCheckBox;
    QCheckBox *autoCollectCheckBox;
    QCheckBox *zombieNoFallingCheckBox;
    QLabel *valueLabel;
    QComboBox *valueCombo;
    QLineEdit *valueLineEdit;
    QPushButton *valueButton;
    QLabel *damageLabel;
    QComboBox *damageCombo;
    QLineEdit *damageLineEdit;
    QPushButton *damageButton;
    QLabel *hpLabel;
    QComboBox *hpCombo;
    QLineEdit *hpLineEdit;
    QPushButton *hpButton;
    QLabel *timeLabel;
    QComboBox *timeCombo;
    QLineEdit *timeLineEdit;
    QPushButton *timeButton;
    QGridLayout *mainLayout;
};

// Plants

class PlantsPage : public QWidget
{
    Q_OBJECT

public:
    PlantsPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void CobCannonNoCD(bool);
    void MagnetsNoCD(bool);
    void PotatoMineNoCD(bool);
    void ChomperNoCD(bool);
    void SetPlantStrength(Strength);
    void LockPult(Bullet);
    void NoCrater(bool);
    void MushroomsAwake(bool);
    void StrongBlover(bool);
    void StrongPeas(bool);
    void SetPlantExplode(Explode);
    void BeghouledFreeMove(bool);
    void AttackSuperposition(bool);
    void PlantTorchwood(bool);
    void PlantGarlic(bool);
    void PlantUmbrella(bool);
    void PlantPaper(bool);

public slots:
    void SetQuickLineupMode(bool);
    void KeepSelectedFeatures();

private:
    QCheckBox *cobsNoCdCheckBox;
    QCheckBox *magnetsNoCdCheckBox;
    QCheckBox *potatoMineNoCdCheckBox;
    QCheckBox *chomperNoCdCheckBox;
    QCheckBox *plantInvincibleCheckBox;
    QCheckBox *plantWeakCheckBox;
    QCheckBox *lockKernelCheckBox;
    QCheckBox *lockButterCheckBox;
    QCheckBox *noCraterCheckBox;
    QCheckBox *mushroomsAwakeCheckBox;
    QCheckBox *strongBloverCheckBox;
    QCheckBox *strongPeasCheckBox;
    QCheckBox *explodeImmediatelyCheckBox;
    QCheckBox *explodeNeverCheckBox;
    QCheckBox *beghouledFreeMoveCheckBox;
    QCheckBox *attackSuperpositionCheckBox;
    QCheckBox *plantTorchwoodCheckBox;
    QCheckBox *plantGarlicCheckBox;
    QCheckBox *plantUmbrellaCheckBox;
    QCheckBox *plantPaperCheckBox;
    QGridLayout *mainLayout;
};

// Zombies

class ZombiesPage : public QWidget
{
    Q_OBJECT

public:
    ZombiesPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void SetZombieExplode(Explode);
    void SetZombieVisibility(Visibility);
    void SetZombieStrength(Strength);
    void StopSpawning(bool);
    void ZombiesNoMove(bool);
    void NoIceSlowDown(bool);
    void NoButterImmobilize(bool);
    void No3zGroup(bool);
    void NoIceTrail(bool);
    void NoThrowImp(bool);
    void GargantuarEatable(bool);
    void ZombossNoMove(bool);
    void BalloonBurst(bool);
    void GatherZombies(bool, float);
    void SpawningNextWave();
    void AllZombiesXXX(int);

public slots:
    void SetQuickLineupMode(bool);
    void KeepSelectedFeatures();

private:
    QCheckBox *zombieExplodeImmediatelyCheckBox;
    QCheckBox *zombieExplodeNeverCheckBox;
    QCheckBox *zombieInvisibleCheckBox;
    QCheckBox *zombieShowCheckBox;
    QCheckBox *zombieInvincibleCheckBox;
    QCheckBox *zombieWeakCheckBox;
    QCheckBox *stopSpawningCheckBox;
    QCheckBox *zombiesNoMoveCheckBox;
    QCheckBox *noIceSlowDownCheckBox;
    QCheckBox *noButterImmobilizeCheckBox;
    QCheckBox *no3ZombiesGroupCheckBox;
    QCheckBox *noIceTrailCheckBox;
    QCheckBox *noThrowImpCheckBox;
    QCheckBox *gargantuarEatableCheckBox;
    QCheckBox *zombossNoMoveCheckBox;
    QCheckBox *balloonBurstCheckBox;
    QCheckBox *gatherZombiesCheckBox;
    QSlider *gatherZombiesSlider;
    QPushButton *spawningNextWaveButton;
    QLabel *allZombiesLabel;
    QComboBox *allZombiesCombo;
    QPushButton *allZombiesButton;
    QGridLayout *mainLayout;
};

// Spawn

class SpawnBriefPage : public QWidget
{
    Q_OBJECT

public:
    SpawnBriefPage(QWidget *parent = nullptr);
    void TranslateUI();
    std::array<bool, 33> GetZombies();
    void SetZombies(std::array<bool, 33>);

signals:
    void SwitchToDetailedPage();
    void ShowSpawnCountPage();
    void InternalSpawn(std::array<bool, 33>, bool);
    void CustomizeSpawn(std::array<bool, 33>, bool, bool, bool, bool, bool, std::array<bool, 20>, int);
    void GetRandomSeed();

public slots:
    void SwitchLayout(bool);
    void LimitSpawnCount(bool);

private:
    void CountCheck();

private:
    bool limit_count;
    QWidget *spawnBriefWidget;
    QGridLayout *spawnBriefLayout;
    QCheckBox *spawnCheckBox[20];
    unsigned int zombieTypes[20];
    QPushButton *naturalSpawnButton;
    QPushButton *extremeSpawnButton;
    QPushButton *detailedModeButton;
    QPushButton *showSpawnCountButton;
    QGridLayout *mainLayout;
};

class SpawnDetailedPage : public QWidget
{
    Q_OBJECT

public:
    SpawnDetailedPage(QWidget *parent = nullptr);
    void TranslateUI();
    std::array<bool, 33> GetZombies();
    void SetZombies(std::array<bool, 33>);
    std::array<bool, 20> GetGigaWaves();

signals:
    void SwitchToBriefPage();
    void SetRandomSeed(int);
    void InternalSpawn(std::array<bool, 33>, bool);
    void CustomizeSpawn(std::array<bool, 33>, bool, bool, bool, bool, bool, std::array<bool, 20>, int);

public slots:
    void ShowRandomSeed(int);
    void ShowGigaWaves(std::array<uint32_t, 1000>);

private:
    QLineEdit *randomSeedLineEdit;
    QPushButton *randomSeedButton;
    QComboBox *spawnZombieCombo;
    QPushButton *spawnAddButton;
    QPushButton *spawnDeleteButton;
    QPushButton *spawnClearButton;
    QRadioButton *naturalSpawnRadioButton;
    QRadioButton *extremeSpawnRadioButton;
    QRadioButton *simulateSpawnRadioButton;
    QListWidget *spawnListWidget;

    QWidget *spawnLimitWidget;
    QGridLayout *spawnLimitLayout;
    QCheckBox *limitFlagCheckBox;
    QCheckBox *limitYetiCheckBox;
    QCheckBox *limitBungeeCheckBox;
    QCheckBox *limitGigaCheckBox;
    QLabel *weightGigaLabel;
    QSpinBox *weightGigaSpinBox;

    QWidget *gigaWavesWidget;
    QHBoxLayout *gigaWavesLayout;
    QCheckBox *waveCheckBox[20];
    QFrame *waveLine9, *waveLine19;

    QPushButton *spawnResetButton;
    QPushButton *spawnSetButton;
    QPushButton *briefModeButton;
    QSpacerItem *spawnSpacer1, *spawnSpacer3, *spawnSpacer5, *spawnSpacer7, *spawnSpacer9;
    QGridLayout *mainLayout;
};

class SpawnPage : public QStackedWidget
{
    Q_OBJECT

public:
    SpawnPage(QWidget *parent = nullptr);
    void TranslateUI();
    std::array<bool, 33> GetBriefZombies();
    std::array<bool, 33> GetDetailedZombies();
    void SetBriefZombies(std::array<bool, 33>);
    void SetDetailedZombies(std::array<bool, 33>);

signals:
    void ShowSpawnCountPage();
    void InternalSpawn(std::array<bool, 33>, bool);
    void CustomizeSpawn(std::array<bool, 33>, bool, bool, bool, bool, bool, std::array<bool, 20>, int);
    void GetRandomSeed();
    void SetRandomSeed(int);

public slots:
    void ShowRandomSeed(int);
    void ShowGigaWaves(std::array<uint32_t, 1000>);
    void SwitchLayout(bool);
    void LimitSpawnCount(bool);

private:
    SpawnBriefPage *briefPage;
    SpawnDetailedPage *detailedPage;
};

// Slots

class SlotsPage : public QWidget
{
    Q_OBJECT

public:
    SlotsPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void SetSlotsCount(int);
    void HideSlots(bool);
    void ShowShovel(bool);
    void LockShovel(bool);
    void GetSeedType(int);
    void SetSeedType(int, int, bool);
    void GetSeedVisible(int);
    void SetSeedVisible(int, bool);
    void IgnoreSun(bool);
    void SlotsNoCoolDown(bool);
    void PurpleSeedUnlimited(bool);
    void PlantingFreely(bool);
    void BeltNoDelay(bool);
    void HideMenuButton(bool);
    void GetSpeed(int);
    void SetSpeed(int, int);
    void GetCost(int);
    void SetCost(int, int);
    void GetRecharge(int);
    void SetRecharge(int, int);

public slots:
    void ShowSeedType(int);
    void ShowSeedImitater(bool);
    void ShowSeedVisible(bool);
    void ShowSpeed(int);
    void ShowCost(int);
    void ShowRecharge(int);
    void UpdateGameData();
    void SetQuickLineupMode(bool);
    void KeepSelectedFeatures();

private:
    QLabel *slotsCountLabel;
    QSpinBox *slotsCountSpinBox;
    QPushButton *slotsCountButton;
    QCheckBox *hideSlotsCheckBox;
    QCheckBox *showShovelCheckBox;
    QCheckBox *lockShovelCheckBox;
    QComboBox *slotsSlotCombo;
    QComboBox *slotsSeedCombo;
    QPushButton *slotsSetButton;
    QCheckBox *imitaterCheckBox;
    QCheckBox *hideSlotsSeedCheckBox;
    QCheckBox *ignoreSunCheckBox;
    QCheckBox *slotsNoCdCheckBox;
    QCheckBox *purpleSeedUnlimitedCheckBox;
    QCheckBox *plantingFreelyCheckBox;
    QCheckBox *beltNoDelayCheckBox;
    QCheckBox *hideMenuButtonCheckBox;
    QLabel *seedLabel;
    QComboBox *seedCombo;
    QLabel *seedSpeedLabel;
    QLineEdit *seedSpeedLineEdit;
    QPushButton *seedSpeedButton;
    QLabel *seedCostLabel;
    QLineEdit *seedCostLineEdit;
    QPushButton *seedCostButton;
    QLabel *seedRechargeLabel;
    QLineEdit *seedRechargeLineEdit;
    QPushButton *seedRechargeButton;
    QGridLayout *mainLayout;
};

// Scene

class ScenePage : public QWidget
{
    Q_OBJECT

public:
    ScenePage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void Plant(int, int, int, bool);
    void PutZombie(int, int, int);
    void PutGrave(int, int);
    void PutRake(int, int);
    void PutCoin(int, int, int);
    void PutLadder(int, int);
    void AutoLadder(bool);
    void GetBlockType(int, int);
    void SetBlockType(int, int, int);
    void GetRowType(int);
    void SetRowType(int, int);
    void GetScene();
    void SetScene(int);
    void SetMusic(int);
    void ClearItems(int);
    void StartLawnMowers();
    void ClearLawnMowers();
    void ResetLawnMowers();
    void ClearAllPlants();
    void AllZombiesXXX(int);

public slots:
    void ShowScene(int);
    void ShowBlock(int);
    void ShowRow(int);

private:
    void Check();

private:
    QLabel *sceneRowLabel;
    QLabel *sceneColLabel;
    QSpinBox *sceneRowSpinBox;
    QSpinBox *sceneColSpinBox;
    QComboBox *plantMenuCombo;
    QPushButton *putPlantButton;
    QCheckBox *imitaterCheckBox;
    QComboBox *zombieMenuCombo;
    QPushButton *putZombieButton;
    QPushButton *putGraveButton;
    QPushButton *putRakeButton;
    QComboBox *coinTypeCombo;
    QPushButton *putCoinButton;
    QPushButton *putLadderButton;
    QPushButton *autoLadderButton;
    QCheckBox *imitaterPumpkinCheckBox;
    QLabel *blockTypeLabel;
    QComboBox *blockTypeCombo;
    QPushButton *blockTypeButton;
    QLabel *rowTypeLabel;
    QComboBox *rowTypeCombo;
    QPushButton *rowTypeButton;
    QLabel *sceneLabel;
    QComboBox *sceneCombo;
    QPushButton *sceneButton;
    QPushButton *startLawnMowersButton;
    QPushButton *clearLawnMowersButton;
    QPushButton *resetLawnMowersButton;
    QLabel *musicLabel;
    QComboBox *musicCombo;
    QPushButton *musicButton;
    QComboBox *itemCombo;
    QPushButton *clearItemButton;
    QGridLayout *mainLayout;
};

// Lineup

class LineupPage : public QWidget
{
    Q_OBJECT

public:
    LineupPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void SetQuickLineupMode(bool);
    void QuickPass();
    void MixMode(int, int);
    void ClearAllGraves();
    void LilyPadOnPool(int);
    void FlowerPotOnRoof(int);
    void ClearAllPlants();
    void SetLineup(std::string, bool, bool);
    void SetLineup2(std::string, bool);
    void GetLineup(bool);
    void ShowMessageStatusBar(QString);

public slots:
    void ShowLineup(std::string);
    void InitLineupString(QString str = "");
    void RefreshLineupString();
    void UpdateLineupString();
    void SaveLineupString();
    void DeleteLineupString();
    void KeepSelectedFeatures();

private:
    QString lastSelectedBuildName;
    QStringList endlessBuildGroupList;
    QStringList endlessBuildUuidList;
    QStringList endlessBuildNameList;
    QStringList endlessBuildStringList;
    bool StringCheck(const QString &);
    std::string ConvertLineup(const std::string &);

private:
    QCheckBox *quickLineupModeCheckBox;
    QPushButton *quickPassButton;
    QPushButton *mixModeToSurvivalEndlessButton;
    QLabel *hiddenSceneLabel;
    QPushButton *clearAllGravesButton;
    QPushButton *lilyPadOnPoolButton;
    QMenu *lilyPadOnPoolMenu;
    QAction *lilyPadPlantToAction[9];
    QPushButton *flowerPotOnRoofButton;
    QMenu *flowerPotOnRoofMenu;
    QAction *flowerPotPlantToAction[9];
    QPushButton *clearAllPlantsButton;
    QLabel *arrayDesignLabel;
    QPushButton *updateCheckButton;
    QComboBox *endlessBuildCombo;
    QPushButton *oneKeySetupButton;
    QPlainTextEdit *stringTextEdit;
    QPushButton *string2buildButton;
    QPushButton *build2stringButton;
    QPushButton *copyStringButton;
    QPushButton *pasteStringButton;
    QPushButton *saveStringButton;
    QPushButton *deleteStringButton;
    QCheckBox *allowSwitchSceneCheckBox;
    QCheckBox *keepHpStatusCheckBox;
    QGridLayout *mainLayout;
};

// Garden

class GardenPage : public QWidget
{
    Q_OBJECT

public:
    GardenPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void FertilizerUnlimited(bool);
    void BugSprayUnlimited(bool);
    void ChocolateUnlimited(bool);
    void TreeFoodUnlimited(bool);
    void SetTreeHeight(int);
    void GetGardenPlants();
    void SetGardenPlants(std::vector<GardenPlant>);

public slots:
    void ShowGardenPlants(std::vector<GardenPlant>);
    void KeepSelectedFeatures();

private:
    void UpdateContent();

private:
    QCheckBox *fertilizerUnlimitedCheckBox;
    QCheckBox *bugSprayUnlimitedCheckBox;
    QCheckBox *chocolateUnlimitedCheckBox;
    QCheckBox *treeFoodUnlimitedCheckBox;
    QLabel *treeHeightLabel;
    QLineEdit *treeHeightLineEdit;
    QPushButton *treeHeightButton;
    QTableWidget *table;
    QPushButton *clearButton;
    QPushButton *loadButton;
    QPushButton *setButton;
    QLabel *sceneLabel;
    QLabel *typeLabel;
    QLabel *directionLabel;
    QLabel *colorLabel;
    QLabel *statusLabel;
    QComboBox *sceneCombo;
    QComboBox *typeCombo;
    QComboBox *directionCombo;
    QComboBox *colorCombo;
    QComboBox *statusCombo;
    QGridLayout *mainLayout;
};

// Vase

class VasePage : public QWidget
{
    Q_OBJECT

public:
    VasePage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetVases();
    void SetVases(std::vector<Vase>);

public slots:
    void ShowVases(std::vector<Vase>);

private:
    void UpdateContent();
    void SetComboEnabled();

private:
    QLabel *vaseCountLabel;
    QPushButton *clearButton;
    QPushButton *loadButton;
    QPushButton *setButton;
    QTableWidget *table;
    QLabel *rowLabel;
    QLabel *colLabel;
    QLabel *vaseSkinLabel;
    QLabel *vaseTypeLabel;
    QLabel *vaseContentPlantLabel;
    QLabel *vaseContentZombieLabel;
    QLabel *vaseContentSunLabel;
    QComboBox *rowCombo;
    QComboBox *colCombo;
    QComboBox *vaseSkinCombo;
    QComboBox *vaseTypeCombo;
    QComboBox *vaseContentPlantCombo;
    QComboBox *vaseContentZombieCombo;
    QLineEdit *vaseContentSunLineEdit;
    QGridLayout *mainLayout;
};

// Effects

class EffectPage : public QWidget
{
    Q_OBJECT

public:
    EffectPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void WisdomTreeCode(int);
    void KonamiCode();
    void ItsRaining(bool);
    void LittleZombie(bool);
    void ColumnLike(bool);
    void ZombieQuick(bool);
    void WhackZombie(bool);
    void HighGravity(bool);
    void GraveDanger(bool);
    void StormyNight(bool);
    void BungeeBlitz(bool);
    void GetIceTrailX(int);
    void SetIceTrailX(int, int);
    void FullFog(bool);
    void NoFog(bool);
    void SeeVase(bool);

public slots:
    void ShowIceTrailX(int);
    void SetQuickLineupMode(bool);
    void KeepSelectedFeatures();

private:
    QPushButton *sukhbirCodeButton;
    QPushButton *futureCodeButton;
    QPushButton *mustacheCodeButton;
    QPushButton *trickedoutCodeButton;
    QPushButton *daisiesCodeButton;
    QPushButton *danceCodeButton;
    QPushButton *pinataCodeButton;
    QPushButton *konamiCodeButton;
    QCheckBox *itsRainingCheckBox;
    QCheckBox *littleZombieCheckBox;
    QCheckBox *columnLikeCheckBox;
    QCheckBox *zombieQuickCheckBox;
    QCheckBox *whackZombieCheckBox;
    QCheckBox *highGravityCheckBox;
    QCheckBox *graveDangerCheckBox;
    QCheckBox *stormyNightCheckBox;
    QCheckBox *bungeeBlitzCheckBox;
    QLabel *iceTrailLabel;
    QComboBox *iceTrailCombo;
    QLineEdit *iceTrailLineEdit;
    QPushButton *iceTrailButton;
    QCheckBox *fullFogCheckBox;
    QCheckBox *noFogCheckBox;
    QCheckBox *seeVaseCheckBox;
    QGridLayout *mainLayout;
};

// Others

class OthersPage : public QWidget
{
    Q_OBJECT

public:
    OthersPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void DisableSaveData(bool);
    void DisableDeleteData(bool);
    void RunningInBackground(bool);
    void DisablePause(bool);
    void OpenDataDir();
    void DebugMode(int);
    void UnpackPAK(QString, QString);
    void PackPAK(QString);
    void ShowTargetMapPage();
    void ShowCannonLauncherPage();
    void ShowPortalPage();
    void ShowIzeLineupPage();

public slots:
    void GetFileName();
    void GetFolderName();
    void UnpackFinished();
    void PackFinished();
    void KeepSelectedFeatures();

protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

private:
    QCheckBox *disableSaveDataCheckBox;
    QCheckBox *disableDeleteDataCheckBox;
    QCheckBox *runningInBackgroundCheckBox;
    QCheckBox *disablePauseCheckBox;
    QPushButton *openDataDirButton;
    QLabel *debugModeLabel;
    QComboBox *debugModeCombo;
    QPushButton *debugModeButton;
    QPushButton *openPakFileButton;
    QLineEdit *pakFileLineEdit;
    QPushButton *unpackPakButton;
    QPushButton *openPakFolderButton;
    QLineEdit *pakPathLineEdit;
    QPushButton *packPakButton;
    QPushButton *targetMapButton;
    QPushButton *cannonLauncherButton;
    QPushButton *portalButton;
    QPushButton *izeLineupButton;
    QGridLayout *mainLayout;
};

// Status

class StatusPage : public QWidget
{
    Q_OBJECT

public:
    StatusPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetStatus();

public slots:
    void ShowStatus(std::array<int, 12>);
    bool IsAutoRefresh();
    void StartTimer();
    void StopTimer(bool uncheck_it = false);

private:
    QTimer *refreshStatusTimer;
    QLabel *gameModeTextLabel;
    QCheckBox *autoRefreshCheckBox;
    QSpinBox *refreshIntervalSpinBox;
    QLabel *gameModeLabel;
    QLabel *gameModeValueLabel;
    QLabel *gameUiLabel;
    QLabel *gameUiValueLabel;
    QLabel *runningTimeLabel;
    QLabel *runningTimeValueLabel;
    QLabel *levelCompletedLabel;
    QLabel *levelCompletedValueLabel;
    QLabel *totalWavesLabel;
    QLabel *totalWavesValueLabel;
    QLabel *pastWavesLabel;
    QLabel *pastWavesValueLabel;
    QLabel *totalHpLabel;
    QLabel *totalHpValueLabel;
    QLabel *triggerHpLabel;
    QLabel *triggerHpValueLabel;
    QLabel *countdownLabel;
    QLabel *countdownValueLabel;
    QLabel *hugewaveCountdownLabel;
    QLabel *hugewaveCountdownValueLabel;
    QLabel *plantCountLabel;
    QLabel *plantCountValueLabel;
    QLabel *zombieCountLabel;
    QLabel *zombieCountValueLabel;
    QGridLayout *mainLayout;
};

// SpawnCount

class SpawnCountPage : public QWidget
{
    Q_OBJECT

public:
    SpawnCountPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetSpawnList();

public slots:
    void UpdateSpawnCount(std::array<uint32_t, 1000>);

private:
    QTableWidget *table;
    QGridLayout *mainLayout;
    QAbstractButton *cornerButton;
};

// Target Map

class TargetMapPage : public QWidget
{
    Q_OBJECT

public:
    TargetMapPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetTargetMap(int);
    void SetTargetMap(int, std::array<int, 54>);

public slots:
    void ShowTargetMap(std::array<int, 54>);

private:
    QComboBox *comboBoxes[54];
    QRadioButton *seeingStarsRadioButton;
    QRadioButton *artChallengeWallnutRadioButton;
    QRadioButton *artChallengeSunflowerRadioButton;
    QPushButton *loadButton;
    QPushButton *clearButton;
    QPushButton *setButton;
    QGridLayout *mainLayout;
};

// Cannon Launcher

class CannonLauncherPage : public QWidget
{
    Q_OBJECT

public:
    CannonLauncherPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetCobInfo(int);
    void GetScene();
    void LaunchCannon(int, int, int);
    void LaunchAllCannon(bool, int, int);

public slots:
    void ShowCobInfo(bool, int, int);
    void CalculateCoord(int);

private:
    QLabel *indexLabel;
    QSpinBox *indexSpinBox;
    QLabel *infoLabel;
    QLabel *gridLabel;
    QLabel *rowLabel;
    QLabel *colLabel;
    QDoubleSpinBox *rowSpinBox;
    QDoubleSpinBox *colSpinBox;
    QLabel *coordLabel;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *xValueLabel;
    QLabel *yValueLabel;
    QCheckBox *randomFallCheckBox;
    QPushButton *launchAllButton;
    QPushButton *launchButton;
    QGridLayout *mainLayout;
};

// Portal

class PortalPage : public QWidget
{
    Q_OBJECT

public:
    PortalPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void StartPortal(bool);
    void LockPortal(bool);
    void SetPortal(int, int, int, int, int, int, int, int);

private:
    QLabel *label_black_row, *label_black_col;
    QLabel *label_white_row, *label_white_col;
    QLabel *label_black_1, *label_black_2;
    QLabel *label_white_1, *label_white_2;
    QLineEdit *line_edit_black_1_row, *line_edit_black_1_col;
    QLineEdit *line_edit_black_2_row, *line_edit_black_2_col;
    QLineEdit *line_edit_white_1_row, *line_edit_white_1_col;
    QLineEdit *line_edit_white_2_row, *line_edit_white_2_col;
    QCheckBox *check_box_portal_start;
    QCheckBox *check_box_portal_lock;
    QPushButton *push_button_portal_set;
    QGridLayout *mainLayout;
};

// I, Zombie Endless

class IzeLineupPage : public QWidget
{
    Q_OBJECT

public:
    IzeLineupPage(QWidget *parent = nullptr);
    void TranslateUI();

signals:
    void GetIzeLineup(int);
    void SetIzeLineup(std::array<int, 25>);

public slots:
    void ShowIzeLineup(std::array<int, 25>);

private:
    int izPlantTypes[22];
    QComboBox *comboBoxes[25];
    QPushButton *loadButton;
    QPushButton *clearButton;
    QPushButton *setButton;
    QGridLayout *mainLayout;
};

// Document

class DocumentPage : public QWidget
{
    Q_OBJECT

public:
    DocumentPage(QWidget *parent = nullptr);
    void TranslateUI();

private:
    QTextBrowser *document;
    QGridLayout *mainLayout;
};

} // namespace Pt
