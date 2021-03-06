#include "GcAuthMgrService.h"

#include "Crypto/CryptoService.h"

#include <F00D/ECDSA.h>

using namespace f00d;

//0x04 - DONE - top level
//0x07 - DONE - top level
//0x0C - DONE - tested
//0x0D - DONE - tested
//0x0E - DONE - top level
//0x10 - DONE - top level
//0x11 - DONE - not tested
//0x12 - DONE - top level
//0x14 - DONE
//0x15 - DONE
//0x16 - DONE - top level
//0x17 - DONE - top level
//0x18 - DONE - not tested
//0x19 - DONE - top level
//0x1B
//0x1C
//0x1D
//0x1E
//0x1F
//0x20
//0x21 - DONE - not tested
//0x22 - DONE
//0x23 - DONE - top level

//==========================================

//curve 160

unsigned char ecc_160_p[0x14] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char ecc_160_a[0x14] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC};        
unsigned char ecc_160_b[0x14] = {0xA6, 0x8B, 0xED, 0xC3, 0x34, 0x18, 0x02, 0x9C, 0x1D, 0x3C, 0xE3, 0x3B, 0x9A, 0x32, 0x1F, 0xCC, 0xBB, 0x9E, 0x0F, 0x0B};
unsigned char ecc_160_n[0x14] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xB5, 0xAE, 0x3C, 0x52, 0x3E, 0x63, 0x94, 0x4F, 0x21, 0x27};
unsigned char ecc_160_gx[0x14] = {0x12, 0x8E, 0xC4, 0x25, 0x64, 0x87, 0xFD, 0x8F, 0xDF, 0x64, 0xE2, 0x43, 0x7B, 0xC0, 0xA1, 0xF6, 0xD5, 0xAF, 0xDE, 0x2C};
unsigned char ecc_160_gy[0x14] = {0x59, 0x58, 0x55, 0x7E, 0xB1, 0xDB, 0x00, 0x12, 0x60, 0x42, 0x55, 0x24, 0xDB, 0xC3, 0x79, 0xD5, 0xAC, 0x5F, 0x4A, 0xDF};

unsigned char* N_ptr_160_81259C = ecc_160_n;

const unsigned char* ECC_160_curve_812590[6] = {ecc_160_p, ecc_160_a, ecc_160_b, ecc_160_n, ecc_160_gx, ecc_160_gy};

//==========================================

//curve 224

unsigned char ecc_224_0x22_p[0x1C] = {0xA5, 0x3E, 0x11, 0x3E, 0x46, 0xD8, 0xC9, 0xC1, 0xF0, 0x9D, 0x9B, 0xCB, 0x2A, 0x53, 0x73, 0xD3, 0x79, 0xF6, 0x9D, 0xA2, 0x8D, 0x09, 0x99, 0x9F, 0xED, 0x57, 0xA9, 0x0F}; // OK
unsigned char ecc_224_0x22_a[0x1C] = {0xA5, 0x3E, 0x11, 0x3E, 0x46, 0xD8, 0xC9, 0xC1, 0xF0, 0x9D, 0x9B, 0xCB, 0x2A, 0x53, 0x73, 0xD3, 0x79, 0xF6, 0x9D, 0xA2, 0x8D, 0x09, 0x99, 0x9F, 0xED, 0x57, 0xA9, 0x0C}; // OK
unsigned char ecc_224_0x22_b[0x1C] = {0x90, 0x65, 0x94, 0x1D, 0x29, 0x37, 0x4A, 0x8F, 0x11, 0xDD, 0x1E, 0x54, 0x01, 0x89, 0x43, 0x4E, 0x4A, 0x6E, 0xBF, 0xAF, 0x54, 0x77, 0xF6, 0xC1, 0x72, 0xF6, 0x85, 0x5E}; // OK
unsigned char ecc_224_0x22_n[0x1C] = {0xA5, 0x3E, 0x11, 0x3E, 0x46, 0xD8, 0xC9, 0xC1, 0xF0, 0x9D, 0x9B, 0xCB, 0x2A, 0x52, 0x26, 0x98, 0xDE, 0xEF, 0x58, 0xDB, 0x1A, 0xD9, 0xAB, 0x7F, 0x04, 0xE3, 0xAE, 0x7F}; // OK
unsigned char ecc_224_0x22_gx[0x1C] = {0x7E, 0x06, 0x09, 0x82, 0x47, 0xE6, 0xB5, 0x9F, 0x31, 0x10, 0xBC, 0xBB, 0x3A, 0xB6, 0xC2, 0x50, 0xBC, 0x5A, 0xB0, 0x6C, 0x03, 0x2D, 0xAD, 0x43, 0x68, 0x4C, 0x24, 0x8F}; // OK
unsigned char ecc_224_0x22_gy[0x1C] = {0x0B, 0xD9, 0x41, 0x8D, 0xE8, 0xE3, 0xE4, 0x5D, 0x2D, 0x70, 0x1E, 0x02, 0x37, 0xFD, 0x7F, 0x2A, 0xDE, 0x0D, 0x48, 0xB7, 0x4C, 0xEE, 0xF2, 0xF1, 0xC8, 0xAC, 0x48, 0x4E}; // OK

unsigned char* N_ptr_224_81251C = ecc_224_0x22_n;

const unsigned char* ECC_224_curve_812510[6] = {ecc_224_0x22_p, ecc_224_0x22_a, ecc_224_0x22_b, ecc_224_0x22_n, ecc_224_0x22_gx, ecc_224_0x22_gy};

//==========================================

unsigned char key_812400[0x10] = {0x6F, 0x22, 0x85, 0xED, 0x46, 0x3A, 0x6E, 0x57, 0xC5, 0xF3, 0x55, 0x0D, 0xDC, 0xC8, 0x1F, 0xEB, };
unsigned char key_812440[0x10] = {0xDA, 0x96, 0x08, 0xB5, 0x28, 0x82, 0x5D, 0x6D, 0x13, 0xA7, 0xAF, 0x14, 0x46, 0xB8, 0xEC, 0x08, };
unsigned char key_812480[0x10] = {0x36, 0x8B, 0x2E, 0xB5, 0x43, 0x7A, 0x82, 0x18, 0x62, 0xA6, 0xC9, 0x55, 0x96, 0xD8, 0xC1, 0x35, };
unsigned char key_8124C0[0x10] = {0x7F, 0x1F, 0xD0, 0x65, 0xDD, 0x2F, 0x40, 0xB3, 0xE2, 0x65, 0x79, 0xA6, 0x39, 0x0B, 0x61, 0x6D, };

unsigned char iv_8124D0[0x10] = {0x8B, 0x14, 0xC8, 0xA1, 0xE9, 0x6F, 0x30, 0xA7, 0xF1, 0x01, 0xA9, 0x6A, 0x30, 0x33, 0xC5, 0x5B, };

//==========================================

unsigned char hmac_256_key_812340[0x40] = {0x54, 0x88, 0xA9, 0x81, 0x1C, 0x9A, 0x2C, 0xBC, 0xCC, 0x59, 0x6B, 0x1F, 0xAD, 0x1A, 0x7E, 0x29, 
                                           0xE0, 0x75, 0x84, 0x0F, 0x47, 0x43, 0x1F, 0x37, 0xAC, 0x06, 0x02, 0x46, 0x4A, 0x27, 0x9E, 0x02, 
                                           0xDF, 0x2E, 0x71, 0x65, 0xF1, 0x13, 0x7B, 0xF6, 0x9A, 0xE6, 0xDC, 0xB9, 0xDC, 0x38, 0x8C, 0x9D, 
                                           0xCC, 0xB3, 0x64, 0xC4, 0xCA, 0x26, 0xCB, 0x8F, 0x1A, 0xF0, 0x63, 0x8A, 0x6E, 0xAD, 0xB5, 0x4D};

unsigned char Pk_00812528[0x1C] = {0x76, 0x74, 0x36, 0xA6, 0x99, 0x9D, 0x88, 0x48, 0x0E, 0xC8, 0x56, 0xF5, 0x5C, 0xEA, 0xBB, 0x43, 0x96, 0x85, 0x9E, 0x37, 0x45, 0x99, 0x40, 0x39, 0x21, 0xF5, 0x55, 0x98};

unsigned char Pk_00812544[0x1C] = {0x60, 0x7A, 0x2E, 0x55, 0x68, 0xB4, 0xB9, 0xA0, 0x32, 0xF4, 0x52, 0x53, 0xCF, 0xED, 0x20, 0xDB, 0x2E, 0x6E, 0x44, 0x6C, 0x37, 0x82, 0xE8, 0x2A, 0x1A, 0xB9, 0xC9, 0x23};

unsigned char Pk_008125A8[0x14] = {0x53, 0xCC, 0xC3, 0x6E, 0xDF, 0xAD, 0xBE, 0x24, 0x55, 0x83, 0x27, 0x05, 0x52, 0xD2, 0x3B, 0x22, 0x51, 0x8E, 0xE3, 0xA8};

//==========================================

unsigned char aes_key_0x23_812380[0x10] = {0x61, 0x35, 0x87, 0xCC, 0xF0, 0x41, 0xDE, 0x6E, 0xB9, 0x73, 0x97, 0xC2, 0x05, 0xDF, 0x49, 0xE9};

