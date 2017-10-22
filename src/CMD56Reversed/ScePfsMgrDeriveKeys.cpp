#include "ScePfsMgrDeriveKeys.h"

#include "Constants.h"
#include "SceSysclib.h"

#include <stdint.h>
#include <string>

#include "SceSblSsMgrDmac5Layer.h"

#include "sha1.h"

//----------------------

typedef struct arm_lldiv_t
{
   long long q;
   long long r;
}arm_lldiv_t;

arm_lldiv_t SceSysclibForDriver__aeabi_ldivmod_7554ab04(long long n, long long d)
{
   lldiv_t res_native = lldiv(n, d);

   arm_lldiv_t res;
   res.q = res_native.quot;
   res.r = res_native.rem;

   return res;
}

ctx_12f8d58e* SceIofilemgrForDriver_thread_related_12f8d58e()
{
   return 0;
}

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

//----------------------

int SceKernelUtilsForDriver_aes_init_2_eda97d6d(void *ctx, uint32_t blocksize, uint32_t keysize, const unsigned char *key)
{
   return 0;
}

int SceKernelUtilsForDriver_aes_encrypt_2_302947b6(void* ctx, const unsigned char* src, unsigned char* dst)
{
   return 0;
}

//############## LEVEL 0 - CRYPTO PRIMITIVES ###############

//moved to ScePfsMgrDeriveKeys.h

//############## LEVEL 1 - CRYPTO BASE WRAPPERS ###############

//#### GROUP 1 (hw dec/enc) ####

//encrypt / decrypt

int AESCBCEncrypt_base_219D8AC(const unsigned char* key, unsigned char* iv, uint32_t size, const unsigned char* src, unsigned char* dst)
{
   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //encrypt N blocks of source data with key and iv
   
   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_e6e1ad15(src, dst, size_block, key, 0x80, iv, 1);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, key, 0x80, 1);
   if(result1 != 0)
      return result1;

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i]; 

   return 0;
}

int AESCBCDecrypt_base_219D950(const unsigned char* key, unsigned char* iv, uint32_t size, const unsigned char* src, unsigned char* dst)
{
   int size_tail = size & 0xF; // get size of tail
   int size_block = size & (~0xF); // get block size aligned to 0x10 boundary

   //decrypt N blocks of source data with key and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptForDriver_121fa69f(src, dst, size_block, key, 0x80, iv, 1);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);
   
   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, key, 0x80, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

//encrypt / decrypt with key_id

int AESCBCDecryptWithKeygen_base_219DAAC(const unsigned char* key, unsigned char* iv, uint32_t size, const unsigned char* src, unsigned char* dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1);

   int size_tail = size & 0xF;
   int size_block = size & (~0xF);
   
   //decrypt N blocks of source data with key and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptWithKeygenForDriver_1901cb5e(src, dst, size_block, key, 0x80, iv, kid, 1);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   //unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);
   unsigned char* iv_enc_aligned = iv_enc;

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, key, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int AESCBCEncryptWithKeygen_base_219D9F4(const unsigned char* klicensee, unsigned char* iv, uint32_t size, const unsigned char* src, unsigned char* dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1); // ???

   int size_tail = size & 0xF; // get size of tail
   int size_block = size & (~0xF); // get block size aligned to 0x10 boundary
   
   //encrypt N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptWithKeygenForDriver_711c057a(src, dst, size_block, klicensee, 0x80, iv, kid, 1);
      if(result0 != 0)
         return result0;  
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   //unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);
   unsigned char* iv_enc_aligned = iv_enc;

   //encrypt iv using klicensee
     
   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, klicensee, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

//#### GROUP 2 (hw cmac) ####

// FUNCTIONS ARE SIMILAR

int AESCMAC_base_1_219DC08(const unsigned char* cmac_key, unsigned char* iv, uint32_t size, const unsigned char* cmac_src, unsigned char* cmac_dst)
{
   int size_tail = size & 0xF;
   int size_block = size & (~0xF);
   
   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int AESCMAC_base_2_219DB64(const unsigned char* cmac_key, unsigned char* iv, uint32_t size, const unsigned char* cmac_src, unsigned char* cmac_dst)
{
   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

// FUNCTIONS ARE SIMILAR

int AESCMACWithKeygen_base_1_219DCAC(const unsigned char* cmac_key, unsigned char* iv, uint32_t size, const unsigned char* cmac_src, unsigned char* cmac_dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1);

   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, kid, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing
   
   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key

   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int AESCMACWithKeygen_base_2_219DD64(const unsigned char* cmac_key, unsigned char* iv, uint32_t size, const unsigned char* cmac_src, unsigned char* cmac_dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1);

   int size_tail = size & 0xF;
   int size_block = size & (~0xF);

   //cmac N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(cmac_src, cmac_dst, size_block, cmac_key, 0x80, iv, kid, 1, 0);
      if(result0 != 0)
         return result0;
   }

   //handle tail section - do a Cipher Text Stealing

   if(size_tail == 0)
      return 0;

   //align destination buffer

   unsigned char iv_enc[0x10] = {0};
   unsigned char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using key
   
   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, cmac_key, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   //CMAC result has constant size - that is why iv is xored with the beginning of dest buffer

   for(int i = 0; i < size_tail; i++)
      cmac_dst[i] = cmac_src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

//#### GROUP 3 (sw dec/enc) ####

// this is most likely SW version of CMAC. both dec and enc functions are implemented
//https://crypto.stackexchange.com/questions/47223/xex-mode-how-to-perturb-the-tweak

int xor_219D624(int* src, int* iv, int* dst, uint32_t size)
{
   int iv_cpy[4] = {0};
   memcpy(iv_cpy, iv, 0x10);

   while(size != 0)
   {
      dst[0] = src[0] ^ iv_cpy[0];
      dst[1] = src[1] ^ iv_cpy[1];
      dst[2] = src[2] ^ iv_cpy[2];
      dst[3] = src[3] ^ iv_cpy[3];

      src += 4;
      dst += 4;
      
      iv_cpy[0] += iv_cpy[0];
      iv_cpy[1] += iv_cpy[1];
      iv_cpy[2] += iv_cpy[2];
      iv_cpy[3] += iv_cpy[3];

      if(true) // this condition should check carry bit after one of the 4 add operations
         iv_cpy[0] = iv_cpy[0] + 0x87;
      
      size = size - 0x10;
   }

   return 0;
}

//IV is a subkey base

int AESCMACDecryptSw_base_219D714(const unsigned char* subkey, const unsigned char* dst_key, const unsigned char* subkey_key, uint32_t key_size, uint32_t size, const unsigned char* src, unsigned char* dst)
{
   char aes_ctx[0x1F0] = {0};
   unsigned char drv_subkey[0x10] = {0};

   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, key_size, subkey_key); //initialize aes ctx with iv_key

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey); //encrypt 0x10 bytes of subkey to derive drv_subkey

   xor_219D624((int*)src, (int*)drv_subkey, (int*)dst, size); // xor src with drv_iv to get dst

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESECBDecryptForDriver_7c978be7(dst, dst, size, dst_key, key_size, 1); //decrypt dst data using dst_key key
   if(result0 == 0)
      xor_219D624((int*)dst, (int*)drv_subkey, (int*)dst, size); //xor dst with drv_iv to get real dst

   return result0;
}

