#include <cstdint>

#include "SceLibKernel.h"
#include "SceThreadmgr.h"
#include "Utils.h"

int SceLibKernel_sceKernelUnlockLwMutex_120afc8c(SceKernelLwMutexWork *work, int unlockCount)
{
   int v2[2];
   
   *(uint64_t*)v2 = *(uint64_t*)&work->unkC;

   bool isZero = unlockCount == 0;
   bool isLessThanZero = unlockCount < 0;

   if (unlockCount > 0)
   {
      isZero = v2[1] == 0;
      isLessThanZero = v2[1] < 0;
   }

   if(isLessThanZero | isZero)
   {
      if (v2[1] < 0)
         return 0x80028181;
      return 0x8002000F;
   }

   int v5 = (v2[0] & 2) - 2;
   if ((v2[0] & 2) != 2 )
      v5 = unlockCount - 1;

   if (v5)
      return 0x8002000F;

   char* probably_tls;
   MRC(p15, 0, probably_tls, c13, c0, 3);
   probably_tls = probably_tls - 0x800;
   probably_tls = probably_tls + 4;

   if (work->unk0 != *probably_tls)
      return 0x80028186;

   int lockCount_temp = work->lockCount;
   if (lockCount_temp < unlockCount)
      return 0x80028184;

   work->lockCount = lockCount_temp - unlockCount;
   if (lockCount_temp > unlockCount)
      return 0;

   while(1)
   {
      int r12, r3;
      ATOMIC_LOAD(&work->unk0, &work->unk4, &r12, &r3);
      if(r3 != 0)
      {
         work->lockCount = lockCount_temp;
         return SceThreadmgr_sceKernelUnlockLwMutex_2abc41df(work, unlockCount);
      }

      r12 = 0;
      int sync_res = ATOMIC_STORE(&r12, &r12, &work->unk0, &work->unk4);
      if(sync_res == 0)
         break;
   }

   return 0; 
}

int SceLibKernel_sceKernelUnlockLwMutex_91fa6614(SceKernelLwMutexWork *work, int unlockCount)
{
   int v2[2];
    
   *(uint64_t*)v2 = *(uint64_t*)&work->unkC;

   bool isZero = unlockCount == 0;
   bool isLessThanZero = unlockCount < 0;

   if (unlockCount > 0)
   {
      isZero = v2[1] == 0;
      isLessThanZero = v2[1] < 0;
   }

   if (isLessThanZero | isZero)
   {
      return SceThreadmgr_sceKernelUnlockLwMutex_2abc41df(work, unlockCount);
   }

   int v5 = (v2[0] & 2) - 2;
   if ((v2[0] & 2) != 2)
      v5 = unlockCount - 1;

   if (v5)
      return 0x8002000F;

   char* probably_tls;
   MRC(p15, 0, probably_tls, c13, c0, 3);
   probably_tls = probably_tls - 0x800;
   probably_tls = probably_tls + 4;

   if (work->unk0 != *probably_tls)
      return 0x80028186;

   int lockCount_temp = work->lockCount;
   if (lockCount_temp < unlockCount)
      return 0x80028184;

   work->lockCount = lockCount_temp - unlockCount;
   if (lockCount_temp > unlockCount)
      return 0;

   while(1)
   {
      int r12, r3;
      ATOMIC_LOAD(&work->unk0, &work->unk4, &r12, &r3);
      if(r3 != 0)
      {
         work->lockCount = lockCount_temp;
         return SceThreadmgr_sceKernelUnlockLwMutex_2abc41df(work, unlockCount);
      }

      r12 = 0;
      int sync_res = ATOMIC_STORE(&r12, &r12, &work->unk0, &work->unk4);
      if(sync_res == 0)
         break;
   }

   return 0;
}

int SceLibKernel_sceKernelCreateLwCond_48c7eae6(SceKernelLwCondWork *pWork, const char *pName, unsigned int attr, SceKernelLwMutexWork *pLwMutex, const SceKernelLwCondOptParam *pOptParam)
{
   return 0;
}

int SceLibKernel_sceKernelDeleteLwMutex_244e76d2(SceKernelLwMutexWork *work)
{
   return 0;
}

int SceLibKernel_sceKernelDeleteLwCond_721f6cb3(SceKernelLwCondWork *pWork)
{
   return 0;
}

int SceLibKernel_sceKernelCreateLwMutex_da6ec8ef(SceKernelLwMutexWork *pWork, const char *pName, unsigned int attr, int initCount, const SceKernelLwMutexOptParam *pOptParam)
{
   return 0;
}

int SceLibKernel_sceKernelLockLwMutex_46e7be7b(SceKernelLwMutexWork *pWork, int lockCount, unsigned int *pTimeout)
{
   return 0;
}

int SceLibKernel_sceKernelCallModuleExit_15e2a45d(int)
{
   return 0;
}

void* SceLibKernel_sceKernelGetTLSAddr_b295eb61(int key)
{
   return 0;
}