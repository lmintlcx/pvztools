
#include <QString>
#include <QMetaType>

#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cassert>

#include "src/pvz.h"
#include "src/bot.h"

namespace Pt
{

// List::damageList
uintptr_t PvZ::damage_addr[] = {
    0x69f1c8 + 0 * 0xc,  // Pea
    0x69f1c8 + 1 * 0xc,  // Frozen Pea
    0x69f1c8 + 2 * 0xc,  // Cabbage
    0x69f1c8 + 3 * 0xc,  // Melon
    0x69f1c8 + 4 * 0xc,  // Fume
    0x69f1c8 + 5 * 0xc,  // Winter Melon
    0x69f1c8 + 6 * 0xc,  // Fireball
    0x69f1c8 + 7 * 0xc,  // Star
    0x69f1c8 + 8 * 0xc,  // Spike
    0x69f1c8 + 9 * 0xc,  // Basketball
    0x69f1c8 + 10 * 0xc, // Kernel
    0x69f1c8 + 12 * 0xc, // Butter
    0x69f1c8 + 13 * 0xc, // Zombie Pea
    0x532fdc,            // Ash
    0x41d931,            // Potato Mine
    0x532493,            // Ice-shroom (Byte)
    0x4607a9,            // Squash
    0x52fcf3             // Bite (Negative Byte)
};

// List::coinList
uintptr_t PvZ::value_addr[] = {
    0x430a46, // Silver Coin x10
    0x430a53, // Gold Coin (Byte) +2x10
    0x430a63, // Diamond (Byte) x10
    0x4309f0, // Sun
    0x4309fd, // Small Sun (Byte) +5
    0x430a0d  // Big Sun (Byte)
};

// List::hpList
uintptr_t PvZ::hp_addr[] = {
    0x45dc55, // Normal Plant
    0x45e1a7, // Wall-nut
    0x45e215, // Tall-nut
    0x45e445, // Pumpkin
    0x45e242, // Garlic
    0x45e5c3, // Spikerock
    0x5227bb, // Normal Zombie
    0x522892, // Conehead Zombie
    0x522cbf, // Pole Vaulting Zombie
    0x52292b, // Bucket Zombie
    0x52337d, // Newspaper Zombie
    0x522949, // Screen Door Zombie
    0x522bb0, // Football Zombie
    0x523530, // Dancing Zombie
    0x522de1, // Zomboni
    0x522d64, // Dolphin Rider Zombie
    0x522fc7, // Jack-in-the-Box Zombie
    0x522bef, // Digger Zombie
    0x523300, // Pogo Zombie
    0x52296e, // Zombie Yeti
    0x522a1b, // Bungee Zombie
    0x52299c, // Ladder Zombie
    0x523d26, // Gargantuar
    0x523624, // Dr. Zomboss
    0x52361e, // Dr. Zomboss Extra
    0x52382b, // Wall-nut Zombie
    0x523a87, // Jalapeno Zombie
    0x52395d, // Tall-nut Zombie
    0x523e4a, // GigaGargantuar
    0x5235ac, // Imp in I, Zombie
    0x5234bf  // Balloon
};

// List::timeList
uintptr_t PvZ::time_addr[] = {
    0x466644, // Fog Clear
    0x45e300, // Cherry Bomb / Jalapeno
    0x45e34e, // Potato Mine
    0x461551, // Chomper
    0x45e3f1, // Sun-shroom
    0x4632b0, // Ice-shroom
    0x460dfe, // Doom-shroom
    0x45dc5f, // Blover
    0x46163a, // Magnet-shroom
    0x464d4d, // Cob Cannon Filling
    0x528885, // Backup Dancer Call
    0x522978, // Zombie Yeti Run Away
    0x525127  // Bungee Zombie Stay
};

PvZ::PvZ()
{
    extra_code_addr = 0;

    qRegisterMetaType<Result>("Result");
    qRegisterMetaType<Sun>("Sun");
    qRegisterMetaType<Strength>("Strength");
    qRegisterMetaType<Bullet>("Bullet");
    qRegisterMetaType<Explode>("Explode");
    qRegisterMetaType<Visibility>("Visibility");
    qRegisterMetaType<std::array<uint32_t, 1000>>("std::array<uint32_t, 1000>");
    qRegisterMetaType<std::string>("std::string");
    qRegisterMetaType<std::vector<GardenPlant>>("std::vector<GardenPlant>");
    qRegisterMetaType<std::vector<Vase>>("std::vector<Vase>");
    qRegisterMetaType<std::array<int, 12>>("std::array<int, 12>");
    qRegisterMetaType<std::array<int, 54>>("std::array<int, 54>");

    // FindPvZ(); // 不能在这里用!
}

PvZ::~PvZ()
{
}

void PvZ::FindPvZ()
{
    Result result;

    if (OpenByWindow(L"MainWindow", L"Plants vs. Zombies"))
        if (IsValid())
            if (ReadMemory<unsigned int>(0x004140c5) == 0x0019b337)
                result = Result::OK;
            else
                result = Result::WrongVersion;
        else
            result = Result::OpenError;
    else if (OpenByWindow(L"MainWindow", nullptr))
        if (IsValid())
            if (ReadMemory<unsigned int>(0x004140c5) == 0x0019b337)
                result = Result::OK;
            else
                result = Result::WrongVersion;
        else
            result = Result::OpenError;
    else
        result = Result::NotFound;

    if (result == Result::OK)
    {
        if (extra_code_addr != nullptr && ReadMemory<byte>((unsigned int)extra_code_addr) == 0xcc)
            VirtualFreeEx(handle, extra_code_addr, 0, MEM_RELEASE);

        void *thread_addr = VirtualAllocEx(handle, nullptr, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if (thread_addr != nullptr)
        {
            extra_code_addr = thread_addr;
            std::wcout << L"申请到内存地址: " << extra_code_addr << std::endl;

            byte extra_code[] = {
                0xcc,                                     // int 3
                0xc7, 0x40, 0x10, 0x02, 0x00, 0x00, 0x00, // mov [eax+10],00000002
                0xc7, 0x40, 0x14, 0x04, 0x00, 0x00, 0x00, // mov [eax+14],00000004
                0xe9, 0x00, 0x00, 0x00, 0x00,             // jmp xxxxxxxx
                0xcc,                                     // int 3
            };
            (unsigned int &)extra_code[16] = 0x0042706f - ((unsigned int)thread_addr + 15) - 5;
            WriteProcessMemory(handle, thread_addr, extra_code, 21, nullptr);

            byte portal_fix_code[] = {
                // 0xc7, 0x40, 0x10, 0x02, 0x00, 0x00, 0x00, // mov [eax+10],00000002
                // 0x89, 0x58, 0x14,                         // mov [eax+14],ebx
                0xe9, 0x00, 0x00, 0x00, 0x00, // jmp xxxxxxxx
                0x90, 0x90, 0x90, 0x90, 0x90, //
            };
            (unsigned int &)portal_fix_code[1] = ((unsigned int)thread_addr + 1) - 0x00427065 - 5;
            WriteProcessMemory(handle, (void *)0x00427065, portal_fix_code, 10, nullptr);
        }
    }
    else
    {
        hwnd = nullptr, pid = 0, handle = nullptr, extra_code_addr = 0;
    }

    emit FindResult(result);
}

void PvZ::GameWindowTopMost()
{
    if (hwnd != nullptr)
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
}

bool PvZ::GameOn()
{
#ifdef _DEBUG
    std::cout << std::endl;
#endif

    bool on = false;
    on = ReadMemory<int>(0x6a9ec0) != 0;
    if (!on)
    {
        FindPvZ();
        on = ReadMemory<int>(0x6a9ec0) != 0;
    }

    return on;
}

void PvZ::asm_code_inject()
{
    WriteMemory<byte>(0xfe, 0x00552014);
    Sleep(10);
    if (IsValid())
        Code::asm_code_inject(handle);
    WriteMemory<byte>(0xdb, 0x00552014);
}

int PvZ::GameMode()
{
    return ReadMemory<int>(0x6a9ec0, 0x7f8);
}

int PvZ::GameUI()
{
    return ReadMemory<int>(0x6a9ec0, 0x7fc);
}

// Level

void PvZ::GetGoldSunflowerTrophy()
{
    if (GameOn())
    {
        // Adventure 2 times
        if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x2c) < 2)
            WriteMemory<int>(2, 0x6a9ec0, 0x82c, 0x2c);

        // Mini-games
        for (size_t i = 0; i < 33; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x6c + i * 4) == 0)
                WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x6c + i * 4);

        // Vasebreaker
        for (size_t i = 0; i < 9; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0xf8 + i * 4) == 0)
                WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0xf8 + i * 4);

        // I, Zombie
        for (size_t i = 0; i < 9; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x120 + i * 4) == 0)
                WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x120 + i * 4);

        // Survival
        for (size_t i = 0; i < 5; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x30 + i * 4) != 5)
                WriteMemory<int>(5, 0x6a9ec0, 0x82c, 0x30 + i * 4);

        // Survival Hard
        for (size_t i = 0; i < 5; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x44 + i * 4) != 10)
                WriteMemory<int>(10, 0x6a9ec0, 0x82c, 0x44 + i * 4);

        emit ShowMessageStatusBar(tr("Already unlocked golden sunflower trophy."));
    }
}

void PvZ::GetAllShopItems()
{
    if (GameOn())
    {
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1c0); // Gatling Pea
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1c4); // Twin Sunflower
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1c8); // Gloom-shroom
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1cc); // Cattail
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1d0); // Winter Melon
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1d4); // Gold Magnet
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1d8); // Spikerock
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1dc); // Cob Cannon

        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1e0); // Imitater
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x234); // Wall-nut First Aid

        WriteMemory<int>(4, 0x6a9ec0, 0x82c, 0x214); // 10 seed slots
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x218); // Pool Cleaner
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x21c); // Roof Cleaner
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x220); // Garden Rake (left)

        WriteMemory<int>(0, 0x6a9ec0, 0x82c, 0x1e8);        // Marigold Sprout #1
        WriteMemory<int>(0, 0x6a9ec0, 0x82c, 0x1ec);        // Marigold Sprout #2
        WriteMemory<int>(0, 0x6a9ec0, 0x82c, 0x1f0);        // Marigold Sprout #3
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x1f4);        // Golden Watering
        if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x1f8) == 0)   //
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x1f8); // Fertilizer 20->1020
        if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x1fc) == 0)   //
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x1fc); // Bug Spray 20->1020
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x200);        // Phonograph
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x204);        // Gardening Glove

        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x208);        // Mushroom Garden
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x224);        // Aquarium Garden
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x22c);        // Tree of Wisdom
        if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x230) == 0)   //
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x230); // Tree Food 20->1020
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x20c);        // Wheel Barrow
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x210);        // Snail
        if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x228) == 0)   //
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x228); // Chocolate 20->1020

        emit ShowMessageStatusBar(tr("Already get all shop items."));
    }
}

void PvZ::UnlockAllMode(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x0044a514);
            WriteMemory(std::array<byte, 3>{0x31, 0xc0, 0xc3}, 0x0042e440);
            WriteMemory<byte>(0x70, 0x0044a5af);
            WriteMemory<byte>(0x70, 0x00454109);
            WriteMemory<byte>(0xeb, 0x00449e7a);
            WriteMemory<byte>(0xeb, 0x00449e9d);
            WriteMemory<byte>(0xeb, 0x00453ad1);
            WriteMemory<int>(0x5beb01b0, 0x00403a10);
            WriteMemory(std::array<byte, 3>{0xb0, 0x01, 0xc3}, 0x00403b30);
            WriteMemory<int>(0x00, 0x0069dca0);
            WriteMemory(std::array<byte, 3>{0x30, 0xc0, 0xc3}, 0x0048aad0);
            WriteMemory<byte>(0xeb, 0x0048a54c);
            WriteMemory<byte>(0xeb, 0x0048d32b);
            WriteMemory<byte>(0xeb, 0x0048c491);
        }
        else
        {
            WriteMemory<byte>(0x7e, 0x0044a514);
            WriteMemory(std::array<byte, 3>{0x51, 0x53, 0x55}, 0x0042e440);
            WriteMemory<byte>(0x7e, 0x0044a5af);
            WriteMemory<byte>(0x7e, 0x00454109);
            WriteMemory<byte>(0x7f, 0x00449e7a);
            WriteMemory<byte>(0x7f, 0x00449e9d);
            WriteMemory<byte>(0x7f, 0x00453ad1);
            WriteMemory<int>(0x6c8b5551, 0x00403a10);
            WriteMemory(std::array<byte, 3>{0x8b, 0x80, 0x6c}, 0x00403b30);
            WriteMemory<int>(0x28, 0x0069dca0);
            WriteMemory(std::array<byte, 3>{0x53, 0x8b, 0xd9}, 0x0048aad0);
            WriteMemory<byte>(0x7f, 0x0048a54c);
            WriteMemory<byte>(0x7f, 0x0048d32b);
            WriteMemory<byte>(0x7f, 0x0048c491);
        }
    }
}

void PvZ::DirectWin()
{
    if (GameOn() && GameUI() == 3)
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::ECX, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, 0x768);
        asm_call(0x0040c3e0);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::MixMode(int mode, int level)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (mode == 0)
        {
            WriteMemory<int>(level, 0x6a9ec0, 0x82c, 0x24);
            WriteMemory<int>(level, 0x6a9ec0, 0x768, 0x5550);
        }
        WriteMemory<int>(mode, 0x6a9ec0, 0x7f8);
    }
}

void PvZ::ShowHiddenGames(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory(std::array<byte, 3>{0x38, 0x59, 0x54}, 0x0042df5d);
            // WriteMemory<byte>(0x38, 0x0042df5d);
        }
        else
        {
            WriteMemory(std::array<byte, 3>{0x88, 0x59, 0x54}, 0x0042df5d);
            // WriteMemory<byte>(0x88, 0x0042df5d);
        }
    }
}

void PvZ::LockIZE(bool on, int mode)
{
    if (GameOn())
    {
        if (on)
        {
            const int value[] = {24, -624, 73, 100, 122, 190, 249, 360};
            WriteMemory<byte>(0x81, 0x0042b047);
            WriteMemory<int>(value[mode], 0x0042b048);
        }
        else
        {
            WriteMemory<byte>(0x85, 0x0042b047);
            WriteMemory<int>(144, 0x0042b048);
        }
    }
}

