#pragma once

#include "SceMsifEcdsa.h"

//for testing

int execute_f00d_command_2_rmauth_sm_C8D988(unsigned const char input[0x10]);

int w_dmac5_command_0x41_derive_iv_tweak_C8D2F0(unsigned char* tweak_input, unsigned char* tweak0_res, unsigned char* tweak1_res);

int w_dmac5_3des_cbc_cts_iv_C8D2F0(unsigned int* result, const unsigned int* data, int size);

//real api

typedef struct SceMsif_subctx
{
   char error_code[4];
   ecdsa_signature signature;
}SceMsif_subctx;

int get_card_key_C8D5FC(SceMsif_subctx* subctx, unsigned char mc_1C_key[0x10]);

int ecdsa_verify_C8D78C(SceMsif_subctx* subctx, unsigned char master_key[0x10]);