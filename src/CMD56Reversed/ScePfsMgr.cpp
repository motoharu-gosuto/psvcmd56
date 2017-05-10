#include "SceIofilemgr.h"

int sub_2199144(vfs_node **node, void *result_pair)
{
   return 0;
}

int read_wrapper_2199064(vfs_node **unk0, char *buffer, int size, int unk3, int num0, int num1, int *readBytes)
{
   return 0;
}

int sub_21A0E3C(int unk0, int unk1, int unk2)
{
   return 0;
}

int proc_copy_14_bytes_219DE1C(int unk0, int unk1)
{
   return 0;
}

int proc_crypto_stuff_219DE7C(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int proc_verify_14_bytes_219DE44(int unk0, int unk1)
{
   return 0;
}

int sub_21A0E28(int unk0, int unk1, int unk2, int unk3, int arg_0, int arg_4)
{
   return 0;
}

int sub_21A6A10(int unk0, int unk1, int unk2, int unk3, int arg_0)
{
   return 0;
}

//----------------

int loc_21A292E(int r9, int var_2C)
{
   if(var_2C == var_009EA004)
      return r9;
   else
      return STACK_CHECK_FAIL;
}

int loc_21A292C(int r0, int var_2C)
{
   return loc_21A292E(r0, var_2C);
}

int proc_SCENGPFS_21A27B8(void *unk0, vfs_node **unk1, void *unk2)
{
   int r0 = unk0;
   int r1 = unk1;
   int r2 = unk2;

   /*
   arg_0_4= -0x2A0         ; args to functions : 0x0, 0x04
   readBytes= -0x298       ; read bytes ptr : 0x8
   var_294= -0x294         ; 0xC
   var_290= -0x290         ; 0x10
   var_28C= -0x28C         ; read bytes value : 0x14
   result_p1= -0x288       ; result pair : 0x18
   result_p2= -0x284       ; 0x1C
   unk0= -0x280            ; 0x14 bytes
   destination= -0x26C     ; size is 0x100
   var_16C= -0x16C         ; 0x140 bytes
   var_2C= -0x2C           ; cookie
   */

   int r7 = &var_009EA004;
   int r6 = r0;
   int r0 = r1;
   int r3 = *r7;
   int r8 = r2;

   r6[0x14] = r1;
   int r1 = &result_p1;

   var_2C = r3;

   int r0 = sub_2199144(r0, r1); //call vfs_node_func15 (sceIoGetstatForDriver) - get some string from node field 70

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   int r4 = result_p1;
   int r5 = result_p2;

   int r3 = r4 | r5; //orrs

   if(true) //beq
      return loc_21A292E(0x80140904, var_2C);

   int r11 = &destination + 0x3F;
   int r2 = 0x200;
   int r11 = r11 & (~0x3F); //why ?
   int r3 = 0;
   int r4 = &var_28C;
   int r0 = r6[0x14]; //vfs_node
   int r1 = r11;

   arg_0 = r2;
   arg_4 = r3;
   readBytes = r4; //arg_8

   int r2 = 0x200;

   int r0 = read_wrapper_2199064(r0, r1, r2, r3, arg_0, arg_4, readBytes);

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   int r2 = *r4;
   
   if(r2 != 0x200)
      return loc_21A292E(0x8014090A, var_2C);
    
   int r0 = r11[0x60];
   r6[0x68] = r0;
   int r9 = r6[0x68];

   if(r9 != 0)
      return loc_21A292E(0x8014090A, var_2C);

   int r1 = r11;
   
   int r0 = r6[0x14];

   readBytes = r4;

   arg_0 = 0x80; //??
   arg_4 = 0x00; //??

   int r0 = read_wrapper_2199064(r0, r1, r2, r3, arg_0, arg_4, readBytes);

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   int r3 = *r4;

   if(r3 != 0x200)
      return loc_21A292E(0x8014090A, var_2C);

   int r10 = r6 + 0x70;
   int r2 = 0x160;
   int r1 = r11;
   int r0 = r10;

   memcpy(r0, r1, r2);

   char* r3 = "SCENGPFS";

   int r2 = r3[0];
   int r3 = r3[4];

   int r4 = r6[0x70];
   int r5 = r6[0x74];

   if(r5 != r3)
      return loc_21A292E(0x8014090A, var_2C);
   
   if(r4 != r2)
      return loc_21A292E(0x8014090A, var_2C);

   int r3 = r8[0x0];
   int r4 = r8[0x4];
   int r0 = r8[0x8];
   int r2 = r8[0xC];
   
   int r1 = r6[0x18];
   
   r6[0x0] = r3;
   r6[0x4] = r4;
   r6[0x8] = r0;
   r6[0xC] = r2;

   int r3 = r8[0x10];
   int r5 = r6[0x80];

   r6[0x10] = r3;

   int r3 = r1[0x4];

   if(r5 != r3)
      return loc_21A292E(0x80140909, var_2C);

   int r3 = r6[0x78];
   int r4 = r6 + 20;
   
   int r2 = r6[0x14];
   
   int r0 = r4;
   int r8 = r6 + 0xD0;

   arg_4 = r9;

   int r3 = r3 - 1;

   if(r3 <= 1)
      r5 = 0x160;

   arg_0 = r5;

   int r5 = r6 + 0xBC;

   sub_21A0E3C(r0, r1, r2);

   int r2 = 0x100;
   int r1 = r8;
   int r0 = &destination;

   memcpy(r0, r1, r2);

   int r1 = r5;
   int r0 = &unk0;

   proc_copy_14_bytes_219DE1C(r0, r1);

   int r1 = r9;
   int r2 = 0x14;
   int r0 = r5;

   memset(r0, r1, r2);

   int r1 = r9;
   int r2 = 0x100;
   int r0 = r8;

   memset(r0, r1, r2);

   int r1 = r6;
   int r0 = r5;
   int r2 = r10;

   int r3 = 0x160;

   proc_crypto_stuff_219DE7C(r0, r1, r2, r3);

   int r0 = &unk0;
   int r1 = r5;
   int r0 = proc_verify_14_bytes_219DE44(r0, r1);

   if(r0 == 0)
      return loc_21A292E(0x80140902, var_2C);

   int r10 = r6[0x98];
   int r11 = r6[0x9C];

   int r0 = r4;

   int r2 = r6[0x90];
   int r3 = r6[0x94];

   arg_0 = r10;
   arg_4 = r11;

   sub_21A0E28(r0, r1, r2, r3, arg_0, arg_4);

   int r2 = r4;

   int r4 = r6[0x78];
   int r3 = r6[0x88];

   int r0 = r6[0x40];
   int r1 = r6;

   arg_0 = r4;

   sub_21A6A10(r0, r1, r2, r3, arg_0); //some vfs node functions inside

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   int r0 = r6 + 0xA8;
   int r1 = r6 + 0x4C;
   int r0 = proc_verify_14_bytes_219DE44(r0, r1);

   if(r0 == 0)
      return loc_21A292E(0x80140902, var_2C);

   int r1 = &destination;
   int r2 = 0x100;
   int r0 = r8;
   int r4 = &unk0;

   memcpy(r0, r1, r2);

   int r0 = r4[0x0];
   int r1 = r4[0x4];
   int r2 = r4[0x8];
   int r3 = r4[0xC];

   r4 + r4 + 0x10;

   r6[0xBC] = r0;

   int r0 = *r4;

   r5[0x4] = r1;
   r5[0x8] = r2;
   
   r5[0x10] = r0;
   r5[0xC] = r3;
   
   return loc_21A292E(r9, var_2C); //r9 is 0 - optimization
}