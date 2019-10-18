
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

#include <Windows.h>

#include "src/pak.h"

namespace Pt
{

PAK::PAK()
{
}

PAK::~PAK()
{
}

bool PAK::Unpack(std::wstring src_file, std::wstring dst_dir)
{
    std::wstring src_path = FormatPath(src_file);
    std::wstring dst_path = FormatPath(dst_dir);

    // open file, get size
    HANDLE hfr = CreateFile(src_path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    DWORD size = GetFileSize(hfr, nullptr);

    // loat entire file to memory
    DWORD read_size = 0;
    char *buffer = new char[size];
    ReadFile(hfr, buffer, size, &read_size, nullptr);
    CloseHandle(hfr);

#ifdef _DEBUG
    assert(hfr != INVALID_HANDLE_VALUE);
    assert(size != INVALID_FILE_SIZE);
    assert(size > 0);
    assert(size == read_size);
#endif

    // XOR entire file with byte 0xf7
    for (size_t i = 0; i < size; ++i)
        buffer[i] = buffer[i] ^ 0xf7;

    // check file header
    char file_header[9] = {char(0xc0), //
                           char(0x4a), //
                           char(0xc0), //
                           char(0xba), //
                           char(0x00), //
                           char(0x00), //
                           char(0x00), //
                           char(0x00), //
                           char(0x00)};
    bool header_ok = true;
    for (size_t i = 0; i < 9; i++)
    {
        if (buffer[i] != file_header[i])
        {
            header_ok = false;
            break;
        }
    }
    if (!header_ok)
    {
        delete[] buffer;
        return false;
    }

    unsigned int index = 9; // skip file header
    unsigned int count = 0;
    std::vector<std::wstring> files_name;
    std::vector<unsigned int> files_size;

    // data structure of index section
    char name_size;                      // 1
    char file_name[MAX_PATH];            // int(name_size)
    int file_size;                       // 4
    [[maybe_unused]] FILETIME file_time; // 8
    char eof_flag;                       // 1

    // get index info
    do
    {
        name_size = buffer[index];
        index++;

        for (int i = 0; i < int(name_size); i++)
            file_name[i] = buffer[index + i];
        file_name[int(name_size)] = 0;
        // char* -> std::wstring
        std::wstring file_name_wstr(&file_name[0], &file_name[int(name_size)]);
        index += int(name_size);

        file_size = (int &)buffer[index];
        index += 4;

#ifdef _DEBUG
        file_time = (FILETIME &)buffer[index]; // useless
#endif
        index += 8;

        eof_flag = buffer[index];
        index++;

        files_name.push_back(file_name_wstr);
        files_size.push_back(file_size);
        count++;

#ifdef _DEBUG
        SYSTEMTIME system_time;
        FileTimeToSystemTime(&file_time, &system_time);
        std::wcout << int(name_size) << " "
                   << file_name << " "
                   << file_size << " "
                   << system_time.wYear << "."
                   << system_time.wMonth << "."
                   << system_time.wDay << " "
                   << system_time.wHour << ":"
                   << system_time.wMinute << ":"
                   << system_time.wSecond << " "
                   << int(eof_flag) << std::endl;
#endif
    } while (eof_flag == 0x00); // eof_flag != 0x80

    // extract all files
    for (size_t i = 0; i < count; i++)
    {
        std::wstring output_file_path = dst_path + L"\\" + files_name.at(i);
        unsigned int output_file_size = files_size.at(i);

        // remove file name, get directory and create it
        bool path_created = CreatePath(output_file_path.substr(0, output_file_path.find_last_of(L"\\")));

        if (path_created)
        {
            char *output_buff = new char[output_file_size];
            for (size_t j = 0; j < output_file_size; j++)
                output_buff[j] = buffer[index + j];

            HANDLE hfw = CreateFile(output_file_path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (hfw != INVALID_HANDLE_VALUE)
            {
                DWORD write_size = 0;
                WriteFile(hfw, output_buff, output_file_size, &write_size, nullptr);
                CloseHandle(hfw);
#ifdef _DEBUG
                assert(output_file_size == write_size);
#endif
            }

            delete[] output_buff;
        }

        index += output_file_size;
    }

#ifdef _DEBUG
    assert(index == size);
#endif

    delete[] buffer;
    return true;
}

bool PAK::Pack(std::wstring src_dir, std::wstring dst_file)
{
    std::wstring src_path = FormatPath(src_dir);
    std::wstring dst_path = FormatPath(dst_file);

    auto [files_name, files_size, files_time] = GetFiles(src_path);
    unsigned int count = files_name.size();

#ifdef _DEBUG
    SYSTEMTIME system_time;
    for (size_t i = 0; i < count; i++)
    {
        FileTimeToSystemTime(&files_time[i], &system_time);
        std::wcout << files_name[i] << " "
                   << files_size[i] << " "
                   << system_time.wYear << "."
                   << system_time.wMonth << "."
                   << system_time.wDay << " "
                   << system_time.wHour << ":"
                   << system_time.wMinute << ":"
                   << system_time.wSecond << std::endl;
    }
#endif

    char file_header[9] = {char(0xc0), //
                           char(0x4a), //
                           char(0xc0), //
                           char(0xba), //
                           char(0x00), //
                           char(0x00), //
                           char(0x00), //
                           char(0x00), //
                           char(0x00)};
    for (size_t i = 0; i < 9; i++)
        file_header[i] = file_header[i] ^ 0xf7;

    // data structure of index section
    char name_size;           // 1
    char file_name[MAX_PATH]; // int(name_size)
    int file_size;            // 4
    FILETIME file_time;       // 8
    char eof_flag;            // 1

    // output file
    HANDLE hfw = CreateFile(dst_path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hfw == INVALID_HANDLE_VALUE)
        return false;

    // write header
    DWORD write_size = 0;
    WriteFile(hfw, file_header, 9, &write_size, nullptr);
#ifdef _DEBUG
    assert(9 == write_size);
#endif

    // write index section
    for (size_t i = 0; i < count; i++)
    {
        std::wstring file_path = files_name.at(i);

        // get info
        name_size = char(file_path.size());
        for (int i = 0; i < int(name_size); i++)
            file_name[i] = char(file_path.at(i)); // file names in .pak should be full english
        file_name[int(name_size)] = 0;
        file_size = files_size.at(i);
        file_time = files_time.at(i);
        eof_flag = (i != count - 1) ? 0x00 : 0x80;

        // struct buff
        unsigned int struct_size = sizeof(char) + int(name_size) + sizeof(int) + sizeof(FILETIME) + sizeof(char);
        char *buff = new char[struct_size];

        // copy info to buff
        unsigned int index = 0;

        buff[index] = name_size;
        index += sizeof(char);

        for (int j = 0; j < name_size; j++)
            buff[index + j] = file_name[j];
        index += int(name_size);

        (int &)buff[index] = file_size;
        index += sizeof(int);

        (FILETIME &)buff[index] = file_time;
        index += sizeof(FILETIME);

        buff[index] = eof_flag;
        index += sizeof(char);

#ifdef _DEBUG
        assert(index == struct_size);
#endif

        for (size_t k = 0; k < struct_size; k++)
            buff[k] = buff[k] ^ 0xf7;

        // write buff to file
        DWORD write_size = 0;
        WriteFile(hfw, buff, struct_size, &write_size, nullptr);
#ifdef _DEBUG
        assert(struct_size == write_size);
#endif

        delete[] buff;
    }

    // write data section
    for (size_t i = 0; i < count; i++)
    {
        std::wstring full_file_path = src_path + L"\\" + files_name.at(i);

        HANDLE hfr = CreateFile(full_file_path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (hfr != INVALID_HANDLE_VALUE)
        {
            unsigned int size = files_size.at(i);
            DWORD read_size = 0;
            char *buffer = new char[size];
            ReadFile(hfr, buffer, size, &read_size, nullptr);
#ifdef _DEBUG
            assert(GetFileSize(hfr, nullptr) == size);
            assert(size == read_size);
#endif

            for (size_t i = 0; i < size; ++i)
                buffer[i] = buffer[i] ^ 0xf7;

            DWORD write_size = 0;
            WriteFile(hfw, buffer, size, &write_size, nullptr);
#ifdef _DEBUG
            assert(size == write_size);
#endif
            delete[] buffer;
            CloseHandle(hfr);
        }
    }

    CloseHandle(hfw);
    return true;
}

std::wstring PAK::FormatPath(const std::wstring &wstr)
{
    std::wstring result = wstr;
    std::wstring::size_type pos(0);

    while ((pos = result.find(L"/")) != std::wstring::npos)
    {
        result.replace(pos, 1, L"\\");
    }

    while ((pos = result.find(L"\\\\")) != std::wstring::npos)
    {
        result = result.substr(0, pos) + result.substr(pos + 1);
    }

    while (result.find_last_of(L"\\") == result.size() - 1)
    {
        result = result.substr(0, result.find_last_of(L"\\"));
    }

#ifdef _DEBUG
    std::wcout << L"format: " << result << std::endl;
    assert((pos = result.find(L"/")) == std::wstring::npos);
    assert((pos = result.find(L"\\\\")) == std::wstring::npos);
    assert(result.find_last_of(L"\\") != result.size() - 1);
#endif

    return result;
}

// create path recursively
bool PAK::CreatePath(const std::wstring &path)
{
    // path exist
    if (GetFileAttributes(path.c_str()) == FILE_ATTRIBUTE_DIRECTORY)
        return true;

    // create success
    if (CreateDirectory(path.c_str(), nullptr))
        return true;

    // parent path not exist, failed
    if (path.substr(0, path.find_last_of(L"\\")) == path)
        return false;

    // parent path create failed
    if (!CreatePath(path.substr(0, path.find_last_of(L"\\"))))
        return false;

    // parent path create succeed, create this path
    return CreateDirectory(path.c_str(), nullptr);
}

file_info PAK::GetFiles(const std::wstring &find_path)
{
    v_name names;
    v_size sizes;
    v_time times;

    std::wstring path = find_path + L"\\*";
    WIN32_FIND_DATA ffd;
    HANDLE hf;

    hf = FindFirstFile(path.c_str(), &ffd);
    if (hf != INVALID_HANDLE_VALUE)
    {
        do
        {
            std::wstring name = ffd.cFileName;
            if (name == L"." || name == L".." || name == L"Thumbs.db")
                continue;
            if (ffd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
            {
                std::wstring sub_path = find_path + L"\\" + name;
                auto [_names, _sizes, _times] = GetFiles(sub_path);
                for (size_t i = 0; i < _names.size(); i++)
                {
                    names.push_back(name + L"\\" + _names[i]);
                    sizes.push_back(_sizes[i]);
                    times.push_back(_times[i]);
                }
            }
            else
            {
                names.push_back(ffd.cFileName);
                sizes.push_back(ffd.nFileSizeLow);
                times.push_back(ffd.ftLastWriteTime);
            }
        } while (FindNextFile(hf, &ffd) != 0);
        FindClose(hf);
    }

    return {names, sizes, times};
}

} // namespace Pt
