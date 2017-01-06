#pragma once

int SceCpuForDriver_lock_int_d32ace9e(int *addr);
int SceCpuForDriver_unlock_int_7bb9d5df(int *addr, int prev_state);

int SceCpuForDriver_lock_bf82deb2(int *addr);
int SceCpuForDriver_unlock_d6ed0c46(int *addr);

//atomic set operation
//set new value of 'value' into 'var'
//return previous value of 'var' xor 'cond'
int SceCpuForDriver_atomic_set_xor_cda96e81(int *var, int cond, int value);

/*
//===================================================================================
//Explanations for address translation instructions etc, used in SceSysmem.SceCpuForKernel._exp_9b8173f4
//===================================================================================
Check page 1459 of ARM® Architecture Reference Manual ARMv7-A and ARMv7-R edition

MRC p15, 0, <Rt>, c3, c0, 0 - Read DACR into Rt
                              (ARMv4 and ARMv5) - Read CP15 Data or unified Region Bufferability Register
MCR p15, 0, <Rt>, c3, c0, 0 - Write Rt to DACR
                              (ARMv4 and ARMv5) - Write CP15 Data or unified Region Bufferability Register

Accessing the PAR and the address translation operations
MCR p15, <opc1>, <Rt>, c7, c8, <opc2> ; Address translation operation, as defined by <opc1> and <opc2>
Check page 1498 of ARM® Architecture Reference Manual ARMv7-A and ARMv7-R edition          
                            
MCR p15, 0, <Rt>, c7, c8, 0 - ATS1CPR - Stage 1 Current state PL1 read
MCR p15, 0, <Rt>, c7, c8, 1 - ATS1CPW - Stage 1 Current state PL1 write
MCR p15, 0, <Rt>, c7, c8, 2 - ATS1CUR - Stage 1 Current state unprivileged read
MCR p15, 0, <Rt>, c7, c8, 3 - ATS1CUW - Stage 1 Current state unprivileged write

PAR, Physical Address Register, VMSA
Check page 1664 of ARM® Architecture Reference Manual ARMv7-A and ARMv7-R edition          

MRC p15, 0, <Rt>, c7, c4, 0 - Read PAR[31:0] into Rt

Accessing the PAR and the address translation operations
Check page 1748 of ARM® Architecture Reference Manual ARMv7-A and ARMv7-R edition          

This explains usage of both PAR and address translation

Regarding DACR:
Domain n access permission, where n = 0 to 15. Permitted values are:
0b00 No access. Any access to the domain generates a Domain fault.
0b01 Client. Accesses are checked against the permission bits in the translation tables.
0b10 Reserved, effect is UNPREDICTABLE.
0b11 Manager. Accesses are not checked against the permission bits in the translation tables.

for example if mask 0x55555555 (check SceSysmem.SceCpuForKernel._exp_9b8173f4) is used 
that means that for all 16 memory domains access permissions are set to 'Client'
*/

//This is wrapper function for SceSysmem.SceCpuForKernel._exp_9b8173f4
//which is void* SceSysmem_SceCpuForKernel_exp_ksceKernelGetPaddr_9b8173f4(void* vaddr)
//why?
//Check SceSysmem.SceSysmemForDriver._exp_sceKernelGetPaddr_8d160e65
//this is wrapper for int SceSysmem.SceCpuForKernel._exp_ksceKernelGetPaddr_67343a07(int maskPAR, void *vaddr, void **result)
//which is wrapper for int sub_9E3308(int maskPAR, int setDACR, void *vaddr, void **result, int **num2)
//Their implementation is completely same even using same subroutines

//this function tries to translate virtual address to physical address and returns 1 or 0
int SceCpuForDriver_sceKernelTryGetPaddr_337cbdf3(void *vaddr);

//there is at least one more exported translation function
//int SceSysmem.SceCpuForKernel._exp_sceKernelGetPaddr_2a46e800(void *vaddr, void **result)