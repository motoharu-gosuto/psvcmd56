#include "Constants.h"
#include "SceIofilemgr.h"

#include <stdint.h>
#include <string>

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
    uint16_t flag; //0x94 = 0
    
    char klicensee[0x10]; //0x96
    
    uint16_t key_id; // = 0
    uint32_t salt0; // 0xA8 = 0
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
   const char* klicensee;
   uint32_t salt0;
   uint32_t salt1;
   uint16_t type;
   uint16_t flag; // 0xE - flag that selects decryption type ?
   
   uint16_t key_id; // 0x10
   uint16_t seed1_base; // 0x12 iv seed
   
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t size1; //0x28
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

//----------------------

int SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(const char *source, int size, char *result)
{
   return 0;
}

int sha1Digest_219DE54(char *result, const char *source, int size)
{
   return SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(source, size, result);
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const char* key, int key_len, const char* data, int data_len, char* digest)
{
   return 0;
}

int hmacSha1Digest_219DE68(char* digest, const char* key, const char* data, int data_len)
{
   return SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(key, 0x14, data, data_len, digest);
}

//----------------------

int calculate_sha1_chain_219E008(char* key, char* iv_xor_key, const char* klicensee, uint32_t salt1)
{
   int saltin[2] = {0};
   char base0[0x14] = {0};
   char base1[0x14] = {0};
   char combo[0x28] = {0};
   char drvkey[0x14] = {0};

   saltin[0] = salt1;

   sha1Digest_219DE54(base0, klicensee, 0x10); //calculate hash of klicensee

   // derive key 0

   saltin[1] = 1;
   
   sha1Digest_219DE54(base1, (char*)saltin, 8); //calculate hash of salt 0

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);
   
   sha1Digest_219DE54(drvkey, combo, 0x28); //calculate hash from combination of salt 0 hash and klicensee hash

   memcpy(key, drvkey, 0x10);  //copy derived key

   // derive key 1
   
   saltin[1] = 2;

   sha1Digest_219DE54(base1, (char*)saltin, 8); //calculate hash of salt 1

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);

   sha1Digest_219DE54(drvkey, combo, 0x28); //calculate hash from combination of salt 1 hash and klicensee hash

   memcpy(iv_xor_key, drvkey, 0x10); //copy derived key

   return 0;
}

int calculate_sha1_chain_219E1CC(char* key, char* iv_xor_key, const char* klicensee, uint32_t ignored_salt0, uint32_t salt1)
{
   return calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt1);
}

char hmac_key_21A93C8[0x14] = {0xE4, 0x62, 0x25, 0x8B, 0x1F, 0x31, 0x21, 0x56, 0x07, 0x45, 0xDB, 0x62, 0xB1, 0x43, 0x67, 0x23, 0xD2, 0xBF, 0x80, 0xFE}; 

int hmac1_sha1_or_sha1_chain_219E0DC(char* key, char* iv_xor_key, const char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t ignored_key_id)
{
   if((flag & 2) == 0)
   {
      calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt1);
      return 0;
   }

   int saltin0[1] = {0};
   int saltin1[2] = {0};
   char drvkey[0x14] = {0};

   memcpy(key, klicensee, 0x10);

   if(salt0 == 0)
   {
      saltin0[0x00] = salt1;
      hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, (char*)saltin0, 4); // derive key with one salt
   }
   else
   {
      saltin1[0] = salt0;
      saltin1[1] = salt1;
      hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, (char*)saltin1, 8); // derive key with two salts
   }

   memcpy(iv_xor_key, drvkey, 0x10); //copy derived key

   return 0;
}

int hmac_sha1_219E164(char* key, char* iv_xor_key, const char* klicensee, uint16_t ignored_flag, uint16_t ignored_key_id, const char* base_key, uint32_t base_key_len)
{
   char drvkey[0x14] = {0};

   hmacSha1Digest_219DE68(drvkey, hmac_key_21A93C8, base_key, base_key_len);

   memcpy(key, klicensee, 0x10);

   memcpy(iv_xor_key, drvkey, 0x10);

   return 0;
}

int calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(char *sha1_combined_digest, char *klicensee, int salt0, int salt1, int key_id)
{
   return 0;
}

