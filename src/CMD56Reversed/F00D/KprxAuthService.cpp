#include "KprxAuthService.h"

using namespace f00d;

char key0_81277C[0x10] = {0xE1, 0x22, 0x13, 0xB4, 0x80, 0x16, 0xB0, 0xE9, 0x9A, 0xB8, 0x1F, 0x8E, 0xC0, 0x2A, 0xD4, 0xA2};

char key1_81279C[0x20] = {0xA9, 0xFA, 0x5A, 0x62, 0x79, 0x9F, 0xCC, 0x4C, 0x72, 0x6B, 0x4E, 0x2C, 0xE3, 0x50, 0x6D, 0x38, 
                          0xF4, 0xF2, 0xD0, 0x15, 0x5D, 0xB9, 0x13, 0xCD, 0xE4, 0x52, 0xE4, 0xB5, 0x4A, 0xB7, 0x5F, 0x4A};

char key2_8127BC[0x40] = {0xB5, 0xD8, 0x51, 0x12, 0xFE, 0xDF, 0xC9, 0xFD, 0x25, 0xE7, 0xD1, 0xDB, 0x85, 0x8D, 0x76, 0xFD, 
                          0x04, 0x1A, 0xFE, 0xDB, 0x58, 0x2B, 0xEB, 0xB9, 0xA5, 0xE1, 0x67, 0xF3, 0xFD, 0xDD, 0x2E, 0x8E, 
                          0x90, 0x1A, 0x84, 0xFB, 0x13, 0xA7, 0x44, 0xA3, 0x78, 0xC5, 0x01, 0x8A, 0x60, 0xF5, 0x8C, 0x22, 
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

char key3_8127FC[0x20] = {0x61, 0x6F, 0xAD, 0xDF, 0x22, 0x04, 0xAC, 0x7A, 0x24, 0x06, 0x4C, 0xCE, 0xD8, 0xCD, 0x88, 0xA0, 
                          0xDE, 0x07, 0xF0, 0x15, 0x43, 0x45, 0x32, 0x7D, 0xBE, 0x4D, 0x49, 0xE1, 0xCA, 0x87, 0x5D, 0x98};

char key4_81281C[0x20] = {0x5E, 0xF0, 0xE4, 0xAB, 0x2A, 0xCE, 0x26, 0x69, 0x00, 0x96, 0xD9, 0x48, 0xD4, 0xC0, 0x1B, 0x36, 
                          0x8B, 0xB0, 0xB2, 0x1D, 0x45, 0x72, 0x7D, 0x70, 0x91, 0x26, 0xF4, 0xA1, 0x10, 0x77, 0x0C, 0xF9};

//some scrambling
int sub_8102BC(char* ptr, int value, int size)
{
   return 0;
}

//key_id 0x00010001 DMAC5 specific setup
int sub_80D318()
{
   return 0;
}

int aes_128_ecb_decrypt_iv_0_80F0A8(char* dst, char* src, int key_size, char* key)
{
   return 0;
}

int aes_128_cbc_encrypt_80F226(char* dst, char* src, int key_size, char* key, char* iv)
{
   return 0;
}

int memcpy_dmac_80F434(char* dst, char* src, int size)
{
   return 0;
}

int sha256_80F2B8(char* dst, char* src, int size)
{
   return 0;
}

int sub_80E162(char* dst, int key_size, char* key)
{
   aes_128_ecb_decrypt_iv_0_80F0A8(dst, dst, key_size, key);

   return 0;
}

int sub_80E43E(char* key1, int key_size, char* key2, char* key3)
{
   char iv_copy[0x10];

   memcpy_dmac_80F434(iv_copy, key3, 0x10);

   aes_128_cbc_encrypt_80F226(key1, key1, key_size, key2, iv_copy);

   return 0;
}

int sub_80E4CC(char* key1, int key_size, char* key2, char* key3)
{
   char iv_copy[0x10];

   memcpy_dmac_80F434(iv_copy, key3, 0x10);

   char sha256[0x20];

   sha256_80F2B8(sha256, key1, 0x20);

   aes_128_cbc_encrypt_80F226(key1, sha256, key_size, key2, iv_copy);

   return 0;
}

int set_dmac5_key_80E26A(char* key, int nblocks, int slot)
{
   return 0;
}


int KprxAuthService::service_0x50001(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommKprxAuthData_50001* ctx_cast = (SceSblSmCommKprxAuthData_50001*)ctx;

   char key_dest[0x20];

   //check that size is aligned

   if((ctx_cast->key_size & 0xF) != 0)
   {
      *f00d_resp = 0x800F0016;
      return -1;
   }

   //check slot id

   if(ctx_cast->slot_id < 0xC || ctx_cast->slot_id > 0x17)
   {
      *f00d_resp = 0x800F0016;
      return -1;
   }

   // do some scrambling - result lost after memcpy ?

   int reg0 = sub_8102BC(key_dest, 0, 0x20);

   //execute command

   if(ctx_cast->key_size <= 0 || ctx_cast->key_size > 0x20)
   {
      *f00d_resp = 0x800F0016;
      return -1;
   }
      
   memcpy(key_dest, ctx_cast->key, ctx_cast->key_size);

   //execute command according to specific key id

   switch(ctx_cast->key_id)
   {
   case 0x00000000:
      {
         *f00d_resp = sub_80E162(key_dest, ctx_cast->key_size, key0_81277C); //probably crypto
         if(*f00d_resp == 0)
            *f00d_resp = set_dmac5_key_80E26A(key_dest, ctx_cast->key_size / 4, ctx_cast->slot_id);
      }
      break;
   case 0x00010000:
      {
         *f00d_resp = sub_80E162(key_dest, ctx_cast->key_size, key1_81279C); //probably crypto
         if(*f00d_resp == 0)
            *f00d_resp = set_dmac5_key_80E26A(key_dest, ctx_cast->key_size / 4, ctx_cast->slot_id);
      }
      break;
   case 0x00010001:
      {
         int reg0 = sub_80D318(); // some dmac setup
         if(reg0 == 0)
         {
            *f00d_resp = 0x800F0016;
            return -1;
         }

         *f00d_resp = sub_80E162(key_dest, ctx_cast->key_size, key2_8127BC); //probably crypto
         if(*f00d_resp == 0)
            *f00d_resp = set_dmac5_key_80E26A(key_dest, ctx_cast->key_size / 4, ctx_cast->slot_id);
      }
      break;
   case 0x00020000:
      {
         *f00d_resp = sub_80E43E(key_dest, ctx_cast->key_size, key3_8127FC, key3_8127FC + 0x10); //probably crypto
         if(*f00d_resp == 0)
            *f00d_resp = set_dmac5_key_80E26A(key_dest, ctx_cast->key_size / 4, ctx_cast->slot_id);
      }
      break;
   case 0x00020001:
      {
         *f00d_resp = sub_80E4CC(key_dest, ctx_cast->key_size, key4_81281C, key4_81281C + 0x20); //probably crypto
         if(*f00d_resp == 0)
            *f00d_resp = set_dmac5_key_80E26A(key_dest, ctx_cast->key_size / 4, ctx_cast->slot_id);
      }
      break;
   default:
      {
         *f00d_resp = 0x800F0016;
         return -1;
      }
      break;
   }

   return 0;
}

int KprxAuthService::service_0x60001(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommKprxAuthData_50001* ctx_cast = (SceSblSmCommKprxAuthData_50001*)ctx;

   char key_dest[0x20];

   //check that size is aligned

   if((ctx_cast->key_size & 0xF) != 0)
   {
      *f00d_resp = 0x800F0016;
      return -1;
   }

   //check slot id

   if(ctx_cast->slot_id < 0xC || ctx_cast->slot_id > 0x17)
   {
      *f00d_resp = 0x800F0016;
      return -1;
   }

   // do some scrambling - result lost after memcpy ?

   int reg0 = sub_8102BC(key_dest, 0, 0x20);

   //execute command

   memset(key_dest, 0, 0x20);

   *f00d_resp = set_dmac5_key_80E26A(key_dest, 0x20 / 4, ctx_cast->slot_id);

   return 0;
}

int KprxAuthService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case KPRX_AUTH_SERVICE_50001:
      return service_0x50001(f00d_resp, ctx, size);
   case KPRX_AUTH_SERVICE_60001:
      return service_0x60001(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = 0x800F0016;
      return -1;
   }
}