#include <map>
#include <stdint.h>

#include "SceIofilemgr.h"

int sub_2199144(vfs_node **node, std::pair<uint32_t, uint32_t>* result_pair)
{
   return 0;
}

int read_wrapper_2199064(vfs_node **unk0, char *buffer, int size, int unk3, int num0, int num1, uint32_t *readBytes)
{
   return 0;
}

int sub_21A0E3C(int unk0, int unk1, int unk2, int unk3, int arg_0, int arg_4)
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

typedef struct ctx_21A27B8
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   uint32_t unk_10;
   vfs_node ** unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;


   

}ctx_21A27B8;

int proc_SCENGPFS_21A27B8(ctx_21A27B8* argument0, vfs_node **argument1, void *argument2)
{
   //var_294= -0x294         
   //var_290= -0x290
   uint32_t var_28C; //read bytes value
   std::pair<uint32_t, uint32_t> result_p; //size is 0x8 bytes in total
   char unk0[0x14]; //0x14 bytes
   char destination[0x100]; //size is 0x100
   char var_16C[0x140]; // 0x140 bytes
   int var_2C = var_009EA004; //cookie

   argument0->unk_14 = argument1;

   int result0 = sub_2199144(argument1, &result_p); //call vfs_node_func15 (sceIoGetstatForDriver) - get some string from node field 70

   if(result0 != 0)
      return loc_21A292C(result0, var_2C);

   if((result_p.first | result_p.second) == 0)
      return loc_21A292E(0x80140904, var_2C);

   char* r11 = (destination + 0x3F) & (~0x3F); //why ?
   
   int result1 = read_wrapper_2199064(argument0->unk_14, r11, 0x200, 0, 0x200, 0, &var_28C);

   if(result1 != 0)
      return loc_21A292C(result1, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);
    
   int some_value = r11[0x60];
   argument0[0x68] = some_value;

   if(some_value != 0)
      return loc_21A292E(0x8014090A, var_2C);

   int result2 = read_wrapper_2199064(argument0->unk_14, r11, 0x200, 0, 0x80, 0x00, &var_28C); //not sure about 0x80 0x00

   if(result2 != 0)
      return loc_21A292C(result2, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(((argument0 + 0x70)), r11, 0x160);

   if(strncmp("SCENGPFS", argument0[0x70], 8) != 0)
      return loc_21A292E(0x8014090A, var_2C);

   argument0[0x0] = argument2[0x0];
   argument0[0x4] = argument2[0x4];
   argument0[0x8] = argument2[0x8];
   argument0[0xC] = argument2[0xC];
   argument0[0x10] = argument2[0x10];

   int r5 = argument0[0x80];
   int r3 = argument0[0x18][0x4];

   if(r5 != r3)
      return loc_21A292E(0x80140909, var_2C);

   int r3 = argument0[0x78] - 1;

   if(r3 <= 1)
      r5 = 0x160;

   sub_21A0E3C((argument0 + 20), argument0[0x18], argument0->unk_14, r3, r5, 0);

   memcpy(destination, (argument0 + 0xD0), 0x100);

   proc_copy_14_bytes_219DE1C(&unk0, (argument0 + 0xBC));

   memset((argument0 + 0xBC), 0, 0x14);

   memset((argument0 + 0xD0), 0, 0x100);

   proc_crypto_stuff_219DE7C((argument0 + 0xBC), argument0, (argument0 + 0x70), 0x160);

   int result3 = proc_verify_14_bytes_219DE44(&unk0, (argument0 + 0xBC));

   if(result3 == 0)
      return loc_21A292E(0x80140902, var_2C);

   sub_21A0E28((argument0 + 20), (argument0 + 0xBC), argument0[0x90], argument0[0x94], argument0[0x98], argument0[0x9C]);

   int result4 = sub_21A6A10((argument0 + 0x40), argument0, (argument0 + 20), argument0[0x88], argument0[0x78]); //some vfs node functions inside

   if(result4 != 0)
      return loc_21A292C(result4, var_2C);

   int result5 = proc_verify_14_bytes_219DE44((argument0 + 0xA8), (argument0 + 0x4C));

   if(result5 == 0)
      return loc_21A292E(0x80140902, var_2C);

   memcpy((argument0 + 0xD0), &destination, 0x100);

   (argument0 + 0xBC)[0x00] = unk0[0x0];
   (argument0 + 0xBC)[0x04] = unk0[0x4];
   (argument0 + 0xBC)[0x08] = unk0[0x8];
   (argument0 + 0xBC)[0x0C] = unk0[0xC];
   (argument0 + 0xBC)[0x10] = unk0[0x10];
   
   return loc_21A292E(0, var_2C);
}