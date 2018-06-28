#include <string>

#include "SceSblSsMgrDmac5Layer.h"

#include "sha1.h"
#include "aes.h"

#include <windows.h>

#include <Dmac5Client.h>
#include <Dmac5ClientAPI.h>

#include "F00DKeyEncryptor.h"

#ifdef USE_PSVDMAC5
SOCKET dmac5_socket = 0;
#endif

#ifdef USE_PSVDMAC5
int initialize_dmac5_context()
{
   return dmac5::initialize_dmac5_proxy_connection(dmac5_socket);
}
#endif

#ifdef USE_PSVDMAC5
int deinitialize_dmac5_context()
{
   return dmac5::deinitialize_dmac5_proxy_connection(dmac5_socket);
}
#endif

//this works
int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptWithKeygenForDriver_1901cb5e(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, uint16_t key_id, int mask_enable)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESCBCDecryptWithKeygen(dmac5_socket, src, dst,size, key, key_size,iv,key_id,mask_enable);
   #else
   F00DKeyEncryptor ec;
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(ec.encrypt_key(key, key_size, drv_key) < 0)
      return -1;

   aes_context aes_ctx;
   memset(&aes_ctx, 0, sizeof(aes_ctx));
   aes_setkey_dec(&aes_ctx, drv_key, key_size);
   aes_crypt_cbc(&aes_ctx, AES_DECRYPT, size, iv, src,dst);

   return 0;
   #endif
}

// this works
int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptWithKeygenForDriver_711c057a(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, uint16_t key_id, int mask_enable)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESCBCEncryptWithKeygen(dmac5_socket, src, dst, size, key, key_size, iv, key_id, mask_enable);
   #else
   F00DKeyEncryptor ec;
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(ec.encrypt_key(key, key_size, drv_key) < 0)
      return -1;

   aes_context aes_ctx;
   memset(&aes_ctx, 0, sizeof(aes_ctx));
   aes_setkey_enc(&aes_ctx, drv_key, key_size);
   aes_crypt_cbc(&aes_ctx, AES_ENCRYPT, size, iv, src,dst);

   return 0;
   #endif
}

//this works
int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, uint16_t key_id, int mask_enable)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESECBEncryptWithKeygen(dmac5_socket, src, dst, size, key, key_size, key_id, mask_enable);
   #else
   F00DKeyEncryptor ec;
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(ec.encrypt_key(key, key_size, drv_key) < 0)
      return -1;

   aes_context aes_ctx;
   memset(&aes_ctx, 0, sizeof(aes_ctx));
   aes_setkey_enc(&aes_ctx, drv_key, key_size);
   aes_crypt_ecb(&aes_ctx, AES_ENCRYPT, src, dst);

   return 0;
   #endif
}

//---------------------

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptForDriver_121fa69f(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int mask_enable)
{
   throw std::runtime_error("not implemented");
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_e6e1ad15(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int mask_enable)
{
   throw std::runtime_error("not implemented");
}

//

int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, int mask_enable)
{
   throw std::runtime_error("not implemented");
}

int SceSblSsMgrForDriver_sceSblSsMgrAESECBDecryptForDriver_7c978be7(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, int mask_enable)
{
   throw std::runtime_error("not implemented");
}

//---------------------

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int mask_enable, int command_bit)
{
   throw std::runtime_error("not implemented");
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, uint16_t key_id, int mask_enable, int command_bit)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESCMACWithKeygen(dmac5_socket, src, dst, size, key, key_size, iv, key_id, mask_enable, command_bit);
   #else
   F00DKeyEncryptor ec;
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(ec.encrypt_key(key, key_size, drv_key) < 0)
      return -1;

   aes_context aes_ctx;
   memset(&aes_ctx, 0, sizeof(aes_ctx));
   aes_setkey_enc(&aes_ctx, drv_key, key_size);

   unsigned char* src_cpy = new unsigned char[size];
   memcpy(src_cpy, src, size);
   aes_cmac(&aes_ctx, size, src_cpy, dst);
   delete [] src_cpy;

   return 0;
   #endif
}

int SceSblSsMgrForDriver_sceSblSsMgrSHA1ForDriver_eb3af9b5(const unsigned char* src, unsigned char* dst, int size, unsigned char* iv, int mask_enable, int command_bit)
{
   if(iv != 0)
      throw std::runtime_error("unsupported iv");

   if(mask_enable != 1)
      throw std::runtime_error("unsupported mask_enable");

   if(command_bit != 0)
      throw std::runtime_error("unsupported command_bit");

   sha1(src, size, dst);

   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrHMACSHA1ForDriver_6704d985(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, unsigned char* iv, int mask_enable, int command_bit)
{
   if(iv != 0)
      throw std::runtime_error("unsupported iv");

   if(mask_enable != 1)
      throw std::runtime_error("unsupported mask_enable");

   if(command_bit != 0)
      throw std::runtime_error("unsupported command_bit");

   sha1_hmac(key, 0x14, src, size, dst);

   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf(char *src, char *dst, int size, int slot_id, int key_size, int mask_enable)
{
   return 0;
}