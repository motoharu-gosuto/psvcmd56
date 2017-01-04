#pragma once

#include <stdint.h>

//TODO: this type is weid just as the code that uses it
//this needs to be fixed (however this code is not required, just good to know timing restrictions)

struct sce_time
{
   union
   {
      struct
      {
         uint32_t v0;
         uint32_t v1;
      };
      uint64_t value;
   };
};

typedef unsigned int SceUInt;

int SceThreadmgrForDriver_0c1d3f20(int unk0, int num1, int num2, int unk3);
int SceThreadmgrForDriver_3c8b55a9(int un0, int unk1, int unk2);
int SceThreadmgrForDriver_4336baa4(int unk0, int unk1, int unk2, int unk3);
int SceThreadmgrForDriver_70627f3a();
int SceThreadmgrForDriver_71ecb352(int unk0);
int SceThreadmgrForDriver_d270498b(int unk0, int unk1);
int SceThreadmgrForDriver_db395782();
int SceThreadmgrForDriver_76c6555b(int unk0, int unk1, int unk2, int unk3);
int SceThreadmgrForDriver_sceKernelDelayThread_4b675d05(SceUInt delay);
sce_time SceThreadmgrForDriver_sceKernelGetSystemTimeWideForDriver_f4ee4fa9();