#pragma once

#include <stdint.h>

//basically what this function does it the following
//it checks if TPIDRPRW is initialized (PL1 only Software Thread ID Registers location)
//it returns 0 if TPIDRPRW value is not 0
//otherwise it takes current CPU ID from MPIDR
//then reads from array of 4 elements starting from offset 4000 from the beginning of data segment for SceKernelIntrMgr
//each element is of size 0x80 and CPU ID is used as element index

//TPIDRPRW is typically used to store the pointer to the curcpu struct,
//while TPIDRURO is used to point to the TCB. 

//https://www.daemon-systems.org/man/curcpu.9.html
//The machine-dependent curcpu() macro returns a pointer to a cpu_info structure containing information of the CPU that this thread is running on.

int SceIntrmgrForDriver_getCurrentCpuUnkData_182ee3e3();

#define INTR_CODE_SceSblSmSchedProxySGI 4

#define INTR_CODE_SceSdif0 0xDC
#define INTR_CODE_SceSdif1 0xDD
#define INTR_CODE_SceSdif2 0xDE
#define INTR_CODE_SceSdif3 0xDF

#define INTR_CODE_SceSblSmSchedCry2Arm0 0xC8
#define INTR_CODE_SceSblSmSchedCry2Arm123_1 0xC9
#define INTR_CODE_SceSblSmSchedCry2Arm123_2 0xCA
#define INTR_CODE_SceSblSmSchedCry2Arm123_3 0xCB

typedef int (SceKernelSubIntrHandler)(void *subintr_arg, void *register_arg, unsigned char intr_priority);
typedef int (SceKernelIntrHandler)(int intr_code, void* userCtx);

typedef int (SceKernelIntrOptHandlersCb1)(int intr_code, int subintr_code);
typedef int (SceKernelIntrOptHandlersCb2)(int intr_code, int subintr_code, void *arg);
typedef int (SceKernelIntrOptHandlersCb3)(int intr_code, int subintr_code, SceKernelSubIntrHandler handler, void *register_arg);

typedef struct SceKernelRegisterInterruptOptionsExtended
{
	uint32_t size; // 0x28
	SceKernelIntrOptHandlersCb3* pre_register_subintr_cb;
	SceKernelIntrOptHandlersCb3* post_register_subintr_cb;
	SceKernelIntrOptHandlersCb1* release_subintr_cb;
	SceKernelIntrOptHandlersCb1* fptr0;
	SceKernelIntrOptHandlersCb1* enable_subintr_cb;
	SceKernelIntrOptHandlersCb1* disable_subintr_cb;
	SceKernelIntrOptHandlersCb2* fptr3;
	SceKernelIntrOptHandlersCb1* fptr4;
   SceKernelIntrOptHandlersCb1* fptr5;
} SceKernelRegisterInterruptOptionsExtended; /* size = 0x28 */

typedef struct SceKernelRegisterInterruptOptions
{
	unsigned int size;
	unsigned int num;
	SceKernelRegisterInterruptOptionsExtended *opt2;
	unsigned int flags; /* 0b1 = use sensitivity param */
	unsigned int sensitivity;
} SceKernelRegisterInterruptOptions; /* size = 0x14 */

int SceIntrmgrForDriver_sceKernelRegisterIntrHandlerForDriver_5c1feb29(int intr_code, const char *name, int interrupt_type, SceKernelIntrHandler *handler, void *userCtx, int priority, int targetcpu, SceKernelRegisterInterruptOptions *opt);

int SceIntrmgrForDriver_180435ec(int code);

int SceIntrmgrForDriver_d6009b98(int code);

int SceIntrmgrForDriver_7117e827(int code);