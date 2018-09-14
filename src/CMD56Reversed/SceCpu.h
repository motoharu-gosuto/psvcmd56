#pragma once

int SceCpuForDriver_sceKernelCpuLockSuspendIntrStoreLRForDriver_d32ace9e(int *addr);
int SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(int *addr, int prev_state);

int SceCpuForDriver_lock_bf82deb2(int *addr);
int SceCpuForDriver_sceKernelCpuUnlockStoreLRForDriver_d6ed0c46(int *addr);

//atomic set operation
//set new value of 'value' into 'var'
//return previous value of 'var' xor 'cond'
template<typename T>
T SceCpuForDriver_atomic_set_xor_cda96e81(T* var, T cond, T value)
{
   //TODO: This is partial implementation omitting all sync primitives

   T r3 = *var;
   int teq = (int)r3 ^ (int)cond;
   if(teq == 0)
      *var = value;

   return (T)teq;
}

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

//this function tries to translate virtual address to physical address and returns 1 on failure or 0 on success
int SceCpuForDriver_sceKernelTryGetPaddr_337cbdf3(void *vaddr);

//there is at least one more exported translation function
//int SceSysmem.SceCpuForKernel._exp_sceKernelGetPaddr_2a46e800(void *vaddr, void **result)

/*
CP15 c7, Cache and branch predictor operations
For ARM-7 Check page 1475 of ARM® Architecture Reference Manual ARMv7-A and ARMv7-R edition

Check implementation of int SceSysmem.SceCpuForKernel._exp_sceKernelCpuDcacheFlush_6ba2e51c(void *ptr, size_t len)
MCR p15, 0, R0, c7, c14, 1 ; DCCIMVAC, Clean and invalidate data* cache line by MVA to PoC

Then compare it to implementation of SceSysmem.SceCpuForKernel._exp_583f30d1
MCR p15, 0, R0, c7, c6, 1 ; DCIMVAC, Invalidate data* cache line by MVA to PoC

Implementations are nearly the same (except calling clean and invalidate or invalidate) so we can name this function as 
int SceSysmem.SceCpuForKernel._exp_sceKernelCpuDcacheInvalidate_583f30d1(void *ptr, size_t len)
*/

//now about NACR
//MRC p15, 0, <Rt>, c1, c1, 2 ; Read NSACR into Rt
//MCR p15, 0, <Rt>, c1, c1, 2 ; Write Rt to NSACR

//now about DMA
//generic information is at:
//http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0211h/Bhcjghif.html

//some examples to be able to search easily:

//MRC p15, 0, <Rd>, c11, c0, 0  ; Read DMA Identification and Status Register present
//MRC p15, 0, <Rd>, c11, c1, 0  ; Read DMA User Accessibility Register
//MRC p15, 0, <Rd>, c11, c2, 0  ; Read DMA Channel Number Register
//MCR p15, 0, <Rd>, c11, c3, 0  ; Stop DMA Enable Register
//MRC p15, 0, <Rd>, c11, c4, 0  ; Read DMA Control Register
//MRC p15, 0, <Rd>, c11, c5, 0  ; Read DMA Internal Start Address Register
//MRC p15, 0, <Rd>, c11, c6, 0  ; Read DMA External Start Address Register
//MRC p15, 0, <Rd>, c11, c7, 0  ; Read DMA Internal End Address Register
//MRC p15, 0, <Rd>, c11, c8, 0  ; Read DMA Channel Status Register
//MRC p15, 0, <Rd>, c11, c15, 0 ; Read DMA Context ID Register

//continue DMA
//There is a function
//int SceSysmem.SceCpuForDriver._exp_sceKernelCpuDcacheAndL2AndDMAFlush_364e68a4(void *ptr, size_t len)
//which is a wrapper to:
//int proc_sceKernelCpuDcacheAndL2AndDMAFlush_9E2D04(void *ptr, size_t len, int tryTranslate)
//there is another function which we can name:
//int SceSysmem.SceCpuForDriver._exp_sceKernelCpuDcacheAndL2AndDMAFlush_e551f99b(void *ptr, size_t len)
//it only differs by internal value of tryTranslate that triggers sceKernelTryGetPaddr

