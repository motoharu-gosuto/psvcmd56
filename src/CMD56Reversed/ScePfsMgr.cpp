#include <map>
#include <stdint.h>

#include "SceIofilemgr.h"
#include "SceSysclib.h"

typedef struct ctx_21A27B8_70 //size is 0x160
{
   //8 + 44 + 14 = 60

   char unk_70[0x8]; //header
   
   uint32_t unk_78; //field
   uint32_t unk_7C;

   uint32_t unk_80; //field
   uint32_t unk_84;
   uint32_t unk_88; //field
   uint32_t unk_8C;

   uint32_t unk_90; //field
   uint32_t unk_94; //field
   uint32_t unk_98; //field
   uint32_t unk_9C; //field

   uint32_t unk_A0;
   uint32_t unk_A4;

   char unk_A8[0x14];
   char unk_BC[0x14];
   char unk_D0[0x100];

} ctx_21A27B8_70;

typedef struct ctx_21A27B8_18 //size is unknown
{
   uint32_t unk_0;
   uint32_t unk_4;

}ctx_21A27B8_18;

typedef struct node_holder
{
   vfs_node * node;
   uint32_t unk_4;
};

typedef struct ctx_21A27B8_20 //size is 0x20
{
   ctx_21A27B8_18* unk_0;
   node_holder* unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   uint32_t unk_10;
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;

}ctx_21A27B8_20;

typedef struct ctx_21A27B8_40 //size is 0x28
{
   uint32_t unk_40;
   uint32_t unk_44;
   uint32_t unk_48;

   char unk_4C[0x14];

   uint32_t unk_60;
   uint32_t unk_64;

}ctx_21A27B8_40;

typedef struct ctx_21A27B8
{
   char data0[0x14];

   node_holder * unk_14;
   ctx_21A27B8_18* unk_18; //field
   uint32_t unk_1C;

   ctx_21A27B8_20 unk_20; //field

   ctx_21A27B8_40 unk_40; //field

   uint32_t unk_68; //field
   uint32_t unk_6C;

   ctx_21A27B8_70 unk_70;
   
   uint32_t unk_1D0;

}ctx_21A27B8;

//this function provides only pair as a responce

int sub_2199144(node_holder* node, std::pair<uint32_t, uint32_t>* result_pair)
{
   //var_D0
   int result_length;
   vfs_node_func15_arg1 arg1;
   vfs_node_func15_arg2 arg2;
   char dest_5C[0x40]; //data from node
   int var_1C = var_009EA004; //cookie
   
   SceIofilemgrForDriver_unk_aa253b68(node->node, dest_5C, 0x40, &result_length); //get dest_5C from vfs_node

   int length = strnlen(dest_5C, 0x3F);

   arg1.data = dest_5C;
   arg1.len = length;
   arg1.unk_8 = 0;

   SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(node->node); //wait - standard wrap

   int result_15 = SceIofilemgrForDriver_vfs_node_func15_50a63acf(node->node, &arg1, &arg2); //execute node function 15

   SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(node->node); //set - standard wrap

   if(result_15 >= 0)
   {
      result_pair->first = arg2.unk_8;
      result_pair->second = arg2.unk_C;
   }

   if(var_1C == var_009EA004)
      return STACK_CHECK_FAIL;
   else
      return result_15;
}

//num0, num1 are probably offset
int read_wrapper_2199064(node_holder* unk0, char *buffer, int size, int ignored, int offsetLo, int offsetHi, uint32_t* readBytes)
{
   /*
   var_3C= -0x3C
   var_38= -0x38
   */

   int var_30 = 0;
   
   int var_2C = var_009EA004;

   /*
   var_28= -0x28
   var_24= -0x24
   var_20= -0x20
   var_1C= -0x1C
   var_18= -0x18
   var_14= -0x14
   var_10= -0x10
   var_C= -0xC
   var_8= -8 
   var_4= -4 
   */

   SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(unk0->node);

   int f_result = SceIofilemgrForDriver_vfs_node_func5_or_19_abbc80e3(unk0->node, unk0->unk_4, buffer, size, offsetLo, offsetHi, &var_30);
   
   SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(unk0->node);
   
   if(f_result >= 0)
   {
      *readBytes = var_30;

      if(var_2C == var_009EA004)
         return 0;
      else
         return STACK_CHECK_FAIL;
   }
   else
   {
      if(var_2C == var_009EA004)
         return f_result;
      else
         return STACK_CHECK_FAIL;
   }
}

