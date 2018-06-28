#pragma once

#include <stdint.h>

typedef struct aes_ctx
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   char data[950]; //not sure about size
}aes_ctx;

int SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(const unsigned char *source, uint32_t size, unsigned char result[0x14]);

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const unsigned char* key, uint32_t key_len, const unsigned char* data, uint32_t data_len, unsigned char digest[0x14]);

int SceKernelUtilsForDriver_aes_init_2_eda97d6d(void *ctx, uint32_t blocksize, uint32_t keysize, const unsigned char *key);

int SceKernelUtilsForDriver_aes_encrypt_2_302947b6(void* ctx, const unsigned char* src, unsigned char* dst);

int SceKernelUtilsForDriver_29a28957(const unsigned char* key, uint32_t key_len, const unsigned char* data, uint32_t data_len, unsigned char digest[0x14]);

int SceKernelUtilsForDriver_ksceSha224Digest_9ea9d4dc(char* source, int size, char* result);

int SceKernelUtilsForDriver_aes_init_f12b6451(aes_ctx* ctx, int blocksize, int keysize, const uint8_t* key);

int SceKernelUtilsForDriver_aes_decrypt_d8678061(aes_ctx* ctx, const char* src, char* dst);