#include "SceMsifHashTableVerify.h"

#include <algorithm>
#include <cstdint>

bool memory_is_all_zeroes(unsigned char const* const begin, std::size_t const bytes)
{
   return std::all_of( begin, begin + bytes, [](unsigned char const byte) { return byte == 0; } );
}

void reverse_byte_order(unsigned char* dst, const unsigned char* src, int size)
{
   memcpy(dst, src, size);
   std::reverse(dst, dst + size);
}

//[REVERSED] - [TESTED]
//returns 0 if sequences are equal
//returns 0 if first unmatching block in first sequence is less than first unmatching block in second sequence
//returns 1 if first unmatching block in first sequence is greater than first unmatching block in second sequence
int block_memcmp_C8EADC(const unsigned char* buffer0, const unsigned char* buffer1, int nBlocks)
{
   if (nBlocks <= 0)
      return 0;

   int res0 = memcmp(buffer0, buffer1, nBlocks * 4);
   return res0 <= 0 ? 0 : 1;
}

//[REVERSED] - [TESTED]
void reverse_byte_order_C8E3AA(unsigned char* dst, const unsigned char* src, int byte_size)
{
   reverse_byte_order(dst, src, byte_size);
}

//[REVERSED] - [TESTED] (but not with automatic tests)
void block_shift_left_with_overflow_C8EB0A(unsigned char* dst, unsigned char* src, int block_size, int bits)
{
   int bits_aligned = bits & 0x3F;
   if (bits_aligned)
   {
      unsigned long long acc = 0;

      for(int i = 0; i < block_size; i++)
      {
         unsigned long long val = *(((unsigned int*)src) + i);
         unsigned long long shft = val << bits_aligned;
         *(((unsigned int*)dst) + i) = shft | acc;

         unsigned int overflow_bits = 0x20 - bits_aligned;
         acc = val >> overflow_bits;
      }
   }
   else
   {
      memcpy(dst, src, block_size * 4);
   }
}

//[REVERSED] - [TESTED] (but not with automatic tests)
void block_shift_right_with_overflow_C8E328(unsigned char* dst, unsigned char* src, int block_size, int bits)
{
   int bits_aligned = bits & 0x3F;
   if (bits_aligned)
   {
      int block_counter = block_size - 1;
      int block_index0 = 0;
      
      unsigned char *src_block_ptr = &src[4 * block_size];
      unsigned char *dst_block_ptr = &dst[4 * block_size];

      unsigned long long accumulator = 0;
      
      while (1)
      {
         block_index0 -= 4;
         
         if (block_counter < 0)
            break;

         unsigned long long cur_block0 = *(unsigned int *)&src_block_ptr[block_index0];

         --block_counter;

         unsigned long long shift_val = (cur_block0 >> bits_aligned);

         *(unsigned int *)&dst_block_ptr[block_index0] = accumulator | shift_val;

         accumulator = cur_block0 << (0x20 - bits_aligned);
      }
   }
   else
   {
      memcpy(dst, src, block_size * 4);
   }
}

//[REVERSED] - [TESTED] (but not with automatic tests)
//dst buffer should be 4 bytes longer then src buffer (higher bit multiplication reminder is stored there)
void arbitrary_length_multiply_by_int_C8E01C(unsigned char *dst, unsigned char *src, int block_size, int multiplier)
{
   if (block_size <= 0)
      return;

   int byte_counter = 0;
   int byte_size = 4 * block_size;

   unsigned int acc0 = 0;

   do
   {
      unsigned int cur_block = *(unsigned int *)&src[byte_counter];

      unsigned short cb_lo16 = (unsigned short)(cur_block);
      unsigned short cb_hi16 = (unsigned short)(cur_block >> 0x10);

      unsigned short ag_lo16 = (unsigned short)(multiplier);
      unsigned short ag_hi16 = (unsigned short)(multiplier >> 0x10);

      unsigned int mul0_lo = ag_lo16 * cb_lo16;
      unsigned int mul0_hi = ag_lo16 * cb_hi16;

      unsigned int mul1_lo = ag_hi16 * cb_lo16;
      unsigned int mul1_hi = ag_hi16 * cb_hi16;

      unsigned short mul0_lo16 = (mul0_lo >> 0x10);
      
      unsigned int sum0 = mul0_hi + mul0_lo16;
      unsigned int sum1 = mul0_hi + mul1_lo;

      unsigned int val3 = mul0_lo + (sum1 << 0x10);

      *(unsigned int *)&dst[byte_counter] = val3 + acc0;

      unsigned short sum0_lo16 = (unsigned short)(sum0);
      unsigned short sum0_hi16 = (unsigned short)(sum0 >> 0x10);

      unsigned int sum2 = mul1_lo + sum0_lo16;
      unsigned short sum2_lo16 = (unsigned short)(sum2 >> 0x10);
      
      unsigned int ct0 =  (val3 | acc0);
      unsigned int ct1 = ~(val3 + acc0);
      
      unsigned int carry = (ct0 & ct1) | (val3 & acc0);

      unsigned int carry_bit = (carry >> 0x1F);

      acc0 = mul1_hi + sum0_hi16 + sum2_lo16 + carry_bit;

      byte_counter += 4;
   }
   while (byte_counter != byte_size);

   *(unsigned int *)&dst[byte_counter] = acc0;
}

//[REVERSED] - [TESTED] (but not with automatic tests)
int arbitrary_length_substract_C8E36E(unsigned char *dst, unsigned char *left, unsigned char *right, int block_size, int carry_input)
{
   unsigned int carry_bit = carry_input & 1;

   int byte_counter = 0;
   int block_counter = 0;

   while (block_counter < block_size)
   {
      unsigned int cb_left = *(unsigned int *)&left[byte_counter];
      unsigned int cb_right = *(unsigned int *)&right[byte_counter];
      
      unsigned int block_res = cb_left - cb_right - carry_bit;

      *(unsigned int *)&dst[byte_counter] = block_res;

      unsigned int ct0 = (~cb_left | cb_right);
      unsigned int ct1 = (ct0 & block_res);
      unsigned int ct2 = (~cb_left & cb_right);

      unsigned int carry = (ct1 | ct2);

      carry_bit = carry >> 0x1F;
      
      byte_counter += 4;
      ++block_counter;
   }

   return carry_bit;
}

//[REVERSED] - [TESTED] (but not with automatic tests)
int arbitrary_length_add_C8EB4A(unsigned char *dst, unsigned char *left, unsigned char *right, int block_size, int carry_input)
{
   unsigned int carry_bit = carry_input & 1;

   int byte_counter = 0;
   int block_counter = 0;

   while (block_counter < block_size)
   {
      unsigned int cb_left = *(unsigned int*)&left[byte_counter];
      unsigned int cb_right = *(unsigned int*)&right[byte_counter];

      unsigned int block_res = cb_left + cb_right + carry_bit;

      *(unsigned int*)&dst[byte_counter] = block_res;

      unsigned int ct0 = (cb_right | cb_left);
      unsigned int ct1 = (ct0 & ~block_res);
      unsigned int ct2 = (cb_left & cb_right);

      unsigned int carry = ct1 | ct2;

      carry_bit = carry >> 0x1F;

      ++block_counter;
      byte_counter += 4;
   }

   return carry_bit;
}

//[REVERSED] - [TESTED] (but not with automatic tests)
void arbitrary_length_multiply_C8DF74(unsigned char *dst, unsigned char *src0, int block_size0, unsigned char *src1, int block_size1)
{
   unsigned char buffer0[260];
   unsigned char accumulator[512];
   
   bool cond0 = (unsigned int)(block_size0 - 1) <= 0x3F;
   bool cond1 = (unsigned int)(block_size1 - 1) <= 0x3F;

   if (!(cond0 && cond1))
      return;

   int block_size0_local = block_size0 + 1;

   //memset 0 accumulator

   memset(accumulator, 0, 4 * (block_size0 + block_size1));

   //multiply and add into accumulator

   int block_counter2 = 0;

   do
   {
      unsigned char * accumulator_block = (unsigned char *)&accumulator[4 * block_counter2];
      int multiplier = *(unsigned int *)&src1[4 * block_counter2];

      arbitrary_length_multiply_by_int_C8E01C(buffer0, src0, block_size0, multiplier); //multiply part of src1 with whole src0
      arbitrary_length_add_C8EB4A(accumulator_block, accumulator_block, buffer0, block_size0_local, 0); //add that into accumulator

      ++block_counter2;
   }
   while (block_counter2 != block_size1);

   //copy result

   memcpy(dst, accumulator, 4 * (block_size0 + block_size1));
}

//=================

unsigned int subroutine0_C8E084(const unsigned char *sha224_1_local, int block_size_arg0)
{
   int block_counter3; // r1
   int block_size1_aligned; // r0
   unsigned int byte_size1; // r6

   unsigned int val3; // r5
   unsigned int val4; // r4
   int val5; // r0
   unsigned int val6; // r4
   unsigned int val7; // r5
   int val8; // r4
   int val9; // r0
   unsigned int val10; // r5
   int val11; // r4
   int val12; // r0
   unsigned int val13; // r5

   block_counter3 = 0;
   block_size1_aligned = 0x20;
   byte_size1 = 0;

   do
   {

      ++block_counter3;
      if ( block_size1_aligned != 0x20 )
         break;

      val3 = *(unsigned int *)&sha224_1_local[4 * block_size_arg0 + -4 * block_counter3];
      val4 = (-(val3 >> 0x10) >> 0x10) & 0x10;
      val5 = 0x10 - val4;
      val6 = val3 >> val4;
      val7 = ((val6 - 0x100) >> 0x10) & 8;
      val8 = val6 << val7;
      val9 = val5 + val7;
      val10 = ((unsigned int)(val8 - 0x1000) >> 0x10) & 4;
      val11 = val8 << val10;
      val12 = val9 + val10;
      val13 = ((unsigned int)(val11 - 0x4000) >> 0x10) & 2;
      block_size1_aligned = val12 + val13 + 2 - (((unsigned int)(val11 << val13) >> 0xE) & ~((unsigned int)(val11 << val13) >> 0xF));
      byte_size1 += block_size1_aligned;
   }
   while ( block_counter3 != block_size_arg0 );

   return byte_size1;
}

