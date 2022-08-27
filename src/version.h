/*
 * @Author: lmintlcx 
 * @Date: 2018-06-27 21:34:35 
 * @Description: Version parameter.
 */

#pragma once

#define TEST_VERSION       false
// #define TEST_VERSION       true

#define SIGNATURE_CHECK    false

#define PRODUCT_ICON       "res\\logo.ico"
// #define PRODUCT_ICON       "res\\logo_beta.ico"

#define COMPANY_NAME       "Cube Studio"
#define COMPANY_WEBSITE    "https://pvz.lmintlcx.com"
#define FILE_DESCRIPTION   "PvZ Tools"
#define LEGAL_COPYRIGHT    "(C) 2018-2022 lmintlcx"
#define INTERNAL_NAME      "pvztools"
#define ORIGINAL_FILENAME  "pvztools.exe"
#define PRODUCT_NAME       "PvZ Tools"


#define VERSION_MAJOR      2
#define VERSION_MINOR      7
#define VERSION_PATCH      2
#define VERSION_BUILD      6970


#define TOSTRING_(arg) #arg
#define TOSTRING(arg) TOSTRING_(arg)

#define VERSION_VER VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_BUILD
#define VERSION_NAME TOSTRING(VERSION_MAJOR) "." TOSTRING(VERSION_MINOR) "." TOSTRING(VERSION_PATCH)
#define VERSION_NAME_FULL VERSION_NAME "." TOSTRING(VERSION_BUILD)
