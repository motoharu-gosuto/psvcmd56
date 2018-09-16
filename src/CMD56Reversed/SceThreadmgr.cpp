#include <chrono>

#include "SceThreadmgr.h"

//------------------------------------

int SceThreadmgrForDriver_af8e1266(uint32_t* unk, char* name, int num0, int num1)
{
   return 0;
}

int SceThreadmgrForDriver_11fe84a1(uint32_t* unk)
{
   return 0;
}

int SceThreadmgrForDriver_70627f3a(int unk0)
{
   return 0;
}

int SceThreadmgrForDriver_db395782(void* unk0)
{
   return 0;
}

//------------------------------------

int SceThreadmgrForDriver_sceKernelDeleteEventFlagForDriver_71ecb352(SceUID evid)
{
   return 0;
}

//------------------------------------

int SceThreadmgrForDriver_sceKernelWaitEventFlagForDriver_0c1d3f20(SceUID evid, unsigned int bits, unsigned int wait, unsigned int *outBits, SceUInt *timeout)
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelPollEventFlag_76c6555b(SceUID evid, unsigned int bits, unsigned int wait, unsigned int *outBits)
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelWaitSema_3c8b55a9(SceUID semaid, int signal, SceUInt *timeout)
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelSignalSema_d270498b(SceUID semaid, int signal)
{
   return 0;
}

SceUID SceThreadmgrForDriver_sceKernelCreateEventFlagForDriver_4336baa4(const char *name, int attr, int bits, SceKernelEventFlagOptParam *opt)
{
   return 0;
}

int SceThreadmgrForDriver_sceKernelDelayThread_4b675d05(SceUInt delay)
{
   return 0;
}

//this is user space signature for the function
//SceInt64 sceKernelGetSystemTimeWide(void);
//I would assume that it returns the same value in kernel as well

//TODO: this is just an imitation - I do not know what time format is used in vita (though I assume it is this format)

sce_time SceThreadmgrForDriver_sceKernelGetSystemTimeWideForDriver_f4ee4fa9()
{
   typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> time_stamp;
   
   time_stamp timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
   std::chrono::duration<int64_t, std::micro> duration = timestamp.time_since_epoch();
   int64_t count = duration.count();
   
   sce_time scetime;
   scetime.value = (uint64_t)count;
         
   return scetime;
}

SceUID SceThreadmgrForDriver_sceKernelCreateMutexForDriver_fbaa026e(const char *name, SceUInt attr, int initCount, SceKernelMutexOptParam *option)
{
   return 0;
}

SceUID SceThreadmgrForDriver_sceKernelCreateCondForDriver_db6cd34a(const char *name, SceUInt attr, SceUID mutexId, const SceKernelCondOptParam *option)
{
   return 0;
}

int SceThreadmgrForDriver_sceKernelDeleteMutexForDriver_0a912340(SceUID uid)
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelInitializeFastMutex_af8e1266(void* mutex, const char* name, int unk0, int unk1)
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelSetEventFlag_d4780c3e(SceUID evid, unsigned int bits)
{
   return 0;
}

//this most likely returns current thread SceUID
int SceThreadmgrForDriver_sceKernelGetThreadIdForDriver_59d06540()
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceUID mutexid, int lockCount, unsigned int *timeout)
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceUID mutexid, int unlockCount)
{
   return 0;
}

SceUID SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a()
{
   return 0;
}

int SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(int value)
{
   return 0;
}

int SceThreadmgr_sceKernelUnlockLwMutex_2abc41df(SceKernelLwMutexWork *work, int unlockCount)
{
   return 0;
}

int SceThreadmgrCoredumpTime_sceKernelExitThread_0c8a38e1(int status)
{
   return 0;
}

int SceThreadmgrForDriver_sceKernelTryLockMutexForDriver_270993a6(SceUID mutexid, int lockCount)
{
   return 0;
}