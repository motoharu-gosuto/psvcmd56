#include "edigest.h"

#include <stdlib.h>
#include <string>

//reversed code resembles implementation of sha256 very much
//https://github.com/B-Con/crypto-algorithms/blob/master/sha256.c

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

//probably sha256_transform
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

//probably sha256_update
void process_blocks(const unsigned int* work_buffer, unsigned int* digest_permu)
{
   int res_item_ctr = 0;

   do
   {
      unsigned int carry;

      block_function(digest_permu[9], digest_permu[10], digest_permu[11], digest_permu[12], 
                     work_buffer[res_item_ctr], dword_4054F4[res_item_ctr], 
                     digest_permu[0], digest_permu[14], digest_permu[15], digest_permu[13],
                     &digest_permu[13], &digest_permu[9]);

      block_function(digest_permu[10], digest_permu[11], digest_permu[12], digest_permu[13], 
                     work_buffer[res_item_ctr + 1], dword_4054F4[res_item_ctr + 1],
                     digest_permu[9], digest_permu[15], digest_permu[0], digest_permu[14],
                     &digest_permu[14], &digest_permu[10]);

      block_function(digest_permu[11], digest_permu[12], digest_permu[13], digest_permu[14], 
                     work_buffer[res_item_ctr + 2], dword_4054F4[res_item_ctr + 2],
                     digest_permu[10], digest_permu[0], digest_permu[9], digest_permu[15],
                     &digest_permu[15], &digest_permu[11]);

      block_function(digest_permu[12], digest_permu[13], digest_permu[14], digest_permu[15], 
                     work_buffer[res_item_ctr + 3], dword_4054F4[res_item_ctr + 3], 
                     digest_permu[11], digest_permu[9], digest_permu[10], digest_permu[0], 
                     &carry, &digest_permu[12]);
      
      block_function(digest_permu[13], digest_permu[14], digest_permu[15], carry, 
                     work_buffer[res_item_ctr + 4], dword_4054F4[res_item_ctr + 4], 
                     digest_permu[12], digest_permu[10], digest_permu[11], digest_permu[9], 
                     &digest_permu[9], &digest_permu[13]);

      block_function(digest_permu[14], digest_permu[15], carry, digest_permu[9], 
                     work_buffer[res_item_ctr + 5], dword_4054F4[res_item_ctr + 5], 
                     digest_permu[13], digest_permu[11], digest_permu[12], digest_permu[10], 
                     &digest_permu[10], &digest_permu[14]);
      
      block_function(digest_permu[15], carry, digest_permu[9], digest_permu[10], 
                     work_buffer[res_item_ctr + 6], dword_4054F4[res_item_ctr + 6],
                     digest_permu[14], digest_permu[12], digest_permu[13], digest_permu[11], 
                     &digest_permu[11], &digest_permu[15]);
      
      block_function(carry, digest_permu[9], digest_permu[10], digest_permu[11], 
                     work_buffer[res_item_ctr + 7], dword_4054F4[res_item_ctr + 7],
                     digest_permu[15], digest_permu[13], digest_permu[14], digest_permu[12], 
                     &digest_permu[12], &digest_permu[0]);

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

struct ctx_40A64C
{
   int state0[8];
   int unk20;
   __int16 unk24;
   __int16 unk26;
   int unk28;
   int unk2C;
   int unk30;
   int unk34;
   int unk38;
   int unk3C;
   int unk40;
   int unk44;
   int unk48;
   int unk4C;
   int unk50;
   int unk54;
   int unk58;
   int unk5C;
   int unk60;
   int unk64;
   int unk68;
   int unk6C;
   char digest2[32];
};

int __cdecl sha256_init_413D84(ctx_40A64C *ctx)
{
   signed int result;

   result = 0x80480500;
   if ( ctx )
   {
      ctx->state0[0] = 0x6A09E667;
      result = 0;
      ctx->state0[1] = 0xBB67AE85;
      ctx->state0[2] = 0x3C6EF372;
      ctx->state0[3] = 0xA54FF53A;
      ctx->state0[4] = 0x510E527F;
      ctx->state0[5] = 0x9B05688C;
      ctx->state0[6] = 0x1F83D9AB;
      ctx->state0[7] = 0x5BE0CD19;
      ctx->unk24 = 0;
      ctx->unk26 = 0;
      ctx->unk28 = 0;
      ctx->unk2C = 0;
   }

   return result;
}

struct control_info_type4_t
{
   int type;
   int size;
   __int64 next;
   char digest1[20];
   char digest2[32];
   char padding[12];
};

struct ctx_40A64C_arg
{
   int unk0;
   int unk4;
   char *filepath;
};

int read_file_in_blocks_409BDC(int fd, char *buffer, unsigned int size)
{
   return 0;
}

int maybe_sha256_update_414004(ctx_40A64C *ctx, char *file_data, int size)
{
   return 0;
}

int maybe_sha256_final_413DF4(ctx_40A64C *ctx, char *digest2)
{
   return 0;
}

signed int sub_40A64C(int a1, ctx_40A64C_arg *a3, control_info_type4_t *control_info)
{
   char *v3; // ebx
   int type; // eax
   int v5; // ecx
   unsigned __int64 v6; // kr00_8
   int fd; // eax
   signed int error_code; // edx
   int fd1; // ebx
   char *v10; // eax
   int read_bytes; // eax
   char *v13; // edx
   signed int v14; // eax
   ctx_40A64C ctx; // [esp+0h] [ebp-100A8h]
   char file_data[65536]; // [esp+90h] [ebp-10018h]
   int v17; // [esp+10090h] [ebp-18h]
   char *v18; // [esp+10094h] [ebp-14h]
   char *v19; // [esp+10098h] [ebp-10h]
   int v20; // [esp+1009Ch] [ebp-Ch]

   //sub_4047B0(0x1009Cu, a1, v20);

   control_info->type = 4;
   control_info->size = 0x50;
   control_info->next = 0i64;

  /*
   LOBYTE(v3) = get_endianness_409C7C();
   if ( (_BYTE)v3 != (unsigned __int8)get_endianness_40CB9C() )
   {
      type = maybe_flip_bytes_409CAC(control_info->type);
      v5 = control_info->size;
      control_info->type = type;
      v3 = *(char **)&file_data[65532];
      control_info->size = maybe_flip_bytes_409CAC(v5);
      v6 = control_info->next;
      v17 = v6 >> 32;
      *(_DWORD *)&file_data[65532] = v6;
      control_info->next = maybe_flip_bytes_409CDC(*(__int64 *)&file_data[65532]);
   }
  */

   /*
   v19 = v3;
   v18 = v3;

   fd = open(a3->filepath, 0x8000);
   error_code = 1;
   fd1 = fd;
   if ( fd < 0 )
      return error_code;
   */

   memset(control_info->digest2, 0, 0x20);

   v10 = (char *)sha256_init_413D84(&ctx);

   error_code = 1;

   if ( !v10 )
   {
      /*
      while ( 1 )
      {
         v19 = v10;
      */
         read_bytes = read_file_in_blocks_409BDC(fd1, file_data, 0x10000u);
      /*
         if ( !read_bytes )
            break;
      */

         v19 = v13;
         v10 = (char *)maybe_sha256_update_414004(&ctx, file_data, read_bytes);
      /*
         if ( v10 )
            return 1;
      }
      */

      v19 = file_data;
      v18 = file_data;
      v14 = maybe_sha256_final_413DF4(&ctx, control_info->digest2);
      error_code = 1;

      /*
      if ( !v14 )
      {
         *(_DWORD *)control_info->digest1 = e_static_digest0_405608;
         *(_DWORD *)&control_info->digest1[4] = e_static_digest0_40560C;
         *(_DWORD *)&control_info->digest1[8] = e_static_digest0_405610;
         *(_DWORD *)&control_info->digest1[0xC] = e_static_digest0_405614;
         *(_DWORD *)&control_info->digest1[0x10] = e_static_digest0_405618;
         *(_DWORD *)&control_info->padding[4] = 0;
         *(_DWORD *)&control_info->padding[8] = 0;
         *(_DWORD *)control_info->padding = 0;
         close(fd1);
         error_code = 0;
      }
      */
   }
  
   return error_code;
}