void PvZ::JumpLevel(int level)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int mode = GameMode();
        if (mode == 60 || mode == 70 || (mode >= 11 && mode <= 15))
            WriteMemory<int>(level, 0x6a9ec0, 0x768, 0x160, 0x6c);
    }
}

// Resources

void PvZ::SetSun(int sun)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        WriteMemory<int>(sun, 0x6a9ec0, 0x768, 0x5560);
}

void PvZ::SetSunLimit(int sun_limit)
{
    if (GameOn())
    {
        WriteMemory<int>(sun_limit, 0x00430a1f);
        WriteMemory<int>(sun_limit, 0x00430a2b);
    }
}

void PvZ::SetMoney(int money)
{
    if (GameOn())
        WriteMemory<int>(money, 0x6a9ec0, 0x82c, 0x28);
}

void PvZ::SetMoneyLimit(int money_limit)
{
    if (GameOn())
    {
        WriteMemory<int>(money_limit, 0x00430a74);
        WriteMemory<int>(money_limit, 0x00430a7d);
    }
}

void PvZ::SetFallingSun(Sun mode)
{
    if (GameOn())
    {
        if (mode == Sun::Many)
            WriteMemory<byte>(0x74, 0x00413B83);
        else if (mode == Sun::None)
            WriteMemory<byte>(0xeb, 0x00413B83);
        else // if (mode == Sun::Normal)
            WriteMemory<byte>(0x75, 0x00413B83);
    }
}

void PvZ::AutoCollect(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xeb, 0x0043158f);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x0043158f);
        }
    }
}

void PvZ::ZombieNoFalling(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory(std::array<byte, 2>{0x90, 0xe9}, 0x0041d025);
        }
        else
        {
            WriteMemory(std::array<byte, 2>{0x0f, 0x8f}, 0x0041d025);
        }
    }
}

int PvZ::GetValue(int index)
{
    int value = 0;

    if (GameOn())
    {
        if (index == 0 || index == 3)
        {
            value = ReadMemory<int>(value_addr[index]);
        }
        else // char
        {
            char _value = ReadMemory<char>(value_addr[index]);
            value = static_cast<int>(_value);
        }
        emit Value(value);
    }

    return value;
}

void PvZ::SetValue(int index, int value)
{
    if (GameOn())
    {
        if (index == 0 || index == 3)
            WriteMemory<int>(value, value_addr[index]);
        else // char
            WriteMemory<char>(static_cast<char>(value), value_addr[index]);
    }
}

int PvZ::GetDamage(int index)
{
    int damage = 0;

    if (GameOn())
    {
        if (index == 15) // Ice-shroom
        {
            char _damage = ReadMemory<char>(damage_addr[index]);
            damage = static_cast<int>(_damage);
        }
        else if (index == 17) // Bite
        {
            // negative number
            char _damage = ReadMemory<char>(damage_addr[index]);
            damage = static_cast<int>(_damage) * (-1);
        }
        else
        {
            damage = ReadMemory<int>(damage_addr[index]);
        }
        emit Damage(damage);
    }

    return damage;
}

void PvZ::SetDamage(int index, int damage)
{
    if (GameOn())
    {
        if (index == 15) // Ice-shroom
            WriteMemory<char>(static_cast<char>(damage), damage_addr[index]);
        else if (index == 17) //  Bite Negative
            WriteMemory<char>(static_cast<char>(damage) * (-1), damage_addr[index]);
        else
            WriteMemory<int>(damage, damage_addr[index]);
    }
}

int PvZ::GetHP(int index)
{
    int hp = 0;

    if (GameOn())
    {
        hp = ReadMemory<int>(hp_addr[index]);
        emit HP(hp);
    }

    return hp;
}

void PvZ::SetHP(int index, int hp)
{
    if (GameOn())
        WriteMemory<int>(hp, hp_addr[index]);
}

int PvZ::GetTime(int index)
{
    int t = 0;

    if (GameOn())
    {
        t = ReadMemory<int>(time_addr[index]);
        emit Time(t);
    }

    return t;
}

void PvZ::SetTime(int index, int t)
{
    if (GameOn())
        WriteMemory<int>(t, time_addr[index]);
}

// Plants

void PvZ::CobCannonNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x80, 0x0046103b);
        else
            WriteMemory<byte>(0x85, 0x0046103b);
    }
}

void PvZ::MagnetsNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x80, 0x00461e37);
        else
            WriteMemory<byte>(0x85, 0x00461e37);
    }
}

void PvZ::PotatoMineNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x80, 0x0045fe54);
        else
            WriteMemory<byte>(0x85, 0x0045fe54);
    }
}

void PvZ::ChomperNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x00461565);
        else
            WriteMemory<byte>(0x75, 0x00461565);
    }
}

void PvZ::SetPlantStrength(Strength status)
{
    if (GameOn())
    {
        if (status == Strength::Invincible)
        {
            WriteMemory(std::array<byte, 3>{0x46, 0x40, 0x00}, 0x0052fcf1);
            WriteMemory<byte>(0xeb, 0x0041cc2f);
            WriteMemory<byte>(0xeb, 0x005276ea);
            WriteMemory(std::array<byte, 3>{0x90, 0x90, 0x90}, 0x0046cfeb);
            WriteMemory(std::array<byte, 3>{0x90, 0x90, 0x90}, 0x0046d7a6);
            WriteMemory<byte>(0xeb, 0x0052e93b);
            WriteMemory<byte>(0x70, 0x0045ee0a);
            WriteMemory<byte>(0x00, 0x0045ec66);
            WriteMemory(std::array<byte, 3>{0xc2, 0x04, 0x00}, 0x00462b80);
        }
        else if (status == Strength::Weak)
        {
            WriteMemory(std::array<byte, 3>{0x66, 0x40, 0x00}, 0x0052fcf1);
            WriteMemory<byte>(0x74, 0x0041cc2f);
            WriteMemory<byte>(0x75, 0x005276ea);
            WriteMemory(std::array<byte, 3>{0x29, 0x40, 0x40}, 0x0046cfeb);
            WriteMemory(std::array<byte, 3>{0x29, 0x76, 0x40}, 0x0046d7a6);
            WriteMemory<byte>(0x74, 0x0052e93b);
            WriteMemory<byte>(0xeb, 0x0045ee0a);
            WriteMemory<byte>(0xce, 0x0045ec66);
            WriteMemory(std::array<byte, 3>{0x53, 0x55, 0x8b}, 0x00462b80);
        }
        else // if (status == Strength::Normal)
        {
            WriteMemory(std::array<byte, 3>{0x46, 0x40, 0xfc}, 0x0052fcf1);
            WriteMemory<byte>(0x74, 0x0041cc2f);
            WriteMemory<byte>(0x75, 0x005276ea);
            WriteMemory(std::array<byte, 3>{0x29, 0x50, 0x40}, 0x0046cfeb);
            WriteMemory(std::array<byte, 3>{0x29, 0x4e, 0x40}, 0x0046d7a6);
            WriteMemory<byte>(0x74, 0x0052e93b);
            WriteMemory<byte>(0x75, 0x0045ee0a);
            WriteMemory<byte>(0xce, 0x0045ec66);
            WriteMemory(std::array<byte, 3>{0x53, 0x55, 0x8b}, 0x00462b80);
        }
    }
}

void PvZ::LockPult(Bullet bullet)
{
    if (GameOn())
    {
        if (bullet == Bullet::Kernel)
            WriteMemory<byte>(0xeb, 0x0045f1ec);
        else if (bullet == Bullet::Butter)
            WriteMemory<byte>(0x70, 0x0045f1ec);
        else // if (bullet == Bullet::Normal)
            WriteMemory<byte>(0x75, 0x0045f1ec);
    }
}

void PvZ::NoCrater(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0041d79e);
        else
            WriteMemory<byte>(0x75, 0x0041d79e);
    }
}

void PvZ::MushroomsAwake(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xeb, 0x0045de8e);

            auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
            auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
            asm_init();
            for (size_t i = 0; i < plant_count_max; i++)
            {
                auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
                auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
                auto plant_sleeping = ReadMemory<bool>(plant_offset + 0x143 + 0x14c * i);
                if (!plant_disappeared && !plant_crushed && plant_sleeping)
                {
                    uint32_t addr = plant_offset + 0x14c * i;
                    asm_mov_exx(Reg::EAX, addr);
                    asm_push(0);
                    asm_call(0x0045e860);
                }
            }
            asm_ret();
            asm_code_inject();
        }
        else
            WriteMemory<byte>(0x74, 0x0045de8e);
    }
}

void PvZ::StrongBlover(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x00466601);
        else
            WriteMemory<byte>(0x74, 0x00466601);
    }
}

void PvZ::StrongPeas(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x0046e429);
        else
            WriteMemory<byte>(0xe9, 0x0046e429);
    }
}

void PvZ::SetPlantExplode(Explode status)
{
    if (GameOn())
    {
        if (status == Explode::Immediately)
        {
            WriteMemory<byte>(0x74, 0x00463408);
        }
        else if (status == Explode::Never)
        {
            WriteMemory<byte>(0xeb, 0x00463408);
        }
        else // if (status == Explode::Normal)
        {
            WriteMemory<byte>(0x75, 0x00463408);
        }
    }
}

void PvZ::BeghouledFreeMove(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x81, 0x004208fb);
            WriteMemory<byte>(0x81, 0x00420533);
        }
        else
        {
            WriteMemory<byte>(0x85, 0x004208fb);
            WriteMemory<byte>(0x85, 0x00420533);
        }
    }
}

void PvZ::AttackSuperposition(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x84, 0x00464a97);
        else
            WriteMemory<byte>(0x85, 0x00464a97);
    }
}

void PvZ::PlantTorchwood(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x004633a4);
        else
            WriteMemory<byte>(0x75, 0x004633a4);
    }
}

void PvZ::PlantGarlic(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0052ba41);
        else
            WriteMemory<byte>(0x75, 0x0052ba41);
    }
}

void PvZ::PlantUmbrella(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0041d3f8);
        else
            WriteMemory<byte>(0x75, 0x0041d3f8);
    }
}

void PvZ::PlantPaper(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x00465df2);
        else
            WriteMemory<byte>(0x74, 0x00465df2);
    }
}

// Zombies

// Jack-in-the-Box and Jalepeno Zombie
void PvZ::SetZombieExplode(Explode status)
{
    if (GameOn())
    {
        if (status == Explode::Immediately)
        {
            WriteMemory<byte>(0x80, 0x00526afc);
            WriteMemory<byte>(0x80, 0x005275dd);
        }
        else if (status == Explode::Never)
        {
            WriteMemory<byte>(0x81, 0x00526afc);
            WriteMemory<byte>(0x81, 0x005275dd);
        }
        else // if (status == Explode::Normal)
        {
            WriteMemory<byte>(0x8f, 0x00526afc);
            WriteMemory<byte>(0x85, 0x005275dd);
        }
    }
}

void PvZ::SetZombieVisibility(Visibility status)
{
    if (GameOn())
    {
        if (status == Visibility::Invisible)
        {
            WriteMemory<byte>(0x70, 0x0052e357);
            WriteMemory<byte>(0x70, 0x0053402b);
        }
        else if (status == Visibility::Visible)
        {
            WriteMemory<byte>(0xeb, 0x0052e357);
            WriteMemory<byte>(0xeb, 0x0053402b);
        }
        else // if (status == Visibility::Normal)
        {
            WriteMemory<byte>(0x75, 0x0052e357);
            WriteMemory<byte>(0x75, 0x0053402b);
        }
    }
}

void PvZ::SetZombieStrength(Strength status)
{
    if (GameOn())
    {
        if (status == Strength::Weak)
        {
            WriteMemory<int>(0x9090ff2b, 0x0053130f);
            WriteMemory<byte>(0xc9, 0x00531045);
            WriteMemory<int>(0xc28bd08b, 0x00530c9b);
            WriteMemory<byte>(0x80, 0x00532ba1);
            WriteMemory<byte>(0x74, 0x0046144a);
            WriteMemory<byte>(0x01, 0x0052fa82);
            WriteMemory(std::array<byte, 2>{0x74, 0x05}, 0x00466601);
            WriteMemory<byte>(0x74, 0x00458836);
        }
        else if (status == Strength::Invincible)
        {
            WriteMemory<int>(0x90909090, 0x0053130f);
            WriteMemory<byte>(0xc0, 0x00531045);
            WriteMemory<int>(0xd233c033, 0x00530c9b);
            WriteMemory<byte>(0x81, 0x00532ba1);
            WriteMemory<byte>(0xeb, 0x0046144a);
            WriteMemory<byte>(0x00, 0x0052fa82);
            WriteMemory(std::array<byte, 2>{0x90, 0x90}, 0x00466601);
            WriteMemory<byte>(0xeb, 0x00458836);
        }
        else // if (status == Strength::Normal)
        {
            WriteMemory<int>(0x20247c2b, 0x0053130f);
            WriteMemory<byte>(0xc8, 0x00531045);
            WriteMemory<int>(0xc28b027c, 0x00530c9b);
            WriteMemory<byte>(0x8d, 0x00532ba1);
            WriteMemory<byte>(0x74, 0x0046144a);
            WriteMemory<byte>(0x01, 0x0052fa82);
            WriteMemory(std::array<byte, 2>{0x74, 0x05}, 0x00466601);
            WriteMemory<byte>(0x74, 0x00458836);
        }
    }
}

void PvZ::StopSpawning(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x004265dc);
        else
            WriteMemory<byte>(0x74, 0x004265dc);
    }
}

void PvZ::ZombiesNoMove(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x54, 0x0052ab2b);
            WriteMemory<byte>(0x54, 0x0052ab34);
        }
        else
        {
            WriteMemory<byte>(0x64, 0x0052ab2b);
            WriteMemory<byte>(0x44, 0x0052ab34);
        }
    }
}

void PvZ::NoIceSlowDown(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory(std::array<byte, 3>{0x33, 0xc0, 0x90}, 0x0052b448);
        else
            WriteMemory(std::array<byte, 3>{0x83, 0xc0, 0xff}, 0x0052b448);
    }
}

