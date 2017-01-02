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

#include "SceSdif.h"

void sub_CA8C98(const char* source_ptr, int size, int param1, int param2, char* destination_ptr);

int sub_CA8E5C(char* buffer);

int sub_CA8DC0(char idx, int packet6_de, const char* a_00BDCFF8, const char* a_00BDCBC4, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF);

char sub_CA8D30(sd_context* ctx, std::pair<char,char>* result_ptr, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF, char* a_00BDD04C_RESPBUF1, int packetIndex);

int sub_CA8EA0(sd_context* sd_context, int packet6_de, const char* a_00BDCFF8, const char* a_00BDCBC4, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF, char* a_00BDD04C_RESPBUF1, char* a_00BDD24C_RESPBUF2, char* a_00BDD018);

//I would assume that var968 is some sort of struct
//however first 4 bytes (that are probably size) are never set - from what I see
//second dword contains value 0x02
//starting from third dword - some data is copied from dword_CADC10 - size is 0x90
//this is in total 0x90 + 0x08 = 0x98 bytes
//leaving space of another 0x98 bytes
//meaning this could also be array of 2 elements of size 0x98

int sub_CAC924(char* destination, char* source, int param0, int size, int packet6_de);