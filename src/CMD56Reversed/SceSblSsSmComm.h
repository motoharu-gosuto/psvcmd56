#pragma once

#include <stdint.h>

#include "SceSblSmSchedProxy.h"

struct memory_block_data_entry
{
   smc_133_input* ptr; //this will be used as input to db9fc204
   int unk;
   SceUID mid; //memory block id
   SceUID eid; //event flag id
};

typedef struct sm_comm_ctx_130
{
   uint32_t unk_0;
   uint32_t self_type;
   char data0[0x90]; //hardcoded data
   char data1[0x90];
   uint32_t pathId; 
   uint32_t unk_12C;   
}sm_comm_ctx_130;

int SceSblSmCommForKernel_sceSblSmCommStartSm1_039c73b1(int priority, char* elf_data, int elf_size, int num1, sm_comm_ctx_130* ctx_130, int* id);

int SceSblSmCommForKernel_sceSblSmCommStartSm2_7863a0cc(int priority, char* elf_path, int num1, sm_comm_ctx_130* ctx_130, int* id);

int SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(int id, int service_id, int* f00d_resp, void* ctx, int size);

int SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(int id, std::pair<int, int>* res);

//====================================================

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommStartSm_Emu(std::string service_name, int* id);

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommCallFunc_Emu(int id, int service_id, int* f00d_resp, void* ctx, int size);

//this is added for the sake of emulation
int SceSblSmCommForKernel_sceSblSmCommStopSm_Emu(int id);
