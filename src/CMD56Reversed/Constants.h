#pragma once

//===================================
//Base addresses used in current run
//SceSblGcAuthMgr : 0x00ca0000
//SceSblSsMgr : 0x00b98000
//SceSdif : 0x00c68000
//SceSysmem : 0x009c0000
//SceKernelDmacMgr : 0x00992000
//===================================

#define STACK_CHECK_FAIL -1

#define DSB(option)

#define PLD(adr)

typedef int SceUID;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
typedef unsigned int SceUInt32;
typedef long long SceInt64;