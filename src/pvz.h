#pragma once

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QDateTime>
#include <QDir>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <initializer_list>

#include <windows.h>
#include <shlwapi.h>

// 32bit pointer
typedef unsigned int ptr;

enum Reg
{
    EAX = 0,
    EBX = EAX + 19,
    ECX = EBX + 20,
    EDX = ECX + 20,
    ESI = EDX + 20,
    EDI = ESI + 20,
    EBP = EDI + 20
};

class PVZ : public QObject
{
    Q_OBJECT

  public:
    // Constructor/Destructor
    PVZ();
    PVZ(PVZ &&) = delete;
    PVZ(const PVZ &) = delete;
    PVZ &operator=(PVZ &&) = delete;
    PVZ &operator=(const PVZ &) = delete;
    ~PVZ();
    // Process
    void FindGame();
    bool GameOn();
    // Read/Write Memory (considered abandoned)
    // T = byte/bool/short/int/float/double
    template <typename T>
    T ReadMemory(ptr);
    template <typename T>
    T ReadMemory(ptr, ptr);
    template <typename T>
    T ReadMemory(ptr, ptr, ptr);
    template <typename T>
    T ReadMemory(ptr, ptr, ptr, ptr);
    template <typename T>
    T ReadMemory(ptr, ptr, ptr, ptr, ptr);
    template <typename T>
    void WriteMemory(T, ptr);
    template <typename T>
    void WriteMemory(T, ptr, ptr);
    template <typename T>
    void WriteMemory(T, ptr, ptr, ptr);
    template <typename T>
    void WriteMemory(T, ptr, ptr, ptr, ptr);
    template <typename T>
    void WriteMemory(T, ptr, ptr, ptr, ptr, ptr);
    template <typename T>
    void WriteArrayMemory(T *, int, ptr);
    // A New Way
    template <typename T>
    T ReadMemory(std::initializer_list<ptr>);
    template <typename T>
    void WriteMemory(T, std::initializer_list<ptr>);
    // Asm Inject Code
    void asm_init();
    void asm_add_byte(unsigned char);
    void asm_add_word(unsigned short);
    void asm_add_dword(unsigned int);
    void asm_push(int);
    void asm_mov_exx(Reg, int);
    void asm_mov_exx_dword_ptr(Reg, int);
    void asm_mov_exx_dword_ptr_exx_add(Reg, int);
    void asm_push_exx(Reg);
    void asm_pop_exx(Reg);
    void asm_call(int);
    void asm_ret();
    void asm_code_inject();
    // Page 0 : Resources
    void SetSun(int);
    void IncreaseSunLimit(bool);
    void SetMoney(int);
    void IncreaseMoneyLimit(bool);
    void SetFallingSun(int);
    void AutoCollect(bool);
    void CoinDisappear();
    void SetTreeHeight(int);
    void GetAllShopItems();
    void FertilizerUnlimited(bool);
    void BugSprayUnlimited(bool);
    void ChocolateUnlimited(bool);
    void TreeFoodUnlimited(bool);
    // Page 1 : Level
    void GetGoldSunflowerTrophy();
    void UnlockAllMode(bool);
    void ShowHideGames(bool);
    void Win();
    void JumpLevel(int);
    void MixMode(int, int);
    // Page 2 : Plants
    void CobCannonNoCD(bool);
    void MagnetsNoCD(bool);
    void PotatoMineNoCD(bool);
    void ChomperNoCD(bool);
    void SetPlantStrength(int);
    void LockKernelOrButter(int);
    void NoCrater(bool);
    void MushroomsAwake(bool);
    void StrongBlover(bool);
    void StrongPeas(bool);
    void Umbrella(bool);
    void BeghouledFreeMove(bool);
    void ProduceSpeedUp(bool);
    void AttackSpeedUp(bool);
    int GetDamage(int);
    void SetDamage(int, int);
    // Page 3 : Zombies
    void SetZombieExplode(int);
    void SetZombieVisibility(int);
    void SetZombieStrength(int);
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
    void SpawningAllZombies();
    void AllZombiesXXX(int);
    // Page 4 : Spawn
    void GenerateZombiesType();
    void GenerateZombiesList();
    void UpdateZombiesView();
    void InternalSpawn(bool *, bool);
    void CustomizeSpawn(bool *, bool, bool, bool, bool);
    int GetRandomSeed();
    void SetRandomSeed(int);
    // Page 5 : Slots
    void SetSlotsCount(int);
    void ShowShovel();
    void SetSlotsSeed(int, int, bool);
    void PurpleSeedUnlimited(bool);
    void PlantingFreely(bool);
    void BeltNoDelay(bool);
    void LockShovel(bool);
    void IgnoreSun(bool);
    void SlotsNoCoolDown(bool);
    int GetSpeed(int);
    void SetSpeed(int, int);
    int GetCost(int);
    void SetCost(int, int);
    int GetRecharge(int);
    void SetRecharge(int, int);
    // Page 6 : Scene
    int GetScene();
    void SetScene(int);
    int GetRowCount();
    void asm_plant(int, int, int, bool, bool);
    void Plant(int, int, int, bool);
    void asm_put_zombie(int, int, int);
    void PutZombie(int, int, int);
    void asm_put_grave(int, int);
    void PutGrave(int, int);
    void asm_put_ladder(int, int);
    void PutLadder(int, int);
    void AutoLadder(bool);
    void EatAllGraves();
    void LilyPadOnPool();
    void FlowerPotOnRoof();
    void ClearAllPlants();
    int GetBlock(int, int);
    void SetBlock(int, int, int);
    int GetRow(int);
    void SetRow(int, int);
    void StartLawnMowers();
    void ResetLawnMowers();
    // Page 7 : Effects
    void PressKey(char);
    void WisdomTreeCode(int);
    void KonamiCode();
    void LittleZombie(bool);
    void ItsRaining(bool);
    void StormyNight(bool);
    void HighGravity(bool);
    void ColumnLike(bool);
    void ZombieQuick(bool);
    int GetIceTrailX(int);
    void SetIceTrailX(int, int);
    void FullFog(bool);
    void NoFog(bool);
    void SeeVase(bool);
    // Page 8 : Others
    void DisableSaveData(bool);
    void DisableDeleteData(bool);
    void RunningInBackground(bool);
    void NoPause(bool);
    void DebugMode(int);
    bool CreatePath(std::string);
    void UnpackPAK(QString, QString);
    QFileInfoList GetFileList(QString path);
    void PackPAK(QString);
    // Page 9 : Status
    int GameMode();
    int GameUI();
    int RunningTime();
    int LevelCompleted();
    int TotalWaves();
    int PastWaves();
    int TotalHP();
    int TriggerHP();
    int CountDown();
    int HugeWaveCountDown();
    int PlantCount();
    int ZombieCount();

