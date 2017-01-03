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
   int unk0;
   int unk4;
   int unk8;
   int unkC;
   int unk10;
   int unk14;
   int unk18;
   int unk1C;
   int unk20;
   int unk24;
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
};

int sub_B9A684(input_B9A684* dest, char* source, int sizeFlag)
{
   /*
   var_5C= -0x5C - array of size 0x40
   var_58= -0x58
   var_54= -0x54
   var_50= -0x50
   var_4C= -0x4C
   var_48= -0x48
   var_44= -0x44
   var_40= -0x40
   var_3C= -0x3C
   var_38= -0x38
   var_34= -0x34
   var_30= -0x30
   var_2C= -0x2C
   var_28= -0x28
   var_24= -0x24
   var_20= -0x20
   var_1C= -0x1C
   */

   int r5 = &var_009EA004;
   int r2 = r2 & 0x300;
   int r4 = r0;
   int r3 = r5[0];
   int r6 = r1;

   if(r2 != 0) //check if r2 is equal to 0x100 or 0x200 or to 0x300
   {
      if(r2 == 0x100)
      {
         int r7 = 0x10;
      }
      else
      {
         if(r2 == 0x300)
         {
            int r7 == 0x20;
         }
         else
         {
            if(r2 == 0x200)
            {
               int r7 = 0x18;
            }
            else
            {
               int r7 = 0x00;
            }
         }
      }
   }

   int r1 = 0;
   int r2 = 0x40;
   int r0 = &var_5C;
   memset(r0, r1, r2);

   int r2 = r7;
   int r0 = &var_5C;
   int r1 = r6;
   memcpy(r0, r1, r2);

   int r0 = var_5C;
   int r2 = var_1C;
   int r3 = r5[0];
   r4[0x2C] = r0;

   int r0 = var_58;
   r4[0x30] = r0;

   int r0 = var_54;
   r4[0x34] = r0;

   int r0 = var_50;
   r4[0x38] = r0;

   int r0 = var_4C;
   r4[0x3C] = r0;

   int r0 = var_48;
   r4[0x40] = r0;

   int r0 = var_44;
   r4[0x44] = r0;

   int r0 = var_40;
   r4[0x48] = r0;

   int r0 = var_3C;
   r4[0x4C] = r0;

   int r0 = var_38;
   r4[0x50] = r0;

   int r0 = var_34;
   r4[0x54] = r0;

   int r0 = var_30;
   r4[0x58] = r0;

   int r0 = var_2C;
   r4[0x5C] = r0;

   int r0 = var_28;
   r4[0x60] = r0;

   int r0 = var_24;
   r4[0x64] = r0;

   int r0 = var_20;
   r4[0x68] = r0;

   int r0 = 0;

   if(r2 == r3)
   {
      return 0
   }
   else
   {
      return STACK_CHECK_FAIL;
   }
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

int sub_B9A790(input_B9A790* ptr, int value)
{
   ptr->unk_1C = value;
   return 0;
}

int exit_loc_B99762(int r0, int* r5, int var2C)
{
   //good!

   int r2 = var2C;
   int r3 = r5[0];
   if(r2 == r3)
   {
      return r0;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }
}

int exit_loc_B9975A(int r4, int* r5, int var2C)
{
   //good!

   int r0 = 0x00;
   int r0_ret = SceKernelSuspendForDriver_2bb92967(r0);
   int r0_res = r4;
   return exit_loc_B99762(r0_res, r5, var2C);
}

int exit_loc_B9979A(int* r5, int var2C)
{
   //good!

   int r0 = 0x00;
   int r0_res = SceKernelSuspendForDriver_2bb92967(r0);
   int r0_ret = 0x800F1528;
   return exit_loc_B99762(r0_ret, r5, var2C);
}

int sub_loc_B996DA()
{
   #pragma region loc_B996DA
   var_78 = r1;
   if(r8 != 0x00)
   {
      #pragma region loc_B997D8
      int r1 = r12 + 0xE8000000;
      if(r1 >= 0x8000000)
      {
         int r0 = r12;
         var_B0 = r3;
         var_AC = r2;
         int r0 = SceCpuForDriver_337cbdf3(r0);
         int r3 = var_B0;
         int r2 = var_AC;
      }
      else
      {
         int r0 = r12 + 0xA0000000;
         int r12 = r12 + 0xE0000000;
         if(r12 >= 0x20000000)
         {
            if(r0 >= 0x21000000)
               int r0 = 0;
            else
               int r0 = 1;
         }
         else
         {
            int r0 = 1;
         }
      }

      if(r0 == 0)
         int r4 = r4 | 0x1000000;
      #pragma endregion
         
      #pragma region loc_B997FE
      int r1 = r2 + 0xE8000000;
      if(r1 >= 0x8000000)
      {
         int r0 = r2;
         varB0 = r3;
         int r0 = SceCpuForDriver_337cbdf3(r0);
         r3 = varB0;
      }
      else
      {
         int r0 = r2 + 0xA0000000;
         int r2 = r2 + 0xE0000000;
         if(r2 >= 0x20000000)
         {
            if(r0 >= 0x21000000)
               int r0 = 0;
            else
               int r0 = 1;
         }
         else
         {
            int r0 = 1;
         }
      }

      if(r0 == 0)
         int r4 = r4 | 0x2000000;
      #pragma endregion
   }
   #pragma endregion
      
   #pragma region loc_B996E2
   var84 = r8;
   if(r9 != 0x00)
   {
      //loc_B997AA:
      int r2 = r3 + 0xE8000000;
      if(r2 >= 0x8000000)
      {
         int r0 = r3;
         r0 = SceCpuForDriver_337cbdf3(r0);
      }
      else
      {
         int r0 = r3 + 0xA0000000;
         int r3 = r3 + 0xE0000000;
         if(r3 >= 0x20000000)
         {
            if(r0 >= 0x21000000)
               int r0 = 0;
            else
               int r0 = 1;
         }
         else
         {
            int r0 = 1;
         }
      }

      if(r0 == 0)
         int r4 = r4 | 0xC000000;
   }
   #pragma endregion
    
   #pragma region loc_B996EC
   int r0 = 0x00;
   var74 = r9;
   SceKernelSuspendForDriver_4df40893(r0);

   if((r10 & 0x29) > 0)
   {
      int r3 = 0x00;
   }
   else
   {
      int r3 = 0x01;
   }

   if(r6 != 0x03)
      int r3 = r3 | 0x01;

   if(r3 != 0)
   {
      if(r6 != 0x04)
      {
         if(r11 <= 0xFF) //BLS = fix this
         {
            int r1 = r11;
            int r0 = &var98;
            int r0 = sub_B9A790(r0, r1);
            if(r0 != 0)
               return exit_loc_B9979A(r5, var2C);
         }
         else
         {
            int r1 = varA4;
            int r0 = var98;
            int r2 = r4;
            int r0 = sub_B9A684(r0, r1, r2);
            if(r0 != 0)
            {
               return exit_loc_B9979A(r5, var2C);
            }
            else
            {
               int r4 = r4 | 0x80;
            }
         }
      }
   }
   #pragma endregion
   
   #pragma region loc_B9970A
   int r3 = var8C;
   int r0 = r7;
   int r1 = 0x13;
   int r2 = 0x00;
   int r3 = r3 | r4;
   var8C = r3;
   int r0 = SceDmacmgrForDriver_fce4171a(r0, r1, r2, r3);
   int r6 = r0;
   if(r6 < 0)
   {
      int r0 = 0x00;
      int r0 =  SceKernelSuspendForDriver_2bb92967(r0);
      int r0 = r6;
      return exit_loc_B99762(r0, r5, var2C);
   }
   else
   {
      r4 = r4 + 0x07;
      int r0 = r7;
      int* r1 = &var98;

      if(r4 == 0x03)
      {
         int r2 == 0x01;
      }
      else
      {
         int r2 = 0x11;
      }

      int r0 = SceDmacmgrForDriver_01a599e0(r0, r1, r2);
      int r4 = r0;
      if(r0 == 0)
      {
         return exit_loc_B9975A(r4, r5, var2C);
      }
      else
      {
         int r0 = r7;
         int r0 = SceDmacmgrForDriver_543f54cf(r0);
         int r4 = r0;
         if(r4 < 0)
         {
            return exit_loc_B9975A(r4, r5, var2C);
         }
         else
         {
            int r0 = SceSysrootForDriver_ee934615();
            int r2 = 0x00;
            int r0 = r7;
            int r1 = 0x02;
            int r3 = r2;

            int r0 = SceDmacmgrForDriver_397a917c(r0, r1, r2, r3);
            int r4 = r0;
                        
            int r0 = SceSysrootForDriver_eef091a7();
                        
            return exit_loc_B9975A(r4, r5, var2C);
         }
      }
   }
   #pragma endregion
}

int sub_B99674(int id, void* ptr0, void* ptr1, int param0, 
               int arg_0, int arg_4, int arg_8, int arg_C, int arg_10, int arg_14)
{
   /*
   var_B0          = -0xB0
   var_A8          = -0xA8
   var_A4          = -0xA4
   var_A0          = -0xA0
   var_9C          = -0x9C
   var_98          = -0x98
   var_94          = -0x94
   var_90          = -0x90
   var_8C          = -0x8C
   var_84          = -0x84
   var_78          = -0x78
   var_74          = -0x74
   var_2C          = -0x2C
   arg_0           =  0
   arg_4           =  4
   arg_8           =  8
   arg_C           =  0xC
   arg_10          =  0x10
   arg_14          =  0x14
   */  

   
   int r4 = arg_8;
   int r5 = &var_009EA004;
   int r7 = r0;
   int lr = [r5];
   int r12 = r1;
   int r6 = r4 & 0x07;
   int r0 = arg_14;

   int r1 = 0x00;
   var_98 = r12;
   var_94 = r2;
   
   var_2C = lr;
   var_A0 = r1;

   r10 = arg_0;
   r11 = arg_4;
   r8 = arg_C;
   r9 = arg_10;
   
   varA4 = r0;

   bool exec_B99846 = false;

   if(r6 == 0x03)
   {
      #pragma region loc_B9982C
      int r0 = r4 << 0x15; //21
      var9c = r1;
      if(r0 >= 0) //i do not understand this check yet
      {
         #pragma region loc_B99870
         int r0 = r2;
         int r1 = &var9C;
         var_B0 = r3;
         var_AC = r2;
         var_A8 = r12;
         int r0 = SceSysmemForDriver_sceKernelGetPaddr_8d160e65(r0, r1);
         int r3 = var_B0;
         int r2 = var_AC;
         int r12 = var_A8;

         if(r0 < 0)
         {
            int r0 = 0x800F1528;
            return exit_loc_B99762(r0, r5, var2C);
         }
         else
         {
            r1 = var9C;
         }
         #pragma endregion
      }

      #pragma region loc_B99832
      int r10 = r10 | 0x10000000;
      int r0 = 0x3000;
      var_90 = r10;
      r10 = r4 & 0x38;
      var_94 = r1;
      var_8C = r0;
     
      exec_B99846 = true;

      #pragma endregion
      #pragma endregion
   }
   else
   {
      #pragma region loc_no_loc
      int r0 = 0x3000;
      var_90 = r10;
      var_8C = r0;
      int r10 = r4 & 0x38;

      if(r6 != 0x04)
      {
         int r0 = r10;
         if(r0 != 0)
            int r0 = 0x01;

         if(r6 == 0x01)
            int r1 = r0;
         else
            int r1 = r0 | 0x01;

         if(r1 == 0)
         {
            r10 = r1;
         }
         else
         {
            #pragma region loc_B9989A
            if(r6 == 0x02)
               int r1 = r0;
            else
               int r1 = r0 | 0x01;

            if(r1 != 0x00)
            {
               exec_B99846 = true;
            }

            #pragma endregion
         }
      }
      #pragma endregion
   }

   if(exec_B99846)
   {      
      #pragma region loc_B99846
      if(r3 == 0)
      {
         int r0 = 0x800F1516;
         return exit_loc_B99762(r0, r5, var2C);
      }
      else
      {
         int r0 = r3;
         int r1 = &var_A0;
         var_B0 = r3;
         var_AC = r2;
         var_A8 = r12;
         int r0 = SceSysmemForDriver_sceKernelGetPaddr_8d160e65(r0, r1);
         int r3 = var_B0;
         int r2 = var_AC;
         int r12 = var_A8;
                  
         if(r0 < 0)
         {
            int r0 = 0x800F1528;
            return exit_loc_B99762(r2, r5, var2C);
         }
         else
         {
            int r1 = var_A0;
         }
      }
      #pragma endregion
   }
       
   return sub_loc_B996DA();
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