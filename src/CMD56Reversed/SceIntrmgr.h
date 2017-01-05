#pragma once

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

int SceIntrmgrForDriver_182ee3e3();