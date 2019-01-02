/*
 * @Author: lmintlcx 
 * @Date: 2018-06-27 21:34:35 
 * @Description: Version parameter.
 */

#pragma once

#define TEST_VERSION       false

#define PRODUCT_ICON       "res\\logo.ico"

#define COMPANY_NAME       "Cube Studio"
#define FILE_DESCRIPTION   "PvZ Tools"
#define LEGAL_COPYRIGHT    "(C) 2018-2019 lmintlcx"
#define INTERNAL_NAME      "pvztools"
#define ORIGINAL_FILENAME  "pvztools.exe"
#define PRODUCT_NAME       "PvZ Tools"


#define VERSION_MAJOR      2
#define VERSION_MINOR      0
#define VERSION_PATCH      1
#define VERSION_BUILD      4966


#define TOSTRING_(arg) #arg
#define TOSTRING(arg) TOSTRING_(arg)

#define VERSION_VER VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_BUILD
#define VERSION_NAME TOSTRING(VERSION_MAJOR) "." TOSTRING(VERSION_MINOR) "." TOSTRING(VERSION_PATCH)
#define VERSION_NAME_FULL VERSION_NAME "." TOSTRING(VERSION_BUILD)
