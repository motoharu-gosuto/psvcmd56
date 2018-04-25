#include <string>

#include "SceSysmem.h"
#include "SceSysmemGlobalVariables.h"

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

int sub_9D13A8(int unk0, char* name, int size)
{
   return 0;
}

struct result_9C40F0
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
};

int sub_9C3E3C(int unk0, int unk1, int unk2, result_9C40F0** unk3)
{
   return 0;
}

int sub_9D13B4(int unk0, int unk1)
{
   return 0;
}

char* _009E84D4 = "GUIDGetName";

int sub_9C40F0(unsigned int unk0, int* result)
{
   result_9C40F0* var_20;
   int cookie = var_009EA004;

   int* r8 = result;
   g_008B8144* r2 = _008B8144;
         
   int res_0 = sub_9D13A8(r2->unk_8, _009E84D4, 0x1484);

   int res_1 = sub_9C3E3C(r2->unk_8, unk0, 0x00, &var_20);
   if(res_1 >= 0)
   {
      result_9C40F0* r3 = var_20;
      
      if((r3->unk_8 & 0xF00000) != 0)
      {
         if(unk0 == r3->unk_10)
         {
            (*result) = r3->unk_1C;
         }
         else
         {
            (*result) = 0;
         }
      }
      else
      {
         (*result) = 0;
      }      
   }

   sub_9D13B4(r2->unk_8, res_0);

   if(cookie == var_009EA004)
      return 0;
   else
      return STACK_CHECK_FAIL;
}

int SceSysmemForDriver_udiv_e655852f(unsigned int numerator_div2)
{
   int var_10;
   int cookie = var_009EA004;

   int res_0 = sub_9C40F0(numerator_div2, &var_10);
   
   int result = (res_0 < 0) ? 0 : var_10;

   if(cookie == var_009EA004)
      return result;
   else
      return STACK_CHECK_FAIL;
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

void* SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceUID uid, SceSize size, ctx_49D4DD9B* unk2)
{
   return 0;
}

void* SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(SceUID uid, SceSize size, ctx_49D4DD9B* unk2)
{
   return SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(uid, size, unk2);
}