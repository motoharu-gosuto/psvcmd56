#include "SceSblDMAC5DmacKRBase.h"

#include <stdexcept>

#include "F00DKeyEncryptorService.h"

using namespace f00d;

SceDmacmgrKeyringReg_t g_f00d_key_slots;

int SceSblDMAC5DmacKRBase::set_key_internal(const unsigned char* key, int key_size, int slot_id)
{
   if(key == 0)
      return -1;

   if(key_size > DMAC5_KEYSIZE)
      return -1;

   if(slot_id > DMAC5_MAX_SLOT_ID)
      return -1;

   memset(g_f00d_key_slots.keys.all_slots.slots[slot_id], 0, DMAC5_KEYSIZE);
   memcpy(g_f00d_key_slots.keys.all_slots.slots[slot_id], key, key_size);

   return 0;
}

//set key into slot directly - works for slots 0x0-0x7 and 0x1D
int SceSblDMAC5DmacKRBase::set_key(const unsigned char* key, int key_size, int slot_id)
{
   if(key == 0)
      return -1;

   if(key_size > DMAC5_KEYSIZE)
      return -1;

   if(slot_id > DMAC5_MAX_SLOT_ID)
      return -1;

   switch(slot_id)
   {
   case 0:
   case 1:
   case 2:
   case 3:
   case 4:
   case 5:
   case 6:
   case 7:
   case 0x1D:
      return set_key_internal(key, key_size, slot_id);
   default:
      return -1;
   }
}

//encrypt the key with f00d key with key_id. then set result to slot_id
int SceSblDMAC5DmacKRBase::set_key(const unsigned char* key, int key_size, int slot_id, int key_id)
{
   if(key == 0)
      return -1;

   if(key_size > DMAC5_KEYSIZE)
      return -1;

   if(slot_id > DMAC5_MAX_SLOT_ID)
      return -1;

   switch(key_id)
   {
   //only key_id 0 is supported. it is handled by F00DKeyEncryptorService
   case 0:
      {
         unsigned char drv_key[0x20] = {0}; //use max possible buffer

         //encrypt the key
         auto encryptor = F00DKeyEncryptorService::get();
         if(encryptor->encrypt_key(key, key_size * 8, drv_key) < 0)
            return -1;

         return set_key_internal(drv_key, key_size, slot_id);
      }
   default:
      throw std::runtime_error("not implemented");
   }
}

int SceSblDMAC5DmacKRBase::read_key(unsigned char* key, int key_size, int slot_id)
{
   if(key == 0)
      return -1;

   if(key_size > DMAC5_KEYSIZE)
      return -1;

   if(slot_id > DMAC5_MAX_SLOT_ID)
      return -1;

   memcpy(key, g_f00d_key_slots.keys.all_slots.slots[slot_id], key_size);
   return 0;
}