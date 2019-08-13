#include "GcAuthMgrService.h"

#include "Crypto/CryptoService.h"

//FIX POINTER CONSTNESS!!!!!!!!!!!!

using namespace f00d;

//curve 160

unsigned char ecc_160_p[0x14] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char ecc_160_a[0x14] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC};        
unsigned char ecc_160_b[0x14] = {0xA6, 0x8B, 0xED, 0xC3, 0x34, 0x18, 0x02, 0x9C, 0x1D, 0x3C, 0xE3, 0x3B, 0x9A, 0x32, 0x1F, 0xCC, 0xBB, 0x9E, 0x0F, 0x0B};
unsigned char ecc_160_n[0x14] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xB5, 0xAE, 0x3C, 0x52, 0x3E, 0x63, 0x94, 0x4F, 0x21, 0x27};
unsigned char ecc_160_gx[0x14] = {0x12, 0x8E, 0xC4, 0x25, 0x64, 0x87, 0xFD, 0x8F, 0xDF, 0x64, 0xE2, 0x43, 0x7B, 0xC0, 0xA1, 0xF6, 0xD5, 0xAF, 0xDE, 0x2C};
unsigned char ecc_160_gy[0x14] = {0x59, 0x58, 0x55, 0x7E, 0xB1, 0xDB, 0x00, 0x12, 0x60, 0x42, 0x55, 0x24, 0xDB, 0xC3, 0x79, 0xD5, 0xAC, 0x5F, 0x4A, 0xDF};

unsigned char* N_ptr_160_81259C = ecc_160_n;

unsigned char* ECC_160_curve_812590[6] = {ecc_160_p, ecc_160_a, ecc_160_b, ecc_160_n, ecc_160_gx, ecc_160_gy};

//curve 224

unsigned char ecc_224_0x22_p[0x1C] = {0xA5, 0x3E, 0x11, 0x3E, 0x46, 0xD8, 0xC9, 0xC1, 0xF0, 0x9D, 0x9B, 0xCB, 0x2A, 0x53, 0x73, 0xD3, 0x79, 0xF6, 0x9D, 0xA2, 0x8D, 0x09, 0x99, 0x9F, 0xED, 0x57, 0xA9, 0x0F}; // OK
unsigned char ecc_224_0x22_a[0x1C] = {0xA5, 0x3E, 0x11, 0x3E, 0x46, 0xD8, 0xC9, 0xC1, 0xF0, 0x9D, 0x9B, 0xCB, 0x2A, 0x53, 0x73, 0xD3, 0x79, 0xF6, 0x9D, 0xA2, 0x8D, 0x09, 0x99, 0x9F, 0xED, 0x57, 0xA9, 0x0C}; // OK
unsigned char ecc_224_0x22_b[0x1C] = {0x90, 0x65, 0x94, 0x1D, 0x29, 0x37, 0x4A, 0x8F, 0x11, 0xDD, 0x1E, 0x54, 0x01, 0x89, 0x43, 0x4E, 0x4A, 0x6E, 0xBF, 0xAF, 0x54, 0x77, 0xF6, 0xC1, 0x72, 0xF6, 0x85, 0x5E}; // OK
unsigned char ecc_224_0x22_n[0x1C] = {0xA5, 0x3E, 0x11, 0x3E, 0x46, 0xD8, 0xC9, 0xC1, 0xF0, 0x9D, 0x9B, 0xCB, 0x2A, 0x52, 0x26, 0x98, 0xDE, 0xEF, 0x58, 0xDB, 0x1A, 0xD9, 0xAB, 0x7F, 0x04, 0xE3, 0xAE, 0x7F}; // OK
unsigned char ecc_224_0x22_gx[0x1C] = {0x7E, 0x06, 0x09, 0x82, 0x47, 0xE6, 0xB5, 0x9F, 0x31, 0x10, 0xBC, 0xBB, 0x3A, 0xB6, 0xC2, 0x50, 0xBC, 0x5A, 0xB0, 0x6C, 0x03, 0x2D, 0xAD, 0x43, 0x68, 0x4C, 0x24, 0x8F}; // OK
unsigned char ecc_224_0x22_gy[0x1C] = {0x0B, 0xD9, 0x41, 0x8D, 0xE8, 0xE3, 0xE4, 0x5D, 0x2D, 0x70, 0x1E, 0x02, 0x37, 0xFD, 0x7F, 0x2A, 0xDE, 0x0D, 0x48, 0xB7, 0x4C, 0xEE, 0xF2, 0xF1, 0xC8, 0xAC, 0x48, 0x4E}; // OK

