#pragma once

#include "SceSblSmSchedProxyTypes.h"

#define INVALID_SM_OPERATION_HANDLE -1

typedef unsigned int SmOperationHandle;

struct item_996E0C //size is 0x10
{
  item_996E0C *item0;
  item_996E0C *item1;
  sysbase_shared_block_t *sysbase_block;
  int unkC;
};

struct lock_8F501C
{
  int lock;
};

struct global_lock_t
{
  int lock;
};

#define SCHED_PROXY_STATE_UNINITIALIZED 0
#define SCHED_PROXY_STATE_INITIALIZED 1
#define SCHED_PROXY_STATE_DEINITIALIZED 2

struct sched_proxy_state_t
{
  int state;
};

struct operation_callback_data
{
  int func_arg2;
  int func_arg4;
  int func_arg3;
};

struct shed_proxy_operation_callback_entry_t
{
   smc_138_callback *cb;
   operation_callback_data data;
};

struct shed_proxy_operation_item_t
{
  int is_used;
  SmOperationId operation_id;
  SmOperationHandle operation_handle;
  SceUID SceSblSmsProxy_event_uid;
  SceUID SceSblSmsProxyWait_mutex_uid;
  shed_proxy_operation_callback_entry_t functions[4];
};

struct SceSblSmschedProxyHeap
{
  shed_proxy_operation_item_t items[0x40];
};

struct smc_12D_data_self_t
{
  unsigned int self_type;
  uint32_t pathId;
  SceUInt64 program_authority_id;
  uint8_t caller_capability[32];
};

struct smc_12D_data_t
{
   int unk0;
   int unk4;
   int unk8;
   int unkC;
   SmOperationId invoke_operation_id;
   SmOperationHandle operation_handle;
   smc_12D_data_self_t caller_self_info;
};

struct smc_12E_data_t
{
  int unk0;
  int unk4;
};

struct smc_12F_data_t
{
  int status0;
  int status1;
};

struct smc_134_137_data_t
{
  int unk0;
};

#define INTR_SET_EVENT_FLAG 1
#define INTR_CALL_CB_EX 2
#define INTR_CALL_CB 4

struct smc_13A_intr_data_t
{
  int function_index;
  SmOperationId operation_id;
  int cb_call_mode_flags;
  int event_flag_bits;
  int smc_arg2;
  int func_arg4;
  int func_arg3;
};