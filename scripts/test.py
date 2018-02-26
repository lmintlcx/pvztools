# -*- coding: utf-8 -*-
'''
Description: PvZ Memory Hack
Author: lmintlcx
Date: 2018-02-25 14:37
'''

import ctypes, struct, win32ui, win32gui, win32process, win32api, win32con

HWND = 0
PROCESS = None

rPM = ctypes.windll.kernel32.ReadProcessMemory
wPM = ctypes.windll.kernel32.WriteProcessMemory

def OpenGame():
    global HWND, PROCESS
    HWND = win32ui.FindWindow(None, u"Plants vs. Zombies").GetSafeHwnd()
    PID = win32process.GetWindowThreadProcessId(HWND)[1]
    PROCESS = win32api.OpenProcess(win32con.PROCESS_ALL_ACCESS, False, PID)

# DataType: Byte/Short/Int/Float/Double/String
def memory_read(data_type, address):
    fmt = 'x'
    if data_type == 'Byte':
        fmt = 'b'
    elif data_type == 'Short':
        fmt = 'h'
    elif data_type == 'Int':
        fmt = 'i'
    elif data_type == 'Float':
        fmt = 'f'
    elif data_type == 'Double':
        fmt = 'd'
    else:
        pass
    if data_type != 'String':
        byte = struct.calcsize(fmt)
        buff = ctypes.create_string_buffer(byte)
        rPM(PROCESS.handle, address, buff, byte, 0)
        bytes = struct.unpack('<' + fmt, buff.raw)[0]
        return bytes
    else:
        byte = 32
        buff = ctypes.create_string_buffer(byte)
        rPM(PROCESS.handle, address, buff, byte, 0)
        i = buff.raw.find(b'\x00')
        if i != -1:
            return buff.raw[:i]
        else:
            return buff.raw

# DataType: Byte/Short/Int/Float/Double
def memory_write(data_type, value, address):
    if data_type == 'Byte':
        dst = ctypes.cast(address, ctypes.c_char_p)
        src = ctypes.c_byte(value)
        length = struct.calcsize('b')
        res = wPM(PROCESS.handle, dst, ctypes.byref(src), length, 0x0)
        return res
    elif data_type == 'Short':
        dst = ctypes.cast(address, ctypes.c_char_p)
        src = ctypes.c_short(value)
        length = struct.calcsize('h')
        res = wPM(PROCESS.handle, dst, ctypes.byref(src), length, 0x0)
        return res
    elif data_type == 'Int':
        dst = ctypes.cast(address, ctypes.c_char_p)
        src = ctypes.c_int(value)
        length = struct.calcsize('i')
        res = wPM(PROCESS.handle, dst, ctypes.byref(src), length, 0x0)
        return res
    elif data_type == 'Float':
        dst = ctypes.cast(address, ctypes.c_char_p)
        src = ctypes.c_float(value)
        length = struct.calcsize('f')
        res = wPM(PROCESS.handle, dst, ctypes.byref(src), length, 0x0)
        return res
    elif data_type == 'Double':
        dst = ctypes.cast(address, ctypes.c_char_p)
        src = ctypes.c_double(value)
        length = struct.calcsize('d')
        res = wPM(PROCESS.handle, dst, ctypes.byref(src), length, 0x0)
        return res
    else:
        pass

def ReadMemory(data_type, *address):
    level = len(address)
    memory = 0
    if level == 1:
        memory = memory_read(data_type, address[0])
    elif level == 2:
        memory = memory_read('Int', address[0]) + address[1]
        memory = memory_read(data_type, memory)
    else:
        memory = memory_read('Int', address[0]) + address[1]
        for i in range(2, level):
            memory = memory_read('Int', memory) + address[i]
        memory = memory_read(data_type, memory)
    return memory

def WriteMemory(data_type, value, *address):
    level = len(address)
    memory = 0
    if level == 1:
        res = memory_write(data_type, value, address[0])
    elif level == 2:
        memory = memory_read('Int', address[0]) + address[1]
        res = memory_write(data_type, value, memory)
    else:
        memory = memory_read('Int', address[0]) + address[1]
        for i in range(2, level):
            memory = memory_read('Int', memory) + address[i]
        res = memory_write(data_type, value, memory)
    return res

str_s = u"""
test
"""
str_e = u""

def strxxx():
    global str_s, str_e
    str_t = ""
    for i in str_s:
        if i not in str_t:
            str_t += i
    print (str_t)
    s = "string"
    l = list(str_t)
    l.sort()
    str_e = "".join(l)
    print (str_e)

def main():
    OpenGame()
    # sun
    print (ReadMemory('Int', 0x6a9ec0, 0x768, 0x5560))
    # plant
    plant_count_now = ReadMemory('Int', 0x6a9ec0, 0x768, 0xbc)
    plant_count_max = ReadMemory('Int', 0x6a9ec0, 0x768, 0xb0)
    plant_offset = ReadMemory('Int', 0x6a9ec0, 0x768, 0xac)
    for i in range(0, plant_count_max):
        plant_disappeared = memory_read('Byte', plant_offset + 0x141 + 0x14c * i)
        plant_crushed     = memory_read('Byte', plant_offset + 0x142 + 0x14c * i)
        if plant_disappeared == 0 and plant_crushed == 0:
            plant_type    = memory_read('Int', plant_offset + 0x24 + 0x14c * i)
            plant_row     = memory_read('Int', plant_offset + 0x1c + 0x14c * i)
            plant_col     = memory_read('Int', plant_offset + 0x28 + 0x14c * i)
            print (str(plant_type) + " " + str(plant_row) + " " + str(plant_col))
    # ice trail
    for i in range(0, 6):
        WriteMemory('Int', 600, 0x6a9ec0, 0x768, 0x60c + 0x4 * i)
        print (str(i) + " " + str(ReadMemory('Int', 0x6a9ec0, 0x768, 0x60c + 0x4 * i)))
    # sun value
    print (ReadMemory('Byte', 0x004309f0))

if __name__ == '__main__':
    main()
