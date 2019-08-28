#pragma once

#define KEYSLOT_0x519 0x519
#define KEYSLOT_0x204 0x204
#define KEYSLOT_0x0 0x0

int bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(unsigned char* dst, const unsigned char* src, int keyslot, int size);

int bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(const unsigned char* src, int src_keyslot, int dst_keyslot, int size);

int bigmac_set_key_to_keyslot(const unsigned char* key, int keyslot);

int bigmac_initialize();