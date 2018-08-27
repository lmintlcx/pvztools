
import os

data = ''
version_file = os.path.join(os.path.dirname(__file__), "..\\src\\version.h")

if (os.path.isfile(version_file) == False):
    exit()

with open(version_file, "r+") as file:
    for line in file.readlines():
        if(line.find('#define VERSION_BUILD') != -1):
            build_num = line.strip(' ').strip('#define').strip(' ').strip('VERSION_BUILD').strip(' ')
            line = line.replace(build_num, str(int(build_num) + 1)) + "\n"
        data += line
    file.seek(0)
    file.truncate()
    file.writelines(data)
