#include "SceMsifHashTableVerify.h"

int do_smth_with_hashes_1_C8E3AA(unsigned char *sha_224_0, unsigned char *sha_224_1, int key_size_bytes)
{
   int key_size_blocks; // r5
   unsigned __int8 *current_block; // r1
   int counter0; // r2
   int counter1; // r3

   key_size_blocks = key_size_bytes / 4;
   current_block = &sha_224_1[key_size_bytes];
   counter0 = 0;

   while ( counter0 < key_size_blocks )
   {
      *(int*)sha_224_0 = *(current_block - 1);
      sha_224_0 += 4;
      
      for ( counter1 = 0; --counter1 != -4; *((int*)sha_224_0 - 1) |= current_block[counter1 - 1] << -8 * counter1 )
      {
         ;
      }

      ++counter0;
      current_block -= 4;
   }

   return (int)sha_224_0;
}

int do_smth_with_hashes_4_C8EADC(unsigned char *sha_224_0, unsigned char *sha_224_1, int key_size_blocks)
{
   unsigned __int8 *block_ptr0; // r3
   unsigned __int8 *block_ptr1; // r1
   int block_val0_copy; // r5
   int block_val0; // t1
   int block_val1; // t1
   int result; // r0

   block_ptr0 = &sha_224_0[4 * key_size_blocks];
   block_ptr1 = &sha_224_1[4 * key_size_blocks];
   do
   {
      if ( block_ptr0 <= sha_224_0 )
         break;

      block_val0 = *((int *)block_ptr0 - 1);
      block_ptr0 -= 4;
      block_val0_copy = block_val0;
      block_val1 = *((int *)block_ptr1 - 1);
      block_ptr1 -= 4;
   }
   while ( block_val0_copy == block_val1 );
   
   if ( key_size_blocks <= 0 )
   {
      result = 0;
   }
   else
   {
      result = *(int *)block_ptr0 > *(int *)block_ptr1;
   }

   return result;
}

int sub_C8EB0A(unsigned char *buffer0, unsigned char *buffer1, int block_size, int byte_size_aligned)
{
   int byte_size_aligned_local; // r3
   unsigned int accumulator; // r5
   int block_counter; // r4
   unsigned int cur_block; // r6

   byte_size_aligned_local = byte_size_aligned & 0x3F;
   if ( byte_size_aligned_local )
   {
      accumulator = 0;
      for ( block_counter = 0; block_counter < block_size; ++block_counter )
      {
         cur_block = *(int *)&buffer1[4 * block_counter];
         *(int *)&buffer0[4 * block_counter] = accumulator | (cur_block << byte_size_aligned_local);
         accumulator = cur_block >> (0x20 - byte_size_aligned_local);
      }
   }
   else
   {
      while ( byte_size_aligned_local < block_size )
      {
         *(int *)&buffer0[4 * byte_size_aligned_local] = *(int *)&buffer1[4 * byte_size_aligned_local];
         ++byte_size_aligned_local;
      }
   }

   return (int)buffer0;
}

int sub_C8E01C(unsigned char *buffer0, unsigned char *buffer1, int block_size, int arg3)
{
   int byte_counter; // r4
   unsigned int v5; // r8
   int byte_size; // r10
   unsigned int v7; // r5
   unsigned int cur_block; // r2
   unsigned int v9; // r9
   int v10; // r6
   int v11; // r7
   unsigned int v12; // lr
   int v13; // r6

   if ( block_size > 0 )
   {
      byte_counter = 0;
      v5 = (unsigned int)arg3 >> 0x10;
      byte_size = 4 * block_size;
      v7 = 0;

      do
      {
         cur_block = *(int *)&buffer1[byte_counter];
         v9 = (unsigned __int16)arg3 * (unsigned __int16)cur_block;
         v10 = (unsigned __int16)arg3 * (cur_block >> 0x10);
         v11 = v5 * (unsigned __int16)cur_block;
         v12 = v10 + (v9 >> 0x10);
         v13 = v9 + ((v10 + v11) << 16);
         *(int *)&buffer0[byte_counter] = v13 + v7;
         byte_counter += 4;
         v7 = v5 * (cur_block >> 0x10)
            + (v12 >> 0x10)
            + ((v11 + (unsigned int)(unsigned __int16)v12) >> 0x10)
            + (((v13 | v7) & ~(v13 + v7) | v13 & v7) >> 0x1F);
      }
      while ( byte_counter != byte_size );

      *(int *)&buffer0[byte_counter] = v7;
   }

   return (int)buffer0;
}

