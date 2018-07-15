#include "edigest.h"

#include <stdlib.h>

#pragma pack(push,1)

#pragma pack(pop)

#define __ROL__(x, y) _rotl(x, y)
#define __ROR__(x, y) _rotr(x, y)

#define __ROL4__ __ROL__
#define __ROR4__ __ROR__

const int dword_4054F4[64] = 
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

//------

void block_function(unsigned int val0, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val30, unsigned int val31, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7, unsigned int* res0, unsigned int* res1)
{
   unsigned int term0 = val30;
   unsigned int term1 = val31;
   unsigned int term2 = val0;
   unsigned int term3 = val1 ^ (val3 & (val1 ^ val2));
   unsigned int term4 = __ROL4__(val3, 7) ^ __ROL4__(val3, 21) ^ __ROL4__(val3, 26);

   unsigned int acc0 = term0 + term1 + term2 + term3 + term4;

   unsigned int term5 = (val4 & val6) | (val5 & (val4 | val6));
   unsigned int term6 = __ROL4__(val4, 10) ^ __ROL4__(val4, 19) ^ __ROL4__(val4, 30);
   unsigned int term7 = acc0;

   unsigned int acc1 = term5 + term6 + term7;

   *res0 = val7 + acc0;
   *res1 = acc1;
}

//change digest_permu[9]
//change digest_permu[13]
void do_block0(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr)
{
   block_function(digest_permu[9], 
                  digest_permu[10], 
                  digest_permu[11], 
                  digest_permu[12], 
                  work_buffer[res_item_ctr], 
                  dword_4054F4[res_item_ctr], 
                  digest_permu[0], 
                  digest_permu[14], 
                  digest_permu[15],
                  digest_permu[13],
                  &digest_permu[13], 
                  &digest_permu[9]);
}

//change digest_permu[10]
//change digest_permu[14]
void do_block1(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr)
{
   block_function(digest_permu[10], 
                  digest_permu[11], 
                  digest_permu[12], 
                  digest_permu[13], 
                  work_buffer[res_item_ctr + 1], 
                  dword_4054F4[res_item_ctr + 1],
                  digest_permu[9], 
                  digest_permu[15], 
                  digest_permu[0], 
                  digest_permu[14],
                  &digest_permu[14], 
                  &digest_permu[10]);
}

//change digest_permu[11]
//change digest_permu[15]
void do_block2(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr)
{
   block_function(digest_permu[11], 
                  digest_permu[12], 
                  digest_permu[13], 
                  digest_permu[14], 
                  work_buffer[res_item_ctr + 2], 
                  dword_4054F4[res_item_ctr + 2],
                  digest_permu[10], 
                  digest_permu[0], 
                  digest_permu[9], 
                  digest_permu[15],
                  &digest_permu[15], 
                  &digest_permu[11]);
}

//change digest_permu[12]
//calculate carry
void do_block3(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr, unsigned int& carry)
{
   int val30 = work_buffer[res_item_ctr + 3];
   int val31 = dword_4054F4[res_item_ctr + 3];

   int val0 = digest_permu[12];
   int val1 = digest_permu[13];
   int val2 = digest_permu[14];
   int val3 = digest_permu[15];

   int term0 = val30;
   int term1 = val31;
   int term2 = val0;
   int term3 = val1 ^ (val3 & (val1 ^ val2)); 
   int term4 = __ROL4__(val3, 7) ^ __ROL4__(val3, 21) ^ __ROL4__(val3, 26); 

   int acc0 = term0+ term1 + term2 + term3 + term4;

   int val4 = digest_permu[11];
   int val5 = digest_permu[9];
   int val6 = digest_permu[10];
   int val7 = digest_permu[0];

   int term5 = (val4 & val6) | (val5 & (val4 | val6));
   int term6 = __ROL4__(val4, 10) ^ __ROL4__(val4, 19) ^ __ROL4__(val4, 30);
   int term7 = acc0;

   int acc1 = term5 + term6 + term7;

   digest_permu[12] = acc1;

   carry = val7 + acc0;
}