unsigned int subroutine1_C8E084(const unsigned char *src1, int block_size_arg1)
{
   int block_counter0; // r1
   int v22; // r0
   unsigned int byte_size0; // r9
   unsigned int val14; // r5
   unsigned int val15; // r4
   int val16; // r0
   unsigned int val17; // r4
   unsigned int val18; // r5
   int val19; // r4
   int val20; // r0
   unsigned int val21; // r5
   int val22; // r4
   int val23; // r0
   unsigned int val24; // r5

   block_counter0 = 0;
   v22 = 0x20;
   byte_size0 = 0;

   do
   {
      ++block_counter0;
      if ( v22 != 0x20 )
         break;

      val14 = *(unsigned int *)&src1[4 * block_size_arg1 + -4 * block_counter0];
      val15 = (-(val14 >> 0x10) >> 0x10) & 0x10;
      val16 = 0x10 - val15;
      val17 = val14 >> val15;
      val18 = ((val17 - 0x100) >> 0x10) & 8;
      val19 = val17 << val18;
      val20 = val16 + val18;
      val21 = ((unsigned int)(val19 - 0x1000) >> 0x10) & 4;
      val22 = val19 << val21;
      val23 = val20 + val21;
      val24 = ((unsigned int)(val22 - 0x4000) >> 0x10) & 2;
      v22 = val23 + val24 + 2 - (((unsigned int)(val22 << val24) >> 14) & ~((unsigned int)(val22 << val24) >> 15));
      byte_size0 += v22;
   }
   while ( block_counter0 != block_size_arg1 );

   return byte_size0;
}

void do_smth_with_hashes_2_C8E084(unsigned char *dst, unsigned char *src0, int block_size_arg0, unsigned char *src1, int block_size_arg1)
{
   int block_size0; // r5
   int block_size1; // r4
   unsigned __int8 *sha224_2_copy; // ST08_4
   int v38; // r0
   int block_counter1; // r12
   int block_counter2; // r3
   int byte_size0_aligned; // r9
   unsigned int val1; // r7
   unsigned __int8 *val_ptr0; // r6
   int val25; // r2
   unsigned int val0; // t1
   int val26; // r3
   signed int byte_counter0; // r1
   int val27; // r0
   int val28; // r4
   unsigned int xor0; // r10
   int block_counter4; // r3
   int block_size2; // [sp+Ch] [bp-444h]
   int block_size3; // [sp+10h] [bp-440h]
   int block_index0; // [sp+14h] [bp-43Ch]
   unsigned __int8 buffer0[260]; // [sp+18h] [bp-438h]
   unsigned __int8 buffer1[260]; // [sp+11Ch] [bp-334h]
   unsigned __int8 buffer2[516]; // [sp+220h] [bp-230h]

   unsigned __int8 * sha224_1_local = src0;
   unsigned __int8 * sha224_0_local = dst;

   //==================

   bool cond0 = (unsigned int)(block_size_arg0 - 1) <= 0x7F;
   bool cond1 = (unsigned int)(block_size_arg1 - 1) <= 0x3F;
  
   if (!(cond0 && cond1))
      return;

   //==================
   
   unsigned int byte_size1 = subroutine0_C8E084(src0, block_size_arg0);

   unsigned int byte_size0 = subroutine1_C8E084(src1, block_size_arg1);

   //==================

   block_size0 = block_size_arg1 - (byte_size0 >> 5);// /0x20

   if ( block_size_arg1 != byte_size0 >> 5 )   // /0x20
   {
      block_size1 = block_size_arg0 - (byte_size1 >> 5);// /0x20
      block_size2 = block_size_arg0 - (byte_size1 >> 5);// /0x20

      if ( block_size1 == block_size0 )
      {
         sha224_2_copy = src1;
         v38 = block_memcmp_C8EADC(src1, sha224_1_local, block_size_arg0 - (byte_size1 >> 5));// /0x20
         src1 = sha224_2_copy;
      }
      else
      {
         v38 = block_size1 < block_size0;
      }

      block_counter1 = 0;

      if ( v38 == 1 )
      {
         while ( block_counter1 < block_size1 )
         {
            *(unsigned int *)&sha224_0_local[4 * block_counter1] = *(unsigned int *)&sha224_1_local[4 * block_counter1];
            ++block_counter1;
         }

         for ( block_counter2 = 0; block_counter2 < block_size_arg1 - block_size1; ++block_counter2 )
         {
            *(unsigned int *)&sha224_0_local[4 * block_size1 + 4 * block_counter2] = 0;
         }
      }
      else
      {
         byte_size0_aligned = byte_size0 & 0x1F;
         *(unsigned int *)&buffer0[4 * block_size0] = 0;
         block_shift_left_with_overflow_C8EB0A(buffer0, src1, block_size0, byte_size0_aligned);

         if ( (unsigned __int8)(byte_size1 & 0x1F) < byte_size0_aligned )
         {
            *(unsigned int *)&buffer2[4 * block_size1] = *(unsigned int *)&sha224_1_local[4 * (block_size1 + 0x3FFFFFFF)] >> (32 - byte_size0_aligned);
         }
         else
         {
            *(unsigned int *)&buffer2[4 * block_size1] = 0;
         }

         block_size3 = block_size0 + 1;
         block_shift_left_with_overflow_C8EB0A(buffer2, sha224_1_local, block_size1, byte_size0_aligned);
         val1 = *(unsigned int *)&buffer0[4 * (block_size0 - 1)];
         val_ptr0 = &buffer2[4 * (block_size1 + 1)];
         block_index0 = -4 * block_size0;

         while ( block_size2 >= block_size0 )
         {
            val0 = *((unsigned int *)val_ptr0 - 1);
            val_ptr0 -= 4;
            val25 = val0;

            if ( val0 >= val1 )
            {
               val26 = -1;
            }
            else
            {
               val26 = *((unsigned int *)val_ptr0 - 1);
               byte_counter0 = 0x20;

               do
               {
                  val27 = val25 >> 0x1F;
                  val28 = (unsigned __int64)(unsigned int)val26 >> 0x1F;
                  val26 *= 2;
                  val25 = val28 | 2 * val25;

                  if ( (val27 | (unsigned int)val25) >= val1 )
                  {
                     val25 -= val1;
                     val26 |= 1u;
                  }

                  --byte_counter0;
               }
               while ( byte_counter0 );
            }

            arbitrary_length_multiply_by_int_C8E01C(buffer1, buffer0, block_size0, val26);

            for ( xor0 = arbitrary_length_substract_C8E36E(&val_ptr0[block_index0], &val_ptr0[block_index0], buffer1, block_size3, 0);
                  xor0;
                  xor0 ^= arbitrary_length_add_C8EB4A(&val_ptr0[block_index0], &val_ptr0[block_index0], buffer0, block_size3, 0) )
            {
               ;
            }

            --block_size2;
         }

         block_shift_right_with_overflow_C8E328(sha224_0_local, buffer2, block_size_arg1, byte_size0_aligned);

         for ( block_counter4 = 0; block_counter4 < block_size_arg1 - block_size0; ++block_counter4 )
         {
            *(unsigned int *)&sha224_0_local[4 * block_size0 + 4 * block_counter4] = 0;
         }
      }
   }
}

