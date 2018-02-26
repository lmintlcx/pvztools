
#include "src/pvz.h"

const byte PVZ::magic_code[] = {        //  0
    0xb8, 0x78, 0x56, 0x34, 0x12,       //  5            mov eax, 0x12345678
    0x8b, 0x80, 0x78, 0x56, 0x34, 0x12, //  6            mov eax, [eax + 0x12345678]
    0x50,                               //  1            push eax
    0x58,                               //  1            pop eax
    0x3e, 0xa1, 0x78, 0x56, 0x34, 0x12, //  6            mov eax, ds:[0x12345678]
    // 5 + 6 + 1 + 1 + 6 = 19
    0xbb, 0x78, 0x56, 0x34, 0x12,             //  5      mov ebx, 0x12345678
    0x8b, 0x9b, 0x78, 0x56, 0x34, 0x12,       //  6      mov ebx, [ebx + 0x12345678]
    0x53,                                     //  1      push ebx
    0x5b,                                     //  1      pop ebx
    0x3e, 0x8b, 0x1d, 0x78, 0x56, 0x34, 0x12, //  7      mov ebx, ds :[0x12345678]
    // 5 + 6 + 1 + 1 + 7 = 20
    0xb9, 0x78, 0x56, 0x34, 0x12,             //  5      mov ecx, 0x12345678
    0x8b, 0x89, 0x78, 0x56, 0x34, 0x12,       //  6      mov ecx, [ecx + 0x12345678]
    0x51,                                     //  1      push ecx
    0x59,                                     //  1      pop ecx
    0x3e, 0x8b, 0x0d, 0x78, 0x56, 0x34, 0x12, //  7      mov ecx, ds :[0x12345678]
    // 5 + 6 + 1 + 1 + 7 = 20
    0xba, 0x78, 0x56, 0x34, 0x12,             //  5      mov edx, 0x12345678
    0x8b, 0x92, 0x78, 0x56, 0x34, 0x12,       //  6      mov edx, [edx + 0x12345678]
    0x52,                                     //  1      push edx
    0x5a,                                     //  1      pop edx
    0x3e, 0x8b, 0x15, 0x78, 0x56, 0x34, 0x12, //  7      mov edx, ds :[0x12345678]
    // 5 + 6 + 1 + 1 + 7 = 20
    0xbe, 0x78, 0x56, 0x34, 0x12,             //  5      mov esi, 0x12345678
    0x8b, 0xb6, 0x78, 0x56, 0x34, 0x12,       //  6      mov esi, [esi + 0x12345678]
    0x56,                                     //  1      push esi
    0x5e,                                     //  1      pop esi
    0x3e, 0x8b, 0x35, 0x78, 0x56, 0x34, 0x12, //  7      mov esi, ds :[0x12345678]
    // 5 + 6 + 1 + 1 + 7 = 20
    0xbf, 0x78, 0x56, 0x34, 0x12,             //  5      mov edi, 0x12345678
    0x8b, 0xbf, 0x78, 0x56, 0x34, 0x12,       //  6      mov edi, [edi + 0x12345678]
    0x57,                                     //  1      push edi
    0x5f,                                     //  1      pop edi
    0x3e, 0x8b, 0x3d, 0x78, 0x56, 0x34, 0x12, //  7      mov edi, ds :[0x12345678]
    // 5 + 6 + 1 + 1 + 7 = 20
    0xbd, 0x78, 0x56, 0x34, 0x12,             //  5      mov ebp, 0x12345678
    0x8b, 0xad, 0x78, 0x56, 0x34, 0x12,       //  6      mov ebp, [ebp + 0x12345678]
    0x55,                                     //  1      push ebp
    0x5d,                                     //  1      pop ebp
    0x3e, 0x8b, 0x2d, 0x78, 0x56, 0x34, 0x12, //  7      mov ebp, ds :[0x12345678]
    // 5 + 6 + 1 + 1 + 7 = 20
    0x68, 0x78, 0x56, 0x34, 0x12, //  5                  push 0x12345678
    0xe8, 0x02, 0x00, 0x00, 0x00, //  5                  call $ + 7
    0xeb, 0x06,                   //  2                  jmp short $ + 8
    0xc3};                        //  1                  ret

PVZ::PVZ()
{
    hwnd = nullptr, pid = 0, handle = nullptr;

    int page = 1;
    code = new byte[4096 * page];
    length = 0;
}

PVZ::~PVZ()
{
    if (handle != nullptr)
        CloseHandle(handle);
    hwnd = nullptr, pid = 0, handle = nullptr;
    delete code;
}

void PVZ::FindGame()
{
    hwnd = nullptr, pid = 0, handle = nullptr;
    hwnd = FindWindow(nullptr, TEXT("Plants vs. Zombies"));
    if (hwnd != nullptr)
        GetWindowThreadProcessId(hwnd, &pid);
    if (pid != 0)
        handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

    int result;
    if (handle == nullptr)
        result = -1; // Not Found
    else
    {
        int n = ReadMemory<int>(0x0042748e);
        if (n != 0xff563de8)
            result = 0; // Wrong Version
        else
            result = 1; // OK!
    }
    emit FindResult(result);
}

bool PVZ::GameOn()
{
    bool result = false;
    result = (ReadMemory<int>(0x6a9ec0) != 0);
    if (!result)
    {
        FindGame();
        result = (ReadMemory<int>(0x6a9ec0) != 0);
    }
    return result;
}

// Asm

void PVZ::asm_init()
{
    length = 0;
}

void PVZ::asm_add_byte(unsigned char value)
{
    code[length] = value;
    length += 1;
}

void PVZ::asm_add_word(unsigned short value)
{
    (unsigned short &)code[length] = value;
    length += 2;
}

void PVZ::asm_add_dword(unsigned int value)
{
    (unsigned int &)code[length] = value;
    length += 4;
}

void PVZ::asm_push(int value)
{
    asm_add_byte(magic_code[19 + 20 + 20 + 20 + 20 + 20 + 20]);
    asm_add_dword(value);
}

void PVZ::asm_mov_exx(Reg reg, int value)
{
    asm_add_byte(magic_code[reg]);
    asm_add_dword(value);
}

void PVZ::asm_mov_exx_dword_ptr(Reg reg, int value)
{
    if (reg == EAX)
    {
        asm_add_word((unsigned short &)magic_code[reg + 5 + 6 + 1 + 1]);
    }
    else
    {
        asm_add_byte(magic_code[reg + 5 + 6 + 1 + 1]);
        asm_add_word((unsigned short &)magic_code[reg + 5 + 6 + 1 + 2]);
    }
    asm_add_dword(value);
}

void PVZ::asm_mov_exx_dword_ptr_exx_add(Reg reg, int value)
{
    asm_add_word((unsigned short &)magic_code[reg + 5]);
    asm_add_dword(value);
}

void PVZ::asm_push_exx(Reg reg)
{
    asm_add_byte(magic_code[reg + 5 + 6]);
}

void PVZ::asm_pop_exx(Reg reg)
{
    asm_add_byte(magic_code[reg + 5 + 6 + 1]);
}

void PVZ::asm_call(int addr)
{
    asm_add_byte(magic_code[19 + 20 + 20 + 20 + 20 + 20 + 20 + 5]);
    asm_add_dword((unsigned int &)magic_code[19 + 20 + 20 + 20 + 20 + 20 + 20 + 5 + 1]);
    asm_add_word((unsigned short &)magic_code[19 + 20 + 20 + 20 + 20 + 20 + 20 + 5 + 5]);
    asm_push(addr);
    asm_ret();
}
void PVZ::asm_ret()
{
    asm_add_byte(magic_code[19 + 20 + 20 + 20 + 20 + 20 + 20 + 5 + 5 + 2]);
}