unsigned char* N_ptr_224_81251C = ecc_224_0x22_n;

unsigned char* ECC_224_curve_812510[6] = {ecc_224_0x22_p, ecc_224_0x22_a, ecc_224_0x22_b, ecc_224_0x22_n, ecc_224_0x22_gx, ecc_224_0x22_gy};

//==========================================

unsigned char key_812400[0x10] = {0x6F, 0x22, 0x85, 0xED, 0x46, 0x3A, 0x6E, 0x57, 0xC5, 0xF3, 0x55, 0x0D, 0xDC, 0xC8, 0x1F, 0xEB, };
unsigned char key_812440[0x10] = {0xDA, 0x96, 0x08, 0xB5, 0x28, 0x82, 0x5D, 0x6D, 0x13, 0xA7, 0xAF, 0x14, 0x46, 0xB8, 0xEC, 0x08, };
unsigned char key_812480[0x10] = {0x36, 0x8B, 0x2E, 0xB5, 0x43, 0x7A, 0x82, 0x18, 0x62, 0xA6, 0xC9, 0x55, 0x96, 0xD8, 0xC1, 0x35, };
unsigned char key_8124C0[0x10] = {0x7F, 0x1F, 0xD0, 0x65, 0xDD, 0x2F, 0x40, 0xB3, 0xE2, 0x65, 0x79, 0xA6, 0x39, 0x0B, 0x61, 0x6D, };

unsigned char iv_8124D0[0x10] = {0x8B, 0x14, 0xC8, 0xA1, 0xE9, 0x6F, 0x30, 0xA7, 0xF1, 0x01, 0xA9, 0x6A, 0x30, 0x33, 0xC5, 0x5B, };

int bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(unsigned char* src, int keyslot_dst, int keyslot_src)
{
   return 0;
}

int bigmac_cmac_aes_128_with_keyslot_80B87C(unsigned char* dst, const unsigned char* src, int size, int keyslot)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_set_keyslot_from_keyslot_80B486(unsigned char* src, unsigned char* iv, int keyslot_dst, int keyslot_src)
{
   return 0;
}

// mode 1 uses key
// mode 2 uses keyslot 0x24
int bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(unsigned char* src_dst, int size, unsigned char* key, int enc_mode)
{
   //iv is 0

   return 0;
}

int bigmac_generate_random_number_80C462(unsigned char* dst, int size)
{
   return 0;
}

// mode 1 uses key
// mode 2 uses keyslot 0x24
int bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(unsigned char* src_dst, int size, unsigned char* key, int enc_mode)
{
   return 0;
}

int bigmac_cmac_aes_128_with_key_80BA5C(unsigned char* src, int size, unsigned char* key, unsigned char* dst)
{
   return 0;
}

int bigmac_sha256_80BAC2(unsigned char* src, int size, unsigned char* dst)
{
   return 0;
}

int bigmac_sha1_80BB18(unsigned char* src, int size, unsigned char* dst)
{
   return 0;
}

//cmac_input - size 0x20
//cmac_output - size 0x10
int initialize_keyslot_0x21_0x24_with_cmac_80BB6E(unsigned char* cmac_input, int key_id, unsigned char* cmac_output, int* mode)
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

int initialize_keyslot_0x21_0x24_with_cmac_and_dec_key_80BCB6(unsigned char* cmac_input, int key_id, unsigned char* src, unsigned char* dst)
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

int bigmac_hmac_sha256_80D974(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, int permission)
{
   auto cryptops = CryptoService::get();
   return cryptops->hmac_sha256(src, dst, size, key, 0x20);
}

int bigmac_sha256_80D960(unsigned char* dst, const unsigned char* src, int size)
{
   auto cryptops = CryptoService::get();
   return cryptops->sha256(src, dst, size);
}

