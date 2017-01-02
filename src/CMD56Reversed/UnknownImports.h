#pragma once

//===================================
//Base addresses used in current run
//SceSblGcAuthMgr : 0x00ca0000
//SceSblSsMgr : 0x00b98000
//SceSdif : 0x00c68000
//SceSysmem : 0x009c0000
//SceKernelDmacMgr : 0x00992000
//===================================

#include <stdint.h>

int SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(char* buffer, int size, int unk);

int SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(char* buffer);


int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1);

int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0);

int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(int unk);

int SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83();

//TODO: remove this function
void InitializeUnknownContext();