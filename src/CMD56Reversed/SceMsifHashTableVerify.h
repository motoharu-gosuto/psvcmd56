#pragma once

typedef struct verify_hash_ctx
{
   unsigned char* ptr_4; //most likely the right size
   unsigned char* ptr_20; //most likely the right size
}verify_hash_ctx;

int verify_hashes_C8DBC0(verify_hash_ctx* ctx, unsigned char secret_key[0x1C], unsigned char* dec_ptr_pair[2], unsigned char* dec_ptr_table[6]);


int block_memcmp_C8EADC(const unsigned char *buffer0, const unsigned char *buffer1, int nBlocks);

void reverse_byte_order_C8E3AA(unsigned char* dst, const unsigned char* src, int byte_size);

void block_shift_with_overflow_C8EB0A(unsigned char* dst, unsigned char* src, int block_size, int bits);

void arbitrary_length_multiply_C8E01C(unsigned char *buffer0, unsigned char *buffer1, int block_size, int arg3);