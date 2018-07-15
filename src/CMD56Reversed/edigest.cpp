#include "edigest.h"

#include <stdlib.h>

#pragma pack(push,1)

#pragma pack(pop)

#define __ROL__(x, y) _rotl(x, y)
#define __ROR__(x, y) _rotr(x, y)

#define __ROL4__ __ROL__
#define __ROR4__ __ROR__

void crypto_or_hash_primitive_40D468(const int *input, int *digest2_result)
{
   unsigned int input_counter;
   int dgr_val0;
   unsigned int op_ctr0;
   unsigned int res_item_ctr;
   int cycle_acc[4];
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
      cycle_acc[0] = work_buffer[res_item_ctr]
                  + dword_4054F4[res_item_ctr]
                  + (digest_permu[10] ^ digest_permu[12] & (digest_permu[10] ^ digest_permu[11]))
                  + digest_permu[9]
                  + (__ROL4__(digest_permu[12], 7) ^ __ROL4__(digest_permu[12], 21) ^ __ROL4__(digest_permu[12], 26));

      digest_permu[13] += cycle_acc[0];

      digest_permu[9] = (dgr_val0 & digest_permu[15] | digest_permu[14] & (dgr_val0 | digest_permu[15]))
                     + (__ROL4__(dgr_val0, 10) ^ __ROL4__(dgr_val0, 19) ^ __ROL4__(dgr_val0, 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 1]
                  + dword_4054F8[res_item_ctr]
                  + (digest_permu[11] ^ digest_permu[13] & (digest_permu[11] ^ digest_permu[12]))
                  + digest_permu[10]
                  + (__ROL4__(digest_permu[13], 7) ^ __ROL4__(digest_permu[13], 21) ^ __ROL4__(digest_permu[13], 26));

      digest_permu[14] += cycle_acc[0];

      digest_permu[10] = (dgr_val0 & digest_permu[9] | digest_permu[15] & (dgr_val0 | digest_permu[9]))
                     + (__ROL4__(digest_permu[9], 10) ^ __ROL4__(digest_permu[9], 19) ^ __ROL4__(digest_permu[9], 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 2]
                  + dword_4054FC[res_item_ctr]
                  + (digest_permu[12] ^ digest_permu[14] & (digest_permu[12] ^ digest_permu[13]))
                  + digest_permu[11]
                  + (__ROL4__(digest_permu[14], 7) ^ __ROL4__(digest_permu[14], 21) ^ __ROL4__(digest_permu[14], 26));

      digest_permu[15] += cycle_acc[0];

      digest_permu[11] = (digest_permu[9] & digest_permu[10] | dgr_val0 & (digest_permu[9] | digest_permu[10]))
                     + (__ROL4__(digest_permu[10], 10) ^ __ROL4__(digest_permu[10], 19) ^ __ROL4__(digest_permu[10], 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 3]
                  + dword_405500[res_item_ctr]
                  + (digest_permu[13] ^ digest_permu[15] & (digest_permu[13] ^ digest_permu[14]))
                  + digest_permu[12]
                  + (__ROL4__(digest_permu[15], 7) ^ __ROL4__(digest_permu[15], 21) ^ __ROL4__(digest_permu[15], 26));

      cycle_acc[3] = cycle_acc[0] + dgr_val0;
      digest_permu[12] = (digest_permu[10] & digest_permu[11] | digest_permu[9] & (digest_permu[10] | digest_permu[11]))
                     + (__ROL4__(digest_permu[11], 10) ^ __ROL4__(digest_permu[11], 19) ^ __ROL4__(digest_permu[11], 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 4]
                  + dword_405504[res_item_ctr]
                  + (digest_permu[14] ^ cycle_acc[3] & (digest_permu[14] ^ digest_permu[15]))
                  + digest_permu[13]
                  + (__ROL4__(cycle_acc[3], 7) ^ __ROL4__(cycle_acc[3], 21) ^ __ROL4__(cycle_acc[3], 26));

      digest_permu[9] += cycle_acc[0];

      digest_permu[13] = (digest_permu[11] & digest_permu[12] | digest_permu[10] & (digest_permu[11] | digest_permu[12]))
                     + (__ROL4__(digest_permu[12], 10) ^ __ROL4__(digest_permu[12], 19) ^ __ROL4__(digest_permu[12], 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 5]
                  + dword_405508[res_item_ctr]
                  + (digest_permu[15] ^ digest_permu[9] & (cycle_acc[3] ^ digest_permu[15]))
                  + digest_permu[14]
                  + (__ROL4__(digest_permu[9], 7) ^ __ROL4__(digest_permu[9], 21) ^ __ROL4__(digest_permu[9], 26));

      digest_permu[10] += cycle_acc[0];

      digest_permu[14] = (digest_permu[12] & digest_permu[13] | digest_permu[11] & (digest_permu[12] | digest_permu[13]))
                     + (__ROL4__(digest_permu[13], 10) ^ __ROL4__(digest_permu[13], 19) ^ __ROL4__(digest_permu[13], 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 6]
                  + dword_40550C[res_item_ctr]
                  + (cycle_acc[3] ^ digest_permu[10] & (cycle_acc[3] ^ digest_permu[9]))
                  + digest_permu[15]
                  + (__ROL4__(digest_permu[10], 7) ^ __ROL4__(digest_permu[10], 21) ^ __ROL4__(digest_permu[10], 26));

      digest_permu[11] += cycle_acc[0];

      digest_permu[15] = (digest_permu[13] & digest_permu[14] | digest_permu[12] & (digest_permu[13] | digest_permu[14]))
                     + (__ROL4__(digest_permu[14], 10) ^ __ROL4__(digest_permu[14], 19) ^ __ROL4__(digest_permu[14], 30))
                     + cycle_acc[0];

      cycle_acc[0] = work_buffer[res_item_ctr + 7]
                  + dword_405510[res_item_ctr]
                  + (digest_permu[9] ^ digest_permu[11] & (digest_permu[9] ^ digest_permu[10]))
                  + (__ROL4__(digest_permu[11], 7) ^ __ROL4__(digest_permu[11], 21) ^ __ROL4__(digest_permu[11], 26))
                  + cycle_acc[3];

      res_item_ctr += 8;

      digest_permu[12] += cycle_acc[0];

      dgr_val0 = (digest_permu[14] & digest_permu[15] | digest_permu[13] & (digest_permu[14] | digest_permu[15]))
               + (__ROL4__(digest_permu[15], 10) ^ __ROL4__(digest_permu[15], 19) ^ __ROL4__(digest_permu[15], 30))
               + cycle_acc[0];
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