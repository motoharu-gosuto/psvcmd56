#pragma once

#include "SceSysmem.h"

typedef int dmac_id;

//packs result_c8672a3d* to number
#define SCE_DMAC_PACK_ID(ptr) ((dmac_id)(((int)ptr >> 1) | 0x01))

#define SCE_DMAC_UNPACK_ID(id) ((result_c8672a3d*)((id >> 0x01) << 0x02))

#define SCE_DMAC_GXOR(g) (((int)&g) | 0x01)

#define SCE_DMAC_BITMASK1 0x07FC0000
#define SCE_DMAC_BITMASK2 0x07F80000

//paired start function
dmac_id SceDmacmgrForDriver_7cd5088a(const char* efName);

//paired exit function
int SceDmacmgrForDriver_adff1186(dmac_id id);

//---------------------------------------------------------------------------

int SceDmacmgrForDriver_fce4171a(dmac_id unk0, int unk1, int unk2);

struct locals_B99674
{
   void* source_vaddr_0;
   void* source_paddr_4;
   int   size_8;
   int   flag_C;
   int   unk_10; //var_88 - used ?
   int   unk_14; // = arg_C
   input_167079fc*   unk_18; //var_80 - used
   int   unk_1C; // = arg_4 - looks like this is a beginning of structure input_167079fc
   void* paddr_20;
   int   unk_24; // = arg_10
   int   unk_28; //var_70 - used ?
   
   char unk_2C[0x40];
};

#define MODE_01a599e0_0 0x00
#define MODE_01a599e0_1 0x01
#define MODE_01a599e0_10 0x10
#define MODE_01a599e0_11 0x11
#define MODE_01a599e0_100 0x100

int SceDmacmgrForDriver_01a599e0(dmac_id id, const locals_B99674* data, int creationMode);

int SceDmacmgrForDriver_543f54cf(dmac_id id);

#define MODE_397a917c_1 0x01
#define MODE_397a917c_2 0x02
#define MODE_397a917c_3 0x03

int SceDmacmgrForDriver_397a917c(dmac_id id, int mode, int unk2, void** unk3);

int SceDmacmgrForDriver_167079fc(dmac_id id, const local_01a599e0* data, input_167079fc* ptr, int creationMode);