unsigned char hmac_256_key_812340[0x20] = {0x54, 0x88, 0xA9, 0x81, 0x1C, 0x9A, 0x2C, 0xBC, 0xCC, 0x59, 0x6B, 0x1F, 0xAD, 0x1A, 0x7E, 0x29, 
                                           0xE0, 0x75, 0x84, 0x0F, 0x47, 0x43, 0x1F, 0x37, 0xAC, 0x06, 0x02, 0x46, 0x4A, 0x27, 0x9E, 0x02};

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
   unsigned char src_xored[0x20];

   if (data_size > 0x20)
      return 0x12;

   for(int i = 0; i < data_size; i++)
      src_xored[i] = src[i] ^ iv[i];

   int r0 = bigmac_sha256_80D960(digest, src_xored, 0x20);
   if(r0 != 0)
      return 0x11;

   for(int i = 0; i < 0x20; i++)
      iv[i] = digest[i] ^ iv[i];

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

unsigned char salt_00812528[0x1C] = {0x76, 0x74, 0x36, 0xA6, 0x99, 0x9D, 0x88, 0x48, 0x0E, 0xC8, 0x56, 0xF5, 0x5C, 0xEA, 0xBB, 0x43, 0x96, 0x85, 0x9E, 0x37, 0x45, 0x99, 0x40, 0x39, 0x21, 0xF5, 0x55, 0x98};

unsigned char salt_00812544[0x1C] = {0x60, 0x7A, 0x2E, 0x55, 0x68, 0xB4, 0xB9, 0xA0, 0x32, 0xF4, 0x52, 0x53, 0xCF, 0xED, 0x20, 0xDB, 0x2E, 0x6E, 0x44, 0x6C, 0x37, 0x82, 0xE8, 0x2A, 0x1A, 0xB9, 0xC9, 0x23};

//---

int maybe_modulus_F00D_80FD6E(unsigned char* dst, unsigned char* nonce, int nonce_size_blocks, int nonce_size, unsigned char* N, int N_blocks_size, int N_size)
{
   //BN_bin2bn N - size is N_size
   //BN_bin2bn nonce - size is nonce_size 
   //check N (what is the check?)
   //copy nonce to 0xE0040000 (what is the buffer?) - size is nonce_size_blocks
   //copy N to 0xE0040000 (RsaModulusBuffer) - size is nonce_size_blocks
   //set 0xE0040800 (RsaControl) to ((N_size_blocks << 9) & (0x3FE00)) | (((0x3FC0000) & (nonce_size_blocks << 0x12)) | (0x58000000))
   //wait for completion by checking 0xE0040804 (RsaStatus)
   //copy to dst from 0xE0040000 (what is the buffer?) - size is N_size_blocks
   //check dst (what is the check?)
   //BN_bn2bin result to dst - size n_size_blocks

   return 0;
}

int cmd_0C_10_21_ecc_160_related_with_mode_maybe_modulus_F00D_80FF34(unsigned char* dst, unsigned char* nonce, unsigned char* n)
{
   return maybe_modulus_F00D_80FD6E(dst, nonce, 0xA, 0x28, n, 5, 0x14);
}

int cmd_14_17_22_ecc_224_related_with_mode_maybe_modulus_F00D_80FF50(unsigned char* dst, unsigned char* nonce, unsigned char* n)
{
   return maybe_modulus_F00D_80FD6E(dst, nonce, 0xF, 0x3C, n, 7, 0x1C);
}

//---

int maybe_BN_bin2bn_80FFD6(unsigned char* dst, unsigned char* src, int size)
{
   return 0;
}

int maybe_BN_bn2bin_81001A(unsigned char* dst, unsigned char* src, int size_blocks)
{
   return 0;
}

int unindentified_function_80DECC(unsigned char* multiplier, unsigned char* order, int size_blocks)
{
   return 0;
}

int maybe_multiply_ecc_curve_F00D_80DF18(unsigned char* curve_point_output[2], unsigned char* curve_point_input[2], unsigned char* curve_p, unsigned char* curve_a, unsigned char* multiplier)
{
   return 0;
}

//---