void PVZ::asm_code_inject()
{
    // for (int i = 0; i < length; i++)
    //     std::cout << std::hex << int(code[i]) << ", ";
    // std::cout << std::endl;
    WriteMemory<byte>(0xfe, 0x00552014);
    Sleep(10);
    LPVOID ThreadAddr = VirtualAllocEx(handle, nullptr, length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(handle, ThreadAddr, code, length, nullptr);
    HANDLE hThread = CreateRemoteThread(handle, nullptr, 0, LPTHREAD_START_ROUTINE(ThreadAddr), nullptr, 0, nullptr);
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    VirtualFreeEx(handle, ThreadAddr, 0, MEM_RELEASE);
    WriteMemory<byte>(0xdb, 0x00552014);
}

// Page 0 : Resources

void PVZ::SetSun(int sun)
{
    if (GameOn())
        WriteMemory<int>(sun, 0x6a9ec0, 0x768, 0x5560);
}

void PVZ::IncreaseSunLimit(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<int>(999999990, 0x00430a1f);
            WriteMemory<int>(999999990, 0x00430a2b);
        }
        else
        {
            WriteMemory<int>(9990, 0x00430a1f);
            WriteMemory<int>(9990, 0x00430a2b);
        }
    }
}

void PVZ::SetMoney(int money)
{
    if (GameOn())
        WriteMemory(money, 0x6a9ec0, 0x82c, 0x28);
}

void PVZ::IncreaseMoneyLimit(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory(999999999, 0x00430a74);
            WriteMemory(999999999, 0x00430a7d);
        }
        else
        {
            WriteMemory(99999, 0x00430a74);
            WriteMemory(99999, 0x00430a7d);
        }
    }
}

// 0.Normal 1.Many 2.None
void PVZ::SetFallingSun(int mode)
{
    if (GameOn())
    {
        if (mode == 0)
            WriteMemory<byte>(0x75, 0x00413B83);
        else if (mode == 1)
            WriteMemory<byte>(0x74, 0x00413B83);
        else if (mode == 2)
            WriteMemory<byte>(0xeb, 0x00413B83);
    }
}

void PVZ::AutoCollect(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x0043158f);
        else
            WriteMemory<byte>(0x75, 0x0043158f);
    }
}

void PVZ::CoinDisappear()
{
    if (GameOn() && GameUI() == 3)
    {
        int item_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xe8);
        int item_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xe4);
        for (int i = 0; i < item_count_max; i++)
        {
            bool item_disappeared = ReadMemory<bool>(item_offset + 0x38 + 0xd8 * i);
            int item_type = ReadMemory<int>(item_offset + 0x58 + 0xd8 * i);
            if (!item_disappeared && (item_type == 1 || item_type == 2 || item_type == 3))
                WriteMemory<bool>(true, item_offset + 0x38 + 0xd8 * i);
        }
    }
}

void PVZ::SetTreeHeight(int height)
{
    if (GameOn())
    {
        if (GameMode() == 50) // Zen Garden
        {
            WriteMemory<int>(height - 1, 0x6a9ec0, 0x82c, 0xf4);
            asm_init();
            asm_mov_exx(EDI, 0x6a9ec0);
            asm_call(0x0042d1f0);
            asm_ret();
            asm_code_inject();
        }
        else
            WriteMemory<int>(height, 0x6a9ec0, 0x82c, 0xf4);
    }
}

void PVZ::GetAllShopItems()
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
        WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x220); // Garden Rake

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
    }
}

void PVZ::FertilizerUnlimited(bool on)
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

void PVZ::BugSprayUnlimited(bool on)
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

void PVZ::ChocolateUnlimited(bool on)
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

void PVZ::TreeFoodUnlimited(bool on)
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

// Page 1 : Level

void PVZ::GetGoldSunflowerTrophy()
{
    if (GameOn())
    {
        if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x2c) < 2)
            WriteMemory<int>(2, 0x6a9ec0, 0x82c, 0x2c); // Adventure 2 times

        for (int i = 0; i < 33; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x6c + i * 4) == 0)
                WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x6c + i * 4); // Mini-games

        for (int i = 0; i < 9; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0xf8 + i * 4) == 0)
                WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0xf8 + i * 4); // Vasebreaker

        for (int i = 0; i < 9; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x120 + i * 4) == 0)
                WriteMemory<int>(1, 0x6a9ec0, 0x82c, 0x120 + i * 4); // I, Zombie

        for (int i = 0; i < 5; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x30 + i * 4) != 5)
                WriteMemory<int>(5, 0x6a9ec0, 0x82c, 0x30 + i * 4); // Survival

        for (int i = 0; i < 5; i++)
            if (ReadMemory<int>(0x6a9ec0, 0x82c, 0x44 + i * 4) != 10)
                WriteMemory<int>(10, 0x6a9ec0, 0x82c, 0x44 + i * 4); // Survival Hard
    }
}

void PVZ::UnlockAllMode(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            byte code_0[] = {0x31, 0xc0, 0xc3};
            byte code_1[] = {0x30, 0xc0, 0xc3};
            byte code_2[] = {0xb0, 0x01, 0xc3};
            WriteMemory<byte>(0x70, 0x00454109);
            WriteMemory<byte>(0x70, 0x0044a514);
            WriteArrayMemory<byte>(code_0, 3, 0x0042e440);
            WriteMemory<byte>(0xeb, 0x00449e9d);
            WriteArrayMemory<byte>(code_1, 3, 0x0048aad0);
            WriteMemory<byte>(0xeb, 0x0048a54c);
            WriteMemory<byte>(0xeb, 0x0048d32b);
            WriteMemory<byte>(0xeb, 0x0048c491);
            WriteMemory<byte>(0xeb, 0x00449e7a);
            WriteMemory<byte>(0xeb, 0x00453ad1);
            WriteMemory<int>(0x5beb01b0, 0x00403a10);
            WriteMemory<int>(0x00, 0x0069dca0);
            WriteArrayMemory<byte>(code_2, 3, 0x00403b30);
        }
        else
        {
            byte code_0[] = {0x51, 0x53, 0x55};
            byte code_1[] = {0x53, 0x8b, 0xd9};
            byte code_2[] = {0x8b, 0x80, 0x6c};
            WriteMemory<byte>(0x7e, 0x00454109);
            WriteMemory<byte>(0x7e, 0x0044a514);
            WriteArrayMemory<byte>(code_0, 3, 0x0042e440);
            WriteMemory<byte>(0x7f, 0x00449e9d);
            WriteArrayMemory<byte>(code_1, 3, 0x0048aad0);
            WriteMemory<byte>(0x7f, 0x0048a54c);
            WriteMemory<byte>(0x7f, 0x0048d32b);
            WriteMemory<byte>(0x7f, 0x0048c491);
            WriteMemory<byte>(0x7f, 0x00449e7a);
            WriteMemory<byte>(0x7f, 0x00453ad1);
            WriteMemory<int>(0x6c8b5551, 0x00403a10);
            WriteMemory<int>(0x28, 0x0069dca0);
            WriteArrayMemory<byte>(code_2, 3, 0x00403b30);
        }
    }
}

void PVZ::ShowHideGames(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0x38, 0x0042df5d);
        }
        else
        {
            WriteMemory<byte>(0x88, 0x0042df5d);
        }
    }
}

void PVZ::Win()
{
    if (GameOn() && GameUI() == 3)
    {
        asm_init();
        asm_mov_exx_dword_ptr(ECX, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(ECX, 0x768);
        asm_call(0x0040c3e0);
        asm_ret();
        asm_code_inject();
    }
}

void PVZ::JumpLevel(int level)
{
    if (GameOn())
        WriteMemory<int>(level, 0x6a9ec0, 0x768, 0x160, 0x6c);
}

void PVZ::MixMode(int mode, int level)
{
    if (GameOn() && GameUI() == 3)
    {
        if (mode == 0)
        {
            WriteMemory<int>(level, 0x6a9ec0, 0x82c, 0x24);
            WriteMemory<int>(level, 0x6a9ec0, 0x768, 0x5550);
        }
        WriteMemory<int>(mode, 0x6a9ec0, 0x7f8);
    }
}

// Page 2 : Plants

void PVZ::CobCannonNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x80, 0x0046103b);
        else
            WriteMemory<byte>(0x85, 0x0046103b);
    }
}