int AESCMACEncryptSw_base_219D694(const unsigned char* subkey, const unsigned char* dst_key, const unsigned char* subkey_key, uint32_t key_size, uint32_t size, const unsigned char* src, unsigned char* dst)
{
   char aes_ctx[0x1F0] = {0};
   unsigned char drv_subkey[0x10] = {0};

   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, key_size, subkey_key);

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey);

   xor_219D624((int*)src, (int*)drv_subkey, (int*)dst, size);

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(dst, dst, size, dst_key, key_size, 1);
   if(result0 == 0)
      xor_219D624((int*)dst, (int*)drv_subkey, (int*)dst, size);

   return result0;
}

//#### GROUP 4 (sw cmac) ####

// this is some CMAC variation but I am not sure ? both functions are similar but most likely ment to be dec / enc

int xor_219D65C(int* src, int* iv, int* dst, uint32_t size)
{
   int iv_cpy[4] = {0};
   memcpy(iv_cpy, iv, 0x10);

   while(size != 0)
   {
      dst[0] = src[0] ^ iv_cpy[0];
      dst[1] = src[1] ^ iv_cpy[1];
      dst[2] = src[2] ^ iv_cpy[2];
      dst[3] = src[3] ^ iv_cpy[3];

      src += 4;
      dst += 4;

      iv_cpy[0] += iv_cpy[0];
      iv_cpy[1] += iv_cpy[1];
      iv_cpy[2] += iv_cpy[2];
      iv_cpy[3] += iv_cpy[3];

      if(true) // this condition should check carry bit after one of the 4 add operations
         iv_cpy[0] = iv_cpy[0] + 0x87;
      
      size = size - 0x10;
   }

   return 0;
}

int AESCMACSw_base_1_219D794(const unsigned char* subkey, const unsigned char* dst_key, const unsigned char* subkey_key, uint32_t keysize, uint32_t size, const unsigned char* src, unsigned char* dst)
{
   char aes_ctx[0x1F0] = {0};
   unsigned char drv_subkey[0x10] = {0};
   unsigned char iv[0x10] = {0}; //HOW IV IS INITIALIZED ?
   
   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, keysize, subkey_key);

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey);

   xor_219D65C((int*)src, (int*)drv_subkey, (int*)dst, size); // WHAT DOES THIS DO IF dst IS OVERWRITTEN BY NEXT CMAC CALL ANYWAY ?

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(src, dst, size, dst_key, keysize, iv, 1, 0);
   if(result0 == 0)
      xor_219D65C((int*)dst, (int*)drv_subkey, (int*)dst, size);

   return result0;
}

int AESCMACSw_base_2_219D820(const unsigned char* subkey, const unsigned char* dst_key, const unsigned char* subkey_key, uint32_t keysize, uint32_t size, const unsigned char* src, unsigned char* dst)
{
   char aes_ctx[0x1F0] = {0};
   unsigned char drv_subkey[0x10] = {0};
   unsigned char iv[0x10] = {0}; //HOW IV IS INITIALIZED ?

   SceKernelUtilsForDriver_aes_init_2_eda97d6d(aes_ctx, 0x80, keysize, subkey_key);

   SceKernelUtilsForDriver_aes_encrypt_2_302947b6(aes_ctx, subkey, drv_subkey);

   xor_219D65C((int*)src, (int*)drv_subkey, (int*)dst, size); // WHAT DOES THIS DO IF dst IS OVERWRITTEN BY NEXT CMAC CALL ANYWAY ?

   int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(src, dst, size, dst_key, keysize, iv, 1, 0);
   
   if(result0 == 0)
      xor_219D65C((int*)dst, (int*)drv_subkey, (int*)dst, size);

   return result0;
}

//############## LEVEL 2 - CRYPTO WRAPPER SELECTORS ###############

#define PFS_CRYPTO_USE_CMAC   0x0001 //1
#define PFS_CRYPTO_USE_KEYGEN 0x0002 //2

//#### GROUP 1, GROUP 2 (hw dec/enc) ####

unsigned char g_1771100[0x10] = {0};

int pfs_decrypt_hw_219D480(const unsigned char* key, const unsigned char* iv_xor_key, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const unsigned char* src, unsigned char* dst, uint16_t flag, uint16_t key_id)
{
   unsigned char iv[0x10] = {0};

   //this piece of code unwraps 64 bit sector number into byte array
   //like here https://github.com/libtom/libtomcrypt/blob/c14bcf4d302f954979f0de43f7544cf30873f5a6/src/headers/tomcrypt_macros.h#L23

   int tk_tmp00 = tweak_key0; //sector_number_hi
   int tk_tmp10 = tweak_key1; //sector_number_lo
   
   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);

   for(int i = 0; i < 0x10; i++)
      iv[i] = iv[i] ^ iv_xor_key[i];
  
   if(size != 0)
   {
      int offset = 0;
      int bytes_left = size;

      do
      {
         int tk_tmp01 = tweak_key0 + offset;
         int tk_tmp11 = tweak_key1 + 0;
         
         for(int i = 0; i < 8; i++)
         {
            iv[i] = tk_tmp01;
            
            tk_tmp01 = (tk_tmp01 >> 8) | (tk_tmp11 << 24);
            tk_tmp11 = tk_tmp11 >> 8;
         }

         memset(iv + 8, 0, 8);

         for(int i = 0; i < 0x10; i++)
            iv[i] = iv[i] ^ iv_xor_key[i];

         // select block_size if we did not yet reach tail of the data. 
         // or select bytes_left which will be the size of the tail in the end

         int size_arg = 0;
         if(block_size < bytes_left)
            size_arg = block_size;
         else
            size_arg = bytes_left;

         if((flag & PFS_CRYPTO_USE_KEYGEN) != 0)
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMACWithKeygen_base_2_219DD64(key, iv, size_arg, src + offset, g_1771100, key_id);
            else
               AESCBCDecryptWithKeygen_base_219DAAC(key, iv, size_arg, src + offset, dst + offset, key_id);
         }
         else
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMAC_base_1_219DC08(key, iv, size_arg, src + offset, g_1771100);
            else
               AESCBCDecrypt_base_219D950(key, iv, size_arg, src + offset, dst + offset);
         }

         offset = offset + block_size;
         bytes_left = bytes_left - block_size;
      }
      while(size > offset);
   }

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

