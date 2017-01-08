#pragma once

typedef int dmac_id;

//packs result_c8672a3d* to number
#define SCE_DMAC_PACK_ID(ptr) ((dmac_id)(((int)ptr >> 1) | 0x01))

#define SCE_DMAC_UNPACK_ID(id) ((result_c8672a3d*)((id >> 0x01) << 0x02))

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
   int*   unk_18; //var_80 - used ?
   int   unk_1C; // = arg_4
   void* paddr_20;
   int   unk_24; // = arg_10
   int   unk_28; //var_70 - used ?
   
   char unk_2C[0x40];
};

//size is 0x20
struct local_01a599e0
{
   void* source_vaddr_44; // used
   void* source_paddr_40; // used
   int size_3C; // used
   int flag_38; // used
   int var_34; // used - arg_4
   void* paddr_30; // used
   int var_2C; // used
   int var_28; // used
};

int SceDmacmgrForDriver_01a599e0(dmac_id id, locals_B99674* data, int unk2);

int SceDmacmgrForDriver_543f54cf(dmac_id id);

int SceDmacmgrForDriver_397a917c(dmac_id id, int num, int unk2, int unk3);

int SceDmacmgrForDriver_167079fc(dmac_id id, void* r1, int r2, int r3);