void PvZ::NoButterImmobilize(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory(std::array<byte, 3>{0x33, 0xc0, 0x90}, 0x0052b464);
        else
            WriteMemory(std::array<byte, 3>{0x83, 0xc0, 0xff}, 0x0052b464);
    }
}

void PvZ::No3zGroup(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xeb, 0x0042694a);
            WriteMemory<byte>(0xeb, 0x00413083);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x0042694a);
            WriteMemory<byte>(0x75, 0x00413083);
        }
    }
}

void PvZ::NoIceTrail(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xc3, 0x0052a7b0);
            WriteMemory<byte>(0xeb, 0x0041f79a);
            if (GameUI() == 2 || GameUI() == 3)
                for (size_t i = 0; i < 6; ++i)
                    // disappear countdown
                    WriteMemory<int>(1, 0x6a9ec0, 0x768, 0x624 + i * 4);
        }
        else
        {
            WriteMemory<byte>(0x51, 0x0052a7b0);
            WriteMemory<byte>(0x75, 0x0041f79a);
        }
    }
}

void PvZ::NoThrowImp(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x00527205);
        else
            WriteMemory<byte>(0x7d, 0x00527205);
    }
}

void PvZ::GargantuarEatable(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x00, 0x00461457);
        else
            WriteMemory<byte>(0x01, 0x00461457);
    }
}

void PvZ::ZombossNoMove(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x00536080);
        else
            WriteMemory<byte>(0x83, 0x00536080);
    }
}

void PvZ::BalloonBurst(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x00525cab);
            WriteMemory<byte>(0x70, 0x00525cc6);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x00525cab);
            WriteMemory<byte>(0x74, 0x00525cc6);
        }
    }
}

void PvZ::GatherZombies(bool on, float pos)
{
    if (GameOn() && GameUI() == 3)
    {
        if (on)
        {
            std::array<byte, 9> code = {0xc7, 0x46, 0x2c, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x23};
            code[3] = ((byte *)&pos)[0];
            code[4] = ((byte *)&pos)[1];
            code[5] = ((byte *)&pos)[2];
            code[6] = ((byte *)&pos)[3];
            WriteMemory<byte>(0x32, 0x0052aa4a);
            WriteMemory(code, 0x0052ab18);
        }
        else
        {
            std::array<byte, 9> code = {0xe8, 0xc3, 0x13, 0x00, 0x00, 0x84, 0xc0, 0x75, 0x0f};
            WriteMemory<byte>(0x84, 0x0052aa4a);
            WriteMemory(code, 0x0052ab18);
        }
    }
}

void PvZ::SpawningNextWave()
{
    if (GameOn() && GameUI() == 3)
        WriteMemory<int>(1, 0x6a9ec0, 0x768, 0x559c);
}

void PvZ::AllZombiesXXX(int zombie_status)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto zombie_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x94);
        auto zombie_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x90);
        for (size_t i = 0; i < zombie_count_max; i++)
        {
            if (!ReadMemory<bool>(zombie_offset + 0xec + i * 0x15c)) // not disappear
            {
                switch (zombie_status)
                {
                    // zombieStatusList
                case 0: // Kill
                    WriteMemory<int>(3, zombie_offset + 0x28 + i * 0x15c);
                    break;
                case 1: // Hypno
                    WriteMemory<bool>(true, zombie_offset + 0xb8 + i * 0x15c);
                    break;
                case 2: // Freeze
                    WriteMemory<int>(600, zombie_offset + 0xb4 + i * 0x15c);
                    WriteMemory<int>(20000, zombie_offset + 0xac + i * 0x15c);
                    break;
                case 3: // Decelerate
                    WriteMemory<int>(1, zombie_offset + 0xb4 + i * 0x15c);
                    WriteMemory<int>(20000, zombie_offset + 0xac + i * 0x15c);
                    break;
                case 4: // Immobilize
                    WriteMemory<int>(500, zombie_offset + 0xb0 + i * 0x15c);
                    break;
                case 5: // Blow Away
                    WriteMemory<bool>(true, zombie_offset + 0xb9 + i * 0x15c);
                    break;
                case 6: // Dying
                    WriteMemory<bool>(false, zombie_offset + 0xba + i * 0x15c);
                    break;
                case 7: // Disappear
                    WriteMemory<int>(1, zombie_offset + 0x28 + i * 0x15c);
                    break;
                case 8: // Black
                    WriteMemory<int>(2, zombie_offset + 0x28 + i * 0x15c);
                    break;
                case 9: // Bigger
                    WriteMemory<float>(2.0f, zombie_offset + 0x11c + i * 0x15c);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

// Spawn

// generate type from seed
void PvZ::UpdateZombiesType()
{
    asm_init();
    asm_mov_exx_dword_ptr(Reg::ESI, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::ESI, 0x768);
    asm_mov_exx_dword_ptr_exx_add(Reg::ESI, 0x160);
    asm_call(0x00425840);
    asm_ret();
    asm_code_inject();
}

// generate list from type
void PvZ::UpdateZombiesList()
{
    asm_init();
    asm_mov_exx_dword_ptr(Reg::EDI, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EDI, 0x768);
    asm_call(0x004092e0);
    asm_ret();
    asm_code_inject();
}

void PvZ::UpdateZombiesPreview()
{
    WriteMemory<byte>(0x80, 0x0043a153);
    asm_init();
    asm_mov_exx_dword_ptr(Reg::EBX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EBX, 0x768);
    asm_call(0x0040df70);
    asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x15c);
    asm_push_exx(Reg::EAX);
    asm_call(0x0043a140);
    asm_ret();
    asm_code_inject();
    WriteMemory<byte>(0x85, 0x0043a153);
}

std::array<uint32_t, 1000> PvZ::GetSpawnList()
{
    std::array<uint32_t, 1000> zl;
    zl.fill(-1);

    if (!GameOn())
        return zl;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return zl;

    zl = ReadMemory<uint32_t, 1000>(0x6a9ec0, 0x768, 0x6b4);

#ifdef _DEBUG
    std::cout << std::dec; // ffffffff -> -1
    std::cout << std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 50; j++)
            std::cout << zl[i * 50 + j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif

    for (size_t i = 0; i < 20; i++)
    {
        // 每一波遇到 -1 之后忽略后面的出怪
        // 所以就算读到了数据也改成 -1
        bool ignore_rest = false;
        for (size_t j = 0; j < 50; j++)
        {
            if (zl[i * 50 + j] == 0xFFFFFFFF)  // -1
            {
                ignore_rest = true;
                continue;
            }
            if (ignore_rest)
            {
                zl[i * 50 + j] = -1;
            }
        }
    }

    emit SpawnList(zl);
    return zl;
}

void PvZ::InternalSpawn(std::array<bool, 33> zombies, bool original)
{
    if (original)
    {
        if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        {
            std::array<bool, 33> zombies = {false};
            WriteMemory(zombies, 0x6a9ec0, 0x768, 0x54d4);
            UpdateZombiesType();
            UpdateZombiesList();
            if (GameUI() == 2)
                UpdateZombiesPreview();
        }
    }
    else
    {
        if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        {
            auto zombies_type_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768) + 0x54d4;
            auto zombies_list_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768) + 0x6b4;

            // backup original zombie types
            auto zombies_type_original = ReadMemory<bool, 33>(zombies_type_offset);

            // zombies[0] for "Zombie", zombies[26] for "Peashooter Zombie"
            // game will crash if neither them was set when using call 0x004092e0
            // so replace the zombie which has the minimal id with Peashooter Zombie
            bool has_normal_zombie = (zombies[0] || zombies[26]) ? true : false;
            uint32_t replace_zombie = 0;
            if (!has_normal_zombie)
            {
                for (size_t i = 0; i < 33; i++)
                    if (zombies[i])
                    {
                        replace_zombie = i;
                        break;
                    }
            }

            WriteMemory(zombies, zombies_type_offset);
            if (!has_normal_zombie)
            {
                WriteMemory<bool>(false, zombies_type_offset + replace_zombie * sizeof(bool));
                WriteMemory<bool>(true, zombies_type_offset + 26 * sizeof(bool));
            }

            std::array<uint32_t, 1000> zombies_list;
            std::fill(zombies_list.begin(), zombies_list.end(), -1);
            WriteMemory(zombies_list, zombies_list_offset);

            UpdateZombiesList();

            // change replace zombie back after the zombies list was generated
            if (!has_normal_zombie)
            {
                auto zombies_list = ReadMemory<uint32_t, 1000>(zombies_list_offset);
                for (size_t i = 0; i < 1000; i++)
                {
                    if (zombies_list[i] == 26)
                        WriteMemory<uint32_t>(replace_zombie, zombies_list_offset + i * sizeof(uint32_t));
                }
            }

            if (GameUI() == 2)
                UpdateZombiesPreview();

            // restore original zombie types
            WriteMemory(zombies_type_original, zombies_type_offset);
        }
    }

    GetSpawnList();
}

void PvZ::CustomizeSpawn(std::array<bool, 33> zombies, bool simulate, bool limit_flag, bool limit_yeti, bool limit_bungee, bool limit_giga, std::array<bool, 20> giga_waves)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        std::array<uint32_t, 1000> *zombies_list = new std::array<uint32_t, 1000>;
        std::fill((*zombies_list).begin(), (*zombies_list).end(), -1);

        bool has_flag = zombies[1];
        bool has_yeti = zombies[19];
        bool has_bungee = zombies[20];
        bool has_giga = zombies[32];

        int count = 0;
        for (size_t i = 0; i < 33; i++)
            if (zombies[i])
                count++;

        if (count > 0)
        {
            std::vector<double> weights = {20, 0, 37, 67, 95, 37, 108, 67, 37, 0, 0, 67, 67, 67, 52, 37, 67, 37, 37, 17, 0, 37, 52, 52, 0, 0, 120, 94, 37, 67, 67, 67, 36};
            std::vector<double> weights_flag = {84, 10, 29, 50, 71, 29, 80, 50, 28, 0, 0, 50, 50, 49, 39, 29, 50, 29, 29, 10, 28, 29, 39, 39, 0, 0, 89, 70, 28, 50, 50, 50, 122};
            std::discrete_distribution<unsigned int> dist(weights.begin(), weights.end());
            std::discrete_distribution<unsigned int> dist_flag(weights_flag.begin(), weights_flag.end());
            auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::mt19937 gen(seed);

            uint32_t type = 0;
            for (size_t i = 0; i < 1000; i++)
            {
                do
                {
                    if (simulate)
                    {
                        if (((i / 50) % 10) == 9) // flag wave
                            type = dist_flag(gen);
                        else
                            type = dist(gen);
                    }
                    else
                    {
                        (++type) %= 33;
                    }
                } while ((!zombies[type])                              //
                         || (has_flag && limit_flag && type == 1)      //
                         || (has_yeti && limit_yeti && type == 19)     //
                         || (has_bungee && limit_bungee && type == 20) //
                         || (has_giga && limit_giga && type == 32 && !giga_waves[(i / 50) % 20]));

                (*zombies_list)[i] = type;
            }

            std::vector<size_t> index_flag = {450, 950};
            std::vector<size_t> index_bungee = {451, 452, 453, 454, 951, 952, 953, 954};

            if (has_flag && limit_flag)
            {
                for (auto i : index_flag)
                    (*zombies_list)[i] = 1;
            }

            if (has_bungee && limit_bungee)
            {
                for (auto i : index_bungee)
                    (*zombies_list)[i] = 20;
            }

            if (has_yeti && limit_yeti)
            {
                uint32_t i;
                do
                {
                    i = rand() % 1000;
                } while ((has_flag && limit_flag && std::find(index_flag.begin(), index_flag.end(), i) != index_flag.end()) //
                         || (has_bungee && limit_bungee && std::find(index_bungee.begin(), index_bungee.end(), i) != index_bungee.end()));
                (*zombies_list)[i] = 19;
            }
        }

        WriteMemory((*zombies_list), 0x6a9ec0, 0x768, 0x6b4);

        if (GameUI() == 2)
            UpdateZombiesPreview();

        // giga count in some wave may be 0 in simulate mode in some extreme cases
        if (simulate && has_giga)
        {
            int test_giga_count[20] = {0};
            for (int w = 0; w < 20; w++)
                for (int j = 0; j < 50; j++)
                    if ((*zombies_list)[j + w * 50] == 32)
                        test_giga_count[w]++;
            bool ok = true;
            for (int w = 0; w < 20; w++)
            {
                if (!((!limit_giga && (test_giga_count[w] > 0)) || (limit_giga && ((test_giga_count[w] > 0) == giga_waves[w]))))
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                CustomizeSpawn(zombies, simulate, limit_flag, limit_yeti, limit_bungee, limit_giga, giga_waves);
        }

        delete zombies_list;

        GetSpawnList();
    }