int pfs_encrypt_hw_219D2DC(const unsigned char* key, const unsigned char* iv_xor_key, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const unsigned char* src, unsigned char* dst, uint16_t flag, uint16_t key_id)
{
   unsigned char iv[0x10] = {0};

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;

   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);

   for(int i = 0; i < 0x10; i++)
      iv[i] = iv[i] ^ iv_xor_key[i];

   if(size != 0)
   {
      int offset = 0;
      int bytes_left = size;

      do
      {         
         int tk_tmp01 = tweak_key0 + offset;
         int tk_tmp11 = tweak_key1 + 0;

         for(int i = 0; i < 8; i++)
         {
            iv[i] = tk_tmp01;

            tk_tmp01 = (tk_tmp01 >> 8) | (tk_tmp11 << 24);
            tk_tmp11 = tk_tmp11 >> 8;
         }

         memset(iv + 8, 0, 8);

         for(int i = 0; i < 0x10; i++)
            iv[i] = iv[i] ^ iv_xor_key[i];

         // select block_size if we did not yet reach tail of the data. 
         // or select bytes_left which will be the size of the tail in the end

         int size_arg = 0;
         if(block_size < bytes_left)
            size_arg = block_size;
         else
            size_arg = bytes_left;

         if((flag & PFS_CRYPTO_USE_KEYGEN) != 0)
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMACWithKeygen_base_1_219DCAC(key, iv, size_arg, src + offset, g_1771100, key_id);
            else
               AESCBCEncryptWithKeygen_base_219D9F4(key, iv, size_arg, src + offset, dst + offset, key_id);
         }
         else
         {
            if((flag & PFS_CRYPTO_USE_CMAC) != 0)
               AESCMAC_base_2_219DB64(key, iv, size_arg, src + offset, g_1771100);
            else
               AESCBCEncrypt_base_219D8AC(key, iv, size_arg, src + offset, dst + offset);
         }

         offset = offset + block_size;
         bytes_left = bytes_left - block_size;
      }
      while(size > offset);
   }

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

//#### GROUP 3, GROUP 4 (sw dec/enc) ####

int pfs_decrypt_sw_219D174(const unsigned char* key, const unsigned char* subkey_key, uint32_t keysize, int ignored, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const unsigned char* src, unsigned char* dst, uint16_t flag)
{
   unsigned char iv[0x10] = {0};

   if(((block_size | size) << 0x1C) != 0)
      return 0x80140609;

   if(size <= 0xF)
      return 0x80140609;
   
   if((((int)src | (int)dst) << 0x1E) != 0)
      return 0x8014060E;

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;

   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);

   int offset = 0;
   int bytes_left = size;

   do
   {
      // select block_size if we did not yet reach tail of the data. 
      // or select bytes_left which will be the size of the tail in the end

      int size_arg = 0;
      if(block_size < bytes_left)
         size_arg = block_size;
      else
         size_arg = bytes_left;

      int result0 = 0;
      if((flag & PFS_CRYPTO_USE_CMAC) != 0)
         result0 = AESCMACSw_base_2_219D820(iv, key, subkey_key, keysize, size_arg, src + offset, g_1771100);
      else
         result0 = AESCMACDecryptSw_base_219D714(iv, key, subkey_key, keysize, size_arg, src + offset, dst + offset);

      if(result0 != 0)
         return result0;

      for(int i = 0; i < 0x10; i++)
      {
         if(iv[i] == 0xFF)
         {
            iv[i] = 0;
         }
         else
         {
            iv[i] = iv[i] + 1;
            break;
         }
      }

      offset = offset + block_size;
      bytes_left = bytes_left - block_size;
   }
   while(size > offset);

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

int pfs_encrypt_sw_219D00C(const unsigned char* key, const unsigned char* subkey_key, uint32_t keysize, int ignored, int tweak_key0, int tweak_key1, uint32_t size, uint32_t block_size, const unsigned char* src, unsigned char* dst, uint16_t flag)
{
   unsigned char iv[0x10] = {0};

   if(((block_size | size) << 0x1C) != 0)
      return 0x80140609;

   if(size <= 0xF)
      return 0x80140609;

   if((((int)src | (int)dst) << 0x1E) != 0)
      return 0x8014060E;

   int tk_tmp00 = tweak_key0;
   int tk_tmp10 = tweak_key1;

   for(int i = 0; i < 8; i++)
   {
      iv[i] = tk_tmp00;

      tk_tmp00 = (tk_tmp00 >> 8) | (tk_tmp10 << 24);
      tk_tmp10 = tk_tmp10 >> 8;
   }

   memset(iv + 8, 0, 8);
   
   int offset = 0;
   int bytes_left = size;
   
   do
   {
      // select block_size if we did not yet reach tail of the data. 
      // or select bytes_left which will be the size of the tail in the end

      int size_arg = 0;
      if(block_size < bytes_left)
         size_arg = block_size;
      else
         size_arg = bytes_left;

      int result0 = 0;
      if((flag & PFS_CRYPTO_USE_CMAC) != 0)
         result0 = AESCMACSw_base_1_219D794(iv, key, subkey_key, keysize, size_arg, src + offset, g_1771100);
      else
         result0 = AESCMACEncryptSw_base_219D694(iv, key, subkey_key, keysize, size_arg, src + offset, dst + offset);
      
      if(result0 != 0)
         return result0;

      for(int i = 0; i < 0x10; i++)
      {
         if(iv[i] == 0xFF)
         {
            iv[i] = 0;
         }
         else
         {
            iv[i] = iv[i] + 1;
            break;
         }
      }

      offset = offset + block_size;
      bytes_left = bytes_left - block_size;
   }
   while(size > offset);

   if((flag & PFS_CRYPTO_USE_CMAC) != 0)
   {
      if(dst != src)
      {
         memcpy(dst, src, size);
      }
   }

   return 0;
}

//----------------------

int sha1Digest_219DE54(unsigned char *result, const unsigned char *source, int size)
{
   return SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(source, size, result);
}

int hmacSha1Digest_219DE68(unsigned char* digest, const unsigned char* key, const unsigned char* data, int data_len)
{
   return SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(key, 0x14, data, data_len, digest);
}

//----------------------

unsigned char hmac_key_21A93C8[0x14] = {0xE4, 0x62, 0x25, 0x8B, 0x1F, 0x31, 0x21, 0x56, 0x07, 0x45, 0xDB, 0x62, 0xB1, 0x43, 0x67, 0x23, 0xD2, 0xBF, 0x80, 0xFE}; 

unsigned char hmac_key_21A93DC[0x14] = {0xAF, 0xE6, 0x56, 0xBB, 0x3C, 0x17, 0x25, 0x6A, 0x3C, 0x80, 0x9F, 0x6E, 0x9B, 0xF1, 0x9F, 0xDD, 0x5A, 0x38, 0x85, 0x43};

unsigned char iv_21A93F0[0x10] = {0x74, 0xD2, 0x0C, 0xC3, 0x98, 0x81, 0xC2, 0x13, 0xEE, 0x77, 0x0B, 0x10, 0x10, 0xE4, 0xBE, 0xA7};

//-------------------------------------