int multiply_generator_point_on_ecc_curve_F00D_80DD96(unsigned char* output_point[2], unsigned char* multiplier, unsigned char* curve[6], int size_blocks, int size)
{
   unsigned char curve_p_bn[0x28];
   unsigned char curve_a_bn[0x28];
   unsigned char curve_n_bn[0x28];
   unsigned char curve_gx_bn[0x28];
   unsigned char curve_gy_bn[0x28];

   maybe_BN_bin2bn_80FFD6(curve_p_bn, curve[0], size);
   maybe_BN_bin2bn_80FFD6(curve_a_bn, curve[1], size);
   maybe_BN_bin2bn_80FFD6(curve_n_bn, curve[3], size);
   maybe_BN_bin2bn_80FFD6(curve_gx_bn, curve[4], size);
   maybe_BN_bin2bn_80FFD6(curve_gy_bn, curve[5], size);

   unsigned char multiplier_bn[0x28];

   maybe_BN_bin2bn_80FFD6(multiplier_bn, multiplier, size);

   int r0 = unindentified_function_80DECC(multiplier_bn, curve_n_bn, size_blocks);
   if(r0 != 0)
      return -1;

   unsigned char output_x[0x28];
   unsigned char output_y[0x28];
   unsigned char* output_curve_point_bn[2] = {output_x, output_y};

   unsigned char* input_curve_point[2] = {curve_gx_bn, curve_gy_bn};

   maybe_multiply_ecc_curve_F00D_80DF18(output_curve_point_bn, input_curve_point, curve_p_bn, curve_a_bn, multiplier_bn);

   maybe_BN_bn2bin_81001A(output_point[0], output_curve_point_bn[0], size_blocks);

   maybe_BN_bn2bin_81001A(output_point[1], output_curve_point_bn[1], size_blocks);

   return 0;
}

int multiply_generator_point_on_ecc_curve_ecc_160_80DEA4(unsigned char* output_point[2] , unsigned char* multiplier, unsigned char* curve[6])
{
   return multiply_generator_point_on_ecc_curve_F00D_80DD96(output_point, multiplier, curve, 5, 0x14);
}

int multiply_generator_point_on_ecc_curve_ecc_224_80DEB8(unsigned char* output_point[2] , unsigned char* multiplier, unsigned char* curve[6])
{
   return multiply_generator_point_on_ecc_curve_F00D_80DD96(output_point, multiplier, curve, 7, 0x1C);
}

//---

int multiply_ecc_curve_point_80EB50(unsigned char* curve_point_output[2], unsigned char* multiplier, unsigned char* curve_point_input[2], unsigned char* curve[6], int size_blocks, int size)
{
   unsigned char curve_p_bn[0x28];
   unsigned char curve_a_bn[0x28];
   unsigned char curve_n_bn[0x28];

   maybe_BN_bin2bn_80FFD6(curve_p_bn, curve[0], size);
   maybe_BN_bin2bn_80FFD6(curve_a_bn, curve[1], size);
   maybe_BN_bin2bn_80FFD6(curve_n_bn, curve[3], size);

   unsigned char curve_point_input_x_bn[0x28];
   unsigned char curve_point_input_y_bn[0x28];

   maybe_BN_bin2bn_80FFD6(curve_point_input_x_bn, curve_point_input[0], size);
   maybe_BN_bin2bn_80FFD6(curve_point_input_y_bn, curve_point_input[1], size);

   //=============== those transformations probably do EC_POINT_set_affine_coordinates

   // do some additional checks of curve parameters (p, maybe a and n)

   unsigned char curve_point_trans_x[0x28];
   unsigned char curve_point_trans_y[0x28];

   if(size_blocks > 0)
   {
      //copy curve_point_input_x_bn to 0xE0040000 - size size_blocks
   }

   if(size_blocks > 0)
   {
      //copy curve_p to 0xE0040000 - size size_blocks
   }

   //set 0xE0040800 to (((size_blocks << 0x12) & 0x3FC0000) | 0x58000000) | ((r3 << 9) & 0x3FE00)
   //copy 0xE0040000 to curve_point_trans_x

   if(size_blocks > 0)
   {
      //copy curve_point_input_y_bn to 0xE0040000 - size size_blocks
   }

   //set 0xE0040800 to (((size_blocks << 0x12) & 0x3FC0000) | 0x58000000) | ((r3 << 9) & 0x3FE00)
   //copy 0xE0040000 to curve_point_trans_y

   //===============

   unsigned char multiplier_bn[0x28];

   maybe_BN_bin2bn_80FFD6(multiplier_bn, multiplier, size);

   int r0 = unindentified_function_80DECC(multiplier_bn, curve_n_bn, size_blocks); // not sure what does this call do
   if(r0 != 0)
      return -1;

   unsigned char output_x[0x28];
   unsigned char output_y[0x28];
   unsigned char* output_curve_point_bn[2] = {output_x, output_y};

   unsigned char* input_curve_point[2] = {curve_point_trans_x, curve_point_trans_y};

   // how equal is this to EC_POINT_mul ?
   // this call probably should include EC_POINT_get_affine_coordinates inside it

   maybe_multiply_ecc_curve_F00D_80DF18(output_curve_point_bn, input_curve_point, curve_p_bn, curve_a_bn, multiplier_bn);

   maybe_BN_bn2bin_81001A(curve_point_output[0], output_curve_point_bn[0], size_blocks);

   maybe_BN_bn2bin_81001A(curve_point_output[1], output_curve_point_bn[1], size_blocks);

   return 0;
}

