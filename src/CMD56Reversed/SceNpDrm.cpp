#include "SceNpDrm.h"

#include "SceSblAuthMgr.h"

#include <string>
#include <stdint.h>

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

int dec_rif_key(dec_buffer* decbuf, char* klicensee)
{
   int r0 = SceSblAuthMgr_sceSblAuthMgrDecBindDataForDriver_41daea12(decbuf->rif_key, 0x10, decbuf->primary_keys, 0x90, 0);

   if(r0 < 0)
      memset(klicensee, 0, 0x10);
   else
      memcpy(klicensee, decbuf->rif_key, 0x10);

   return 0;
}

void get_rif_key_1D37B48_part(const char* act_data, const char* static_keys, const char* rif_data, const char* cmd56_handshake, int lic_flag, int lic_derived_flag, int onfly_bit11, char* klicensee)
{
   dec_buffer decbuf;

   memset(&decbuf, 0, 0x100);
   
   memcpy(decbuf.rif_data, rif_data, 0x70);

   if(onfly_bit11 == 0)
   {
      if(lic_flag == 0xD)
      {
         memcpy(decbuf.primary_keys, static_keys + 0x20, 0x20); //keys 3 and 4

         memcpy(decbuf.rif_key, rif_data + 0xA0, 0x10);

         dec_rif_key(&decbuf, klicensee);
      }
      else
      {
         memcpy(decbuf.primary_keys, act_data + 0x10, 0x20); //primary keys 1 and 2

         memcpy(decbuf.rif_key, rif_data + 0xA0, 0x10);

         dec_rif_key(&decbuf, klicensee);
      }
   }
   else
   {
      if(lic_derived_flag == 0)
      {
         memcpy(decbuf.primary_keys, cmd56_handshake, 0x20);

         memcpy(decbuf.rif_key, rif_data + 0xA0, 0x10);

         dec_rif_key(&decbuf, klicensee);
      }
      else
      { 
         memcpy(decbuf.primary_keys, cmd56_handshake, 0x20);

         memcpy(decbuf.rif_key, decbuf.rif_data + 0x50, 0x10); //rif key

         memset(decbuf.rif_data + 0x50, 0, 0x10); //clear rif key
         
         dec_rif_key(&decbuf, klicensee);
      }
   }
}