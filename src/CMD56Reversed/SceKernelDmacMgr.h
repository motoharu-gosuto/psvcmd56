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

int SceDmacmgrForDriver_fce4171a(int unk0, int unk1, int unk2);

struct locals_B99674
{
   void* unk_0;
   void* unk_4;
   int   unk_8;
   int   unk_C;
   int   unk_10; //var_88 - used ?
   int   unk_14;
   int   unk_18; //var_80 - used ? - is this void* ?
   int   unk_1C;
   void* unk_20;
   int   unk_24;
   int   unk_28; //var_70 - used ?
   
   char unk_2C[0x40];
};

struct r9_01a599e0
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;

   int unk_20;
   int unk_24;
   void* unk_28;
   int unk_2C;

   void* unk_30;
   int unk_34;

   short unk_38;
   short unk_3A;
};

//size is 0x20
struct local_01a599e0
{
   int var_44; // used
   int var_40; // used
   int var_3C; // used
   int var_38; // used
   int var_34; // used
   int var_30; // used
   int var_2C; // used
   int var_28; // used
};

int SceDmacmgrForDriver_01a599e0(int id, locals_B99674* unk1, int unk2);

int SceDmacmgrForDriver_543f54cf(int unk0);

int SceDmacmgrForDriver_397a917c(int id, int num, int unk2, int unk3);

int SceDmacmgrForDriver_167079fc(int id, void* r1, int r2, int r3);