int multiply_ECC_160_curve_point_80EDEA(unsigned char* curve_point_output[2], unsigned char* multiplier, unsigned char* curve_point_input[2], unsigned char* curve[6])
{
   return multiply_ecc_curve_point_80EB50(curve_point_output, multiplier, curve_point_input, curve, 5, 0x14);
}

int multiply_ECC_224_curve_point_80EE00(unsigned char* curve_point_output[2], unsigned char* multiplier, unsigned char** curve_point_input, unsigned char* curve[6])
{
   return multiply_ecc_curve_point_80EB50(curve_point_output, multiplier, curve_point_input, curve, 7, 0x1C);
}

//---

//for signing we need
//curve
//private key
//M
//nonce
//result is signature
int F00D_math_80EE76(unsigned char* sig[2], unsigned char*, unsigned char* , unsigned char* , unsigned char* curve[6], int size_blocks, int size)
{
   return 0;
}

int F00D_math_ecc_160_related_80F4B4(unsigned char* sig[2], unsigned char* b, unsigned char* c, unsigned char* d, unsigned char* curve[6])
{
   return F00D_math_80EE76(sig, b, c, d, curve, 5, 0x14);
}

int F00D_math_ecc_224_related_80F4CE(unsigned char* sig[2], unsigned char* b, unsigned char* c, unsigned char* d, unsigned char* curve[6])
{
   return F00D_math_80EE76(sig, b, c, d, curve, 7, 0x1C);
}

//==========================================

int GcAuthMgrService::service_0x1000B_04(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_4_80CF98();

   return -1;
}

int GcAuthMgrService::service_0x1000B_07(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_7_80CC9C();

   return -1;
}

struct SceSblSmCommGcAuthMgrData_1000B_0C_output
{
   unsigned char private_key[0x14];
   unsigned char public_key_x[0x14];
   unsigned char public_key_y[0x14];
};

int service_handler_0x1000B_command_C_80C9F4(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char nonce[0x40];
   bigmac_generate_random_number_80C462(nonce, 0x40);

   unsigned char nonce_modulus[0x14];
   cmd_0C_10_21_ecc_160_related_with_mode_maybe_modulus_F00D_80FF34(nonce_modulus, nonce, N_ptr_160_81259C);

   unsigned char output_curve_point_x[0x14];
   unsigned char output_curve_point_y[0x14];
   unsigned char* output_curve_point[2] = {output_curve_point_x, output_curve_point_y};

   multiply_generator_point_on_ecc_curve_ecc_160_80DEA4(output_curve_point, nonce_modulus, ECC_160_curve_812590);

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

struct SceSblSmCommGcAuthMgrData_1000B_0D_input
{
   unsigned char multiplier[0x14];
   unsigned char x[0x14];
   unsigned char y[0x14];
};

struct SceSblSmCommGcAuthMgrData_1000B_0D_output
{
   unsigned char x[0x14];
   unsigned char y[0x14];
};

int service_handler_0x1000B_command_D_80B2C8(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_0D_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_0D_input*)ctx->data;

   unsigned char multiplier[0x14];

   memcpy(multiplier, input_data->multiplier, 0x14);

   unsigned char x[0x14];
   unsigned char y[0x14];
   unsigned char* curve_point[2] = {x, y};

   memcpy(x, input_data->x, 0x14);
   memcpy(y, input_data->y, 0x14);

   unsigned char output_x[0x14];
   unsigned char output_y[0x14];
   unsigned char* output_curve_point[2] = {output_x, output_y};

   multiply_ECC_160_curve_point_80EDEA(output_curve_point, multiplier, curve_point, ECC_160_curve_812590);

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

int GcAuthMgrService::service_0x1000B_0E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_E_80C9A6();

   return -1;
}

