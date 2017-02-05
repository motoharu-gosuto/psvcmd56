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


typedef int(intr_callback)(int code, int unk);

typedef struct reg_intr_opt2
{
   uint32_t size; //0x28
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;
   intr_callback* fptr0; // function pointer
   intr_callback* fptr1; // function pointer
   intr_callback* fptr2; // function pointer
   uint32_t unk_1C;
   uint32_t unk_20;
   uint32_t unk_24;
}reg_intr_opt2;

typedef struct reg_intr_opt
{
   uint32_t size; //0x14
   uint32_t num;
   reg_intr_opt2* opt2;
   uint32_t unk_C;
   uint32_t unk_10;
}reg_intr_opt;

typedef int (intr_callback_func)(int unk, void* userCtx);

int SceIntrmgrForDriver_register_interrupt_5c1feb29(int code, const char *name, int interrupt_type, intr_callback_func* func, void* userCtx, int priority, int targetcpu, reg_intr_opt* opt);