unsigned char cmac_key_0x23_8123C0[0x10] = {0x66, 0x01, 0x54, 0x5F, 0x5E, 0x9D, 0x4D, 0xD8, 0xF8, 0xED, 0x3B, 0x33, 0x39, 0x26, 0xA8, 0x99};

//==========================================

unsigned char cmd_4_7_key0_8125C0[0x10]  = {0xF8, 0x1E, 0x0E, 0x97, 0xAD, 0xED, 0x52, 0xB3, 0xA9, 0xFB, 0x83, 0x22, 0xCF, 0x58, 0x92, 0x63};
unsigned char cmd_4_7_key1_812600[0x10]  = {0xA7, 0x01, 0x56, 0x5F, 0x1E, 0xAD, 0xDC, 0x05, 0x17, 0x96, 0xDC, 0x2D, 0x46, 0xDC, 0x50, 0x9A};
unsigned char cmd_4_7_key2_812640[0x10]  = {0xCC, 0xB8, 0x15, 0xDC, 0x41, 0x94, 0xB7, 0xCB, 0x3F, 0x33, 0xDA, 0x7C, 0x1D, 0x53, 0x3E, 0xE5};
unsigned char cmd_4_7_key3_812680[0x10]  = {0x35, 0x5D, 0x76, 0x19, 0x6F, 0x58, 0xDA, 0x2B, 0x90, 0xAB, 0x65, 0xB2, 0x7B, 0xDF, 0xE9, 0x2E};
unsigned char cmd_4_7_key4_8126C0[0x10]  = {0x9E, 0x6C, 0x4F, 0x1E, 0xBE, 0xD9, 0xA4, 0xCC, 0x2F, 0xC7, 0x49, 0xCB, 0x40, 0x38, 0x40, 0xC9};
unsigned char cmd_4_7_key5_812700[0x10]  = {0x6E, 0xC2, 0xF2, 0x55, 0x1D, 0xA4, 0x2B, 0xC6, 0x8A, 0xAB, 0x44, 0x73, 0x90, 0xF1, 0x4C, 0x87};
unsigned char cmd_4_7_key6_812740[0x10]  = {0xD4, 0x28, 0x2A, 0x71, 0x66, 0x2C, 0x76, 0x6C, 0x84, 0x0B, 0x0B, 0xC3, 0x61, 0x92, 0x71, 0x68};
unsigned char cmd_4_7_key7_812780[0x10]  = {0x65, 0x17, 0x5E, 0xCF, 0x5F, 0xEF, 0x05, 0xA7, 0x59, 0x79, 0x8E, 0x96, 0x12, 0xEB, 0x55, 0xAD};
unsigned char cmd_4_7_key8_8127C0[0x10]  = {0x5C, 0x91, 0x4E, 0xD0, 0xF1, 0x8C, 0x1D, 0x2C, 0x52, 0x8C, 0x1A, 0xD2, 0xB6, 0xE8, 0xEC, 0x3E};
unsigned char cmd_4_7_key9_812800[0x10]  = {0x90, 0xEF, 0x05, 0x35, 0x9B, 0xBF, 0x56, 0xA2, 0x34, 0xB0, 0x21, 0x2B, 0x61, 0xB7, 0x02, 0x99};
unsigned char cmd_4_7_key10_812840[0x10] = {0x2B, 0x35, 0x2A, 0xC0, 0xAE, 0xEA, 0x17, 0x5B, 0xD0, 0x27, 0x19, 0x60, 0xB8, 0xA1, 0x86, 0x7F};
unsigned char cmd_4_7_key11_812880[0x10] = {0x78, 0xEA, 0x6E, 0xD4, 0x3A, 0xB5, 0x59, 0xD4, 0x15, 0x2A, 0x46, 0x15, 0xF2, 0xD7, 0x4F, 0xC3};
unsigned char cmd_4_7_key12_8128C0[0x10] = {0x04, 0x72, 0x84, 0xE1, 0x05, 0xEE, 0xD5, 0xCC, 0x61, 0x93, 0x26, 0xF0, 0x25, 0x8E, 0xD5, 0x74};
unsigned char cmd_4_7_key13_812900[0x10] = {0x40, 0x9C, 0x89, 0x90, 0x23, 0xBC, 0x00, 0xCB, 0xC1, 0xFF, 0x90, 0xD3, 0x18, 0x58, 0xCD, 0x93};
unsigned char cmd_4_7_key14_812940[0x10] = {0xFC, 0xF6, 0x84, 0x1F, 0x0E, 0x73, 0xD7, 0xEC, 0x59, 0xB1, 0x12, 0x5D, 0x5A, 0x12, 0x1D, 0x0C};
unsigned char cmd_7_key15_812980[0x10]   = {0x3F, 0xB3, 0x00, 0x74, 0x43, 0x1A, 0x5D, 0x39, 0x16, 0xFD, 0x0E, 0xFA, 0xEE, 0xEC, 0xA8, 0x0F};
unsigned char cmd_7_key16_8129C0[0x10]   = {0xA9, 0x4C, 0xD0, 0x91, 0x6A, 0xA9, 0x70, 0xBB, 0x94, 0xF8, 0xC0, 0xA4, 0x11, 0xBB, 0x5C, 0x75};
unsigned char cmd_7_key17_812A00[0x10]   = {0xFE, 0xB8, 0x0A, 0x86, 0x27, 0xBD, 0x66, 0x9A, 0x49, 0x82, 0xE1, 0xE4, 0x9F, 0x48, 0xB7, 0x33};
unsigned char cmd_7_key18_812A40[0x10]   = {0x45, 0xB1, 0x88, 0x16, 0xEF, 0x5E, 0xD6, 0x50, 0xF5, 0xED, 0x7B, 0xF3, 0x27, 0x5A, 0x78, 0x92};
unsigned char cmd_7_key19_812A80[0x10]   = {0xD4, 0x9C, 0x99, 0x9F, 0x7B, 0x4A, 0xD6, 0x1F, 0x72, 0x92, 0xFE, 0x6B, 0xF0, 0x56, 0x75, 0x08};
unsigned char cmd_7_key20_812AC0[0x10]   = {0x9C, 0x33, 0x84, 0x3C, 0x60, 0xD6, 0xEE, 0x3E, 0xD4, 0x4E, 0x9E, 0xC0, 0x94, 0xF5, 0xF5, 0x42};
unsigned char cmd_4_7_key21_812B00[0x10] = {0xC8, 0xED, 0x1E, 0xE4, 0xBF, 0xDD, 0xDD, 0x94, 0x0E, 0xBB, 0xEE, 0x85, 0x11, 0xDC, 0x2A, 0x20};
unsigned char cmd_4_7_key22_812B40[0x10] = {0x1A, 0x39, 0xFA, 0x7E, 0x64, 0x3A, 0xDB, 0xEE, 0xA9, 0x83, 0xEB, 0xE8, 0x31, 0x7C, 0x15, 0xCE};
unsigned char cmd_4_7_key23_812B80[0x10] = {0x17, 0x3D, 0xF1, 0x51, 0xF8, 0x92, 0x8B, 0x1C, 0x51, 0x9F, 0x4A, 0x76, 0x23, 0xE1, 0xD3, 0x44};
unsigned char cmd_4_7_key24_812BC0[0x10] = {0x27, 0x2C, 0xEE, 0xF4, 0x61, 0xC9, 0xD7, 0xAB, 0xA7, 0xF3, 0x4B, 0x4B, 0x2A, 0x7C, 0x40, 0x35};
unsigned char cmd_7_key25_812C00[0x10]   = {0x06, 0x9F, 0x49, 0xE1, 0xFB, 0xFE, 0x34, 0x92, 0xDC, 0x40, 0xFD, 0x2D, 0x1C, 0x86, 0x05, 0x88};
unsigned char cmd_7_key26_812C40[0x10]   = {0x53, 0xC3, 0x70, 0x31, 0x81, 0x61, 0x75, 0x43, 0x3B, 0xB3, 0x43, 0x92, 0xEA, 0x9E, 0x20, 0x43};
unsigned char cmd_7_key27_812C80[0x10]   = {0xEF, 0xF7, 0xD3, 0xB9, 0x55, 0x97, 0xC3, 0x7A, 0xB4, 0xE5, 0xDC, 0x16, 0x06, 0x65, 0xC4, 0x4C};
unsigned char cmd_7_key28_812CC0[0x10]   = {0xEF, 0xA8, 0xA0, 0x55, 0x93, 0xE0, 0x0D, 0x45, 0xC3, 0xC1, 0xE1, 0x1D, 0x74, 0xE2, 0x2A, 0x24};

//==========================================

unsigned char key_seed_812580[0x10] = {0xB0, 0x74, 0x4F, 0x09, 0x1C, 0xD3, 0x33, 0xF9, 0xF6, 0xA5, 0x24, 0xF4, 0x26, 0xCC, 0x0D, 0x6E};

unsigned char key_seed_812500[0x10] = {0x82, 0x1C, 0x57, 0x14, 0x41, 0x5E, 0x98, 0x04, 0xD6, 0xAA, 0xE3, 0x24, 0xEB, 0x3D, 0xDD, 0xFE}; 

//==========================================

int bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(const unsigned char* src, int keyslot_dst, int keyslot_src)
{
   return 0;
}

