#pragma once

#include <stdint.h>

struct sce_time
{
   uint32_t v0;
   uint32_t v1;
};

int SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(char* buffer, int size, int unk);
int SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(char* buffer);

int SceSblGcAuthMgr_SceSysrootForKernel_imp_f10ab792(int arg0, int* arg1);
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(int r0, int r1, int r2, int r3, char* unk0, int* unk1);
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0);
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(int unk);

int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_3c8b55a9(int un0, int unk1, int unk2);
int SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83();
int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_d270498b(int unk0, int unk1);
sce_time SceSblGcAuthMgr_SceThreadmgrForDriver_imp_sceKernelGetSystemTimeWideForDriver_f4ee4fa9();