int calculate_sha1_chain_219E008(unsigned char* key, unsigned char* iv_xor_key, const unsigned char* klicensee, uint32_t salt1)
{
   int saltin[2] = {0};
   unsigned char base0[0x14] = {0};
   unsigned char base1[0x14] = {0};
   unsigned char combo[0x28] = {0};
   unsigned char drvkey[0x14] = {0};

   saltin[0] = salt1;

   sha1Digest_219DE54(base0, klicensee, 0x10); //calculate hash of klicensee

   // derive key 0

   saltin[1] = 1;
   
   sha1Digest_219DE54(base1, (unsigned char*)saltin, 8); //calculate hash of salt 0

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);
   
   sha1Digest_219DE54(drvkey, combo, 0x28); //calculate hash from combination of salt 0 hash and klicensee hash

   memcpy(key, drvkey, 0x10);  //copy derived key

   // derive key 1
   
   saltin[1] = 2;

   sha1Digest_219DE54(base1, (unsigned char*)saltin, 8); //calculate hash of salt 1

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);

   sha1Digest_219DE54(drvkey, combo, 0x28); //calculate hash from combination of salt 1 hash and klicensee hash

   memcpy(iv_xor_key, drvkey, 0x10); //copy derived key

   return 0;
}

int calculate_sha1_chain_219E1CC(unsigned char* key, unsigned char* iv_xor_key, const unsigned char* klicensee, uint32_t ignored_salt0, uint32_t salt1)
{
   return calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt1);
}

int hmac1_sha1_or_sha1_chain_219E0DC(unsigned char* key, unsigned char* iv_xor_key, const unsigned char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t ignored_key_id)
{
   if((flag & 2) == 0)
   {
      calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt1);
      return 0;
   }

   int saltin0[1] = {0};
   int saltin1[2] = {0};
   unsigned char drvkey[0x14] = {0};

   memcpy(key, klicensee, 0x10);

   if(salt0 == 0)
   {
      saltin0[0x00] = salt1;
      hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, (unsigned char*)saltin0, 4); // derive key with one salt
   }
   else
   {
      saltin1[0] = salt0;
      saltin1[1] = salt1;
      hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, (unsigned char*)saltin1, 8); // derive key with two salts
   }

   memcpy(iv_xor_key, drvkey, 0x10); //copy derived key

   return 0;
}

int hmac_sha1_219E164(unsigned char* key, unsigned char* iv_xor_key, const unsigned char* klicensee, uint16_t ignored_flag, uint16_t ignored_key_id, const unsigned char* base_key, uint32_t base_key_len)
{
   unsigned char drvkey[0x14] = {0};

   hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, base_key, base_key_len);

   memcpy(key, klicensee, 0x10);

   memcpy(iv_xor_key, drvkey, 0x10);

   return 0;
}

int calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(unsigned char* hmac_key, const unsigned char* klicensee, uint32_t salt0, uint32_t salt1, uint16_t key_id)
{
   unsigned char drvkey[0x14] = {0};
   unsigned char iv[0x10] = {0};
   unsigned char combo[0x14] = {0};

   //align buffers

   /*
   unsigned char* drvkey_aligned = drvkey + ((0 - (int)drvkey) & 0x3F);
   unsigned char* iv_aligned = iv + ((0 - (int)iv) & 0x3F);
   unsigned char* combo_aligned = combo + ((0 - (int)combo) & 0x3F);
   */

   unsigned char* drvkey_aligned = drvkey;
   unsigned char* iv_aligned = iv;
   unsigned char* combo_aligned = combo;

   int saltin0[1] = {0};
   int saltin1[2] = {0};
   unsigned char base[0x14] = {0};

   if(salt0 == 0)
   {
      saltin0[0] = salt1;
      hmacSha1Digest_219DE68(base, hmac_key_21A93DC, (unsigned char*)saltin0, 4); // derive base with one salt
   }
   else
   {
      saltin1[0] = salt0;
      saltin1[1] = salt1;
      hmacSha1Digest_219DE68(base, hmac_key_21A93DC, (unsigned char*)saltin1, 8); // derive base with two salts
   }

   memcpy(combo_aligned, base, 0x14); // calculated digest will be src data

   memcpy(iv_aligned, iv_21A93F0, 0x10); //initialize iv

   AESCBCEncryptWithKeygen_base_219D9F4(klicensee, iv_aligned, 0x14, combo_aligned, drvkey_aligned, key_id);

   memcpy(hmac_key, drvkey_aligned, 0x14); // copy derived key
   
   return 0;
}

int combine_klicensee_digest_219E1D8(unsigned char* hmac_key, const unsigned char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t key_id)
{
   if((flag & 1) > 0) // check bit 0
   {
      memset(hmac_key, 0, 0x14);
      return 0;
   }

   if((flag & 2) > 0) // check bit 1
   {
      calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(hmac_key, klicensee, salt0, salt1, key_id);
      return 0;
   }

   int saltin[2] = {0};
   unsigned char base0[0x14] = {0};
   unsigned char base1[0x14] = {0};
   unsigned char combo[0x28] = {0};
   unsigned char drvkey[0x14] = {0};

   sha1Digest_219DE54(base0, klicensee, 0x10); // calculate digest of klicensee

   saltin[0] = 0xA;
   saltin[1] = salt1;

   sha1Digest_219DE54(base1, (unsigned char*)saltin, 8); // calculate digest of salt

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);
         
   sha1Digest_219DE54(drvkey, combo, 0x28); // calculate digest of combination of klicensee and salt digests
               
   memcpy(hmac_key, drvkey, 0x14); // copy derived key

   return 0;
}

//return 0 - error
//return 1 - success
int proc_verify_14_bytes_219DE44(unsigned char unk0[0x14], unsigned char unk1[0x14])
{
   //from what I know - b5a4d745 returns only 0, -1 (not sure about 1) based on reversing and tests
   //for  0 - CLZ is 32
   //for  1 - CLZ is 31
   //for -1 - CLZ is 0
    
   //for  0 - >> 5 is 1
   //for  1 - >> 5 is 0
   //for -1 - >> 5 is 0
    
   //LSRS changes flag to indicate if value is zero or not
   //zero value is considered as error
   //which means that original value 1 or -1 is an error and 0 is success
   //meaning that unk0 and unk1 should be identical for this function to succeed
   //this is some analog of strcmp or memcmp

   int result = SceSysclibForDriver_b5a4d745(unk0, unk1, 0x14);
   return (result == 0) ? 1 : 0;
}

//-------------------------------------

int sub_219A29C(const derive_keys_ctx* ctx)
{
   return ctx->unk_68;
}