void PVZ::MagnetsNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x80, 0x00461e37);
        else
            WriteMemory<byte>(0x85, 0x00461e37);
    }
}

void PVZ::PotatoMineNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x80, 0x0045fe54);
        else
            WriteMemory<byte>(0x85, 0x0045fe54);
    }
}

void PVZ::ChomperNoCD(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x00461565);
        else
            WriteMemory<byte>(0x75, 0x00461565);
    }
}

// 0.Normal 1.Invincible 2.Weak
void PVZ::SetPlantStrength(int status)
{
    if (GameOn())
    {
        if (status == 0)
        {
            byte code_0[] = {0x46, 0x40, 0xfc};
            byte code_1[] = {0x29, 0x50, 0x40};
            byte code_2[] = {0x29, 0x4e, 0x40};
            WriteArrayMemory<byte>(code_0, 3, 0x0052fcf1);
            WriteArrayMemory<byte>(code_1, 3, 0x0046cfeb);
            WriteArrayMemory<byte>(code_2, 3, 0x0046d7a6);
            WriteMemory<byte>(0x74, 0x0052e93b);
            WriteMemory<byte>(0x74, 0x0041cc2f);
            WriteMemory<byte>(0x75, 0x005276ea);
            WriteMemory<byte>(0x75, 0x0045ee0a);
            WriteMemory<byte>(0xe0, 0x0045ec66);
        }
        else if (status == 1)
        {
            byte code_0[] = {0x46, 0x40, 0x00};
            byte code_1[] = {0x90, 0x90, 0x90};
            byte code_2[] = {0x90, 0x90, 0x90};
            WriteArrayMemory<byte>(code_0, 3, 0x0052fcf1);
            WriteArrayMemory<byte>(code_1, 3, 0x0046cfeb);
            WriteArrayMemory<byte>(code_2, 3, 0x0046d7a6);
            WriteMemory<byte>(0xeb, 0x0052e93b);
            WriteMemory<byte>(0xeb, 0x0041cc2f);
            WriteMemory<byte>(0xeb, 0x005276ea);
            WriteMemory<byte>(0x70, 0x0045ee0a);
            WriteMemory<byte>(0x00, 0x0045ec66);
        }
        else if (status == 2)
        {
            byte code_0[] = {0x66, 0x40, 0x00};
            byte code_1[] = {0x29, 0x40, 0x40};
            byte code_2[] = {0x29, 0x76, 0x40};
            WriteArrayMemory<byte>(code_0, 3, 0x0052fcf1);
            WriteArrayMemory<byte>(code_1, 3, 0x0046cfeb);
            WriteArrayMemory<byte>(code_2, 3, 0x0046d7a6);
            WriteMemory<byte>(0x74, 0x0052e93b);
            WriteMemory<byte>(0x74, 0x0041cc2f);
            WriteMemory<byte>(0x75, 0x005276ea);
            WriteMemory<byte>(0x70, 0x0045ee0a);
            WriteMemory<byte>(0xe0, 0x0045ec66);
        }
    }
}

// 0.Normal 1.Kernel 2.Butter
void PVZ::LockKernelOrButter(int status)
{
    if (GameOn())
    {
        if (status == 0)
            WriteMemory<byte>(0x75, 0x00464bd6);
        else if (status == 1)
            WriteMemory<byte>(0xeb, 0x00464bd6);
        else if (status == 2)
            WriteMemory<byte>(0x70, 0x00464bd6);
    }
}

void PVZ::NoCrater(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0041d79e);
        else
            WriteMemory<byte>(0x75, 0x0041d79e);
    }
}

void PVZ::MushroomsAwake(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xeb, 0x0045de8e);

            int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
            int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);
            asm_init();
            for (int i = 0; i < plant_count_max; i++)
            {
                bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
                bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
                bool plant_sleeping = ReadMemory<bool>(plant_offset + 0x143 + 0x14c * i);
                if (!plant_disappeared && !plant_crushed && plant_sleeping)
                {
                    int addr = plant_offset + 0x14c * i;
                    asm_mov_exx(EAX, addr);
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

void PVZ::StrongBlover(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x00466601);
        else
            WriteMemory<byte>(0x74, 0x00466601);
    }
}

void PVZ::StrongPeas(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x0046e429);
        else
            WriteMemory<byte>(0xe9, 0x0046e429);
    }
}

void PVZ::Umbrella(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0041d3f8);
        else
            WriteMemory<byte>(0x75, 0x0041d3f8);
    }
}

void PVZ::BeghouledFreeMove(bool on)
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

void PVZ::ProduceSpeedUp(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<int>(750, 0x69f2cc + 0x24 * 1);
            WriteMemory<int>(750, 0x69f2cc + 0x24 * 9);
            WriteMemory<int>(750, 0x69f2cc + 0x24 * 38);
            WriteMemory<int>(750, 0x69f2cc + 0x24 * 41);
        }
        else
        {
            WriteMemory<int>(2500, 0x69f2cc + 0x24 * 1);  // Sunflower
            WriteMemory<int>(2500, 0x69f2cc + 0x24 * 9);  // Sun-shroom
            WriteMemory<int>(2500, 0x69f2cc + 0x24 * 38); // Marigold
            WriteMemory<int>(2500, 0x69f2cc + 0x24 * 41); // Twin Sunflower
        }

        int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
        int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);
        for (int i = 0; i < plant_count_max; i++)
        {
            bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            int plant_type = ReadMemory<int>(plant_offset + 0x24 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
                if (plant_type == 1 || plant_type == 9 || plant_type == 38 || plant_type == 41)
                    WriteMemory<int>(on ? 750 : 2500, plant_offset + 0x5c + 0x14c * i);
        }
    }
}

void PVZ::AttackSpeedUp(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 0);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 5);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 7);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 8);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 10);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 13);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 18);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 24);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 26);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 28);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 29);
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 32);
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 34);
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 39);
            WriteMemory<int>(75, 0x69f2cc + 0x24 * 40);
            WriteMemory<int>(175, 0x69f2cc + 0x24 * 42);
            WriteMemory<int>(100, 0x69f2cc + 0x24 * 43);
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 44);
        }
        else
        {
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 0);  // Peashooter
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 5);  // Snow Pea
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 7);  // Repeater
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 8);  // Puff-shroom
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 10); // Fume-shroom
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 13); // Scaredy-shroom
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 18); // Threepeater
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 24); // Sea-shroom
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 26); // Cactus
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 28); // Split Pea
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 29); // Starfruit
            WriteMemory<int>(300, 0x69f2cc + 0x24 * 32); // Cabbage-pult
            WriteMemory<int>(300, 0x69f2cc + 0x24 * 34); // Kernel-pult
            WriteMemory<int>(300, 0x69f2cc + 0x24 * 39); // Melon-pult
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 40); // Gatling Pea
            WriteMemory<int>(200, 0x69f2cc + 0x24 * 42); // Gloom-shroom
            WriteMemory<int>(150, 0x69f2cc + 0x24 * 43); // Cattail
            WriteMemory<int>(300, 0x69f2cc + 0x24 * 44); // Winter Melon
        }

        int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
        int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);
        for (int i = 0; i < plant_count_max; i++)
        {
            bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            int plant_type = ReadMemory<int>(plant_offset + 0x24 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
                if (plant_type == 0 || plant_type == 5 || plant_type == 7 || plant_type == 8        // .
                    || plant_type == 10 || plant_type == 13 || plant_type == 18 || plant_type == 24 // .
                    || plant_type == 26 || plant_type == 28 || plant_type == 29 || plant_type == 40)
                    WriteMemory<int>(on ? 75 : 150, plant_offset + 0x5c + 0x14c * i);
                else if (plant_type == 32 || plant_type == 34 || plant_type == 39 || plant_type == 44)
                    WriteMemory<int>(on ? 150 : 300, plant_offset + 0x5c + 0x14c * i);
                else if (plant_type == 42)
                    WriteMemory<int>(on ? 175 : 200, plant_offset + 0x5c + 0x14c * i);
                else if (plant_type == 43)
                    WriteMemory<int>(on ? 100 : 150, plant_offset + 0x5c + 0x14c * i);
        }
    }
}