#ifdef _DEBUG
    auto zombies_list = ReadMemory<uint32_t, 1000>(0x6a9ec0, 0x768, 0x6b4);
    std::cout << std::dec;

    std::cout << "zombies list: " << std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 50; j++)
            std::cout << zombies_list[i * 50 + j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int zombies_type_count[33] = {0};
    for (size_t i = 0; i < 1000; i++)
        zombies_type_count[zombies_list[i]]++;

    std::cout << "target type: ";
    for (size_t i = 0; i < 33; i++)
        std::cout << zombies[i] << " ";
    std::cout << std::endl;

    std::cout << "type count: ";
    for (size_t t = 0; t < 33; t++)
        std::cout << zombies_type_count[t] << " ";
    std::cout << std::endl;

    std::array<int, 33> weights = {25, 0, 22, 43, 63, 22, 73, 43, 22, 0, 0, 43, 43, 43, 33, 22, 43, 22, 22, 0, 16, 22, 33, 33, 0, 0, 82, 63, 22, 43, 43, 43, 27};
    for (size_t t = 0; t < 33; t++)
        if ((simulate && weights[t] != 0) && !simulate)
            assert(zombies[t] == (zombies_type_count[t] > 0 ? true : false));

    int flag_count[20] = {0};
    int yeti_count[20] = {0};
    int bungee_count[20] = {0};
    int giga_count[20] = {0};
    for (int w = 0; w < 20; w++)
        for (int j = 0; j < 50; j++)
        {
            if (zombies_list[j + w * 50] == 1)
                flag_count[w]++;
            else if (zombies_list[j + w * 50] == 19)
                yeti_count[w]++;
            else if (zombies_list[j + w * 50] == 20)
                bungee_count[w]++;
            else if (zombies_list[j + w * 50] == 32)
                giga_count[w]++;
        }

    std::cout << "flag ";
    for (int w = 0; w < 20; ++w)
        std::cout << flag_count[w] << (((w == 8) || (w == 18)) ? "  " : " ");
    std::cout << std::endl;

    std::cout << "yeti ";
    for (int w = 0; w < 20; ++w)
        std::cout << yeti_count[w] << (((w == 8) || (w == 18)) ? "  " : " ");
    std::cout << std::endl;

    std::cout << "bungee ";
    for (int w = 0; w < 20; ++w)
        std::cout << bungee_count[w] << (((w == 8) || (w == 18)) ? "  " : " ");
    std::cout << std::endl;

    std::cout << "target giga wave ";
    for (int w = 0; w < 20; ++w)
        std::cout << giga_waves[w] << (((w == 8) || (w == 18)) ? "  " : " ");
    std::cout << std::endl;

    std::cout << "giga wave ";
    for (int w = 0; w < 20; ++w)
        std::cout << giga_count[w] << (((w == 8) || (w == 18)) ? "  " : " ");
    std::cout << std::endl;

    bool has_flag = zombies[1];
    bool has_yeti = zombies[19];
    bool has_bungee = zombies[20];
    bool has_giga = zombies[32];

    bool flag_waves[20] = {false};
    flag_waves[9] = true;
    flag_waves[19] = true;
    bool bungee_waves[20] = {false};
    bungee_waves[9] = true;
    bungee_waves[19] = true;

    std::cout << "simulate: " << simulate << std::endl;
    std::cout << "limit_flag: " << limit_flag << std::endl;
    std::cout << "limit_yeti: " << limit_yeti << std::endl;
    std::cout << "limit_bungee: " << limit_bungee << std::endl;
    std::cout << "limit_giga: " << limit_giga << std::endl;

    for (int w = 0; w < 20; ++w)
    {
        assert(!has_flag                                                                        //
               || (has_flag && !limit_flag && (flag_count[w] > 0))                              //
               || (has_flag && limit_flag && ((flag_count[w] == 1) == flag_waves[w])));         //
        assert(!has_bungee                                                                      //
               || (has_bungee && !limit_bungee && (bungee_count[w] > 0))                        //
               || (has_bungee && limit_bungee && ((bungee_count[w] == 4) == bungee_waves[w]))); //
        assert(!has_yeti                                                                        //
               || (has_yeti && !limit_yeti && (yeti_count[w] > 0))                              //
               || (has_yeti && limit_yeti && ((yeti_count[w] == 0) || (yeti_count[w] == 1))));  //
        assert(!has_giga                                                                        //
               || (has_giga && !limit_giga && (giga_count[w] > 0))                              //
               || (has_giga && limit_giga && ((giga_count[w] > 0) == giga_waves[w])));          //
    }

    if (has_yeti && limit_yeti)
        assert(zombies_type_count[19] == 1);
#endif
}

int PvZ::GetRandomSeed()
{
    int random_seed = 0;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        random_seed = ReadMemory<int>(0x6a9ec0, 0x768, 0x561c);
        emit RandomSeed(random_seed);
    }

    return random_seed;
}

void PvZ::SetRandomSeed(int seed)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        WriteMemory<int>(seed, 0x6a9ec0, 0x768, 0x561c);
}

// Slots

void PvZ::SetSlotsCount(int num)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        WriteMemory<byte>(0xc3, 0x0041bee0);
        asm_init();
        asm_mov_exx(Reg::EAX, num);
        asm_mov_exx_dword_ptr(Reg::ESI, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::ESI, 0x768);
        asm_mov_exx_dword_ptr_exx_add(Reg::ESI, 0x144);
        asm_call(0x00489cd0);
        asm_ret();
        asm_code_inject();
        WriteMemory<byte>(0x56, 0x0041bee0);
    }
}

void PvZ::HideSlots(bool on)
{
    if (GameOn())
        WriteMemory<bool>(!on, 0x6a9ec0, 0x768, 0x144, 0x18);
}

void PvZ::ShowShovel(bool on)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (on)
            WriteMemory<bool>(true, 0x6a9ec0, 0x768, 0x55f1);
        else
            WriteMemory<bool>(false, 0x6a9ec0, 0x768, 0x55f1);
    }
}

void PvZ::LockShovel(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x39, 0x004123a3);
            WriteMemory<int>(6, 0x6a9ec0, 0x768, 0x138, 0x30);
        }
        else
            WriteMemory<byte>(0x89, 0x004123a3);
    }
}

int PvZ::GetSeedType(int index)
{
    int seed_type = 0;
    int seed_imitater_type = 0;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        seed_type = ReadMemory<int>(0x6a9ec0, 0x768, 0x144, 0x5c + index * 0x50);
        seed_imitater_type = ReadMemory<int>(0x6a9ec0, 0x768, 0x144, 0x60 + index * 0x50);
        if (seed_type == 48)
        {
            emit SeedType(seed_imitater_type);
            emit SeedImitater(true);
        }
        else
        {
            emit SeedType(seed_type);
            emit SeedImitater(false);
        }
    }

    return seed_type;
}

// index: 0~9
// type: 0~47 (Pea ~ Cob)
void PvZ::SetSeedType(int index, int type, bool imitater = false)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if ((type >= 0 && type <= 52) && (type == 48 || imitater))
        {
            WriteMemory<int>(48, 0x6a9ec0, 0x768, 0x144, 0x5c + index * 0x50);
            WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x144, 0x60 + index * 0x50);
        }
        else
        {
            WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x144, 0x5c + index * 0x50);
            WriteMemory<int>(-1, 0x6a9ec0, 0x768, 0x144, 0x60 + index * 0x50);
        }
    }
}

bool PvZ::GetSeedVisible(int index)
{
    bool visible = false;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        visible = ReadMemory<bool>(0x6a9ec0, 0x768, 0x144, 0x40 + index * 0x50);
        emit SeedVisible(visible);
    }

    return visible;
}

void PvZ::SetSeedVisible(int index, bool visible)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        WriteMemory<bool>(visible, 0x6a9ec0, 0x768, 0x144, 0x40 + index * 0x50);
}

void PvZ::IgnoreSun(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x0041ba72);
            WriteMemory<byte>(0x3b, 0x0041ba74);
            WriteMemory<byte>(0x91, 0x0041bac0);
            WriteMemory<byte>(0x80, 0x00427a92);
            WriteMemory<byte>(0x80, 0x00427dfd);
            WriteMemory<byte>(0xeb, 0x0042487f);
        }
        else
        {
            WriteMemory<byte>(0x7f, 0x0041ba72);
            WriteMemory<byte>(0x2b, 0x0041ba74);
            WriteMemory<byte>(0x9e, 0x0041bac0);
            WriteMemory<byte>(0x8f, 0x00427a92);
            WriteMemory<byte>(0x8f, 0x00427dfd);
            WriteMemory<byte>(0x74, 0x0042487f);
        }
    }
}

void PvZ::SlotsNoCoolDown(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x00487296);
            WriteMemory<byte>(0xeb, 0x00488250);
        }
        else
        {
            WriteMemory<byte>(0x7e, 0x00487296);
            WriteMemory<byte>(0x75, 0x00488250);
        }
    }
}

void PvZ::PurpleSeedUnlimited(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory(std::array<byte, 3>{0xb0, 0x01, 0xc3}, 0x0041d7d0);
            WriteMemory<byte>(0xeb, 0x0040e477);
        }
        else
        {
            WriteMemory(std::array<byte, 3>{0x51, 0x83, 0xf8}, 0x0041d7d0);
            WriteMemory<byte>(0x74, 0x0040e477);
        }
    }
}

void PvZ::PlantingFreely(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x81, 0x0040fe30);
            WriteMemory<byte>(0xeb, 0x00438e40);
            WriteMemory<byte>(0x8d, 0x0042a2d9);
        }
        else
        {
            WriteMemory<byte>(0x84, 0x0040fe30);
            WriteMemory<byte>(0x74, 0x00438e40);
            WriteMemory<byte>(0x84, 0x0042a2d9);
        }
    }
}

void PvZ::BeltNoDelay(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x80, 0x00422d20);
            WriteMemory<byte>(0x33, 0x00489ca1);
        }
        else
        {
            WriteMemory<byte>(0x8f, 0x00422d20);
            WriteMemory<byte>(0x85, 0x00489ca1);
        }
    }
}

void PvZ::HideMenuButton(bool on)
{
    if (GameOn())
    {
        int ui = GameUI();
        if (on)
        {
            WriteMemory<bool>(true, 0x0043b9e0);
            WriteMemory<bool>(true, 0x0043c39f);
            if (ui == 2)
                WriteMemory<bool>(true, 0x6a9ec0, 0x774, 0x9c, 0xf9);
            else if (ui == 3)
                WriteMemory<bool>(true, 0x6a9ec0, 0x768, 0x148, 0xf9);
        }
        else
        {
            WriteMemory<bool>(false, 0x0043b9e0);
            WriteMemory<bool>(false, 0x0043c39f);
            if (ui == 2)
                WriteMemory<bool>(false, 0x6a9ec0, 0x774, 0x9c, 0xf9);
            else if (ui == 3)
                WriteMemory<bool>(false, 0x6a9ec0, 0x768, 0x148, 0xf9);
        }
    }
}

int PvZ::GetSpeed(int index)
{
    int speed = 0;

    if (GameOn())
    {
        speed = ReadMemory<int>(0x69f2cc + index * 0x24);
        emit Speed(speed);
    }

    return speed;
}

void PvZ::SetSpeed(int index, int speed)
{
    if (GameOn())
        WriteMemory<int>(speed, 0x69f2cc + index * 0x24);
}

int PvZ::GetCost(int index)
{
    int cost = 0;

    if (GameOn())
    {
        cost = ReadMemory<int>(0x69f2c0 + index * 0x24);
        emit Cost(cost);
    }

    return cost;
}

void PvZ::SetCost(int index, int cost)
{
    if (GameOn())
        WriteMemory<int>(cost, 0x69f2c0 + index * 0x24);
}

int PvZ::GetRecharge(int index)
{
    int recharge = 0;

    if (GameOn())
    {
        recharge = ReadMemory<int>(0x69f2c4 + index * 0x24);
        emit Recharge(recharge);
    }

    return recharge;
}

void PvZ::SetRecharge(int index, int recharge)
{
    if (GameOn())
        WriteMemory<int>(recharge, 0x69f2c4 + index * 0x24);
}

// Scene

int PvZ::GetScene()
{
    int scene = -1;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        scene = ReadMemory<int>(0x6a9ec0, 0x768, 0x554c);
        emit Scene(scene);
    }

    return scene;
}

void PvZ::SetScene(int scene)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        WriteMemory<int>(scene, 0x6a9ec0, 0x768, 0x554c);

        asm_init();
        asm_mov_exx_dword_ptr(Reg::ESI, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::ESI, 0x768);
        asm_call(0x0040a160);
        asm_ret();
        asm_code_inject();

        // 0.none 1.land 2.water
        int row_0[6] = {1, 1, 1, 1, 1, 0};
        int row_1[6] = {1, 1, 2, 2, 1, 1};

        switch (scene)
        {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            for (size_t r = 0; r < 6; r++)
                SetRowType(r, row_0[r]);
            break;
        case 2:
        case 3:
            for (size_t r = 0; r < 6; r++)
                SetRowType(r, row_1[r]);
            break;
        default:
            break;
        }

        // 1.lawn 2.bare 3.pool
        int block_0[6] = {1, 1, 1, 1, 1, 2};
        int block_1[6] = {1, 1, 3, 3, 1, 1};

        switch (scene)
        {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            for (size_t r = 0; r < 6; r++)
                for (size_t c = 0; c < 9; c++)
                    SetBlockType(r, c, block_0[r]);
            break;
        case 2:
        case 3:
            for (size_t r = 0; r < 6; r++)
                for (size_t c = 0; c < 9; c++)
                    SetBlockType(r, c, block_1[r]);
            break;
        default:
            break;
        }

        if (scene != 2 && scene != 3) // 泳池和雾夜仍然保留水波光
        {
            auto particle_systems_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x820, 0x0, 0x0);
            auto particle_systems_count_max = ReadMemory<uintptr_t>(0x6a9ec0, 0x820, 0x0, 0x4);

            asm_init();
            for (size_t i = 0; i < particle_systems_count_max; i++)
            {
                auto particle_systems_type = ReadMemory<int>(particle_systems_offset + 0x00 + 0x2c * i);
                auto particle_systems_dead = ReadMemory<bool>(particle_systems_offset + 0x1c + 0x2c * i);
                if (!particle_systems_dead && particle_systems_type == 34)
                {
                    uintptr_t addr = particle_systems_offset + 0x2c * i;
                    asm_push(addr);
                    asm_call(0x005160c0);
                }
            }
            asm_ret();
            asm_code_inject();

            WriteMemory<int>(0, 0x6a9ec0, 0x768, 0x5620);
        }
    }
}

int PvZ::GetRowCount()
{
    int scene = GetScene();
    return (scene == 2 || scene == 3) ? 6 : 5;
}

void PvZ::asm_plant(int row, int col, int type, bool imitater, bool iz_style)
{
    if (imitater && !iz_style) // imitater
    {
        asm_push(type);
        asm_push(48);
        asm_mov_exx(Reg::EAX, row);
        asm_push(col);
        asm_mov_exx_dword_ptr(Reg::EBP, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBP, 0x768);
        asm_push_exx(Reg::EBP);
        asm_call(0x0040d120);
        asm_add_word(0xf08b); // mov esi, eax
        asm_push_exx(Reg::EAX);
        asm_call(0x00466b80);
        asm_add_byte(0x58); // pop eax
    }
    else
    {
        asm_push(-1);
        asm_push(type);
        asm_mov_exx(Reg::EAX, row);
        asm_push(col);
        asm_mov_exx_dword_ptr(Reg::EBP, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBP, 0x768);
        asm_push_exx(Reg::EBP);
        asm_call(0x0040d120);
    }

    if (iz_style) // I, Zombie style
    {
        asm_push_exx(Reg::EAX);
        asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x768);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x160);
        asm_call(0x0042a530);
    }
}