void sub_21A0E3C(ctx_21A27B8_20* unk0, ctx_21A27B8_18* unk1, node_holder* unk2, int unk3, int arg_0, int arg_4)
{
   unk0->unk_0 = unk1;
   unk0->unk_4 = unk2;
   unk0->unk_8 = 0xFFFFFFFF;
   unk0->unk_C = 0xFFFFFFFF;
   unk0->unk_10 = 0x80;
   unk0->unk_14 = 0x80;
   unk0->unk_18 = arg_0;
   unk0->unk_1C = arg_4;
}

void proc_copy_14_bytes_219DE1C(char unk0[0x14], char unk1[0x14])
{
   memcpy(unk0, unk1, 0x14);
}

int SceKernelUtilsForDriver_29a28957(int unk0, int unk1, int unk2, int unk3, int arg_0)
{
   return 0;
}

int proc_crypto_stuff_219DE7C(char bytes14[0x14], ctx_21A27B8* base, ctx_21A27B8_70* data_base, int size)
{
   int r6 = &var_009EA004;
   int lr = r1;
   int r8 = r0;
   int r1 = *r6;
   int r9 = r3;

   unk0 = r2;
   var_2C = r1; //cookie

   if(r3 == 0)
   {
      arg_0 = r0;
      int r1 = 0x14;
      int r0 = lr;

      SceKernelUtilsForDriver_29a28957(r0, r1, r2, r3, arg_0);

      //optimization here, r3 = 0
      //however r9 is returned meaning that 0 is returned since r9 is assigned with r3 before 'if' 
      r9 = 0;
   }
   else
   {
      int r4 = &var_12C;
      int r0 = lr[0];
      int r12 = 0 - r4;

      int r1 = lr[4];
      int r2 = lr[8];

      int r12 = r12 & 0x3F;

      int r3 = lr[0x0C];

      int r12 = r12 + r4;
      
      int r5 = 0;
      
      int r4 = r12 + 8;
      
      int r7 = r12;

      int r11 = &var_AC;
      
      r4[0] = r5;
      r4 = r4 + 4;

      int r10 = 0 - r11;

      r4[0] = r5;
      r4 = r4 + 4;

      int r10 = r10 & 0x3F;
      
      r4[0] = r5;
      r4 = r4 + 4;

      int r10 = r10 + r11;

      r4[0] = r5;
      r4[4] = r5;
      r4 = r4 + 8;

      r4[0] = r5;

      int r4 = 1;

      r7[0x00] = r0;
      r7[0x04] = r1;
      r7[0x08] = r2;
      r7[0x0C] = r3;

      r7 = r7 + 0x10;

      int r2 = r9;
      
      int r0 = lr[0x10];
      int r3 = r12;
      int r1 = r10;
      
      arg_0 = r5;
      arg_8 = r5;

      r7[0] = r0;

      int r0 = unk0;
      arg_4 = r4;

      ScePfsMgr.SceSblSsMgrForDriver._imp_6704d985();

      int r9 = r0;

      if(r0 == 0)
      {
         int r0 = r10[0x00];
         int r1 = r10[0x04];
         int r2 = r10[0x08];
         int r3 = r10[0x0C];

         r10 = r10 + 0x10;

         r8[0x00] = r0;
         
         int r0 = r10[0];
         
         r8[0x04] = r1;
         r8[0x08] = r2;
         r8[0x10] = r0;
         r8[0x0C] = r3;
      }
   }

   //loc_219DEF8:

   int r2 = var_2C;
   int r0 = r9;
   int r3 = r6[0];

   if(r2 == r3)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

//count leading zeroes
#define CLZ(x) 0

int proc_verify_14_bytes_219DE44(char unk0[0x14], char unk1[0x14])
{
   //from what I know - b5a4d745 returns only 0, -1 (not sure about 1) based on reversing and tests
   //for  0 - CLZ is 32
   //for  1 - CLZ is 31
   //for -1 - CLZ is 0
    
   //for  0 - >> 5 is 1
   //for  1 - >> 5 is 0
   //for -1 - >> 5 is 0
    
   //LSRS changes flag to indicate if value is zero or not
   //zero value is considered as error
   //which means that original value 1 or -1 is an error and 0 is success
   //meaning that unk0 and unk1 should be identical for this function to succeed
   //this is some analog of strcmp or memcmp

   int result = SceSysclibForDriver_b5a4d745(unk0, unk1, 0x14);
   int leadZeroesCnt = CLZ(result); 
   int r0 = leadZeroesCnt >> 5;
   return r0;
}

//unk1 is ignored
void sub_21A0E28(ctx_21A27B8_20* unk0, char unk1[0x14], int unk2, int unk3, int arg_0, int arg_4)
{
   unk0->unk_8 = unk2;
   unk0->unk_C = unk3;
   unk0->unk_10 = arg_0;
   unk0->unk_14 = arg_4;
}

int sub_21A6A10(ctx_21A27B8_40* unk0, ctx_21A27B8* unk1, ctx_21A27B8_20* unk2, int unk3, int arg_0)
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

int proc_SCENGPFS_21A27B8(ctx_21A27B8* argument0, node_holder* argument1, char argument2[0x14])
{
   //var_294= -0x294         
   //var_290= -0x290
   uint32_t var_28C; //read bytes value
   std::pair<uint32_t, uint32_t> result_p; //size is 0x8 bytes in total
   char unk0[0x14]; //0x14 bytes
   char destination[0x240]; //size is 0x100 or 0x200 aligned to 0x40 (that is why 0x240 in total). this is multipurpose buffer
   int var_2C = var_009EA004; //cookie

   argument0->unk_14 = argument1;

   int result0 = sub_2199144(argument1, &result_p); //call vfs_node_func15 (sceIoGetstatForDriver) - only provides pair responce

   if(result0 != 0)
      return loc_21A292C(result0, var_2C);

   if((result_p.first | result_p.second) == 0)
      return loc_21A292E(0x80140904, var_2C);

   char* aligned_buffer = (char*)(((uint32_t)destination + 0x3F) & (~0x3F)); //align up to 0x40
   
   int result1 = read_wrapper_2199064(argument0->unk_14, aligned_buffer, 0x200, 0, 0x200, 0, &var_28C); // call func5_or_19

   if(result1 != 0)
      return loc_21A292C(result1, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);
    
   int some_value = aligned_buffer[0x60]; //save some value from files.db file
   argument0->unk_68 = some_value;

   if(some_value != 0)
      return loc_21A292E(0x8014090A, var_2C);

   //not sure about 0x80 80
   int result2 = read_wrapper_2199064(argument0->unk_14, aligned_buffer, 0x200, 0, 0x80, 0x80, &var_28C); // call func5_or_19

   if(result2 != 0)
      return loc_21A292C(result2, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(&argument0->unk_70, aligned_buffer, 0x160); //copy 0x160 bytes of files.db beginning into buffer

   //-----------

   if(strncmp("SCENGPFS", argument0->unk_70.unk_70, 8) != 0) //verify header
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(argument0->data0, argument2, 0x14); //copy 0x14 bytes of some input data

   int r5 = argument0->unk_70.unk_80; //offset 0x10 in file - some kind of size ?

   if(r5 != argument0->unk_18->unk_4)
      return loc_21A292E(0x80140909, var_2C);

   int r3 = argument0->unk_70.unk_78 - 1; //offset 0x08 in file - some kind of counter ?

   if(r3 <= 1)
      r5 = 0x160;

   //assign values to argument0->unk_20
   sub_21A0E3C(&argument0->unk_20, argument0->unk_18, argument0->unk_14, r3, r5, 0);

   memcpy(destination, argument0->unk_70.unk_D0, 0x100); //offset 0x60 in file - copy 0x100 bytes

   proc_copy_14_bytes_219DE1C(unk0, argument0->unk_70.unk_BC); //offset 0x4C in real file - copy 0x14 bytes

   memset(argument0->unk_70.unk_BC, 0, 0x14); //clear read data

   memset(argument0->unk_70.unk_D0, 0, 0x100); //clear read data

   proc_crypto_stuff_219DE7C(argument0->unk_70.unk_BC, argument0, &argument0->unk_70, 0x160);

   int result3 = proc_verify_14_bytes_219DE44(unk0, argument0->unk_70.unk_BC);

   if(result3 == 0)
      return loc_21A292E(0x80140902, var_2C);

   sub_21A0E28(&argument0->unk_20, argument0->unk_70.unk_BC, argument0->unk_70.unk_90, argument0->unk_70.unk_94, argument0->unk_70.unk_98, argument0->unk_70.unk_9C);

   int result4 = sub_21A6A10(&argument0->unk_40, argument0, &argument0->unk_20, argument0->unk_70.unk_88, argument0->unk_70.unk_78); //some vfs node functions inside

   if(result4 != 0)
      return loc_21A292C(result4, var_2C);

   int result5 = proc_verify_14_bytes_219DE44(argument0->unk_70.unk_A8, argument0->unk_40.unk_4C);

   if(result5 == 0)
      return loc_21A292E(0x80140902, var_2C);

   memcpy(argument0->unk_70.unk_D0, &destination, 0x100);

   memcpy(argument0->unk_70.unk_BC, unk0, 0x14);
   
   return loc_21A292E(0, var_2C);
}