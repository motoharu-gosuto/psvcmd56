#pragma once

#include <stdint.h>
#include <string>

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

int SceSysrootForKernel_sceSysrootGetSelfInfoForKernel_f10ab792(int index, elf_info_pair* info);

//this is added for the sake of emulation
int SceSysrootForKernel_sceSysrootGetSelfInfoForKernel_Emu(int index, std::string& self_name);

//-------------------------------------------------

//TODO: remove this function
void SceSysroot_InitializeContext();

int SceSysrootForDriver_ksceSysrootIsManufacturingMode_55392965();

int SceSysrootForDriver_check_boot_type_indicator_50fe3b4d();

int SceSysrootForDriver_check_sysroot_buffer_84_8aa268d6();

struct SceSelfInfo // size is 0x90
{
  SceUInt64 program_authority_id; //0x0
  SceUInt64 padding1;     //0x8
  uint8_t capability[32]; //0x10
  uint8_t attribute[32];  //0x30
  uint8_t padding2[16];   //0x50
  uint8_t klicensee[16];  //0x60
  uint32_t unk_70;
  uint32_t unk_74;
  uint32_t unk_78;
  uint32_t unk_7C;
  uint32_t unk_80;
  uint32_t unk_84;
  uint32_t unk_88;
  uint32_t unk_8C;
};

int SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(SceUID pid, SceSelfInfo *self_info);

struct sysbase_shared_block_t
{
  char data[128];
};

struct sysbase_shared_block40
{
  int block_index;
  int unk4;
  int unk8;
  int unkC;
  int unk10;
  int unk14;
  int unk18;
  int unk1C;
  int unk20;
  int unk24;
  int unk28;
  int unk2C;
  int unk30;
  int unk34;
  int unk38;
  int unk3C;
};

struct sysbase_shared_buffer_t
{
  sysbase_shared_block_t blocks0[8];
  sysbase_shared_block_t blocks1[8];
  sysbase_shared_block40 block40;
};

sysbase_shared_buffer_t * SceSysrootForKernel_get_sysbase_0x320_shared_tz_region_c8c8c321();