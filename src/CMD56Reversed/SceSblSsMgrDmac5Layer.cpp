#include <string>

#include "SceSblSsMgrDmac5Layer.h"

#include "sha1.h"

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptWithKeygenForDriver_1901cb5e(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, uint16_t key_id, int mask_enable)
{
   throw std::runtime_error("unsupported keygen function");
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptWithKeygenForDriver_711c057a(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, uint16_t key_id, int mask_enable)
{
   throw std::runtime_error("unsupported keygen function");
}

//

int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, uint16_t key_id, int mask_enable)
{
   throw std::runtime_error("unsupported keygen function");
}

//---------------------

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptForDriver_121fa69f(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int mask_enable)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_e6e1ad15(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int mask_enable)
{
   return 0;
}

//

int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_c517770d(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, int mask_enable)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESECBDecryptForDriver_7c978be7(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, int mask_enable)
{
   return 0;
}

//---------------------

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACForDriver_1b14658d(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int mask_enable, int command_bit)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, uint16_t key_id, int mask_enable, int command_bit)
{
   throw std::runtime_error("unsupported keygen function");
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