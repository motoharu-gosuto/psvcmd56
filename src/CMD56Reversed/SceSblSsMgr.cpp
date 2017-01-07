#include <string>

#include "SceSblSsMgr.h"

#include "Constants.h"
#include "GlobalVariables.h"

#include "SceCpu.h"
#include "SceSysroot.h"
#include "SceSysmem.h"
#include "SceKernelDmacMgr.h"
#include "SceKernelSuspend.h"

// ======================================

struct input_B9A684
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
   int unk_28;
   
   char unk_2C[0x40];
};

//source is array of size 0x20 at max
int sub_B9A684(input_B9A684* dest, char* source, int sizeFlag)
{
   int cookie = var_009EA004;
   int mask = (sizeFlag & 0x300);
   int tempSize;

   if(mask == 0) //check if r2 is equal to 0x100 or 0x200 or to 0x300
      tempSize = 0x08;
   else if(mask == 0x100)
      tempSize = 0x10;
   else if(mask == 0x300)
      tempSize == 0x20;
   else if(mask == 0x200)
      tempSize = 0x18;
   else
      tempSize = 0x00;

   char buffer_temp[0x40];

   memset(buffer_temp, 0, 0x40);

   memcpy(buffer_temp, source, tempSize);
   
   memcpy(dest->unk_2C, buffer_temp, 0x40);

   if(cookie == var_009EA004)
      return 0;
   else
      return STACK_CHECK_FAIL;
}

struct input_B9A790
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
};

int sub_B9A790_set_1C(input_B9A790* ptr, int value)
{
   ptr->unk_1C = value;
   return 0;
}

int exit_loc_B99762(int r0, int cookie)
{
   if(cookie == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

int exit_loc_B9975A(int r4, int var2C)
{
   SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0x00);
   return exit_loc_B99762(r4, var2C);
}

int exit_loc_B9979A(int var2C)
{
   SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0x00);
   return exit_loc_B99762(0x800F1528, var2C);
}

int finalize_buffer(int id, int var_8C, int var_2C, int R4, void* var_98)
{
   int r0 = SceDmacmgrForDriver_fce4171a(id, 0x13, 0x00, var_8C);
   if(r0 < 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0x00);
      return exit_loc_B99762(r0, var_2C);
   }
   else
   {
      int R2;
      if((R4 & 0x07) == 0x03)
         R2 == 0x01;
      else
         R2 = 0x11;

      int r0 = SceDmacmgrForDriver_01a599e0(id, var_98, R2);
      if(r0 == 0)
      {
         return exit_loc_B9975A(r0, var_2C);
      }
      else
      {
         
         int r0 = SceDmacmgrForDriver_543f54cf(id);
         if(r0 < 0)
         {
            return exit_loc_B9975A(r0, var_2C);
         }
         else
         {
            SceSysrootForDriver_atomic_add_10_to_008B80A8_ee934615();

            int r0 = SceDmacmgrForDriver_397a917c(id, 0x02, 0x00, 0x00);
                        
            SceSysrootForDriver_atomic_sub_10_from_008B80A8_eef091a7();
                        
            return exit_loc_B9975A(r0, var_2C);
         }
      }
   }
}

int call_subs_update_r4_flag(int arg_8, int arg_4, char* arg_14, int R10, int var_2C, int& R4, void* var_98)
{
   int R3;
   if((R10 & 0x29) > 0)
      R3 = 0x00;
   else
      R3 = 0x01;

   int mask = arg_8 & 0x07;

   if(mask != 0x03)
      R3 = R3 | 0x01;

   if(R3 != 0)
   {
      if(mask != 0x04)
      {
         if(arg_4 <= 0xFF)
         {
            int res_3 = sub_B9A790_set_1C(var_98, arg_4); //this is very important !!!!!!
            if(res_3 != 0)
               return exit_loc_B9979A(var_2C);
         }
         else
         {
            int res_3 = sub_B9A684(var_98, arg_14, arg_8); //this is also important !!!
            if(res_3 != 0)
               return exit_loc_B9979A(var_2C);
            else
               R4 = arg_8 | 0x80;
         }
      }
   }

   return 0;
}

void update_r4_flag(void* param0, int arg_10, int& R4)
{
   if(arg_10 != 0x00)
   {
      int R0;

      if(param0 + 0xE8000000 >= 0x8000000)
      {
         R0 = SceCpuForDriver_sceKernelTryGetPaddr_337cbdf3(param0);
      }
      else
      {
         int rng0 = param0 + 0xA0000000;
         int rng1 = param0 + 0xE0000000;
         if(rng1 >= 0x20000000)
         {
            if(rng0 >= 0x21000000)
               R0 = 0;
            else
               R0 = 1;
         }
         else
         {
            R0 = 1;
         }
      }

      if(R0 == 0)
         R4 = R4 | 0xC000000;
   }
}


