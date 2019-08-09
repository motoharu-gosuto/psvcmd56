#pragma once

#include <F00D/ECDSA.h>

int ecdsa_verify_C8DBC0(ecdsa_signature* sig, unsigned char M[0x1C], const ecdsa_point* Qa, const ecdsa_params* params);