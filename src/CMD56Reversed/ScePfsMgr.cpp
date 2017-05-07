#include "SceIofilemgr.h"

int sub_2199144(vfs_node **node, void *result_pair)
{
   return 0;
}

int read_wrapper_2199064(vfs_node **unk0, char *buffer, int size, int unk3, int num0, int num1, int *readBytes)
{
   return 0;
}

int sub_21A0E3C()
{
}

int proc_copy_14_bytes_219DE1C()
{
}

int proc_crypto_stuff_219DE7C()
{
}

int proc_verify_14_bytes_219DE44()
{
}

int sub_21A0E28()
{
}

int sub_21A6A10()
{
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
   var_2A0= -0x2A0         ; args to functions
   readBytes= -0x298       ; read bytes ptr
   var_28C= -0x28C         ; read bytes value
   result= -0x288          ; result pair
   var_284= -0x284
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
   int r1 = &result;

   var_2C = r3;

   int r0 = sub_2199144(r0, r1); //call vfs_node_func15 (sceIoGetstatForDriver) - get some string from node field 70

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   int r4 = [SP,#0x18]; //where on stack?
   int r5 = [SP,#0x1C]; //where on stack?

   int r3 = r4 | r5; //orrs

   if(true) //beq
      return loc_21A292E(0x80140904, var_2C);

   int r11 = &destination + 0x3F;
   int r2 = 0x200;
   int r11 = r11 & (~0x3F); //why ?
   int r3 = 0;
   int r4 = &var_28C;
   int r0 = r6[0x14];
   int r1 = r11;

   [SP + 0] = r2; //where on stack?
   [SP + 4] = r3; //where on stack?
   readBytes = r4;

   int r2 = 0x200;

   int r0 = read_wrapper_2199064(r0, r1, r2, r3, ?, ?, ?);

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

   //VMOV.I32        D16, #0x80

   int r1 = r11;
   
   int r0 = r6[0x14];

   readBytes = r4;

   //VSTR            D16, [SP,#0x2A0+var_2A0]

   int r0 = read_wrapper_2199064(r0, r1, r2, r3, ?, ?, ?);

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

   short r3 = r8[0x0];
   short r4 = r8[0x4];
   short r0 = r8[0x8];
   short r2 = r8[0xC];
   
   int r1 = r6[0x18];
   
   r6[0x0] = r3;
   r6[0x4] = r4;
   r6[0x8] = r0;
   r6[0xC] = r2;

   short r3 = r8[0x10];
   short r5 = r6[0x80];

   r6[0x10] = r3;

   int r3 = r1[0x4];

   if(r5 != r3)
      return loc_21A292E(0x80140909, var_2C);

   int r3 = r6[0x78];
   int r4 = r6 + 20;
   
   int r2 = r6[0x14];
   
   int r0 = r4;
   int r8 = r6 + 0xD0;

   [var_2A0 + 4] = r9;

   int r3 = r3 - 1;

   if(r3 <= 1) //LS ???
      r5 = 0x160;

   var_2A0 = r5;

   int r5 = r6 + 0xBC;

   sub_21A0E3C(?);

   int r2 = 0x100;
   int r1 = r8;
   int r0 = &destination;

   memcpy(r0, r1, r2,);

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

   [SP + 0] = r10; //where on stack?
   [SP + 4] = r11; //where on stack?

   sub_21A0E28(?);

   int r2 = r4;

   int r4 = r6[0x78];
   int r3 = r6[0x88];

   int r0 = r6[0x40];
   int r1 = r6;

   var_2A0 = r4;

   sub_21A6A10(?); //some vfs node functions inside

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

   r6[0xBC] = (short)r0;

   int r0 = *r4;

   r5[0x4] = r1;
   r5[0x8] = r2;
   
   r5[0x10] = r0;
   r5[0xC] = r3;
   
   return loc_21A292E(r9, var_2C); //r9 is 0 - optimization
}