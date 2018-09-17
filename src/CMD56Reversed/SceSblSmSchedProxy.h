#pragma once

#include "Constants.h"
#include "SceSysroot.h"

//there is new information about SMC services on Vita at xyz wiki:
//https://wiki.henkaku.xyz/vita/F00D_Processor

/*
//http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0301h/ch02s12s13.html

A Secure Monitor Call (SMC) is used to enter the Secure Monitor mode and perform a Secure Monitor kernel service call. 
This instruction can only be executed in privileged modes, so when a User process wants to request a change from one 
world to the other it must first execute a SVC instruction. 
This changes the processor to a privileged mode 
where the Supervisor call handler processes the SVC and executes a SMC, see Exceptions.
*/

//there is a 32 bit code function int proc_enterSMC_996000(int arg_0, int arg_1, int arg_2, int index, int monitorApiNumber)
//that is used by many exports
//it looks like this proxy library is used to perform Secure Monitor kernel service calls

//there is some info on xyz wiki - recirection from SMC
//https://wiki.henkaku.xyz/vita/SceExcpmgr

//==========================================================================================================

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

//==========================================================================================================

int SceSblSmschedProxy_module_start_935cd196();

int SceSblSmSchedProxyForKernel_initialize_shed_proxy_a488d604();

int SceSblSmSchedProxyForKernel_after_proxy_invoke_smc_138_8b84ac2a(SmOperationId id, int function_index, smc_138_callback *cb, int func_arg2);

int SceSblSmSchedProxyForKernel_not_implemented_1dfc8624();

int SceSblSmSchedProxyForKernel_not_implemented_984ec9d1();

int SceSblSmSchedProxyForKernel_smc_12D_sceSblSmSchedProxyInvokeForKernel_1916509b(int priority, void *sm_self_data_paddr, unsigned int num_pairs, sm_invoke_data_block_input *invoke_input, SceSblSmCommContext130 *ctx, SmOperationId *id);

int SceSblSmSchedProxyForKernel_smc_12E_sceSblSmSchedProxyWait_f35efc1a(SmOperationId id, int result[2]);

int SceSblSmSchedProxyForKernel_smc_12F_sceSblSmSchedProxyGetStatus_27eb92f1(SmOperationId id, int status[2]);

int SceSblSmSchedProxyForKernel_smc_130_de4eac3c(SmOperationId id);

int SceSblSmSchedProxyForKernel_smc_133_sceSblSmSchedCallFunc_723b382f(SmOperationId id, int f00d_cmd_fifo_idx, SceSblSmschedCallFuncCommand *cmd_paddr);

int SceSblSmSchedProxyForKernel_smc_134_f70c04ec(SmOperationId id, int smcArg1, int *result);

int SceSblSmSchedProxyForKernel_smc_135_3ce17233(SmOperationId id, int smcArg1, int smcArg2);

int SceSblSmSchedProxyForKernel_smc_136_15b0e4df(SmOperationId id, int num_or_index, int res_from_smc0x137);

int SceSblSmSchedProxyForKernel_smc_137_973a4a7d(SmOperationId id, int num, int *result);

int SceSblSmSchedProxyForKernel_smc_139_85eda5fc(SmOperationId id, int function_index);

int SceSblSmSchedProxyForKernel_smc_13B_uninitialize_shed_proxy_33a3a1e2();

int SceSblSmSchedProxyForKernel_smc_13C_7894b6f0(int smcArg0, int smcArg1, int smcArg2, int smcArg3);