int bigmac_cmac_aes_128_with_keyslot_80B87C(unsigned char* dst, const unsigned char* src, int size, int keyslot)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_set_keyslot_from_keyslot_80B486(const unsigned char* src, unsigned char* iv, int keyslot_dst, int keyslot_src)
{
   return 0;
}

// mode 1 uses key
// mode 2 uses keyslot 0x24
int bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(const unsigned char* src_dst, int size, const unsigned char* key, int enc_mode)
{
   //iv is 0

   return 0;
}

int bigmac_generate_random_number_80C462(unsigned char* dst, int size)
{
   memset(dst, 0, size);

   return 0;
}

// mode 1 uses key
// mode 2 uses keyslot 0x24
int bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(unsigned char* src_dst, int size, const unsigned char* key, int enc_mode)
{
   return 0;
}

int bigmac_cmac_aes_128_with_key_80BA5C(const unsigned char* src, int size, const unsigned char* key, unsigned char* dst)
{
   return 0;
}

int bigmac_sha256_80BAC2(const unsigned char* src, int size, unsigned char* dst)
{
   return 0;
}

int bigmac_sha1_80BB18(const unsigned char* src, int size, unsigned char* dst)
{
   return 0;
}

//cmac_input - size 0x20
//cmac_output - size 0x10
int initialize_keyslot_0x21_0x24_with_cmac_80BB6E(const unsigned char* cmac_input, int key_id, unsigned char* cmac_output, int* mode)
{
   switch(key_id)
   {
   case 0x8001:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_812400, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         *mode = 1; //with key
         return 0;
      }
      break;
   case 0x8002:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_812440, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         *mode = 1; //with key
         return 0;
      }
      break;
   case 0x8003:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_812480, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         *mode = 1; //with key
         return 0;
      }
      break;
   case 0x0001:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_8124C0, 0x21, 0x345); //initialize key slot 0x21 by decrypting key_8124C0 with key slot 0x345
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21); // calculate cmac of the cmac_input with key slot 0x21
         if(res1 != 0)
            return res1;

         int res2 = bigmac_aes_128_cbc_decrypt_set_keyslot_from_keyslot_80B486(cmac_output, iv_8124D0, 0x24, 0x348); // decrypt cmac with iv_8124D0 and key slot 0x348 and set key slot 0x24
         if(res2 != 0)
            return res2;
   
         *mode = 2; //with keyslot 0x24
         return 0;
      }
      break;
   default:
       return 0xE;
   }
}

int initialize_keyslot_0x21_0x24_with_cmac_and_dec_key_80BCB6(const unsigned char* cmac_input, int key_id, const unsigned char* src, unsigned char* dst)
{
   int mode;
   unsigned char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(cmac_input, key_id, drv_key, &mode);
   if(res0 != 0)
      return res0;

   memcpy(dst, src, 0x10);
   
   int res1 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dst, 0x10, drv_key, mode);
                           
   return res1;
}

int bigmac_hmac_sha256_80D974(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, int key_size)
{
   if(key_size != 0x40)
      return -1;

   auto cryptops = CryptoService::get();
   return cryptops->hmac_sha256(src, dst, size, key, 0x40);
}

int bigmac_sha256_80D960(unsigned char* dst, const unsigned char* src, int size)
{
   auto cryptops = CryptoService::get();
   return cryptops->sha256(src, dst, size);
}

int bigmac_hmac_sha256_contract_80C0F6(const unsigned char* src2, const unsigned char* src1, int size, unsigned char* dst)
{
   if (size != 0x14 && size != 0x1C)
      return 0x12;

   unsigned char combo[0x38];

   memcpy(combo, src1, size);
   memcpy(combo + size, src2, size);

   unsigned char contract[0x20];

   int r0 = bigmac_hmac_sha256_80D974(contract, combo, size * 2, hmac_256_key_812340, 0x40);
   if (r0 != 0)
      return 0x11;
  
   memcpy(dst, contract, 0x20);
   
   return 0;
}

int bigmac_sha256_block_update_80C17A(const unsigned char* src, int data_size, unsigned char* iv, unsigned char* digest)
{
   unsigned char src_xored[0x20] = {0};

   if (data_size > 0x20)
      return 0x12;

   // this memcpy is important because src is only of size 0x1C!
   // if memcpy is not done - 4 last bytes will be incorrectly calculated
   memcpy(src_xored, iv, 0x20);

   for(int i = 0; i < data_size; i++)
      src_xored[i] = src_xored[i] ^ src[i];

   int r0 = bigmac_sha256_80D960(digest, src_xored, 0x20);
   if(r0 != 0)
      return 0x11;

   for(int i = 0; i < 0x20; i++)
      iv[i] = iv[i] ^ digest[i];

   for(int i = 0; i < 0x20; i++)
   {
      if(iv[i] != 0xFF)
      {
         iv[i] = iv[i] + 1;
         break;
      }
      
      iv[i] = 0;
   }

   return 0;
}

int bigmac_aes_128_cbc_submit_with_keyslot_80B538(unsigned char* dst, const unsigned char* src, int size, int keyslot, int function)
{
   return 0;
}

//==========================================

// 0x00 CMAC-AES-192
// 0x10 CMAC-AES-128
// 0x20 CMAC-AES-256
int bigmac_cmac_aes_submit_80D990(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, int func_mode)
{
   return 0;
}

int bigmac_cmac_aes_submit_80D990(unsigned char* dst, const unsigned char* src, int size, int keyslot, int func_mode)
{
   return 0;
}

//==========================================

int bigmac_aes_128_cbc_encrypt_with_potential_key_and_iv_80D906(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, unsigned char* iv)
{
   return 0;
}

int bigmac_aes_128_cbc_encrypt_with_potential_key_and_iv_80D906(unsigned char* dst, const unsigned char* src, int size, int keyslot, unsigned char* iv)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_with_potential_key_and_iv_80D928(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, unsigned char* iv)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_with_potential_key_and_iv_80D928(unsigned char* dst, const unsigned char* src, int size, int keyslot, unsigned char* iv)
{
   return 0;
}

//==========================================

int bigmac_aes_128_ecb_encrypt_set_keyslot_0x0_from_0x204_80B5EE(const unsigned char* src)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_with_keyslot_0x0_80B67A(unsigned char* dst, const unsigned char* src, int size)
{
   unsigned char key_0[0x10] = {0};
   unsigned char iv[0x10] = {0};

   auto cryptops = CryptoService::get();
   return cryptops->aes_cbc_decrypt(src, dst, size, key_0, 0x80, iv);
}

//==========================================

int bigmac_aes_256_ecb_encrypt_with_keyslot_0x212_80D118(unsigned char* dst, unsigned char* src)
{
   unsigned char key_212[0x20] = {0};

   auto cryptops = CryptoService::get();
   return cryptops->aes_ecb_encrypt(src, dst, 0x10, key_212, 0x100);
}

int sw_cmac_with_keyslot_0x212_80D182(unsigned char* dst, const unsigned char* src, int size)
{
   unsigned char key_212[0x20] = {0};

   auto cryptops = CryptoService::get();
   return cryptops->aes_cmac(src, dst, 0xA8, key_212, 0x100);
}

//==========================================

int bigmac_read_key_from_keyring_80B11A(int index, unsigned char* dst)
{
   return 0;
}