int initialize_data_ctx(CryptEngineData* data, uint32_t salt1, int unk2, int unk3, uint16_t flag0, int arg_4, const derive_keys_ctx* drv_ctx, const pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
{
   ctx_12f8d58e* ctx0 = SceIofilemgrForDriver_thread_related_12f8d58e();
   data->unk_18 = 0x100;
   if((ctx0 != 0) && (ctx0->unk_2C >= 0))
      data->unk_18 = (uint32_t)(ctx0->unk_2C & 0x0000FFFF);

   ctx_12f8d58e* ctx1 = SceIofilemgrForDriver_thread_related_12f8d58e();
   data->unk_14 = 0xF;
   if(ctx1 != 0)
      data->unk_14 = ctx1->unk_28;

   data->salt0 = pfs_pmi_bcl->salt0;
   data->salt1 = salt1;
   data->unk_1C = arg_4;

   data->type = pfs_pmi_bcl->type;
   data->pmi_bcl_flag = pfs_pmi_bcl->flag;
   data->key_id = pfs_pmi_bcl->key_id;
   data->flag0 = flag0;
   
   data->unk_20 = unk2;
   data->unk_24 = unk3;

   data->klicensee = pfs_pmi_bcl->klicensee;

   data->block_size = drv_ctx->get_block_size_14(drv_ctx);

   return 0;
}

int derive_data_ctx_keys(CryptEngineData* data, const derive_keys_ctx* drv_ctx)
{
   int some_flag_base = (uint32_t)(data->pmi_bcl_flag - 2);
   int some_flag = 0xC0000B03 & (1 << some_flag_base);

   if((some_flag_base > 0x1F) || (some_flag == 0))
   {
      calculate_sha1_chain_219E1CC(data->key, data->iv_xor_key, data->klicensee, data->salt0, data->salt1);
      return combine_klicensee_digest_219E1D8(data->hmac_key, data->klicensee, data->salt0, data->pmi_bcl_flag, data->salt1, data->key_id);
   }
   else
   {
      if((drv_ctx->unk_40 != 0 && drv_ctx->unk_40 != 3) || (drv_ctx->unk_58 <= 1))
      {    
         hmac1_sha1_or_sha1_chain_219E0DC(data->key, data->iv_xor_key, data->klicensee, data->salt0, data->pmi_bcl_flag, data->salt1, data->key_id);
         return combine_klicensee_digest_219E1D8(data->hmac_key, data->klicensee, data->salt0, data->pmi_bcl_flag, data->salt1, data->key_id);
      }
      else
      {
         if(drv_ctx->unk_40 == 0 || drv_ctx->unk_40 == 3)
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, data->klicensee, data->pmi_bcl_flag, data->key_id, drv_ctx->base_key, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, data->klicensee, data->salt0, data->pmi_bcl_flag, data->salt1, data->key_id);
         }
         else
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, data->klicensee, data->pmi_bcl_flag, data->key_id, 0, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, data->klicensee, data->salt0, data->pmi_bcl_flag, data->salt1, data->key_id);
         }
      }
   }
}

// I have separated this into two functions for easy testing