int combine_klicensee_digest_219E1D8(char* hmac_key, const char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t key_id)
{
   /*
   MOV             R4, 0x9EA004
   SUB             SP, SP, #0x78
   MOV             R8, R0  ; char*
   LDR             R5, [R4]
   LDR             R6, [SP,#0x90+salt]
   LDRH.W          R7, [SP,#0x90+arg_4]
   STR             R5, [SP,#0x90+var_1C]
   LSLS            R5, R3, #0x1F ; check bit 0
   */

   if(BMI)
   {
      /*
      MOVS            R1, #0
      MOVS            R2, #0x14 ; num
      BLX             ScePfsMgr.SceSysclibForDriver._imp_memset_0ab9bf5c ; set combined digest to 0
      */
      return 0;
   }
   else
   {
      /*
      LSLS            R3, R3, #0x1E ; check bit 1
      */

      if(BMI)
      {
         /*
         STR             R7, [SP,#0x90+key_id]
         MOV             R3, R6  ; salt1
         BL              calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38
         */

         return 0;
      }
      else
      {
         /*
         MOVS            R2, #0x10 ; size - construct digest with utils functions
         ADD             R0, SP, #0x90+klicensee_sha1_digest ; result
         BL              sha1Digest_219DE54 ; calculate digest of *klicensee
         ADD             R7, SP, #0x90+klicensee_sha1_digest
         MOVS            R3, #0xA
         ADD             R1, SP, #0x90+data_for_sha1 ; source
         MOVS            R2, #8  ; size
         ADD             R0, SP, #0x90+sha_digest_58 ; result
         STRD.W          R3, R6, [SP,#0x90+data_for_sha1] ; 0x0A, arg_0
         BL              sha1Digest_219DE54
         LDMIA           R7!, {R0-R3} ; klicensee_sha1_digest
         ADD             R6, SP, #0x90+sha_digest_58
         ADD.W           LR, SP, #0x90+klicensee_sha1_digest_copy
         ADD             R5, SP, #0x90+sha_digest_58_copy
         STMIA.W         LR!, {R0-R3} ; store klicensee digest
         LDR             R7, [R7] ; load klicensee digest
         LDMIA           R6!, {R0-R3}
         STR.W           R7, [LR] ; store klicensee digest
         LDR             R6, [R6]
         STMIA           R5!, {R0-R3}
         ADD             R1, SP, #0x90+klicensee_sha1_digest_copy ; source
         MOVS            R2, #0x28 ; unk2 - 40 dec - size of two sha1 digests
         ADD             R0, SP, #0x90+total_sha1_digest_80 ; result holder
         STR             R6, [R5]
         ADD             R5, SP, #0x90+total_sha1_digest_80 ; result holder
         BL              sha1Digest_219DE54 ; calculate total digest
         LDMIA           R5!, {R0-R3} ; load total digest
         STR.W           R0, [R8] ; store result
         LDR             R0, [R5] ; load total digest
         STR.W           R1, [R8,#4] ; store result
         STR.W           R2, [R8,#8] ; store result
         STR.W           R0, [R8,#0x10] ; store result
         STR.W           R3, [R8,#0xC] ; store result
         */

         return 0;
      }
   }
}

struct derive_keys_ctx;

typedef int(derive_keys_sub_219A29C_cb)(const derive_keys_ctx*);

typedef struct derive_keys_ctx
{
   derive_keys_sub_219A29C_cb* unk_14; //function pointer

   uint32_t unk_40;


   uint32_t unk_58;
   uint32_t unk_68;

   char base_key[0x14]; // 0x84

}derive_keys_ctx;

int sub_219A29C(const derive_keys_ctx* ctx)
{
   return ctx->unk_68;
}

typedef struct ctx_12f8d58e
{
   uint32_t unk_28;
   uint32_t unk_2C;

}ctx_12f8d58e;

ctx_12f8d58e* SceIofilemgrForDriver_thread_related_12f8d58e()
{
   return 0;
}

int derive_keys_from_klicensee_219B4A0(CryptEngineData *data, uint32_t salt1, int unk2, int unk3, uint16_t seed1_base, int arg_4, const derive_keys_ctx* drv_ctx, const pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
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
   data->flag = pfs_pmi_bcl->flag;
   data->key_id = pfs_pmi_bcl->key_id;
   data->seed1_base = seed1_base;
   
   data->unk_20 = unk2;
   data->unk_24 = unk3;

   data->klicensee = pfs_pmi_bcl->klicensee;

   data->size1 = drv_ctx->unk_14(drv_ctx);
   
   int some_flag_base = (uint32_t)(data->flag - 2);
   int some_flag = 0xC0000B03 & (1 << some_flag_base);

   if((some_flag_base > 0x1F) || (some_flag == 0))
   {
      calculate_sha1_chain_219E1CC(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, salt1);
      return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
   }
   else
   {
      if((drv_ctx->unk_40 != 0 && drv_ctx->unk_40 != 3) || (drv_ctx->unk_58 <= 1))
      {    
         hmac1_sha1_or_sha1_chain_219E0DC(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
         return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
      }
      else
      {
         if(drv_ctx->unk_40 == 0 || drv_ctx->unk_40 == 3)
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->flag, pfs_pmi_bcl->key_id, drv_ctx->base_key, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
         }
         else
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->flag, pfs_pmi_bcl->key_id, 0, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->salt0, pfs_pmi_bcl->flag, salt1, pfs_pmi_bcl->key_id);
         }
      }
   }
}