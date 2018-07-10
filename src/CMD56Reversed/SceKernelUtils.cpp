#include "SceKernelUtils.h"

#include <stdexcept>

#include "Crypto/CryptoService.h""


int SceKernelUtilsForDriver_sceSha1DigestForDriver_87dc7f2f(const unsigned char *source, uint32_t size, unsigned char result[0x14])
{
   auto cryptops = CryptoService::get();
   cryptops->sha1(source, result, size);
   return 0;
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const unsigned char* key, uint32_t key_len, const unsigned char* data, uint32_t data_len, unsigned char digest[0x14])
{
   auto cryptops = CryptoService::get();
   cryptops->hmac_sha1(data, digest, data_len, key, key_len);
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
   throw std::runtime_error("Not implemented");

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