//change digest_permu[9]
//change digest_permu[13]
void do_block4(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr, const unsigned int carry)
{
   int v11;

   v11 = work_buffer[res_item_ctr + 4]
            + dword_4054F4[res_item_ctr + 4]
            + (digest_permu[14] ^ carry & (digest_permu[14] ^ digest_permu[15]))
            + digest_permu[13]
            + (__ROL4__(carry, 7) ^ __ROL4__(carry, 21) ^ __ROL4__(carry, 26));

   digest_permu[9] += v11;

   digest_permu[13] = (digest_permu[11] & digest_permu[12] | digest_permu[10] & (digest_permu[11] | digest_permu[12]))
                  + (__ROL4__(digest_permu[12], 10) ^ __ROL4__(digest_permu[12], 19) ^ __ROL4__(digest_permu[12], 30))
                  + v11;
}

//change digest_permu[10]
//change digest_permu[14]
void do_block5(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr, const unsigned int carry)
{
   int v12;

   v12 = work_buffer[res_item_ctr + 5]
            + dword_4054F4[res_item_ctr + 5]
            + (digest_permu[15] ^ digest_permu[9] & (carry ^ digest_permu[15]))
            + digest_permu[14]
            + (__ROL4__(digest_permu[9], 7) ^ __ROL4__(digest_permu[9], 21) ^ __ROL4__(digest_permu[9], 26));

   digest_permu[10] += v12;

   digest_permu[14] = (digest_permu[12] & digest_permu[13] | digest_permu[11] & (digest_permu[12] | digest_permu[13]))
                  + (__ROL4__(digest_permu[13], 10) ^ __ROL4__(digest_permu[13], 19) ^ __ROL4__(digest_permu[13], 30))
                  + v12;
}

//change digest_permu[11]
//change digest_permu[15]
void do_block6(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr, const unsigned int carry)
{
   int v13;

   v13 = work_buffer[res_item_ctr + 6]
            + dword_4054F4[res_item_ctr + 6]
            + (carry ^ digest_permu[10] & (carry ^ digest_permu[9]))
            + digest_permu[15]
            + (__ROL4__(digest_permu[10], 7) ^ __ROL4__(digest_permu[10], 21) ^ __ROL4__(digest_permu[10], 26));

   digest_permu[11] += v13;

   digest_permu[15] = (digest_permu[13] & digest_permu[14] | digest_permu[12] & (digest_permu[13] | digest_permu[14]))
                  + (__ROL4__(digest_permu[14], 10) ^ __ROL4__(digest_permu[14], 19) ^ __ROL4__(digest_permu[14], 30))
                  + v13;
}

//change digest_permu[12]
//change digest_permu[0]
void do_block7(const unsigned int* work_buffer, unsigned int* digest_permu, const unsigned int res_item_ctr, const unsigned int carry)
{
   int v14;

   v14 = work_buffer[res_item_ctr + 7]
            + dword_4054F4[res_item_ctr + 7]
            + (digest_permu[9] ^ digest_permu[11] & (digest_permu[9] ^ digest_permu[10]))
            + (__ROL4__(digest_permu[11], 7) ^ __ROL4__(digest_permu[11], 21) ^ __ROL4__(digest_permu[11], 26))
            + carry;

   digest_permu[12] += v14;

   digest_permu[0] = (digest_permu[14] & digest_permu[15] | digest_permu[13] & (digest_permu[14] | digest_permu[15]))
            + (__ROL4__(digest_permu[15], 10) ^ __ROL4__(digest_permu[15], 19) ^ __ROL4__(digest_permu[15], 30))
            + v14;
}

//------

