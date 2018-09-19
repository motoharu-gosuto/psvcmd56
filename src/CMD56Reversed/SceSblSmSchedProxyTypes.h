#pragma once

#include <stdint.h>
#include <cstdint>

#include "SceSysroot.h"

typedef unsigned int SmOperationId;

typedef int smc_138_callback(SmOperationId id, int index, int arg2, int arg3, int arg4);

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