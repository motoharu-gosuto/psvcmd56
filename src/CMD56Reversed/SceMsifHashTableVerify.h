#pragma once

typedef struct verify_hash_ctx
{
   unsigned char* ptr_4; //most likely the right size
   unsigned char* ptr_20; //most likely the right size
}verify_hash_ctx;

int verify_hashes_C8DBC0(verify_hash_ctx* ctx, unsigned char secret_key[0x1C], unsigned char* dec_ptr_pair[2], unsigned char* dec_ptr_table[6]);