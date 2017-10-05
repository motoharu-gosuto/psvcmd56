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
   
   char hmac_key[0x14]; //0x4C

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

typedef struct ctx_12f8d58e
{
   uint32_t unk_28;
   uint32_t unk_2C;

}ctx_12f8d58e;

//----------------------

ctx_12f8d58e* SceIofilemgrForDriver_thread_related_12f8d58e()
{
   return 0;
}

int SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(const char *source, int size, char *result)
{
   return 0;
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(const char* key, int key_len, const char* data, int data_len, char* digest)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_711c057a(const char* src, char* dst, int size, const char* key, int key_size, char* iv, uint16_t key_id, int mask_enable)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_0f7d28af(const char* src, char* dst, int size, const char* key, int key_size, uint16_t key_id, int mask_enable)
{
   return 0;
}

//----------------------

int sha1Digest_219DE54(char *result, const char *source, int size)
{
   return SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(source, size, result);
}

int hmacSha1Digest_219DE68(char* digest, const char* key, const char* data, int data_len)
{
   return SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(key, 0x14, data, data_len, digest);
}

//----------------------

char hmac_key_21A93C8[0x14] = {0xE4, 0x62, 0x25, 0x8B, 0x1F, 0x31, 0x21, 0x56, 0x07, 0x45, 0xDB, 0x62, 0xB1, 0x43, 0x67, 0x23, 0xD2, 0xBF, 0x80, 0xFE}; 

char hmac_key_21A93DC[0x14] = {0xAF, 0xE6, 0x56, 0xBB, 0x3C, 0x17, 0x25, 0x6A, 0x3C, 0x80, 0x9F, 0x6E, 0x9B, 0xF1, 0x9F, 0xDD, 0x5A, 0x38, 0x85, 0x43};

char iv_21A93F0[0x10] = {0x74, 0xD2, 0x0C, 0xC3, 0x98, 0x81, 0xC2, 0x13, 0xEE, 0x77, 0x0B, 0x10, 0x10, 0xE4, 0xBE, 0xA7};

//-------------------------------------

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

int encrypt_aes_cbc_encrypt_aes_ecb_with_key_id_callback_219D9F4(const char* klicensee, char* iv, uint32_t size, const char* src, char* dst, uint16_t key_id)
{
   uint16_t kid = 0 - (key_id - 1) + (key_id - 1); // ???

   int size_tail = size & 0xF; // get size of tail
   int size_block = size & (~0xF); // get block size aligned to 0x10 boundary
   
   //encrypt N blocks of source data with klicensee and iv

   if(size_block != 0)
   {
      int result0 = SceSblSsMgrForDriver_sceSblSsMgrAESCBCEncryptForDriver_711c057a(src, dst, size_block, klicensee, 0x80, iv, kid, 1);
      if(result0 != 0)
         return result0;  
   }

   //handle tail section

   if(size_tail == 0)
      return 0;

   //align destination buffer

   char iv_enc[0x10] = {0};
   char* iv_enc_aligned = iv_enc + ((0 - (int)iv_enc) & 0x3F);

   //encrypt iv using klicensee
     
   int result1 = SceSblSsMgrForDriver_sceSblSsMgrAESECBEncryptForDriver_0f7d28af(iv, iv_enc_aligned, 0x10, klicensee, 0x80, kid, 1);
   if(result1 != 0)
      return result1;

   //produce destination tail by xoring source tail with encrypted iv

   for(int i = 0; i < size_tail; i++)
      dst[size_block + i] = src[size_block + i] ^ iv_enc_aligned[i];

   return 0;
}

int calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(char* hmac_key, const char* klicensee, uint32_t salt0, uint32_t salt1, uint16_t key_id)
{
   char drvkey[0x14] = {0};
   char iv[0x10] = {0};
   char combo[0x14] = {0};

   //align buffers

   char* drvkey_aligned = drvkey + ((0 - (int)drvkey) & 0x3F);
   char* iv_aligned = iv + ((0 - (int)iv) & 0x3F);
   char* combo_aligned = combo + ((0 - (int)combo) & 0x3F);

   int saltin0[1] = {0};
   int saltin1[2] = {0};
   char base[0x14] = {0};

   if(salt0 == 0)
   {
      saltin0[0] = salt1;
      hmacSha1Digest_219DE68(base, hmac_key_21A93DC, (char*)saltin0, 4); // derive base with one salt
   }
   else
   {
      saltin1[0] = salt0;
      saltin1[1] = salt1;
      hmacSha1Digest_219DE68(base, hmac_key_21A93DC, (char*)saltin1, 8); // derive base with two salts
   }

   memcpy(combo_aligned, base, 0x14); // calculated digest will be src data

   memcpy(iv_aligned, iv_21A93F0, 0x10); //initialize iv

   encrypt_aes_cbc_encrypt_aes_ecb_with_key_id_callback_219D9F4(klicensee, iv_aligned, 0x14, combo_aligned, drvkey_aligned, key_id);

   memcpy(hmac_key, drvkey_aligned, 0x14); // copy derived key
   
   return 0;
}

int combine_klicensee_digest_219E1D8(char* hmac_key, const char* klicensee, uint32_t salt0, uint16_t flag, uint32_t salt1, uint16_t key_id)
{
   if((flag << 0x1F) < 0) // check bit 0
   {
      memset(hmac_key, 0, 0x14);
      return 0;
   }

   if((flag << 0x1E) < 0) // check bit 1
   {
      calculate_aes_cbc_encrypted_hmac_sha1_digest_219DF38(hmac_key, klicensee, salt0, salt1, key_id);
      return 0;
   }

   int saltin[2] = {0};
   char base0[0x14] = {0};
   char base1[0x14] = {0};
   char combo[0x28] = {0};
   char drvkey[0x14] = {0};

   sha1Digest_219DE54(base0, klicensee, 0x10); // calculate digest of klicensee

   saltin[0] = 0xA;
   saltin[1] = salt1;

   sha1Digest_219DE54(base1, (char*)saltin, 8); // calculate digest of salt

   memcpy(combo, base0, 0x14);
   memcpy(combo + 0x14, base1, 0x14);
         
   sha1Digest_219DE54(drvkey, combo, 0x28); // calculate digest of combination of klicensee and salt digests
               
   memcpy(hmac_key, drvkey, 0x14); // copy derived key

   return 0;
}

//-------------------------------------

int sub_219A29C(const derive_keys_ctx* ctx)
{
   return ctx->unk_68;
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

//-------------------------------------

void* proc_get_table_element_2198B1C(int index)
{
   return 0;
}

int init_crypto_context_219B934(CryptEngineSubctx *subctx, CryptEngineData *data, int unk2, int unk3, int arg_0)
{
   /*
   MOV             R9, R3
   LDRD.W          R4, R5, [R1,#0x20]
   SUB             SP, SP, #0x1C
   MOV.W           R10, #0
   MOVS            R3, #4  ; operation code
   VMOV.I32        D16, #0x80
   MOV             R11, R1 ; R1 = CryptEngineData*
   CMP             R4, R2  ; compare
   STRD.W          R4, R5, [SP]
   SBCS.W          R5, R5, R9
   LDR             R6, [R1,#0x28] ; R1 = CryptEngineData*
   MOV             R7, R0  ; CryptEngineSubctx *subctx
   MOV             R8, R2
   STRD.W          R3, R1, [R0,#8] ; = 4, CryptEngineData*
   VSTR            D16, [R0,#0x20] ; = 0x80, 0x80
   STRD.W          R10, R10, [R0,#0x10] ; = 0
   STRD.W          R10, R10, [R0,#0x18] ; = 0
   STRD.W          R10, R10, [R0,#0x28] ; = 0
   STRD.W          R10, R10, [R0,#0x30] ; = 0
   STRD.W          R10, R10, [R0,#0x38] ; = 0
   STRD.W          R10, R10, [R0,#0x40] ; = 0
   STRD.W          R10, R10, [R0,#0x48] ; = 0
   STRD.W          R10, R10, [R0,#0x50] ; = 0
   */

   if(? < ?)
   {
      /*
      LDRD.W          R1, R0, [R11,#0x14]
      BL              sub_21A1AA8
      SUBS            R0, #1
      LDRD.W          R2, R3, [SP]
      MUL.W           R0, R6, R0
      ADDS            R2, R2, R0
      ADC.W           R3, R3, #0
      ADDS            R4, R2, #1
      ADC.W           R5, R3, #0
      CMP             R4, R8
      SBCS.W          R0, R5, R9
      */

      if(? < ?)
      {
         /*
         MOV             R3, R10
         MOV             R0, R4  ; unk0
         MOV             R1, R5  ; unk1
         MOV             R2, R6  ; unk2
         BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
         SUBS.W          R8, R4, R2
         SBC.W           R9, R5, R3
         */
      }
      
      /*
      LDR             R1, [SP,#0x40+unk1]
      MOV             R2, R6  ; unk2
      STRD.W          R8, R9, [R7,#0x20]
      SUB.W           R3, R8, R1
      LDRD.W          R0, R1, [SP]
      STR             R3, [R7,#0x28]
      MOVS            R3, #0  ; unk3
      BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
      MOV             R4, R0
      ADDS.W          R0, R8, #0xFFFFFFFF ; unk0
      MOV             R2, R6  ; unk2
      MOV.W           R3, #0  ; unk3
      MOV             R5, R1
      ADC.W           R1, R9, #0xFFFFFFFF
      BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
      SUBS            R0, R0, R4
      STR             R4, [R7,#0x34]
      ADDS            R3, R0, #1
      MOV             R2, R6  ; unk2
      STR             R3, [R7,#0x2C]
      MOVS            R3, #0  ; unk3
      LDRD.W          R0, R1, [SP]
      MOV             R10, R3
      BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
      LDR.W           R1, [R11,#0x1C]
      STR             R2, [R7,#0x38]
      STR.W           R10, [R7,#0x40]
      */

      if(r1 == 1)
      {
         /*
         ORRS.W          R0, R2, R3
         IT EQ
         MOVEQ           R4, R10
         */

         if(!eq)
         {
            /*
            STRD.W          R4, R10, [SP,#8]
            LDRD.W          R0, R1, [SP,#8]
            CMP             R5, R1
            IT EQ
            CMPEQ           R4, R0
            ITE NE
            MOVNE           R4, R6
            MOVEQ           R4, R2
            */
         }

         /*
         MOVS            R3, #0
         STR             R4, [R7,#0x3C]
         STR             R3, [R7,#0x48]
         MOV             R0, R8  ; unk0
         MOV             R1, R9  ; unk1
         MOV             R2, R6  ; unk2
         BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
         CMP             R2, #1
         SBCS.W          R1, R3, #0
         IT LT
         MOVLT           R2, R6
         STR             R2, [R7,#0x44]
         */

         /*
         LDR             R4, [SP,#0x40+arg_0]
         STRD.W          R8, R9, [R4]
         ADD             SP, SP, #0x1C
         */
      }
      else
      {
         /*
         ORRS.W          R4, R2, R3
         MOV             R0, R8  ; unk0
         ITE NE
         MOVNE           R3, R6
         MOVEQ           R3, #0
         MOV             R1, R9  ; unk1
         STR             R3, [R7,#0x3C]
         MOV             R2, R6  ; unk2
         MOV             R3, R10 ; unk3
         BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
         CMP             R2, #1
         SBCS.W          R5, R3, #0
         ITE GE
         SUBGE           R4, R6, R2
         MOVLT           R4, R10
         STRD.W          R6, R4, [R7,#0x44]
         */

         /*
         LDR             R4, [SP,#0x40+arg_0]
         STRD.W          R8, R9, [R4]
         ADD             SP, SP, #0x1C
         */
      }
   }
   else
   {
      /*
      STRD.W          R8, R9, [R0,#0x20] ; R0 = CryptEngineSubctx *
      MOV             R3, R10 ; unk3
      MOV             R0, R2  ; unk0
      MOV             R1, R9  ; unk1
      MOV             R2, R6  ; unk2
      BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
      STR             R0, [SP,#0x40+var_38]
      MOV             R1, R9  ; unk1
      LDR             R5, [SP,#0x40+var_38]
      MOV             R0, R8  ; unk0
      MOV             R2, R6  ; unk2
      MOV             R3, R10 ; unk3
      STR             R5, [R7,#0x34] ; R7 =  CryptEngineSubctx *
      BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
      MOV             R5, R3
      LDR.W           R3, [R11,#0x1C] ; R11 = CryptEngineData*
      MOV             R4, R2
      ORRS.W          R0, R4, R5
      STR             R4, [R7,#0x38] ; R7 =  CryptEngineSubctx *
      ITE EQ
      MOVEQ           R2, #0
      MOVNE           R2, #1
      CMP             R3, #1
      STR             R2, [R7,#0x2C] ; R7 =  CryptEngineSubctx *
      */

      if(eq)
      {
         if(r2 == 0)
         {
            /*
            STR             R2, [R7,#0x3C]
            STR             R4, [R7,#0x44]
            */

            /*
            LDR             R4, [SP,#0x40+arg_0]
            STRD.W          R8, R9, [R4]
            ADD             SP, SP, #0x1C
            */
         }
         else
         {
            /*
            LDR             R1, [SP,#0x40+var_38] ; unk1
            MOVS            R2, #0
            STR             R2, [SP,#0x40+var_2C]
            MOV             R3, R10 ; unk3
            MOV             R2, R6  ; unk2
            STR             R1, [SP,#0x40+var_30]
            LDRD.W          R0, R1, [SP]
            BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
            LDRD.W          R2, R3, [SP,#0x10]
            CMP             R1, R3
            ITE EQ
            CMPEQ           R0, R2
            MOVNE           R2, R6
            BEQ             loc_219BB06
            */

            if(eq)
            {
               /*
               LDRD.W          R0, R1, [SP]
               MOV             R2, R6  ; unk2
               MOV             R3, R10 ; unk3
               BLX             ScePfsMgr.SceSysclibForDriver._imp_7554ab04
               */
            }
            
            /*
            STR             R2, [R7,#0x3C]
            STR             R4, [R7,#0x44]
            */

            /*
            LDR             R4, [SP,#0x40+arg_0]
            STRD.W          R8, R9, [R4]
            ADD             SP, SP, #0x1C
            */
         }
      }
      else
      {
         if(r2 == 0)
         {
            //MOVS            R3, #0
         }
         else
         {
            /*
            STR             R6, [R7,#0x3C]
            SBCS.W          R3, R5, #0
            */

            if(r4 < 1)
            {
               //MOVS            R3, #0
            }
            else
            {
               /*
               MOV             R3, R6
               SUBS            R4, R6, R4
               STR             R4, [R7,#0x48]
               */
            }
         }

         //STR             R3, [R7,#0x44]

         /*
         LDR             R4, [SP,#0x40+arg_0]
         STRD.W          R8, R9, [R4]
         ADD             SP, SP, #0x1C
         */
      }
   }


   return 0;
}

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

int ScePfsCryptEngineThread_work_219BF20(CryptEngineWorkCtx *work_ctx)
{
   return 0;
}