void check_vaddr0(void* vaddr_0, int arg_8, int& R4)
{
   int R0;
      
   if(((int64_t)vaddr_0 + 0xE8000000) >= 0x8000000) //original condition was BCC
   {
      R0 = SceCpuForDriver_sceKernelTryGetPaddr_337cbdf3(vaddr_0); //returns 0 on success or 1 on failure
   }
   else
   {
      if((int64_t)vaddr_0 + 0xE0000000 >= 0x20000000) //original condition was BCS
      {
         R0 = 1;
      }
      else
      {
         if((int64_t)vaddr_0 + 0xA0000000 >= 0x21000000) //original condition was BCS
            R0 = 1;
         else
            R0 = 0;
      }
   }

   if(R0 == 0)
   {
      R4 = arg_8 | 0x1000000;
   }
}

void check_vaddr1(void* vaddr_1, int arg_8, int& R4)
{
   int R0;
      
   if(((int64_t)vaddr_1 + 0xE8000000) >= 0x8000000) // original condition was BCC
   {
      R0 = SceCpuForDriver_sceKernelTryGetPaddr_337cbdf3(vaddr_1); //returns 0 on success or 1 on failure
   }
   else
   {
      if(((int64_t)vaddr_1 + 0xE0000000) >= 0x20000000)  //original condition was BCS
      {
         R0 = 1;  
      }
      else
      {
         if(((int64_t)vaddr_1 + 0xA0000000) >= 0x21000000) //original condition was BCS
            R0 = 1;
         else
            R0 = 0;
      }
   }

   if(R0 == 0)
   {
      R4 = R4 | 0x2000000;
   }
}

//adds to arg_8 mask 0x1000000 (based on vaddr_0 and arg_C)
//adds to arg_8 mask 0x2000000 (based on vaddr_1 and arg_C)
//sets var_84 to arg_C
void update_r4_by_vaddr0_vaddr1(void* vaddr_0, void* vaddr_1, int arg_8, int arg_C, int& R4, int& var_84)
{
   R4 = arg_8;

   if(arg_C != 0x00)
   {
      check_vaddr0(vaddr_0, arg_8, R4);

      check_vaddr1(vaddr_1, arg_8, R4);
   }

   var_84 = arg_C;
}

int translateVaddr2(void* vaddr_2, void*& paddr_2, int cookie)
{
   paddr_2 = 0x00;

   if(vaddr_2 == 0)
      return exit_loc_B99762(0x800F1516, cookie);

   void* paddr_2_temp = 0x00;
   int res_1 = SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(vaddr_2, &paddr_2_temp);     
   if(res_1 < 0)
      return exit_loc_B99762(0x800F1528, cookie);

   paddr_2 = paddr_2_temp;

   return 0;
}

int translateVaddr1(void* vaddr_1, int arg_8, void*& paddr_1, int cookie)
{
   paddr_1 = 0x00;

   if((arg_8 << 0x15) >= 0)
   {
      void* paddr_1_temp = 0x00;
      int res_0 = SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(vaddr_1, &paddr_1_temp);
      if(res_0 < 0)
         return exit_loc_B99762(0x800F1528, cookie);
         
      paddr_1 = paddr_1_temp;
   }

   return 0;
}

//optionally translates vaddr_1 and stores paddr to var_94 (based on arg_8) - if not translated - vaddr_1 is stored
//optionally translates vaddr_2 and stores paddr to var_78 (based on arg_8) - if not translated - 0 is stored
//sets var_90 to arg_0 or (arg_0 | 0x10000000) (based on arg_8)
//sets var_8C to 0x3000
//sets R10 to (arg_8 & 0x38) or 0 based on (based on arg_8)
int translate_vaddr1_vaddr2(void* vaddr_1, void* vaddr_2, int arg_0, int arg_8, int cookie, int& R10, int& var_90, void*& var_94, int& var_8C, void*& var_78)
{
   int mask = arg_8 & 0x07;

   var_94 = vaddr_1;
   var_8C = 0x3000;
   R10 = arg_8 & 0x38;

   var_90 = (mask == 0x03) ? (arg_0 | 0x10000000) : arg_0;

   if(mask == 0x03)
   {
      int res_0 = translateVaddr1(vaddr_1, arg_8, var_94, cookie);
      if(res_0 != 0)
         return res_0;

      int res_1 = translateVaddr2(vaddr_2, var_78, cookie);
      if(res_1 != 0)
         return res_1;
      
      return 0;
   }
   else
   {
      if(mask == 0x04)
      {
         var_78 = 0x00;
         return 0;
      }
      
      int flag = ((arg_8 & 0x38) != 0) ? 0x01 : 0x00; //flag can only take values of 0 or 1
      
      int C1 = (mask == 0x01) ? flag : (flag | 0x01); //r1 can only take values of 0 and 1
      if(C1 == 0)
      {
         R10 = 0;
         var_78 = 0x00;
         return 0;
      }

      int C2 = (mask == 0x02) ? flag : (flag | 0x01); //r1 can only take values of 0 and 1
      if(C2 == 0x00)
      {
         //could it be that at this point R10 can only equal 0
         //but it is not set due to optimization?
         var_78 = 0x00;
         return 0;
      }
      
      int res_1 = translateVaddr2(vaddr_2, var_78, cookie);
      if(res_1 != 0)
         return res_1;
      
      return 0;
   }
}

