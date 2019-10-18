/*
 * @Author: lmintlcx 
 * @Date: 2018-06-29 19:17:18 
 * @Description: Pack and unpack ".pak" file.
 */

#pragma once

namespace Pt
{

typedef std::vector<std::wstring> v_name;
typedef std::vector<unsigned int> v_size;
typedef std::vector<FILETIME> v_time;
typedef std::tuple<v_name, v_size, v_time> file_info;

class PAK
{
public:
  PAK();
  ~PAK();

  bool Unpack(std::wstring, std::wstring);
  bool Pack(std::wstring, std::wstring);

private:
  std::wstring FormatPath(const std::wstring &);
  bool CreatePath(const std::wstring &);
  file_info GetFiles(const std::wstring &);
};

} // namespace Pt
