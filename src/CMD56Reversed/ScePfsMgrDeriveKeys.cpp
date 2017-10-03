#include "Constants.h"
#include "SceIofilemgr.h"

#include <stdint.h>

typedef struct buffer_list
{
    SceUID mutex_id;
    uint32_t unk_4;
    uint32_t unk_8;
    uint32_t unk_C;
    uint32_t unk_10;
    void* bcl; //0x14 - one of versions is pfs_pmi_buffer_list_ctx
}buffer_list;

typedef struct pfs_pmi_buffer_list_ctx
{
    buffer_list* blist;
    uint32_t unk_4;
    SceUID ScePfsPmi_mutex_id; // 0x08
    char original_path[0x3F];  // 0xC
    
    char mount_point1[0x22]; // 0x4C - /%s
    
    char mount_point2[0x23];  // 0x6E - %s0:
    
    char unk_91;
    
    uint16_t type;   //0x92
    uint16_t unk_94; //0x94 = 0
    
    char klicensee[0x10]; //0x96
    
    uint16_t unk_A6; // = 0
    uint32_t unk_A8; // = 0
    uint32_t unk_AC; // = 0
    
    SceUID ScePfsFilesDb_mutex_id; // 0xB0
    
    char unk_data1[0xBC]; // 0xB4
    
    pfs_pmi_buffer_list_ctx *bcl; //0x170
    uint32_t unk_174;
    SceUInt64 auth_id;
    
    char unk_data2[0x78]; // 0x180

    vfs_block_dev_info block_dev; // 0x1F8

    uint32_t unk_20C;
    
    //further fields are unknown
} pfs_pmi_buffer_list_ctx;

typedef struct CryptEngineData //size is 0x60
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint16_t unk_C;
   uint16_t flag; // 0xE - flag that selects decryption type ?
   
   uint16_t key_id; //0x10
   uint16_t seed1_base; //iv seed
   
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t size1;
   char key[0x10]; //0x2C
   
   char iv_xor_key[0x10]; //0x3C
   
   char hmac_key[0x10]; //0x4C

   uint32_t unk_5C;

}CryptEngineData;

typedef struct CryptEngineSubctx //size is 0x58
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t opt_code; // 0x8 - if 3 then decrypt, if 4 then encrypt, if 2 then encrypt
   CryptEngineData* data; // 0xC
   
   uint32_t unk_10;
   uint32_t source; // 0x14
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t size2; //0x28
   uint32_t nDigests; // 0x2C - also digest table index
   
   uint32_t unk_30;
   uint32_t seed0_base; // 0x34
   uint32_t dest_offset; // 0x38
   uint32_t size0; // 0x3C
   
   uint32_t size1;
   uint32_t unk_44;
   uint32_t size3; //0x48
   char* hmac_sha1_digest; // digest to verify (possibly table)
   
   void* buffer0; // 0x50
   void* buffer1; // 0x54
   
}CryptEngineSubctx;

typedef struct CryptEngineWorkCtx //size is 0x18
{
   void* unk_0; // pointer to data 0x140 + 0x18 ?
   void* unk_4; // pointer to data 0x140 + 0x18 ?
   CryptEngineSubctx* subctx; // 0x8
   uint32_t error; //set to 0 or error code after executing crypto task
   
   SceUID threadId; // = set with sceKernelGetThreadIdForDriver. used with ksceKernelSignalCondTo
   uint32_t unk_14;
   
}CryptEngineWorkCtx;

int loc_219B544()
{
   /*
   ADD.W           R0, R4, #0x4C ; hmac_key in data
   LDRH.W          R4, [R5,#0xA6]
   LDRH.W          R3, [R5,#0x94] ; flags
   MOV             R1, R6  ; klicensee
   LDR.W           R2, [R5,#0xA8] ; unk2
   STRD.W          R8, R4, [SP] ; int salt, ?
   BL              combine_klicensee_digest_219E1D8
   ADD             SP, SP, #0x14
   VPOP            {D8}
   */
   return 0;
}

