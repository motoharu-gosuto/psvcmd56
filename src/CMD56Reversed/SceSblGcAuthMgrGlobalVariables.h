#pragma once

//===================================
//Base addresses used in current run
//SceSblGcAuthMgr : 0x00ca0000
//SceSblSsMgr : 0x00b98000
//SceSdif : 0x00c68000
//SceSysmem : 0x009c0000
//SceKernelDmacMgr : 0x00992000
//===================================

#include "SceSdif.h"

extern int _00BD84D8_THREAD_ID;

extern sd_context* _00BDCBC0_SD_CTX_ELM;
extern char  _00BDCBC4[0x30];
extern char  _00BDCBF4_REQBUF[0x200];
extern int  _00BDCDF4_PACKET6_DE;
extern char  _00BDCDF8_WB20[0x200];
extern char  _00BDCFF8[0x20];
extern char  _00BDD018[0x34];
extern char  _00BDD04C_RESPBUF1[0x200];
extern char  _00BDD24C_RESPBUF2[0x200];
extern char  _00BDD44C[0x20];