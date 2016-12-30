#include <string>
#include <chrono>
#include <stdint.h>

#include "UnknownImports.h"
#include "Subroutines.h"
#include "Constants.h"

//CRITICAL - key generation

int SceSblSsMgr_SceKernelSuspendForDriver_imp_4df40893(int unk)
{
   //does it return values?
   return 0;
}

int SceSblSsMgr_SceKernelSuspendForDriver_imp_2bb92967(int unk)
{
   //does it return values ?
   return 0;
}

int SceSblSsMgr_SceSysrootForDriver_imp_ee934615()
{
   //does it return values ?
   return 0;
}

char* unk_B9CC90 = "SceSblDmac5Common";

//TODO: looks like this function returns id
//this can be easily checked
//need to look at other known paired functions and see how id is formed there
//looks like there is a special algorithm to convert pointer to id ?

int SceSblSsMgr_SceDmacmgrForDriver_imp_7cd5088a(const char* name)
{
   return 0;
}

int SceSblSsMgr_SceDmacmgrForDriver_imp_fce4171a(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceSblSsMgr_SceDmacmgrForDriver_imp_01a599e0(int unk0, int unk1, int unk2)
{
   return 0;
}

int SceSblSsMgr_SceDmacmgrForDriver_imp_543f54cf(int unk0)
{
   return 0;
}

int SceSblSsMgr_SceDmacmgrForDriver_imp_397a917c(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceSblSsMgr_SceSysrootForDriver_imp_eef091a7()
{
   //does it return values?
   return 0;
}


int sub_B9A684(int unk0, int unk1, int unk2)
{
   return 0;
}

int sub_B9A790(int unk0, int unk1)
{
   return 0;
}

int exit_loc_B99762(int r0, int* r5, int var2C)
{
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
   int r0 = 0x00;
   int r0 = SceSblSsMgr_SceKernelSuspendForDriver_imp_2bb92967(r0);
   int r0 = r4;
   return exit_loc_B99762(r0, r5, var2C);
}

int exit_loc_B9979A(int* r5, int var2C)
{
   int r0 = 0x00;
   int r0 = SceSblSsMgr_SceKernelSuspendForDriver_imp_2bb92967(r0);
   int r0 = 0x800F1528;
   return exit_loc_B99762(r0, r5, var2C);
}



//TODO: looks like this function has 8 or 9 arguments - need to verify this
int sub_B99674(int id, void *source_aligned, int size, int param0, int stack_unk0, int stack_unk1, int stack_unk2, int stack_unk3, int stack_unk4)
{
   /*
   var_B0=	-0xB0
   source_aligned_temp_A8=	-0xA8
   var_A4=	-0xA4
   var_A0=	-0xA0
   var_9C=	-0x9C
   var_98=	-0x98
   var_94=	-0x94
   var_90=	-0x90
   var_8C=	-0x8C
   var_84=	-0x84
   var_78=	-0x78
   var_74=	-0x74
   var_2C=	-0x2C
   stack_unk0=  0
   stack_unk1=  4
   stack_unk2=  8
   stack_unk3=  0xC
   arg_14=	 0x14 ; stack_unk4 ?
   */

   int r4 = stack_unk2;
   int r5 = &var_009EA004;
   int r7 = r0;
   int lr = [r5];
   int r12 = r1;
   int r6 = r4 + 0x07;
   int r0 = arg14; //what is this var?

   int r1 = 0x00;
   //STRD.W		R12, R2, [SP,#0x18]
   var2C = lr;
   varA4 = r0;

   if(r6 == 0x03)
   {
      int r0 = r1 << 0x15; //21
      var9c = r1;
      if(true) //(BPL)
      {
         //goto loc_B99870  ================================
      }
      else
      {
         //goto loc_B99832  ================================
      }
   }
   else
   {
      int r0 = 0x3000;
      //STRD.W		R10, R0, [SP,#0x20]
      int r10 = r4 & 0x38;

      if(r6 != 0x04)
      {
         int r0 = r10;
         if(r6 != 0x04) //this check is weird
            int r0 = 0x01;

         if(r6 == 0x01)
            int r1 = r0; // moveq ?
         else
            int r1 = r0 | 0x01;

         if(r1 != 0)
         {
            if(r6 == 0x02)
            {
               int r1 = r0;
            }
            else
            {
               int r1 = r0 | 0x01;
            }

            if(r1 == 0x00)
            {
               //goto loc_B996DA - next outer condition
            }
            else
            {
               //goto loc_B99846 ================================
            }
         }
         else
         {
            r10 = r1;
            //goto loc_B996DA - next outer condition
         }
      }

      //loc_B996DA:
      var78 = r1;
      if(r8 != 0x00)
      {
         //loc_B997D8    ================================
      }
      else
      {
         var84 = r8;
         if(r9 != 0x00)
         {
            //loc_B997AA ================================
         }
         else
         {
            int r0 = 0x00;
            var74 = r9;
            SceSblSsMgr_SceKernelSuspendForDriver_imp_4df40893(r0);

            bool br0 = r10 & 0x29; //TST.W		R10, #0x29
            if(br0)
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
                  if(r11 == 0xFF) //BLS = fix this
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

            //loc_B9970A:
            int r3 = var8C;
            int r0 = r7;
            int r1 = 0x13;
            int r2 = 0x00;
            int r3 = r3 | r4; ; // ORRS signed!
            var8C = r3;
            int r0 = SceSblSsMgr_SceDmacmgrForDriver_imp_fce4171a(r0, r1, r2, r3);
            int r6 = r0 - 0;
            if(r6 < 0)
            {
               int r0 = 0x00;
               int r0 =  SceSblSsMgr_SceKernelSuspendForDriver_imp_2bb92967(r0);
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

               int r0 = SceSblSsMgr_SceDmacmgrForDriver_imp_01a599e0(r0, r1, r2);
               int r4 = r0;
               if(r0 == 0)
               {
                  return exit_loc_B9975A(r4, r5, var2C);
               }
               else
               {
                  int r0 = r7;
                  int r0 = SceSblSsMgr_SceDmacmgrForDriver_imp_543f54cf(r0);
                  int r4 = r0 - 0x00;
                  if(r4 < 0)
                  {
                     return exit_loc_B9975A(r4, r5, var2C);
                  }
                  else
                  {
                     int r0 = SceSblSsMgr_SceSysrootForDriver_imp_ee934615();
                     int r2 = 0x00;
                     int r0 = r7;
                     int r1 = 0x02;
                     int r3 = r2;

                     int r0 = SceSblSsMgr_SceDmacmgrForDriver_imp_397a917c(r0, r1, r2, r3);
                     int r4 = r0;
                        
                     int r0 = SceSblSsMgr_SceSysrootForDriver_imp_eef091a7();
                        
                     return exit_loc_B9975A(r4, r5, var2C);
                  }
               }
            }
         }
      }
   }

   



   return 0;
}

int SceSblSsMgr_SceDmacmgrForDriver_imp_adff1186(int unk)
{
   return 0;
}

int exit_loc_B99C0A(int r0, int* r4, int var4)
{
   int r2 = var4;
   int r3 = r4[0];
   if(r2 == r3)
   {
      int r7 = r7 + 0x0C;
      int sp = r7;
      return r0;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }
}

//CHECK procedure sub_B99998
//TODO: it shows all the arguments to sub_B99674 very intuitively !!!

//assume - gen/buffer shift
int SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(char* buffer, int size, int unk)
{
   int size_98; //stack_unk0 ? - arg4
   int stack_unk1_94; //stack_unk1 - arg5
   int stack_unk2_90; //stack_unk2 - arg6
   int param_8C;      //stack_unk3 - arg7
                      //88 stack_unk4 - arg8
   int var41;
   int var4; //what is the offset
   //-----------------------

   char* r0 = buffer;
   int r1 = size;
   int r2 = unk; //always equal to 0x01
   int* r4 = &var_009EA004;

   int r3 = r4[0];
   int r7 = sp + 0x18; // some stack variable

   int r8 = r1;
   int r6 = &var41; 
   int r9 = r0;
   int r10 = r2;

   int r6 = r6 & (~0x3F); //this is weird - bit extraction
   var4 = r3;

   if(r1 > 0x40)
      return exit_loc_B99C0A(0x800F1516, r4, var4);

   char* r0 = unk_B9CC90;
   int r0 = SceSblSsMgr_SceDmacmgrForDriver_imp_7cd5088a(r0);
   int r11 = r0 - 0;

   if(r11 < 0)
      return exit_loc_B99C0A(0x800F1528, r4, var4);

   int r3 = -1;
   int r5 = 0x00;
   int r3 = r3 >> 0x0E; //14
   int lr = 4;
   int r2 = 0x40;
   stack_unk1_94 = r5;

   if(r10 == r5)
   {
      r3 = r5;
   }

   size_98 = r2;
   param_8C = r3;
   int r1 = r6;
   int r3 = r5;

   //STRD.W		R5, R5,	[SP,#0x10]

   int r2 = r6;
   stack_unk2_90 = lr; 

   int r0 = sub_B99674(r0, r1, r2, r3, ?, ?, ?, ?);
   int r5 = r0;
   int r0 = r11;
   int r0 = SceSblSsMgr_SceDmacmgrForDriver_imp_adff1186(r0);
   if(r0 != 0)
      return exit_loc_B99C0A(r0, r4, var4);

   int r0 = r9;
   int r1 = r6;
   int r2 = r8;
   memcpy(r0, r1, r2);
   int r0 = r5;
   return exit_loc_B99C0A(r0, r4, var4);
}

//wrapper
int SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(char* buffer)
{
   return SceSblSsMgr_SceSblSsMgrForDriver_exp_4dd1b2e5(buffer, 0x40, 0x01);
}

//=========================================

//CRITICAL - buffer init

struct _8BF5F8_global_2 // this is just a pair of values of size 0x08
{
   uint32_t unk_0;
   uint32_t unk_4;
};

struct _8BF5F8_global_1
{
   uint32_t unk_000;
   uint32_t unk_004;
   uint32_t unk_008;
   uint32_t unk_00C;
   uint32_t unk_010;
   uint32_t unk_014;
   uint32_t unk_018;
   uint32_t unk_01C;
   uint32_t unk_020;
   uint32_t unk_024;
   uint32_t unk_028;
   uint32_t unk_02C;
   uint32_t unk_030;
   uint32_t unk_034;
   uint32_t unk_038;
   uint32_t unk_03C;
   uint32_t unk_040;
   uint32_t unk_044;
   uint32_t unk_048;
   uint32_t unk_04C;
   uint32_t unk_050;
   uint32_t unk_054;
   uint32_t unk_058;
   uint32_t unk_05C;
   uint32_t unk_060;
   uint32_t unk_064;
   uint32_t unk_068;
   uint32_t unk_06C;
   uint32_t unk_070;
   uint32_t unk_074;
   uint32_t unk_078;
   uint32_t unk_07C;
   uint32_t unk_080;
   uint32_t unk_084;
   uint32_t unk_088;
   uint32_t unk_08C;
   uint32_t unk_090;
   uint32_t unk_094;
   uint32_t unk_098;
   uint32_t unk_09C;
   uint32_t unk_0A0;
   uint32_t unk_0A4;
   uint32_t unk_0A8;
   uint32_t unk_0AC;
   uint32_t unk_0B0;
   uint32_t unk_0B4;
   uint32_t unk_0B8;
   uint32_t unk_0BC;
   uint32_t unk_0C0;
   uint32_t unk_0C4;
   uint32_t unk_0C8;
   uint32_t unk_0CC;
   uint32_t unk_0D0;
   uint32_t unk_0D4;
   uint32_t unk_0D8;
   uint32_t unk_0DC;
   uint32_t unk_0E0;
   uint32_t unk_0E4;
   uint32_t unk_0E8;
   uint32_t unk_0EC;
   uint32_t unk_0F0;
   uint32_t unk_0F4;
   uint32_t unk_0F8;
   uint32_t unk_0FC;

   uint32_t unk_100;
   uint32_t unk_104;
   uint32_t unk_108;
   uint32_t unk_10C;
   uint32_t unk_110;
   uint32_t unk_114;
   uint32_t unk_118;
   uint32_t unk_11C;
   uint32_t unk_120;
   uint32_t unk_124;
   uint32_t unk_128;
   uint32_t unk_12C;
   uint32_t unk_130;
   uint32_t unk_134;
   uint32_t unk_138;
   uint32_t unk_13C;
   uint32_t unk_140;
   uint32_t unk_144;
   uint32_t unk_148;
   uint32_t unk_14C;
   uint32_t unk_150;
   uint32_t unk_154;
   uint32_t unk_158;
   uint32_t unk_15C;
   uint32_t unk_160;
   uint32_t unk_164;
   uint32_t unk_168;
   uint32_t unk_16C;
   uint32_t unk_170;
   uint32_t unk_174;
   uint32_t unk_178;
   uint32_t unk_17C;
   uint32_t unk_180;
   uint32_t unk_184;
   uint32_t unk_188;
   uint32_t unk_18C;
   uint32_t unk_190;
   uint32_t unk_194;
   uint32_t unk_198;
   uint32_t unk_19C;
   uint32_t unk_1A0;
   uint32_t unk_1A4;
   uint32_t unk_1A8;
   uint32_t unk_1AC;
   uint32_t unk_1B0;
   uint32_t unk_1B4;
   uint32_t unk_1B8;
   uint32_t unk_1BC;
   uint32_t unk_1C0;
   uint32_t unk_1C4;
   uint32_t unk_1C8;
   uint32_t unk_1CC;
   uint32_t unk_1D0;
   uint32_t unk_1D4;
   uint32_t unk_1D8;
   uint32_t unk_1DC;
   uint32_t unk_1E0;
   uint32_t unk_1E4;
   uint32_t unk_1E8;
   uint32_t unk_1EC;
   uint32_t unk_1F0;
   uint32_t unk_1F4;
   uint32_t unk_1F8;
   uint32_t unk_1FC;

   uint32_t unk_200;
   uint32_t unk_204;
   uint32_t unk_208;
   uint32_t unk_20C;
   uint32_t unk_210;
   uint32_t unk_214;
   uint32_t unk_218;
   uint32_t unk_21C;
   uint32_t unk_220;
   uint32_t unk_224;
   uint32_t unk_228;
   uint32_t unk_22C;
   uint32_t unk_230;
   uint32_t unk_234;
   uint32_t unk_238;
   uint32_t unk_23C;
   uint32_t unk_240;
   uint32_t unk_244;
   uint32_t unk_248;
   uint32_t unk_24C;
   uint32_t unk_250;
   uint32_t unk_254;
   uint32_t unk_258;
   uint32_t unk_25C;
   uint32_t unk_260;
   uint32_t unk_264;
   uint32_t unk_268;
   uint32_t unk_26C;
   uint32_t unk_270;
   uint32_t unk_274;
   uint32_t unk_278;
   uint32_t unk_27C;
   uint32_t unk_280;
   uint32_t unk_284;
   uint32_t unk_288;
   uint32_t unk_28C;
   uint32_t unk_290;
   uint32_t unk_294;
   uint32_t unk_298;
   uint32_t unk_29C;
   uint32_t unk_2A0;
   uint32_t unk_2A4;
   uint32_t unk_2A8;
   uint32_t unk_2AC;
   uint32_t unk_2B0;
   uint32_t unk_2B4;
   uint32_t unk_2B8;
   uint32_t unk_2BC;
   uint32_t unk_2C0;
   uint32_t unk_2C4;
   uint32_t unk_2C8;
   uint32_t unk_2CC;
   uint32_t unk_2D0;
   uint32_t unk_2D4;
   uint32_t unk_2D8;
   uint32_t unk_2DC;
   uint32_t unk_2E0;
   uint32_t unk_2E4;
   uint32_t unk_2E8;
   uint32_t unk_2EC;
   uint32_t unk_2F0;
   uint32_t unk_2F4;
   uint32_t unk_2F8;
   uint32_t unk_2FC;

   uint32_t unk_300;
   uint32_t unk_304;
   uint32_t unk_308;
   uint32_t unk_30C;
   uint32_t unk_310;
   uint32_t unk_314;
   uint32_t unk_318;
   uint32_t unk_31C;
   uint32_t unk_320;
   uint32_t unk_324;
   uint32_t unk_328;
   uint32_t unk_32C;
   uint32_t unk_330;
   uint32_t unk_334;
   uint32_t unk_338;
   uint32_t unk_33C;
   uint32_t unk_340;
   uint32_t unk_344;
   uint32_t unk_348;
   uint32_t unk_34C;
   uint32_t unk_350;
   uint32_t unk_354;
   uint32_t unk_358;
   uint32_t unk_35C;
   uint32_t unk_360;
   uint32_t unk_364;
   uint32_t unk_368;
   uint32_t unk_36C;
   uint32_t unk_370;
   uint32_t unk_374;
   uint32_t unk_378;
   uint32_t unk_37C;
   uint32_t unk_380;
   uint32_t unk_384;
   uint32_t unk_388;
   uint32_t unk_38C;
   uint32_t unk_390;
   uint32_t unk_394;
   uint32_t unk_398;
   uint32_t unk_39C;
   _8BF5F8_global_2* unk_3A0;
};

struct _8BF5F8_global_0
{
   _8BF5F8_global_1* unk_0;
};

_8BF5F8_global_2 _8BF5F8_g2[3];
_8BF5F8_global_1 _8BF5F8_g1;
_8BF5F8_global_0 _8BF5F8_g0;

//modifies input arg1
int SceSblGcAuthMgr_SceSysrootForKernel_imp_f10ab792(int arg0, f10ab792_input* arg1)
{
   if(arg0 > 2) // looks like there can be only 3 elements in the array
      return 0x80020005;

   if(arg1 == 0)
      return 0x80020006;

   if(arg1->size != 0x0C) //must be 0x0C
      return 0x80020009;

   _8BF5F8_global_0* g0 = &_8BF5F8_g0;
   _8BF5F8_global_1* g1 = g0->unk_0;
   _8BF5F8_global_2* g2 = g1->unk_3A0;

   if(g2 == 0)
      return 0x8001000C;

   //this part looked differently originally, however it was obvious that it was an array access where array elements are of size 0x08

   if(g2[arg0].unk_4 == 0)
      return 0x80010002;

   arg1->unk_4_var970 = g2[arg0].unk_0;
   arg1->unk_8_var96C = g2[arg0].unk_4;
   
   return 0;
}

//assume - init
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1)
{
   //TODO: imitating size change and encryption - need to figure out what is going on here

   switch(ctx->command)
   {
   case CAC924_COMMAND_1B:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1C:
      ctx->size = 0x33;  // 0x40 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1D:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1E:
      ctx->size = 0x33;  //0x51 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1F:
      ctx->size = 0x20;  //0xB3 -> 0x20
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_20:
      ctx->size = 0x34; //0x116 -> 0x34
      memset(ctx->data, 0xBB, ctx->size);
      break;
   }

   return 0;
}

//assume - gen/hash
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0)
{
   return 0;
}

