
#include <iostream>

#include <Windows.h>

#include "src/process.h"

namespace Pt
{

Process::Process()
{
    hwnd = nullptr;
    pid = 0;
    handle = nullptr;
}

Process::~Process()
{
    if (IsValid())
        CloseHandle(handle);
}

bool Process::OpenByWindow(const wchar_t *class_name, const wchar_t *window_name)
{
    if (IsValid())
        CloseHandle(handle);

    hwnd = FindWindow(class_name, window_name);
    if (hwnd != nullptr)
        GetWindowThreadProcessId(hwnd, &pid);
    if (pid != 0)
        handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

#ifdef _DEBUG
    // assert(PROCESS_ALL_ACCESS == 0x001F0FFF);
#endif

#ifdef _DEBUG
    std::cout << "OpenByWindow: ";
    std::wcout << (class_name == nullptr ? L"nullptr" : class_name) << L"  "
               << (window_name == nullptr ? L"nullptr" : window_name);
    std::cout << "  " << hwnd << "  " << pid << "  " << handle << std::endl;
#endif

    return hwnd != nullptr;
}

bool Process::IsValid()
{
    if (handle == nullptr)
        return false;

    DWORD exit_code;
    GetExitCodeProcess(handle, &exit_code);
    bool valid = (exit_code == STILL_ACTIVE);

#ifdef _DEBUG
    if (!valid)
        std::cout << "Not Valid" << std::endl;
#endif

    return valid;
}

} // namespace Pt
