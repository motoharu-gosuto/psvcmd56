#pragma once

#include "Constants.h"
#include "SceSysroot.h"
#include "SceSblSmSchedProxyTypes.h"

//information about SMC calls of Vita:

//there is new information about SMC services on Vita at xyz wiki:
//https://wiki.henkaku.xyz/vita/SceExcpmgr
//https://wiki.henkaku.xyz/vita/F00D_Processor
//https://wiki.henkaku.xyz/vita/SceSblSmschedProxy

//TZ exploit:
//http://hexkyz.blogspot.com/2017/02/the-aftermath-tale-of-secure-worlds.html
//https://wiki.henkaku.xyz/vita/Vulnerabilities#Secure_World_.28TrustZone.29

/*
//http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0301h/ch02s12s13.html

A Secure Monitor Call (SMC) is used to enter the Secure Monitor mode and perform a Secure Monitor kernel service call. 
This instruction can only be executed in privileged modes, so when a User process wants to request a change from one 
world to the other it must first execute a SVC instruction. 
This changes the processor to a privileged mode 
where the Supervisor call handler processes the SVC and executes a SMC, see Exceptions.
*/

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