int derive_keys_from_klicensee_219B4A0(CryptEngineData *data, int salt, int unk2, int unk3, int arg_0, int arg_4, int arg_8, pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
{
   /*
   MOV             R4, R0
   VPUSH           {D8}
   SUB             SP, SP, #0x14 ; salt
   MOV             R8, R1  ;  int salt
   VMOV            D8, R2, R3
   LDRH.W          R10, [SP,#0x38+arg_0]
   LDRD.W          R7, R5, [SP,#0x38+arg_8] ; R7 = pfs_pmi_buffer_list_ctx *pfs_pmi_bcl
   BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
   MOV.W           R3, #0x100
   */

   if(r0 != 0)
   {
      /*
      LDR             R3, [R0,#0x2C]
      CMP             R3, #0
      IT GE
      UXTHGE          R3, R3
      */
   }

   /*
   STR             R3, [R4,#0x18]
   BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
   MOVS            R3, #0xF
   */

   if(r0 != 0)
   {
      /*
      LDR             R3, [R0,#0x28]
      */
   }

   /*
   LDRH.W          R12, [R5,#0x92] ; type
   ADD.W           R6, R5, #0x96 ; offset to klicensee
   LDRH.W          LR, [R5,#0x94]
   MOV             R0, R7
   LDRH.W          R1, [R5,#0xA6]
   LDR.W           R2, [R5,#0xA8]
   STR             R3, [R4,#0x14]
   LDR             R3, [SP,#0x38+arg_4]
   STRD.W          R2, R8, [R4,#4] ; R8 =  int salt
   STR             R3, [R4,#0x1C]
   STRH.W          R12, [R4,#0xC]
   STRH.W          LR, [R4,#0xE]
   STRH.W          R10, [R4,#0x12]
   STRH            R1, [R4,#0x10]
   VSTR            D8, [R4,#0x20]
   STR             R6, [R4] ; char* klicensee
   LDR             R3, [R7,#0x14]
   BLX             R3
   LDRH            R2, [R4,#0xE]
   STR             R0, [R4,#0x28]
   SUBS            R2, #2
   UXTH            R2, R2
   */

   if(r2 > 0x1F)
   {
      /*
      LDR.W           R3, [R5,#0xA8] ; ignored
      ADD.W           R0, R4, #0x2C ; result0 - key in data
      STR.W           R8, [SP,#0x38+salt] ; salt
      ADD.W           R1, R4, #0x3C ; result1 - iv_xor_key in data
      MOV             R2, R6  ; klicensee
      BL              calculate_sha1_chain_219E1CC
      */

      return loc_219B544();
   }
   else
   {
      /*
      MOVS            R1, #1
      MOVW            R3, #0xB03
      LSL.W           R2, R1, R2
      MOVT.W          R3, #0xC000
      ANDS            R3, R2
      */

      if(r3 == 0)
      {
         /*
         LDR.W           R3, [R5,#0xA8] ; ignored
         ADD.W           R0, R4, #0x2C ; result0 - key in data
         STR.W           R8, [SP,#0x38+salt] ; salt
         ADD.W           R1, R4, #0x3C ; result1 - iv_xor_key in data
         MOV             R2, R6  ; klicensee
         BL              calculate_sha1_chain_219E1CC
         */

         return loc_219B544();
      }
      else
      {
         /*
         LDR             R2, [R7,#0x40]
         */

         if(r2 != 0 && r2 != 3)
         {
            /*
            LDRH.W          LR, [R5,#0x94]
            ADD.W           R0, R4, #0x2C ; result0 - key in data
            LDRH.W          R7, [R5,#0xA6]
            ADD.W           R1, R4, #0x3C ; result1 - iv_xor_key in data
            LDR.W           R3, [R5,#0xA8] ; unk3
            MOV             R2, R6  ; klicensee
            STRD.W          LR, R8, [SP] ; ?,  int salt
            STR             R7, [SP,#0x38+data_len]
            BL              hmac1_sha1_or_sha1_chain_219E0DC
            */
            return loc_219B544();
         }
         else
         {
            /*
            LDR             R3, [R7,#0x58]
            */

            if(r3 <= 1)
            {
               /*
               LDRH.W          LR, [R5,#0x94]
               ADD.W           R0, R4, #0x2C ; result0 - key in data
               LDRH.W          R7, [R5,#0xA6]
               ADD.W           R1, R4, #0x3C ; result1 - iv_xor_key in data
               LDR.W           R3, [R5,#0xA8] ; unk3
               MOV             R2, R6  ; klicensee
               STRD.W          LR, R8, [SP] ; ?,  int salt
               STR             R7, [SP,#0x38+data_len]
               BL              hmac1_sha1_or_sha1_chain_219E0DC
               */
               return loc_219B544();
            }
            else
            {
               /*
               ADD.W           R0, R4, #0x2C ; result0 - key in data
               ADD.W           R1, R4, #0x3C ; result1 - iv_xor_key in data
               LDRH.W          R3, [R5,#0x94] ; unk3
               LDRH.W          LR, [R5,#0xA6]
               */

               if(r2 == 0)
               {
                  /*
                  ADDS            R7, #0x84
                  */
                  /*
                  MOVS            R2, #0x14
                  STRD.W          LR, R7, [SP]
                  STR             R2, [SP,#0x38+data_len] ; data_len
                  MOV             R2, R6  ; klicensee
                  BL              hmac_sha1_219E164
                  */
                  return loc_219B544();
               }
               else
               {
                  if(r2 == 3)
                  {
                     /*
                     ADDS            R7, #0x84
                     */
                     /*
                     MOVS            R2, #0x14
                     STRD.W          LR, R7, [SP]
                     STR             R2, [SP,#0x38+data_len] ; data_len
                     MOV             R2, R6  ; klicensee
                     BL              hmac_sha1_219E164
                     */
                     return loc_219B544();
                  }
                  else
                  {
                     /*
                     MOVNE           R7, #0
                     */
                     /*
                     MOVS            R2, #0x14
                     STRD.W          LR, R7, [SP]
                     STR             R2, [SP,#0x38+data_len] ; data_len
                     MOV             R2, R6  ; klicensee
                     BL              hmac_sha1_219E164
                     */
                     return loc_219B544();
                  }
               }
            }
         }
      }
   }
}