int PVZ::GetDamage(int index)
{
    return ReadMemory<int>(0x69f1c8 + index * 0xc);
}

void PVZ::SetDamage(int index, int damage)
{
    if (GameOn())
        WriteMemory<int>(damage, 0x69f1c8 + index * 0xc);
}

// Page 3 : Zombies

// Jack-in-the-Box and Jalepeno Zombie
// 0.Normal 1.Immediately 2.Never
void PVZ::SetZombieExplode(int status)
{
    if (GameOn())
    {
        if (status == 0)
        {
            WriteMemory<byte>(0x8f, 0x00526afc);
            WriteMemory<byte>(0x85, 0x005275dd);
        }
        else if (status == 1)
        {
            WriteMemory<byte>(0x80, 0x00526afc);
            WriteMemory<byte>(0x80, 0x005275dd);
        }
        else if (status == 2)
        {
            WriteMemory<byte>(0x81, 0x00526afc);
            WriteMemory<byte>(0x81, 0x005275dd);
        }
    }
}

// 0.Normal 1.Invisible 2.Visible
void PVZ::SetZombieVisibility(int status)
{
    if (GameOn())
    {
        if (status == 0)
        {
            WriteMemory<byte>(0x75, 0x0052e357);
            WriteMemory<byte>(0x75, 0x0053402b);
        }
        else if (status == 1)
        {
            WriteMemory<byte>(0x70, 0x0052e357);
            WriteMemory<byte>(0x70, 0x0053402b);
        }
        else if (status == 2)
        {
            WriteMemory<byte>(0xeb, 0x0052e357);
            WriteMemory<byte>(0xeb, 0x0053402b);
        }
    }
}

// 0.Normal 1.Weak 2.Invincible
void PVZ::SetZombieStrength(int status)
{
    if (GameOn())
    {
        if (status == 0)
        {
            WriteMemory<byte>(0xc8, 0x00531045);
            WriteMemory<int>(0x20247c2b, 0x0053130f);
            WriteMemory<int>(0xc28b027c, 0x00530c9b);
            WriteMemory<byte>(0x8d, 0x00532ba1);
            WriteMemory<byte>(0x74, 0x0046144a);
        }
        else if (status == 1)
        {
            WriteMemory<byte>(0xc9, 0x00531045);
            WriteMemory<int>(0x9090ff2b, 0x0053130f);
            WriteMemory<int>(0xc28bd08b, 0x00530c9b);
            WriteMemory<byte>(0x80, 0x00532ba1);
            WriteMemory<byte>(0x74, 0x0046144a);
        }
        else if (status == 2)
        {
            WriteMemory<byte>(0xc0, 0x00531045);
            WriteMemory<int>(0x90909090, 0x0053130f);
            WriteMemory<int>(0xd233c033, 0x00530c9b);
            WriteMemory<byte>(0x81, 0x00532ba1);
            WriteMemory<byte>(0xeb, 0x0046144a);
        }
    }
}

void PVZ::StopSpawning(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x00, 0x00413e4b);
        else
            WriteMemory<byte>(0xff, 0x00413e4b);
    }
}

void PVZ::ZombiesNoMove(bool on)
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

void PVZ::NoIceSlowDown(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            byte code[] = {0x33, 0xc0, 0x90};
            WriteArrayMemory<byte>(code, 3, 0x0052b448);
        }
        else
        {
            byte code[] = {0x83, 0xc0, 0xff};
            WriteArrayMemory<byte>(code, 3, 0x0052b448);
        }
    }
}

void PVZ::NoButterImmobilize(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            byte code[] = {0x33, 0xc0, 0x90};
            WriteArrayMemory<byte>(code, 3, 0x0052b464);
        }
        else
        {
            byte code[] = {0x83, 0xc0, 0xff};
            WriteArrayMemory<byte>(code, 3, 0x0052b464);
        }
    }
}

void PVZ::No3zGroup(bool on)
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

void PVZ::NoIceTrail(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            WriteMemory<byte>(0xc3, 0x0052a7b0);
            WriteMemory<byte>(0xeb, 0x0041f79a);
            for (int i = 0; i < 6; ++i)
            {
                // disappear countdown
                WriteMemory<int>(1, 0x6a9ec0, 0x768, 0x624 + i * 4);
            }
        }
        else
        {
            WriteMemory<byte>(0x51, 0x0052a7b0);
            WriteMemory<byte>(0x75, 0x0041f79a);
        }
    }
}

void PVZ::NoThrowImp(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x00527205);
        else
            WriteMemory<byte>(0x7d, 0x00527205);
    }
}

void PVZ::GargantuarEatable(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x00, 0x00461457);
        else
            WriteMemory<byte>(0x01, 0x00461457);
    }
}

void PVZ::ZombossNoMove(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x00536080);
        else
            WriteMemory<byte>(0x83, 0x00536080);
    }
}

void PVZ::BalloonBurst(bool on)
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

void PVZ::GatherZombies(bool on, float pos)
{
    if (GameOn() && GameUI() == 3)
    {
        if (on)
        {
            byte code[] = {0xc7, 0x46, 0x2c, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x23};
            (DWORD &)code[3] = (DWORD &)pos;
            WriteMemory<byte>(0x32, 0x0052aa4a);
            WriteArrayMemory<byte>(code, sizeof(code), 0x0052ab18);
        }
        else
        {
            byte code[] = {0xe8, 0xc3, 0x13, 0x00, 0x00, 0x84, 0xc0, 0x75, 0x0f};
            WriteMemory<byte>(0x84, 0x0052aa4a);
            WriteArrayMemory<byte>(code, sizeof(code), 0x0052ab18);
        }
    }
}

void PVZ::SpawningAllZombies()
{
    if (GameOn() && GameUI() == 3)
    {
        while ((PastWaves() < TotalWaves()) && GameUI() == 3)
        {
            // WriteMemory<int>(TotalWaves(), 0x6a9ec0, 0x768, 0x557c);
            WriteMemory<int>(1, 0x6a9ec0, 0x768, 0x559c);
            Sleep(10);
        }
    }
}