int sub_C8E36E(unsigned char *buffer0, unsigned char *buffer1, unsigned char *buffer2, int block_size, int arg_0)
{
   unsigned __int8 *buffer0_local; // r12
   int result; // r0
   int byte_counter; // r4
   int block_counter; // r5
   unsigned int cur_block1; // r6
   int cur_block0; // lr
   int block_res; // r7

   buffer0_local = buffer0;
   result = arg_0 & 1;
   byte_counter = 0;
   block_counter = 0;

   while ( block_counter < block_size )
   {
      cur_block1 = *(int *)&buffer2[byte_counter];
      ++block_counter;
      cur_block0 = *(int *)&buffer1[byte_counter];
      block_res = cur_block0 - cur_block1 - result;
      *(int *)&buffer0_local[byte_counter] = block_res;
      result = ((~cur_block0 | cur_block1) & block_res | ~cur_block0 & cur_block1) >> 0x1F;
      byte_counter += 4;
   }

   return result;
}

int sub_C8EB4A(unsigned char *buffer0, unsigned char *buffer1, unsigned char *buffer2, int block_size, int arg_0)
{
   unsigned __int8 *buffer0_local; // r12
   int result; // r0
   int byte_counter; // r4
   int block_counter; // r5
   int cur_block0; // r6
   unsigned int cur_block1; // r7
   int block_res; // lr

   buffer0_local = buffer0;
   result = arg_0 & 1;
   byte_counter = 0;
   block_counter = 0;

   while ( block_counter < block_size )
   {
      cur_block0 = *(int *)&buffer1[byte_counter];
      ++block_counter;
      cur_block1 = *(int *)&buffer2[byte_counter];
      block_res = cur_block0 + cur_block1 + result;
      *(int *)&buffer0_local[byte_counter] = block_res;
      result = ((cur_block1 | cur_block0) & ~block_res | cur_block0 & cur_block1) >> 0x1F;
      byte_counter += 4;
   }

   return result;
}

int sub_C8E328(unsigned char *buffer0, unsigned char *buffer1, int key_size_blocks, int byte_size_aligned)
{
   int byte_size_aligned_local; // r3
   int key_size_blocks_local; // r5
   int byte_size; // r2
   int block_index0; // r4
   unsigned __int8 *cur_block0_ptr; // r1
   int accumulator; // r6
   unsigned __int8 *cur_block1_ptr; // r2
   unsigned int cur_block0; // r7

   byte_size_aligned_local = byte_size_aligned & 0x3F;

   if ( byte_size_aligned_local )
   {
      key_size_blocks_local = key_size_blocks - 1;
      byte_size = 4 * key_size_blocks;
      block_index0 = 0;
      cur_block0_ptr = &buffer1[byte_size];
      accumulator = 0;
      cur_block1_ptr = &buffer0[byte_size];
      while ( 1 )
      {
         block_index0 -= 4;
         if ( key_size_blocks_local < 0 )
            break;
         cur_block0 = *(int *)&cur_block0_ptr[block_index0];
         --key_size_blocks_local;
         buffer0 = (unsigned __int8 *)(cur_block0 >> byte_size_aligned_local);
         *(int *)&cur_block1_ptr[block_index0] = accumulator | (cur_block0 >> byte_size_aligned_local);
         accumulator = cur_block0 << (0x20 - byte_size_aligned_local);
      }
   }
   else
   {
      while ( byte_size_aligned_local < key_size_blocks )
      {
         *(int *)&buffer0[4 * byte_size_aligned_local] = *(int *)&buffer1[4 * byte_size_aligned_local];
         ++byte_size_aligned_local;
      }
   }

   return (int)buffer0;
}

