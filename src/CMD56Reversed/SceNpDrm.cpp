#include <string>
#include <stdint.h>


void loc_1D37F94()
{
   int r4 = 0x1C8D680;
   var_260 = r4;

   int r0 = r4[0x00];
   int r1 = r4[0x04];
   int r2 = r4[0x08];
   int r3 = r4[0x0C];

   r11[0x00] = r0;
   r11[0x04] = r1;
   r11[0x08] = r2;
   r11[0x0C] = r3;
}

void get_rif_key_1D37B48_part()
{
   int r1 = 0x100;
   int r5 = 0x1C8D680
   int r0 = r5;
   unk0 = r5;

   memset(r0, 0, r1);
   
   int r3 = rif_data+0xA0;

   int r0 = r3[0x00]
   int r1 = r3[0x04]
   int r2 = r3[0x08]
   int r3 = r3[0x0C]

   r5[0x00] = r0;
   r5[0x04] = r1;
   r5[0x08] = r2;
   r5[0x0C] = r3;

   int r0 = 1C8D680;
   int r0 = r0 + 0x60;
   int r1 = rif_data;
   int r2 = 0x70;

   memcpy(r0, r1, r2);

   if(r7 == 0)
   {
      int r4 = value; //byte of rif_lic_flags

      if(r4 == 0xD)
      {
         arg_0 = R7;
         int r4 = unk0;
         int r5 = 0x1C8C030;

         int r0 = r5[0x00];
         int r1 = r5[0x04];
         int r2 = r5[0x08];
         int r3 = r5[0x0C];
         r5 = r5 + 0x10;

         int r4 = r4 + 0x40;

         r4[0x00] = r0;
         r4[0x04] = r1;
         r4[0x08] = r2;
         r4[0x0C] = r3;
         r4 = r4 + 0x10;
         
         var_25C = r5;

         int r0 = r5[0x00];
         int r1 = r5[0x04];
         int r2 = r5[0x08];
         int r3 = r5[0x0C];

         r4[0x00] = r0;
         r4[0x04] = r1;
         r4[0x08] = r2;
         r4[0x0C] = r3;

         r2 = r4 - 0x10;
         r0 = unk0;
         r1 = 0x10;
         r3 = 0x90;

         sceSblAuthMgrDecBindData_41daea12(r0,r1,r2,r3,arg_0);

         if(r0 < 0)
         {
            //loc_1D3802A
         }
         else
         {
            //goto loc_1D37F94
         }
      }
      else
      {
         int r4 = unk0;
         int r5 = r4 - 0x870;
         int r4 = r4 + 0x40;

         int r0 = r5[0x00];
         int r1 = r5[0x04];
         int r2 = r5[0x08];
         int r3 = r5[0x0C];
         r5 = r5 + 0x10;

         r4[0x00] = r0;
         r4[0x04] = r1;
         r4[0x08] = r2;
         r4[0x0C] = r3;
         r4 = r4 + 0x10;

         int r0 = r5[0x00];
         int r1 = r5[0x04];
         int r2 = r5[0x08];
         int r3 = r5[0x0C];

         r4[0x00] = r0;
         r4[0x04] = r1;
         r4[0x08] = r2;
         r4[0x0C] = r3;

         int r0 = 01C8D680;
         int r3 = 0;
         arg_0 = r3;

         int r2 = r0 + 0x40;
         r1 = 0x10;
         r3 = 0x90;

         sceSblAuthMgrDecBindData_41daea12(r0,r1,r2,r3,arg_0);

         if(r0 < 0)
         {
            //goto loc_1D3802A
         }
         else
         {
            //goto loc_1D37F94
         }
      }
   }
   else
   {
      int r7 = cmd56_handshake;
      int r5 = unk0;

      int r0 = r7[0x00];
      int r1 = r7[0x04];
      int r2 = r7[0x08];
      int r3 = r7[0x0C];
      r7 = r7 + 0x10;

      int r5 = r5 + 0x40;

      r5[0x00] = r0;
      r5[0x04] = r1;
      r5[0x08] = r2;
      r5[0x0C] = r3;
      r5 = r5 + 0x10;

      int r0 = r7[0x00];
      int r1 = r7[0x04];
      int r2 = r7[0x08];
      int r3 = r7[0x0C];

      r5[0x00] = r0;
      r5[0x04] = r1;
      r5[0x08] = r2;
      r5[0x0C] = r3;

      if(r4 == 0)
      {
         int r0 = 01C8D680;
         int r3 = 0;
         arg_0 = r3;

         int r2 = r0 + 0x40;
         r1 = 0x10;
         r3 = 0x90;

         sceSblAuthMgrDecBindData_41daea12(r0,r1,r2,r3,arg_0);

         if(r0 < 0)
         {
            //goto loc_1D3802A
         }
         else
         {
            //goto loc_1D37F94
         }
      }
      else
      { 
         int r4 = unk0;
         int r5 = unk0;

         int r4 = r4 + 0xB0;

         int r0 = r4[0x00];
         int r1 = r4[0x04];
         int r2 = r4[0x08];
         int r3 = r4[0x0C];

         r5[0x00] = r0;
         r5[0x04] = r1;
         r5[0x08] = r2;
         r5[0x0C] = r3;

         int r0 = r4;
         int r1 = 0x10;
         memset(r0, 0, r1);
         
         int r0 = 01C8D680;
         int r3 = 0;
         arg_0 = r3;

         int r2 = r0 + 0x40;
         r1 = 0x10;
         r3 = 0x90;

         sceSblAuthMgrDecBindData_41daea12(r0,r1,r2,r3,arg_0);

         if(r0 < 0)
         {
            //goto loc_1D3802A
         }
         else
         {
            //goto loc_1D37F94
         }
      }
   }
}