int derive_keys_from_klicensee_219B4A0(CryptEngineData* data, uint32_t salt1, int unk2, int unk3, uint16_t flag0, int arg_4, const derive_keys_ctx* drv_ctx, const pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
{
   initialize_data_ctx(data, salt1, unk2, unk3, flag0, arg_4, drv_ctx, pfs_pmi_bcl);
   
   return derive_data_ctx_keys(data, drv_ctx);
}

//-------------------------------------

void* proc_get_table_element_2198B1C(int index)
{
   return 0;
}

typedef struct init_res_219B934
{
   uint32_t unk_0;
   uint32_t unk_4;
}init_res_219B934;

/*
int init_crypto_context_219B934(CryptEngineSubctx *subctx, CryptEngineData *data, int unk2, int unk3, init_res_219B934* init_result)
{
   #pragma region

   int r4 = data->unk_20;
   int r5 = data->unk_24;
   
   unk1[0] = r4;
   unk1[4] = r5;

   int r5 = r5 - unk3;
   
   int r6 = data->size1; // 0x28
   
   int r9 = unk3;
   int r8 = unk2;
   
   subctx->opt_code = 4; // 0x08
   subctx->data = data; //0x0C
   
   subctx->unk_20 = 0x80;
   subctx->unk_24 = 0x80;

   subctx->unk_10 = 0;
   subctx->source = 0; //0x14

   subctx->unk_18 = 0;
   subctx->unk_1C = 0;

   subctx->size2 = 0; //0x28
   subctx->nDigests = 0; //0x2C
   
   subctx->unk_30 = 0;
   subctx->seed0_base = 0; //0x34

   subctx->dest_offset = 0; //0x38
   subctx->size0 = 0; //0x3C

   subctx->size1 = 0; //0x40
   subctx->unk_44 = 0;

   subctx->size3 = 0; //0x48
   subctx->hmac_sha1_digest = 0; //0x4C

   subctx->buffer0 = 0; //0x50
   subctx->buffer1 = 0; //0x54

   #pragma endregion

   int r10 = 0;
   int r3 = 4;

   if(r4 < unk2)
   {
      #pragma region

      int r1 = data->unk_14; //0x14
      int r0 = data->unk_18; //0x18
      int r0 = 8;
      int r0 = r0 - 1;
      
      int r2 = unk1[0];
      int r3 = unk1[4];
      
      int r0 = r6 * r0;
      int r2 = r2 + r0;
      int r3 = r3 + 0;
      int r4 = r2 + 1;
      int r5 = r3 + 0;
      int r0 = r5 - r9;
      
      if(r4 < r8)
      {
         int r3 = r10;
         int r0 = r4;
         int r1 = r5;
         int r2 = r6;

         SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

         int r8 = r4 - r2;
         int r9 = r5 - r3;
      }

      #pragma endregion

      #pragma region
      
      int r1 = unk1[0];
      int r2 = r6;
      
      subctx->unk_20 = r8;
      subctx->unk_24 = r9;

      int r3 = r8 - r1;

      int r0 = unk1[0];
      int r1 = unk1[4];
      
      subctx->size2 = r3; //0x28
      
      int r3 = 0;
      
      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      int r4 = r0;

      int r0 = r8 + 0xFFFFFFFF;

      int r2 = r6;
      int r3 = 0;
      int r5 = r1;
      int r1 = r9 + 0xFFFFFFFF;

      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      
      int r0 = r0 - r4;
      
      subctx->seed0_base = r4; //0x34
      
      int r3 = r0 + 1;
      
      int r2 = r6;
      
      subctx->nDigests = r3; //0x2C
      
      int r3 = 0;

      int r0 = unk1[0];
      int r1 = unk1[1];
      int r10 = r3;
      
      SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      
      int r1 = data->unk_1C;

      subctx->dest_offset = r2; //0x38
      subctx->size1 = r10; //0x40

      #pragma endregion

      if(r1 == 1)
      {
         #pragma region

         int r0 = r2 | r3;
         if(r0 == 0)
         {
            r4 = r10;
         }

         if(r0 != 0)
         {
            var_38[0] = r4;
            var_38[1] = r10;
            
            int r0 = var_38[0];
            int r1 = var_38[1];

            if((r5 == r1) && (r4 == r0))
            {
               int r4 = r2;
            }
            else
            {
               int r4 = r6;
            }
         }

         int r3 = 0;
         subctx->size0 = r4; //0x3C
         subctx->size3 = r3; //0x48

         int r0 = r8;
         int r1 = r9;
         int r2 = r6;
         int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

         int r1 = r3 - 0; //why this line. does it influence comparison ?
         if(r2 < 1)
         {
            int r2 = r6;
         }
         
         subctx->unk_44 = r2; //0x44

         init_result->unk_0 = r8;
         init_result->unk_4 = r9;

         #pragma endregion
         
         return r0;
      }
      else
      {
         #pragma region

         int r4 = r2 | r3;
         int r0 = r8;
         
         if(r4 != 0)
         {
            int r3 = r6;
         }
         else
         {
            int r3 = 0;
         }

         int r1 = r9;
         subctx->size0 = r3; //0x3C
         int r2 = r6;
         int r3 = r10;
         int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
         
         int r5 = r3 - 0; //why this line. does it influence comparison ?
         if(r2 >= 1)
         {
            int r4 = r6 - r2;
         }
         else
         {
            int r4 = r10;
         }

         subctx->unk_44 = r6;
         subctx->size3 = r4; //0x48
         
         init_result->unk_0 = r8;
         init_result->unk_4 = r9;

         #pragma endregion
         
         return r0;
      }
   }
   else
   {
      #pragma region

      subctx->unk_20 = r8;
      subctx->unk_24 = r9;

      int r3 = r10;
      int r0 = r2;
      int r1 = r9;
      int r2 = r6;

      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

      var_38 = r0;
      int r1 = r9;
      int r5 = var_38;

      int r0 = r8;
      int r2 = r6;
      int r3 = r10;

      subctx->seed0_base = r5; //0x34
      
      int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
      
      int r5 = r3;

      int r3 = data->unk_1C;
      int r4 = r2;
      
      int r0 = r4 | r5;

      subctx->dest_offset = r4; //0x38
      
      if(r0 == 0)
      {
         int r2 = 0;
      }
      else
      {
         int r2 = 1;
      }

      subctx->nDigests = r2; //0x2C

      #pragma endregion

      if(r3 == 1)
      {
         if(r2 == 0)
         {
            #pragma region

            subctx->size0 = r2; //0x3C
            subctx->unk_44 = r4;

            init_result->unk_0 = r8;
            init_result->unk_4 = r9;

            #pragma endregion
            
            return r0;
         }
         else
         {
            #pragma region

            int r1 = var_38;
            int r2 = 0;
            var_2C = r2;
            int r3 = r10;
            int r2 = r6;
            var_30 = r1;
            
            int r0 = unk1[0];
            int r1 = unk1[1];
            int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);

            int r2 = var_30[0];
            int r3 = var_30[1];
            
            if((r1 == r3) && (r0 == r2))
            {
               int r0 = unk1[0];
               int r1 = unk1[1];

               int r2 = r6;
               int r3 = r10;
               int r0 = SceSysclibForDriver__aeabi_ldivmod_7554ab04(r0, r1, r2, r3);
            }
            else
            {
               int r2 = r6;
            }

            subctx->size0 = r2; //0x3C
            subctx->unk_44 = r4;
            
            init_result->unk_0 = r8;
            init_result->unk_4 = r9;

            #pragma endregion

            return 0;
         }
      }
      else
      {
         #pragma region

         if(r2 == 0)
         {
            int r3 = 0;
         }
         else
         {
            subctx->size0 = r6; //0x3C
            int r3 = r5 - 0; //does this influence comparison?

            if(r4 < 1)
            {
               int r3 = 0;
            }
            else
            {
               int r3 = r6;
               int r4 = r6 - r4;
               subctx->size3 = r4; //0x48
            }
         }

         subctx->unk_44 = r3;

         init_result->unk_0 = r8;
         init_result->unk_4 = r9;

         #pragma endregion
         
         return 0;
      }
   }
}
*/

int validate_subctx_zero_pointers_219BB14(CryptEngineSubctx *subctx)
{
   return 0;
}

int subctx_enter_219AC0C(CryptEngineSubctx *subctx, int unk1, int unk2)
{
   return 0;
}

int dispatch_task_to_crypto_engine_219BD88(CryptEngineWorkCtx *work)
{
   return 0;
}

int wait_task_to_crypto_engine_219BEA0(CryptEngineWorkCtx *work)
{
   return 0;
}

int subctx_exit_219AB30(CryptEngineSubctx *subctx, int unk1, int unk2)
{
   return 0;
}

int crypto_ScePfsCryptBufVC_219BB70(void *unk0)
{
   return 0;
}

int clear_crypto_data_219B5C4(CryptEngineData *data)
{
   return 0;
}

//-------------------------------------

int ScePfsCryptEngineThread_219BBB0()
{
   return 0;
}

#define IGNORE_ARG 0

int hmac_sha1_digest_219DE7C(unsigned char digest[0x14], unsigned char* key, const unsigned char* src, uint32_t size)
{
   if(size == 0)
   {
      //NOT SURE WHY DATA LEN CAN BE 0 ?
      SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(key, 0x14, src, 0, digest);
      return 0;
   }

   unsigned char key_raw[0x14] = {0};
   unsigned char dst_raw[0x14] = {0};

   /*
   unsigned char* key_aligned = key_raw + ((0 - (int)key_raw) & 0x3F);
   unsigned char* dst_aligned = dst_raw + ((0 - (int)dst_raw) & 0x3F);
   */
   unsigned char* key_aligned = key_raw;
   unsigned char* dst_aligned = dst_raw;

   //memset(key_aligned + 8, 0, 0x18); //NOT SURE WHAT IS THE PURPOSE OF THIS LINE ?

   memcpy(key_aligned, key, 0x14);
   
   int result = SceSblSsMgrForDriver_sceSblSsMgrHMACSHA1ForDriver_6704d985(src, dst_aligned, size, key_aligned, 0, 1, 0); // IV is zero in this case - this is OK (tested)
   if(result != 0)
      return result;

   memcpy(digest, dst_aligned, 0x14);

   return 0;
}

void verify_step(CryptEngineWorkCtx* crypt_ctx, int tweak_key0, int tweak_key1, int bitSize, int size, unsigned char* source)
{
   // variable mapping

   if((crypt_ctx->subctx->data->flag0 << 0x12) < 0)
      return; // this does not terminate crypto task (local exit)
   
   if((crypt_ctx->subctx->data->flag0 << 0x10) < 0)
      return; // this does not terminate crypto task (local exit)

   if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x20) != 0)
      return; // this does not terminate crypto task (local exit)

   if((bitSize > 0x1F) || ((0xC0000B03 & (1 << bitSize)) == 0))
   {
      if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x41) != 0x41)
      {
         if(crypt_ctx->subctx->nBlocks != 0)
         {
            int counter = 0;

            unsigned char* source_base = source;
            unsigned char* signatures_base = crypt_ctx->subctx->signature_table;
                     
            unsigned char bytes14[0x14] = {0};

            do
            {
               hmac_sha1_digest_219DE7C(bytes14, crypt_ctx->subctx->data->hmac_key, source_base, crypt_ctx->subctx->data->block_size);
                        
               int ver_res = proc_verify_14_bytes_219DE44(signatures_base, bytes14);

               //if verify is not successful and flag is not specified
               if((ver_res == 0) && ((crypt_ctx->subctx->data->pmi_bcl_flag & 9) != 1))
               {
                  crypt_ctx->error = 0x80140F02;
                  return; // this should terminate crypto task (global exit)
               }
                        
               counter = counter + 1;

               source_base = source_base + crypt_ctx->subctx->data->block_size;
               signatures_base = signatures_base + 0x14;
            }
            while(counter != crypt_ctx->subctx->nBlocks);
         }
      }
   }
   else
   {
      if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x41) != 0x41)
      {
         int64_t tk_combo = (int64_t)tweak_key0 | ((int64_t)tweak_key1 << 32);
         arm_lldiv_t div_res = SceSysclibForDriver__aeabi_ldivmod_7554ab04(tk_combo, crypt_ctx->subctx->data->block_size);

         int salt = (int)div_res.q;
                  
         if(crypt_ctx->subctx->nBlocks != 0)
         {
            int counter = 0;
            int bytes_left = size;

            unsigned char* source_base = source;
            unsigned char* signatures_base = crypt_ctx->subctx->signature_table;

            unsigned char digest[0x14] = {0};
            unsigned char bytes14[0x14] = {0};

            do
            {
               hmacSha1Digest_219DE68(digest, crypt_ctx->subctx->data->hmac_key, (unsigned char*)&salt, 4);

               int size_arg = (crypt_ctx->subctx->data->block_size < bytes_left) ? crypt_ctx->subctx->data->block_size : bytes_left;
               hmac_sha1_digest_219DE7C(bytes14, digest, source_base, size_arg);
                        
               int ver_res = proc_verify_14_bytes_219DE44(signatures_base, bytes14);
                        
               //if verify is not successful and flag is not specified
               if((ver_res == 0) && ((crypt_ctx->subctx->data->pmi_bcl_flag & 9) != 1))
               {
                  crypt_ctx->error = 0x80140F02;
                  return; // this should terminate crypto task (global exit)
               }
                        
               counter = counter + 1;
               bytes_left = bytes_left - crypt_ctx->subctx->data->block_size;

               source_base = source_base + crypt_ctx->subctx->data->block_size;
               signatures_base = signatures_base + 0x14;

               salt = salt + 1;
            }
            while(counter != crypt_ctx->subctx->nBlocks);
         }
      }
   }
}