void PVZ::AllZombiesXXX(int zombie_status)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int zombie_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x94);
        int zombie_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x90);
        for (int i = 0; i < zombie_count_max; i++)
        {
            if (!ReadMemory<bool>(zombie_offset + 0xec + i * 0x15c))
            {
                switch (zombie_status)
                {
                case 0: // Kill
                    WriteMemory<int>(3, zombie_offset + 0x28 + i * 0x15c);
                    break;
                case 1: // Hypno
                    WriteMemory<bool>(true, zombie_offset + 0xb8 + i * 0x15c);
                    break;
                case 2: // Freeze
                    WriteMemory<int>(2147483647, zombie_offset + 0xb4 + i * 0x15c);
                    break;
                case 3: // Decelerate
                    WriteMemory<int>(2147483647, zombie_offset + 0xac + i * 0x15c);
                    break;
                case 4: // Immobilize
                    WriteMemory<int>(2147483647, zombie_offset + 0xb0 + i * 0x15c);
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
                    WriteMemory<float>(2.0, zombie_offset + 0x11c + i * 0x15c);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

// Page 4 : Spawn

void PVZ::GenerateZombiesType()
{
    asm_init();
    asm_mov_exx_dword_ptr(ESI, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(ESI, 0x768);
    asm_mov_exx_dword_ptr_exx_add(ESI, 0x160);
    asm_call(0x00425840);
    asm_ret();
    asm_code_inject();
}

void PVZ::GenerateZombiesList()
{
    asm_init();
    asm_mov_exx_dword_ptr(EDI, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(EDI, 0x768);
    asm_call(0x004092e0);
    asm_ret();
    asm_code_inject();
}

void PVZ::UpdateZombiesView()
{
    WriteMemory<byte>(0x80, 0x0043a153);
    asm_init();
    asm_mov_exx_dword_ptr(EBX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(EBX, 0x768);
    asm_call(0x0040df70);
    asm_mov_exx_dword_ptr(EAX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(EAX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(EAX, 0x15c);
    asm_push_exx(EAX);
    asm_call(0x0043a140);
    asm_ret();
    asm_code_inject();
    WriteMemory<byte>(0x85, 0x0043a153);
}

// zombies[0] for "Zombie", zombies[26] for "Peashooter Zombie".
// Game will crash if neither Zombie nor Peashooter Zombie was set when using call 0x004092e0.
// So replace the zombie which has the minimal id with Peashooter Zombie.
// Then change it back after the zombies list was generated.
// Do backup original zombie types and restore them.

void PVZ::InternalSpawn(bool *zombies, bool original)
{
    if (original)
    {
        if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        {
            int zombies_type_offset = ReadMemory<int>(0x6a9ec0, 0x768) + 0x54d4;
            for (int i = 0; i < 33; i++)
            {
                WriteMemory<bool>(false, zombies_type_offset + i * sizeof(bool));
            }
            GenerateZombiesType();
            GenerateZombiesList();
            if (GameUI() == 2)
                UpdateZombiesView();
        }
    }
    else
    {
        if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        {
            int zombies_type_offset = ReadMemory<int>(0x6a9ec0, 0x768) + 0x54d4;
            int zombies_list_offset = ReadMemory<int>(0x6a9ec0, 0x768) + 0x6b4;

            bool zombies_type_original[33];
            for (int i = 0; i < 33; i++)
            {
                zombies_type_original[i] = ReadMemory<bool>(zombies_type_offset + i * sizeof(bool));
            }

            bool has_normal_zombie = (zombies[0] || zombies[26]) ? true : false;
            int replace_zombie = 0;
            if (!has_normal_zombie)
            {
                for (int i = 0; i < 33; i++)
                {
                    if (zombies[i])
                    {
                        replace_zombie = i;
                        break;
                    }
                }
            }

            WriteArrayMemory<bool>(zombies, 33, zombies_type_offset);
            if (!has_normal_zombie)
            {
                WriteMemory<bool>(false, zombies_type_offset + replace_zombie * sizeof(bool));
                WriteMemory<bool>(true, zombies_type_offset + 26 * sizeof(bool));
            }

            GenerateZombiesList();

            if (!has_normal_zombie)
            {
                int zombies_list[2000] = {0};
                ReadProcessMemory(handle, LPCVOID(zombies_list_offset), zombies_list, 2000 * sizeof(int), nullptr);
                for (int i = 0; i < 2000; i++)
                {
                    if (zombies_list[i] == 26)
                        WriteMemory<int>(replace_zombie, zombies_list_offset + i * sizeof(int));
                }
            }

            if (GameUI() == 2)
                UpdateZombiesView();

            WriteArrayMemory<bool>(zombies_type_original, 33, zombies_type_offset);
        }
    }
}

void PVZ::CustomizeSpawn(bool *zombies, bool random, bool limit_yeti, bool limit_bungee, bool limit_giga)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int zombies_list_offset = ReadMemory<int>(0x6a9ec0, 0x768) + 0x6b4;
        int zombies_list[2000] = {0};
        bool has_yeti = zombies[19];
        bool has_bungee = zombies[20];
        bool has_giga = zombies[32];

        int count = 0;
        for (int i = 0; i < 33; i++)
        {
            if (zombies[i])
                count++;
        }
        if (count > 0)
        {
            unsigned int t = QDateTime::currentDateTime().toTime_t();
            qsrand(t);
            int type = 0;
            for (int i = 0; i < 2000; i++)
            {
                do
                {
                    if (random)
                    {
                        type = qrand() % 33;
                    }
                    else
                    {
                        type++;
                        type %= 33;
                    }
                } while ((!zombies[type])                                                                                                                              //
                         || (has_yeti && limit_yeti && type == 19)                                                                                                     //
                         || (has_bungee && limit_bungee && (i >= 0 && i < 450 || i >= 500 && i < 950 || i >= 1000 && i < 1450 || i >= 1500 && i < 1950) && type == 20) //
                         || (has_giga && limit_giga && (i >= 500 && i < 950 || i >= 1500 && i < 1950) && type == 32));                                                 //
                zombies_list[i] = type;
            }
            if (has_yeti && limit_yeti)
            {
                int index = qrand() % 1000;
                zombies_list[index] = 19;
            }
        }

        WriteProcessMemory(handle, LPVOID(zombies_list_offset), zombies_list, 2000 * sizeof(int), nullptr);

        if (GameUI() == 2)
            UpdateZombiesView();
    }
}

int PVZ::GetRandomSeed()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x561c);
}

void PVZ::SetRandomSeed(int seed)
{
    if (GameUI() == 2 || GameUI() == 3)
        WriteMemory<int>(seed, 0x6a9ec0, 0x768, 0x561c);
}

// Page 5 : Slots

void PVZ::SetSlotsCount(int num)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        WriteMemory<byte>(0xc3, 0x0041bee0);
        asm_init();
        asm_mov_exx(EAX, num);
        asm_mov_exx_dword_ptr(ESI, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(ESI, 0x768);
        asm_mov_exx_dword_ptr_exx_add(ESI, 0x144);
        asm_call(0x00489cd0);
        asm_ret();
        asm_code_inject();
        WriteMemory<byte>(0x56, 0x0041bee0);
    }
}

void PVZ::ShowShovel()
{
    if (GameOn())
        WriteMemory<bool>(true, 0x6a9ec0, 0x768, 0x55f1);
}

// index: 0~9
// type: 0~47 (Pea ~ Cob)
void PVZ::SetSlotsSeed(int index, int type, bool imitater)
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
        }
    }
}

void PVZ::BeltNoDelay(bool on)
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

void PVZ::PurpleSeedUnlimited(bool on)
{
    if (GameOn())
    {
        if (on)
        {
            byte code[] = {0xb0, 0x01, 0xc3};
            WriteArrayMemory<byte>(code, 3, 0x0041d7d0);
            WriteMemory<byte>(0xeb, 0x0040e477);
        }
        else
        {
            byte code[] = {0x51, 0x83, 0xf8};
            WriteArrayMemory<byte>(code, 3, 0x0041d7d0);
            WriteMemory<byte>(0x74, 0x0040e477);
        }
    }
}

void PVZ::PlantingFreely(bool on)
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

void PVZ::LockShovel(bool on)
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

void PVZ::IgnoreSun(bool on)
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

void PVZ::SlotsNoCoolDown(bool on)
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

int PVZ::GetSpeed(int index)
{
    return ReadMemory<int>(0x69f2cc + index * 0x24);
}

void PVZ::SetSpeed(int index, int speed)
{
    if (GameOn())
        WriteMemory<int>(speed, 0x69f2cc + index * 0x24);
}

int PVZ::GetCost(int index)
{
    return ReadMemory<int>(0x69f2c0 + index * 0x24);
}

void PVZ::SetCost(int index, int cost)
{
    if (GameOn())
        WriteMemory<int>(cost, 0x69f2c0 + index * 0x24);
}

int PVZ::GetRecharge(int index)
{
    return ReadMemory<int>(0x69f2c4 + index * 0x24);
}

void PVZ::SetRecharge(int index, int recharge)
{
    if (GameOn())
        WriteMemory<int>(recharge, 0x69f2c4 + index * 0x24);
}

