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

//TODO: this type is weid just as the code that uses it
//this needs to be fixed (however this code is not required, just good to know timing restrictions)

struct sce_time
{
   union
   {
      struct
      {
         uint32_t v0;
         uint32_t v1;
      };
      uint64_t value;
   };
};

int SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(char* buffer, int size, int unk);
int SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(char* buffer);

struct f10ab792_input
{
   uint32_t size; //input
   uint32_t unk_4_var970; //output
   uint32_t unk_8_var96C; //output
};

int SceSblGcAuthMgr_SceSysrootForKernel_imp_f10ab792(int arg0, f10ab792_input* arg1);

struct _039c73b1_context
{
   char var968[0x130];
   int var838;
   int command; //var834
   char data[0x800]; //var830
   int packet6_de; //var30
   int size; //var2C
   int var28;
};

int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1);

int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0);
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(int unk);

int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_3c8b55a9(int un0, int unk1, int unk2);
int SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83();
int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_d270498b(int unk0, int unk1);
sce_time SceSblGcAuthMgr_SceThreadmgrForDriver_imp_sceKernelGetSystemTimeWideForDriver_f4ee4fa9();

//TODO: remove this function
void InitializeUnknownContext();