void digest_decomposition(const unsigned int *digest2_result, unsigned int* digest_permu)
{
   digest_permu[1] =  digest2_result[7];
   digest_permu[9] =  digest2_result[7];

   digest_permu[2] =  digest2_result[6];
   digest_permu[10] = digest2_result[6];

   digest_permu[3] =  digest2_result[5];
   digest_permu[11] = digest2_result[5];

   digest_permu[4] =  digest2_result[4];
   digest_permu[12] = digest2_result[4];

   digest_permu[6] =  digest2_result[3];
   digest_permu[13] = digest2_result[3];

   digest_permu[7] =  digest2_result[2];
   digest_permu[14] = digest2_result[2];

   digest_permu[8] =  digest2_result[1];
   digest_permu[15] = digest2_result[1];

   digest_permu[5] =  digest2_result[0];
   digest_permu[0] = digest2_result[0];
}

void digest_composition(unsigned int *digest2_result, const unsigned int* digest_permu)
{
   digest2_result[0] = digest_permu[0] + digest_permu[5];
   digest2_result[1] = digest_permu[15] + digest_permu[8];
   digest2_result[2] = digest_permu[14] + digest_permu[7];
   digest2_result[3] = digest_permu[13] + digest_permu[6];
   digest2_result[4] = digest_permu[12] + digest_permu[4];
   digest2_result[5] = digest_permu[11] + digest_permu[3];
   digest2_result[6] = digest_permu[10] + digest_permu[2];
   digest2_result[7] = digest_permu[9] + digest_permu[1];
}

//------

void construct_work_buffer(const unsigned int *input, unsigned int* work_buffer)
{
   //copy input to head of the work buffer

   int in_ctr = 0;
   do
   {
      work_buffer[in_ctr] = input[in_ctr];
      in_ctr++;
   }
   while (in_ctr <= 0xF);

   //derive tail of work buffer from work buffer itself

   int wb_ctr = 0;

   do
   {
      unsigned int val0 = work_buffer[wb_ctr];
      unsigned int val1 = work_buffer[wb_ctr + 1];
      unsigned int val2 = work_buffer[wb_ctr + 9];
      unsigned int val3 = work_buffer[wb_ctr + 14];

      unsigned int term0 = val0;
      unsigned int term1 = (val1 >> 3) ^ __ROL4__(val1, 14) ^ __ROL4__(val1, 25);
      unsigned int term2 = val2;
      unsigned int term3 = (val3 >> 10) ^ __ROL4__(val3, 13) ^ __ROL4__(val3, 15);

      work_buffer[wb_ctr + 16] = term0 + term1 + term2 + term3;

      wb_ctr++;
   }
   while (wb_ctr <= 0x2F);
}

//------

void process_blocks(const unsigned int* work_buffer, unsigned int* digest_permu)
{
   int res_item_ctr = 0;

   do
   {
      unsigned int carry;

      do_block0(work_buffer, digest_permu, res_item_ctr);
      do_block1(work_buffer, digest_permu, res_item_ctr);
      do_block2(work_buffer, digest_permu, res_item_ctr);
      do_block3(work_buffer, digest_permu, res_item_ctr, carry);

      do_block4(work_buffer, digest_permu, res_item_ctr, carry);
      do_block5(work_buffer, digest_permu, res_item_ctr, carry);
      do_block6(work_buffer, digest_permu, res_item_ctr, carry);
      do_block7(work_buffer, digest_permu, res_item_ctr, carry);

      res_item_ctr += 8;
   }
   while (res_item_ctr <= 0x3F);
}

//------

//input buffer is 0x40 bytes (0x10 integers)
//digest2_result is 0x20 bytes (0x8 integers)
void crypto_or_hash_primitive_40D468(const unsigned int *input, unsigned int *digest2_result)
{
   //peform decomposition of digest2
   unsigned int digest_permu[16];
   digest_decomposition(digest2_result, digest_permu);
   
   //construct work buffer
   unsigned int work_buffer[64];
   construct_work_buffer(input, work_buffer);
   
   //main processing - this will change digest_permu
   process_blocks(work_buffer, digest_permu);

   //perform composition of digest2
   digest_composition(digest2_result, digest_permu);
}