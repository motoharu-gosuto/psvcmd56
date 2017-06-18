#include <string>
#include <stdint.h>

int sceSblAuthMgrDecBindData_41daea12(void *buffer, int num1, void *keypair, int num2, void *arg_0)
{
   return 0;
}

void get_rif_key_1D37B48_part(char* klicensee)
{
   memset(0x1C8D680, 0, 0x100);
   
   memcpy(0x1C8D680, rif_data + 0xA0, 0x10);

   memcpy(1C8D680 + 0x60, rif_data, 0x70);

   if(r7 == 0)
   {
      int r4 = value; //byte of rif_lic_flags

      if(r4 == 0xD)
      {
         memccpy(0x1C8D680 + 0x40, 0x1C8C030, 0x20);

         int r0 = sceSblAuthMgrDecBindData_41daea12(0x1C8D680, 0x10, 0x1C8D680 + 0x40, 0x90, 0);

         if(r0 < 0)
            memset(r11, 0, 0x10);
         else
            memcpy(r11, 0x1C8D680, 0x10);
      }
      else
      {
         memcpy(0x1C8D680 + 0x40, 0x1C8D680 - 0x870, 0x20);

         int r0 = sceSblAuthMgrDecBindData_41daea12(01C8D680, 0x10, 01C8D680 + 0x40, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, 0x1C8D680, 0x10);
      }
   }
   else
   {
      memcpy(0x1C8D680 + 0x40, cmd56_handshake, 0x20);

      if(r4 == 0)
      {
         int r0 = sceSblAuthMgrDecBindData_41daea12(01C8D680, 0x10, 01C8D680 + 0x40, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, 0x1C8D680, 0x10);
      }
      else
      { 
         memcpy(0x1C8D680, 0x1C8D680 + 0xB0, 0x10);

         memset(0x1C8D680 + 0xB0, 0, 0x10);
         
         int r0 = sceSblAuthMgrDecBindData_41daea12(01C8D680, 0x10, 01C8D680 + 0x40, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, 0x1C8D680, 0x10);
      }
   }
}