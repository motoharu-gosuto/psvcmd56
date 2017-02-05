#include <string>

#include "SceSblSsSmComm.h"

#include "Constants.h"

// =============================

int sub_B86218()
{
   
   return 0;
}

int sub_B862A0()
{
   //many globals   
   return 0;
}

int sub_B864A8()
{
   
   return 0;
}

memory_block_data_entry g_B85010[0x20]; //there are 0x20 entries in SceSblSsSmComm module

int SceSblSmCommForKernel_sceSblSmCommStartSm1_039c73b1(int priority, char* elf_data, int elf_size, int num1, sm_comm_ctx_130* ctx_130, int* id)
{
   //many calls and subroutines

   

   return 0;
}

// =============================

int SceSblSmCommForKernel_sceSblSmCommStartSm2_7863a0cc(int priority, char* elf_path, int num1, sm_comm_ctx_130* ctx_130, int* id)
{
   return 0;
}

// =============================


int SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(int id, int mode, int* err_state, context_db9fc204* ctx, int size)
{
   //many globals, functionality is simplier

   //TODO: imitating size change and encryption - need to figure out what is going on here

   switch(ctx->command)
   {
   case KIRK_SERVICE_1B:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1C:
      ctx->size = 0x33;  // 0x40 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1D:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1E:
      ctx->size = 0x33;  //0x51 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_1F:
      ctx->size = 0x20;  //0xB3 -> 0x20
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case KIRK_SERVICE_20:
      ctx->size = 0x34; //0x116 -> 0x34
      memset(ctx->data, 0xBB, ctx->size);
      break;
   }

   //more imitations
   smc_133_input in;
   in.size = 0x40 + size;
   in.mode = mode;
   in.smcArg0 = 0x00;
   in.unk = 0x00;

   memcpy(&in.data, ctx, 0x814);

   SceSblSmSchedProxyForKernel_smc_133_723b382f(&in, 1, &in);

   return 0;
}

// =============================


int SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(int id)
{
   
   return 0;
}