int do_smth_with_hashes_5_C8DBD4(unsigned char *sha224_0, unsigned char *sha_224_1, unsigned char *sha_224_2, int key_size_blocks)
{
   int key_size_blocks_local; // r4
   unsigned __int8 *sha_224_1_local; // r10
   unsigned __int8 *sha_224_2_local; // r6
   unsigned int block_size0; // r3
   int result; // r0
   unsigned int block_size1; // r11
   int byte_index0; // r3
   int block_val3; // r2
   int block_val1; // r1
   int block_val0; // r7
   int block_val2; // r0
   int res0; // ST08_4
   int res1; // r0
   int block_val4; // r0
   int block_val5; // r2
   int block_val6; // r1
   int byte_index1; // r3
   int byte_index2; // r2
   int block_val11; // r12
   unsigned __int8 *block_ptr6; // r0
   unsigned int block_val8; // lr
   unsigned int block_val9; // r9
   unsigned int block_val10; // r0
   int check0; // ST08_4
   int res2; // ST28_4
   int res3; // r0
   int block_val12; // lr
   int block_val13; // r2
   int block_val15; // r1
   int byte_index3; // r3
   int byte_index4; // r2
   int block_val16; // r12
   unsigned __int8 *block_ptr7; // r0
   unsigned int block_val17; // lr
   unsigned int block_val18; // r9
   unsigned int block_val19; // r0
   unsigned int block_size3; // r3
   char check1; // cf
   int block_index0; // r3
   int res4; // r0
   unsigned __int8 *block_ptr2; // [sp+Ch] [bp-664h]
   unsigned __int8 *block_ptr1; // [sp+10h] [bp-660h]
   unsigned __int8 *block_ptr0; // [sp+14h] [bp-65Ch]
   unsigned __int8 *block_ptr3; // [sp+18h] [bp-658h]
   unsigned __int8 *block_ptr4; // [sp+1Ch] [bp-654h]
   unsigned __int8 *block_ptr5; // [sp+20h] [bp-650h]
   int block_size2; // [sp+24h] [bp-64Ch]
   int block_val7; // [sp+28h] [bp-648h]
   int block_val14; // [sp+28h] [bp-648h]
   unsigned __int8 *sha224_0_local; // [sp+2Ch] [bp-644h]
   unsigned __int8 buffer0[256]; // [sp+34h] [bp-63Ch]
   unsigned __int8 buffer1[256]; // [sp+134h] [bp-53Ch]
   unsigned __int8 buffer2[260]; // [sp+234h] [bp-43Ch]
   unsigned __int8 buffer3[260]; // [sp+338h] [bp-338h]
   unsigned __int8 buffer4[260]; // [sp+43Ch] [bp-234h]
   unsigned __int8 buffer5[260]; // [sp+540h] [bp-130h]
   
   key_size_blocks_local = key_size_blocks;
   sha_224_1_local = sha_224_1;
   sha_224_2_local = sha_224_2;
   sha224_0_local = sha224_0;

   block_size0 = key_size_blocks - 1;

   if ( block_size0 > 0x3F )
   {
      goto LABEL_2;
   }

   if ( !((*sha_224_2 | *sha_224_1) & 1) )
   {
      goto LABEL_2;
   }

   block_size1 = block_size0;
   block_size2 = -4 * key_size_blocks_local;
   block_ptr0 = &buffer0[4 * key_size_blocks_local];
   block_ptr1 = &buffer1[4 * key_size_blocks_local];
   block_ptr2 = &buffer2[4 * key_size_blocks_local];
   block_ptr3 = &buffer3[4 * key_size_blocks_local];
   block_ptr4 = &buffer4[4 * key_size_blocks_local];
   byte_index0 = 0;
   block_val3 = 0;
   block_val1 = 0;
   block_ptr5 = &buffer5[4 * key_size_blocks_local];

   do
   {
      block_val0 = *&sha_224_1_local[4 * key_size_blocks_local - 4 + byte_index0];
      block_val1 |= block_val0;
      *&block_ptr0[byte_index0 - 4] = block_val0;
      block_val2 = *&sha_224_2_local[4 * key_size_blocks_local - 4 + byte_index0];
      *&block_ptr1[byte_index0 - 4] = block_val2;
      block_val3 |= block_val2;
      *&block_ptr2[byte_index0] = 0;
      *&block_ptr3[byte_index0] = 0;
      *&block_ptr4[byte_index0] = 0;
      *&block_ptr5[byte_index0] = 0;
      byte_index0 -= 4;
   }
   while ( byte_index0 != block_size2 );

   *buffer3 = 0;
   *buffer2 = 1;
   *buffer4 = 0;
   *buffer5 = 1;

   if ( !block_val1 || !block_val3 )
   {
LABEL_2:
      result = 0;
      goto LABEL_40;
   }

LABEL_8:
   while ( !(buffer1[0] & 1) )
   {
      if ( (*buffer2 | *buffer3) & 1 )
      {
         res0 = arbitrary_length_add_C8EB4A(buffer2, buffer2, sha_224_1_local, key_size_blocks_local, buffer1[0] & 1);
         res1 = arbitrary_length_substract_C8E36E(buffer3, buffer3, sha_224_2_local, key_size_blocks_local, 0);
         *&buffer2[4 * key_size_blocks_local] += res0;
         *&buffer3[4 * key_size_blocks_local] -= res1;
      }

      block_val4 = *&buffer2[4 * key_size_blocks_local];
      block_val5 = *&buffer3[4 * key_size_blocks_local];
      block_val6 = block_val5 << 31;
      block_val7 = block_val4 << 31;
      *&buffer3[4 * key_size_blocks_local] = block_val5 >> 1;
      byte_index1 = 0;
      byte_index2 = 0;
      block_val11 = 0;
      *&buffer2[4 * key_size_blocks_local] = block_val4 >> 1;

      do
      {
         byte_index1 -= 4;
         block_ptr6 = &block_ptr1[byte_index2];
         byte_index2 -= 4;
         block_val8 = *&block_ptr2[byte_index1];
         block_val9 = *(block_ptr6 - 1);
         block_val10 = *&block_ptr3[byte_index1];
         *&block_ptr1[byte_index1] = block_val11 | (block_val9 >> 1);
         *&block_ptr2[byte_index1] = block_val7 | (block_val8 >> 1);
         block_val11 = block_val9 << 31;
         block_val7 = block_val8 << 31;
         *&block_ptr3[byte_index1] = block_val6 | (block_val10 >> 1);
         block_val6 = block_val10 << 31;
      }
      while ( byte_index2 != block_size2 );
   }

   while ( !(buffer0[0] & 1) )
   {
      if ( (*buffer4 | *buffer5) & 1 )
      {
         check0 = buffer0[0] & 1;
         res2 = arbitrary_length_add_C8EB4A(buffer4, buffer4, sha_224_1_local, key_size_blocks_local, check0);
         res3 = arbitrary_length_substract_C8E36E(buffer5, buffer5, sha_224_2_local, key_size_blocks_local, check0);
         *&buffer4[4 * key_size_blocks_local] += res2;
         *&buffer5[4 * key_size_blocks_local] -= res3;
      }

      block_val12 = *&buffer4[4 * key_size_blocks_local];
      block_val13 = *&buffer5[4 * key_size_blocks_local];
      block_val14 = block_val12 << 31;
      block_val15 = block_val13 << 31;
      *&buffer4[4 * key_size_blocks_local] = block_val12 >> 1;
      *&buffer5[4 * key_size_blocks_local] = block_val13 >> 1;
      byte_index3 = 0;
      byte_index4 = 0;
      block_val16 = 0;

      do
      {
         byte_index3 -= 4;
         block_ptr7 = &block_ptr0[byte_index4];
         byte_index4 -= 4;
         block_val17 = *&block_ptr4[byte_index3];
         block_val18 = *(block_ptr7 - 1);
         block_val19 = *&block_ptr5[byte_index3];
         *&block_ptr0[byte_index3] = block_val16 | (block_val18 >> 1);
         *&block_ptr4[byte_index3] = block_val14 | (block_val17 >> 1);
         block_val16 = block_val18 << 31;
         block_val14 = block_val17 << 31;
         *&block_ptr5[byte_index3] = block_val15 | (block_val19 >> 1);
         block_val15 = block_val19 << 31;
      }
      while ( byte_index4 != block_size2 );
  }

   if ( block_memcmp_C8EADC(buffer0, buffer1, key_size_blocks_local) )
   {
      arbitrary_length_substract_C8E36E(buffer0, buffer0, buffer1, key_size_blocks_local, 0);
      arbitrary_length_substract_C8E36E(buffer4, buffer4, buffer2, key_size_blocks_local + 1, 0);
      arbitrary_length_substract_C8E36E(buffer5, buffer5, buffer3, key_size_blocks_local + 1, 0);
   }
   else
   {
      arbitrary_length_substract_C8E36E(buffer1, buffer1, buffer0, key_size_blocks_local, 0);
      arbitrary_length_substract_C8E36E(buffer2, buffer2, buffer4, key_size_blocks_local + 1, 0);
      arbitrary_length_substract_C8E36E(buffer3, buffer3, buffer5, key_size_blocks_local + 1, 0);
   }

   block_size3 = key_size_blocks_local;

   while ( 1 )
   {
      check1 = block_size3-- >= 1;

      if ( !check1 )
      {
         break;
      }

      if ( *&buffer1[4 * block_size3] )
      {
         goto LABEL_8;
      }
   }

   do
   {
      check1 = block_size1-- >= 1;
   }
   while ( check1 && !*&buffer0[4 * block_size1 + 4] );

   if ( (block_size1 & 0x80000000) == 0 || *buffer0 != 1 )
   {
      goto LABEL_2;
   }

   if ( *&buffer5[4 * key_size_blocks_local] < 0 )
   {
      do
      {
         res4 = arbitrary_length_add_C8EB4A(buffer5, buffer5, sha_224_2_local, key_size_blocks_local, 0)
               + *&buffer5[4 * key_size_blocks_local];

         *&buffer5[4 * key_size_blocks_local] = res4;
      }
      while ( res4 );
   }
   else
   {
      while ( *&buffer5[4 * key_size_blocks_local] || !block_memcmp_C8EADC(sha_224_2_local, buffer5, key_size_blocks_local) )
      {
         *&buffer5[4 * key_size_blocks_local] -= arbitrary_length_substract_C8E36E(buffer5, buffer5, sha_224_2_local, key_size_blocks_local, 0);
      }
   }

   block_index0 = 0;

   do
   {
      *&sha224_0_local[4 * block_index0] = *&buffer5[4 * block_index0];
      ++block_index0;
   }
   while ( block_index0 < key_size_blocks_local );

  result = 1;

LABEL_40:

   return result;
}



int sub_C8EB80(unsigned char *buffer0, unsigned char *buffer1, unsigned char *buffer2, unsigned char *buffer3, int key_size_blocks, int arg4)
{
   unsigned __int8 *buffer3_local; // r6
   unsigned __int8 *buffer0_local; // r9
   unsigned __int8 *buffer2_local; // r8
   int block_index0; // r5
   unsigned __int8 *buffer1_local; // r11
   int block_counter0; // r12
   int block_counter1; // ST0C_4
   int buffer1_val; // t1
   int res0; // r10
   int res1; // r0
   int block_index1; // r3

   unsigned __int8 data00[4]; // [sp+18h] [bp-338h]
   unsigned __int8 data01[256]; // [sp+1Ch] [bp-334h]
   unsigned __int8 data20[260]; // [sp+11Ch] [bp-234h]
   unsigned __int8 data30[4]; // [sp+220h] [bp-130h]
   unsigned __int8 data31[256]; // [sp+224h] [bp-12Ch]

   buffer3_local = buffer3;
   buffer0_local = buffer0;
   buffer2_local = buffer2;

   if ( (key_size_blocks - 1) <= 0x3F )
   {
      block_index0 = 0;

      do
      {
         *&data00[4 * block_index0++] = 0;
      }
      while ( key_size_blocks >= block_index0 );

      buffer1_local = buffer1;
      block_counter0 = 0;

      do
      {
         block_counter1 = block_counter0;
         arbitrary_length_multiply_by_int_C8E01C(data30, buffer3_local, key_size_blocks, (*data00 + *buffer2_local * *buffer1_local) * arg4);
         buffer1_val = *buffer1_local;
         buffer1_local += 4;
         arbitrary_length_multiply_by_int_C8E01C(data20, buffer2_local, key_size_blocks, buffer1_val);
         res0 = arbitrary_length_add_C8EB4A(data30, data30, data20, key_size_blocks + 1, 0);
         res1 = arbitrary_length_add_C8EB4A(data00, data01, data31, key_size_blocks, (*data00 | *data30) != 0) + res0;
         *&data00[4 * key_size_blocks] = res1;
         block_counter0 = block_counter1 + 1;
      }
      while ( block_counter1 + 1 != key_size_blocks );

      if ( res1 || (buffer0 = (unsigned char *)block_memcmp_C8EADC(buffer3_local, data00, key_size_blocks)) == 0 )
      {
         buffer0 = (unsigned char *)arbitrary_length_substract_C8E36E(data00, data00, buffer3_local, key_size_blocks, 0);
      }

      block_index1 = 0;

      do
      {
         *&buffer0_local[block_index1] = *&data00[block_index1];
         block_index1 += 4;
      }
      while ( block_index1 != 4 * key_size_blocks );
   }
  
   return (int)buffer0;
}

