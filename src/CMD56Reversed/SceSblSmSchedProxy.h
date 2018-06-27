#pragma once

#include "Constants.h"

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

struct input_1916509b
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;
};

//wrapper for a 12D smc call
//can return errors as int
//smcArg3 is element ptr in the array of elements of size 0x80
int SceSblSmSchedProxyForKernel_smc_12D_1916509b(int smcArg0, int smcArg1, int smcArg2, input_1916509b* unk3);

struct context_db9fc204
{
   //this is a structure of size 0x814

   int var838; // set to 1
   int command; //var834
   char data[0x800]; //var830
   int packet6_de; //var30
   int size; //var2C
   int var28; //is set to 0
};

//there is more info about this structure in https://wiki.henkaku.xyz/vita/F00D_Commands
//however documentation starts from offset 0x40
//which means it documents context_db9fc204
struct smc_133_input
{
   SceSize size; //0x40 + 0x814
   int service_id; //for example 1000B
   int smcArg0; // or error state
   int unk; // is 0

   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;

   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;

   int unk_30;
   int unk_34;
   int unk_38;
   int unk_3C;

   context_db9fc204 data; //request / response area
};

//wrapper for a 133 smc call
//can return errors as int

//smcArg0 is taken from input structure
//smcArg3 is 0
int SceSblSmSchedProxyForKernel_smc_133_723b382f(smc_133_input* vaddr, int smcArg1_num, smc_133_input* smcArg2_paddr);

struct input_8b84ac2a
{
   int unk_0;
   int unk_4;
   int smcArg0;
};

typedef int (func_8b84ac2a)(input_8b84ac2a* basePtr, int funcArg1, int funcArg2, int unk3, int unk4);

//wrapper for a 138 smc call
//can return errors as int

//smcArg0 is taken from input structure
//smcArg2 is 0
//smcArg3 is 0
int SceSblSmSchedProxyForKernel_smc_138_8b84ac2a(input_8b84ac2a* basePtr, int smcArg1_funcArg1, func_8b84ac2a* func, int funcArg2);

struct input_f35efc1a
{
   int unk_0;
   int unk_4;
   int smcArg0;
};

struct output_f35efc1a
{
   int unk_0;
   int unk_4;
};

//wrapper for a 12E smc call
//can return errors as int

//smcArg0 is taken from input structure
//smcArg1 is element ptr in the array of elements of size 0x80
//smcArg2 is 0
//smcArg3 is 0
int SceSblSmSchedProxyForKernel_smc_12E_f35efc1a(input_f35efc1a* ptr, output_f35efc1a* result);
 
//All other exports of SceSblSmSchedProxy:
/*
SceSblSmschedProxy.._exp_initialize_935cd196
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_check_affinity_initialize_a488d604
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_not_implemented_1dfc8624
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_not_implemented_984ec9d1
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_12D_1916509b
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_12E_f35efc1a
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_12F_27eb92f1
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_130_de4eac3c
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_133_723b382f
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_134_f70c04ec
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_135_3ce17233
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_136_15b0e4df
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_137_973a4a7d
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_138_8b84ac2a
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_139_85eda5fc
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_13B_33a3a1e2
SceSblSmschedProxy.SceSblSmSchedProxyForKernel._exp_smc_13C_7894b6f0
*/