void PvZ::Plant(int row, int col, int type, bool imitater)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int row_count = GetRowCount();        // 6 or 5
        int col_count = (type == 47 ? 8 : 9); // Cob Cannon cannot be planted at col 9
        int width = (type == 47 ? 2 : 1);     // Cob Cannon's width is 2
        int mode = GameMode();
        bool iz_style = (mode >= 61 && mode <= 70);
        asm_init();
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c += width)
                    asm_plant(r, c, type, imitater, iz_style);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c += width)
                asm_plant(row, c, type, imitater, iz_style);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                asm_plant(r, col, type, imitater, iz_style);
        else
            asm_plant(row, col, type, imitater, iz_style);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::asm_put_zombie(int row, int col, int type)
{
    asm_push(col);
    asm_push(type);
    asm_mov_exx(Reg::EAX, row);
    asm_mov_exx_dword_ptr(Reg::ECX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::ECX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(Reg::ECX, 0x160);
    asm_call(0x0042a0f0);
}

void PvZ::PutZombie(int row, int col, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (type == 25)
        {
            asm_init();
            asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
            asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x768);
            asm_push(0);
            asm_push(25);
            asm_call(0x0040ddc0);
            asm_ret();
            asm_code_inject();
            return;
        }
        int row_count = GetRowCount();
        int col_count = 9;
        asm_init();
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c++)
                    asm_put_zombie(r, c, type);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c++)
                asm_put_zombie(row, c, type);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                asm_put_zombie(r, col, type);
        else
            asm_put_zombie(row, col, type);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::asm_put_grave(int row, int col)
{
    asm_mov_exx_dword_ptr(Reg::EDX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EDX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(Reg::EDX, 0x160);
    asm_push_exx(Reg::EDX);
    asm_mov_exx(Reg::EDI, row);
    asm_mov_exx(Reg::EBX, col);
    asm_call(0x00426620);
}

void PvZ::PutGrave(int row, int col)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int row_count = GetRowCount();
        int col_count = 9;
        asm_init();
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c++)
                    asm_put_grave(r, c);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c++)
                asm_put_grave(row, c);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                asm_put_grave(r, col);
        else
            asm_put_grave(row, col);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::asm_put_rake(int row, int col)
{
    asm_push(row);
    asm_push(col);
    asm_mov_exx_dword_ptr(Reg::ECX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::ECX, 0x768);
    asm_push_exx(Reg::ECX);
    asm_call(0x0040b9c0);
    asm_add_exx(Reg::ESP, 0x08);
}

void PvZ::PutRake(int row, int col)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int row_count = GetRowCount();
        int col_count = 9;
        asm_init();
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c++)
                    asm_put_rake(r, c);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c++)
                asm_put_rake(row, c);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                asm_put_rake(r, col);
        else
            asm_put_rake(row, col);
        asm_ret();
        WriteMemory<int>(0x0000a681, 0x0040b9e3);
        WriteMemory<byte>(0x00, 0x0040bb2b);
        WriteMemory<int>(0x900c4d8b, 0x0040bb3b);
        WriteMemory<int>(0x9010458b, 0x0040bb41);
        asm_code_inject();
        WriteMemory<int>(0x00027984, 0x0040b9e3);
        WriteMemory<byte>(0xff, 0x0040bb2b);
        WriteMemory<int>(0x10244c8b, 0x0040bb3b);
        WriteMemory<int>(0x1424448b, 0x0040bb41);
    }
}

// type = 1 ~ 6
void PvZ::asm_put_coin(int row, int col, int type, int scene)
{
    int x;
    int y;
    int r = row + 1;
    int c = col + 1;

    x = 80 * c;
    switch (scene)
    {
    case 2: // pool
    case 3: // fog
        y = 55 + 85 * r;
        break;
    case 4: // roof
    case 5: // moon
        if (c >= 6.0)
            y = 45 + 85 * r;
        else
            y = 45 + 85 * r + 20 * (6 - c);
        break;
    case 0: // day
    case 1: // night
    case 6: // mushroom garden
    case 7: // zen garden
    case 8: // aquarium garden
    case 9: // tree of wisdom
    default:
        y = 40 + 100 * r;
        break;
    }
    y -= 40;

    asm_push(2); // 0 ~ 5
    asm_push(type);
    asm_push(y);
    asm_push(x);
    asm_mov_exx_dword_ptr(Reg::ECX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::ECX, 0x768);
    asm_call(0x0040cb10);
}

void PvZ::PutCoin(int row, int col, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int scene = GetScene();
        int row_count = (scene == 2 || scene == 3) ? 6 : 5;
        int col_count = 9;
        asm_init();
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c++)
                    asm_put_coin(r, c, type, scene);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c++)
                asm_put_coin(row, c, type, scene);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                asm_put_coin(r, col, type, scene);
        else
            asm_put_coin(row, col, type, scene);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::asm_put_ladder(int row, int col)
{
    asm_mov_exx(Reg::EDI, row);
    asm_push(col);
    asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x768);
    asm_call(0x00408f40);
}

void PvZ::PutLadder(int row, int col)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int row_count = GetRowCount();
        int col_count = 9;
        asm_init();
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c++)
                    asm_put_ladder(r, c);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c++)
                asm_put_ladder(row, c);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                asm_put_ladder(r, col);
        else
            asm_put_ladder(row, col);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::AutoLadder(bool imitater_pumpkin_only)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        bool has_ladder[6][9] = {{false}};
        ClearItems(3); // Ladders

        // auto grid_item_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x120);
        // auto grid_item_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x11c);
        // for (size_t i = 0; i < grid_item_count_max; i++)
        // {
        //     auto grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
        //     auto grid_item_type = ReadMemory<int>(grid_item_offset + 0x08 + 0xec * i); // 3 for Ladder
        //     auto grid_item_row = ReadMemory<uint32_t>(grid_item_offset + 0x14 + 0xec * i);
        //     auto grid_item_col = ReadMemory<uint32_t>(grid_item_offset + 0x10 + 0xec * i);
        //     if (!grid_item_disappeared && grid_item_type == 3)
        //         has_ladder[grid_item_row][grid_item_col] = true;
        // }

        auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
        asm_init();
        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            auto plant_type = ReadMemory<uint32_t>(plant_offset + 0x24 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed && plant_type == 30) // 30 for Pumpkin
            {
                auto plant_row = ReadMemory<uint32_t>(plant_offset + 0x1c + 0x14c * i);
                auto plant_col = ReadMemory<uint32_t>(plant_offset + 0x28 + 0x14c * i);
                auto is_imitater = ReadMemory<int>(plant_offset + 0x138 + 0x14c * i) == 48;
                auto block_type = ReadMemory<int>(0x6a9ec0, 0x768, 0x168 + 0x04 * plant_row + 0x18 * plant_col); // 1 for lawn
                if (plant_col != 0 && block_type == 1 && !has_ladder[plant_row][plant_col])
                    if (!imitater_pumpkin_only || (imitater_pumpkin_only && is_imitater))
                        asm_put_ladder(plant_row, plant_col);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

int PvZ::GetBlockType(int row, int col)
{
    int type = 1;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        type = ReadMemory<int>(0x6a9ec0, 0x768, 0x168 + row * 0x04 + col * 0x18);
        emit BlockType(type);
    }

    return type;
}

// 1.lawn 2.bare 3.pool
void PvZ::SetBlockType(int row, int col, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        uint32_t row_count = GetRowCount();
        uint32_t col_count = 9;
        if (row == -1 && col == -1)
            for (size_t r = 0; r < row_count; r++)
                for (size_t c = 0; c < col_count; c++)
                    WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + r * 0x04 + c * 0x18);
        else if (row != -1 && col == -1)
            for (size_t c = 0; c < col_count; c++)
                WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + row * 0x04 + c * 0x18);
        else if (row == -1 && col != -1)
            for (size_t r = 0; r < row_count; r++)
                WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + r * 0x04 + col * 0x18);
        else
            WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + row * 0x04 + col * 0x18);
    }
}

int PvZ::GetRowType(int row)
{
    int type = 0;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        type = ReadMemory<int>(0x6a9ec0, 0x768, 0x5d8 + row * 0x04);
        emit RowType(type);
    }

    return type;
}

// 0.none 1.land 2.water
void PvZ::SetRowType(int row, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (row == -1)
            for (size_t r = 0; r < 6; r++)
                WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x5d8 + r * 0x04);
        else
            WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x5d8 + row * 0x04);
    }
}

void PvZ::SetMusic(int id)
{
    asm_init();
    asm_mov_exx(Reg::EDI, id);
    asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x83c);
    asm_call(0x0045b750);
    asm_ret();
    asm_code_inject();
}

// 1 Grave
// 2 Crater
// 3 Ladder
// 4/5 Portal
// 7 Vase
// 10 Snail
// 11 Rake
// 12 Brain
void PvZ::ClearItems(int index)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        asm_init();
        auto grid_item_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x120);
        auto grid_item_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x11c);
        for (size_t i = 0; i < grid_item_count_max; i++)
        {
            auto grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
            auto grid_item_type = ReadMemory<int>(grid_item_offset + 0x8 + 0xec * i);
            if (!grid_item_disappeared && grid_item_type == index)
            {
                int addr = grid_item_offset + 0xec * i;
                asm_mov_exx(Reg::ESI, addr);
                asm_call(0x0044d000);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::StartLawnMowers()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto lawn_mower_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x104);
        auto lawn_mower_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x100);
        asm_init();
        for (size_t i = 0; i < lawn_mower_count_max; i++)
        {
            auto lawn_mower_disappeared = ReadMemory<bool>(lawn_mower_offset + 0x30 + 0x48 * i);
            if (!lawn_mower_disappeared)
            {
                uint32_t addr = lawn_mower_offset + 0x48 * i;
                asm_mov_exx(Reg::ESI, addr);
                asm_call(0x00458da0);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::ClearLawnMowers()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto lawn_mower_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x104);
        auto lawn_mower_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x100);
        asm_init();
        for (size_t i = 0; i < lawn_mower_count_max; i++)
        {
            auto lawn_mower_disappeared = ReadMemory<bool>(lawn_mower_offset + 0x30 + 0x48 * i);
            if (!lawn_mower_disappeared)
            {
                uint32_t addr = lawn_mower_offset + 0x48 * i;
                asm_mov_exx(Reg::EAX, addr);
                asm_call(0x00458d10);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::ResetLawnMowers()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        ClearLawnMowers();

        WriteMemory<unsigned short>(0x60eb, 0x0040bc98);
        WriteMemory<byte>(0x01, 0x0040bd17);
        WriteMemory<unsigned short>(0x99fc, 0x00458002);
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x768);
        asm_push_exx(Reg::EAX);
        asm_call(0x0040bc70);
        asm_ret();
        asm_code_inject();
        WriteMemory<unsigned short>(0x0975, 0x0040bc98);
        WriteMemory<byte>(0x00, 0x0040bd17);
        WriteMemory<unsigned short>(0x9bf8, 0x00458002);
    }
}

// Lineup

void PvZ::SetQuickLineupMode(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            // Auto Collect
            WriteMemory<byte>(0xeb, 0x0043158f);
            // Cob Cannon No CD
            WriteMemory<byte>(0x80, 0x0046103b);
            // Plant Invincible
            WriteMemory(std::array<byte, 3>{0x46, 0x40, 0x00}, 0x0052fcf1);
            WriteMemory<byte>(0xeb, 0x0041cc2f);
            WriteMemory<byte>(0xeb, 0x005276ea);
            WriteMemory(std::array<byte, 3>{0x90, 0x90, 0x90}, 0x0046cfeb);
            WriteMemory(std::array<byte, 3>{0x90, 0x90, 0x90}, 0x0046d7a6);
            WriteMemory<byte>(0xeb, 0x0052e93b);
            WriteMemory<byte>(0x70, 0x0045ee0a);
            WriteMemory<byte>(0x00, 0x0045ec66);
            WriteMemory(std::array<byte, 3>{0xc2, 0x04, 0x00}, 0x00462b80);
            // Stop Spawning
            WriteMemory<byte>(0xeb, 0x004265dc);
            // Ignore Sun
            WriteMemory<byte>(0x70, 0x0041ba72);
            WriteMemory<byte>(0x3b, 0x0041ba74);
            WriteMemory<byte>(0x91, 0x0041bac0);
            WriteMemory<byte>(0x80, 0x00427a92);
            WriteMemory<byte>(0x80, 0x00427dfd);
            WriteMemory<byte>(0xeb, 0x0042487f);
            // Slots No CD
            WriteMemory<byte>(0x70, 0x00487296);
            WriteMemory<byte>(0xeb, 0x00488250);
            // Purple Seed Unlimited
            WriteMemory(std::array<byte, 3>{0xb0, 0x01, 0xc3}, 0x0041d7d0);
            WriteMemory<byte>(0xeb, 0x0040e477);
            // No Fog
            WriteMemory<unsigned short>(0xd231, 0x0041a68d);
        }
        else
        {
            // Auto Collect
            WriteMemory<byte>(0x75, 0x0043158f);
            // Cob Cannon No CD
            WriteMemory<byte>(0x85, 0x0046103b);
            // Plant Invincible
            WriteMemory(std::array<byte, 3>{0x46, 0x40, 0xfc}, 0x0052fcf1);
            WriteMemory<byte>(0x74, 0x0041cc2f);
            WriteMemory<byte>(0x75, 0x005276ea);
            WriteMemory(std::array<byte, 3>{0x29, 0x50, 0x40}, 0x0046cfeb);
            WriteMemory(std::array<byte, 3>{0x29, 0x4e, 0x40}, 0x0046d7a6);
            WriteMemory<byte>(0x74, 0x0052e93b);
            WriteMemory<byte>(0x75, 0x0045ee0a);
            WriteMemory<byte>(0xce, 0x0045ec66);
            WriteMemory(std::array<byte, 3>{0x53, 0x55, 0x8b}, 0x00462b80);
            // Stop Spawning
            WriteMemory<byte>(0x74, 0x004265dc);
            // Ignore Sun
            WriteMemory<byte>(0x7f, 0x0041ba72);
            WriteMemory<byte>(0x2b, 0x0041ba74);
            WriteMemory<byte>(0x9e, 0x0041bac0);
            WriteMemory<byte>(0x8f, 0x00427a92);
            WriteMemory<byte>(0x8f, 0x00427dfd);
            WriteMemory<byte>(0x74, 0x0042487f);
            // Slots No CD
            WriteMemory<byte>(0x7e, 0x00487296);
            WriteMemory<byte>(0x75, 0x00488250);
            // Purple Seed Unlimited
            WriteMemory(std::array<byte, 3>{0x51, 0x83, 0xf8}, 0x0041d7d0);
            WriteMemory<byte>(0x74, 0x0040e477);
            // No Fog
            WriteMemory<unsigned short>(0xf23b, 0x0041a68d);
        }
    }
}