int sub_C8EC70(unsigned char *buffer0, unsigned char *buffer1, int block_size_arg0, unsigned char *buffer3, int block_size_arg1, int arg_4)
{
   unsigned __int8 *buffer3_local; // r9
   unsigned __int8 *buffer0_local; // r11
   int byte_counter0; // r3
   unsigned __int8 *block_ptr0; // r8
   unsigned __int8 *block_ptr2; // r1
   int block_size0; // r2
   int byte_counter1; // r3
   unsigned __int8 *block_ptr1; // r7
   int block_counter1; // r6
   int block_val0; // t1
   int block_val1; // r5
   int byte_counter2; // r3
   int block_index0; // [sp+8h] [bp-440h]
   unsigned __int8 data10[256]; // [sp+18h] [bp-430h]
   unsigned __int8 data20[256]; // [sp+118h] [bp-330h]
   unsigned __int8 data30[4]; // [sp+218h] [bp-230h]
   unsigned __int8 data31[512]; // [sp+21Ch] [bp-22Ch]

   buffer3_local = buffer3;
   buffer0_local = buffer0;

   if ( (block_size_arg1 - 1) <= 0x3F && block_size_arg0 >= block_size_arg1 && block_size_arg0 <= 2 * block_size_arg1 )
   {
      byte_counter0 = 0;
      block_index0 = 4 * block_size_arg1;
      block_ptr0 = &data31[4 * block_size_arg1];

      do
      {
         *&data31[byte_counter0] = *&buffer1[byte_counter0];
         *&block_ptr0[byte_counter0] = 0;
         byte_counter0 += 4;
      }
      while ( byte_counter0 != block_index0 );

      block_ptr2 = &buffer1[block_index0];
      block_size0 = 4 * (block_size_arg0 - block_size_arg1);

      for ( byte_counter1 = 0; byte_counter1 != block_size0; byte_counter1 += 4 )
      {
         *&block_ptr0[byte_counter1] = *&block_ptr2[byte_counter1];
      }

      block_ptr1 = data30;
      block_counter1 = 0;

      do
      {
         block_val0 = *(block_ptr1 + 1);
         block_ptr1 += 4;
         arbitrary_length_multiply_by_int_C8E01C(data20, buffer3_local, block_size_arg1, block_val0 * arg_4);
         block_val1 = *&data20[4 * block_size_arg1];
         *&data10[4 * block_counter1++] = arbitrary_length_add_C8EB4A(block_ptr1, block_ptr1, data20, block_size_arg1, 0) + block_val1;
      }
      while ( block_counter1 != block_size_arg1 );

      if ( arbitrary_length_add_C8EB4A(&data31[4 * block_size_arg1], &data31[4 * block_size_arg1], data10, block_size_arg1, 0)
         || (buffer0 = (unsigned char *)block_memcmp_C8EADC(buffer3_local, &data31[4 * block_size_arg1], block_size_arg1)) == 0 )
      {
         buffer0 = (unsigned char *)arbitrary_length_substract_C8E36E(&data31[4 * block_size_arg1], &data31[4 * block_size_arg1], buffer3_local, block_size_arg1, 0);
      }

      byte_counter2 = 0;

      do
      {
         *&buffer0_local[byte_counter2] = *&block_ptr0[byte_counter2];
         byte_counter2 += 4;
      }
      while ( byte_counter2 != block_index0 );
   }

   return (int)buffer0;
}

int sub_C8EA10(unsigned char **buffer_ptrs0, unsigned char **buffer_ptrs1, unsigned char *buffer2, int block_size, int arg_0)
{
   int block_size_local; // r4
   unsigned __int8 *buffer2_local; // r5
   unsigned __int8 **buffer_ptrs0_local; // r8
   unsigned __int8 **buffer_ptrs1_local; // r7
   char check0; // cf
   unsigned __int8 *block_ptr1; // r1
   int byte_size0; // r4
   unsigned int byte_counter0; // r3
   unsigned __int8 *block_ptr0; // r1
   unsigned __int8 data0[28]; // [sp+8h] [bp-40h]

   block_size_local = block_size;
   buffer2_local = buffer2;
   buffer_ptrs0_local = buffer_ptrs0;
   buffer_ptrs1_local = buffer_ptrs1;

   if ( (block_size - 1) <= 6 )
   {
      while ( 1 )
      {
         check0 = block_size-- >= 1;

         if ( !check0 )
           break;

         block_ptr0 = buffer_ptrs1_local[2];

         if ( *&block_ptr0[4 * block_size] )
         {
            sub_C8EB80(data0, block_ptr0, buffer_ptrs1_local[2], buffer2, block_size_local, arg_0);
            sub_C8EB80(data0, data0, buffer_ptrs1_local[2], buffer2_local, block_size_local, arg_0);
            sub_C8EC70(data0, data0, block_size_local, buffer2_local, block_size_local, arg_0);
            do_smth_with_hashes_5_C8DBD4(data0, data0, buffer2_local, block_size_local);
            sub_C8EB80(buffer_ptrs0_local[1], buffer_ptrs1_local[1], data0, buffer2_local, block_size_local, arg_0);
            sub_C8EB80(data0, data0, buffer_ptrs1_local[2], buffer2_local, block_size_local, arg_0);
            buffer_ptrs0 = (unsigned char **)sub_C8EB80(*buffer_ptrs0_local, *buffer_ptrs1_local, data0, buffer2_local, block_size_local, arg_0);
            goto LABEL_7;
         }
      }

      buffer_ptrs0 = (unsigned char **)*buffer_ptrs0;
      block_ptr1 = buffer_ptrs0_local[1];
      byte_size0 = 4 * block_size_local;
      byte_counter0 = 0;

      do
      {
         buffer_ptrs0[byte_counter0 / 4] = 0;
         *&block_ptr1[byte_counter0] = 0;
         byte_counter0 += 4;
      }
      while ( byte_counter0 != byte_size0 );
   }

LABEL_7:

   return (int)buffer_ptrs0;
}

int sub_C8ED80(unsigned char *buffer0, unsigned char *buffer1, unsigned char *buffer2, unsigned char *buffer3, int key_size_blocks)
{
   int block_index0; // r4
   unsigned int block_val0; // r5
   int block_counter; // r7
   unsigned int v8; // lr
   int blockval11; // r12
   int blockval12; // r8
   int block_counter1; // r2
   unsigned __int8 *block_ptr0; // lr
   unsigned __int8 *block_ptr1; // r7
   int block_index1; // r1
   unsigned __int8 *block_val1; // r4
   unsigned int block_val5; // r1
   int block_index2; // r2
   int block_val2; // r4
   int block_val3; // r5
   unsigned int block_val4; // r1

   block_index0 = 0;
   block_val0 = 0;
   block_counter = 0;

   while ( block_counter < key_size_blocks )
   {
      v8 = *(int *)&buffer1[block_index0];
      ++block_counter;
      blockval11 = *(int *)&buffer2[block_index0];
      blockval12 = v8 + blockval11 + block_val0;
      *(int *)&buffer0[block_index0] = blockval12;
      block_val0 = ((blockval11 | v8) & ~blockval12 | blockval11 & v8) >> 31;
      block_index0 += 4;
   }

   block_counter1 = key_size_blocks & ~(key_size_blocks >> 31);
   if ( block_val0 )
      goto LABEL_16;

   block_ptr0 = &buffer0[4 * block_counter1];
   block_ptr1 = &buffer3[4 * block_counter1];
   block_index1 = 0;

   do
   {
      if ( --block_counter1 + 1 <= 0 )
      break;
      block_val1 = &block_ptr0[block_index1];
      block_index1 -= 4;
   }
   while ( *((int *)block_val1 - 1) == *(int *)&block_ptr1[block_index1] );

   if ( block_counter1 < 0 || *(int *)&buffer0[4 * block_counter1] >= *(int *)&buffer3[4 * block_counter1] )
   {
   LABEL_16:
      block_val5 = 0;
      block_index2 = 0;
      while ( block_index2 < key_size_blocks )
      {
         block_val2 = *(int *)&buffer3[4 * block_index2++];
         block_val3 = *(int *)buffer0 - block_val2 - block_val5;
         block_val4 = (~*(int *)buffer0 | block_val2) & block_val3 | block_val2 & ~*(int *)buffer0;
         *(int *)buffer0 = block_val3;
         buffer0 += 4;
         block_val5 = block_val4 >> 31;
      }
   }

   return (int)buffer0;
}

int sub_C8EE20(unsigned char *buffer0, unsigned char *buffer1, unsigned char *buffer2, unsigned char *buffer3, int key_size_blocks)
{
   int block_index0; // r4
   unsigned int acc0; // r5
   int block_counter0; // r6
   unsigned int block_val0; // r7
   int block_val1; // r8
   int block_val2; // r12
   unsigned int acc1; // r1
   int block_counter1; // r2
   int block_val3; // r5
   int block_val4; // r6
   unsigned int block_val6; // r1

   block_index0 = 0;
   acc0 = 0;
   block_counter0 = 0;

   while ( block_counter0 < key_size_blocks )
   {
      block_val0 = *(int *)&buffer2[block_index0];
      ++block_counter0;
      block_val1 = *(int *)&buffer1[block_index0];
      block_val2 = block_val1 - block_val0 - acc0;
      *(int *)&buffer0[block_index0] = block_val2;
      acc0 = ((~block_val1 | block_val0) & block_val2 | ~block_val1 & block_val0) >> 31;
      block_index0 += 4;
   }

   if ( acc0 )
   {
      acc1 = 0;
      block_counter1 = 0;

      while ( block_counter1 < key_size_blocks )
      {
         block_val3 = *(int *)&buffer3[4 * block_counter1++];
         block_val4 = block_val3 + *(int *)buffer0 + acc1;
         block_val6 = (block_val3 | *(int *)buffer0) & ~block_val4 | *(int *)buffer0 & block_val3;
         *(int *)buffer0 = block_val4;
         buffer0 += 4;
         acc1 = block_val6 >> 31;
      }
   }

   return (int)buffer0;
}

