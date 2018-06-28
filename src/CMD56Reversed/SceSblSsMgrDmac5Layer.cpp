#include <string>

#include "SceSblSsMgrDmac5Layer.h"

#include <windows.h>

#include <Dmac5Client.h>
#include <Dmac5ClientAPI.h>

#include "SceSblAuthMgr.h"
#include "Crypto/CryptoService.h"
#include "F00D/SceSblDMAC5DmacKRBase.h"

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

#define DEFAULT_AVAILABLE_SLOT 0xC

//this function operates on range of slots from 0xC to 0x17 including
//for sake of simplicity we dont do this here
//just select first available slot which is 0xC
int w_ksceSblAuthMgrSetDmac5Key_B9A874(const unsigned char *key, int key_size, int *slot_id, int key_id)
{
   //set the key into slot
   if(SceSblAuthMgr_sceSblAuthMgrSetDmac5KeyForKernel_0x122acdea(key, key_size, DEFAULT_AVAILABLE_SLOT, key_id) < 0)
      return -1;

   //return chosen slot
   *slot_id = DEFAULT_AVAILABLE_SLOT;
   return 0;
}

//this works
int SceSblSsMgrForDriver_sceSblSsMgrAESCBCDecryptWithKeygenForDriver_1901cb5e(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int key_id, int mask_enable)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESCBCDecryptWithKeygen(dmac5_socket, src, dst,size, key, key_size,iv,key_id,mask_enable);
   #else

   //set the key
   int slot_id = 0;
   if(w_ksceSblAuthMgrSetDmac5Key_B9A874(key, key_size, &slot_id, key_id) < 0)
      return -1;

   //retrive the key
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(f00d::SceSblDMAC5DmacKRBase::read_key(drv_key, key_size, slot_id) < 0)
      return -1;

   //invoke crypto operation
   auto cryptops = CryptoService::get();
   cryptops->aes_cbc_decrypt(src, dst, size, drv_key, key_size, iv);

   return 0;
   #endif
}

// this works
int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptWithKeygenForDriver_711c057a(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int key_id, int mask_enable)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESCBCEncryptWithKeygen(dmac5_socket, src, dst, size, key, key_size, iv, key_id, mask_enable);
   #else

   //set the key
   int slot_id = 0;
   if(w_ksceSblAuthMgrSetDmac5Key_B9A874(key, key_size, &slot_id, key_id) < 0)
      return -1;

   //retrive the key
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(f00d::SceSblDMAC5DmacKRBase::read_key(drv_key, key_size, slot_id) < 0)
      return -1;

   //invoke crypto operation
   auto cryptops = CryptoService::get();
   cryptops->aes_cbc_encrypt(src, dst, size, drv_key, key_size, iv);

   return 0;
   #endif
}

//this works
int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptWithKeygenForDriver_0f7d28af(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, int key_id, int mask_enable)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESECBEncryptWithKeygen(dmac5_socket, src, dst, size, key, key_size, key_id, mask_enable);
   #else

   //set the key
   int slot_id = 0;
   if(w_ksceSblAuthMgrSetDmac5Key_B9A874(key, key_size, &slot_id, key_id) < 0)
      return -1;

   //retrive the key
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(f00d::SceSblDMAC5DmacKRBase::read_key(drv_key, key_size, slot_id) < 0)
      return -1;

   //invoke crypto operation
   auto cryptops = CryptoService::get();
   cryptops->aes_ecb_encrypt(src, dst, size, drv_key, key_size);

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

int SceSblSsMgrForDriver_sceSblSsMgrAESCMACWithKeygenForDriver_83b058f5(const unsigned char* src, unsigned char* dst, int size, const unsigned char* key, int key_size, unsigned char* iv, int key_id, int mask_enable, int command_bit)
{
   #ifdef USE_PSVDMAC5
   return dmac5::sceSblSsMgrAESCMACWithKeygen(dmac5_socket, src, dst, size, key, key_size, iv, key_id, mask_enable, command_bit);
   #else

   //set the key
   int slot_id = 0;
   if(w_ksceSblAuthMgrSetDmac5Key_B9A874(key, key_size, &slot_id, key_id) < 0)
      return -1;

   //retrive the key
   unsigned char drv_key[0x20] = {0}; //use max possible buffer
   if(f00d::SceSblDMAC5DmacKRBase::read_key(drv_key, key_size, slot_id) < 0)
      return -1;

   //invoke crypto operation
   auto cryptops = CryptoService::get();
   cryptops->aes_cmac(src, dst, size, drv_key, key_size);

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

   auto cryptops = CryptoService::get();
   cryptops->sha1(src, dst, size);

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

   auto cryptops = CryptoService::get();
   cryptops->hmac_sha1(src, dst, size, key, 0x14);

   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf(const unsigned char *src, unsigned char *dst, int size, int slot_id, int key_size, int mask_enable)
{
   /*
   unsigned char key[8];

   auto cryptops = CryptoService::get();
   cryptops->des_encrypt(src, dst, size, key);

   return 0;
   */

   throw std::runtime_error("not implemented");
}