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
    uint16_t flag; //0x94 = 0
    
    char klicensee[0x10]; //0x96
    
    uint16_t key_id; // = 0
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
   const char* klicensee;
   uint32_t unk_4;
   uint32_t salt;
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

int SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(char *source, int size, char *result)
{
   return 0;
}

int sha1Digest_219DE54(char *result, char *source, int size)
{
   return SceKernelUtilsForDriverksceSha1Digest_87dc7f2f(source, size, result);
}

int SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(char* key, int key_len, char* data, int data_len, char* digest)
{
   return 0;
}

int hmacSha1Digest_219DE68(char* digest, char* key, char* data, int data_len)
{
   return SceKernelUtilsForDriver_sceHmacSha1DigestForDriver_29a28957(key, 0x14, data, data_len, digest);
}

//----------------------

int calculate_sha1_chain_219E008(char* key, char* iv_xor_key, const char* klicensee, uint32_t salt)
{
   /*
   SUB             SP, SP, #0x70
   MOV             R8, R1
   MOV             R10, R0
   LDR.W           R5, [R9]
   MOV             R1, R2  ; source
   ADD             R0, SP, #0x90+result ; result
   MOVS            R2, #0x10 ; size
   MOV             R4, R3
   MOV             R6, R0
   STR             R5, [SP,#0x90+var_24]
   BL              sha1Digest_219DE54
   MOVS            R3, #1  ; unk3
   ADD             R0, SP, #0x90+var_60 ; result
   MOV             R1, SP  ; source
   MOVS            R2, #8  ; size
   STR             R4, [SP,#0x90+var_90]
   MOV             R5, R0
   STR             R3, [SP,#0x90+var_90+4]
   ADD             R4, SP, #0x90+source
   BL              sha1Digest_219DE54
   LDMIA           R6!, {R0-R3}
   ADD.W           LR, SP, #0x90+source+0x14
   STMIA           R4!, {R0-R3}
   LDR             R7, [R6]
   LDMIA           R5!, {R0-R3}
   STR             R7, [R4]
   ADD             R7, SP, #0x90+var_88
   STMIA.W         LR!, {R0-R3}
   ADD             R1, SP, #0x90+source ; source
   LDR             R3, [R5] ; unk3
   MOVS            R2, #0x28 ; size
   ADD             R0, SP, #0x90+var_88 ; result
   STR.W           R3, [LR]
   BL              sha1Digest_219DE54
   LDMIA           R7!, {R0-R3} ; get pointer to last result, load data
   MOV.W           LR, #2
   ADD             R7, SP, #0x90+result
   STR.W           LR, [SP,#0x90+var_90+4] ; = 2
   STR.W           R0, [R10] ; store result
   ADD             R0, SP, #0x90+var_60 ; result
   STR.W           R1, [R10,#4] ; store result
   MOV             R1, SP  ; source - stack beginning
   STR.W           R2, [R10,#8] ; store result
   MOVS            R2, #8  ; size
   STR.W           R3, [R10,#0xC] ; store result
   BL              sha1Digest_219DE54
   LDMIA           R7!, {R0-R3}
   ADD.W           LR, SP, #0x90+var_60
   ADD.W           R12, SP, #0x90+source
   ADD             R7, SP, #0x90+source+0x14
   LDR             R5, [R5]
   LDR             R6, [R6]
   STMIA.W         R12!, {R0-R3}
   LDMIA.W         LR!, {R0-R3}
   STR             R6, [R4]
   ADD             R4, SP, #0x90+var_88
   STMIA           R7!, {R0-R3}
   ADD             R1, SP, #0x90+source ; source
   MOVS            R2, #0x28 ; size
   STR             R5, [R7]
   ADD             R0, SP, #0x90+var_88 ; result
   BL              sha1Digest_219DE54
   LDMIA           R4!, {R0-R3} ; get pointer to last result, load data
   LDR             R5, [SP,#0x90+var_24]
   STR.W           R0, [R8] ; store result
   LDR.W           R0, [R9] ; cookie
   STR.W           R1, [R8,#4] ; store result
   STR.W           R2, [R8,#8] ; store result
   CMP             R5, R0
   STR.W           R3, [R8,#0xC] ; store result
   */
   return 0;
}

