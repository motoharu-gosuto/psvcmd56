#include "RmAuthService.h"

#include "SceSblDMAC5DmacKRBase.h"

#include "Crypto/CryptoService.h"

//this service is implemented with the reversing help provided by xerpi

using namespace f00d;

const unsigned char key0[0x10] = {0xD4, 0x19, 0xA2, 0xEB, 0x9D, 0x61, 0xA5, 0x2F, 0x4F, 0xA2, 0x8B, 0x27, 0xE3, 0x2F, 0xCD, 0xD7};
const unsigned char key1[0x10] = {0xE0, 0x04, 0x8D, 0x44, 0x3D, 0x63, 0xC9, 0x2C, 0x0B, 0x27, 0x13, 0x55, 0x41, 0xD9, 0x2E, 0xC4};

int RmAuthService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommRmAuthData_1* ctx_cast = (SceSblSmCommRmAuthData_1*)ctx;

   //other bytes are untouched
   memset(ctx_cast->data + 0x10, 0, 4);

   *f00d_resp = 0;

   return 0;
}

int RmAuthService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommRmAuthData_2* ctx_cast = (SceSblSmCommRmAuthData_2*)ctx;

   unsigned char seed_trunc[0x10];
   
   memcpy(seed_trunc, ctx_cast->seed, 0x10);

   unsigned char iv[0x10];

   memset(iv, 0, 0x10);

   unsigned char outkey[0x20];

   //invoke crypto operation
   auto cryptops = CryptoService::get();
   if(cryptops->aes_cbc_encrypt(seed_trunc, outkey, 0x10, key0, 0x80, iv) < 0)
      return -1;

   memset(iv, 0, 0x10);

   if(cryptops->aes_cbc_encrypt(seed_trunc, outkey + 0x10, 0x10, key1, 0x80, iv) < 0)
      return -1;

   SceSblDMAC5DmacKRBase::set_key_unrestricted(outkey, 0x20, 0x1C);

   return 0;
}

int RmAuthService::service_0x3(int* f00d_resp, void* ctx, int size) const
{
   unsigned char key[0x20];
   memset(key, 0, 0x20);

   SceSblDMAC5DmacKRBase::set_key_unrestricted(key, 0x20, 0x1C);

   return 0;
}

int RmAuthService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case RMAUTH_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case RMAUTH_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   case RMAUTH_SERVICE_3:
      return service_0x3(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}