// Page 6 : Scene

int PVZ::GetScene()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x554c);
}

void PVZ::SetScene(int scene)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
        WriteMemory<int>(scene, 0x6a9ec0, 0x768, 0x554c);
}

int PVZ::GetRowCount()
{
    int scene = GetScene();
    return scene == 2 || scene == 3 ? 6 : 5;
}

void PVZ::asm_plant(int row, int col, int type, bool imitater, bool iz_style)
{
    if (imitater && !iz_style) // imitater
    {
        asm_push(type);
        asm_push(48);
        asm_mov_exx(EAX, row);
        asm_push(col);
        asm_mov_exx_dword_ptr(EBP, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(EBP, 0x768);
        asm_push_exx(EBP);
        asm_call(0x0040d120);
        asm_add_word(0xf08b); // mov esi, eax
        asm_push_exx(EAX);
        asm_call(0x00466b80);
        asm_add_byte(0x58); // pop eax
    }
    else
    {
        asm_push(-1);
        asm_push(type);
        asm_mov_exx(EAX, row);
        asm_push(col);
        asm_mov_exx_dword_ptr(EBP, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(EBP, 0x768);
        asm_push_exx(EBP);
        asm_call(0x0040d120);
    }

    if (iz_style) // I, Zombie style
    {
        asm_push_exx(EAX);
        asm_mov_exx_dword_ptr(EAX, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(EAX, 0x768);
        asm_mov_exx_dword_ptr_exx_add(EAX, 0x160);
        asm_call(0x0042a530);
    }
}

void PVZ::Plant(int row, int col, int type, bool imitater)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int row_count = GetRowCount();        // 6 or 5
        int col_count = (type == 47 ? 8 : 9); // Cob Cannon cannot be planted at col 9
        int width = (type == 47 ? 2 : 1);     // Cob Cannon's width is 2
        int mode = GameMode();
        bool iz_style = mode >= 61 && mode <= 70;
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

void PVZ::asm_put_zombie(int row, int col, int type)
{
    asm_push(col);
    asm_push(type);
    asm_mov_exx(EAX, row);
    asm_mov_exx_dword_ptr(ECX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(ECX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(ECX, 0x160);
    asm_call(0x0042a0f0);
}

void PVZ::PutZombie(int row, int col, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (type == 25)
        {
            asm_init();
            asm_mov_exx_dword_ptr(EAX, 0x6a9ec0);
            asm_mov_exx_dword_ptr_exx_add(EAX, 0x768);
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

void PVZ::asm_put_grave(int row, int col)
{
    asm_mov_exx_dword_ptr(EDX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(EDX, 0x768);
    asm_mov_exx_dword_ptr_exx_add(EDX, 0x160);
    asm_push_exx(EDX);
    asm_mov_exx(EDI, row);
    asm_mov_exx(EBX, col);
    asm_call(0x00426620);
}

void PVZ::PutGrave(int row, int col)
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

void PVZ::asm_put_ladder(int row, int col)
{
    asm_mov_exx(EDI, row);
    asm_push(col);
    asm_mov_exx_dword_ptr(EAX, 0x6a9ec0);
    asm_mov_exx_dword_ptr_exx_add(EAX, 0x768);
    asm_call(0x00408f40);
}

void PVZ::PutLadder(int row, int col)
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

void PVZ::AutoLadder(bool imitater_pumpkin_only)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int grid_item_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x120);
        int grid_item_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x11c);
        bool has_ladder[6][9] = {false};

        for (int i = 0; i < grid_item_count_max; i++)
        {
            bool grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
            int grid_item_type = ReadMemory<int>(grid_item_offset + 0x08 + 0xec * i); // 3 for Ladder
            int grid_item_row = ReadMemory<int>(grid_item_offset + 0x14 + 0xec * i);
            int grid_item_col = ReadMemory<int>(grid_item_offset + 0x10 + 0xec * i);
            if (!grid_item_disappeared && grid_item_type == 3)
                has_ladder[grid_item_row][grid_item_col] = true;
        }

        int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
        int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);

        asm_init();
        for (int i = 0; i < plant_count_max; i++)
        {
            bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            int plant_type = ReadMemory<int>(plant_offset + 0x24 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed && plant_type == 30) // 30 for Pumpkin
            {
                int plant_row = ReadMemory<int>(plant_offset + 0x1c + 0x14c * i);
                int plant_col = ReadMemory<int>(plant_offset + 0x28 + 0x14c * i);
                int is_imitater = ReadMemory<int>(plant_offset + 0x138 + 0x14c * i);
                int block_type = ReadMemory<int>(0x6a9ec0, 0x768, 0x168 + 0x04 * plant_row + 0x18 * plant_col); // 1.lawn
                if (plant_col != 0 && block_type == 1 && !has_ladder[plant_row][plant_col])
                    if (!imitater_pumpkin_only || imitater_pumpkin_only && is_imitater == 48)
                        asm_put_ladder(plant_row, plant_col);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PVZ::EatAllGraves()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int grid_item_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x120);
        int grid_item_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x11c);

        asm_init();
        for (int i = 0; i < grid_item_count_max; i++)
        {
            bool grid_item_disappeared = ReadMemory<bool>(grid_item_offset + 0x20 + 0xec * i);
            int grid_item_type = ReadMemory<int>(grid_item_offset + 0x08 + 0xec * i); // 1 for Grave
            int grid_item_row = ReadMemory<int>(grid_item_offset + 0x14 + 0xec * i);
            int grid_item_col = ReadMemory<int>(grid_item_offset + 0x10 + 0xec * i);
            if (!grid_item_disappeared && grid_item_type == 1)
                asm_plant(grid_item_row, grid_item_col, 11, false, false);
        }
        asm_ret();
        asm_code_inject();
    }
}

void PVZ::LilyPadOnPool()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
        int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);
        bool has_plant[6][9] = {false};

        for (int i = 0; i < plant_count_max; i++)
        {
            bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            int plant_row = ReadMemory<int>(plant_offset + 0x1c + 0x14c * i);
            int plant_col = ReadMemory<int>(plant_offset + 0x28 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
                has_plant[plant_row][plant_col] = true;
        }

        asm_init();
        for (int r = 0; r < GetRowCount(); r++)
        {
            for (int c = 0; c < 9; c++)
            {
                int block_type = ReadMemory<int>(0x6a9ec0, 0x768, 0x168 + 0x04 * r + 0x18 * c); // 3.pool
                if (block_type == 3 && !has_plant[r][c])
                    asm_plant(r, c, 16, false, false);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PVZ::FlowerPotOnRoof()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (GetScene() == 4 || GetScene() == 5)
        {
            int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
            int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);
            bool has_plant[5][9] = {false};

            for (int i = 0; i < plant_count_max; i++)
            {
                bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
                bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
                int plant_row = ReadMemory<int>(plant_offset + 0x1c + 0x14c * i);
                int plant_col = ReadMemory<int>(plant_offset + 0x28 + 0x14c * i);
                if (!plant_disappeared && !plant_crushed)
                    has_plant[plant_row][plant_col] = true;
            }

            asm_init();
            for (int r = 0; r < 5; r++)
                for (int c = 0; c < 9; c++)
                    if (!has_plant[r][c])
                        asm_plant(r, c, 33, false, false);
            asm_ret();
            asm_code_inject();
        }
    }
}

void PVZ::ClearAllPlants()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int plant_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0xb0);
        int plant_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0xac);

        for (int i = 0; i < plant_count_max; i++)
        {
            bool plant_disappeared = ReadMemory<bool>(plant_offset + 0x141 + 0x14c * i);
            bool plant_crushed = ReadMemory<bool>(plant_offset + 0x142 + 0x14c * i);
            if (!plant_disappeared && !plant_crushed)
                WriteMemory<bool>(true, plant_offset + 0x141 + 0x14c * i);
        }
    }
}

int PVZ::GetBlock(int row, int col)
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x168 + row * 0x04 + col * 0x18);
}

