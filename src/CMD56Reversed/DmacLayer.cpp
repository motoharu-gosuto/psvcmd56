#include <string>

#include "DmacLayer.h"

int SceKernelDmacMgr_SceIntrmgrForDriver_imp_182ee3e3(int r0)
{
   return 0;
}

struct global_008FE000
{
   int unk_00;
   int unk_04;
   int unk_08;
   int unk_0C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
};

result_c8672a3d* SceKernelDmacMgr_SceSysmemForKernel_imp_c8672a3d(int unk0)
{
   return 0;
}

int SceKernelDmacMgr_SceSysmemForKernel_imp_571660aa(int r0, int r1)
{
   return 0;
}

int SceKernelDmacMgr_SceThreadmgrForDriver_imp_4336baa4(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceKernelDmacMgr_SceSysmemForDriver_imp_e655852f(int unk0)
{
   return 0;
}

int SceKernelDmacMgr_SceCpuForDriver_imp_lock_int_d32ace9e(int *addr)
{
   return 0;
}

int SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(int *addr, int prev_state)
{
   return 0;
}

//==========================================================================

struct result_c8672a3d
{
   int unk_00;
   int unk_04;
   int unk_08;
   int unk_0C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
   int unk_30;
   int unk_34;
   int unk_38;
   int unk_3C;
};

global_008FE000 _008FE000;
char* unk_994808 = "SceDmacDefault";

int _008FE278;

int _008FE02C;

int _008FE060;

int _008FE254;

//==========================================================================

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_7cd5088a(const char* name)
{
   int r0 = name;
   int r6 = r0;
   int r0 = SceKernelDmacMgr_SceIntrmgrForDriver_imp_182ee3e3(r0);
   if(r0 != 0)
      return 0x80027101;

   global_008FE000* r5 = &_008FE000;
   int r3 = unk_994808;
   int r0 = r5->unk_20;

   if(r6 == 0)
      r6 = r3;
   result_c8672a3d* r0 = SceKernelDmacMgr_SceSysmemForKernel_imp_c8672a3d(r0);
   result_c8672a3d* r4 = r0;
   if(r0 == 0)
      return 0x8002710B;

   int r3 = r0 >> 1;
   int r1 = r7;
   int r2 = 0x30;
   int r8 = r3 | 0x01;
   memset(r0, r1, r2);
   int r1 = r7;
   int r7 = r5 | 0x01;
   int r0 = r6;
   int r2 = r1;
   int r3 = r1;
   r4->unk_30 = r7;
   int r0 = SceKernelDmacMgr_SceThreadmgrForDriver_imp_4336baa4(r0, r1, r2, r3);
   int r6 = r0 - 0;
   if(r6 < 0)
   {
      int r0 = r5->unk_20;
      int r1 = r4;
      int r0 = SceKernelDmacMgr_SceSysmemForKernel_imp_571660aa(r0, r1);
      int r0 = r6;
      return r0;
   }

   int r6 = r4->unk_34;
   int r0 = SceKernelDmacMgr_SceSysmemForDriver_imp_e655852f(r0);
   int r3 = 0x01;
   r4->unk_3C = r0;
   r4->unk_38 = r3;
   int r0 = r8;
   return r0;
}

//==========================================================================

//TODO: MARK KNOWN ERRORS WITH CONSTANTS

int exit_loc_992EAC()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027201; //SCE_KERNEL_ERROR_ALREADY_QUEUED
   return r0;
}

//default case
int exit_loc_992EC2()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80020005; //SCE_KERNEL_ERROR_INVALID_FLAGS
   return r0;
}

int exit_loc_992ED6()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027207; //SCE_KERNEL_ERROR_NOT_UNDER_CONTROL
   return r0;
}

int exit_loc_992EE8()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027205; //SCE_KERNEL_ERROR_NOT_INITIALIZED
   return r0;
}

int exit_loc_992EFA()
{
   int r0 = r6;
   int r1 = r2;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0x80027208; //SCE_UNKNOWN_ERROR_80027208
   return r0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_fce4171a(void* unk0, int unk1, int unk2, int unk3)
{
   int r0 = r0 >> 1;
   int r5 = _008FE000;
   int r4 = r0 << 2;
   int r0 = r5 | 1;
   int r3 = r4[0x30]
   //SUB		SP, SP,	#0xC

   int r10 = r1;
   int r11 = r2;

   if(r3 != r0)
      return 0x80020005;

   int r6 = r4 + 0x2C;
   int r0 = r6;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_lock_int_d32ace9e(r0);
   int r3 = r4[0x38];
   int r2 = r0;
   int r0 = r3 << 0x1F;
   if(true) //BPL
      return exit_loc_992EE8();

   int r3 = r4[0x38];
   int r1 = r3 << 0x1C;
   if(true) //BMI
      return exit_loc_992EAC();

   int r3 = r4[0x14];
   if(r3 != 0)
      return exit_loc_992EAC();

   int r3 = r4[0x38];
   int r3 = r3 << 0x19;
   if(true) //BMI
      return exit_loc_992EFA();

   int r3 = r10 - 0x10;
   if(r3 > 0x04)
      return exit_loc_992EC2();

   //this are not exactly switch constants - just imitation for now
   switch(r3)
   {
   case 20: // loc_992E32
      {
         int r3 = r5[0x18];
         if(r3 == 0)
            return exit_loc_992EC2();

         int r3 = var2C;
         int r3 = &_008FE278;
         int r7 = r3;
         var2C = r3;
         r4[0x10] = r3;
      }
      break;
   case 0: //loc_992E6C
      {
         int r9 = &_008FE02C;
         r4[0x10] = r9;
         int r7 = r9;
      }
   case 0: //loc_992E7C
      {
         int r8 = &_008FE060;
         r4[0x10] = r4;
         int r7 = r8;
      }
      break;
   case 18: //loc_992E8C
      {
         if(r11 > 0x0F)
            return exit_loc_992EC2();
         //RSB.W		R11, R11, R11,LSL#3
         int r7 = r5 + (r1 << 2);
         int r7 = r7 + 0x94;
         r4[0x10] = r7;
      }
      break;
   case 0: //loc_992E48
      {
         int r7 = _008FE254;
         r4[0x10] = 74;
      }
      break;
   }
  
	int r3 = r7[0x10];
   if(r3 == 0)
      return exit_loc_992ED6();

   int r5 = r4[0x38];
   int r3 = 0xFFDF;
   int r0 = r6;
   r4[0x3A] = r10;
   int r1 = r2;
   int r3 = r3 & r5;
   r4[0x34] = r3;
   int r0 = SceKernelDmacMgr_SceCpuForDriver_imp_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0;

   return r0;
}

//==========================================================================

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_01a599e0(int unk0, int unk1, int unk2)
{
   return 0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_543f54cf(int unk0)
{
   return 0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_397a917c(int unk0, int unk1, int unk2, int unk3)
{
   return 0;
}

int SceKernelDmacMgr_SceDmacmgrForDriver_exp_adff1186(int unk)
{
   return 0;
}