int get_encrypted_shuffled_key_from_key_0x601_0x602_80CA94(unsigned char* dst)
{
   unsigned char key_buffer1[0x20];
   unsigned char shuffled_key[0x10];

   bigmac_read_key_from_keyring_80B11A(0x602, key_buffer1);
   
   shuffled_key[0x03] = (char)((*((int*)(key_buffer1 + 0x1C))));
   shuffled_key[0x00] = (char)((*((int*)(key_buffer1 + 0x1C))) >> 0x18);
   shuffled_key[0x01] = (char)((*((int*)(key_buffer1 + 0x1C))) >> 0x10);
   shuffled_key[0x02] = (char)((*((int*)(key_buffer1 + 0x1C))) >> 8);

   shuffled_key[0x07] = (char)((*((int*)(key_buffer1 + 0x18))));
   shuffled_key[0x04] = (char)((*((int*)(key_buffer1 + 0x18))) >> 0x18);
   shuffled_key[0x05] = (char)((*((int*)(key_buffer1 + 0x18))) >> 0x10);
   shuffled_key[0x06] = (char)((*((int*)(key_buffer1 + 0x18))) >> 8);

   shuffled_key[0x0B] = (char)((*((int*)(key_buffer1 + 0x14))));
   shuffled_key[0x08] = (char)((*((int*)(key_buffer1 + 0x14))) >> 0x18);
   shuffled_key[0x09] = (char)((*((int*)(key_buffer1 + 0x14))) >> 0x10);
   shuffled_key[0x0A] = (char)((*((int*)(key_buffer1 + 0x14))) >> 8);

   shuffled_key[0x0F] = (char)((*((int*)(key_buffer1 + 0x10))));
   shuffled_key[0x0C] = (char)((*((int*)(key_buffer1 + 0x10))) >> 0x18);
   shuffled_key[0x0D] = (char)((*((int*)(key_buffer1 + 0x10))) >> 0x10);
   shuffled_key[0x0E] = (char)((*((int*)(key_buffer1 + 0x10))) >> 8);

   unsigned char key_buffer2[0x20];
   unsigned char shuffled_seed[0x10];
   
   bigmac_read_key_from_keyring_80B11A(0x601, key_buffer2);
   
   shuffled_seed[0x03] = (char)((*((int*)(key_buffer2 + 0x0C))));
   shuffled_seed[0x00] = (char)((*((int*)(key_buffer2 + 0x0C))) >> 0x18);
   shuffled_seed[0x01] = (char)((*((int*)(key_buffer2 + 0x0C))) >> 0x10);
   shuffled_seed[0x02] = (char)((*((int*)(key_buffer2 + 0x0C))) >> 8);

   shuffled_seed[0x07] = (char)((*((int*)(key_buffer2 + 0x08))));
   shuffled_seed[0x04] = (char)((*((int*)(key_buffer2 + 0x08))) >> 0x18);
   shuffled_seed[0x05] = (char)((*((int*)(key_buffer2 + 0x08))) >> 0x10);
   shuffled_seed[0x06] = (char)((*((int*)(key_buffer2 + 0x08))) >> 8);

   shuffled_seed[0x0B] = (char)((*((int*)(key_buffer2 + 0x04))));
   shuffled_seed[0x08] = (char)((*((int*)(key_buffer2 + 0x04))) >> 0x18);
   shuffled_seed[0x09] = (char)((*((int*)(key_buffer2 + 0x04))) >> 0x10);
   shuffled_seed[0x0A] = (char)((*((int*)(key_buffer2 + 0x04))) >> 8);

   shuffled_seed[0x0F] = (char)((*((int*)(key_buffer2 + 0x00))));
   shuffled_seed[0x0C] = (char)((*((int*)(key_buffer2 + 0x00))) >> 0x18);
   shuffled_seed[0x0D] = (char)((*((int*)(key_buffer2 + 0x00))) >> 0x10);
   shuffled_seed[0x0E] = (char)((*((int*)(key_buffer2 + 0x00))) >> 0x8);

   unsigned char iv[0x10];

   memset(iv, 0, 0x10);

   int r0 = bigmac_aes_128_cbc_encrypt_with_potential_key_and_iv_80D906(dst, shuffled_seed, 0x10, shuffled_key, iv);
   if(r0 != 0)
      return 5;
   
   return 0;
}

int encrypt_with_static_key_ids_80CEFE(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char encrypted_key[0x10] = {0};

   int r0 = get_encrypted_shuffled_key_from_key_0x601_0x602_80CA94(encrypted_key);
   if(r0 != 0)
      return r0;

   unsigned char work_buffer_812E80[0x800] = {0};

   memcpy(work_buffer_812E80, ctx->data, ctx->size);

   unsigned char iv[0x10];
   memset(iv, 0, 0x10);

   unsigned char work_buffer_813680[0x800] = {0};

   int r1 = bigmac_aes_128_cbc_encrypt_with_potential_key_and_iv_80D906(work_buffer_813680, work_buffer_812E80, ctx->size, encrypted_key, iv);
   if(r1 != 0)
      return r1;

   memcpy(ctx->data, work_buffer_813680, ctx->size);

   return 0;
}

int decrypt_with_static_key_ids_80CC02(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char encrypted_key[0x10] = {0};

   int r0 = get_encrypted_shuffled_key_from_key_0x601_0x602_80CA94(encrypted_key);
   if(r0 != 0)
      return r0;

   unsigned char work_buffer_812E80[0x800] = {0};

   memcpy(work_buffer_812E80, ctx->data, ctx->size);

   unsigned char iv[0x10];
   memset(iv, 0, 0x10);

   unsigned char work_buffer_813680[0x800] = {0};

   int r1 = bigmac_aes_128_cbc_decrypt_with_potential_key_and_iv_80D928(work_buffer_813680, work_buffer_812E80, ctx->size, encrypted_key, iv);
   if(r1 != 0)
      return r1;

   memcpy(ctx->data, work_buffer_813680, ctx->size);

   return 0;
}

//==========================================

int ecc_modulus_80FD6E(unsigned char* dst, const unsigned char* nonce, int nonce_size_blocks, int nonce_size, const unsigned char* N, int N_blocks_size, int N_size)
{
   return ecc_modulus(nonce, nonce_size, N, N_size, dst);
}

int modulus_ecc_160_80FF34(unsigned char* dst, const unsigned char* nonce, const unsigned char* n)
{
   return ecc_modulus_80FD6E(dst, nonce, 0xA, 0x28, n, 5, 0x14);
}

int modulus_ecc_224_80FF50(unsigned char* dst, const unsigned char* nonce, const unsigned char* n)
{
   return ecc_modulus_80FD6E(dst, nonce, 0xF, 0x3C, n, 7, 0x1C);
}

//==========================================

int multiply_generator_ecc_curve_point_80DD96(unsigned char* curve_point_output[2], const unsigned char* multiplier, const unsigned char* curve[6], int size_blocks, int size)
{
   ecdsa_params params;

   memcpy(params.P, curve[0], size);
   memcpy(params.A, curve[1], size);
   memcpy(params.B, curve[2], size);
   memcpy(params.N, curve[3], size);
   memcpy(params.G.X, curve[4], size);
   memcpy(params.G.Y, curve[5], size);

   ecdsa_point output_point;

   ecc_multiply(size, &params, multiplier, &output_point);

   memcpy(curve_point_output[0], output_point.X, size);
   memcpy(curve_point_output[1], output_point.Y, size);

   return 0;
}

int multiply_ECC_160_generator_curve_point_80DEA4(unsigned char* curve_point_output[2] , const unsigned char* multiplier, const unsigned char* curve[6])
{
   return multiply_generator_ecc_curve_point_80DD96(curve_point_output, multiplier, curve, 5, 0x14);
}

int multiply_ECC_224_generator_curve_point_80DEB8(unsigned char* curve_point_output[2] , const unsigned char* multiplier, const unsigned char* curve[6])
{
   return multiply_generator_ecc_curve_point_80DD96(curve_point_output, multiplier, curve, 7, 0x1C);
}

//==========================================

int multiply_ecc_custom_curve_point_80EB50(unsigned char* curve_point_output[2], const unsigned char* multiplier, const unsigned char* curve_point_input[2], const unsigned char* curve[6], int size_blocks, int size)
{
   ecdsa_params params;

   memcpy(params.P, curve[0], size);
   memcpy(params.A, curve[1], size);
   memcpy(params.B, curve[2], size);
   memcpy(params.N, curve[3], size);
   memcpy(params.G.X, curve[4], size);
   memcpy(params.G.Y, curve[5], size);

   ecdsa_point input_point;
   memcpy(input_point.X, curve_point_input[0], size);
   memcpy(input_point.Y, curve_point_input[1], size);

   ecdsa_point output_point;

   ecc_multiply(size, &params, &input_point, multiplier, &output_point);

   memcpy(curve_point_output[0], output_point.X, size);
   memcpy(curve_point_output[1], output_point.Y, size);

   return 0;
}

int multiply_ecc_160_custom_curve_point_80EDEA(unsigned char* curve_point_output[2], const unsigned char* multiplier, const unsigned char* curve_point_input[2], const unsigned char* curve[6])
{
   return multiply_ecc_custom_curve_point_80EB50(curve_point_output, multiplier, curve_point_input, curve, 5, 0x14);
}

int multiply_ecc_224_custom_curve_point_80EE00(unsigned char* curve_point_output[2], const unsigned char* multiplier, const unsigned char* curve_point_input[2], const unsigned char* curve[6])
{
   return multiply_ecc_custom_curve_point_80EB50(curve_point_output, multiplier, curve_point_input, curve, 7, 0x1C);
}

//==========================================

int sign_ecc_80EE76(unsigned char* sig[2], const unsigned char* M, const unsigned char* nonce, const unsigned char* Pk, const unsigned char* curve[6], int size_blocks, int size)
{
   ecdsa_params params;

   memcpy(params.P, curve[0], size);
   memcpy(params.A, curve[1], size);
   memcpy(params.B, curve[2], size);
   memcpy(params.N, curve[3], size);
   memcpy(params.G.X, curve[4], size);
   memcpy(params.G.Y, curve[5], size);

   ecdsa_signature signature;

   ecdsa_sign(size, M, Pk, &params, nonce, &signature);

   memcpy(sig[0], signature.r, size);
   memcpy(sig[1], signature.s, size);

   return 0;
}

int sign_ecc_160_80F4B4(unsigned char* sig[2], const unsigned char* M, const unsigned char* nonce, const unsigned char* Pk, const unsigned char* curve[6])
{
   return sign_ecc_80EE76(sig, M, nonce, Pk, curve, 5, 0x14);
}

int sign_ecc_224_80F4CE(unsigned char* sig[2], const unsigned char* M, const unsigned char* nonce, const unsigned char* Pk, const unsigned char* curve[6])
{
   return sign_ecc_80EE76(sig, M, nonce, Pk, curve, 7, 0x1C);
}

//==========================================

int verify_ecc_signature_80F548(const unsigned char* sig[2], const unsigned char* M, const unsigned char* Qa[2], const unsigned char* curve[6], int size_blocks, int size)
{
   ecdsa_params params;

   memcpy(params.P, curve[0], size);
   memcpy(params.A, curve[1], size);
   memcpy(params.B, curve[2], size);
   memcpy(params.N, curve[3], size);
   memcpy(params.G.X, curve[4], size);
   memcpy(params.G.Y, curve[5], size);

   ecdsa_signature signature;
   memcpy(signature.r, sig[0], size);
   memcpy(signature.s, sig[1], size);

   ecdsa_point pub_key;
   memcpy(pub_key.X, Qa[0], size);
   memcpy(pub_key.Y, Qa[1], size);
   
   return ecdsa_verify(size, &signature, M, &pub_key, &params);
}