int GcAuthMgrService::service_0x1000B_10(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_10_80C8CA();

   return -1;
}

int GcAuthMgrService::service_0x1000B_11(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_11_80B372();

   return -1;
}

int GcAuthMgrService::service_0x1000B_12(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_12_80D374();

   return -1;
}

struct SceSblSmCommGcAuthMgrData_1000B_14_output
{
   unsigned char private_key[0x1C];
   unsigned char public_key_x[0x1C];
   unsigned char public_key_y[0x1C];
};

int service_handler_0x1000B_command_14_80C828(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   unsigned char nonce[0x40];
   bigmac_generate_random_number_80C462(nonce, 0x40);

   unsigned char nonce_modulus[0x1C];
   cmd_14_17_22_ecc_224_related_with_mode_maybe_modulus_F00D_80FF50(nonce_modulus, nonce, N_ptr_224_81251C);

   unsigned char output_curve_point_x[0x1C];
   unsigned char output_curve_point_y[0x1C];
   unsigned char* output_curve_point[2] = {output_curve_point_x, output_curve_point_y};

   multiply_generator_point_on_ecc_curve_ecc_224_80DEB8(output_curve_point, nonce_modulus, ECC_224_curve_812510);

   // construct response

   int response_size = 0x3C;

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

struct SceSblSmCommGcAuthMgrData_1000B_15_input
{
   unsigned char multiplier[0x1C];
   unsigned char x[0x1C];
   unsigned char y[0x1C];
};

struct SceSblSmCommGcAuthMgrData_1000B_15_output
{
   unsigned char x[0x1C];
   unsigned char y[0x1C];
};

int service_handler_0x1000B_command_15_80B72A(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_15_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_15_input*)ctx->data;

   unsigned char multiplier[0x1C];

   memcpy(multiplier, input_data->multiplier, 0x1C);

   unsigned char x[0x1C];
   unsigned char y[0x1C];
   unsigned char* curve_point[2] = {x, y};

   memcpy(x, input_data->x, 0x1C);
   memcpy(y, input_data->y, 0x1C);

   unsigned char output_x[0x1C];
   unsigned char output_y[0x1C];
   unsigned char* output_curve_point[2] = {output_x, output_y};

   multiply_ECC_224_curve_point_80EE00(output_curve_point, multiplier, curve_point, ECC_224_curve_812510);

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

int GcAuthMgrService::service_0x1000B_16(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_16_80C7DA();

   return -1;
}

int GcAuthMgrService::service_0x1000B_17(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_17_80C6FC();

   return -1;
}

int GcAuthMgrService::service_0x1000B_18(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_18_80B7DA();

   return -1;
}

int GcAuthMgrService::service_0x1000B_19(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_19_80D2E4();

   return -1;
}

struct SceSblSmCommGcAuthMgrData_1000B_1B_input
{
   unsigned char packet6_chunk[0x20];
   unsigned char packet7_chunk[0x10];
   unsigned char packet8_chunk[0x23];
};

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

struct SceSblSmCommGcAuthMgrData_1000B_1C_input
{
   unsigned char packet6_chunk[0x20];
   unsigned char packet8_chunk[0x20]; 
};

struct SceSblSmCommGcAuthMgrData_1000B_1C_output
{
   unsigned char command;
   unsigned char unknown;
   unsigned char size;
   unsigned char data[0x30];
};

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

struct SceSblSmCommGcAuthMgrData_1000B_1D_input
{
  unsigned char packet6_chunk[0x20];
  unsigned char packet9_chunk[0x30];
  unsigned char packet13_chunk[0x10];
  unsigned char packet14_chunk[0x43];
};

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

struct SceSblSmCommGcAuthMgrData_1000B_1E_input
{
   unsigned char packet6_chunk[0x20];
   unsigned char packet9_chunk[0x30];
   unsigned char parameter; // value 2 or 3
};

struct SceSblSmCommGcAuthMgrData_1000B_1E_output
{
   unsigned char command;
   unsigned char unknown;
   unsigned char size;
   unsigned char data[0x30];
};

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

struct SceSblSmCommGcAuthMgrData_1000B_1F_input
{
   unsigned char packet6_chunk[0x20];
   unsigned char packet9_chunk[0x30];
   unsigned char packet15_chunk[0x20];
   unsigned char packet16_chunk[0x43];
};

struct SceSblSmCommGcAuthMgrData_1000B_1F_output
{
   unsigned char unknown[0x20];
};

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

struct SceSblSmCommGcAuthMgrData_1000B_20_input
{
   unsigned char packet6_chunk[0x20];
   unsigned char packet9_chunk[0x30];
   unsigned char packet17_chunk[0x20];
   unsigned char packet18_chunk[0x43];
   unsigned char packet19_chunk[0x10];
   unsigned char packet20_chunk[0x53];
};

struct SceSblSmCommGcAuthMgrData_1000B_20_output
{
   unsigned char klicensee_keys[0x20];
   unsigned char rif_digest[0x14];
};

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

int GcAuthMgrService::service_0x1000B_21(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_21_80C36A();

   return -1;
}

struct SceSblSmCommGcAuthMgrData_1000B_22_input
{
   unsigned char field0[0x20];
   unsigned char salt[0x1C];
};

struct SceSblSmCommGcAuthMgrData_1000B_22_output
{
   unsigned char r[0x1C];
   unsigned char s[0x1C];
};

int service_handler_0x1000B_command_22_80C256(SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_22_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_22_input*)ctx->data;

   // get static salt

   unsigned char* static_salt = 0;

   if(ctx->key_id == 0)
   {
      static_salt = salt_00812528;
   }
   else if(ctx->key_id == 1)
   {
      static_salt = salt_00812544;
   }
   else
   {
      return 0x12;
   }

   unsigned char sig[0x38] = {0};
   unsigned char* sig_ptrs[2] = {sig, sig + 0x1C};

   // get input salt

   unsigned char input_salt_94[0x1C];

   memcpy(input_salt_94, input_data->salt, 0x1C);

   // calculate contract

   unsigned char iv_B4[0x20];

   int r0_0 = bigmac_hmac_sha256_contract_80C0F6(static_salt, input_salt_94, 0x1C, iv_B4);
   if(r0_0 != 0)
      return 5;

   // set order N ? calculate nonce ? calculate partials ?

   unsigned char digest_F4[0x40] = {0};
   unsigned char nonce_n_product_40[0x1C] = {0}; // size is unknown, probably 0x1C

   while(true)
   {
      int r0_1 = bigmac_sha256_block_update_80C17A(input_salt_94, 0x1C, iv_B4, digest_F4);
      if(r0_1 != 0)
         return 5;

      int r0_2 = bigmac_sha256_block_update_80C17A(input_salt_94, 0x1C, iv_B4, digest_F4 + 0x20);
      if(r0_2 != 0)
         return 5;

      int r0_3 = cmd_14_17_22_ecc_224_related_with_mode_maybe_modulus_F00D_80FF50(nonce_n_product_40, digest_F4, N_ptr_224_81251C);
      if(r0_3 != 0)
         break;
   }

   //check input

   for(int i = 0; i < 0x20; i++)
   {
      if(input_data->field0[i] != 0)
         return 5;
   }

   // calculate signature

   unsigned char static_salt_813680[0x1C] = {0};
   memcpy(static_salt_813680, static_salt, 0x1C);
      
   int r0_4 = F00D_math_ecc_224_related_80F4CE(sig_ptrs, input_salt_94, nonce_n_product_40, static_salt_813680, ECC_224_curve_812510);
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

   return -0;
}

int GcAuthMgrService::service_0x1000B_23(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_23_80C04A();

   return -1;
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
