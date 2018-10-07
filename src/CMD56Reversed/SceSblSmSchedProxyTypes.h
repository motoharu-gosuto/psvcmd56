#pragma once

#include <stdint.h>
#include <cstdint>

#include "SceSysroot.h"

typedef unsigned int SmOperationId;

#define CRY_INTERRUPT_INDEX0 0
#define CRY_INTERRUPT_INDEX1 1
#define CRY_INTERRUPT_INDEX2 2
#define CRY_INTERRUPT_INDEX3 3

#define F00D_FIFO_REGISTER_INDEX1 1
#define F00D_FIFO_REGISTER_INDEX2 2
#define F00D_FIFO_REGISTER_INDEX3 3

typedef int smc_138_callback(SmOperationId id, int intr_index, int arg2, int arg3, int arg4);

struct sm_invoke_data_block_input
{
  int unk0;
  int unk4;
  int unk8;
  int unkC;
};

struct SceSblSmCommContext130
{
  uint32_t unk_0;
  uint32_t self_type;
  SceSelfInfo caller_self_info;
  SceSelfInfo called_self_info;
  uint32_t pathId;
  uint32_t unk_12C;
};

struct SceSblSmschedCallFuncCommand
{
  unsigned int size;
  unsigned int service_id;
  unsigned int response;
  unsigned int unk2;
  unsigned int padding[12];
  unsigned int data[];
};

enum class SmStatus
{
   SM_STATUS_1 = 0x1,
   SM_STATUS_2 = 0x2,
   SM_STATUS_3 = 0x3,
   SM_STATUS_4 = 0x4,
   SM_STATUS_5 = 0x5,
   SM_STATUS_6 = 0x6,
   SM_STATUS_7 = 0x7,
   SM_STATUS_8 = 0x8,
   SM_STATUS_9 = 0x9,
   SM_STATUS_A = 0xA,
   SM_STATUS_B = 0xB,
   SM_STATUS_C = 0xC,
};

struct smc_12E_data_t
{
  int status0;
  SmStatus status1;
};

struct smc_12F_data_t
{
  int status0;
  SmStatus status1;
};

enum class F00D_cmd_index
{
   F00D_CMD_B_INDEX = 0,
   F00D_CMD_C_INDEX = 1,
   F00D_CMD_D_INDEX = 2,
   F00D_CMD_E_INDEX = 3,
   F00D_CMD_F_INDEX = 4,
};