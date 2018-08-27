/*
 * @Author: lmintlcx 
 * @Date: 2018-06-29 19:17:18 
 * @Description: Pack and unpack ".pak" file.
 */

// constructor of std::fstream in mingw-w64 does not support std::wstring, use win32 api instead

#pragma once

namespace Pt
{

class PAK
{
public:
  PAK();
  ~PAK();

  void Unpack(std::wstring, std::wstring);
  void Pack(std::wstring);

private:
  std::wstring FormatPath(const std::wstring &);
};

} // namespace Pt
