#include "CryptoCommLayer.h"

//=====

int SceSblSsSmComm_SceKernelSuspendForDriver_imp_2bb92967()
{
   return 0;
}

int SceSblSsSmComm_SceKernelSuspendForDriver_imp_4df40893()
{
   return 0;
}

//=====

int SceSblSsSmComm_SceSblSmCommForKernel_exp_db9fc204()
{
   return 0;
}

//=====

int SceSblSsSmComm_SceSblSmSchedProxyForKernel_imp_1916509b()
{
   return 0;
}

int SceSblSsSmComm_SceSblSmSchedProxyForKernel_imp_723b382f()
{
   return 0;
}

int SceSblSsSmComm_SceSblSmSchedProxyForKernel_imp_8b84ac2a()
{
   return 0;
}

int SceSblSsSmComm_SceSblSmSchedProxyForKernel_imp_f35efc1a()
{
   return 0;
}

//=====

int SceSblSsSmComm_SceSysmemForDriver_imp_sceKernelAllocMemBlockForKernel_c94850c9()
{
   return 0;
}

int SceSblSsSmComm_SceSysmemForDriver_imp_sceKernelFreeMemBlockForKernel_009e1c61()
{
   return 0;
}

int SceSblSsSmComm_SceSysmemForDriver_imp_sceKernelGetMemBlockBaseForDriver_a841edda()
{
   return 0;
}

int SceSblSsSmComm_SceSysmemForDriver_imp_sceKernelGetPaddrList_e68beebd()
{
   return 0;
}

int SceSblSsSmComm_SceSysmemForDriver_imp_sceKernelGetPaddr_8d160e65()
{
   return 0;
}

//=====

int SceSblSsSmComm_SceSysrootForDriver_imp_ee934615()
{
   return 0;
}

int SceSblSsSmComm_SceSysrootForDriver_imp_eef091a7()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_0c1d3f20()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_3c8b55a9()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_4336baa4()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_70627f3a()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_71ecb352()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_d270498b()
{
   return 0;
}

int SceSblSsSmComm_SceThreadmgrForDriver_imp_db395782()
{
   return 0;
}


// ============================= SceSblSsSmComm =================== 

int sub_B86218()
{
   
   return 0;
}

int sub_B862A0()
{
   
   return 0;
}

int sub_B864A8()
{
   
   return 0;
}

//assume - init
int SceSblSsSmComm_SceSblSmCommForKernel_exp_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1)
{
   //many calls and subroutines

   //TODO: imitating size change and encryption - need to figure out what is going on here

   switch(ctx->command)
   {
   case CAC924_COMMAND_1B:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1C:
      ctx->size = 0x33;  // 0x40 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1D:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1E:
      ctx->size = 0x33;  //0x51 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1F:
      ctx->size = 0x20;  //0xB3 -> 0x20
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_20:
      ctx->size = 0x34; //0x116 -> 0x34
      memset(ctx->data, 0xBB, ctx->size);
      break;
   }

   return 0;

   
}

// =============================

//assume - gen/hash
int SceSblSsSmComm_SceSblSmCommForKernel_exp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0)
{
   //many globals, functionality is simplier

   return 0;
}

// =============================

int sub_B862A0()
{
   //many globals

   //SceSblSsSmComm.SceThreadmgrForDriver._imp_70627f3a
   //SceSblSsSmComm.SceThreadmgrForDriver._imp_db395782
   return 0;
}

//assume - deinit
int SceSblSsSmComm_SceSblSmCommForKernel_exp_0631f8ed(int unk)
{
   
   return 0;
}