int sub_B99674(int id, void* vaddr_0, void* vaddr_1, void* vaddr_2, 
               int arg_0, int arg_4, int arg_8, int arg_C, int arg_10, char* arg_14)
{
   //void* var_B0; //temp for storing regs between calls
   //void* var_AC; //temp for storing regs between calls
   //void* var_A8; //temp for storing regs between calls

   //int var_A4; //temp for storing arg_14
   //int var_A0; //temp for function result int*
   //int var_9C; //temp for function result int*

   //var_98 is also used by SceDmacmgrForDriver_01a599e0
   //var_98 is structure of size 0x6C

   //beginning of structure
   void* var_98;   //0x00 - field of structure that is used - vaddr_0
   void* var_94;   //0x04 - field of structure that is used - vaddr_1 or (some result of sceKernelGetPaddr)
   int var_90;     //0x08 - field of structure that is used - (arg_0) or (arg_0 | 0x10000000)
   int var_8C;     //0x0C - field of structure that is used - 0x3000
   int var_84;     //0x10 - field of structure that is used - arg_C
   void* var_78;   //0x14 - field of structure that is used - 0 or ? or (some result of sceKernelGetPaddr)
   int var_74;     //0x18 - field of structure that is used - arg_10
                   //0x1C - can be set by sub_B9A790
                   //0x20 - ?
                   //0x24 - ?
                   //0x28 - ?
                   //0x2C - start of 0x40 buffer

   //resulting structure will fit the stack exactly:
   //0x2C + 0x40 = 0x6C
   //0x98 - 0x6C = 0x2C - address of cookie

   //---------------------------------------------------

   int var_2C = var_009EA004; //cookie
   
   int R10;
   int res_0 = translate_vaddr1_vaddr2(vaddr_1, vaddr_2, arg_0, arg_8, var_2C, R10, var_90, var_94, var_8C, var_78);
   if(res_0 != 0)
      return res_0;

   int R4;
   update_r4_by_vaddr0_vaddr1(vaddr_0, vaddr_1, arg_8, arg_C, R4, var_84);
   
   //------------------------------------

   update_r4_flag(vaddr_2, arg_10, R4);

   //------------------------------------

   var_74 = arg_10;

   SceKernelSuspendForDriver_call_func_008B808C_atomic_inc_008BF3FC_4df40893(0x00);


   var_98 = vaddr_0;

   int res_1 = call_subs_update_r4_flag(arg_8, arg_4, arg_14, R10, var_2C, R4, var_98);
   if(res_1 != 0)
      return res_1;

  //------------------------------------
   
   var_8C = var_8C | R4;

   return finalize_buffer(id, var_8C, var_2C, R4, &var_98);
}

// ================

int exit_loc_B99C0A(int r0, int cookie)
{
   if(var_009EA004 == cookie)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

//CHECK procedure sub_B99998
//TODO: it shows all the arguments to sub_B99674 very intuitively !!!

char* unk_B9CC90 = "SceSblDmac5Common";

//assume - gen/buffer shift
//size - in our case is always 0x40 because passed by wrapper
//unk - in our case is always 0x01 because passed by wrapper
int SceSblSsMgrForDriver_4dd1b2e5(char* outputBuffer, int size, int unk)
{
   char sourceBuffer[0x40];   
   int cookie = var_009EA004;
     
   if(size > 0x40)
      return exit_loc_B99C0A(0x800F1516, cookie);

   int id = SceDmacmgrForDriver_7cd5088a(unk_B9CC90);

   if(id < 0)
      return exit_loc_B99C0A(0x800F1528, cookie);
   
   int var_8C;

   if(unk == 0x00)
      var_8C = 0x00000000;
   else
      var_8C = 0x0003ffff;

   int res_0 = sub_B99674(id, sourceBuffer, sourceBuffer, 0x00, 0x40, 0x00, 0x04, var_8C, 0x00, 0x00);

   int res_1 = SceDmacmgrForDriver_adff1186(id);

   if(res_0 != 0)
      return exit_loc_B99C0A(res_0, cookie);

   memcpy(outputBuffer, sourceBuffer, size);

   return exit_loc_B99C0A(res_0, cookie);
}

//wrapper
int SceSblSsMgrForDriver_ac57f4f0(char* buffer)
{
   return SceSblSsMgrForDriver_4dd1b2e5(buffer, 0x40, 0x01);
}