// 1.lawn 2.bare 3.pool
void PVZ::SetBlock(int row, int col, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int row_count = GetRowCount();
        int col_count = 9;
        if (row == -1 && col == -1)
            for (int r = 0; r < row_count; r++)
                for (int c = 0; c < col_count; c++)
                    WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + r * 0x04 + c * 0x18);
        else if (row != -1 && col == -1)
            for (int c = 0; c < col_count; c++)
                WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + row * 0x04 + c * 0x18);
        else if (row == -1 && col != -1)
            for (int r = 0; r < row_count; r++)
                WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + r * 0x04 + col * 0x18);
        else
            WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x168 + row * 0x04 + col * 0x18);
    }
}

int PVZ::GetRow(int row)
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x5d8 + row * 0x04);
}

// 0.none 1.land 2.water
void PVZ::SetRow(int row, int type)
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        if (row == -1)
            for (int r = 0; r < 6; r++)
                WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x5d8 + r * 0x04);
        else
            WriteMemory<int>(type, 0x6a9ec0, 0x768, 0x5d8 + row * 0x04);
    }
}

void PVZ::StartLawnMowers()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int lawn_mower_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x100);
        int lawn_mower_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x104);
        asm_init();
        for (int i = 0; i < lawn_mower_count_max; i++)
        {
            bool lawn_mower_disappeared = ReadMemory<bool>(lawn_mower_offset + 0x30 + 0x48 * i);
            if (!lawn_mower_disappeared)
            {
                int addr = lawn_mower_offset + 0x48 * i;
                asm_mov_exx(ESI, addr);
                asm_call(0x00458da0);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PVZ::ResetLawnMowers()
{
    if (GameOn() && (GameUI() == 2 || GameUI() == 3))
    {
        int lawn_mower_offset = ReadMemory<int>(0x6a9ec0, 0x768, 0x100);
        int lawn_mower_count_max = ReadMemory<int>(0x6a9ec0, 0x768, 0x104);
        asm_init();
        for (int i = 0; i < lawn_mower_count_max; i++)
        {
            bool lawn_mower_disappeared = ReadMemory<bool>(lawn_mower_offset + 0x30 + 0x48 * i);
            if (!lawn_mower_disappeared)
            {
                int addr = lawn_mower_offset + 0x48 * i;
                asm_mov_exx(EAX, addr);
                asm_call(0x00458d10);
            }
        }
        WriteMemory<unsigned short>(0x60eb, 0x0040bc98);
        WriteMemory<byte>(0x01, 0x0040bd17);
        WriteMemory<unsigned short>(0x99fc, 0x00458002);
        asm_mov_exx_dword_ptr(EAX, 0x6a9ec0);
        asm_mov_exx_dword_ptr_exx_add(EAX, 0x768);
        asm_push_exx(EAX);
        asm_call(0x0040bc70);
        asm_ret();
        asm_code_inject();
        WriteMemory<unsigned short>(0x0975, 0x0040bc98);
        WriteMemory<byte>(0x00, 0x0040bd17);
        WriteMemory<unsigned short>(0x9bf8, 0x00458002);
    }
}

// Page 7 : Effects

// Only work for '0' - '9' and 'A' - 'Z'
void PVZ::PressKey(char key)
{
    SendMessage(hwnd, WM_KEYDOWN, key, 0);
    SendMessage(hwnd, WM_KEYUP, key, 0);
}

void PVZ::WisdomTreeCode(int code)
{
    if (GameOn())
    {
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
            PressKey(key);
        }
    }
}

//  ↑ ↑ ↓ ↓ ← → ← → B A
void PVZ::KonamiCode()
{
    Sleep(1000);
    if (GameOn())
    {
        SendMessage(hwnd, WM_KEYDOWN, VK_UP, 0);
        SendMessage(hwnd, WM_KEYUP, VK_UP, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_UP, 0);
        SendMessage(hwnd, WM_KEYUP, VK_UP, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
        SendMessage(hwnd, WM_KEYUP, VK_DOWN, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
        SendMessage(hwnd, WM_KEYUP, VK_DOWN, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
        SendMessage(hwnd, WM_KEYUP, VK_LEFT, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_RIGHT, 0);
        SendMessage(hwnd, WM_KEYUP, VK_RIGHT, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
        SendMessage(hwnd, WM_KEYUP, VK_LEFT, 0);
        SendMessage(hwnd, WM_KEYDOWN, VK_RIGHT, 0);
        SendMessage(hwnd, WM_KEYUP, VK_RIGHT, 0);
        SendMessage(hwnd, WM_KEYDOWN, 'B', 0);
        SendMessage(hwnd, WM_KEYUP, 'B', 0);
        SendMessage(hwnd, WM_KEYDOWN, 'A', 0);
        SendMessage(hwnd, WM_KEYUP, 'A', 0);
    }
}

void PVZ::LittleZombie(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xeb, 0x00523ed5);
        else
            WriteMemory<byte>(0x74, 0x00523ed5);
    }
}

void PVZ::ItsRaining(bool on)
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

void PVZ::StormyNight(bool on)
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

void PVZ::HighGravity(bool on)
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

void PVZ::ColumnLike(bool on)
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

void PVZ::ZombieQuick(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x004248aa);
        else
            WriteMemory<byte>(0x75, 0x004248aa);
    }
}

// row : 0~5
int PVZ::GetIceTrailX(int row)
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x60c + 0x4 * row);
}

void PVZ::SetIceTrailX(int row, int x)
{
    if (GameOn())
    {
        if (row == -1)
            for (int r = 0; r < 6; r++)
                WriteMemory<int>(x, 0x6a9ec0, 0x768, 0x60c + 0x4 * r);
        else
            WriteMemory<int>(x, 0x6a9ec0, 0x768, 0x60c + 0x4 * row);
    }
}

void PVZ::FullFog(bool on)
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
            int fog_offset = ReadMemory<int>(0x6a9ec0, 0x768) + 0x4c8;
            for (int i = 0; i < 63; ++i)
                WriteMemory<int>(0, fog_offset + i * 4);
            WriteMemory<byte>(0x8b, 0x0041c1c0);
            WriteMemory<byte>(0x81, 0x0041c1c1);
            WriteMemory<byte>(0x8c, 0x0041c1c2);
            WriteMemory<byte>(0x75, 0x0041a476);
            WriteMemory<byte>(0x05, 0x0041a477);
            WriteMemory<byte>(0x04, 0x0041a4ba);
        }
    }
}

void PVZ::NoFog(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<unsigned short>(0xd231, 0x0041a68d);
        else
            WriteMemory<unsigned short>(0xf23b, 0x0041a68d);
    }
}

void PVZ::SeeVase(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<int>(0x0033b866, 0x0044e5cc);
        else
            WriteMemory<int>(0x067ec085, 0x0044e5cc);
    }
}

// Page 8 : Others

void PVZ::DisableSaveData(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x70, 0x0054b267);
        else
            WriteMemory<byte>(0x74, 0x0054b267);
    }
}

void PVZ::DisableDeleteData(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0x2e, 0x00482149);
        else
            WriteMemory<byte>(0x13, 0x00482149);
    }
}

void PVZ::RunningInBackground(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x0054ebef);
        else
            WriteMemory<byte>(0x57, 0x0054ebef);
    }
}

void PVZ::NoPause(bool on)
{
    if (GameOn())
    {
        if (on)
            WriteMemory<byte>(0xc3, 0x004502c0);
        else
            WriteMemory<byte>(0x55, 0x004502c0);
    }
}

void PVZ::DebugMode(int mode)
{
    if (GameOn())
        WriteMemory<int>(mode, 0x6a9ec0, 0x768, 0x55f8);
}

