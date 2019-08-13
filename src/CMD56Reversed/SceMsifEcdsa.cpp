#include "SceMsifEcdsa.h"
#include "SceMsifEcdsaNative.h"

#include <string>

#include <openssl/obj_mac.h>
#include <openssl/ec.h>

#include <iostream>
#include <iomanip>

int ecdsa_verify_C8DBC0(ecdsa_signature* sig, unsigned char M[0x1C], const ecdsa_point* Qa, const ecdsa_params* params)
{
   //return ecdsa_verify_C8DA14(sig, M, Qa, params, 7, 0x1C);

   return ecdsa_verify(0x1C, sig, M, Qa, params); // , 7, 0x1C
}
