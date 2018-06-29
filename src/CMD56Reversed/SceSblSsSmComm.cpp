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

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommStartSm_Emu(std::string service_name, int* id)
{
   return 0;
}

// =============================

int SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(int id, int service_id, int* f00d_resp, void* ctx, int size)
{
   //many globals, functionality is simplier

   //TODO: imitating size change and encryption - need to figure out what is going on here

   if(service_id == 0x1000B)
   {
      context_db9fc204* ctx_cast = (context_db9fc204*)ctx;

      switch(ctx_cast->command)
      {
      case KIRK_SERVICE_1B:
         //size is ok
         memset(ctx_cast->data, 0xBB, ctx_cast->size);
         break;
      case KIRK_SERVICE_1C:
         ctx_cast->size = 0x33;  // 0x40 -> 0x33
         memset(ctx_cast->data, 0xBB, ctx_cast->size);
         break;
      case KIRK_SERVICE_1D:
         //size is ok
         memset(ctx_cast->data, 0xBB, ctx_cast->size);
         break;
      case KIRK_SERVICE_1E:
         ctx_cast->size = 0x33;  //0x51 -> 0x33
         memset(ctx_cast->data, 0xBB, ctx_cast->size);
         break;
      case KIRK_SERVICE_1F:
         ctx_cast->size = 0x20;  //0xB3 -> 0x20
         memset(ctx_cast->data, 0xBB, ctx_cast->size);
         break;
      case KIRK_SERVICE_20:
         ctx_cast->size = 0x34; //0x116 -> 0x34
         memset(ctx_cast->data, 0xBB, ctx_cast->size);
         break;
      }
   }

   //more imitations
   smc_133_input in;
   in.size = 0x40 + size;
   in.service_id = service_id;
   in.smcArg0 = 0x00;
   in.unk = 0x00;

   memcpy(&in.data, ctx, 0x814);

   SceSblSmSchedProxyForKernel_smc_133_723b382f(&in, 1, &in);

   return 0;
}

// =============================


int SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(int id, std::pair<int, int>* res)
{
   
   return 0;
}