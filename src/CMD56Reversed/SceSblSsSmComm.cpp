#include <string>

#include "SceSblSsSmComm.h"

#include "Constants.h"

#include "F00D/F00DServiceDispatcherService.h"

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

int SceSblSmCommForKernel_sceSblSmCommStartSm2_7863a0cc(int priority, char* elf_path, int num1, sm_comm_ctx_130* ctx_130, int* id)
{
   return 0;
}

int SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(int id, int service_id, int* f00d_resp, void* ctx, int size)
{
   //many globals, functionality is simplier

   //more imitations
   smc_133_input in;
   in.size = 0x40 + size;
   in.service_id = service_id;
   in.smcArg0 = 0x00;
   in.unk = 0x00;

   memcpy(&in.data, ctx, size);

   SceSblSmSchedProxyForKernel_smc_133_723b382f(&in, 1, &in);

   return 0;
}

int SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(int id, std::pair<int, int>* res)
{
   return 0;
}

// =============================

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommStartSm_Emu(std::string service_name, int* id)
{
   auto service = f00d::F00DServiceDispatcherService::get();
   return service->start(service_name, id);
}

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommCallFunc_Emu(int id, int service_id, int* f00d_resp, void* ctx, int size)
{
   auto service = f00d::F00DServiceDispatcherService::get();
   return service->dispatch(id, service_id, f00d_resp, ctx, size);
}

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommStopSm_Emu(int id)
{
   auto service = f00d::F00DServiceDispatcherService::get();
   return service->stop(id);
}