#pragma once

struct ecdsa_signature
{
   unsigned char r[0x1C];
   unsigned char s[0x1C];
};

struct ecdsa_point
{
   unsigned char X[0x1C];
   unsigned char Y[0x1C];
};

struct ecdsa_params
{
   unsigned char P[0x1C];
   unsigned char A[0x1C];
   unsigned char B[0x1C];
   unsigned char N[0x1C];
   ecdsa_point G;
};

int ecdsa_verify(int ecc_size, ecdsa_signature *sig, const unsigned char* M, const ecdsa_point* Qa, const ecdsa_params* params);

int ecdsa_sign(int ecc_size, const unsigned char* M, const unsigned const char* Pk, const ecdsa_params* params, const unsigned char* nonce, ecdsa_signature* sig_res);

int ecc_multiply(int ecc_size, const ecdsa_params* params, const unsigned char* multiplier, ecdsa_point* output);

int ecc_multiply(int ecc_size, const ecdsa_params* params, const ecdsa_point* input, const unsigned char* multiplier, ecdsa_point* output);

int ecc_modulus(const unsigned char* nonce, int nonce_size, const unsigned char* N, int N_size, unsigned char* output);