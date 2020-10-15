/*
 * @Author: lmintlcx 
 * @Date: 2018-06-28 18:14:37 
 * @Description: PvZ memory modify.
 */

#pragma once

#include <QObject>

#include <zlib.h>

#include <regex>

#include "src/process.h"
#include "src/code.h"

namespace Pt
{

enum class Result : int
{
    NotFound,
    WrongVersion,
    OpenError,
    OK
};

enum class Sun : int
{
    Many,
    None,
    Normal
};

enum class Strength : int
{
    Invincible,
    Weak,
    Normal
};

enum class Bullet : int
{
    Kernel,
    Butter,
    Normal
};

enum class Explode : int
{
    Immediately,
    Never,
    Normal
};

enum class Visibility : int
{
    Invisible,
    Visible,
    Normal
};

struct GardenPlant
{
    int index;
    int type;
    int scene;
    int col;
    int row;
    int direction;
    int color;
    int status;
};

struct Vase
{
    int index;
    int skin;
    int col;
    int row;
    int content_zombie;
    int content_plant;
    int type;
    int content_sun;
};

class PvZ : public QObject, public Process, public Code
{
    Q_OBJECT

public:
    PvZ();
    ~PvZ();

protected:
    void *extra_code_addr;

public:
    static uintptr_t value_addr[];
    static uintptr_t damage_addr[];
    static uintptr_t hp_addr[];
    static uintptr_t time_addr[];

    void FindPvZ();
    void GameWindowTopMost();
    bool GameOn();
    void asm_code_inject();
    int GameMode();
    int GameUI();

    // Level
    void GetGoldSunflowerTrophy();
    void GetAllShopItems();
    void UnlockAllMode(bool);
    void DirectWin();
    void MixMode(int, int);
    void ShowHiddenGames(bool);
    void LockIZE(bool, int);
    void JumpLevel(int);
    // Resources
    void SetSun(int);
    void SetSunLimit(int);
    void SetMoney(int);
    void SetMoneyLimit(int);
    void SetFallingSun(Sun);
    void AutoCollect(bool);
    void ZombieNoFalling(bool);
    int GetValue(int);
    void SetValue(int, int);
    int GetDamage(int);
    void SetDamage(int, int);
    int GetHP(int);
    void SetHP(int, int);
    int GetTime(int);
    void SetTime(int, int);
    // Plants
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
    // Zombies
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
    // Spawn
    void UpdateZombiesType();
    void UpdateZombiesList();
    void UpdateZombiesPreview();
    std::array<uint32_t, 1000> GetSpawnList();
    void InternalSpawn(std::array<bool, 33>, bool);
    void CustomizeSpawn(std::array<bool, 33>, bool, bool, bool, bool, bool, std::array<bool, 20>, int);
    int GetRandomSeed();
    void SetRandomSeed(int);
    // Slots
    void SetSlotsCount(int);
    void HideSlots(bool);
    void ShowShovel(bool);
    void LockShovel(bool);
    int GetSeedType(int);
    void SetSeedType(int, int, bool);
    bool GetSeedVisible(int);
    void SetSeedVisible(int, bool);
    void IgnoreSun(bool);
    void SlotsNoCoolDown(bool);
    void PurpleSeedUnlimited(bool);
    void PlantingFreely(bool);
    void BeltNoDelay(bool);
    void HideMenuButton(bool);
    int GetSpeed(int);
    void SetSpeed(int, int);
    int GetCost(int);
    void SetCost(int, int);
    int GetRecharge(int);
    void SetRecharge(int, int);
    // Scene
    int GetScene();
    void SetScene(int);
    int GetRowCount();
    void asm_plant(int, int, int, bool, bool);
    void Plant(int, int, int, bool);
    void asm_put_zombie(int, int, int);
    void PutZombie(int, int, int);
    void asm_put_grave(int, int);
    void PutGrave(int, int);
    void asm_put_rake(int, int);
    void PutRake(int, int);
    void asm_put_coin(int, int, int, int);
    void PutCoin(int, int, int);
    void asm_put_ladder(int, int);
    void PutLadder(int, int);
    void AutoLadder(bool);
    int GetBlockType(int, int);
    void SetBlockType(int, int, int);
    int GetRowType(int);
    void SetRowType(int, int);
    void SetMusic(int);
    void ClearItems(int);
    void ClearItems(std::vector<int>);
    void StartLawnMowers();
    void ClearLawnMowers();
    void ResetLawnMowers();
    // Lineup
    void QuickPass();
    void ClearAllGraves();
    void LilyPadOnPool(int);
    void FlowerPotOnRoof(int);
    void ClearAllPlants();
    void SetLineup(std::string, bool, bool);
    void SetLineup2(std::string, bool);
    std::string GetLineup(bool);
    // Garden
    void FertilizerUnlimited(bool);
    void BugSprayUnlimited(bool);
    void ChocolateUnlimited(bool);
    void TreeFoodUnlimited(bool);
    void SetTreeHeight(int);
    std::vector<GardenPlant> GetGardenPlants();
    void SetGardenPlants(std::vector<GardenPlant>);
    // Vase
    std::vector<Vase> GetVases();
    void SetVases(std::vector<Vase>);
    // Effects
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
    int GetIceTrailX(int);
    void SetIceTrailX(int, int);
    void FullFog(bool);
    void NoFog(bool);
    void SeeVase(bool);
    void IgnoreSlope(bool);
    // Others
    void DisableSaveData(bool);
    void DisableDeleteData(bool);
    void RunningInBackground(bool);
    void DisablePause(bool);
    void OpenDataDir();
    void DebugMode(int);
    int GetFrameDuration();
    void SetFrameDuration(int);
    // Status
    std::array<int, 12> GetStatus();
    // Target Map
    std::array<int, 54> GetTargetMap(int);
    void SetTargetMap(int, std::array<int, 54>);
    // Cannon Launcher
    void GetCobInfo(int);
    void asm_launch_cannon(int, int, int);
    void LaunchCannon(int, int, int);
    void LaunchAllCannon(bool, int, int);
    // Portal
    void StartPortal(bool);
    void LockPortal(bool);
    void SetPortal(int, int, int, int, int, int, int, int);
    // I, Zombie Endless
    std::array<int, 25> GetIzeLineup();
    void SetIzeLineup(std::array<int, 25>);

signals:
    void FindResult(Result);
    void Value(int);
    void Damage(int);
    void HP(int);
    void Time(int);
    void RandomSeed(int);
    void SpawnList(std::array<uint32_t, 1000>);
    void SeedType(int);
    void SeedImitater(bool);
    void SeedVisible(bool);
    void Speed(int);
    void Cost(int);
    void Recharge(int);
    void Scene(int);
    void BlockType(int);
    void RowType(int);
    void LineupString(const std::string &);
    void GardenPlants(std::vector<GardenPlant>);
    void Vases(std::vector<Vase>);
    void IceTrailX(int);
    void ShowMessageBox(QString);
    void ShowMessageStatusBar(QString);
    void GameStatus(std::array<int, 12>);
    void TargetMap(std::array<int, 54>);
    void CobInfo(bool, int, int);
    void IzeLineup(std::array<int, 25>);
};

} // namespace Pt