int verify_signature_ECC_160_80FD3E(const unsigned char* sig[2], const unsigned char* M, const unsigned char* Qa[2], const unsigned char* curve[6])
{
   return verify_ecc_signature_80F548(sig, M, Qa, curve, 5, 0x14);
}

int verify_signature_ECC_224_80FD56(const unsigned char* sig[2], const unsigned char* M, const unsigned char* Qa[2], const unsigned char* curve[6])
{
   return verify_ecc_signature_80F548(sig, M, Qa, curve, 7, 0x1C);
}

//==========================================

int get_command_4_key(int key_id, const unsigned char** key, int* src_key_slot, int* dst_key_slot)
{
   switch(key_id)
   {
   case 0x02:
      *key = cmd_4_7_key0_8125C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x03:
      *key = cmd_4_7_key1_812600;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x04:
      *key = cmd_4_7_key2_812640;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x05:
      *key = cmd_4_7_key3_812680;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0C:
      *key = cmd_4_7_key4_8126C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0D:
      *key = cmd_4_7_key5_812700;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0E:
      *key = cmd_4_7_key6_812740;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0F:
      *key = cmd_4_7_key7_812780;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x10:
      *key = cmd_4_7_key8_8127C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x11:
      *key = cmd_4_7_key9_812800;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x12:
      *key = cmd_4_7_key10_812840;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x13:
      *key = cmd_4_7_key11_812880;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x38:
      *key = cmd_4_7_key12_8128C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x39:
      *key = cmd_4_7_key13_812900;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x3A:
      *key = cmd_4_7_key14_812940;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;

   //case 0x44:
   //   *key = cmd_7_key15_812980; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0x53:
   //   *key = cmd_7_key16_8129C0; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0x57:
   //   *key = cmd_7_key17_812A00; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0x63:
   //   *key = cmd_7_key18_812A40; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0x64:
   //   *key = cmd_7_key19_812A80; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0x68:
   //   *key = cmd_7_key20_812AC0; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;

   case 0x80:
      *key = cmd_4_7_key21_812B00;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x81:
      *key = cmd_4_7_key22_812B40;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x82:
      *key = cmd_4_7_key23_812B80;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x83:
      *key = cmd_4_7_key24_812BC0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;

   //case 0xC0:
   //   *key = cmd_7_key25_812C00; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0xC1:
   //   *key = cmd_7_key26_812C40; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0xC2:
   //   *key = cmd_7_key27_812C80; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;
   //case 0xC3:
   //   *key = cmd_7_key28_812CC0; // available only for decryption
   //   *src_key_slot = 0x340;
   //   *dst_key_slot = 0x10;
   //   return 0;

   default:
      return 0xE;
   }
}

int service_handler_0x1000B_command_4_80CF98(SceSblSmCommGcAuthMgrData_1000B* ctx)
{   
   if(ctx->key_id == 0x100)
      return encrypt_with_static_key_ids_80CEFE(ctx);
   
   const unsigned char* key = 0;
   int src_key_slot = 0;
   int dst_key_slot = 0;
   int r0 = get_command_4_key(ctx->key_id, &key, &src_key_slot, &dst_key_slot);
   if(r0 != 0)
      return r0;

   int r1 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key, dst_key_slot, src_key_slot);
   if(r1 != 0)
      return r1;

   unsigned char work_buffer_812E80[0x800] = {0};

   memcpy(work_buffer_812E80, ctx->data, ctx->size);

   unsigned char work_buffer_813680[0x800] = {0};
   
   int r2 = bigmac_aes_128_cbc_submit_with_keyslot_80B538(work_buffer_813680, work_buffer_812E80, ctx->size, dst_key_slot, 1); // AES-128-CBC encrypt
   if(r2 != 0)
      return r2;
    
   memcpy(ctx->data, work_buffer_813680, ctx->size);
   
   return 0;
}

int GcAuthMgrService::service_0x1000B_04(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_4_80CF98(ctx);
   
   return 0;
}

int get_command_7_key(int key_id, const unsigned char** key, int* src_key_slot, int* dst_key_slot)
{
   switch(key_id)
   {
   case 0x02:
      *key = cmd_4_7_key0_8125C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x03:
      *key = cmd_4_7_key1_812600;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x04:
      *key = cmd_4_7_key2_812640;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x05:
      *key = cmd_4_7_key3_812680;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0C:
      *key = cmd_4_7_key4_8126C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0D:
      *key = cmd_4_7_key5_812700;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0E:
      *key = cmd_4_7_key6_812740;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x0F:
      *key = cmd_4_7_key7_812780;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x10:
      *key = cmd_4_7_key8_8127C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x11:
      *key = cmd_4_7_key9_812800;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x12:
      *key = cmd_4_7_key10_812840;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x13:
      *key = cmd_4_7_key11_812880;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x38:
      *key = cmd_4_7_key12_8128C0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x39:
      *key = cmd_4_7_key13_812900;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x3A:
      *key = cmd_4_7_key14_812940;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;

   case 0x44:
      *key = cmd_7_key15_812980;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0x53:
      *key = cmd_7_key16_8129C0;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0x57:
      *key = cmd_7_key17_812A00;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0x63:
      *key = cmd_7_key18_812A40;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0x64:
      *key = cmd_7_key19_812A80;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0x68:
      *key = cmd_7_key20_812AC0;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;

   case 0x80:
      *key = cmd_4_7_key21_812B00;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x81:
      *key = cmd_4_7_key22_812B40;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x82:
      *key = cmd_4_7_key23_812B80;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;
   case 0x83:
      *key = cmd_4_7_key24_812BC0;
      *src_key_slot = 0x345;
      *dst_key_slot = 0x21;
      return 0;

   case 0xC0:
      *key = cmd_7_key25_812C00;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0xC1:
      *key = cmd_7_key26_812C40;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0xC2:
      *key = cmd_7_key27_812C80;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;
   case 0xC3:
      *key = cmd_7_key28_812CC0;
      *src_key_slot = 0x340;
      *dst_key_slot = 0x10;
      return 0;

   default:
      return 0xF;
   }
}

int service_handler_0x1000B_command_7_80CC9C(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   if(ctx->key_id == 0x100)
      return decrypt_with_static_key_ids_80CC02(ctx);
   
   const unsigned char* key = 0;
   int src_key_slot = 0;
   int dst_key_slot = 0;
   int r0 = get_command_7_key(ctx->key_id, &key, &src_key_slot, &dst_key_slot);
   if(r0 != 0)
      return r0;

   int r1 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key, dst_key_slot, src_key_slot);
   if(r1 != 0)
      return r1;

   unsigned char work_buffer_812E80[0x800] = {0};

   memcpy(work_buffer_812E80, ctx->data, ctx->size);

   unsigned char work_buffer_813680[0x800] = {0};
   
   int r2 = bigmac_aes_128_cbc_submit_with_keyslot_80B538(work_buffer_813680, work_buffer_812E80, ctx->size, dst_key_slot, 2); // AES-128-CBC decrypt
   if(r2 != 0)
      return r2;

   memcpy(ctx->data, work_buffer_813680, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_07(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_7_80CC9C(ctx);

   return -1;
}

int service_handler_0x1000B_command_C_80C9F4(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char nonce[0x40];
   bigmac_generate_random_number_80C462(nonce, 0x40);

   unsigned char nonce_modulus[0x14];
   modulus_ecc_160_80FF34(nonce_modulus, nonce, N_ptr_160_81259C);

   unsigned char output_curve_point_x[0x14];
   unsigned char output_curve_point_y[0x14];
   unsigned char* output_curve_point[2] = {output_curve_point_x, output_curve_point_y};

   multiply_ECC_160_generator_curve_point_80DEA4(output_curve_point, nonce_modulus, ECC_160_curve_812590);

   // construct response

   int response_size = 0x3C;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_0C_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_0C_output*)ctx->data;

   memcpy(output_data->private_key, nonce_modulus, 0x14);

   memcpy(output_data->public_key_x, output_curve_point[0], 0x14);

   memcpy(output_data->public_key_y, output_curve_point[1], 0x14);

   return 0;
}

int GcAuthMgrService::service_0x1000B_0C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_C_80C9F4(ctx);

   return 0;
}

int service_handler_0x1000B_command_D_80B2C8(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_0D_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_0D_input*)ctx->data;

   unsigned char multiplier[0x14];

   memcpy(multiplier, input_data->multiplier, 0x14);

   unsigned char x[0x14];
   unsigned char y[0x14];
   const unsigned char* curve_point[2] = {x, y};

   memcpy(x, input_data->x, 0x14);
   memcpy(y, input_data->y, 0x14);

   unsigned char output_x[0x14];
   unsigned char output_y[0x14];
   unsigned char* output_curve_point[2] = {output_x, output_y};

   multiply_ecc_160_custom_curve_point_80EDEA(output_curve_point, multiplier, curve_point, ECC_160_curve_812590);

   // construct response

   int response_size = 0x28;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_0D_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_0D_output*)ctx->data;

   memcpy(output_data->x, output_curve_point[0], 0x14);

   memcpy(output_data->y, output_curve_point[1], 0x14);

   return 0;
}