int sub_C8E728(unsigned char **ptr_table, unsigned char * unused, unsigned char *buffer0, unsigned int key_size_blocks, int arg_0)
{
   int key_size_blocks0; // r4
   unsigned char *buffer0_ptr; // r5
   unsigned char **ptr_table_local; // r6
   int *cookie_addr; // r8
   char block_counter0; // cf
   unsigned char *buffer_ptr0; // r1
   unsigned char buffer_local0[28]; // [sp+Ch] [bp-8Ch]
   unsigned char buffer_local1[28]; // [sp+28h] [bp-70h]
   unsigned char buffer_local2[28]; // [sp+44h] [bp-54h]
   unsigned char buffer_local3[28]; // [sp+60h] [bp-38h]
   int cookie; // [sp+7Ch] [bp-1Ch]

   key_size_blocks0 = key_size_blocks;
   buffer0_ptr = buffer0;
   ptr_table_local = ptr_table;

   /*
   cookie_addr = (int *)cookie_addr_C8E8C0;
   cookie = *(_DWORD *)cookie_addr_C8E8C0;
   */

   if ( key_size_blocks - 1 <= 6 )
   {
      while ( 1 )
      {
         block_counter0 = key_size_blocks-- >= 1;
         if ( !block_counter0 )
            break;

         buffer_ptr0 = ptr_table[2];
         if ( *(int *)&buffer_ptr0[4 * key_size_blocks] )
         {
            sub_C8EB80(buffer_local0, buffer_ptr0, ptr_table[2], buffer0, key_size_blocks0, arg_0);
            sub_C8ED80(buffer_local1, *ptr_table_local, buffer_local0, buffer0_ptr, key_size_blocks0);
            sub_C8EE20(buffer_local2, *ptr_table_local, buffer_local0, buffer0_ptr, key_size_blocks0);
            sub_C8EB80(buffer_local0, buffer_local1, buffer_local2, buffer0_ptr, key_size_blocks0, arg_0);
            sub_C8ED80(buffer_local2, buffer_local0, buffer_local0, buffer0_ptr, key_size_blocks0);
            sub_C8ED80(buffer_local0, buffer_local2, buffer_local0, buffer0_ptr, key_size_blocks0);

            sub_C8EB80(
               buffer_local2,
               (unsigned char *)*(unsigned long long *)(ptr_table_local + 1),
               (unsigned char *)(*(unsigned long long *)(ptr_table_local + 1) >> 32),
               buffer0_ptr,
               key_size_blocks0,
               arg_0);

            sub_C8ED80(ptr_table_local[2], buffer_local2, buffer_local2, buffer0_ptr, key_size_blocks0);
            sub_C8EB80(buffer_local1, *ptr_table_local, ptr_table_local[1], buffer0_ptr, key_size_blocks0, arg_0);
            sub_C8EB80(buffer_local1, buffer_local1, ptr_table_local[1], buffer0_ptr, key_size_blocks0, arg_0);
            sub_C8ED80(buffer_local1, buffer_local1, buffer_local1, buffer0_ptr, key_size_blocks0);
            sub_C8ED80(buffer_local1, buffer_local1, buffer_local1, buffer0_ptr, key_size_blocks0);
            sub_C8EB80(buffer_local3, buffer_local0, buffer_local0, buffer0_ptr, key_size_blocks0, arg_0);
            sub_C8ED80(buffer_local2, buffer_local1, buffer_local1, buffer0_ptr, key_size_blocks0);
            sub_C8EE20(*ptr_table_local, buffer_local3, buffer_local2, buffer0_ptr, key_size_blocks0);
            sub_C8EB80(buffer_local2, ptr_table_local[1], ptr_table_local[1], buffer0_ptr, key_size_blocks0, arg_0);
            sub_C8EB80(buffer_local2, buffer_local2, buffer_local2, buffer0_ptr, key_size_blocks0, arg_0);
            sub_C8ED80(buffer_local2, buffer_local2, buffer_local2, buffer0_ptr, key_size_blocks0);
            sub_C8ED80(buffer_local2, buffer_local2, buffer_local2, buffer0_ptr, key_size_blocks0);
            sub_C8ED80(buffer_local2, buffer_local2, buffer_local2, buffer0_ptr, key_size_blocks0);
            sub_C8EE20(buffer_local1, buffer_local1, *ptr_table_local, buffer0_ptr, key_size_blocks0);
            sub_C8EB80(buffer_local0, buffer_local0, buffer_local1, buffer0_ptr, key_size_blocks0, arg_0);

            ptr_table = (unsigned __int8 **)sub_C8EE20(ptr_table_local[1], buffer_local0, buffer_local2, buffer0_ptr, key_size_blocks0);
            break;
         }
      }
   }
  /*
   if ( cookie != *cookie_addr )
      SceMsif_SceSysclibForDriver__imp___stack_chk_fail_b997493d(ptr_table);
  */
   return (int)ptr_table;
}

