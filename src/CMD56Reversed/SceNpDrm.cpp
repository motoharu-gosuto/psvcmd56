#include <string>
#include <stdint.h>

int sceSblAuthMgrDecBindData_41daea12(void *buffer, int num1, void *keypair, int num2, void *arg_0)
{
   return 0;
}

typedef struct dec_buffer
{
   char rif_key[0x10];      //0x00
   char unk0[0x30];         //0x10
   char primary_keys[0x20]; //0x40
   char rif_data[0x70];     //0x60
   char unk1[0x30];         //0xD0
}dec_buffer;

//0x1C8D680 - decbuf
//20 + 70 = rif data

//static_keys 0x1C8C010

void get_rif_key_1D37B48_part(const char* act_data, const char* static_keys, const char* rif_data, const char* cmd56_handshake, char* klicensee)
{
   dec_buffer decbuf;

   memset(&decbuf, 0, 0x100);
   
   memcpy(decbuf.rif_key, rif_data + 0xA0, 0x10);

   memcpy(decbuf.rif_data, rif_data, 0x70);

   if(r7 == 0)
   {
      int r4 = value; //byte of rif_lic_flags

      if(r4 == 0xD)
      {
         memcpy(decbuf.primary_keys, static_keys + 0x20, 0x20); //keys 3 and 4

         int r0 = sceSblAuthMgrDecBindData_41daea12(decbuf.rif_key, 0x10, decbuf.primary_keys, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, decbuf.rif_key, 0x10);
      }
      else
      {
         memcpy(decbuf.primary_keys, act_data + 0x10, 0x20); //primary keys 1 and 2

         int r0 = sceSblAuthMgrDecBindData_41daea12(decbuf.rif_key, 0x10, decbuf.primary_keys, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, decbuf.rif_key, 0x10);
      }
   }
   else
   {
      memcpy(decbuf.primary_keys, cmd56_handshake, 0x20);

      if(r4 == 0)
      {
         int r0 = sceSblAuthMgrDecBindData_41daea12(decbuf.rif_key, 0x10, decbuf.primary_keys, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, decbuf.rif_key, 0x10);
      }
      else
      { 
         memcpy(decbuf.rif_key, decbuf.rif_data + 0x50, 0x10); //rif key

         memset(decbuf.rif_data + 0x50, 0, 0x10); //clear rif key
         
         int r0 = sceSblAuthMgrDecBindData_41daea12(decbuf.rif_key, 0x10, decbuf.primary_keys, 0x90, 0);

         if(r0 < 0)
            memset(klicensee, 0, 0x10);
         else
            memcpy(klicensee, decbuf.rif_key, 0x10);
      }
   }
}