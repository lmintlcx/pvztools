
#include <cassert>

#include <Windows.h>

#include "src/bot.h"

namespace Pt
{

Bot::Bot(HWND hwnd)
{
    this->hwnd = hwnd;
}

Bot::~Bot()
{
}

// Open process when memory operate is needed.
void Bot::OpenProcess()
{
    if (hwnd == nullptr)
    {
        if (!OpenByWindow(L"MainWindow", L"Plants vs. Zombies"))
            OpenByWindow(L"MainWindow", L"植物大战僵尸汉化版");
    }
    else
    {
        GetWindowThreadProcessId(hwnd, &pid);
        handle = ::OpenProcess(PROCESS_ALL_ACCESS, false, pid);
    }
}

int Bot::GetSlotsCount()
{
    if (!IsValid())
        OpenProcess();
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x144, 0x24);
}

int Bot::GetGameScene()
{
    if (!IsValid())
        OpenProcess();
    return ReadMemory<int>(0x6a9ec0, 0x768, 0x554c);
}

void Bot::LeftDown(int x, int y)
{
    PostMessage(hwnd, WM_LBUTTONDOWN, 0, (y << 16) | x);
}

void Bot::LeftUp(int x, int y)
{
    PostMessage(hwnd, WM_LBUTTONUP, 0, (y << 16) | x);
}

void Bot::LeftClick(int x, int y)
{
    PostMessage(hwnd, WM_LBUTTONDOWN, 0, (y << 16) | x);
    PostMessage(hwnd, WM_LBUTTONUP, 0, (y << 16) | x);
}

void Bot::Click(int x, int y)
{
    PostMessage(hwnd, WM_LBUTTONDOWN, 0, (y << 16) | x);
    PostMessage(hwnd, WM_LBUTTONUP, 0, (y << 16) | x);
}

void Bot::RightDown(int x, int y)
{
    PostMessage(hwnd, WM_RBUTTONDOWN, 0, (y << 16) | x);
}

void Bot::RightUp(int x, int y)
{
    PostMessage(hwnd, WM_RBUTTONUP, 0, (y << 16) | x);
}

void Bot::RightClick(int x, int y)
{
    PostMessage(hwnd, WM_RBUTTONDOWN, 0, (y << 16) | x);
    PostMessage(hwnd, WM_RBUTTONUP, 0, (y << 16) | x);
}

void Bot::SafeClick()
{
    PostMessage(hwnd, WM_RBUTTONDOWN, 0, (1 << 16) | 1);
    PostMessage(hwnd, WM_RBUTTONUP, 0, (1 << 16) | 1);
}

void Bot::PressESC()
{
    PostMessage(hwnd, WM_KEYDOWN, VK_ESCAPE, 0);
    PostMessage(hwnd, WM_KEYUP, VK_ESCAPE, 0);
}

void Bot::PressSpace()
{
    PostMessage(hwnd, WM_KEYDOWN, VK_SPACE, 0);
    PostMessage(hwnd, WM_KEYUP, VK_SPACE, 0);
}

void Bot::PressUp()
{
    PostMessage(hwnd, WM_KEYDOWN, VK_UP, 0);
    PostMessage(hwnd, WM_KEYUP, VK_UP, 0);
}

void Bot::PressDown()
{
    PostMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
    PostMessage(hwnd, WM_KEYUP, VK_DOWN, 0);
}

void Bot::PressLeft()
{
    PostMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
    PostMessage(hwnd, WM_KEYUP, VK_LEFT, 0);
}

void Bot::PressRight()
{
    PostMessage(hwnd, WM_KEYDOWN, VK_RIGHT, 0);
    PostMessage(hwnd, WM_KEYUP, VK_RIGHT, 0);
}

// only works for '0' - '9' and 'A' - 'Z'
void Bot::PressKey(char key)
{
    PostMessage(hwnd, WM_KEYDOWN, key, 0);
    PostMessage(hwnd, WM_KEYUP, key, 0);
}

// index = 1 ~ 10
void Bot::ClickSeed(int index)
{
    int y = 42;
    int slots_count = GetSlotsCount();
    if (index >= 1 && index <= slots_count)
    {
        switch (slots_count)
        {
        case 6:
            Click(61 + 59 * index, y);
            break;
        case 7:
            Click(61 + 59 * index, y);
            break;
        case 8:
            Click(61 + 54 * index, y);
            break;
        case 9:
            Click(63 + 52 * index, y);
            break;
        case 10:
            Click(63 + 51 * index, y);
            break;
        default:
            break;
        }
    }
}

void Bot::ClickShovel()
{
    int y = 42;
    int slots_count = GetSlotsCount();
    switch (slots_count)
    {
    case 6:
        Click(490, y);
        break;
    case 7:
        Click(550, y);
        break;
    case 8:
        Click(570, y);
        break;
    case 9:
        Click(600, y);
        break;
    case 10:
        Click(640, y);
        break;
    default:
        break;
    }
}

void Bot::ClickGrid(double row, double col)
{
    int game_scene = GetGameScene();
    switch (game_scene)
    {
    case 2: // pool
    case 3: // fog
        LeftClick(80 * col, 60 + 85 * row);
        break;
    case 4: // roof
    case 5: // moon
        if (col > 5.5)
            LeftClick(80 * col, 50 + 85 * row);
        else
            LeftClick(80 * col, 60 + 85 * row + (110 - 20 * col));
        break;
    case 0: // day
    case 1: // night
    case 6: // mushroom garden
    case 7: // zen garden
    case 8: // aquarium garden
    case 9: // tree of wisdom
    default:
        LeftClick(80 * col, 45 + 100 * row);
        break;
    }
}

} // namespace Pt
