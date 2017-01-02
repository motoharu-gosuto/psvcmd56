#include <chrono>

#include "SceThreadmgr.h"

int SceThreadmgrForDriver_0c1d3f20(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

//assume - some thread init
int SceThreadmgrForDriver_3c8b55a9(int un0, int unk1, int unk2)
{
   return 0;
}

int SceThreadmgrForDriver_4336baa4(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceThreadmgrForDriver_70627f3a()
{
   return 0;
}

int SceThreadmgrForDriver_71ecb352(int unk0)
{
   return 0;
}

//assume - some thread deinit
int SceThreadmgrForDriver_d270498b(int unk0, int unk1)
{
   return 0;
}

int SceThreadmgrForDriver_db395782()
{
   return 0;
}

int SceThreadmgrForDriver_76c6555b(int unk0, int unk1, int unk2, int unk3)
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