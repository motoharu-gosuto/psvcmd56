#pragma once

int execute_f00d_command_2_rmauth_sm_C8D988(unsigned const char input[0x10]);

int w_dmac5_command_0x41_derive_iv_tweak_C8D2F0(unsigned char* tweak_input, unsigned char* tweak0_res, unsigned char* tweak1_res);

int w_dmac5_3des_cbc_cts_iv_C8D2F0(unsigned int* result, const unsigned int* data, int size);