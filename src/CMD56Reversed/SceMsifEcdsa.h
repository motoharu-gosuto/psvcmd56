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

int ecdsa_verify_C8DBC0(ecdsa_signature* sig, unsigned char M[0x1C], const ecdsa_point* Qa, const ecdsa_params* params);