int GcAuthMgrService::service_0x1000B_0D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_D_80B2C8(ctx);

   return 0;
}

int service_handler_0x1000B_command_E_80C9A6(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char rng[0x20] = {0};

   int r0 = bigmac_generate_random_number_80C462(rng, 0x20);
   if(r0 != 0)
      return 5;

   // construct response

   int response_size = 0x14;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_0E_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_0E_output*)ctx->data;

   memcpy(output_data->random, rng, 0x14);

   return 0;
}

int GcAuthMgrService::service_0x1000B_0E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_E_80C9A6(ctx);

   return 0;
}

int service_handler_0x1000B_command_10_80C8CA(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_10_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_10_input*)ctx->data;

   unsigned char nonce_modulus[0x14];

   while(true)
   {
      unsigned char nonce[0x40];
      int r0 = bigmac_generate_random_number_80C462(nonce, 0x40);
      if(r0 != 0)
         return 5;

      int r1 = modulus_ecc_160_80FF34(nonce_modulus, nonce, N_ptr_160_81259C);
      if(r1 == 0)
         break;
   }

   int r2 = bigmac_aes_128_ecb_encrypt_set_keyslot_0x0_from_0x204_80B5EE(key_seed_812580);
   if(r2 != 0)
      return r2;

   unsigned char work_buffer_812E80[0x20];
   memcpy(work_buffer_812E80, input_data->enc_private_key, 0x20);

   unsigned char work_buffer_813680[0x20];
   bigmac_aes_128_cbc_decrypt_with_keyslot_0x0_80B67A(work_buffer_813680, work_buffer_812E80, 0x20);
   
   unsigned char message_hash[0x14];
   memcpy(message_hash, input_data->message_hash, 0x14);

   unsigned char sig_r[0x14] = {0};
   unsigned char sig_s[0x14] = {0};
   unsigned char* sig_ptrs[2] = {sig_r, sig_s};

   int r3 = sign_ecc_160_80F4B4(sig_ptrs, message_hash, nonce_modulus, work_buffer_813680, ECC_160_curve_812590);
   if(r3 != 0)
      return 5;

   // construct response

   int response_size = 0x28;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_10_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_10_output*)ctx->data;

   memcpy(output_data->r, sig_ptrs[0], 0x14);

   memcpy(output_data->s, sig_ptrs[1], 0x14);

   return 0;
}

int GcAuthMgrService::service_0x1000B_10(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_10_80C8CA(ctx);

   return 0;
}

int service_handler_0x1000B_command_11_80B372(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_11_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_11_input*)ctx->data;

   unsigned char public_key_x[0x14];
   memcpy(public_key_x, input_data->public_key_x, 0x14);

   unsigned char public_key_y[0x14];
   memcpy(public_key_y, input_data->public_key_y, 0x14);

   const unsigned char* Qa[2] = {public_key_x, public_key_y};

   unsigned char message_hash[0x14];
   memcpy(message_hash, input_data->message_hash, 0x14);

   unsigned char signature_r[0x14];
   memcpy(signature_r, input_data->signature_r, 0x14);

   unsigned char signature_s[0x14];
   memcpy(signature_s, input_data->signature_s, 0x14);

   const unsigned char* signature[2] = {signature_r, signature_s};

   int r0 = verify_signature_ECC_160_80FD3E(signature, message_hash, Qa, ECC_160_curve_812590);
   if(r0 != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_11(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_11_80B372(ctx);

   return 0;
}

int service_handler_0x1000B_command_12_80D374(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_12_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_12_input*)ctx->data;

   unsigned char message_cmac[0x40];
   memset(message_cmac, 0, 0x40);

   int r0 = bigmac_aes_128_ecb_encrypt_set_keyslot_0x0_from_0x204_80B5EE(key_seed_812500);
   if(r0 != 0)
      return r0;

   int r1 = sw_cmac_with_keyslot_0x212_80D182(message_cmac, input_data->message, 0xA8);
   if(r1 != 0)
      return r1;

   unsigned char expected_cmac[0x40];
   memset(expected_cmac, 0, 0x40);

   int r2 = bigmac_aes_128_cbc_decrypt_with_keyslot_0x0_80B67A(expected_cmac, input_data->enc_cmac, 0x10);
   if(r2 != 0)
      return r2;

   if(memcmp(message_cmac, expected_cmac, 0x10) != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_12(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_12_80D374(ctx);

   return 0;
}

int service_handler_0x1000B_command_14_80C828(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char nonce[0x40];
   bigmac_generate_random_number_80C462(nonce, 0x40);

   unsigned char nonce_modulus[0x1C];
   modulus_ecc_224_80FF50(nonce_modulus, nonce, N_ptr_224_81251C);

   unsigned char output_curve_point_x[0x1C];
   unsigned char output_curve_point_y[0x1C];
   unsigned char* output_curve_point[2] = {output_curve_point_x, output_curve_point_y};

   multiply_ECC_224_generator_curve_point_80DEB8(output_curve_point, nonce_modulus, ECC_224_curve_812510);

   // construct response

   int response_size = 0x54;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_14_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_14_output*)ctx->data;

   memcpy(output_data->private_key, nonce_modulus, 0x1C);

   memcpy(output_data->public_key_x, output_curve_point[0], 0x1C);

   memcpy(output_data->public_key_y, output_curve_point[1], 0x1C);

   return 0;
}

int GcAuthMgrService::service_0x1000B_14(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_14_80C828(ctx);

   return 0;
}

int service_handler_0x1000B_command_15_80B72A(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_15_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_15_input*)ctx->data;

   unsigned char multiplier[0x1C];

   memcpy(multiplier, input_data->multiplier, 0x1C);

   unsigned char x[0x1C];
   unsigned char y[0x1C];
   const unsigned char* curve_point[2] = {x, y};

   memcpy(x, input_data->x, 0x1C);
   memcpy(y, input_data->y, 0x1C);

   unsigned char output_x[0x1C];
   unsigned char output_y[0x1C];
   unsigned char* output_curve_point[2] = {output_x, output_y};

   multiply_ecc_224_custom_curve_point_80EE00(output_curve_point, multiplier, curve_point, ECC_224_curve_812510);

   // construct response

   int response_size = 0x38;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_15_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_15_output*)ctx->data;

   memcpy(output_data->x, output_curve_point[0], 0x1C);

   memcpy(output_data->y, output_curve_point[1], 0x1C);

   return 0;
}

int GcAuthMgrService::service_0x1000B_15(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_15_80B72A(ctx);

   return 0;
}

int service_handler_0x1000B_command_16_80C7DA(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char rng[0x20] = {0};

   int r0 = bigmac_generate_random_number_80C462(rng, 0x20);
   if(r0 != 0)
      return 5;

   // construct response

   int response_size = 0x1C;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_16_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_16_output*)ctx->data;

   memcpy(output_data->random, rng, 0x1C);

   return 0;
}

int GcAuthMgrService::service_0x1000B_16(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_16_80C7DA(ctx);

   return 0;
}

int service_handler_0x1000B_command_17_80C6FC(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_17_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_17_input*)ctx->data;

   unsigned char nonce_modulus[0x1C];

   while(true)
   {
      unsigned char nonce[0x40];
      int r0 = bigmac_generate_random_number_80C462(nonce, 0x40);
      if(r0 != 0)
         return 5;

      int r1 = modulus_ecc_224_80FF50(nonce_modulus, nonce, N_ptr_224_81251C);
      if(r1 == 0)
         break;
   }

   int r2 = bigmac_aes_128_ecb_encrypt_set_keyslot_0x0_from_0x204_80B5EE(key_seed_812580);
   if(r2 != 0)
      return r2;

   unsigned char work_buffer_812E80[0x20];
   memcpy(work_buffer_812E80, input_data->enc_private_key, 0x20);

   unsigned char work_buffer_813680[0x20];
   bigmac_aes_128_cbc_decrypt_with_keyslot_0x0_80B67A(work_buffer_813680, work_buffer_812E80, 0x20);
   
   unsigned char message_hash[0x1C];
   memcpy(message_hash, input_data->message_hash, 0x1C);

   unsigned char sig_r[0x1C] = {0};
   unsigned char sig_s[0x1C] = {0};
   unsigned char* sig_ptrs[2] = {sig_r, sig_s};

   int r3 = sign_ecc_224_80F4CE(sig_ptrs, message_hash, nonce_modulus, work_buffer_813680, ECC_224_curve_812510);
   if(r3 != 0)
      return 5;

   // construct response

   int response_size = 0x38;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_17_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_17_output*)ctx->data;

   memcpy(output_data->r, sig_ptrs[0], 0x1C);

   memcpy(output_data->s, sig_ptrs[1], 0x1C);

   return 0;
}

int GcAuthMgrService::service_0x1000B_17(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_17_80C6FC(ctx);

   return 0;
}

