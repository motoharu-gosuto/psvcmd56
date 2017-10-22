#pragma once

#include "SceIofilemgr.h"

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
    
    unsigned char klicensee[0x10]; //0x96
    
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
   unsigned const char* klicensee;
   uint32_t salt0; // salt that is used to derive keys
   uint32_t salt1; // salt that is used to derive keys
   uint16_t type; // 0xC
   uint16_t pmi_bcl_flag; // 0xE
   
   uint16_t key_id; // 0x10
   uint16_t flag0; // 0x12
   
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t block_size; //0x28
   unsigned char key[0x10]; //0x2C
   
   unsigned char iv_xor_key[0x10]; //0x3C
   
   unsigned char hmac_key[0x14]; //0x4C

}CryptEngineData;

typedef struct CryptEngineSubctx //size is 0x58
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t opt_code; // 0x8 - if 3 then decrypt, if 4 then encrypt, if 2 then encrypt
   CryptEngineData* data; // 0xC
   
   unsigned char* unk_10; // I DONT KNOW BUT I AM ASSUMING THAT THIS IS POINTER
   uint32_t unk_14; // 0x14
   uint32_t unk_18; // I DONT KNOW BUT I AM ASSUMING THAT THIS IS SIZE (based on tweak key derrivation)
   uint32_t nBlocksTail;
   
   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t unk_28; //0x28
   uint32_t nBlocks; // 0x2C - also digest table index
   
   uint32_t unk_30;
   uint32_t seed0_base; // 0x34
   uint32_t dest_offset; // 0x38
   uint32_t unk_3C; // 0x3C
   
   uint32_t tail_size; //0x40
   uint32_t unk_44;
   uint32_t unk_48; //0x48
   unsigned char* signature_table; // 0x4C hmac sha1 digest table
   
   unsigned char* work_buffer0; // 0x50
   unsigned char* work_buffer1; // 0x54
   
}CryptEngineSubctx;

typedef struct CryptEngineWorkCtx //size is 0x18
{
   void* unk_0; // pointer to data 0x140 + 0x18 ?
   void* unk_4; // pointer to data 0x140 + 0x18 ?
   CryptEngineSubctx* subctx; // 0x8
   uint32_t error; // 0xC set to 0 or error code after executing crypto task
   
   SceUID threadId; // = set with sceKernelGetThreadIdForDriver. used with ksceKernelSignalCondTo
   uint32_t unk_14;
   
}CryptEngineWorkCtx;

struct derive_keys_ctx;

typedef int(derive_keys_sub_219A29C_cb)(const derive_keys_ctx*);

struct read_op_ctx
{
  vfs_node *node;
  void *objectBase;
};

typedef struct derive_keys_ctx
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   uint32_t unk_10;
   derive_keys_sub_219A29C_cb* get_block_size_14; //function pointer
   uint32_t unk_18;
   uint32_t unk_1C;

   uint32_t unk_20;
   uint32_t unk_24;
   uint32_t unk_28;
   uint32_t unk_2C;

   uint32_t unk_30;
   uint32_t unk_34;
   uint32_t unk_38;
   uint32_t unk_3C;

   uint32_t unk_40; //
   uint32_t unk_44;
   uint32_t unk_48;
   uint32_t unk_4C;

   uint32_t unk_50; // here starts SCEIFTBL data - most likely
   uint32_t unk_54;
   uint32_t unk_58; //
   struct read_op_ctx rd_opt_5C;

   uint32_t unk_60;
   uint32_t unk_64;
   uint32_t unk_68; //
   uint32_t unk_6C;

   uint32_t unk_70;
   uint32_t unk_74;
   uint32_t unk_78;
   uint32_t unk_7C;

   uint32_t unk_80;
   unsigned char base_key[0x14]; // 0x84

}derive_keys_ctx;

typedef struct ctx_12f8d58e
{
   uint32_t unk_28;
   uint32_t unk_2C;

}ctx_12f8d58e;

int proc_verify_14_bytes_219DE44(unsigned char unk0[0x14], unsigned char unk1[0x14]);

int derive_data_ctx_keys(CryptEngineData* data, const derive_keys_ctx* drv_ctx);

void ScePfsCryptEngineThread_work_219BF20(CryptEngineWorkCtx* work_ctx);