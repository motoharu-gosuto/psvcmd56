#include "SceKernelUtils.h"

#include "sha1.h"

int SceKernelUtilsForDriver_sceSha1DigestForDriver_87dc7f2f(const unsigned char *source, uint32_t size, unsigned char result[0x14])
{
   sha1(source, size, result);

   return 0;
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const unsigned char* key, uint32_t key_len, const unsigned char* data, uint32_t data_len, unsigned char digest[0x14])
{
   sha1_hmac(key, key_len, data, data_len, digest);

   return 0;
}

int SceKernelUtilsForDriver_sceAesInit2ForDriver_eda97d6d(void *ctx, uint32_t blocksize, uint32_t keysize, const unsigned char *key)
{
   return 0;
}

int SceKernelUtilsForDriver_sceAesEncrypt2ForDriver_302947b6(void* ctx, const unsigned char* src, unsigned char* dst)
{
   return 0;
}

int SceKernelUtilsForDriver_sceSha224DigestForDriver_9ea9d4dc(unsigned char* source, int size, unsigned char* result)
{
   return 0;
}

int SceKernelUtilsForDriver_sceAesInit1ForDriver_f12b6451(aes_ctx* ctx, int blocksize, int keysize, const unsigned char* key)
{
   return 0;
}

int SceKernelUtilsForDriver_sceAesDecrypt1ForDriver_d8678061(aes_ctx* ctx, const unsigned char* src, unsigned char* dst)
{
   return 0;
}