void PvZ::QuickPass()
{
    if (!GameOn())
        return;
    if (GameUI() != 3)
        return;

    Bot bot(this->hwnd);

    if (true)
    {
        int game_clock = ReadMemory<int>(0x6a9ec0, 0x768, 0x5568);
        int time_to_wait = 75 - ((game_clock + 500) % 75);
        if (ReadMemory<bool>(0x6a9ec0, 0x768, 0x164))
        {
            if (time_to_wait != 0)
            {
                bot.PressSpace(); // 解除暂停
                Sleep(time_to_wait * 10);
                bot.PressSpace(); // 暂停
            }
        }
        else
        {
            Sleep(time_to_wait * 10);
            bot.PressSpace(); // 暂停
        }
    }

    Sleep(10);
    asm_init();
    asm_mov_exx_dword_ptr(Reg::ECX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::ECX, 0x768);
    asm_call(0x0040c3e0);
    asm_ret();
    asm_code_inject();

    Sleep(10);
    auto zombie_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x94);
    auto zombie_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x90);
    for (size_t i = 0; i < zombie_count_max; i++)
        if (!ReadMemory<bool>(zombie_offset + 0xec + i * 0x15c))   // not disappear
            WriteMemory<int>(3, zombie_offset + 0x28 + i * 0x15c); // kill

    if (true)
    {
        Sleep(10);
        bot.PressSpace(); // 解除暂停
    }

    Sleep(100);
    WriteMemory<int>(8000, 0x6a9ec0, 0x768, 0x5560);
    WriteMemory<int>(1009, 0x6a9ec0, 0x768, 0x160, 0x6c);
}

void PvZ::ClearAllGraves()
{
    // if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    // {
    //     auto grid_item_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x120);
    //     auto grid_item_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x11c);

    //     asm_init();
    //     for (size_t i = 0; i < grid_item_count_max; i++)
    //     {
    //         auto grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
    //         auto grid_item_type = ReadMemory<int>(grid_item_offset + 0x08 + 0xec * i); // 1 for Grave
    //         auto grid_item_row = ReadMemory<uint32_t>(grid_item_offset + 0x14 + 0xec * i);
    //         auto grid_item_col = ReadMemory<uint32_t>(grid_item_offset + 0x10 + 0xec * i);
    //         if (!grid_item_disappeared && grid_item_type == 1)
    //             asm_plant(grid_item_row, grid_item_col, 11, false, false); // 11 for Grave Buster
    //     }
    //     asm_ret();
    //     asm_code_inject();
    // }

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        ClearItems(1);
}

void PvZ::LilyPadOnPool(int to_col)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
        bool has_plant[6][9] = {{false}};

        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            auto plant_row = ReadMemory<uint32_t>(plant_offset + 0x1c + 0x14c * i);
            auto plant_col = ReadMemory<uint32_t>(plant_offset + 0x28 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
                has_plant[plant_row][plant_col] = true;
        }

        asm_init();
        int rows = GetRowCount();
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                auto block_type = ReadMemory<int>(0x6a9ec0, 0x768, 0x168 + 0x04 * r + 0x18 * c);
                if (block_type == 3 && !has_plant[r][c] && c <= to_col - 1) // 3 for pool
                    asm_plant(r, c, 16, false, false);                      // 16 for Lily Pad
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::FlowerPotOnRoof(int to_col)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int scene = GetScene();
        if (scene == 4 || scene == 5) // Roof or Moon
        {
            auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
            auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
            bool has_plant[5][9] = {{false}};

            for (size_t i = 0; i < plant_count_max; i++)
            {
                auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
                auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
                auto plant_row = ReadMemory<uint32_t>(plant_offset + 0x1c + 0x14c * i);
                auto plant_col = ReadMemory<uint32_t>(plant_offset + 0x28 + 0x14c * i);
                if (!plant_disappeared && !plant_crushed)
                    has_plant[plant_row][plant_col] = true;
            }

            asm_init();
            for (int r = 0; r < 5; r++)
                for (int c = 0; c < 9; c++)
                    if (!has_plant[r][c] && c <= to_col - 1)
                        asm_plant(r, c, 33, false, false);
            asm_ret();
            asm_code_inject();
        }
    }
}

void PvZ::ClearAllPlants()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);

        asm_init();
        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
            {
                uint32_t addr = plant_offset + 0x14c * i;
                asm_push(addr);
                asm_call(0x004679b0);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::SetLineup(std::string str, bool enable_switch_scene, bool keep_hp_status)
{
    auto split = [](const std::string &str, char seperator) -> std::vector<std::string> {
        std::vector<std::string> result;
        std::string::size_type prev = 0, pos = 0;
        while ((pos = str.find(seperator, pos)) != std::string::npos)
        {
            std::string sub_string(str.substr(prev, pos - prev));
            result.push_back(sub_string);
            prev = ++pos;
        }
        result.push_back(str.substr(prev, pos - prev));
        return result;
    };

    auto hex2dec = [](const std::string &str) -> long {
        char *ptr;
        long num;
        num = strtol(str.c_str(), &ptr, 16);
        return num;
    };

    const bool may_sleep[] = {false, false, false, false, false, false, false, false,
                              true, true, true, false, true, true, true, true,
                              false, false, false, false, false, false, false, false,
                              true, false, false, false, false, false, false, true,
                              false, false, false, false, false, false, false, false,
                              false, false, true, false, false, false, false, false};

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        std::vector<std::string> str_list = split(str, ',');
        size_t count = str_list.size() - 1;

        std::string str_scene = str_list[0];
        int game_scene = GetScene();
        bool same_scene = ((str_scene == "0" && game_scene == 2)    //
                           || (str_scene == "1" && game_scene == 3) //
                           || (str_scene == "2" && game_scene == 0) //
                           || (str_scene == "3" && game_scene == 1) //
                           || (str_scene == "4" && game_scene == 4) //
                           || (str_scene == "5" && game_scene == 5));

        if (!same_scene && !enable_switch_scene)
        {
            emit ShowMessageStatusBar(tr("The target lineup scene is inconsistent with the current scene."));
            return;
        }

        switch (atoi(str_scene.c_str()))
        {
        case 0: // pool
            game_scene = 2;
            break;
        case 1: // fog
            game_scene = 3;
            break;
        case 2: // day
            game_scene = 0;
            break;
        case 3: // night
            game_scene = 1;
            break;
        case 4: // roof
            game_scene = 4;
            break;
        case 5: // moon
            game_scene = 5;
            break;
        default:
            break;
        }

        ClearItems(1);  // Grave
        ClearItems(3);  // Ladder
        ClearItems(11); // Rake
        ClearAllPlants();
        SetScene(game_scene);

        auto has_lawn_mower = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x110) > 0;
        if (has_lawn_mower)
        {
            ClearLawnMowers();
            ResetLawnMowers();
        }

        std::vector<std::array<int, 6>> items;
        for (size_t i = 0; i < count; i++)
        {
            std::array<int, 6> item;
            std::vector<std::string> item_str = split(str_list[i + 1], ' ');
            item[0] = hex2dec(item_str[0]);
            item[1] = atoi(item_str[1].c_str()) - 1;
            item[2] = atoi(item_str[2].c_str()) - 1;
            item[3] = atoi(item_str[3].c_str());
            item[4] = atoi(item_str[4].c_str());
            item[5] = atoi(item_str[5].c_str());
            items.push_back(item);
        }

        // create plants/ladder/rake/grave
        asm_init();
        for (size_t i = 0; i < count; i++)
        {
            int item_type = items[i][0];
            int item_row = items[i][1];
            int item_col = items[i][2];
            [[maybe_unused]] int item_state_row = items[i][3];
            [[maybe_unused]] int item_state_col = items[i][4];
            bool item_imitater = (items[i][5] == 0) ? false : true;

            if ((item_type >= 0) && (item_type <= 0x2f)) // plants
                asm_plant(item_row, item_col, item_type, item_imitater, false);
            else if (item_type == 0x30) // ladder
                asm_put_ladder(item_row, item_col);
            else if (item_type == 0x31) // rake
                asm_put_rake(item_row, item_col);
            else if (item_type == 0x32) // grave
                asm_put_grave(item_row, item_col);
        }
        asm_ret();
        WriteMemory<int>(0x0000a681, 0x0040b9e3);
        WriteMemory<byte>(0x00, 0x0040bb2b);
        WriteMemory<int>(0x900c4d8b, 0x0040bb3b);
        WriteMemory<int>(0x9010458b, 0x0040bb41);
        asm_code_inject();
        WriteMemory<int>(0x00027984, 0x0040b9e3);
        WriteMemory<byte>(0xff, 0x0040bb2b);
        WriteMemory<int>(0x10244c8b, 0x0040bb3b);
        WriteMemory<int>(0x1424448b, 0x0040bb41);

        std::vector<std::array<int, 5>> plants;
        auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
            {
                auto plant_type = ReadMemory<uint32_t>(plant_offset + 0x24 + 0x14c * i);
                auto plant_row = ReadMemory<uint32_t>(plant_offset + 0x1c + 0x14c * i);
                auto plant_col = ReadMemory<uint32_t>(plant_offset + 0x28 + 0x14c * i);
                auto is_imitater = ReadMemory<int>(plant_offset + 0x138 + 0x14c * i) == 48;
                std::array<int, 5> plant;
                plant[0] = i;
                plant[1] = plant_type;
                plant[2] = plant_row;
                plant[3] = plant_col;
                plant[4] = is_imitater ? 1 : 0;
                plants.push_back(plant);
            }
        }

        size_t plant_count = plants.size();

        asm_init();
        for (size_t i = 0; i < plant_count; i++)
        {
            int plant_index = plants[i][0];
            int plant_type = plants[i][1];
            int plant_row = plants[i][2];
            int plant_col = plants[i][3];
            bool is_imitater = (plants[i][4] == 0) ? false : true;
            for (size_t j = 0; j < count; j++)
            {
                int item_type = items[j][0];
                int item_row = items[j][1];
                int item_col = items[j][2];
                int item_state_row = items[j][3];
                int item_state_col = items[j][4];
                bool item_imitater = (items[j][5] == 0) ? false : true;
                // which means this plant is the same one in string
                if (item_type == plant_type && item_row == plant_row && item_col == plant_col && item_imitater == is_imitater)
                {

                    // wake up mushrooms
                    if ((game_scene == 0 || game_scene == 2 || game_scene == 4) && may_sleep[plant_type] && item_state_row == 1)
                    {
                        auto plant_sleeping = ReadMemory<bool>(plant_offset + 0x143 + 0x14c * plant_index);
                        if (plant_sleeping)
                        {
                            uint32_t addr = plant_offset + 0x14c * plant_index;
                            asm_mov_exx(Reg::EAX, addr);
                            asm_push(0);
                            asm_call(0x0045e860);
                        }
                    }

                    // Potato Mine and Sun-shroom grow up
                    // 0 should be ok, here reserved 1s for wake up call to excecute first
                    if ((plant_type == 4) || (plant_type == 9 && item_state_row == 1 && (item_state_col == 2 || item_state_col == 3)))
                        WriteMemory<uint32_t>(100, plant_offset + 0x54 + 0x14c * plant_index);

                    // set hp status
                    if (keep_hp_status)
                    {
                        // Pumpkin HP status
                        if (item_type == 30)
                        {
                            auto plant_hp_max = ReadMemory<uint32_t>(plant_offset + 0x44 + 0x14c * plant_index);
                            if (item_state_row == 1) // damage piont 1
                                WriteMemory<uint32_t>(plant_hp_max * 2 / 3 - 1, plant_offset + 0x40 + 0x14c * plant_index);
                            else if (item_state_row == 2) // damage piont 2
                                WriteMemory<uint32_t>(plant_hp_max * 1 / 3 - 1, plant_offset + 0x40 + 0x14c * plant_index);
                        }
                        // Wall-nut / Tall-nut / Pumpkin / Garlic / Spikerock HP status
                        else if (plant_type == 3 || plant_type == 23 || plant_type == 36 || plant_type == 46)
                        {
                            // FIXME Spikerock issue
                            auto plant_hp_max = ReadMemory<uint32_t>(plant_offset + 0x44 + 0x14c * plant_index);
                            if (item_state_col == 1) // damage piont 1
                                WriteMemory<uint32_t>(plant_hp_max * 2 / 3 - 1, plant_offset + 0x40 + 0x14c * plant_index);
                            else if (item_state_col == 2) // damage piont 2
                                WriteMemory<uint32_t>(plant_hp_max * 1 / 3 - 1, plant_offset + 0x40 + 0x14c * plant_index);
                        }
                    }

                    break; // theoretically there can be only one and same plant on each grid
                }
            }
        }
        asm_ret();
        asm_code_inject();
    }
    Sleep(10);
}