//assume - deinit
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(int unk)
{
   return 0;
}

//=========================================

//NON CRITICAL

//assume - some thread init
int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_3c8b55a9(int un0, int unk1, int unk2)
{
   return 0;
}

//assume - some sort of deinit
int SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83()
{
   return 0;
}

//assume - some thread deinit
int SceSblGcAuthMgr_SceThreadmgrForDriver_imp_d270498b(int unk0, int unk1)
{
   return 0;
}

//this is user space signature for the function
//SceInt64 sceKernelGetSystemTimeWide(void);
//I would assume that it returns the same value in kernel as well

//TODO: this is just an imitation - I do not know what time format is used in vita (though I assume it is this format)

sce_time SceSblGcAuthMgr_SceThreadmgrForDriver_imp_sceKernelGetSystemTimeWideForDriver_f4ee4fa9()
{
   typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> time_stamp;
   
   time_stamp timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
   std::chrono::duration<int64_t, std::micro> duration = timestamp.time_since_epoch();
   int64_t count = duration.count();
   
   sce_time scetime;
   scetime.value = (uint64_t)count;
         
   return scetime;
}

//initializes some globals

void InitializeUnknownContext()
{
   //TODO: figure out how this is initialized in reality
   _8BF5F8_g0.unk_0 = &_8BF5F8_g1;
   _8BF5F8_g1.unk_3A0 = _8BF5F8_g2;

   _8BF5F8_g2[0].unk_0 = 0xFFFFFFFF;
   _8BF5F8_g2[0].unk_4 = 0xFFFFFFFF;
   
   _8BF5F8_g2[1].unk_0 = 0xDDDDDDDD;
   _8BF5F8_g2[1].unk_4 = 0xDDDDDDDD;

   _8BF5F8_g2[2].unk_0 = 0xAAAAAAAA;
   _8BF5F8_g2[2].unk_4 = 0xAAAAAAAA;
}