int do_smth_with_hashes_2_C8E084(unsigned char *sha224_0, unsigned char *sha224_1, int key_size_blocks0, unsigned char *sha224_2, int key_size_blocks1)
{
   unsigned __int8 *sha224_1_local; // r10
   unsigned __int8 *sha224_0_local; // r11
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
   int block_counter0; // r1
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
   int block_size0; // r5
   int block_size1; // r4
   unsigned __int8 *sha224_2_copy; // ST08_4
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
   int xor0; // r10
   int block_counter4; // r3
   int block_size2; // [sp+Ch] [bp-444h]
   int block_size3; // [sp+10h] [bp-440h]
   int block_index0; // [sp+14h] [bp-43Ch]
   unsigned __int8 buffer0[260]; // [sp+18h] [bp-438h]
   unsigned __int8 buffer1[260]; // [sp+11Ch] [bp-334h]
   unsigned __int8 buffer2[516]; // [sp+220h] [bp-230h]
  
   sha224_1_local = sha224_1;
   sha224_0_local = sha224_0;
  
   if ( (unsigned int)(key_size_blocks0 - 1) <= 0x7F && (unsigned int)(key_size_blocks1 - 1) <= 0x3F )
   {
      block_counter3 = 0;
      block_size1_aligned = 0x20;
      byte_size1 = 0;

      do
      {
         ++block_counter3;
      
         if ( block_size1_aligned != 0x20 )
         {
           break;
         }

         val3 = *(int *)&sha224_1_local[4 * key_size_blocks0 + -4 * block_counter3];
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
      while ( block_counter3 != key_size_blocks0 );

      block_counter0 = 0;
      sha224_0 = (unsigned __int8 *)0x20;         // this is variable reusage
      byte_size0 = 0;

      do
      {
         ++block_counter0;

         if ( sha224_0 != (unsigned __int8 *)0x20 )
         {
            break;
         }

         val14 = *(int *)&sha224_2[4 * key_size_blocks1 + -4 * block_counter0];
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
         sha224_0 = (unsigned __int8 *)(val23 + val24 + 2 - (((unsigned int)(val22 << val24) >> 14) & ~((unsigned int)(val22 << val24) >> 15)));
         byte_size0 += (unsigned int)sha224_0;
      }
      while ( block_counter0 != key_size_blocks1 );

      block_size0 = key_size_blocks1 - (byte_size0 >> 5);// /0x20

      if ( key_size_blocks1 != byte_size0 >> 5 )  // /0x20
      {
         block_size1 = key_size_blocks0 - (byte_size1 >> 5);// /0x20
         block_size2 = key_size_blocks0 - (byte_size1 >> 5);// /0x20

         if ( block_size1 == block_size0 )
         {
            sha224_2_copy = sha224_2;
            sha224_0 = (unsigned __int8 *)do_smth_with_hashes_4_C8EADC(sha224_2, sha224_1_local, key_size_blocks0 - (byte_size1 >> 5));// /0x20
            sha224_2 = sha224_2_copy;
         }
         else
         {
            sha224_0 = (unsigned __int8 *)(block_size1 < block_size0);
         }

         block_counter1 = 0;

         if ( sha224_0 == (unsigned __int8 *)1 )
         {
            while ( block_counter1 < block_size1 )
            {
               *(int *)&sha224_0_local[4 * block_counter1] = *(int *)&sha224_1_local[4 * block_counter1];
               ++block_counter1;
            }

            for ( block_counter2 = 0; block_counter2 < key_size_blocks1 - block_size1; ++block_counter2 )
            {
               *(int *)&sha224_0_local[4 * block_size1 + 4 * block_counter2] = 0;
            }
         }
         else
         {
            byte_size0_aligned = byte_size0 & 0x1F;
            *(int *)&buffer0[4 * block_size0] = 0;

            sub_C8EB0A(buffer0, sha224_2, block_size0, byte_size0_aligned);

            if ( (unsigned __int8)(byte_size1 & 0x1F) < byte_size0_aligned )
            {
               *(int *)&buffer2[4 * block_size1] = *(int *)&sha224_1_local[4 * (block_size1 + 0x3FFFFFFF)] >> (32 - byte_size0_aligned);
            }
            else
            {
               *(int *)&buffer2[4 * block_size1] = 0;
            }

            block_size3 = block_size0 + 1;
            sub_C8EB0A(buffer2, sha224_1_local, block_size1, byte_size0_aligned);
            val1 = *(int *)&buffer0[4 * (block_size0 - 1)];
            val_ptr0 = &buffer2[4 * (block_size1 + 1)];
            block_index0 = -4 * block_size0;

            while ( block_size2 >= block_size0 )
            {
               val0 = *((int *)val_ptr0 - 1);
               val_ptr0 -= 4;
               val25 = val0;

               if ( val0 >= val1 )
               {
                  val26 = -1;
               }
               else
               {
                  val26 = *((int *)val_ptr0 - 1);
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

               sub_C8E01C(buffer1, buffer0, block_size0, val26);

               for ( xor0 = sub_C8E36E(&val_ptr0[block_index0], &val_ptr0[block_index0], buffer1, block_size3, 0);
                     xor0;
                     xor0 ^= sub_C8EB4A(&val_ptr0[block_index0], &val_ptr0[block_index0], buffer0, block_size3, 0) )
               {
                  ;
               }

               --block_size2;
            }

            sha224_0 = (unsigned __int8 *)sub_C8E328(sha224_0_local, buffer2, key_size_blocks1, byte_size0_aligned);

            for ( block_counter4 = 0; block_counter4 < key_size_blocks1 - block_size0; ++block_counter4 )
            {
               *(int *)&sha224_0_local[4 * block_size0 + 4 * block_counter4] = 0;
            }
         }
      }
   }

   return (int)sha224_0;
}

int do_smth_with_hashes_3_C8E3EE(unsigned char *sha_224_0, unsigned char *sha_224_1, int key_size_blocks)
{
   int block_counter; // r3
   int result; // r0

   block_counter = key_size_blocks;

   do
   {
      --block_counter;
   }
   while ( block_counter + 1 > 0 && !*(int*)&sha_224_0[4 * block_counter]);

   if ( block_counter >= 0 )
   {
      result = (unsigned int)(do_smth_with_hashes_4_C8EADC(sha_224_1, sha_224_0, key_size_blocks) - 1) <= 0;
   }
   else
   {
      result = 0;
   }

   return result;
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
         res0 = sub_C8EB4A(buffer2, buffer2, sha_224_1_local, key_size_blocks_local, buffer1[0] & 1);
         res1 = sub_C8E36E(buffer3, buffer3, sha_224_2_local, key_size_blocks_local, 0);
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
         res2 = sub_C8EB4A(buffer4, buffer4, sha_224_1_local, key_size_blocks_local, check0);
         res3 = sub_C8E36E(buffer5, buffer5, sha_224_2_local, key_size_blocks_local, check0);
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

   if ( do_smth_with_hashes_4_C8EADC(buffer0, buffer1, key_size_blocks_local) )
   {
      sub_C8E36E(buffer0, buffer0, buffer1, key_size_blocks_local, 0);
      sub_C8E36E(buffer4, buffer4, buffer2, key_size_blocks_local + 1, 0);
      sub_C8E36E(buffer5, buffer5, buffer3, key_size_blocks_local + 1, 0);
   }
   else
   {
      sub_C8E36E(buffer1, buffer1, buffer0, key_size_blocks_local, 0);
      sub_C8E36E(buffer2, buffer2, buffer4, key_size_blocks_local + 1, 0);
      sub_C8E36E(buffer3, buffer3, buffer5, key_size_blocks_local + 1, 0);
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
         res4 = sub_C8EB4A(buffer5, buffer5, sha_224_2_local, key_size_blocks_local, 0)
               + *&buffer5[4 * key_size_blocks_local];

         *&buffer5[4 * key_size_blocks_local] = res4;
      }
      while ( res4 );
   }
   else
   {
      while ( *&buffer5[4 * key_size_blocks_local] || !do_smth_with_hashes_4_C8EADC(sha_224_2_local, buffer5, key_size_blocks_local) )
      {
         *&buffer5[4 * key_size_blocks_local] -= sub_C8E36E(buffer5, buffer5, sha_224_2_local, key_size_blocks_local, 0);
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

int do_smth_with_hashes_6_C8DF74(unsigned char *sha_224_0, unsigned char *sha_224_1, int key_size_blocks0, unsigned char *sha_224_2, int key_size_blocks1)
{
   unsigned __int8 *sha_224_1_local; // r12
   int key_size_blocks0_local; // r5
   int block_size0; // r10
   int block_counter0; // r3
   int block_counter2; // r4
   unsigned __int8 *block_ptr0; // r11
   int block_ptr1; // r3
   int block_counter1; // r9
   unsigned __int8 *sha_224_1_local_copy; // ST0C_4
   int block_size1; // [sp+8h] [bp-340h]
   unsigned __int8 *sha_224_0_local; // [sp+10h] [bp-338h]
   unsigned __int8 *sha_224_2_local; // [sp+14h] [bp-334h]
   char buffer0[260]; // [sp+18h] [bp-330h]
   char buffer1[512]; // [sp+11Ch] [bp-22Ch]

   sha_224_2_local = sha_224_2;
   sha_224_1_local = sha_224_1;
   key_size_blocks0_local = key_size_blocks0;
   sha_224_0_local = sha_224_0;

   if ( (unsigned int)(key_size_blocks0 - 1) <= 0x3F && (unsigned int)(key_size_blocks1 - 1) <= 0x3F )
   {
      block_size0 = key_size_blocks0 + 1;

      for ( block_counter0 = 0; ; ++block_counter0 )
      {
         block_counter2 = 0;
         block_size1 = key_size_blocks0 + key_size_blocks1;

         if ( block_counter0 >= key_size_blocks0 + key_size_blocks1 )
            break;

         *(int *)&buffer1[4 * block_counter0] = 0;
      }

      do
      {
         block_ptr0 = (unsigned __int8 *)&buffer1[4 * block_counter2];
         block_ptr1 = *(int *)&sha_224_2_local[4 * block_counter2];
         block_counter1 = 0;
         sha_224_1_local_copy = sha_224_1_local;
         ++block_counter2;
         sub_C8E01C((unsigned __int8 *)buffer0, sha_224_1_local, key_size_blocks0_local, block_ptr1);
         sha_224_0 = (unsigned __int8 *)sub_C8EB4A(block_ptr0, block_ptr0, (unsigned __int8 *)buffer0, block_size0, 0);
         sha_224_1_local = sha_224_1_local_copy;
      }
      while ( block_counter2 != key_size_blocks1 );

      do
      {
         *(int *)&sha_224_0_local[4 * block_counter1] = *(int *)&buffer1[4 * block_counter1];
         ++block_counter1;
      }
      while ( block_counter1 < block_size1 );
   }

   return (int)sha_224_0;
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
         sub_C8E01C(data30, buffer3_local, key_size_blocks, (*data00 + *buffer2_local * *buffer1_local) * arg4);
         buffer1_val = *buffer1_local;
         buffer1_local += 4;
         sub_C8E01C(data20, buffer2_local, key_size_blocks, buffer1_val);
         res0 = sub_C8EB4A(data30, data30, data20, key_size_blocks + 1, 0);
         res1 = sub_C8EB4A(data00, data01, data31, key_size_blocks, (*data00 | *data30) != 0) + res0;
         *&data00[4 * key_size_blocks] = res1;
         block_counter0 = block_counter1 + 1;
      }
      while ( block_counter1 + 1 != key_size_blocks );

      if ( res1 || (buffer0 = (unsigned char *)do_smth_with_hashes_4_C8EADC(buffer3_local, data00, key_size_blocks)) == 0 )
      {
         buffer0 = (unsigned char *)sub_C8E36E(data00, data00, buffer3_local, key_size_blocks, 0);
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
         sub_C8E01C(data20, buffer3_local, block_size_arg1, block_val0 * arg_4);
         block_val1 = *&data20[4 * block_size_arg1];
         *&data10[4 * block_counter1++] = sub_C8EB4A(block_ptr1, block_ptr1, data20, block_size_arg1, 0) + block_val1;
      }
      while ( block_counter1 != block_size_arg1 );

      if ( sub_C8EB4A(&data31[4 * block_size_arg1], &data31[4 * block_size_arg1], data10, block_size_arg1, 0)
         || (buffer0 = (unsigned char *)do_smth_with_hashes_4_C8EADC(buffer3_local, &data31[4 * block_size_arg1], block_size_arg1)) == 0 )
      {
         buffer0 = (unsigned char *)sub_C8E36E(&data31[4 * block_size_arg1], &data31[4 * block_size_arg1], buffer3_local, block_size_arg1, 0);
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
                     ptr_table0 = (unsigned __int8 **)(sub_C8EB4A(buffer4_local, buffer4_local, buffer1_local_ptr, key_size_blocks, 0) << 31);

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

int sub_C8E95C(unsigned char **ptr_table0, unsigned char **ptr_table1, unsigned char *buffer0, unsigned char **ptr_table2, unsigned char **ptr_table3, unsigned char *buffer1, unsigned char *buffer2, unsigned int key_size_blocks1, int arg_10)
{
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

   /*
   if ( cookie != *(_DWORD *)cookie_address_C8EA0C )
      SceMsif_SceSysclibForDriver__imp___stack_chk_fail_b997493d(ptr_table0);
   */
   return (int)ptr_table0;
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

struct locals_C8DA14
{
  unsigned __int8 data0[28];
  unsigned __int8 data1[28];
  unsigned __int8 data2[28];
};

int verify_hashes_C8DA14(verify_hash_ctx *ctx, unsigned char secret_key[28], unsigned char *dec_ptr_pair[2], unsigned char *dec_ptr_table[6], int key_size_blocks, int key_size_bytes)
{
   //order of stack variables can be important here because of buffers!

   unsigned __int8 **dec_ptr_table_local; // r7
   unsigned __int8 **dec_ptr_pair_local; // r9
   unsigned __int8 *secret_key_local; // r11
   verify_hash_ctx *ctx_local; // r8
   unsigned __int8 *dec_ptr0; // r1
   int counter0; // r3
   int counter1; // r0
   int result; // r0
   unsigned __int8 *sha224_i3_ptr; // [sp+10h] [bp-1E8h]
   unsigned __int8 *sha224_i4_ptr; // [sp+14h] [bp-1E4h]
   char *sha224_unused0_ptr; // [sp+18h] [bp-1E0h]
   unsigned __int8 *sha224_i6_ptr; // [sp+1Ch] [bp-1DCh]
   unsigned __int8 *sha224_i7_ptr; // [sp+20h] [bp-1D8h]
   char *sha224_unused1_ptr; // [sp+24h] [bp-1D4h]
   unsigned __int8 sha224_i0[28]; // [sp+28h] [bp-1D0h]
   unsigned __int8 sha224_i1[28]; // [sp+44h] [bp-1B4h]
   unsigned __int8 sha224_i2[28]; // [sp+60h] [bp-198h]
   unsigned __int8 sha224_i8[28]; // [sp+7Ch] [bp-17Ch]
   unsigned __int8 sha224_i9[28]; // [sp+98h] [bp-160h]
   unsigned __int8 sha224_i5[28]; // [sp+B4h] [bp-144h]
   unsigned __int8 sha224_i3[28]; // [sp+D0h] [bp-128h]
   unsigned __int8 sha224_i4[28]; // [sp+ECh] [bp-10Ch]
   char sha224_unused0[28]; // [sp+108h] [bp-F0h]
   unsigned __int8 sha224_i6[28]; // [sp+124h] [bp-D4h]
   unsigned __int8 sha224_i7[28]; // [sp+140h] [bp-B8h]
   char sha224_unused1[28]; // [sp+15Ch] [bp-9Ch]
   locals_C8DA14 sha224_n; // [sp+178h] [bp-80h]

   dec_ptr_table_local = dec_ptr_table;
   dec_ptr_pair_local = dec_ptr_pair;
   secret_key_local = secret_key;
   ctx_local = ctx;
   dec_ptr0 = *dec_ptr_table;
  
   sha224_i3_ptr = sha224_i3;
   sha224_i4_ptr = sha224_i4;
   sha224_unused0_ptr = sha224_unused0;
   sha224_i6_ptr = sha224_i6;
   sha224_i7_ptr = sha224_i7;
   sha224_unused1_ptr = sha224_unused1;

   do_smth_with_hashes_1_C8E3AA(sha224_i0, dec_ptr0, key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i1, dec_ptr_table_local[1], key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i2, dec_ptr_table_local[3], key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i3, dec_ptr_table_local[4], key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i4, dec_ptr_table_local[5], key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i5, secret_key_local, key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i6, *dec_ptr_pair_local, key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i7, dec_ptr_pair_local[1], key_size_bytes);

   // tricky check on zero vector

   counter0 = key_size_blocks;

   do
   {
      --counter0;
   }
   while ( counter0 + 1 > 0 && !*(int*)&sha224_i0[4 * counter0] );
   if ( counter0 < 0 )
   {
      return -1;
   }

   do_smth_with_hashes_2_C8E084(sha224_i6_ptr, sha224_i6_ptr, key_size_blocks, sha224_i0, key_size_blocks);
   do_smth_with_hashes_2_C8E084(sha224_i7_ptr, sha224_i7_ptr, key_size_blocks, sha224_i0, key_size_blocks);
   do_smth_with_hashes_1_C8E3AA(sha224_i8, ctx_local->ptr_4, key_size_bytes);
   do_smth_with_hashes_1_C8E3AA(sha224_i9, ctx_local->ptr_20, key_size_bytes);
  
   if ( !do_smth_with_hashes_3_C8E3EE(sha224_i8, sha224_i2, key_size_blocks) || !do_smth_with_hashes_3_C8E3EE(sha224_i9, sha224_i2, key_size_blocks) )
   {
      return -1;
   }

   do_smth_with_hashes_5_C8DBD4(sha224_i9, sha224_i9, sha224_i2, key_size_blocks);
   do_smth_with_hashes_6_C8DF74(&sha224_n.data0[4 * key_size_blocks], sha224_i5, key_size_blocks, sha224_i9, key_size_blocks); // that would be offset to data1 (because key_size_blocks is fixed)
   do_smth_with_hashes_2_C8E084(sha224_n.data0, &sha224_n.data0[4 * key_size_blocks], 2 * key_size_blocks, sha224_i2, key_size_blocks); // that would be offset to data0 // that would be offset to data1 (because key_size_blocks is fixed)
   do_smth_with_hashes_6_C8DF74(&sha224_n.data0[4 * key_size_blocks], sha224_i8, key_size_blocks, sha224_i9, key_size_blocks); // that would be offset to data1 (because key_size_blocks is fixed)
   do_smth_with_hashes_2_C8E084(&sha224_n.data0[4 * key_size_blocks], &sha224_n.data0[4 * key_size_blocks], 2 * key_size_blocks, sha224_i2, key_size_blocks); // that would be offset to data1 (because key_size_blocks is fixed) // that would be offset to data1 (because key_size_blocks is fixed)
   do_smth_with_hashes_7_C8E420(&sha224_i6_ptr, &sha224_i3_ptr, &sha224_i6_ptr, sha224_n.data0, &sha224_n.data0[4 * key_size_blocks], sha224_i0, sha224_i1, key_size_blocks); // that would be offset to data0 // that would be offset to data1 (because key_size_blocks is fixed)
   do_smth_with_hashes_2_C8E084(sha224_i6_ptr, sha224_i6_ptr, key_size_blocks, sha224_i2, key_size_blocks);
  
   // block wise equality check
   for ( counter1 = 0; counter1 < key_size_blocks && *(int*)&sha224_i6_ptr[4 * counter1] == *(int*)&sha224_i8[4 * counter1]; ++counter1 )
   {
      ;
   }

   if ( key_size_blocks > 0 )
   {
      result = key_size_blocks - counter1;
      if ( result )
         result = -1;
   }
   else
   {
      result = -1;
   }

   return result;
}

int verify_hashes_C8DBC0(verify_hash_ctx* ctx, unsigned char secret_key[0x1C], unsigned char* dec_ptr_pair[2], unsigned char* dec_ptr_table[6])
{
   return verify_hashes_C8DA14(ctx, secret_key, dec_ptr_pair, dec_ptr_table, 7, 0x1C);
}