void work_3_step0(CryptEngineWorkCtx* crypt_ctx, int tweak_key0, int tweak_key1, int bitSize, int size, unsigned char* buffer)
{
   // variable mapping

   unsigned const char* key = crypt_ctx->subctx->data->key;
   unsigned const char* subkey_key = crypt_ctx->subctx->data->iv_xor_key;
   
   //------------------------------

   //conflicts with decryption
   /*
   if(((int)crypt_ctx->subctx->data->flag0 & 0x4000) == 0)
   {
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }
   */

   if((crypt_ctx->subctx->data->flag0 << 0x10) < 0)
   {
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x41) == 0x41)
   {
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   if(crypt_ctx->subctx->nBlocks == 0)
   {
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   //============== remove first encryption layer ? =========================

   int offset = 0;
   int counter = 0;

   if((bitSize > 0x1F) || ((0xC0000B03 & (1 << bitSize)) == 0))
   {   
      do
      {
         pfs_decrypt_sw_219D174(key, subkey_key, 0x80, IGNORE_ARG, tweak_key0 + offset, tweak_key1 + 0, crypt_ctx->subctx->data->block_size, crypt_ctx->subctx->data->block_size, buffer + offset, buffer + offset, crypt_ctx->subctx->data->pmi_bcl_flag);

         counter = counter + 1;
         offset = offset + crypt_ctx->subctx->data->block_size;
      }
      while(counter != crypt_ctx->subctx->nBlocks);
   }
   else
   {
      int bytes_left = size;
   
      do
      {
         int size_arg = ((crypt_ctx->subctx->data->block_size < bytes_left) ? crypt_ctx->subctx->data->block_size : bytes_left);
         pfs_decrypt_hw_219D480(key, subkey_key, tweak_key0 + offset, tweak_key1 + 0, size_arg, crypt_ctx->subctx->data->block_size, buffer + offset, buffer + offset, crypt_ctx->subctx->data->pmi_bcl_flag, crypt_ctx->subctx->data->key_id);

         bytes_left = bytes_left - crypt_ctx->subctx->data->block_size;
         offset = offset + crypt_ctx->subctx->data->block_size;
         counter = counter + 1;
      }
      while(counter != crypt_ctx->subctx->nBlocks);
   }

   crypt_ctx->error = 0;
   return; // this should terminate crypto task (global exit)
}

void work_3_step1(CryptEngineWorkCtx* crypt_ctx, int bitSize, unsigned char* buffer)
{
   // variable mapping

   unsigned const char* key = crypt_ctx->subctx->data->key;
   unsigned const char* subkey_key = crypt_ctx->subctx->data->iv_xor_key;

   unsigned char* output_dst = crypt_ctx->subctx->unk_10 + ((crypt_ctx->subctx->data->block_size * crypt_ctx->subctx->unk_18) - crypt_ctx->subctx->dest_offset);
   unsigned char* output_src = buffer + (crypt_ctx->subctx->data->block_size * crypt_ctx->subctx->unk_18);
   int output_size = crypt_ctx->subctx->data->block_size * crypt_ctx->subctx->nBlocksTail;

   //========== process block part of source buffer ? ========================

   if(crypt_ctx->subctx->unk_18 == 0)
   {
      int tweak_key0_block = crypt_ctx->subctx->data->block_size * crypt_ctx->subctx->seed0_base;
      int tweak_key1_block = (int)crypt_ctx->subctx->data->flag0 & 0x4000;

      if(tweak_key1_block == 0)
      {
         if((crypt_ctx->subctx->data->flag0 << 0x10) >= 0)
         {
            if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x41) != 0x41)
            {
               if((bitSize > 0x1F) || ((0xC0000B03 & (1 << bitSize)) == 0))
               {
                  pfs_decrypt_sw_219D174(key, subkey_key, 0x80, IGNORE_ARG, tweak_key0_block, tweak_key1_block, crypt_ctx->subctx->data->block_size, crypt_ctx->subctx->data->block_size, buffer, buffer, crypt_ctx->subctx->data->pmi_bcl_flag);
               }
               else
               {
                  pfs_decrypt_hw_219D480(key, subkey_key, tweak_key0_block, tweak_key1_block, crypt_ctx->subctx->data->block_size, crypt_ctx->subctx->data->block_size, buffer, buffer, crypt_ctx->subctx->data->pmi_bcl_flag, crypt_ctx->subctx->data->key_id);
               }
            }
         }
      }  
   }

   //========= copy result to output buffer if source buffer had no tail ? ============

   int some_value = crypt_ctx->subctx->nBlocksTail + crypt_ctx->subctx->unk_18;
   
   if((some_value >= crypt_ctx->subctx->nBlocks))
   {
      if(output_src != output_dst)
         memcpy(output_dst, output_src, output_size);
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   if(((int)crypt_ctx->subctx->data->flag0 & 0x4000) != 0)
   {   
      if(output_src != output_dst)
         memcpy(output_dst, output_src, output_size);
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   //=========== process tail part of source buffer ? ===============================
   
   if((crypt_ctx->subctx->data->flag0 << 0x10) >= 0)
   {   
      if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x41) != 0x41)
      {
         int tweak_key0_tail = crypt_ctx->subctx->data->block_size * (crypt_ctx->subctx->seed0_base + (crypt_ctx->subctx->nBlocks - 1));
         int tweak_key1_tail = (int)crypt_ctx->subctx->data->flag0 & 0x4000;

         unsigned char* tail_buffer = buffer + crypt_ctx->subctx->data->block_size * (crypt_ctx->subctx->nBlocks - 1);

         if((bitSize > 0x1F) || ((0xC0000B03 & (1 << bitSize)) == 0))
         {
            pfs_decrypt_sw_219D174(key, subkey_key, 0x80, IGNORE_ARG, tweak_key0_tail, tweak_key1_tail, crypt_ctx->subctx->data->block_size, crypt_ctx->subctx->data->block_size, tail_buffer, tail_buffer, crypt_ctx->subctx->data->pmi_bcl_flag);
         }
         else
         {
            int size_arg = (crypt_ctx->subctx->data->block_size <= crypt_ctx->subctx->tail_size) ? crypt_ctx->subctx->data->block_size : crypt_ctx->subctx->tail_size;
            pfs_decrypt_hw_219D480(key, subkey_key, tweak_key0_tail, tweak_key1_tail, size_arg, crypt_ctx->subctx->data->block_size, tail_buffer, tail_buffer, crypt_ctx->subctx->data->pmi_bcl_flag, crypt_ctx->subctx->data->key_id);
         }
      }
   }

   //========= copy tail result to output buffer ? ===========================
   
   if((crypt_ctx->subctx->data->flag0 << 0x10) < 0)
   {
      if(output_src != output_dst)
         memcpy(output_dst, output_src, output_size);
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   if((crypt_ctx->subctx->data->pmi_bcl_flag & 0x41) == 0x41)
   {
      if(output_src != output_dst)
         memcpy(output_dst, output_src, output_size);
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   //============== remove second encryption layer ? =========================

   //seed derrivation is quite same to derrivation in first layer

   int seed_root = crypt_ctx->subctx->data->block_size * (crypt_ctx->subctx->unk_18 + crypt_ctx->subctx->seed0_base);
   int tweak_key0_end = seed_root >> 0x20;
   int tweak_key1_end = seed_root >> 0x20;
   
   if(crypt_ctx->subctx->nBlocksTail == 0)
   {
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }

   int offset = 0;
   int counter = 0;

   if((bitSize > 0x1F) || ((0xC0000B03 & (1 << bitSize)) == 0))
   {
      do
      {
         pfs_decrypt_sw_219D174(key, subkey_key, 0x80, IGNORE_ARG, tweak_key0_end + offset, tweak_key1_end + 0, crypt_ctx->subctx->data->block_size, crypt_ctx->subctx->data->block_size, output_src + offset, output_dst + offset, crypt_ctx->subctx->data->pmi_bcl_flag);

         offset = offset + crypt_ctx->subctx->data->block_size;
         counter = counter + 1;
      }
      while(counter != crypt_ctx->subctx->nBlocksTail);

      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }
   else
   {
      int bytes_left = output_size;
      
      do
      {
         int size_arg = (crypt_ctx->subctx->data->block_size <= bytes_left) ? crypt_ctx->subctx->data->block_size : bytes_left;
         pfs_decrypt_hw_219D480(key, subkey_key, tweak_key0_end + offset, tweak_key1_end + 0, size_arg, crypt_ctx->subctx->data->block_size, output_src + offset, output_dst + offset, crypt_ctx->subctx->data->pmi_bcl_flag, crypt_ctx->subctx->data->key_id);

         offset = offset + crypt_ctx->subctx->data->block_size;
         bytes_left = bytes_left - crypt_ctx->subctx->data->block_size;
         counter = counter + 1;
      }
      while(counter != crypt_ctx->subctx->nBlocksTail);
   
      crypt_ctx->error = 0;
      return; // this should terminate crypto task (global exit)
   }
}

//TODO CHECK:
//int var_8C = (int)crypt_ctx->subctx->data->type - 2; // this does not correlate with derive_keys_from_klicensee_219B4A0
//int some_flag_base = (uint32_t)(data->pmi_bcl_flag - 2);
//int some_flag = 0xC0000B03 & (1 << some_flag_base);

//however i have double checked the code and it is correct in both places

void crypt_engine_work_3(CryptEngineWorkCtx* crypt_ctx)
{
   int seed_root = (crypt_ctx->subctx->data->block_size) * (crypt_ctx->subctx->seed0_base);
   int tweak_key0 = seed_root >> 0x20;
   int tweak_key1 = seed_root >> 0x20;

   int bitSize = (int)crypt_ctx->subctx->data->type - 2; // this does not correlate with derive_keys_from_klicensee_219B4A0
   int total_size = (crypt_ctx->subctx->data->block_size) * ((crypt_ctx->subctx->nBlocks) - 1) + (crypt_ctx->subctx->tail_size);

   unsigned char* work_buffer;
   if((bitSize > 0x1F) || ((0xC0000B03 & (1 << bitSize)) == 0))
      work_buffer = crypt_ctx->subctx->work_buffer0;
   else
      work_buffer = crypt_ctx->subctx->work_buffer1;

   //verifies table of hashes ?
   verify_step(crypt_ctx, tweak_key0, tweak_key1, bitSize, total_size, work_buffer);

   //need to add this check since dec functionality is now split into several functions
   if(crypt_ctx->error < 0)
      return;

   if(crypt_ctx->subctx->nBlocksTail == 0)
   {
      //immediately decrypts everything in while loop
      work_3_step0(crypt_ctx, tweak_key0, tweak_key1, bitSize, total_size, work_buffer);
   }
   else
   {
      //first - decrypts block part with single call
      //second - decrypts tail part with single call
      //third - decrypts everything in while loop
      work_3_step1(crypt_ctx, bitSize, work_buffer);
   }
}

void crypt_engine_work_2_4(CryptEngineWorkCtx * crypt_ctx, CryptEngineSubctx* r10)
{

}

void ScePfsCryptEngineThread_work_219BF20(CryptEngineWorkCtx *work_ctx)
{
   switch(work_ctx->subctx->opt_code)
   {
   case 2:
      crypt_engine_work_2_4(work_ctx, work_ctx->subctx);
      break;
   case 3:
      crypt_engine_work_3(work_ctx);
      break;
   case 4:
      crypt_engine_work_2_4(work_ctx, work_ctx->subctx);
      break;
   default:
      break;
   }
}