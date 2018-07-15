#include "edigest.h"

#include <stdlib.h>

#pragma pack(push,1)

#pragma pack(pop)

#define __ROL__(x, y) _rotl(x, y)
#define __ROR__(x, y) _rotr(x, y)

#define __ROL4__ __ROL__
#define __ROR4__ __ROR__

int dword_4054F4[64] = 
{
   0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5, 
   0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
   0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA, 
   0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
   0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
   0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070, 
   0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3, 
   0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2,
};

void __cdecl crypto_or_hash_primitive_40D468(const int *input, int *digest2_result)
{
   unsigned int input_counter;
   int dgr_val0;
   unsigned int op_ctr0;
   unsigned int res_item_ctr;
   int cycle_acc;
   int v7;
   int v8;
   int v9;
   int v10;
   int v11;
   int v12;
   int v13;
   int v14;
   int res_acc0;
   int res_acc1;
   int res_acc2;
   int res_acc3;
   int res_acc4;
   int res_acc5;
   int res_acc6;
   int res_acc7;
   int res_acc8;
   int digest_permu[16];
   int work_buffer[64];

   input_counter = 0;
   dgr_val0 = *digest2_result;
   digest_permu[15] = digest2_result[1];
   digest_permu[8] = digest_permu[15];
   digest_permu[5] = dgr_val0;
   digest_permu[14] = digest2_result[2];
   digest_permu[7] = digest_permu[14];
   digest_permu[13] = digest2_result[3];
   digest_permu[6] = digest_permu[13];
   digest_permu[12] = digest2_result[4];
   digest_permu[4] = digest_permu[12];
   digest_permu[11] = digest2_result[5];
   digest_permu[3] = digest_permu[11];
   digest_permu[10] = digest2_result[6];
   digest_permu[2] = digest_permu[10];
   digest_permu[9] = digest2_result[7];
   digest_permu[1] = digest_permu[9];

   do
   {
      work_buffer[input_counter] = input[input_counter];
      ++input_counter;
   }
   while ( input_counter <= 0xF );

   op_ctr0 = 0x10;

   do
   {
      work_buffer[op_ctr0] = (((unsigned int)digest_permu[op_ctr0 + 14] >> 10) ^ __ROL4__(digest_permu[op_ctr0 + 14], 13) ^ __ROL4__(digest_permu[op_ctr0 + 14], 0xF))
                           + (((unsigned int)digest_permu[op_ctr0 + 1] >> 3) ^ __ROL4__(digest_permu[op_ctr0 + 1], 14) ^ __ROL4__(digest_permu[op_ctr0 + 1], 0x19))
                           + digest_permu[op_ctr0]
                           + digest_permu[op_ctr0 + 9];
      ++op_ctr0;
   }
   while ( op_ctr0 <= 0x3F );

   res_item_ctr = 0;

   do
   {
      cycle_acc = work_buffer[res_item_ctr]
               + dword_4054F4[res_item_ctr]
               + (digest_permu[10] ^ digest_permu[12] & (digest_permu[10] ^ digest_permu[11]))
               + digest_permu[9]
               + (__ROL4__(digest_permu[12], 7) ^ __ROL4__(digest_permu[12], 21) ^ __ROL4__(digest_permu[12], 26));

      digest_permu[13] += cycle_acc;

      digest_permu[9] = (dgr_val0 & digest_permu[15] | digest_permu[14] & (dgr_val0 | digest_permu[15]))
                     + (__ROL4__(dgr_val0, 10) ^ __ROL4__(dgr_val0, 19) ^ __ROL4__(dgr_val0, 30))
                     + cycle_acc;

      v7 = work_buffer[res_item_ctr + 1]
         + dword_4054F4[res_item_ctr + 1]
         + (digest_permu[11] ^ digest_permu[13] & (digest_permu[11] ^ digest_permu[12]))
         + digest_permu[10]
         + (__ROL4__(digest_permu[13], 7) ^ __ROL4__(digest_permu[13], 21) ^ __ROL4__(digest_permu[13], 26));

      digest_permu[14] += v7;

      digest_permu[10] = (dgr_val0 & digest_permu[9] | digest_permu[15] & (dgr_val0 | digest_permu[9]))
                     + (__ROL4__(digest_permu[9], 10) ^ __ROL4__(digest_permu[9], 19) ^ __ROL4__(digest_permu[9], 30))
                     + v7;

      v8 = work_buffer[res_item_ctr + 2]
         + dword_4054F4[res_item_ctr + 2]
         + (digest_permu[12] ^ digest_permu[14] & (digest_permu[12] ^ digest_permu[13]))
         + digest_permu[11]
         + (__ROL4__(digest_permu[14], 7) ^ __ROL4__(digest_permu[14], 21) ^ __ROL4__(digest_permu[14], 26));

      digest_permu[15] += v8;

      digest_permu[11] = (digest_permu[9] & digest_permu[10] | dgr_val0 & (digest_permu[9] | digest_permu[10]))
                     + (__ROL4__(digest_permu[10], 10) ^ __ROL4__(digest_permu[10], 19) ^ __ROL4__(digest_permu[10], 30))
                     + v8;

      v9 = work_buffer[res_item_ctr + 3]
         + dword_4054F4[res_item_ctr + 3]
         + (digest_permu[13] ^ digest_permu[15] & (digest_permu[13] ^ digest_permu[14]))
         + digest_permu[12]
         + (__ROL4__(digest_permu[15], 7) ^ __ROL4__(digest_permu[15], 21) ^ __ROL4__(digest_permu[15], 26));

      v10 = v9 + dgr_val0;

      digest_permu[12] = (digest_permu[10] & digest_permu[11] | digest_permu[9] & (digest_permu[10] | digest_permu[11]))
                     + (__ROL4__(digest_permu[11], 10) ^ __ROL4__(digest_permu[11], 19) ^ __ROL4__(digest_permu[11], 30))
                     + v9;

      v11 = work_buffer[res_item_ctr + 4]
         + dword_4054F4[res_item_ctr + 4]
         + (digest_permu[14] ^ v10 & (digest_permu[14] ^ digest_permu[15]))
         + digest_permu[13]
         + (__ROL4__(v10, 7) ^ __ROL4__(v10, 21) ^ __ROL4__(v10, 26));
      digest_permu[9] += v11;

      digest_permu[13] = (digest_permu[11] & digest_permu[12] | digest_permu[10] & (digest_permu[11] | digest_permu[12]))
                     + (__ROL4__(digest_permu[12], 10) ^ __ROL4__(digest_permu[12], 19) ^ __ROL4__(digest_permu[12], 30))
                     + v11;

      v12 = work_buffer[res_item_ctr + 5]
         + dword_4054F4[res_item_ctr + 5]
         + (digest_permu[15] ^ digest_permu[9] & (v10 ^ digest_permu[15]))
         + digest_permu[14]
         + (__ROL4__(digest_permu[9], 7) ^ __ROL4__(digest_permu[9], 21) ^ __ROL4__(digest_permu[9], 26));
      digest_permu[10] += v12;

      digest_permu[14] = (digest_permu[12] & digest_permu[13] | digest_permu[11] & (digest_permu[12] | digest_permu[13]))
                     + (__ROL4__(digest_permu[13], 10) ^ __ROL4__(digest_permu[13], 19) ^ __ROL4__(digest_permu[13], 30))
                     + v12;

      v13 = work_buffer[res_item_ctr + 6]
         + dword_4054F4[res_item_ctr + 6]
         + (v10 ^ digest_permu[10] & (v10 ^ digest_permu[9]))
         + digest_permu[15]
         + (__ROL4__(digest_permu[10], 7) ^ __ROL4__(digest_permu[10], 21) ^ __ROL4__(digest_permu[10], 26));
      digest_permu[11] += v13;

      digest_permu[15] = (digest_permu[13] & digest_permu[14] | digest_permu[12] & (digest_permu[13] | digest_permu[14]))
                     + (__ROL4__(digest_permu[14], 10) ^ __ROL4__(digest_permu[14], 19) ^ __ROL4__(digest_permu[14], 30))
                     + v13;

      v14 = work_buffer[res_item_ctr + 7]
         + dword_4054F4[res_item_ctr + 7]
         + (digest_permu[9] ^ digest_permu[11] & (digest_permu[9] ^ digest_permu[10]))
         + (__ROL4__(digest_permu[11], 7) ^ __ROL4__(digest_permu[11], 21) ^ __ROL4__(digest_permu[11], 26))
         + v10;

      res_item_ctr += 8;

      digest_permu[12] += v14;

      dgr_val0 = (digest_permu[14] & digest_permu[15] | digest_permu[13] & (digest_permu[14] | digest_permu[15]))
               + (__ROL4__(digest_permu[15], 10) ^ __ROL4__(digest_permu[15], 19) ^ __ROL4__(digest_permu[15], 30))
               + v14;
   }
   while ( res_item_ctr <= 0x3F );

   res_acc0 = digest_permu[15];
   *digest2_result = dgr_val0 + digest_permu[5];
   res_acc1 = digest_permu[14];
   res_acc2 = digest_permu[13];
   res_acc3 = digest_permu[12];
   digest2_result[1] = res_acc0 + digest_permu[8];
   res_acc4 = digest_permu[11];
   res_acc5 = res_acc1 + digest_permu[7];
   res_acc6 = digest_permu[10];
   digest2_result[2] = res_acc5;
   res_acc7 = res_acc2 + digest_permu[6];
   res_acc8 = digest_permu[9];
   digest2_result[3] = res_acc7;
   digest2_result[4] = res_acc3 + digest_permu[4];
   digest2_result[5] = res_acc4 + digest_permu[3];
   digest2_result[6] = res_acc6 + digest_permu[2];
   digest2_result[7] = res_acc8 + digest_permu[1];
}