std::string PvZ::GetLineup(bool keep_hp_status)
{
    auto int_to_hex_string = [](unsigned int num) -> std::string {
        std::stringstream sstream;
        sstream << std::hex << num;
        std::string str = sstream.str();
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    };

    const bool may_sleep[] = {false, false, false, false, false, false, false, false,
                              true, true, true, false, true, true, true, true,
                              false, false, false, false, false, false, false, false,
                              true, false, false, false, false, false, false, true,
                              false, false, false, false, false, false, false, false,
                              false, false, true, false, false, false, false, false};

    std::string str;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int str_scene = 0;
        int game_scene = GetScene();
        switch (game_scene)
        {
        case 0: // day
            str_scene = 2;
            break;
        case 1: // night
            str_scene = 3;
            break;
        case 2: // pool
        default:
            str_scene = 0;
            break;
        case 3: // fog
            str_scene = 1;
            break;
        case 4: // roof
            str_scene = 4;
            break;
        case 5: // moon
            str_scene = 5;
            break;
        }
        str += std::to_string(str_scene);

        // item_row
        // item_col
        // item_type
        // item_state_row
        // item_state_col
        // item_imitater
        std::vector<std::array<int, 6>> items;

        auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            auto plant_type = ReadMemory<uint32_t>(plant_offset + 0x24 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed && (plant_type >= 0 && plant_type <= 47))
            {
                auto plant_row = ReadMemory<uint32_t>(plant_offset + 0x1c + 0x14c * i);
                auto plant_col = ReadMemory<uint32_t>(plant_offset + 0x28 + 0x14c * i);
                auto plant_hp = ReadMemory<uint32_t>(plant_offset + 0x40 + 0x14c * i);
                auto plant_hp_max = ReadMemory<uint32_t>(plant_offset + 0x44 + 0x14c * i);
                auto plant_sleeping = ReadMemory<bool>(plant_offset + 0x143 + 0x14c * i);
                auto is_imitater = ReadMemory<int>(plant_offset + 0x138 + 0x14c * i) == 48;
                auto plant_countdown = ReadMemory<uint32_t>(plant_offset + 0x54 + 0x14c * i);

                std::array<int, 6> item;
                // [0]
                item[0] = plant_row + 1;
                // [1]
                item[1] = plant_col + 1;
                // [2]
                item[2] = plant_type;
                // [3]
                if (may_sleep[plant_type]) // mushrooms
                    item[3] = plant_sleeping ? 0 : 1;
                else if (plant_type == 30 && keep_hp_status) // pumpkin
                {
                    uint32_t damage_piont_2 = plant_hp_max * 1 / 3;
                    uint32_t damage_piont_1 = plant_hp_max * 2 / 3;
                    if (0 <= plant_hp && plant_hp < damage_piont_2)
                        item[3] = 2;
                    else if (damage_piont_2 <= plant_hp && plant_hp < damage_piont_1)
                        item[3] = 1;
                    else
                        item[3] = 0;
                }
                else
                    item[3] = 0;
                // [4]
                if ((plant_type == 3 || plant_type == 23 || plant_type == 36 || plant_type == 46) && keep_hp_status)
                {
                    uint32_t damage_piont_2 = plant_hp_max * 1 / 3;
                    uint32_t damage_piont_1 = plant_hp_max * 2 / 3;
                    if (0 <= plant_hp && plant_hp < damage_piont_2)
                        item[4] = 2;
                    else if (damage_piont_2 <= plant_hp && plant_hp < damage_piont_1)
                        item[4] = 1;
                    else
                        item[4] = 0;
                }
                else if (plant_type == 9) // Sun-shroom
                {
                    if (plant_countdown == 0)
                        item[4] = 2; // 2 3
                    else
                        item[4] = 0; // 0 1
                }
                else
                    item[4] = 0;
                // [5]
                item[5] = is_imitater ? 1 : 0;
                items.push_back(item);
            }
        }

        auto grid_item_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x120);
        auto grid_item_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x11c);
        for (size_t i = 0; i < grid_item_count_max; i++)
        {
            auto grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
            auto grid_item_type = ReadMemory<uint32_t>(grid_item_offset + 0x08 + 0xec * i);
            if (!grid_item_disappeared && (grid_item_type == 1 || grid_item_type == 3 || grid_item_type == 11))
            {
                auto grid_item_row = ReadMemory<uint32_t>(grid_item_offset + 0x14 + 0xec * i);
                auto grid_item_col = ReadMemory<uint32_t>(grid_item_offset + 0x10 + 0xec * i);

                std::array<int, 6> item;
                item[0] = grid_item_row + 1;
                item[1] = grid_item_col + 1;
                if (grid_item_type == 3) // ladder
                    item[2] = 0x30;
                else if (grid_item_type == 11) // rake
                    item[2] = 0x31;
                else if (grid_item_type == 1) // grave
                    item[2] = 0x32;
                item[3] = 0;
                item[4] = 0;
                item[5] = 0;
                items.push_back(item);
            }
        }

        size_t count = items.size();

        // Lily Pad 16 -> -2
        // Flower Pot 33 -> -1
        // Pumpkin 30 -> 51
        // Plants
        // Coffee Bean 35 -> 52
        // Grave 50 -> 53
        // Rake 49 -> 54
        // Ladder 48 -> 55
        int priority[48 + 3] = {0, 1, 2, 3, 4, 5, 6, 7,         //
                                8, 9, 10, 11, 12, 13, 14, 15,   //
                                -2, 17, 18, 19, 20, 21, 22, 23, //
                                24, 25, 26, 27, 28, 29, 51, 31, //
                                32, -1, 34, 52, 36, 37, 38, 39, //
                                40, 41, 42, 43, 44, 45, 46, 47, //
                                55, 54, 53};

        // replace type with priority
        for (size_t i = 0; i < count; i++)
        {
            int index = items[i][2];
            items[i][2] = priority[index];
        }
        // sort
        std::sort(items.begin(), items.end());
        // replace back
        for (size_t i = 0; i < count; i++)
        {
            int prior = items[i][2];
            for (size_t index = 0; index < (48 + 3); index++)
                if (prior == priority[index])
                {
                    items[i][2] = index;
                    break;
                }
        }

        for (size_t i = 0; i < count; i++)
        {
            std::string item_str = ","                              //
                                   + int_to_hex_string(items[i][2]) //
                                   + " "                            //
                                   + std::to_string(items[i][0])    //
                                   + " "                            //
                                   + std::to_string(items[i][1])    //
                                   + " "                            //
                                   + std::to_string(items[i][3])    //
                                   + " "                            //
                                   + std::to_string(items[i][4])    //
                                   + " "                            //
                                   + std::to_string(items[i][5]);
            str += item_str;
        }

        emit LineupString(str);
    }

#ifdef _DEBUG
    std::cout << "Lineup String: " << std::endl
              << str << std::endl
              << std::endl;
#endif

    return str;
}

// Garden

void PvZ::FertilizerUnlimited(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x00, 0x0051f017);
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x1f8);
        }
        else
            WriteMemory<byte>(0xff, 0x0051f017);
    }
}

void PvZ::BugSprayUnlimited(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x00, 0x0051f110);
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x1fc);
        }
        else
            WriteMemory<byte>(0xff, 0x0051f110);
    }
}

void PvZ::ChocolateUnlimited(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x00, 0x0051ec38);
            WriteMemory<byte>(0x00, 0x0051ecb8);
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x228);
        }
        else
        {
            WriteMemory<byte>(0xff, 0x0051ec38);
            WriteMemory<byte>(0xff, 0x0051ecb8);
        }
    }
}

void PvZ::TreeFoodUnlimited(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x00, 0x0042d463);
            WriteMemory<int>(1020, 0x6a9ec0, 0x82c, 0x230);
        }
        else
            WriteMemory<byte>(0xff, 0x0042d463);
    }
}

void PvZ::SetTreeHeight(int height)
{
    if (GameOn())
    {
        if (GameMode() == 50) // Zen Garden
        {
            WriteMemory<int>(height - 1, 0x6a9ec0, 0x82c, 0xf4);
            asm_init();
            asm_mov_exx(Reg::EDI, 0x6a9ec0);
            asm_call(0x0042d1f0);
            asm_ret();
            asm_code_inject();
        }
        else
        {
            WriteMemory<int>(height, 0x6a9ec0, 0x82c, 0xf4);
        }
    }
}

std::vector<GardenPlant> PvZ::GetGardenPlants()
{
    std::vector<GardenPlant> plants;

    if (GameOn())
    {
        auto plant_count = ReadMemory<uint32_t>(0x6a9ec0, 0x82c, 0x350);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x82c) + 0x350;
        for (size_t i = 0; i < plant_count; i++)
        {
            GardenPlant plant;
            plant.index = i;
            plant.type = ReadMemory<int>(plant_offset + 0x8 + 0x58 * i);
            plant.scene = ReadMemory<int>(plant_offset + 0xc + 0x58 * i);
            plant.col = ReadMemory<int>(plant_offset + 0x10 + 0x58 * i);
            plant.row = ReadMemory<int>(plant_offset + 0x14 + 0x58 * i);
            plant.direction = ReadMemory<int>(plant_offset + 0x18 + 0x58 * i);
            plant.color = ReadMemory<int>(plant_offset + 0x28 + 0x58 * i);
            plant.status = ReadMemory<int>(plant_offset + 0x2c + 0x58 * i);
            plants.push_back(plant);
        }
        emit GardenPlants(plants);
    }

    return plants;
}

void PvZ::SetGardenPlants(std::vector<GardenPlant> plants)
{
    if (GameOn())
    {
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x82c) + 0x350;
        size_t count = plants.size();
        for (size_t i = 0; i < count; i++)
        {
            GardenPlant plant = plants[i];
            int index = plant.index;
            if (ReadMemory<int>(plant_offset + 0x8 + 0x58 * index) != plant.type)
                WriteMemory<int>(plant.type, plant_offset + 0x8 + 0x58 * index);
            if (ReadMemory<int>(plant_offset + 0xc + 0x58 * index) != plant.scene)
                WriteMemory<int>(plant.scene, plant_offset + 0xc + 0x58 * index);
            if (ReadMemory<int>(plant_offset + 0x10 + 0x58 * index) != plant.col)
                WriteMemory<int>(plant.col, plant_offset + 0x10 + 0x58 * index);
            if (ReadMemory<int>(plant_offset + 0x14 + 0x58 * index) != plant.row)
                WriteMemory<int>(plant.row, plant_offset + 0x14 + 0x58 * index);
            if (ReadMemory<int>(plant_offset + 0x18 + 0x58 * index) != plant.direction)
                WriteMemory<int>(plant.direction, plant_offset + 0x18 + 0x58 * index);
            if (ReadMemory<int>(plant_offset + 0x28 + 0x58 * index) != plant.color)
                WriteMemory<int>(plant.color, plant_offset + 0x28 + 0x58 * index);
            if (ReadMemory<int>(plant_offset + 0x2c + 0x58 * index) != plant.status)
                WriteMemory<int>(plant.status, plant_offset + 0x2c + 0x58 * index);
        }
        if (ReadMemory<uint32_t>(0x6a9ec0, 0x82c, 0x350) != count)
            WriteMemory<uint32_t>(count, 0x6a9ec0, 0x82c, 0x350);

        Bot bot(this->hwnd);
        if (GameUI() == 3)
            for (size_t i = 0; i < 4; i++)
                bot.Click(600, 30);
    }
}

// Vase

std::vector<Vase> PvZ::GetVases()
{
    std::vector<Vase> vases;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto grid_item_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0x120);
        auto grid_item_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x11c);
        for (size_t i = 0; i < grid_item_count_max; i++)
        {
            auto grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
            auto grid_item_type = ReadMemory<uint32_t>(grid_item_offset + 0x8 + 0xec * i);
            if (!grid_item_disappeared && grid_item_type == 7)
            {
                Vase vase;
                vase.index = i;
                vase.skin = ReadMemory<int>(grid_item_offset + 0xc + 0xec * i);
                vase.col = ReadMemory<int>(grid_item_offset + 0x10 + 0xec * i);
                vase.row = ReadMemory<int>(grid_item_offset + 0x14 + 0xec * i);
                vase.content_zombie = ReadMemory<int>(grid_item_offset + 0x3c + 0xec * i);
                vase.content_plant = ReadMemory<int>(grid_item_offset + 0x40 + 0xec * i);
                vase.type = ReadMemory<int>(grid_item_offset + 0x44 + 0xec * i);
                vase.content_sun = ReadMemory<int>(grid_item_offset + 0x50 + 0xec * i);
                vases.push_back(vase);
            }
        }
        emit Vases(vases);
    }

    return vases;
}

void PvZ::SetVases(std::vector<Vase> vases)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto grid_item_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0x11c);
        size_t count = vases.size();
        for (size_t i = 0; i < count; i++)
        {
            Vase vase = vases[i];
            int index = vase.index;
            if (ReadMemory<int>(grid_item_offset + 0x14 + 0xec * index) != vase.row)
                WriteMemory<int>(vase.row, grid_item_offset + 0x14 + 0xec * index);
            if (ReadMemory<int>(grid_item_offset + 0x10 + 0xec * index) != vase.col)
                WriteMemory<int>(vase.col, grid_item_offset + 0x10 + 0xec * index);
            if (ReadMemory<int>(grid_item_offset + 0xc + 0xec * index) != vase.skin)
                WriteMemory<int>(vase.skin, grid_item_offset + 0xc + 0xec * index);
            if (vase.type == 1) // Plant
            {
                if (ReadMemory<int>(grid_item_offset + 0x40 + 0xec * index) != vase.content_plant)
                    WriteMemory<int>(vase.content_plant, grid_item_offset + 0x40 + 0xec * index);
            }
            else if (vase.type == 2) // Zombie
            {
                if (ReadMemory<int>(grid_item_offset + 0x3c + 0xec * index) != vase.content_zombie)
                    WriteMemory<int>(vase.content_zombie, grid_item_offset + 0x3c + 0xec * index);
            }
            else if (vase.type == 3) // Sun
            {
                if (ReadMemory<int>(grid_item_offset + 0x50 + 0xec * index) != vase.content_sun)
                    WriteMemory<int>(vase.content_sun, grid_item_offset + 0x50 + 0xec * index);
            }
            if (ReadMemory<int>(grid_item_offset + 0x44 + 0xec * index) != vase.type)
                WriteMemory<int>(vase.type, grid_item_offset + 0x44 + 0xec * index);
        }
    }
}

// Effects

void PvZ::WisdomTreeCode(int code)
{
    if (GameOn())
    {
        Bot bot(this->hwnd);
        std::string str;
        switch (code)
        {
        case 0:
            str = "SUKHBIR";
            break;
        case 5:
            str = "FUTURE";
            break;
        case 20:
            str = "MUSTACHE";
            break;
        case 48:
            str = "TRICKEDOUT";
            break;
        case 99:
            str = "DAISIES";
            break;
        case 500:
            str = "DANCE";
            break;
        case 999:
            str = "PINATA";
            break;
        default:
            str = "";
        }
        for (size_t i = 0; i < str.length(); i++)
        {
            char key = str[i];
            bot.PressKey(key);
        }
    }
}

