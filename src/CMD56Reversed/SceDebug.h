#pragma once

struct kernel_message_ctx
{
  int hex_value0_hi;
  int hex_value0_lo;
  int hex_value1;
  char* msg0;
  int num;
  char* msg1;
};

int SceDebugForDriver_sceKernelCpuPrintKernelPanicForDriver_391b5b74(kernel_message_ctx *msg_ctx, void *some_address);

int SceDebugForDriver_sceDebugPrintf2ForDriver_02b04343(int msg_type_flag, kernel_message_ctx *msg_ctx, const char *fmt, ...);