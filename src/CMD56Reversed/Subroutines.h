#pragma once

//===================================
//Base addresses used in current run
//SceSblGcAuthMgr : 0x00ca0000
//SceSblSsMgr : 0x00b98000
//SceSdif : 0x00c68000
//SceSysmem : 0x009c0000
//SceKernelDmacMgr : 0x00992000
//===================================

#include <map>

#include "GlobalVariables.h"

void sub_CA8C98(const char* source_ptr, int size, int param1, int param2, char* destination_ptr);

int sub_CA8E5C(char* buffer);

int sub_CA8DC0(char idx, int packet6_de, const char* a_00BDCFF8, const char* a_00BDCBC4, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF);

char sub_CA8D30(sd_context* ctx, std::pair<char,char>* result_ptr, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF, char* a_00BDD04C_RESPBUF1, int packetIndex);

int sub_CA8EA0(sd_context* sd_context, int packet6_de, const char* a_00BDCFF8, const char* a_00BDCBC4, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF, char* a_00BDD04C_RESPBUF1, char* a_00BDD24C_RESPBUF2, char* a_00BDD018);

#define CAC924_COMMAND_0C 0x0C
#define CAC924_COMMAND_0D 0x0D
#define CAC924_COMMAND_0E 0x0E
#define CAC924_COMMAND_10 0x10
#define CAC924_COMMAND_11 0x11
#define CAC924_COMMAND_12 0x12
#define CAC924_COMMAND_14 0x14
#define CAC924_COMMAND_15 0x15
#define CAC924_COMMAND_16 0x16
#define CAC924_COMMAND_17 0x17
#define CAC924_COMMAND_18 0x18
#define CAC924_COMMAND_19 0x19
#define CAC924_COMMAND_1B 0x1B
#define CAC924_COMMAND_1C 0x1C
#define CAC924_COMMAND_1D 0x1D
#define CAC924_COMMAND_1E 0x1E
#define CAC924_COMMAND_1F 0x1F
#define CAC924_COMMAND_20 0x20
#define CAC924_COMMAND_21 0x21
#define CAC924_COMMAND_22 0x22
#define CAC924_COMMAND_23 0x23

//I would assume that var968 is some sort of struct
//however first 4 bytes (that are probably size) are never set - from what I see
//second dword contains value 0x02
//starting from third dword - some data is copied from dword_CADC10 - size is 0x90
//this is in total 0x90 + 0x08 = 0x98 bytes
//leaving space of another 0x98 bytes
//meaning this could also be array of 2 elements of size 0x98

int sub_CAC924(char* destination, char* source, int param0, int size, int packet6_de);