#pragma once

#include <stdint.h>

#include "Constants.h"

//--------------------------------------------------

//these 2 functions are wrappers that are built upon 
//SceSysmem.SceCpuForDriver._exp_atomic_add_341b6e81

//they operate on global variable 008B80A8, incrementing or decrementing it by 0x10
//they return value after add/sub operation

//this variable is not used in any other function meaning that it is part of some bigger structure ?

int SceSysrootForDriver_atomic_add_10_to_008B80A8_ee934615();

int SceSysrootForDriver_atomic_sub_10_from_008B80A8_eef091a7();

//-------------------------------------------------

typedef struct elf_info_pair
{
   uint32_t size; // 0x0C
   char* elf_data; 
   uint32_t elf_size;
} elf_info_pair;

int SceSysrootForKernel_f10ab792(int arg0, elf_info_pair* arg1);

//-------------------------------------------------

//TODO: remove this function
void SceSysroot_InitializeContext();

int SceSysrootForDriver_ksceSysrootIsManufacturingMode_55392965();

int SceSysrootForDriver_check_boot_type_indicator_50fe3b4d();

int SceSysrootForDriver_check_sysroot_buffer_84_8aa268d6();

typedef struct SceSelfAuthInfo // size is 0x90
{
   SceUInt64 auth_id;
   
   uint32_t unk_10[20];
   
   uint32_t unk_60;
   uint32_t unk_64;
   char klicensee[0x10]; // offset 0x68
   
   uint32_t unk_78;
   uint32_t unk_7C;
   
   uint32_t unk_80;
   uint32_t unk_84;
   uint32_t unk_88;
   uint32_t unk_8C;
   
   uint32_t unk_90;
   uint32_t unk_94;
} SceSelfAuthInfo;

int SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(SceUID pid, SceSelfAuthInfo *self_info);