#pragma once

//TODO: looks like this function returns id
//this can be easily checked
//need to look at other known paired functions and see how id is formed there
//looks like there is a special algorithm to convert pointer to id ?

//paired start function
int SceDmacmgrForDriver_7cd5088a(const char* efName);

int SceDmacmgrForDriver_fce4171a(int unk0, int unk1, int unk2);

/*
struct input_01a599e0
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   void* unk_18;
   int unk_1C;

   int unk_20;
};
*/

struct locals_B99674
{
   void* unk_0;
   void* unk_4;
   int   unk_8;
   int   unk_C;
   int   unk_10; //var_88 - used ?
   int   unk_14;
   int   unk_18; //var_80 - used ?
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

//paired exit function
int SceDmacmgrForDriver_adff1186(int id);

int SceDmacmgrForDriver_167079fc(int id, void* r1, int r2, int r3);