//Now we can compare function int proc_sceKernelCpuDcacheAndL2AndDMAFlush_9E2D04(void *ptr, size_t len, int tryTranslate)
//to another function int sub_9E2E14(void *ptr, size_t len, int tryTranslate)
//using our knowledge about int SceSysmem.SceCpuForKernel._exp_sceKernelCpuDcacheInvalidate_583f30d1(void *ptr, size_t len)
//this function ALSO has 2 wrappers with SAME argument values and implementation is completely the same (except that it looks like L2 cache is not Invalidated?)
//so we can name 2 more functions:
//int SceSysmem.SceCpuForDriver._exp_sceKernelCpuDcacheAndDMAInvalidate_8b4c26df(void *ptr, size_t len)
//int SceSysmem.SceCpuForDriver._exp_sceKernelCpuDcacheAndDMAInvalidate_02796361(void *ptr, size_t len)

//now lets check this function:
//int SceSysmem.SceCpuForDriver._exp_sceKernelCpuDcacheAndL2Flush_9cb9f0ce(void *ptr, size_t)
//it is a wrapper for:
//int proc_sceKernelCpuDcacheAndL2Flush_9E2C50(void *ptr, size_t len, int tryTranslate)
//based on previous knowledge we already know that there is a second wrapper:
//int SceSysmem.SceCpuForDriver._exp_sceKernelCpuDcacheAndL2Flush_103872a5(void *ptr, size_t)

//based on previous knowledge we locate inside function int proc_sceKernelCpuDcacheAndL2Flush_9E2C50(void *ptr, size_t len, int tryTranslate)
//another function that is the same as other cache invalidate functions that use MCR operations
//we name it int SceSysmem.SceCpuForKernel._exp_sceKernelCpuDcacheClean_c5c1ee4e(void *ptr, size_t len)

//looking near to clean/flush functions found this function:
//int SceSysmem_SceCpuForKernel_exp_sceKernelCpuIcacheClean_f4c7f578(void *ptr, size_t len)
//that is used by:
//int SceSysmem.SceCpuForKernel._exp_sceKernelCpuIcacheAndL2Flush_19f17bd0(void *ptr, size_t len)

//based on previous knowledge I would assume that 
//proc_sceKernelCpuDMAFlush_9E2C18()
//because it is used by DMA flush functions and contains MCR/MRC DMA related operations 

//which means we can name this function as well:
//void SceSysmem.SceCpuForKernel._exp_sceKernelCpuDMAFlush_d0d85ff8()

//if we search by different variations of registers -
//Check page 1475 of ARM® Architecture Reference Manual ARMv7-A and ARMv7-R edition
//we can find some simple functions with single MCR command like:

//void SceSysmem.SceCpuForKernel._exp_DCCMVAC_f7159b55(void *ptr)
//void SceSysmem.SceCpuForKernel._exp_DCCIMVAC_c8e8c9e9(void *ptr)
//void SceSysmem.SceCpuForKernel._exp_DCIMVAC_470eae1e(void *ptr)
//void SceSysmem.SceCpuForKernel._exp_ICIALLU_aee0b489(void)
//void SceSysmem.SceCpuForKernel._exp_BPIALL_4c4c7d6b(void)
//void SceSysmem.SceCpuForKernel._exp_ICIALLUIS_264da250(void)
//void SceSysmem.SceCpuForKernel._exp_BPIALLIS_1bb2bb8d(void)

//other functions can also be named:
//int SceSysmem.SceCpuForKernel._exp_sceKernelCpuReadCONTEXTIDR_5b6b3274(void)
//int SceSysmem.SceCpuForKernel._exp_sceKernelCpuCombineACTLRWith_1806_04008cf7(void)
//int SceSysmem.SceCpu._exp_sceKernelReadMPIDRAffinityLevel0_2704cfee(void)
//int SceSysmem.SceCpuForDriver._exp_sceKernelReadMPIDRAffinityLevel0_5e4d5de1(void)

int SceCpuForDriver_sceKernelCpuGetCpuIdForDriver_5e4d5de1();

int SceCpuForDriver_sceKernelCpuDcacheAndL2CleanMVACRange_1ForDriver_103872a5(void *ptr, size_t size);

int SceCpuForDriver_sceKernelCpuDcacheAndL2InvalidateMVACRange_1ForDriver_02796361(void *ptr, size_t len);