int sub_C8F130(unsigned char **ptr_table, unsigned char *buffer1, unsigned char *buffer2, unsigned int key_size_blocks, int arg_0)
{
   int key_size_blocks_local; // r4
   unsigned char *buffer2_ptr_local; // r5
   unsigned char **ptr_table_local; // r6
   unsigned char *buffer1_ptr_local; // r9
   //int *cookie_addr; // r8
   char check0; // cf
   unsigned char buffer_local0[28]; // [sp+Ch] [bp-94h]
   unsigned char buffer_local1[28]; // [sp+28h] [bp-78h]
   unsigned char buffer_local2[28]; // [sp+44h] [bp-5Ch]
   unsigned char buffer_local3[28]; // [sp+60h] [bp-40h]
   //int cookie; // [sp+7Ch] [bp-24h]

   key_size_blocks_local = key_size_blocks;
   buffer2_ptr_local = buffer2;
   ptr_table_local = ptr_table;
   buffer1_ptr_local = buffer1;
   //cookie_addr = (int *)cookie_address_C8F2DC;
   //cookie = *(int *)cookie_address_C8F2DC;

   if ( (unsigned int)(key_size_blocks - 1) <= 6 )
   {
      while ( 1 )
      {
         check0 = (unsigned int)key_size_blocks-- >= 1;
         if ( !check0 )
            break;

         if ( *(int *)&ptr_table[2][4 * key_size_blocks] )
         {
            sub_C8EB80(buffer_local0, *ptr_table, *ptr_table, buffer2, key_size_blocks_local, arg_0);
            sub_C8EB80(buffer_local1, ptr_table_local[2], ptr_table_local[2], buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8EB80(buffer_local1, buffer_local1, buffer_local1, buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8ED80(buffer_local2, buffer_local0, buffer_local0, buffer2_ptr_local, key_size_blocks_local);
            sub_C8ED80(buffer_local0, buffer_local0, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EB80(buffer_local1, buffer1_ptr_local, buffer_local1, buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8ED80(buffer_local0, buffer_local0, buffer_local1, buffer2_ptr_local, key_size_blocks_local);

            sub_C8EB80(
               buffer_local2,
               (unsigned __int8 *)*(long long *)(ptr_table_local + 1),
               (unsigned __int8 *)(*(long long *)(ptr_table_local + 1) >> 32),
               buffer2_ptr_local,
               key_size_blocks_local,
               arg_0);

            sub_C8ED80(ptr_table_local[2], buffer_local2, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EB80(buffer_local1, *ptr_table_local, ptr_table_local[1], buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8EB80(buffer_local1, buffer_local1, ptr_table_local[1], buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8ED80(buffer_local1, buffer_local1, buffer_local1, buffer2_ptr_local, key_size_blocks_local);
            sub_C8ED80(buffer_local1, buffer_local1, buffer_local1, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EB80(buffer_local3, buffer_local0, buffer_local0, buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8ED80(buffer_local2, buffer_local1, buffer_local1, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EE20(*ptr_table_local, buffer_local3, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EB80(buffer_local2, ptr_table_local[1], ptr_table_local[1], buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8EB80(buffer_local2, buffer_local2, buffer_local2, buffer2_ptr_local, key_size_blocks_local, arg_0);
            sub_C8ED80(buffer_local2, buffer_local2, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            sub_C8ED80(buffer_local2, buffer_local2, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            sub_C8ED80(buffer_local2, buffer_local2, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EE20(buffer_local1, buffer_local1, *ptr_table_local, buffer2_ptr_local, key_size_blocks_local);
            sub_C8EB80(buffer_local0, buffer_local0, buffer_local1, buffer2_ptr_local, key_size_blocks_local, arg_0);

            ptr_table = (unsigned char **)sub_C8EE20(ptr_table_local[1], buffer_local0, buffer_local2, buffer2_ptr_local, key_size_blocks_local);
            break;
         }
      }
   }
   /*
   if ( cookie != *cookie_addr )
      SceMsif_SceSysclibForDriver__imp___stack_chk_fail_b997493d(ptr_table);
   */
   return (int)ptr_table;
}
   
int sub_C8EE88(unsigned char **ptr_table0, unsigned char **ptr_table1, unsigned char *buffer0, unsigned char *buffer1, int key_size_blocks, int arg4)
{
   unsigned char *buffer1_local_ptr; // r5
   unsigned char **ptr_table0_local; // r7
   unsigned char **ptr_table1_local; // r8
   unsigned char *buffer0_local_ptr; // r11
   int v10; // r3
   unsigned char *ptr0; // r1
   unsigned char *ptr1; // r2
   unsigned char *ptr2; // r12
   unsigned int block_index0; // r3
   unsigned char *ptr3; // r5
   unsigned char *ptr4; // r6
   unsigned int key_size_blocks0; // r3
   char check0; // cf
   unsigned int key_size_blocks1; // r3
   unsigned int key_size_blocks2; // r3
   signed int block_index1; // r3
   unsigned char *ptr5; // r5
   unsigned char *ptr6; // r1
   unsigned char *ptr7; // r4
   int block_index2; // r3
   unsigned char *ptr8; // r5
   unsigned int block_val0; // r2
   unsigned __int8 buffer0_local[28]; // [sp+Ch] [bp-D4h]
   unsigned __int8 buffer1_local[28]; // [sp+28h] [bp-B8h]
   unsigned __int8 buffer2_local[28]; // [sp+44h] [bp-9Ch]
   unsigned __int8 buffer3_local[28]; // [sp+60h] [bp-80h]
   unsigned __int8 buffer4_local[28]; // [sp+7Ch] [bp-64h]
   unsigned __int8 buffer5_local[28]; // [sp+98h] [bp-48h]
   int cookie; // [sp+B4h] [bp-2Ch]

   buffer1_local_ptr = buffer1;
   ptr_table0_local = ptr_table0;
   ptr_table1_local = ptr_table1;
   buffer0_local_ptr = buffer0;

  //cookie = *(int *)cookie_address_C8F12C;

   if ( (unsigned int)(key_size_blocks - 1) <= 6 )
   {
      v10 = key_size_blocks;

      do
      {
         --v10;
         ptr0 = ptr_table0[2];
         if ( v10 == -1 )
         {
            ptr1 = *ptr_table0;
            ptr2 = *ptr_table1_local;
            block_index0 = 0;
            ptr3 = ptr_table0[1];
            ptr_table0 = (unsigned __int8 **)(*(long long *)(ptr_table1_local + 1) >> 32);
            ptr4 = (unsigned __int8 *)*(long long *)(ptr_table1_local + 1);

            do
            {
               *(int *)&ptr1[block_index0] = *(int *)&ptr2[block_index0];
               *(int *)&ptr3[block_index0] = *(int *)&ptr4[block_index0];
               *(int *)&ptr0[block_index0] = (int)ptr_table0[block_index0 / 4]; //this is bad
               block_index0 += 4;
            }
            while ( block_index0 != 4 * key_size_blocks );

            goto LABEL_27;
         }
      }
      while ( !*(int *)&ptr0[4 * v10] );

      key_size_blocks0 = key_size_blocks;

      while ( 1 )
      {
         check0 = key_size_blocks0-- >= 1;
         if ( !check0 )
            break;

         if ( *(int *)&ptr_table1_local[2][4 * key_size_blocks0] )
         {
            sub_C8EB80(buffer3_local, ptr0, ptr_table0[2], buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EB80(buffer4_local, ptr_table1_local[2], ptr_table1_local[2], buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EB80(buffer0_local, *ptr_table1_local, buffer3_local, buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EB80(buffer1_local, *ptr_table0_local, buffer4_local, buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EE20(buffer2_local, buffer0_local, buffer1_local, buffer1_local_ptr, key_size_blocks);
            sub_C8EB80(buffer3_local, buffer3_local, ptr_table0_local[2], buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EB80(buffer4_local, buffer4_local, ptr_table1_local[2], buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EB80(buffer3_local, buffer3_local, ptr_table1_local[1], buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EB80(buffer4_local, buffer4_local, ptr_table0_local[1], buffer1_local_ptr, key_size_blocks, arg4);
            sub_C8EE20(buffer5_local, buffer3_local, buffer4_local, buffer1_local_ptr, key_size_blocks);
            key_size_blocks1 = key_size_blocks;

            while ( 1 )
            {
               check0 = key_size_blocks1-- >= 1;
               if ( !check0 )
                  break;

               if ( *(int *)&buffer2_local[4 * key_size_blocks1] )
               {
                  sub_C8ED80(buffer0_local, buffer0_local, buffer1_local, buffer1_local_ptr, key_size_blocks);
                  sub_C8ED80(buffer3_local, buffer3_local, buffer4_local, buffer1_local_ptr, key_size_blocks);
                  sub_C8EB80(buffer4_local, ptr_table1_local[2], ptr_table0_local[2], buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EB80(ptr_table0_local[2], buffer4_local, buffer2_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EB80(buffer1_local, buffer5_local, buffer5_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EB80(buffer4_local, buffer2_local, buffer2_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EB80(buffer0_local, buffer0_local, buffer4_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EE20(*ptr_table0_local, buffer1_local, buffer0_local, buffer1_local_ptr, key_size_blocks);
                  sub_C8EE20(buffer0_local, buffer0_local, *ptr_table0_local, buffer1_local_ptr, key_size_blocks);
                  sub_C8EE20(buffer0_local, buffer0_local, *ptr_table0_local, buffer1_local_ptr, key_size_blocks);
                  sub_C8EB80(buffer0_local, buffer0_local, buffer5_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EB80(buffer4_local, buffer4_local, buffer2_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EB80(buffer3_local, buffer3_local, buffer4_local, buffer1_local_ptr, key_size_blocks, arg4);
                  sub_C8EE20(buffer4_local, buffer0_local, buffer3_local, buffer1_local_ptr, key_size_blocks);
                  ptr_table0 = (unsigned __int8 **)(buffer4_local[0] & 1);

                  if ( buffer4_local[0] & 1 )
                     ptr_table0 = (unsigned __int8 **)(arbitrary_length_add_C8EB4A(buffer4_local, buffer4_local, buffer1_local_ptr, key_size_blocks, 0) << 31);

                  ptr7 = &ptr_table0_local[1][4 * key_size_blocks];
                  block_index2 = 0;

                  do
                  {
                     ptr8 = &ptr7[block_index2];
                     block_val0 = *(int *)&buffer4_local[4 * key_size_blocks - 4 + block_index2];
                     block_index2 -= 4;
                     *((int *)ptr8 - 1) = (unsigned int)ptr_table0 | (block_val0 >> 1);
                     ptr_table0 = (unsigned __int8 **)(block_val0 << 31);
                  }
                  while ( block_index2 != -4 * key_size_blocks );

                  goto LABEL_27;
               }
            }

            key_size_blocks2 = key_size_blocks;

            do
            {
               check0 = key_size_blocks2-- >= 1;
               if ( !check0 )
               {
                  ptr_table0 = (unsigned __int8 **)sub_C8F130(ptr_table0_local, buffer0_local_ptr, buffer1_local_ptr, key_size_blocks, arg4);
                  goto LABEL_27;
               }
            }
            while ( !*(int *)&buffer5_local[4 * key_size_blocks2] );

            for ( block_index1 = 1; ; ++block_index1 )
            {
               ptr_table0 = (unsigned __int8 **)(*(long long *)ptr_table0_local >> 32);
               ptr5 = (unsigned __int8 *)*(long long *)ptr_table0_local;
               ptr6 = ptr_table0_local[2];

               if ( block_index1 == key_size_blocks )
                  break;

               *(int *)&ptr5[4 * block_index1] = 0;
               ptr_table0[block_index1] = 0;
               *(int *)&ptr6[4 * block_index1] = 0;
            }

            *(int *)ptr5 = 1;
            *ptr_table0 = (unsigned __int8 *)1;
            *(int *)ptr6 = 0;

            break;
         }
      }
   }
LABEL_27:
  
   /*
   if ( cookie != *(_DWORD *)cookie_address_C8F12C )
      SceMsif_SceSysclibForDriver__imp___stack_chk_fail_b997493d(ptr_table0);
   */

  return (int)ptr_table0;
}   

int sub_C8E8C4(unsigned char **ptr_table0, unsigned char **ptr_table1, unsigned char *buffer0, unsigned char *buffer1, int key_size_blocks, int arg_4)
{
   unsigned char **ptr_table0_local; // r5
   unsigned char **ptr_table1_local; // r6
   unsigned char *buffer0_local; // r9
   unsigned char *buffer1_local; // r8
   int key_size_blocks_local; // r0
   int block_index0; // r3
   int result; // r0
   unsigned char *ptr0; // r6
   unsigned char *ptr1; // r1

   ptr_table0_local = ptr_table0;
   ptr_table1_local = ptr_table1;
   buffer0_local = buffer0;
   buffer1_local = buffer1;
   key_size_blocks_local = key_size_blocks;

   do
      --key_size_blocks_local;
   while ( key_size_blocks_local + 1 > 0
       && !*(int *)&(*ptr_table1)[4 * key_size_blocks_local]
       && !*(int *)&ptr_table1[1][4 * key_size_blocks_local] );

   if ( key_size_blocks_local >= 0 )
   {
      sub_C8EB80(*ptr_table0_local, *ptr_table1, buffer0, buffer1, key_size_blocks, arg_4);
      sub_C8EB80(ptr_table0_local[1], ptr_table1_local[1], buffer0_local, buffer1_local, key_size_blocks, arg_4);
      result = sub_C8EC70(ptr_table0_local[2], buffer0_local, key_size_blocks, buffer1_local, key_size_blocks, arg_4);
   }
   else
   {
      for ( block_index0 = 1; ; ++block_index0 )
      {
         result = *(long long *)ptr_table0_local >> 32;
         ptr0 = (unsigned __int8 *)*(long long *)ptr_table0_local;
         ptr1 = ptr_table0_local[2];
         if ( block_index0 >= key_size_blocks )
            break;
         *(int *)&ptr0[4 * block_index0] = 0;
         *(int *)(result + 4 * block_index0) = 0;
         *(int *)&ptr1[4 * block_index0] = 0;
      }

      *(int *)ptr0 = 1;
      *(int *)result = 1;
      *(int *)ptr1 = 0;
   }

   return result;
}

void sub_C8E95C(unsigned char **ptr_table0, unsigned char **ptr_table1, unsigned char *buffer0, unsigned char **ptr_table2, unsigned char **ptr_table3, unsigned char *buffer1, unsigned char *buffer2, unsigned int key_size_blocks1, int arg_10)
{
   /*
   unsigned __int8 **v9; // r10
   unsigned __int8 **v10; // r11
   signed int size1; // r2
   signed int counter0; // r3
   unsigned __int8 **ptr_table_local; // [sp+8h] [bp-70h]
   unsigned __int8 *buffer0_local; // [sp+Ch] [bp-6Ch]
   unsigned __int8 buffer1_local[56]; // [sp+10h] [bp-68h]
   int cookie; // [sp+4Ch] [bp-2Ch]
   char dummy; // [sp+50h] [bp-28h]

   v9 = ptr_table2;
   v10 = ptr_table1;
   buffer0_local = buffer0;
  
   //cookie = *(_DWORD *)cookie_address_C8EA0C;

   if ( key_size_blocks1 - 1 <= 6 )
   {
      size1 = 2 * key_size_blocks1;
      counter0 = 0;

      do
         *(int *)&buffer1_local[4 * counter0++] = 0;
      while ( counter0 < size1 );
      
      *((int *)&dummy + 2 * key_size_blocks1 - 0x10) = 1;
      
      ptr_table_local = ptr_table0;
      ptr_table0 = (unsigned __int8 **)do_smth_with_hashes_2_C8E084(buffer1_local, buffer1_local, size1 + 1, buffer2, key_size_blocks1);

      if ( v9 )
         ptr_table0 = (unsigned __int8 **)sub_C8E8C4(ptr_table_local, v9, buffer1_local, buffer2, key_size_blocks1, arg_10);
      if ( ptr_table3 )
         ptr_table0 = (unsigned __int8 **)sub_C8E8C4(v10, ptr_table3, buffer1_local, buffer2, key_size_blocks1, arg_10);
      if ( buffer1 )
         ptr_table0 = (unsigned __int8 **)sub_C8EB80(buffer0_local, buffer1_local, buffer1, buffer2, key_size_blocks1, arg_10);
   }

   
   //if ( cookie != *(_DWORD *)cookie_address_C8EA0C )
   //   SceMsif_SceSysclibForDriver__imp___stack_chk_fail_b997493d(ptr_table0);
   
   return (int)ptr_table0;
   */
}   

typedef int hsub_hash_fun7(unsigned char **ptr_table, unsigned char *buffer0, unsigned char *buffer1, unsigned int key_size_blocks, int arg_0);

hsub_hash_fun7 *off_C8E720 = sub_C8E728;
hsub_hash_fun7* off_C8E724 = sub_C8F130;

int do_smth_with_hashes_7_C8E420(unsigned char **sha_224_0, unsigned char **sha_224_1, unsigned char **sha_224_2, unsigned char *sha_224_3, unsigned char *sha_224_4, unsigned char *sha_224_5, unsigned char *sha_224_6, int key_size_blocks)
{
   unsigned char *buffer_ptr5; // r9
   unsigned char **ptr_table6; // r6
   int block_counter0; // r0
   unsigned int block_val0; // r3
   int block_val1; // r7
   int block_val2; // r4
   hsub_hash_fun7 *func7; // r8
   signed int bit_counter0; // r7
   int bit_val0; // r4
   signed int bit_val1; // r3
   int block_val3; // r1
   unsigned char **ptr_table7; // r3
   int key_size_total0; // r6
   int byte_counter0; // r1
   int block_counter1; // r3
   int byte_counter1; // r2
   unsigned int block_val4; // r7
   unsigned int block_val5; // r0
   int block_val6; // r1
   unsigned int block_val7; // r0
   unsigned int block_val8; // r7
   int block_val9; // r0
   int block_val10; // r1
   unsigned int block_val11; // r7
   int block_val12; // r0
   int block_val13; // r1
   unsigned int block_val14; // r7
   int block_counter2; // r3
   int byte_counter2; // lr
   int byte_counter3; // r1
   unsigned int block_val15; // r0
   unsigned int block_val16; // r7
   int block_val17; // lr
   unsigned int block_val18; // r7
   unsigned int block_val19; // r0
   int block_val20; // r7
   int block_val21; // lr
   unsigned int block_val22; // r0
   int block_val23; // r7
   int block_val24; // lr
   unsigned int block_val25; // r0
   unsigned char *ptr_table8[2]; // kr00_8
   int block_counter3; // r3
   unsigned int total_byte_size0; // r7
   unsigned char *buffer_ptr7; // r2
   unsigned char *ptr_table9[2]; // kr08_8
   int block_counter4; // r3
   unsigned char *buffer_ptr8; // lr
   int maybe_tail_size0; // r3
   unsigned char *buffer_ptr9; // r8
   int block_counter5; // r3
   unsigned char *buffer_ptr0; // r9
   unsigned char *buffer_ptr1; // r7
   unsigned char *buffer_ptr2; // r2
   unsigned char *buffer_ptr3; // lr
   unsigned char *buffer_ptr4; // r0
   unsigned char **ptr_table0; // [sp+1Ch] [bp-22Ch]
   unsigned char *ptr_table1[3]; // [sp+20h] [bp-228h]
   unsigned char *ptr_table2[3]; // [sp+2Ch] [bp-21Ch]
   unsigned char *ptr_table3[3]; // [sp+38h] [bp-210h]
   unsigned char *ptr_table4[3]; // [sp+44h] [bp-204h]
   unsigned char *ptr_table5[3]; // [sp+50h] [bp-1F8h]
   unsigned char buffer0[28]; // [sp+5Ch] [bp-1ECh]
   unsigned char buffer1[28]; // [sp+78h] [bp-1D0h]
   unsigned char buffer2[28]; // [sp+94h] [bp-1B4h]
   unsigned char buffer3[28]; // [sp+B0h] [bp-198h]
   unsigned char buffer4[28]; // [sp+CCh] [bp-17Ch]
   unsigned char buffer5[28]; // [sp+E8h] [bp-160h]
   unsigned char buffer6[28]; // [sp+104h] [bp-144h]
   unsigned char buffer7[28]; // [sp+120h] [bp-128h]
   unsigned char buffer8[28]; // [sp+13Ch] [bp-10Ch]
   unsigned char buffer9[28]; // [sp+158h] [bp-F0h]
   unsigned char buffer10[28]; // [sp+174h] [bp-D4h]
   unsigned char buffer11[28]; // [sp+190h] [bp-B8h]
   unsigned char buffer12[28]; // [sp+1ACh] [bp-9Ch]
   unsigned char buffer13[28]; // [sp+1C8h] [bp-80h]
   unsigned char buffer14[28]; // [sp+1E4h] [bp-64h]
   unsigned char buffer15[28]; // [sp+200h] [bp-48h]
   int cookie; // [sp+21Ch] [bp-2Ch]

   buffer_ptr5 = sha_224_3;
   ptr_table6 = sha_224_1;
   ptr_table0 = sha_224_0;
  
   //cookie = *(int *)cookie_address_C8E71C;

   if ( (unsigned int)(key_size_blocks - 1) > 6 )
      goto LABEL_38;

   block_counter0 = 0;
   ptr_table1[0] = buffer1;
   ptr_table1[1] = buffer2;
   ptr_table1[2] = buffer3;
   ptr_table2[0] = buffer4;
   ptr_table2[1] = buffer5;
   ptr_table2[2] = buffer6;
   ptr_table3[0] = buffer7;
   ptr_table3[1] = buffer8;
   ptr_table3[2] = buffer9;
   block_val0 = 3;

   do
   {
      block_val1 = *(int *)&sha_224_6[4 * block_counter0];
      if ( block_val1 + block_val0 != *(int *)&sha_224_5[4 * block_counter0] )
      {
         if ( block_val0 || key_size_blocks != block_counter0 )
            goto LABEL_10;

LABEL_9:
         func7 = off_C8E720;
         goto LABEL_11;
      }

      ++block_counter0;
      block_val2 = block_val1 + block_val0;
      block_val0 = (block_val1 & ~(block_val1 + block_val0)) >> 31;
   }
   while ( block_counter0 != key_size_blocks );

   if ( (block_val1 & ~block_val2) >= 0 )
      goto LABEL_9;

LABEL_10:
   func7 = off_C8E724;

LABEL_11:
   bit_counter0 = 31;
   bit_val0 = 1;
   bit_val1 = 2;

   do
   {
      --bit_counter0;
      block_val3 = -*(int *)sha_224_5 * bit_val0 & bit_val1;
      bit_val1 *= 2;
      bit_val0 |= block_val3;
   }
   while ( bit_counter0 );

   ptr_table7 = ptr_table6;
   key_size_total0 = 4 * key_size_blocks;

   sub_C8E95C((unsigned char **)ptr_table2, ptr_table3, buffer0, ptr_table7, sha_224_2, sha_224_6, sha_224_5, key_size_blocks, bit_val0);

   ptr_table4[0] = buffer10;
   ptr_table4[1] = buffer11;
   ptr_table4[2] = buffer12;
   ptr_table5[0] = buffer13;
   ptr_table5[1] = buffer14;
   ptr_table5[2] = buffer15;
   byte_counter0 = 0x20;
   block_counter1 = 0;
   byte_counter1 = 0;

   do
   {
      ++block_counter1;

      if ( byte_counter0 != 32 )
         break;

      block_val4 = *(int *)&buffer_ptr5[key_size_total0 + -4 * block_counter1];
      block_val5 = (-(block_val4 >> 16) >> 16) & 0x10;
      block_val6 = 0x10 - block_val5;
      block_val7 = block_val4 >> block_val5;
      block_val8 = ((block_val7 - 0x100) >> 16) & 8;
      block_val9 = block_val7 << block_val8;
      block_val10 = block_val6 + block_val8;
      block_val11 = ((unsigned int)(block_val9 - 0x1000) >> 16) & 4;
      block_val12 = block_val9 << block_val11;
      block_val13 = block_val10 + block_val11;
      block_val14 = ((unsigned int)(block_val12 - 0x4000) >> 16) & 2;

      byte_counter0 = block_val13
                  + block_val14
                  + 2
                  - (((unsigned int)(block_val12 << block_val14) >> 14) & ~((unsigned int)(block_val12 << block_val14) >> 15));

      byte_counter1 += byte_counter0;
   }
   while ( block_counter1 != key_size_blocks );

   block_counter2 = 0;
   byte_counter2 = 32;
   byte_counter3 = 0;

   do
   {
      ++block_counter2;

      if ( byte_counter2 != 32 )
         break;

      block_val15 = *(int *)&sha_224_4[key_size_total0 + -4 * block_counter2];
      block_val16 = (-(block_val15 >> 16) >> 16) & 0x10;
      block_val17 = 16 - block_val16;
      block_val18 = block_val15 >> block_val16;
      block_val19 = ((block_val18 - 256) >> 16) & 8;
      block_val20 = block_val18 << block_val19;
      block_val21 = block_val17 + block_val19;
      block_val22 = ((unsigned int)(block_val20 - 0x1000) >> 16) & 4;
      block_val23 = block_val20 << block_val22;
      block_val24 = block_val21 + block_val22;
      block_val25 = ((unsigned int)(block_val23 - 0x4000) >> 16) & 2;

      byte_counter2 = block_val24
                  + block_val25
                  + 2
                  - (((unsigned int)(block_val23 << block_val25) >> 14) & ~((unsigned int)(block_val23 << block_val25) >> 15));

      byte_counter3 += byte_counter2;
   }
   while ( block_counter2 != key_size_blocks );

   if ( byte_counter3 < byte_counter1 )
      byte_counter1 = byte_counter3;

   *(long long *)ptr_table8 = *(long long *)ptr_table2;
   block_counter3 = 0;
   total_byte_size0 = 32 * key_size_blocks - byte_counter1;
   buffer_ptr7 = ptr_table2[2];

   do
   {
      *(int *)&buffer10[block_counter3] = *(int *)&ptr_table8[0][block_counter3];
      *(int *)&buffer11[block_counter3] = *(int *)&ptr_table8[1][block_counter3];
      *(int *)&buffer12[block_counter3] = *(int *)&buffer_ptr7[block_counter3];
      block_counter3 += 4;
   }
   while ( block_counter3 != key_size_total0 );

   sub_C8EE88(ptr_table4, ptr_table3, buffer0, sha_224_5, key_size_blocks, bit_val0);
   *(long long *)ptr_table9 = *(long long *)ptr_table5;
   block_counter4 = 0;

   for ( buffer_ptr8 = ptr_table5[2]; ; *(int *)&buffer_ptr8[block_counter4] = 0 )
   {
      block_counter4 += 4;
      
      if ( block_counter4 == key_size_total0 )
         break;

      *(int *)&ptr_table9[0][block_counter4] = 0;
      *(int *)&ptr_table9[1][block_counter4] = 0;
   }

   *(int *)ptr_table5[0] = 1;
   *(int *)ptr_table5[1] = 1;
   *(int *)ptr_table5[2] = 0;

   while ( (--total_byte_size0 & 0x80000000) == 0 )
   {
      func7(ptr_table5, buffer0, sha_224_5, key_size_blocks, bit_val0);

      maybe_tail_size0 = (*(int *)&sha_224_4[4 * (total_byte_size0 >> 5)] >> (total_byte_size0 & 0x1F)) & 1 | 2 * ((*(int *)&buffer_ptr5[4 * (total_byte_size0 >> 5)] >> (total_byte_size0 & 0x1F)) & 1);

      switch ( maybe_tail_size0 )
      {
      case 2:
         sub_C8EE88(ptr_table5, ptr_table2, buffer0, sha_224_5, key_size_blocks, bit_val0);
         break;
      case 3:
         sub_C8EE88(ptr_table5, ptr_table4, buffer0, sha_224_5, key_size_blocks, bit_val0);
         break;
      case 1:
         sub_C8EE88(ptr_table5, ptr_table3, buffer0, sha_224_5, key_size_blocks, bit_val0);
         break;
      }
   }

   buffer_ptr9 = ptr_table1[0];
   block_counter5 = 0;
   buffer_ptr0 = ptr_table5[0];
   buffer_ptr1 = ptr_table1[1];
   buffer_ptr2 = ptr_table5[1];
   buffer_ptr3 = ptr_table1[2];
   buffer_ptr4 = ptr_table5[2];

   do
   {
      *(int *)&buffer_ptr9[block_counter5] = *(int *)&buffer_ptr0[block_counter5];
      *(int *)&buffer_ptr1[block_counter5] = *(int *)&buffer_ptr2[block_counter5];
      *(int *)&buffer_ptr3[block_counter5] = *(int *)&buffer_ptr4[block_counter5];
      block_counter5 += 4;
   }
   while ( block_counter5 != key_size_total0 );

   sha_224_0 = (unsigned __int8 **)sub_C8EA10(ptr_table0, ptr_table1, sha_224_5, key_size_blocks, bit_val0);

LABEL_38:

  //if ( cookie != *(int *)cookie_address_C8E71C )
  //  SceMsif_SceSysclibForDriver__imp___stack_chk_fail_b997493d();

  return (int)sha_224_0;
}

int verify_hashes_C8DA14(verify_hash_ctx *ctx, unsigned char secret_key[0x1C], unsigned char *dec_ptr_pair[2], unsigned char *dec_ptr_table[6], int key_size_blocks, int key_size_bytes)
{
   //order of variables may be important

   unsigned char* pointer_table0[3];
   unsigned char* pointer_table1[3];

   unsigned char dec_ptr_table_item0_rev[28];
   unsigned char dec_ptr_table_item1_rev[28];
   unsigned char dec_ptr_table_item2_rev[28];

   unsigned char verify_ptr0_rev[28];
   unsigned char verify_ptr1_rev[28];

   unsigned char secret_key_rev[28];

   unsigned char pointer_table0_item0[28];
   unsigned char pointer_table0_item1[28];
   unsigned char pointer_table0_item2[28];

   unsigned char pointer_table1_item0[28];
   unsigned char pointer_table1_item1[28];
   unsigned char pointer_table1_item2[28];

   unsigned char buffer_table0[3][28];

   //prepare pointer tables

   pointer_table0[0] = pointer_table0_item0;
   pointer_table0[1] = pointer_table0_item1;
   pointer_table0[2] = pointer_table0_item2;
   
   pointer_table1[0] = pointer_table1_item0;
   pointer_table1[1] = pointer_table1_item1;
   pointer_table1[2] = pointer_table1_item2;

   if(key_size_blocks <= 0)
      return -1;

   //reverse all required buffers

   reverse_byte_order_C8E3AA(dec_ptr_table_item0_rev, dec_ptr_table[0], key_size_bytes);
   reverse_byte_order_C8E3AA(dec_ptr_table_item1_rev, dec_ptr_table[1], key_size_bytes);
   reverse_byte_order_C8E3AA(dec_ptr_table_item2_rev, dec_ptr_table[3], key_size_bytes);

   reverse_byte_order_C8E3AA(pointer_table0[0], dec_ptr_table[4], key_size_bytes);
   reverse_byte_order_C8E3AA(pointer_table0[1], dec_ptr_table[5], key_size_bytes);

   reverse_byte_order_C8E3AA(secret_key_rev, secret_key, key_size_bytes);

   reverse_byte_order_C8E3AA(pointer_table1[0], dec_ptr_pair[0], key_size_bytes);
   reverse_byte_order_C8E3AA(pointer_table1[1], dec_ptr_pair[1], key_size_bytes);

   reverse_byte_order_C8E3AA(verify_ptr0_rev, ctx->ptr_4, key_size_bytes);
   reverse_byte_order_C8E3AA(verify_ptr1_rev, ctx->ptr_20, key_size_bytes);
   
   //check dec_ptr_table_item0_rev and derive something from it

   if(memory_is_all_zeroes(dec_ptr_table_item0_rev, key_size_blocks * 4))
      return -1;

   do_smth_with_hashes_2_C8E084(pointer_table1[0], pointer_table1[0], key_size_blocks, dec_ptr_table_item0_rev, key_size_blocks);
   do_smth_with_hashes_2_C8E084(pointer_table1[1], pointer_table1[1], key_size_blocks, dec_ptr_table_item0_rev, key_size_blocks);

   //verify ctx pointers

   if(memory_is_all_zeroes(verify_ptr0_rev, key_size_blocks * 4))
      return -1;

   if(memcmp(verify_ptr0_rev, dec_ptr_table_item2_rev, key_size_blocks * 4) >= 0)
      return -1;

   if(memory_is_all_zeroes(verify_ptr1_rev, key_size_blocks * 4))
      return -1;

   if(memcmp(verify_ptr1_rev, dec_ptr_table_item2_rev, key_size_blocks * 4) >= 0)
      return -1;

   //some hash magic

   do_smth_with_hashes_5_C8DBD4(verify_ptr1_rev, verify_ptr1_rev, dec_ptr_table_item2_rev, key_size_blocks);
   arbitrary_length_multiply_C8DF74(buffer_table0[1], secret_key_rev, key_size_blocks, verify_ptr1_rev, key_size_blocks);
   do_smth_with_hashes_2_C8E084(buffer_table0[0], buffer_table0[1], 2 * key_size_blocks, dec_ptr_table_item2_rev, key_size_blocks);
   arbitrary_length_multiply_C8DF74(buffer_table0[1], verify_ptr0_rev, key_size_blocks, verify_ptr1_rev, key_size_blocks);
   do_smth_with_hashes_2_C8E084(buffer_table0[1], buffer_table0[1], 2 * key_size_blocks, dec_ptr_table_item2_rev, key_size_blocks);
   do_smth_with_hashes_7_C8E420(pointer_table1, pointer_table0, pointer_table1, buffer_table0[0], buffer_table0[1], dec_ptr_table_item0_rev, dec_ptr_table_item1_rev, key_size_blocks);
   do_smth_with_hashes_2_C8E084(pointer_table1[0], pointer_table1[0], key_size_blocks, dec_ptr_table_item2_rev, key_size_blocks);

   //verify ctx pointer

   if(memcmp(pointer_table1[0], verify_ptr0_rev, key_size_blocks * 4) != 0)
      return -1;

   return 0;
}

// ctx contains 2 pointers of size 0x1C
// dec_ptr_pair - contains 2 pointers of size 0x1C
// dec_ptr_table - contains 6 pointers of size 0x1C
int verify_hashes_C8DBC0(verify_hash_ctx* ctx, unsigned char secret_key[0x1C], unsigned char* dec_ptr_pair[2], unsigned char* dec_ptr_table[6])
{
   return verify_hashes_C8DA14(ctx, secret_key, dec_ptr_pair, dec_ptr_table, 7, 0x1C);
}
