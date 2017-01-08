#include <string>

#include "SceSysmem.h"

result_c8672a3d* SceSysmemForKernel_functor_c8672a3d(input1_c8672a3d* ctx)
{
   //TODO: this is just an immitation - need to figure out how this is really initialized
   result_c8672a3d* var = new result_c8672a3d();
   memset(var, 0, sizeof(result_c8672a3d)); 
   return var;
}

int SceSysmemForKernel_functor_571660aa(input1_c8672a3d* ctx, result_c8672a3d* arg_1)
{
   //TODO: this is just an immitation - need to figure out how this is really initialized
   delete arg_1;
   return 0;
}

int SceSysmemForDriver_udiv_e655852f(unsigned int numerator_div2)
{
   return 0;
}

//--------------------------------

SceUID SceSysmemForDriver_ksceKernelAllocMemBlock_c94850c9(const char *name, SceKernelMemBlockType type, int size, SceKernelAllocMemBlockKernelOpt *optp)
{
   return 0;
}

int SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(SceUID uid)
{
   return 0;
}

int SceSysmemForDriver_ksceKernelGetMemBlockBase_a841edda(SceUID uid, void **basep)
{
   return 0;
}

int SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(addr_pair* input, paddr_list_req *req)
{
   return 0;
}

int SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(void *vaddr, void **result)
{
   //wrapper for SceSysmem.SceCpuForKernel._exp_67343a07 - very interesting
   return 0;
}

void* SceSysmemForDriver_ksceKernelMemPoolAlloc_7b4cb60a(SceUID pool, SceSize size)
{
   return 0;
}

void SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceUID pool, void *ptr)
{
}