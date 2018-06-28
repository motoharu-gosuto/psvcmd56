#pragma once

#define DMAC5_KEYSIZE 0x20
#define DMAC5_MAX_SLOT_ID 0x1F

//Key slots 0x0-0x7 and 0x1D can be modified directly using dmac5keyring. 
#define DMAC5_KEYRING_KEY_0 0
#define DMAC5_KEYRING_KEY_1 1
#define DMAC5_KEYRING_KEY_2 2
#define DMAC5_KEYRING_KEY_3 3
#define DMAC5_KEYRING_KEY_4 4
#define DMAC5_KEYRING_KEY_5 5
#define DMAC5_KEYRING_KEY_6 6
#define DMAC5_KEYRING_KEY_7 7
#define DMAC5_KEYRING_KEY_1D 0x1D

namespace f00d
{
   #pragma pack(push,1)

   typedef struct SceDmacmgrKeyringReg_t
   {
      union
      {
         struct 
         {
            char slot_00[DMAC5_KEYSIZE];
            char slot_01[DMAC5_KEYSIZE];
            char slot_02[DMAC5_KEYSIZE];
            char slot_03[DMAC5_KEYSIZE];
            char slot_04[DMAC5_KEYSIZE];
            char slot_05[DMAC5_KEYSIZE];
            char slot_06[DMAC5_KEYSIZE];
            char slot_07[DMAC5_KEYSIZE];
            char slot_08[DMAC5_KEYSIZE];
            char slot_09[DMAC5_KEYSIZE];
            char slot_0A[DMAC5_KEYSIZE];
            char slot_0B[DMAC5_KEYSIZE];
            char slot_0C[DMAC5_KEYSIZE];
            char slot_0D[DMAC5_KEYSIZE];
            char slot_0E[DMAC5_KEYSIZE];
            char slot_0F[DMAC5_KEYSIZE];
            char slot_10[DMAC5_KEYSIZE];
            char slot_11[DMAC5_KEYSIZE];
            char slot_12[DMAC5_KEYSIZE];
            char slot_13[DMAC5_KEYSIZE];
            char slot_14[DMAC5_KEYSIZE];
            char slot_15[DMAC5_KEYSIZE];
            char slot_16[DMAC5_KEYSIZE];
            char slot_17[DMAC5_KEYSIZE];
            char slot_18[DMAC5_KEYSIZE];
            char slot_19[DMAC5_KEYSIZE];
            char slot_1A[DMAC5_KEYSIZE];
            char slot_1B[DMAC5_KEYSIZE];
            char slot_1C[DMAC5_KEYSIZE];
            char slot_1D[DMAC5_KEYSIZE];
            char slot_1E[DMAC5_KEYSIZE];
            char slot_1F[DMAC5_KEYSIZE];
         } each_slot;
         struct
         {
            char slots[DMAC5_MAX_SLOT_ID + 1][DMAC5_KEYSIZE];
         } all_slots;
      } keys;
     
   } SceDmacmgrKeyringReg_t;

   #pragma pack(pop)

   class SceSblDMAC5DmacKRBase
   {
   private:
      static int set_key_internal(unsigned char* key, int key_size, int slot_id);

   public:
      //set key into slot directly - works for slots 0x0-0x7 and 0x1D
      // key_size - in bytes
      static int set_key(unsigned char* key, int key_size, int slot_id);

      //encrypt the key with f00d key with key_id. then set result to slot_id
      // key_size - in bytes
      static int set_key(unsigned char* key, int key_size, int slot_id, int key_id);
   };
}