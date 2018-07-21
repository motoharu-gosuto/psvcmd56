#pragma once

typedef struct verify_hash_ctx
{
   unsigned char* ptr_4; //most likely the right size
   unsigned char* ptr_20; //most likely the right size
}verify_hash_ctx;

int verify_hashes_C8DBC0(verify_hash_ctx* ctx, unsigned char secret_key[0x1C], unsigned char* dec_ptr_pair[2], unsigned char* dec_ptr_table[6]);


int block_memcmp_C8EADC(unsigned char *buffer0, unsigned char *buffer1, int nBlocks);

int block_is_zero_or_memcmp_C8E3EE(unsigned char *sha_224_0, unsigned char *sha_224_1, int key_size_blocks);