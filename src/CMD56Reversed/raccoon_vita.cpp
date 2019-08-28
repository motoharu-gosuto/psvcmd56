#include "raccoon_vita.h"

#include "raccoon_bigmac.h"

#include <string>

// in this function we obtain decryption partials
// we are trying to abuse bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs
// and figure out what value is decrypted into KEYSLOT_0x0
// it is important that we can not recover value of KEYSLOT_0x204
// both KEYSLOT_0x0 and KEYSLOT_0x204 are not readable and writable from F00D

int raccoon_obtain_decryption_partials(unsigned char* encrypted_key, int src_keyslot, int dst_keyslot, unsigned char* dec_partial0, unsigned char* dec_partial1, unsigned char* dec_partial2, unsigned char* dec_partial3)
{
   // choose keys

   unsigned char key_0x519[0x20] = {0};

   // assume that master keys are initialized with some values
   bigmac_initialize();

   // set 0x519 keyslot which is both readable and writable directly from F00D
   bigmac_set_key_to_keyslot(key_0x519, KEYSLOT_0x519);

   // ---------- obtain decryption partial for 0xC - 0xF ----------

   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(encrypted_key, src_keyslot, dst_keyslot, 0x10);

   unsigned char input0[0xC] = {0}; // zero plain text
   unsigned char output0[0xC] = {0};
   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(output0, input0, KEYSLOT_0x519, 0xC);

   // ---------- obtain decryption partial for 0x8 - 0xB ----------

   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(encrypted_key, src_keyslot, dst_keyslot, 0x10);

   unsigned char input1[0x8] = {0}; // zero plain text
   unsigned char output1[0x8] = {0};
   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(output1, input1, KEYSLOT_0x519, 0x8);

   // ---------- obtain decryption partial for 0x4 - 0x7 ----------

   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(encrypted_key, src_keyslot, dst_keyslot, 0x10);

   unsigned char input2[0x4] = {0}; // zero plain text
   unsigned char output2[0x4] = {0};
   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(output2, input2, KEYSLOT_0x519, 0x4);

   // ---------- obtain decryption partial for 0x0 - 0x3 ----------

   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(encrypted_key, src_keyslot, dst_keyslot, 0x10);

   unsigned char input3[0x10] = {0};  // zero plain text
   unsigned char output3[0x10] = {0};

   bigmac_decrypt_aes_ecb_0x128_internal_implementation_with_bugs(output3, input3, dst_keyslot, 0x10);

   // copy results

   memcpy(dec_partial0, output0, 0xC);
   memcpy(dec_partial1, output1, 0x8);
   memcpy(dec_partial2, output2, 0x4);
   memcpy(dec_partial3, output3, 0x10);

   return 0;
}