int service_handler_0x1000B_command_18_80B7DA(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_18_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_18_input*)ctx->data;

   unsigned char public_key_x[0x1C];
   memcpy(public_key_x, input_data->public_key_x, 0x1C);

   unsigned char public_key_y[0x1C];
   memcpy(public_key_y, input_data->public_key_y, 0x1C);

   const unsigned char* Qa[2] = {public_key_x, public_key_y};

   unsigned char message_hash[0x1C];
   memcpy(message_hash, input_data->message_hash, 0x1C);

   unsigned char signature_r[0x1C];
   memcpy(signature_r, input_data->signature_r, 0x1C);

   unsigned char signature_s[0x1C];
   memcpy(signature_s, input_data->signature_s, 0x1C);

   const unsigned char* signature[2] = {signature_r, signature_s};

   int r0 = verify_signature_ECC_224_80FD56(signature, message_hash, Qa, ECC_224_curve_812510);
   if(r0 != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_18(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_18_80B7DA(ctx);

   return 0;
}

int service_handler_0x1000B_command_19_80D2E4(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_19_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_19_input*)ctx->data;

   unsigned char message_cmac[0x40];
   memset(message_cmac, 0, 0x40);

   int r0 = bigmac_aes_128_ecb_encrypt_set_keyslot_0x0_from_0x204_80B5EE(key_seed_812500);
   if(r0 != 0)
      return r0;

   int r1 = sw_cmac_with_keyslot_0x212_80D182(message_cmac, input_data->message, 0xD8);
   if(r1 != 0)
      return r1;

   unsigned char expected_cmac[0x40];
   memset(expected_cmac, 0, 0x40);

   int r2 = bigmac_aes_128_cbc_decrypt_with_keyslot_0x0_80B67A(expected_cmac, input_data->enc_cmac, 0x10);
   if(r2 != 0)
      return r2;

   if(memcmp(message_cmac, expected_cmac, 0x10) != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_19(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_19_80D2E4(ctx);

   return 0;
}

int service_handler_0x1000B_command_1B_80BC44(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1B_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1B_input*)ctx->data;

   unsigned char drv_key[0x10];
   int mode;

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(input_data->packet6_chunk, ctx->key_id, drv_key, &mode);
   if(res0 != 0)
      return res0;

   unsigned char dec_input[0x20];
   memcpy(dec_input, input_data->packet8_chunk + 3, 0x20);
   
   int res1 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input, 0x20, drv_key, mode);
   
   int res2 = memcmp(input_data->packet7_chunk + 1, dec_input + 0x11, 0xF);
   if(res2 != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_1B(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_1B_80BC44(ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_1C_80C604( SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1C_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1C_input*)ctx->data;

   int mode;
   unsigned char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(input_data->packet6_chunk, ctx->key_id, drv_key, &mode);
   if(res0 != 0)
      return res0;

   unsigned char dec_input[0x20];
   memcpy(dec_input, input_data->packet8_chunk, 0x20);

   int res1 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input, 0x20, drv_key, mode);

   unsigned char dec_part0[0x10];
   unsigned char dec_part1[0x10];
                           
   memcpy(dec_part0, dec_input + 0x00, 0x10);
   memcpy(dec_part1, dec_input + 0x10, 0x10);

   dec_part0[0] |= 0x80;
   dec_part1[0] |= 0x80;

   unsigned char session_id[0x20];
   
   int res2 = bigmac_generate_random_number_80C462(session_id, 0x20);
   if(res2 != 0)
      return 5;

   unsigned char enc_output[0x30];
   
   memcpy(enc_output + 0x00, session_id, 0x10);
   memcpy(enc_output + 0x10, dec_part1, 0x10);
   memcpy(enc_output + 0x20, dec_part0, 0x10);

   int res3 = bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(enc_output, 0x30, drv_key, mode);

   int response_size = 0x33;
   
   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_1C_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_1C_output*)ctx->data;
   output_data->command = 0xA3;
   output_data->unknown = 0;
   output_data->size = response_size;
   
   memcpy(output_data->data, enc_output, 0x30);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_1C_80C604(ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  // 0x40 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_1D_80BFC0(SceSblSmCommGcAuthMgrData_1000B* ctx)
{  
   SceSblSmCommGcAuthMgrData_1000B_1D_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1D_input*)ctx->data;

   unsigned char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_key_80BCB6(input_data->packet6_chunk, ctx->key_id, input_data->packet9_chunk, drv_key);
   if(res0 != 0)
      return res0;

   unsigned char dec_input[0x40];
   memcpy(dec_input, input_data->packet14_chunk + 3, 0x40);

   int res1 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input, 0x40, drv_key, 1); //dec with key mode

   int res2 = memcmp(input_data->packet13_chunk + 1, dec_input + 9, 0xF);
   if(res2 != 0)
      return 5;

   int res3 = memcmp(input_data->packet6_chunk, dec_input + 0x18, 0x20);
   if(res3 != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_1D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_1D_80BFC0(ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_1E_80C4F6(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1E_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1E_input*)ctx->data;

   //derive encryption key

   unsigned char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_key_80BCB6(input_data->packet6_chunk, ctx->key_id, input_data->packet9_chunk, drv_key);
   if(res0 != 0)
      return res0;

   //generate session id

   unsigned char session_id[0x20];

   int res1 = bigmac_generate_random_number_80C462(session_id, 0x20);
   if(res1 != 0)
      return 5;

   //construct challenge

   unsigned char enc_output[0x20];

   memcpy(enc_output, session_id, 0x10); // copy 0x10 bytes of session_id
   enc_output[0] |= 0x80; // tweak session_id
   memset(enc_output + 0x10, 0, 0x10); // set other 0x10 bytes to 0
   enc_output[0x1F]= input_data->parameter; // tweak other bytes

   //encrypt challenge
   
   int res2 = bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(enc_output, 0x20, drv_key, 1); // enc with key mode

   //construct buffer for cmac

   unsigned char cmac_input[0x30];

   cmac_input[0] = 0xB1; // set command
   cmac_input[1] = 0; // set unknown
   cmac_input[2] = 0x33; // set size
   memset(cmac_input + 3, 0, 0xD); // set other bytes to 0
   memcpy(cmac_input + 0x10, enc_output, 0x20); // 0x20 bytes of data that was encrypted

   //calculate cmac

   unsigned char cmac_output[0x10];

   int res3 = bigmac_cmac_aes_128_with_key_80BA5C(cmac_input, 0x30, drv_key, cmac_output);

   //update response size in context

   int response_size = 0x33;

   ctx->size = response_size;

   //construct output

   SceSblSmCommGcAuthMgrData_1000B_1E_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_1E_output*)ctx->data;
   output_data->command = 0xB1;
   output_data->unknown = 0;
   output_data->size = response_size;
   memcpy(output_data->data + 3, enc_output, 0x20); // 0x20 bytes of data that was encrypted
   memcpy(output_data->data + 0x23, cmac_output, 0x10); //0x10 bytes of cmac (same packet header + encrypted data)

   return 0;
}

int GcAuthMgrService::service_0x1000B_1E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_1E_80C4F6(ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  //0x51 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_1F_80BEC4(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1F_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1F_input*)ctx->data;
 
   unsigned char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_key_80BCB6(input_data->packet6_chunk, ctx->key_id, input_data->packet9_chunk, drv_key);
   if(res0 != 0)
      return res0;

   unsigned char cmac_input[0x40];
   
   memcpy(cmac_input, input_data->packet16_chunk, 3);
   memset(cmac_input + 3, 0, 0xD);
   memcpy(cmac_input + 0x10, input_data->packet16_chunk + 3, 0x30);

   unsigned char cmac_output[0x10];

   int res1 = bigmac_cmac_aes_128_with_key_80BA5C(cmac_input, 0x40, drv_key, cmac_output);

   int res2 = memcmp(input_data->packet16_chunk + 0x33, cmac_output, 0x10);
   if(res2 != 0)
      return 5;

   unsigned char dec_input1[0x20];
   memcpy(dec_input1, input_data->packet15_chunk, 0x20);

   int res3 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input1, 0x20, drv_key, 1);  //dec with key mode

   unsigned char dec_input2[0x30];
   memcpy(dec_input2, input_data->packet16_chunk + 3, 0x30);

   int res4 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input2, 0x30, drv_key, 1);  //dec with key mode

   int res5 = memcmp(dec_input1 + 1, dec_input2 + 1, 0xF);
   if(res5 != 0)
      return 5;

   if(dec_input1[0x1F] == 3)
      return 0x12;

   int response_size = 0x20;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_1F_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_1F_output*)ctx->data;

   memcpy(output_data->unknown, dec_input2 + 0x10, response_size);
   
   return 0;
}