  signals:
    void FindResult(int);
    void PackOrUnpackFinished();

  public:
    static const byte magic_code[];

  private:
    HWND hwnd;
    DWORD pid;
    HANDLE handle;
    byte *code;
    int length;
};

template <typename T>
inline T PVZ::ReadMemory(ptr base)
{
    T result = 0;
    ReadProcessMemory(handle, LPCVOID(base), &result, sizeof(result), nullptr);
    return result;
}

template <typename T>
inline T PVZ::ReadMemory(ptr base, ptr offset_1)
{
    T result = 0;
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &result, sizeof(result), nullptr);
    return result;
}

template <typename T>
inline T PVZ::ReadMemory(ptr base, ptr offset_1, ptr offset_2)
{
    T result = 0;
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_2), &result, sizeof(result), nullptr);
    return result;
}

template <typename T>
inline T PVZ::ReadMemory(ptr base, ptr offset_1, ptr offset_2, ptr offset_3)
{
    T result = 0;
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_2), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_3), &result, sizeof(result), nullptr);
    return result;
}

template <typename T>
inline T PVZ::ReadMemory(ptr base, ptr offset_1, ptr offset_2, ptr offset_3, ptr offset_4)
{
    T result = 0;
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_2), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_3), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_4), &result, sizeof(result), nullptr);
    return result;
}

template <typename T>
inline void PVZ::WriteMemory(T value, ptr base)
{
    WriteProcessMemory(handle, LPVOID(base), &value, sizeof(value), nullptr);
}

template <typename T>
inline void PVZ::WriteMemory(T value, ptr base, ptr offset_1)
{
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    WriteProcessMemory(handle, LPVOID(buff + offset_1), &value, sizeof(value), nullptr);
}

template <typename T>
inline void PVZ::WriteMemory(T value, ptr base, ptr offset_1, ptr offset_2)
{
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &buff, sizeof(buff), nullptr);
    WriteProcessMemory(handle, LPVOID(buff + offset_2), &value, sizeof(value), nullptr);
}

template <typename T>
inline void PVZ::WriteMemory(T value, ptr base, ptr offset_1, ptr offset_2, ptr offset_3)
{
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_2), &buff, sizeof(buff), nullptr);
    WriteProcessMemory(handle, LPVOID(buff + offset_3), &value, sizeof(value), nullptr);
}

template <typename T>
inline void PVZ::WriteMemory(T value, ptr base, ptr offset_1, ptr offset_2, ptr offset_3, ptr offset_4)
{
    ptr buff = 0;
    ReadProcessMemory(handle, LPCVOID(base), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_1), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_2), &buff, sizeof(buff), nullptr);
    ReadProcessMemory(handle, LPCVOID(buff + offset_3), &buff, sizeof(buff), nullptr);
    WriteProcessMemory(handle, LPVOID(buff + offset_4), &value, sizeof(value), nullptr);
}

template <typename T>
inline void PVZ::WriteArrayMemory(T *data, int length, ptr addr)
{
    for (int i = 0; i < length; i++)
        WriteMemory(data[i], addr + sizeof(T) * i);
}

template <typename T>
inline T PVZ::ReadMemory(std::initializer_list<ptr> addr)
{
    T result = 0;
    ptr buff = 0;
    for (auto it = addr.begin(); it != addr.end(); it++)
        if (it != addr.end() - 1)
            ReadProcessMemory(handle, LPCVOID(buff + *it), &buff, sizeof(buff), nullptr);
        else
            ReadProcessMemory(handle, LPCVOID(buff + *it), &result, sizeof(result), nullptr);
    return result;
}

template <typename T>
inline void PVZ::WriteMemory(T value, std::initializer_list<ptr> addr)
{
    ptr buff = 0;
    for (auto it = addr.begin(); it != addr.end(); it++)
        if (it != addr.end() - 1)
            ReadProcessMemory(handle, LPCVOID(buff + *it), &buff, sizeof(buff), nullptr);
        else
            WriteProcessMemory(handle, LPVOID(buff + *it), &value, sizeof(value), nullptr);
}