int calculate_sha1_chain_219E1CC(char* key, char* iv_xor_key, const char* klicensee, uint32_t ignored, uint32_t salt)
{
   return calculate_sha1_chain_219E008(key, iv_xor_key, klicensee, salt);
}

int hmac1_sha1_or_sha1_chain_219E0DC(char* key, char* iv_xor_key, const char* klicensee, uint32_t unk3, uint16_t flag, uint32_t salt, uint16_t ignored_key_id)
{
   return 0;
}

int hmac_sha1_219E164(char* key, char* iv_xor_key, const char* klicensee, uint16_t flag, uint16_t key_id, const char* data, uint32_t data_len)
{
   return 0;
}

int combine_klicensee_digest_219E1D8(char* hmac_key, const char* klicensee, uint32_t unk2, uint16_t flag, uint32_t salt, uint16_t key_id)
{
   return 0;
}

struct derive_keys_ctx;

typedef int(derive_keys_sub_219A29C_cb)(const derive_keys_ctx*);

typedef struct derive_keys_ctx
{
   derive_keys_sub_219A29C_cb* unk_14; //function pointer

   uint32_t unk_40;


   uint32_t unk_58;
   uint32_t unk_68;

   char unk_84[];

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

int derive_keys_from_klicensee_219B4A0(CryptEngineData *data, int salt, int unk2, int unk3, uint16_t seed1_base, int arg_4, const derive_keys_ctx* drv_ctx, const pfs_pmi_buffer_list_ctx *pfs_pmi_bcl)
{
   ctx_12f8d58e* ctx0 = SceIofilemgrForDriver_thread_related_12f8d58e();
   data->unk_18 = 0x100;
   if((ctx0 != 0) && (ctx0->unk_2C >= 0))
      data->unk_18 = (uint32_t)(ctx0->unk_2C & 0x0000FFFF);

   ctx_12f8d58e* ctx1 = SceIofilemgrForDriver_thread_related_12f8d58e();
   data->unk_14 = 0xF;
   if(ctx1 != 0)
      data->unk_14 = ctx1->unk_28;

   data->unk_4 = pfs_pmi_bcl->unk_A8;
   data->salt = salt;
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
      calculate_sha1_chain_219E1CC(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->unk_A8, salt);
      return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->unk_A8, pfs_pmi_bcl->flag, salt, pfs_pmi_bcl->key_id);
   }
   else
   {
      if((drv_ctx->unk_40 != 0 && drv_ctx->unk_40 != 3) || (drv_ctx->unk_58 <= 1))
      {    
         hmac1_sha1_or_sha1_chain_219E0DC(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->unk_A8, pfs_pmi_bcl->flag, salt, pfs_pmi_bcl->key_id);
         return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->unk_A8, pfs_pmi_bcl->flag, salt, pfs_pmi_bcl->key_id);
      }
      else
      {
         if(drv_ctx->unk_40 == 0 || drv_ctx->unk_40 == 3)
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->flag, pfs_pmi_bcl->key_id, drv_ctx->unk_84, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->unk_A8, pfs_pmi_bcl->flag, salt, pfs_pmi_bcl->key_id);
         }
         else
         {
            hmac_sha1_219E164(data->key, data->iv_xor_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->flag, pfs_pmi_bcl->key_id, 0, 0x14);
            return combine_klicensee_digest_219E1D8(data->hmac_key, pfs_pmi_bcl->klicensee, pfs_pmi_bcl->unk_A8, pfs_pmi_bcl->flag, salt, pfs_pmi_bcl->key_id);
         }
      }
   }
}