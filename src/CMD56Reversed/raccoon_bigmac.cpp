#include "raccoon_bigmac.h"

#include "Crypto/CryptoService.h"

// this is implementation of bigmac internals which are not accessable from F00D

// bigmac keyring
unsigned char bigmac_keyring[0x800 * 0x20] = {0};

// implementation of bigmac aes decryption with bugs
unsigned char bigmac_internal_buffer[0x20] = {0};

// this function emulates initialization of master keys with some known values
// values of master keys are not real
int bigmac_initialize()
{
   unsigned char key_0x204[0x20] = { 0x47, 0x47, 0x9f, 0x92, 0x8f, 0x90, 0x84, 0x7a, 0x3a, 0xfc, 0xae, 0xc5, 0x50, 0x39, 0xee, 0x47, 0x86, 0xb7, 0x10, 0x0a, 0xfa, 0x28, 0x9c, 0xaa, 0x01, 0xdb, 0x7b, 0x93, 0x3d, 0x59, 0x3d, 0x70};
   memcpy(bigmac_keyring + KEYSLOT_0x204 * 0x20, key_0x204, 0x20);

   return 0;
}

int bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(unsigned char* dst, const unsigned char* src, int keyslot, int size)
{
   // ALLOW encryption of sizes which are MULTIPLE OF 4
   if((size & 0x3) != 0)
      return -1;

   // copy SIZE bytes WITHOUT clearing the buffer first and WITHOUT PADDING it
   memcpy(bigmac_internal_buffer, src, size);

   // aes 0x128 decrypt of 0x10 bytes - result is stored in SAME internal buffer
   auto cryptops = CryptoService::get();
   int crypt_res = cryptops->aes_ecb_decrypt(bigmac_internal_buffer, bigmac_internal_buffer, 0x10, bigmac_keyring + keyslot * 0x20, 0x80);
   if(crypt_res != 0)
      return crypt_res;

   // copy SIZE bytes out
   memcpy(dst, bigmac_internal_buffer, size);

   return 0;
}

int bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(const unsigned char* src, int src_keyslot, int dst_keyslot, int size)
{
   // ALLOW encryption of sizes which are MULTIPLE OF 4
   if((size & 0x3) != 0)
      return -1;

   // copy SIZE bytes WITHOUT clearing the buffer first and WITHOUT PADDING it
   memcpy(bigmac_internal_buffer, src, size);

   // aes 0x128 decrypt of 0x10 bytes - result is stored in SAME internal buffer
   auto cryptops = CryptoService::get();
   int crypt_res = cryptops->aes_ecb_decrypt(bigmac_internal_buffer, bigmac_internal_buffer, 0x10, bigmac_keyring + src_keyslot * 0x20, 0x80);
   if(crypt_res != 0)
      return crypt_res;

   // copy SIZE bytes out
   memcpy(bigmac_keyring + dst_keyslot * 0x20, bigmac_internal_buffer, size);

   return 0;
}

// this function emulates permission checks for keyslot
int check_keyslot_permission(int keyslot)
{
   if(keyslot == KEYSLOT_0x519)
      return 0;
   return -1;
}

// implementation of key setter in bigmac keyring (will only work for some keyslots)
int bigmac_set_key_to_keyslot(const unsigned char* key, int keyslot)
{
   if(check_keyslot_permission(keyslot) != 0)
      return -1;

   memcpy(bigmac_keyring + keyslot * 0x20, key, 0x20);
   return 0;
}