//  U U D D L R L R B A
void PvZ::KonamiCode()
{
    if (GameOn())
    {
        Bot bot(this->hwnd);
        bot.PressUp();
        bot.PressUp();
        bot.PressDown();
        bot.PressDown();
        bot.PressLeft();
        bot.PressRight();
        bot.PressLeft();
        bot.PressRight();
        bot.PressKey('B');
        bot.PressKey('A');
    }
}

void PvZ::ItsRaining(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x00426b4e);
            WriteMemory<byte>(0x70, 0x00416f07);
            WriteMemory<byte>(0xeb, 0x00424715);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x00426b4e);
            WriteMemory<byte>(0x75, 0x00416f07);
            WriteMemory<byte>(0x74, 0x00424715);
        }
    }
}

void PvZ::LittleZombie(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x00523ed5);
        else
            WriteMemory<byte>(0x74, 0x00523ed5);
    }
}

void PvZ::ColumnLike(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x80, 0x0043903d);
            WriteMemory<byte>(0x80, 0x00410ae7);
        }
        else
        {
            WriteMemory<byte>(0x85, 0x0043903d);
            WriteMemory<byte>(0x85, 0x00410ae7);
        }
    }
}

void PvZ::ZombieQuick(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x004248aa);
        else
            WriteMemory<byte>(0x75, 0x004248aa);
    }
}

void PvZ::WhackZombie(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x004538a2);
            WriteMemory<byte>(0xeb, 0x004222b1);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x004538a2);
            WriteMemory<byte>(0x74, 0x004222b1);
        }
    }
}

void PvZ::HighGravity(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x0046d546);
            WriteMemory<byte>(0x70, 0x0046dc28);
            WriteMemory<byte>(0x70, 0x00525bed);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x0046d546);
            WriteMemory<byte>(0x75, 0x0046dc28);
            WriteMemory<byte>(0x75, 0x00525bed);
        }
    }
}

void PvZ::GraveDanger(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x70, 0x004268fa);
            // WriteMemory<byte>(0x05, 0x00426925); // since wave 7
        }
        else
        {
            WriteMemory<byte>(0x75, 0x004268fa);
            // WriteMemory<byte>(0x05, 0x00426925);
        }
    }
}

void PvZ::StormyNight(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xeb, 0x00416eef);
            WriteMemory<byte>(0xeb, 0x00426b6b);
            WriteMemory<byte>(0xeb, 0x00426b35);
            WriteMemory<byte>(0xeb, 0x004246c9);
            WriteMemory<byte>(0xeb, 0x00424729);
        }
        else
        {
            WriteMemory<byte>(0x74, 0x00416eef);
            WriteMemory<byte>(0x74, 0x00426b6b);
            WriteMemory<byte>(0x74, 0x00426b35);
            WriteMemory<byte>(0x74, 0x004246c9);
            WriteMemory<byte>(0x74, 0x00424729);
        }
    }
}

void PvZ::BungeeBlitz(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x75, 0x00412f16);
        else
            WriteMemory<byte>(0x74, 0x00412f16);
    }
}

// row : 0~5
int PvZ::GetIceTrailX(int row)
{
    int x = 0;

    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        x = ReadMemory<int>(0x6a9ec0, 0x768, 0x60c + 0x4 * row);
        emit IceTrailX(x);
    }

    return x;
}

void PvZ::SetIceTrailX(int row, int x)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (row == -1)
        {
            for (size_t r = 0; r < 6; r++)
                WriteMemory<int>(x, 0x6a9ec0, 0x768, 0x60c + 0x4 * r);
        }
        else
        {
            WriteMemory<int>(x, 0x6a9ec0, 0x768, 0x60c + 0x4 * row);
        }
    }
}

void PvZ::FullFog(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x33, 0x0041c1c0);
            WriteMemory<byte>(0xc0, 0x0041c1c1);
            WriteMemory<byte>(0xc3, 0x0041c1c2);
            WriteMemory<byte>(0xeb, 0x0041a476);
            WriteMemory<byte>(0x3f, 0x0041a477);
            WriteMemory<byte>(0x00, 0x0041a4ba);
        }
        else
        {
            if (GameUI() == 2 || GameUI() == 3)
            {
                std::array<int, 63> fog = {0};
                WriteMemory(fog, 0x6a9ec0, 0x768, 0x4c8);
            }
            WriteMemory<byte>(0x8b, 0x0041c1c0);
            WriteMemory<byte>(0x81, 0x0041c1c1);
            WriteMemory<byte>(0x8c, 0x0041c1c2);
            WriteMemory<byte>(0x75, 0x0041a476);
            WriteMemory<byte>(0x05, 0x0041a477);
            WriteMemory<byte>(0x04, 0x0041a4ba);
        }
    }
}

void PvZ::NoFog(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<unsigned short>(0xd231, 0x0041a68d);
        else
            WriteMemory<unsigned short>(0xf23b, 0x0041a68d);
    }
}

void PvZ::SeeVase(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<int>(0x0033b866, 0x0044e5cc);
        else
            WriteMemory<int>(0x067ec085, 0x0044e5cc);
    }
}

// Others

void PvZ::DisableSaveData(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0054b267);
        else
            WriteMemory<byte>(0x74, 0x0054b267);
    }
}

void PvZ::DisableDeleteData(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x2e, 0x00482149);
        else
            WriteMemory<byte>(0x13, 0x00482149);
    }
}

void PvZ::RunningInBackground(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<short>(0x00eb, 0x0054eba8);
        else
            WriteMemory<short>(0x2e74, 0x0054eba8);
    }
}

void PvZ::DisablePause(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x004502c0);
        else
            WriteMemory<byte>(0x55, 0x004502c0);
    }
}

void PvZ::OpenDataDir()
{
    ShellExecuteW(nullptr, L"open", L"C:\\ProgramData\\PopCap Games\\PlantsVsZombies\\userdata", nullptr, nullptr, SW_SHOWNORMAL);
}

void PvZ::DebugMode(int mode)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        WriteMemory<int>(mode, 0x6a9ec0, 0x768, 0x55f8);
}

// Status

std::array<int, 12> PvZ::GetStatus()
{
    std::array<int, 12> status = {0};
    if (GameOn())
    {
        auto pvzbase = ReadMemory<uintptr_t>(0x6a9ec0);
        auto mainobject = ReadMemory<uintptr_t>(pvzbase + 0x768);
        status[0] = ReadMemory<int>(pvzbase + 0x7f8);          // game mode
        status[1] = ReadMemory<int>(pvzbase + 0x7fc);          // game ui
        status[2] = ReadMemory<int>(mainobject + 0x28);        // running time
        status[3] = ReadMemory<int>(mainobject + 0x160, 0x6c); // level completed
        status[4] = ReadMemory<int>(mainobject + 0x5564);      // total waves
        status[5] = ReadMemory<int>(mainobject + 0x557c);      // past waves
        status[6] = ReadMemory<int>(mainobject + 0x5598);      // total hp
        status[7] = ReadMemory<int>(mainobject + 0x5594);      // trigger hp
        status[8] = ReadMemory<int>(mainobject + 0x559c);      // countdown
        status[9] = ReadMemory<int>(mainobject + 0x55a4);      // hugewave countdown
        status[10] = ReadMemory<int>(mainobject + 0xbc);       // plant count
        status[11] = ReadMemory<int>(mainobject + 0xa0);       // zombie count
        emit GameStatus(status);
    }
    return status;
}

// Target Map

std::array<int, 54> PvZ::GetTargetMap(int mode)
{
    std::array<int, 54> map;
    map.fill(-1);

    if (GameOn())
    {
        int tmp[54] = {0};

        if (mode == 22)
            ReadProcessMemory(handle, (const void *)(0x006a3410), &tmp, 54 * sizeof(int), nullptr);
        else if (mode == 36)
            ReadProcessMemory(handle, (const void *)(0x006a3260), &tmp, 54 * sizeof(int), nullptr);
        else if (mode == 40)
            ReadProcessMemory(handle, (const void *)(0x006a3338), &tmp, 54 * sizeof(int), nullptr);

        std::copy(std::begin(tmp), std::end(tmp), std::begin(map));
        emit TargetMap(map);
    }

    return map;
}

// mode 22 36 40
void PvZ::SetTargetMap(int mode, std::array<int, 54> map)
{
    if (GameOn())
    {
        if (mode == 22)
            WriteMemory(map, 0x006a3410);
        else if (mode == 36)
            WriteMemory(map, 0x006a3260);
        else if (mode == 40)
            WriteMemory(map, 0x006a3338);
    }
}

// Cannon Launcher

void PvZ::GetCobInfo(int index)
{
    bool is_cob_cannon = false;
    int row = -1;
    int col = -1;
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
        auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * index);
        auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * index);
        auto plant_type = ReadMemory<unsigned int>(plant_offset + 0x24 + 0x14c * index);
        if (!plant_disappeared && !plant_crushed && plant_type == 47)
        {
            is_cob_cannon = true;
            row = ReadMemory<uint32_t>(plant_offset + 0x1c + 0x14c * index);
            col = ReadMemory<uint32_t>(plant_offset + 0x28 + 0x14c * index);
        }
        emit CobInfo(is_cob_cannon, row, col);
    }
}

void PvZ::asm_launch_cannon(int index, int x, int y)
{
    asm_mov_exx_dword_ptr(Reg::EAX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, 0xac);
    asm_add_byte((unsigned char)(0x05)); // add eax
    asm_add_dword(0x14c * index);
    asm_push(y);
    asm_push(x);
    asm_call(0x00466d50);
}

void PvZ::LaunchCannon(int index, int x, int y)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        asm_init();
        asm_launch_cannon(index, x, y);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::LaunchAllCannon(bool random_fall, int x, int y)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        asm_init();
        auto plant_count_max = ReadMemory<uint32_t>(0x6a9ec0, 0x768, 0xb0);
        auto plant_offset = ReadMemory<uintptr_t>(0x6a9ec0, 0x768, 0xac);
        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            auto plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            auto plant_type = ReadMemory<unsigned int>(plant_offset + 0x24 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed && plant_type == 47)
            {
                if (random_fall)
                {
                    int _x = rand() % 800;
                    int _y = rand() % 600;
                    asm_launch_cannon(i, _x, _y);
                }
                else
                {
                    asm_launch_cannon(i, x, y);
                }
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

// Portal

void PvZ::StartPortal(bool b)
{
    if (GameOn())
    {
        if (b)
        {
            if (GameUI() == 3)
            {
                bool has_portal = false;
                int grid_item_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x11c);
                int grid_item_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x120);
                for (int i = 0; i < grid_item_count_max; i++)
                {
                    bool grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
                    int grid_item_type = ReadMemory<int>(grid_item_offset + 0x8 + 0xec * i);
                    if (!grid_item_disappeared && (grid_item_type == 4 || grid_item_type == 5))
                    {
                        has_portal = true;
                        break;
                    }
                }
                if (!has_portal)
                    SetPortal(0, 2, 1, 9, 3, 9, 4, 2);
            }

            WriteMemory<byte>(0x70, 0x00467665);
            WriteMemory<byte>(0x70, 0x004248ce);
            WriteMemory<byte>(0x70, 0x0041ffb4);
        }
        else
        {
            WriteMemory<byte>(0x75, 0x00467665);
            WriteMemory<byte>(0x75, 0x004248ce);
            WriteMemory<byte>(0x75, 0x0041ffb4);

            if (GameUI() == 3)
            {
                asm_init();
                int grid_item_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x11c);
                int grid_item_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x120);
                for (int i = 0; i < grid_item_count_max; i++)
                {
                    bool grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
                    int grid_item_type = ReadMemory<int>(grid_item_offset + 0x8 + 0xec * i);
                    if (!grid_item_disappeared && (grid_item_type == 4 || grid_item_type == 5))
                    {
                        int addr = grid_item_offset + 0xec * i;
                        asm_mov_exx(Reg::ESI, addr);
                        asm_call(0x0044d000);
                    }
                }
                asm_ret();
                asm_code_inject();
            }
        }
    }
}

void PvZ::LockPortal(bool b)
{
    if (GameOn())
    {
        if (b)
            WriteMemory<byte>(0x00, 0x004276dd);
        else
            WriteMemory<byte>(0xff, 0x004276dd);
    }
}

void PvZ::SetPortal(int b1r, int b1c, int b2r, int b2c, int w1r, int w1c, int w2r, int w2c)
{
    if (GameOn() && GameUI() == 3)
    {
        asm_init();
        int grid_item_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x11c);
        int grid_item_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x120);
        for (int i = 0; i < grid_item_count_max; i++)
        {
            bool grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
            int grid_item_type = ReadMemory<int>(grid_item_offset + 0x8 + 0xec * i);
            if (!grid_item_disappeared && (grid_item_type == 4 || grid_item_type == 5))
            {
                int addr = grid_item_offset + 0xec * i;
                asm_mov_exx(Reg::ESI, addr);
                asm_call(0x0044d000);
            }
        }
        asm_ret();
        asm_code_inject();

        Sleep(10);
        WriteMemory<int>(b1r, 0x00426fe9);
        WriteMemory<int>(b1c, 0x00426fe2);
        WriteMemory<int>(b2r, 0x00427014);
        WriteMemory<int>(b2c, 0x0042700d);
        WriteMemory<int>(w1r, 0x00427044);
        WriteMemory<int>(w1c, 0x0042703d);
        WriteMemory<int>(w2r, (unsigned int)extra_code_addr + 11);
        WriteMemory<int>(w2c, (unsigned int)extra_code_addr + 4);

        Sleep(10);
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EDI, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDI, 0x768);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDI, 0x160);
        asm_call(0x00426fc0);
        asm_ret();
        asm_code_inject();

        Sleep(10);
        WriteMemory<int>(0, 0x00426fe9);
        WriteMemory<int>(2, 0x00426fe2);
        WriteMemory<int>(1, 0x00427014);
        WriteMemory<int>(9, 0x0042700d);
        WriteMemory<int>(3, 0x00427044);
        WriteMemory<int>(9, 0x0042703d);
        WriteMemory<int>(4, (unsigned int)extra_code_addr + 11);
        WriteMemory<int>(2, (unsigned int)extra_code_addr + 4);
    }
}

} // namespace Pt