bool PVZ::CreatePath(std::string path)
{
    if (PathFileExistsA(path.c_str()))
        return true;
    else
    {
        if (CreateDirectoryA(path.c_str(), 0))
            return true;
        else
        {
            if (path.substr(0, path.find_last_of("/")) != path)
            {
                if (CreatePath(path.substr(0, path.find_last_of("/"))))
                    return CreateDirectoryA(path.c_str(), 0);
                else
                    return false;
            }
            else
                return false;
        }
    }
}

void PVZ::UnpackPAK(QString src, QString dst)
{
    std::string src_file = src.toStdString();
    std::string dst_dir = dst.toStdString();

    // loat entire file to memory
    std::ifstream ifs(src_file, std::ios::binary);
    std::filebuf *buf = ifs.rdbuf();
    int size = buf->pubseekoff(0, std::ios::end, std::ios::in);
    char *buffer = new char[size];
    buf->pubseekpos(0, std::ios::in);
    buf->sgetn(buffer, size);
    ifs.close();

    for (int i = 0; i < size; ++i)
        buffer[i] = buffer[i] ^ 0xf7;

    // data structure
    char name_size;
    char file_name[MAX_PATH];
    int file_size;
    FILETIME file_time;
    char eof_flag;

    int index = 9;
    int file_count = 0;
    std::vector<std::string> files_path;
    std::vector<int> files_size;
    do
    {
        name_size = buffer[index];
        index++;

        for (int i = 0; i < name_size; i++)
            file_name[i] = buffer[index + i];
        file_name[name_size] = 0;
        std::string file_path = file_name; // char* -> std::string
        index += name_size;

        file_size = (int &)buffer[index];
        index += 4;

        file_time = (FILETIME &)buffer[index]; // useless
        index += 8;

        eof_flag = buffer[index];
        index++;

        files_path.push_back(file_path);
        files_size.push_back(file_size);
        file_count++;

    } while (eof_flag == 0x00); // or eof_flag != 0x80

    // create unpack dir
    CreateDirectoryA(dst_dir.c_str(), 0);

    std::string output_file_path;
    int output_file_size;
    for (int i = 0; i < file_count; i++)
    {
        output_file_path = dst_dir + "/" + files_path.at(i);
        output_file_size = files_size.at(i);

        // \ -> /
        while (true)
        {
            std::string::size_type pos(0);
            if ((pos = output_file_path.find("\\")) != std::string::npos)
                output_file_path.replace(pos, 1, "/");
            else
                break;
        }
        // remove file name
        output_file_path = output_file_path.substr(0, output_file_path.find_last_of("/"));

        if (CreatePath(output_file_path))
        {
            char *output_buff = new char[output_file_size];
            for (int i = 0; i < output_file_size; i++)
                output_buff[i] = (char &)(buffer[index + i]);
            std::string full_file_path = dst_dir + "/" + files_path.at(i);
            while (true)
            {
                std::string::size_type pos(0);
                if ((pos = full_file_path.find("\\")) != std::string::npos)
                    full_file_path.replace(pos, 1, "/");
                else
                    break;
            }
            std::ofstream ofs;
            ofs.open(full_file_path, std::ios::binary);
            ofs.write(output_buff, output_file_size);
            ofs.close();
            delete[] output_buff;
            index += output_file_size;
        }
    }

    files_path.clear();
    files_size.clear();
    delete[] buffer;

    emit PackOrUnpackFinished();
}

QFileInfoList PVZ::GetFileList(QString path)
{
    QDir dir(path);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i = 0; i < folder_list.size(); i++)
    {
        QString folder_name = folder_list.at(i).absoluteFilePath();
        QFileInfoList child_file_list = GetFileList(folder_name);
        file_list.append(child_file_list);
    }
    return file_list;
}

void PVZ::PackPAK(QString src)
{
    QFileInfoList file_info_list = GetFileList(src);
    int prefix_size = src.size();
    std::string dst = src.toStdString();
    dst = dst.substr(0, dst.find_last_of("/")) + "/" + "main_" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss").toStdString() + ".pak";
    std::cout << dst;
    // data structure
    char name_size;
    char file_name[MAX_PATH];
    int file_size;
    FILETIME file_time;
    char eof_flag;

    QDateTime origin(QDate(1601, 1, 1), QTime(0, 0, 0, 0), Qt::UTC);
    QDateTime now = QDateTime::currentDateTime();
    qint64 _100nanosecs = origin.msecsTo(now) * 10000; // 1ms = 10000 x 100ns
    file_time.dwLowDateTime = _100nanosecs;
    file_time.dwHighDateTime = (_100nanosecs >> 32);

    char file_header[9] = {char(0xc0), char(0x4a), char(0xc0), char(0xba), char(0x00), char(0x00), char(0x00), char(0x00), char(0x00)};
    for (int i = 0; i < 9; i++)
        file_header[i] = file_header[i] ^ 0xf7;

    std::ofstream ofs;
    ofs.open(dst, std::ios::binary);
    ofs.write(file_header, 9);

    for (int i = 0; i < file_info_list.size(); i++)
    {
        std::string file_name_full_path = file_info_list.at(i).absoluteFilePath().toStdString().substr(prefix_size + 1);
        while (true)
        {
            std::string::size_type pos(0);
            if ((pos = file_name_full_path.find("/")) != std::string::npos)
                file_name_full_path.replace(pos, 1, "\\");
            else
                break;
        }
        name_size = char(file_name_full_path.size());
        for (int i = 0; i < int(name_size); i++)
            file_name[i] = file_name_full_path.at(i);
        file_name[int(name_size)] = 0;
        file_size = file_info_list.at(i).size();
        eof_flag = (i != file_info_list.size() - 1) ? 0x00 : 0x80;

        int buff_size = sizeof(char) + name_size + sizeof(int) + sizeof(FILETIME) + sizeof(char);
        char *buff = new char[buff_size];
        (char &)buff[0] = name_size;
        for (int i = 0; i < name_size; i++)
            (char &)buff[sizeof(char) + i] = file_name[i];
        (int &)buff[sizeof(char) + name_size] = file_size;
        (FILETIME &)buff[sizeof(char) + name_size + sizeof(int)] = file_time;
        (char &)buff[sizeof(char) + name_size + sizeof(int) + sizeof(FILETIME)] = eof_flag;

        for (int i = 0; i < buff_size; i++)
            buff[i] = buff[i] ^ 0xf7;
        ofs.write(buff, buff_size);
        delete[] buff;
    }

    for (int i = 0; i < file_info_list.size(); i++)
    {
        std::string file_path = file_info_list.at(i).absoluteFilePath().toStdString();

        std::ifstream ifs(file_path, std::ios::binary);
        std::filebuf *buf = ifs.rdbuf();
        int size = buf->pubseekoff(0, std::ios::end, std::ios::in);
        char *buffer = new char[size];
        buf->pubseekpos(0, std::ios::in);
        buf->sgetn(buffer, size);
        ifs.close();

        // int size = file_info_list.at(i).size();
        for (int i = 0; i < size; ++i)
            buffer[i] = buffer[i] ^ 0xf7;

        ofs.write(buffer, size);
    }

    ofs.close();

    emit PackOrUnpackFinished();
}

// Page 9 : Status

int PVZ::GameMode()
{
    return ReadMemory<int>(0x6a9ec0, 0x7f8);
}

int PVZ::GameUI()
{
    return ReadMemory<int>(0x6a9ec0, 0x7fc);
}

int PVZ::RunningTime()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x28);
}

int PVZ::LevelCompleted()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x160, 0x6c);
}

int PVZ::TotalWaves()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x5564);
}

int PVZ::PastWaves()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x557c);
}

int PVZ::TotalHP()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x5598);
}

int PVZ::TriggerHP()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x5594);
}

int PVZ::CountDown()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x559C);
}

int PVZ::HugeWaveCountDown()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x55A4);
}

int PVZ::PlantCount()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0xbc);
}

int PVZ::ZombieCount()
{
    return ReadMemory<int>(0x6a9ec0, 0x768, 0xa0);
}
