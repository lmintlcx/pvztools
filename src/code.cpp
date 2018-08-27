
#include <iostream>
#include <cassert>

#include <Windows.h>

#include "src/code.h"

namespace Pt
{

Code::Code()
{
    unsigned int page = 16; // 1 or 2 would be enough for most occasions
    code = new unsigned char[4096 * page];
    length = 0;
}

Code::~Code()
{
    delete[] code;
}

void Code::asm_init()
{
    length = 0;
}

void Code::asm_add_byte(unsigned char value)
{
    code[length] = value;
    length += 1;
}

void Code::asm_add_word(unsigned short value)
{
    (unsigned short &)code[length] = value;
    length += 2;
}

void Code::asm_add_dword(unsigned int value)
{
    (unsigned int &)code[length] = value;
    length += 4;
}

void Code::asm_push(int value)
{
    asm_add_byte((unsigned char)(0x68));
    asm_add_dword(value);
}

void Code::asm_mov_exx(Reg reg, int value)
{
    unsigned char mov_exx[] = {0xb8, 0xbb, 0xb9, 0xba, 0xbe, 0xbf, 0xbd};
    asm_add_byte(mov_exx[static_cast<unsigned int>(reg)]);
    asm_add_dword(value);
}

void Code::asm_mov_exx_dword_ptr(Reg reg, int value)
{
    unsigned char mov_exx_dword_ptr[] = {0xa1, 0x1d, 0x0d, 0x15, 0x35, 0x3d, 0x2d};
    asm_add_byte((unsigned char)(0x3e));
    if (reg != Reg::EAX)
        asm_add_byte((unsigned char)(0x8b));
    asm_add_byte(mov_exx_dword_ptr[static_cast<unsigned int>(reg)]);
    asm_add_dword(value);
}

void Code::asm_mov_exx_dword_ptr_exx_add(Reg reg, int value)
{
    unsigned char mov_exx_dword_ptr_exx_add[] = {0x80, 0x9b, 0x89, 0x92, 0xb6, 0xbf, 0xad};
    asm_add_byte((unsigned char)(0x8b));
    asm_add_byte(mov_exx_dword_ptr_exx_add[static_cast<unsigned int>(reg)]);
    asm_add_dword(value);
}

void Code::asm_push_exx(Reg reg)
{
    unsigned char push_exx[] = {0x50, 0x53, 0x51, 0x52, 0x56, 0x57, 0x55};
    asm_add_byte(push_exx[static_cast<unsigned int>(reg)]);
}

void Code::asm_pop_exx(Reg reg)
{
    unsigned char pop_exx[] = {0x58, 0x5b, 0x59, 0x5a, 0x5e, 0x5f, 0x5d};
    asm_add_byte(pop_exx[static_cast<unsigned int>(reg)]);
}

void Code::asm_add_esp(int value)
{
    asm_add_byte((unsigned char)(0x81));
    asm_add_byte((unsigned char)(0xc4));
    asm_add_dword(value);
}

void Code::asm_call(int addr)
{
    asm_add_byte((unsigned char)(0xe8));
    asm_add_dword((unsigned int)(0x00000002));
    asm_add_word((unsigned short)(0x06eb));
    asm_push(addr);
    asm_ret();
}
void Code::asm_ret()
{
    asm_add_byte((unsigned char)(0xc3));
}

void Code::asm_code_inject(HANDLE handle)
{
    LPVOID thread_addr = VirtualAllocEx(handle, nullptr, length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (thread_addr != nullptr)
    {
        WriteProcessMemory(handle, thread_addr, code, length, nullptr);
        HANDLE thread_handle = CreateRemoteThread(handle, nullptr, 0, LPTHREAD_START_ROUTINE(thread_addr), nullptr, 0, nullptr);
        if (thread_handle != nullptr)
        {
            WaitForSingleObject(thread_handle, INFINITE);
            CloseHandle(thread_handle);
        }
        VirtualFreeEx(handle, thread_addr, 0, MEM_RELEASE);
    }

#ifdef _DEBUG
    assert(length > 0);
    assert(length < 4096 * 16);
    std::cout << "Asm Code: ";
    for (size_t i = 0; i < length; i++)
        std::cout << std::hex << int(code[i]) << " ";
    std::cout << std::endl;
#endif
}

} // namespace Pt