int GcAuthMgrService::service_0x1000B_1F(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_1F_80BEC4(ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x20;  //0xB3 -> 0x20
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_20_80BD06(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_20_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_20_input*)ctx->data;

   unsigned char drv_key[0x10];
   
   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_key_80BCB6(input_data->packet6_chunk, ctx->key_id, input_data->packet9_chunk, drv_key);
   if(res0 != 0)
      return res0;

   //=================

   unsigned char cmac_input1[0x40];
   
   memcpy(cmac_input1, input_data->packet18_chunk, 3);
   memset(cmac_input1 + 3, 0, 0xD);
   memcpy(cmac_input1 + 0x10, input_data->packet18_chunk + 3, 0x30);

   unsigned char cmac_output1[0x10];

   int res1 = bigmac_cmac_aes_128_with_key_80BA5C(cmac_input1, 0x40, drv_key, cmac_output1);

   int res2 = memcmp(input_data->packet18_chunk + 0x33, cmac_output1, 0x10);
   if(res2 != 0)
      return 5;

   //=================

   unsigned char dec_input1[0x20];

   memcpy(dec_input1, input_data->packet17_chunk, 0x20);

   int res3 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input1, 0x20, drv_key, 1);

   unsigned char dec_input2[0x30];

   memcpy(dec_input2, input_data->packet18_chunk + 3, 0x30);

   int res4 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input2, 0x30, drv_key, 1);

   int res5 = memcmp(dec_input1 + 1, dec_input2 + 1, 0xF);
   if(res5 != 0)
      return 5;

   if(dec_input1[0x1F] != 3)
      return 0x12;

   //=================

   unsigned char cmac_input2[0x50];
  
   memcpy(cmac_input2, input_data->packet20_chunk, 3);
   memset(cmac_input2 + 3, 0, 0xD);
   memcpy(cmac_input2 + 0x10, input_data->packet20_chunk + 3, 0x40);

   unsigned char cmac_output2[0x10];

   int res6 = bigmac_cmac_aes_128_with_key_80BA5C(cmac_input2, 0x50, drv_key, cmac_output2);

   int res7 = memcmp(input_data->packet20_chunk + 0x43, cmac_output2, 0x10);
   if(res7 != 0)
      return 5;

   //=================

   unsigned char dec_input3[0x40];
   memcpy(dec_input3, input_data->packet20_chunk + 3, 0x40); 

   int res8 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input3, 0x40, drv_key, 1);

   int res9 = memcmp(input_data->packet19_chunk + 1, dec_input3 + 9, 0xF);
   if(res9 != 0)
      return 5;

   //=================

   int response_size = 0x34;
   
   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_20_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_20_output*)ctx->data;
   
   unsigned char sha_input[0x40];
   memcpy(sha_input, dec_input3 + 0x18, 0x20);
   memcpy(sha_input + 0x20, dec_input2 + 0x10, 0x20);

   int res10 = bigmac_sha256_80BAC2(sha_input, 0x40, output_data->klicensee_keys); 

   int res11 = bigmac_sha1_80BB18(dec_input3 + 0x18, 0x20, output_data->rif_digest);

   return 0;
}

int GcAuthMgrService::service_0x1000B_20(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_20_80BD06(ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x34; //0x116 -> 0x34
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_21_80C36A(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_21_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_21_input*)ctx->data;

   unsigned char sig_r[0x14] = {0};
   unsigned char sig_s[0x14] = {0};
   unsigned char* sig_ptrs[2] = {sig_r, sig_s};

   // calculate contract

   unsigned char iv_94[0x20] = {0};

   int r0_0 = bigmac_hmac_sha256_contract_80C0F6(Pk_008125A8, input_data->message_hash, 0x14, iv_94);
   if(r0_0 != 0)
      return 5;

   unsigned char digest_D4[0x40] = {0};
   unsigned char nonce[0x14] = {0};

   // calculate nonce

   // this part is supposed to cycle forever on fail, untill modulus completes successfully

   while(true)
   {
      int r0_1 = bigmac_sha256_block_update_80C17A(input_data->message_hash, 0x14, iv_94, digest_D4);
      if(r0_1 != 0)
         return 5;

      int r0_2 = bigmac_sha256_block_update_80C17A(input_data->message_hash, 0x14, iv_94, digest_D4 + 0x20);
      if(r0_2 != 0)
         return 5;

      int r0_3 = modulus_ecc_160_80FF34(nonce, digest_D4, N_ptr_160_81259C);
      if(r0_3 == 0)
         break;
   }

   //check input

   for(int i = 0; i < 0x20; i++)
   {
      if(input_data->field0[i] != 0)
         return 5;
   }

   // calculate signature
   
   int r0_4 = sign_ecc_160_80F4B4(sig_ptrs, input_data->message_hash, nonce, Pk_008125A8, ECC_160_curve_812590);
   if(r0_4 != 0)
      return 5;

   // construct response

   int response_size = 0x28;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_21_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_21_output*)ctx->data;

   memcpy(output_data->r, sig_ptrs[0], 0x14);

   memcpy(output_data->s, sig_ptrs[1], 0x14);
   
   return 0;
}

int GcAuthMgrService::service_0x1000B_21(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_21_80C36A(ctx);

   return 0;
}

int service_handler_0x1000B_command_22_80C256(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_22_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_22_input*)ctx->data;

   // get Pk salt

   unsigned char* Pk = 0;

   if(ctx->key_id == 0)
   {
      Pk = Pk_00812528;
   }
   else if(ctx->key_id == 1)
   {
      Pk = Pk_00812544;
   }
   else
   {
      return 0x12;
   }

   unsigned char sig_r[0x1C] = {0};
   unsigned char sig_s[0x1C] = {0};
   unsigned char* sig_ptrs[2] = {sig_r, sig_s};

   // calculate contract

   unsigned char iv_B4[0x20] = {0};

   int r0_0 = bigmac_hmac_sha256_contract_80C0F6(Pk, input_data->message_hash, 0x1C, iv_B4);
   if(r0_0 != 0)
      return 5;

   unsigned char digest_F4[0x40] = {0};
   unsigned char nonce[0x1C] = {0};

   // calculate nonce

   // this part is supposed to cycle forever on fail, untill modulus completes successfully

   while(true)
   {
      int r0_1 = bigmac_sha256_block_update_80C17A(input_data->message_hash, 0x1C, iv_B4, digest_F4);
      if(r0_1 != 0)
         return 5;

      int r0_2 = bigmac_sha256_block_update_80C17A(input_data->message_hash, 0x1C, iv_B4, digest_F4 + 0x20);
      if(r0_2 != 0)
         return 5;

      int r0_3 = modulus_ecc_224_80FF50(nonce, digest_F4, N_ptr_224_81251C);
      if(r0_3 == 0)
         break;
   }

   //check input

   for(int i = 0; i < 0x20; i++)
   {
      if(input_data->field0[i] != 0)
         return 5;
   }

   // calculate signature
   
   int r0_4 = sign_ecc_224_80F4CE(sig_ptrs, input_data->message_hash, nonce, Pk, ECC_224_curve_812510);
   if(r0_4 != 0)
      return 5;

   // construct response

   int response_size = 0x38;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_22_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_22_output*)ctx->data;

   memcpy(output_data->r, sig_ptrs[0], 0x1C);

   memcpy(output_data->s, sig_ptrs[1], 0x1C);
   
   return 0;
}

int GcAuthMgrService::service_0x1000B_22(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_22_80C256(ctx);

   return 0;
}

int service_handler_0x1000B_command_23_80C04A(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_23_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_23_input*)ctx->data;

   unsigned char work_buffer_812E80[0x10] = {0};

   memcpy(work_buffer_812E80, input_data->message, 0x10);

   unsigned char iv_C[0x10];
   memset(iv_C, 0, 0x10);

   unsigned char work_buffer_813680[0x10] = {0};

   int res0 = bigmac_aes_128_cbc_encrypt_with_potential_key_and_iv_80D906(work_buffer_813680, work_buffer_812E80, 0x10, aes_key_0x23_812380, iv_C);
   if(res0 != 0)
      return 0x11;

   unsigned char cmac_value[0x10] = {0};

   int res1 = bigmac_cmac_aes_submit_80D990(cmac_value, work_buffer_813680, 0x10, cmac_key_0x23_8123C0, 0x10);
   if(res1 != 0)
      return 0x11;

   // construct response

   int response_size = 0x20;

   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_23_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_23_output*)ctx->data;

   memcpy(output_data->enc_message, work_buffer_813680, 0x10);
   
   memcpy(output_data->cmac, cmac_value, 0x10);

   return 0;
}

int GcAuthMgrService::service_0x1000B_23(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   *f00d_resp = service_handler_0x1000B_command_23_80C04A(ctx);

   return 0;
}

int GcAuthMgrService::service_0x1000B(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommGcAuthMgrData_1000B* ctx_cast = (SceSblSmCommGcAuthMgrData_1000B*)ctx;

   switch(ctx_cast->command)
   {
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_04:
      return service_0x1000B_04(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_07:
      return service_0x1000B_07(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0C:
      return service_0x1000B_0C(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0D:
      return service_0x1000B_0D(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0E:
      return service_0x1000B_0E(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_10:
      return service_0x1000B_10(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_11:
      return service_0x1000B_11(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_12:
      return service_0x1000B_12(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_14:
      return service_0x1000B_14(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_15:
      return service_0x1000B_15(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_16:
      return service_0x1000B_16(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_17:
      return service_0x1000B_17(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_18:
      return service_0x1000B_18(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_19:
      return service_0x1000B_19(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1B:
      return service_0x1000B_1B(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1C:
      return service_0x1000B_1C(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1D:
      return service_0x1000B_1D(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1E:
      return service_0x1000B_1E(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1F:
      return service_0x1000B_1F(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_20:
      return service_0x1000B_20(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_21:
      return service_0x1000B_21(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_22:
      return service_0x1000B_22(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_23:
      return service_0x1000B_23(f00d_resp, ctx_cast, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }

   return 0;
}

int GcAuthMgrService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case GCAUTHMGR_SERVICE_1000B:
      return service_0x1000B(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
