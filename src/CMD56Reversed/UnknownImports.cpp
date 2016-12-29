#include "UnknownImports.h"

//CRITICAL - key generation

//assume - gen/buffer shift
int SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(char* buffer, int size, int unk)
{
   return 0;
}

//wrapper
int SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(char* buffer)
{
   return SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(buffer, 0x40, 0x01);
}

//=========================================

//CRITICAL - buffer init

int SceSblGcAuthMgr_SceSysrootForKernel_imp_f10ab792(int arg0, int* arg1)
{
   /*
   //this is not even reviewed yet - need to do

   if(arg0 > 2)
      return 0x80020005;

   if(arg1 == 0)
      return 0x80020006;

   int r3 = arg1[0];
   if(r3 != 0x0C)
      return 0x80020009;

   int r3 = 0x8BF5F8; //global?
   int r3 = r3[0x00];
   int r3 = r3[0x3A0];

   if(r3 == 0)
      return 0x8001000C;

   int r2 = r3 + (arg0 << 3);
   int r2 = r2[0x04];

   if(r2 == 0)
      return 0x80010002;

   int r3 = ?;
   //LDR.W R3, [R3,R0,LSL#3]

   r1[0x04] = r3;
   r1[0x08] = r2;
   */
   return 0;
}

//assume - init
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(int r0, int r1, int r2, int r3, char* unk0, int* unk1)
{
   return 0;
}

//assume - gen/hash
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0)
{
   return 0;
}

//assume - deinit
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(int unk)
{
   return 0;
}

//=========================================

//NON CRITICAL

//assume - some thread init
int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_3c8b55a9(int un0, int unk1, int unk2)
{
   return 0;
}

//assume - some sort of deinit
int SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83()
{
   return 0;
}

//assume - some thread deinit
int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_d270498b(int unk0, int unk1)
{
   return 0;
}

//this is user space signature for the function
//SceInt64 sceKernelGetSystemTimeWide(void);
//I would assume that it returns the same value in kernel as well

sce_time SceSblGcAuthMgr_SceThreadmgrForDriver_imp_sceKernelGetSystemTimeWideForDriver_f4ee4fa9()
{
   return sce_time();
}
