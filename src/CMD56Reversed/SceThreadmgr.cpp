#include <chrono>

#include "SceThreadmgr.h"

//------------------------------------

int SceThreadmgrForDriver_70627f3a(int unk0)
{
   return 0;
}

int SceThreadmgrForDriver_db395782(void* unk0)
{
   return 0;
}

//------------------------------------

int SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(SceUID evid)
{
   return 0;
}

//------------------------------------

int SceThreadmgrForDriver_ksceKernelWaitEventFlag_0c1d3f20(SceUID evid, unsigned int bits, unsigned int wait, unsigned int *outBits, SceUInt *timeout)
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

SceUID SceThreadmgrForDriver_ksceKernelCreateEventFlag_4336baa4(const char *name, int attr, int bits, SceKernelEventFlagOptParam *opt)
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