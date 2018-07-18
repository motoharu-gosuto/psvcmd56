#pragma once

struct ctx_40A64C
{
   unsigned int state0[8];
   int unk20;
   __int16 unk24;
   __int16 unk26;
   int unk28;
   int unk2C;
   int unk30;
   int unk34;
   int unk38;
   int unk3C;
   int unk40;
   int unk44;
   int unk48;
   int unk4C;
   int unk50;
   int unk54;
   int unk58;
   int unk5C;
   int unk60;
   int unk64;
   int unk68;
   int unk6C;
   char digest2[32];
};

struct control_info_type4_t
{
   int type;
   int size;
   __int64 next;
   char digest1[20];
   char digest2[32];
   char padding[12];
};

struct ctx_40A64C_arg
{
   int unk0;
   int unk4;
   char *filepath;
};

signed int sub_40A64C(int a1, ctx_40A64C_arg *a3, control_info_type4_t *control_info);