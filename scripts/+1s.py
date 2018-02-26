
import os

data = ''
file_name = "D:\\repo\\pvz\\res\\version.rc"

if (os.path.isfile(file_name) == False):
    exit()

with open(file_name, "r+") as file:
    for line in file.readlines():
        if(line.find('#define VERSION_BUILD') != -1):
            build_num = line.strip('#define VERSION_BUILD').strip(" ")
            line = line.replace(build_num, str(int(build_num) + 1)) + "\n"
        data += line
    file.seek(0)
    file.truncate()
    file.writelines(data)
