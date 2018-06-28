#include "SceKernelUtils.h"

#include "sha1.h"

int SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(const unsigned char *source, uint32_t size, unsigned char result[0x14])
{
   sha1(source, size, result);

   return 0;
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const unsigned char* key, uint32_t key_len, const unsigned char* data, uint32_t data_len, unsigned char digest[0x14])
{
   sha1_hmac(key, key_len, data, data_len, digest);

   return 0;
}

int SceKernelUtilsForDriver_aes_init_2_eda97d6d(void *ctx, uint32_t blocksize, uint32_t keysize, const unsigned char *key)
{
   return 0;
}

int SceKernelUtilsForDriver_aes_encrypt_2_302947b6(void* ctx, const unsigned char* src, unsigned char* dst)
{
   return 0;
}

int SceKernelUtilsForDriver_29a28957(const unsigned char* key, uint32_t key_len, const unsigned char* data, uint32_t data_len, unsigned char digest[0x14])
{
   //this function is powered by table of function pointers that are called indirectly

   //wrapper for sub_9DD908

   //SceSysmem.SceKernelUtilsForDriver._exp_87dc7f2f
   //SceSysmem.SceKernelUtilsForDriver._exp_e4390ffa
   //SceSysmem.SceKernelUtilsForDriver._exp_478a6f3c
   //SceSysmem.SceKernelUtilsForDriver._exp_48f24106

   return 0;
}

int SceKernelUtilsForDriver_ksceSha224Digest_9ea9d4dc(char* source, int size, char* result)
{
   return 0;
}

int SceKernelUtilsForDriver_aes_init_f12b6451(aes_ctx* ctx, int blocksize, int keysize, const uint8_t* key)
{
   return 0;
}

int SceKernelUtilsForDriver_aes_decrypt_d8678061(aes_ctx* ctx, const char* src, char* dst)
{
   return 0;
}