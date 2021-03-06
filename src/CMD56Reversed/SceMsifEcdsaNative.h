#pragma once

#include "SceMsifEcdsa.h"

int block_memcmp_C8EADC(const unsigned char *buffer0, const unsigned char *buffer1, int nBlocks);

void reverse_byte_order_C8E3AA(unsigned char* dst, const unsigned char* src, int byte_size);

void block_shift_left_with_overflow_C8EB0A(unsigned char* dst, unsigned char* src, int block_size, int bits);

void block_shift_right_with_overflow_C8E328(unsigned char* dst, unsigned char* src, int block_size, int bits);

void arbitrary_length_multiply_by_int_C8E01C(unsigned char *dst, unsigned char *src, int block_size, int multiplier);

int arbitrary_length_substract_C8E36E(unsigned char *dst, unsigned char *left, unsigned char *right, int block_size, int carry_input);

int arbitrary_length_add_C8EB4A(unsigned char *dst, unsigned char *left, unsigned char *right, int block_size, int carry_input);

void arbitrary_length_modulo_C8E084(unsigned char *dst, unsigned char *src0, int byte_size_arg, unsigned char *src1, int block_size_arg);

void arbitrary_length_multiply_C8DF74(unsigned char *dst, unsigned char *src0, int block_size0, unsigned char *src1, int block_size1);

int maybe_arbitrary_length_inverse_5_C8DBD4(unsigned char *dst, unsigned char *src1, unsigned char *mod, int block_size);