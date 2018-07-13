#include <cstdint>
#include <string.h>
#include <iostream>

#include "SceMsif.h"
#include "SceMsifKeys.h"

#include "SceSblSsMgr.h"
#include "SceSblSsMgrDmac5Layer.h"
#include "SceKernelSuspend.h"
#include "SceSblSsSmComm.h"
#include "SceSysroot.h"
#include "SceKernelUtils.h"

#include "F00D/IF00DService.h"
#include "F00D/F00DUtils.h"

//-------- memory card communication --------

typedef struct SceMsif_subctx
{
   char error_code[4];
   unsigned char resp_buffer0[0x1C];
   unsigned char resp_buffer1[0x1C];
}SceMsif_subctx;

#define MS_TPC_48 0x48
#define MS_TPC_49 0x49
#define MS_TPC_4A 0x4A
#define MS_TPC_4B 0x4B

//[NO NEED TO REVERSE]
int ms_execute_ex_set_cmd_write_short_data_C8A3A8(SceMsif_subctx *subctx, int cmd, int size, const char* source, int delay)
{
   return 0;
}

//[NO NEED TO REVERSE]
int ms_execute_ex_set_cmd_read_short_data_C8A448(SceMsif_subctx *subctx, int cmd, int size, char* dest, int delay)
{
   return 0;
}

//[NO NEED TO REVERSE]
int ms_execute_ex_set_cmd_C8A4E8(SceMsif_subctx *subctx, int cmd, SceMsif_subctx *subctx2, int delay)
{
   return 0;
}

//-------- f00d communication --------

int id_B9F9BC = 0;

unsigned char ctx_130_part_C904A8[0x90] =
{
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x80, 0x09, 0x80, 0x03, 0x00, 0x00, 0xC3, 0x00, 0x00, 0x00, 0x80, 0x09, 0x80, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//[REVERSED]
int food_start_F00D_communication_rmauth_sm_C8D880()
{
   /*
   elf_info_pair self;
   self.size = 0xC;
   self.elf_data = 0;
   self.elf_size = 0;
   
   if (SceSysrootForKernel_sceSysrootGetSelfInfoForKernel_f10ab792(1, &self) < 0)
      return 0x800F0016;
   */

   std::string service_name;
   if(SceSysrootForKernel_sceSysrootGetSelfInfoForKernel_Emu(1, service_name) < 0)
      return 0x800F0016;

   sm_comm_ctx_130 ctx_130;
   
   memset(&ctx_130, 0, 0x130u);
   memcpy(ctx_130.data0, ctx_130_part_C904A8, 0x90u);

   ctx_130.pathId = 2;
   ctx_130.self_type = 2;

   return SceSblSmCommForKernel_sceSblSmCommStartSm_Emu(service_name, &id_B9F9BC);
   //return SceSblSmCommForKernel_sceSblSmCommStartSm1_039c73b1(0, self.elf_data, self.elf_size, 0, &ctx_130, &id_B9F9BC);
}

//[REVERSED]
int execute_f00d_command_1_rmauth_sm_C8D908(unsigned int* f00d_data)
{
   if(f00d_data == 0)
      return 0x800F1916;

   SceKernelSuspendForDriver_call_func_008B808C_atomic_inc_008BF3FC_4df40893(0);
   
   int res0 = food_start_F00D_communication_rmauth_sm_C8D880();
   if (res0 != 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
      return res0;
   }

   SceSblSmCommMsifData_1 data;

   int f00d_resp = 0;
      
   //if (SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(id_B9F9BC, RM_AUTH_SM_SERVICE_1, &f00d_resp, &data, 0x20))
   //   f00d_resp = 0x800F1928;
   if(SceSblSmCommForKernel_sceSblSmCommCallFunc_Emu(id_B9F9BC, RM_AUTH_SM_SERVICE_1, &f00d_resp, &data, 0x20))
      f00d_resp = 0x800F1928;

   std::pair<int, int> res;

   //int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(id_B9F9BC, &res);
   int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_Emu(id_B9F9BC);
   if (res1 != 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
      return res1;
   }
   
   *f00d_data = *(unsigned int*)(&data.data[0x10]);

   SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
   return f00d_resp;
}

//[REVERSED]
int execute_f00d_command_2_rmauth_sm_C8D988(unsigned const char input[0x10])
{
   if (input == 0)
      return 0x800F1916;

   SceKernelSuspendForDriver_call_func_008B808C_atomic_inc_008BF3FC_4df40893(0);
         
   int res0 = food_start_F00D_communication_rmauth_sm_C8D880();
   if (res0 != 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
      return res0;
   }

   SceSblSmCommMsifData_2 data;
   memcpy(data.data, input, 0x10);

   int f00d_resp = 0;

   //if (SceSblSmCommForKernel_sceSblSmCommCallFunc_db9fc204(id_B9F9BC, RM_AUTH_SM_SERVICE_2, &f00d_resp, &data, 0x20))
   //   f00d_resp = 0x800F1928;

   if (SceSblSmCommForKernel_sceSblSmCommCallFunc_Emu(id_B9F9BC, RM_AUTH_SM_SERVICE_2, &f00d_resp, &data, 0x20))
      f00d_resp = 0x800F1928;
   
   std::pair<int, int> res;

   //int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(id_B9F9BC, &res);
   int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_Emu(id_B9F9BC);
   if (res1 != 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
      return res1;
   }
   
   SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
   return f00d_resp;
}

//--------

void byte_array_to_uint64_t(unsigned char* x, std::uint64_t* y)
{
   std::uint64_t c0 = (((std::uint64_t)x[0]) << 56);
   std::uint64_t c1 = (((std::uint64_t)x[1]) << 48);
   std::uint64_t c2 = (((std::uint64_t)x[2]) << 40);
   std::uint64_t c3 = (((std::uint64_t)x[3]) << 32);
   std::uint64_t c4 = (((std::uint64_t)x[4]) << 24);
   std::uint64_t c5 = (((std::uint64_t)x[5]) << 16);
   std::uint64_t c6 = (((std::uint64_t)x[6]) <<  8);
   std::uint64_t c7 = (((std::uint64_t)x[7]) <<  0);
   *y = c0 | c1 | c2 | c3 | c4 | c5 | c6 | c7;
}

void uint64_t_to_byte_array(std::uint64_t x, unsigned char* y)
{
   (y)[0] = (unsigned char)((x) >> 56); 
   (y)[1] = (unsigned char)((x) >> 48); 
   (y)[2] = (unsigned char)((x) >> 40);
   (y)[3] = (unsigned char)((x) >> 32);
   (y)[4] = (unsigned char)((x) >> 24); 
   (y)[5] = (unsigned char)((x) >> 16);
   (y)[6] = (unsigned char)((x) >> 8); 
   (y)[7] = (unsigned char)(x);
}

//[REVERSED]
int w_dmac5_command_0x41_derive_iv_tweak_C8D2F0(unsigned char* tweak_seed, unsigned char* tweak_key0, unsigned char* tweak_key1)
{
   //read about 0x1B xor here:
   //https://en.wikipedia.org/wiki/Finite_field_arithmetic#Rijndael%27s_finite_field

   //first round - multiply by 2

   std::uint64_t i64_0;
   byte_array_to_uint64_t(tweak_seed, &i64_0);

   std::uint64_t mul64_0 = i64_0 * 2;

   uint64_t_to_byte_array(mul64_0, tweak_key0);

   tweak_key0[7] = ((tweak_seed[0] & 0x80) > 0) ? (tweak_key0[7] ^ 0x1B) 
                                                :  tweak_key0[7];
   
   //second round - multiply by 2

   std::uint64_t i64_1;
   byte_array_to_uint64_t(tweak_key0, &i64_1);

   std::uint64_t mul64_1 = i64_1 * 2;

   uint64_t_to_byte_array(mul64_1, tweak_key1);

   tweak_key1[7] = ((tweak_key0[0] & 0x80) > 0) ? (tweak_key1[7] ^ 0x1B) 
                                                :  tweak_key1[7];

   return 0;
}

//looks like this function is doing 3-DES CBC with ciphertext stealing
//I am still not sure how tweak keys are calculated
//it looks like to be related to a multiplication by 2 in Galois Field GF(2^64)

//result of this function looks like to be IV of the 3DES

//this function executes dmac5 0x41 command under the hood

//[REVERSED]
int w_dmac5_3des_cbc_cts_iv_C8D2F0(unsigned int* result, const unsigned int* data, int size)
{
   //calculate tweak keys

   unsigned char tweak_seed[8];
   memset(tweak_seed, 0, 8);

   unsigned char tweak_seed_enc[8];

   int enc_res0 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf((unsigned char*)tweak_seed, tweak_seed_enc, 8, 0x1C, 0xC0, 1);
   if(enc_res0 < 0)
      return enc_res0;

   unsigned int tweak_key0[2];
   unsigned int tweak_key1[2];
   int r0 = w_dmac5_command_0x41_derive_iv_tweak_C8D2F0(tweak_seed_enc, (unsigned char*)tweak_key0, (unsigned char*)tweak_key1);

   //---- process data in blocks of 8 bytes (calculate 3-DES CBC)----

   if(size <= 8)
      return r0;

   const unsigned int* current_ptr = data;
   int current_size = size;

   int IV[2];
   IV[0] = 0;
   IV[1] = 0;

   while(current_size > 8)
   {
      //perform xor operation with input data
      int current_round[2];
      current_round[0] = current_ptr[0] ^ IV[0];
      current_round[1] = current_ptr[1] ^ IV[1];

      current_ptr = current_ptr + 2;

      //perform encryption, write back to round_buffer
      int enc_res1 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf((unsigned char*)current_round, (unsigned char*)IV, 8, 0x1C, 0xC0, 1);
      if(enc_res1 < 0)
         break;

      current_size = current_size - 8;
   }

   //---- process tail of the data (looks like with ciphertext stealing) ----

   int IV_mod[2];
   int tail_data[2];

   if(current_size == 8)
   {
      //write last chunk of data
      tail_data[0] = current_ptr[0];
      tail_data[1] = current_ptr[1];
      
      //perform xor operation of current buffer with some data
      IV_mod[0] = IV[0] ^ tweak_key0[0];
      IV_mod[1] = IV[1] ^ tweak_key0[1];
   }
   else
   {
      //write last chunk of data
      tail_data[0] = current_ptr[0];
      tail_data[1] = current_ptr[1];
      
      //pad the tail with zeroes
      memset(((char*)tail_data) + current_size, 0, 8 - current_size);
      
      //perform xor operation of current buffer with some data
      IV_mod[0] = IV[0] ^ tweak_key1[0];
      IV_mod[1] = IV[1] ^ tweak_key1[1];
   }

   //perform xor operation with input data
   int final_round[2];
   final_round[0] = tail_data[0] ^ IV_mod[0];
   final_round[1] = tail_data[1] ^ IV_mod[1];

   //perform encryption - store result
   int enc_res2 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf((unsigned char*)final_round, (unsigned char*)result, 8, 0x1C, 0xC0, 1);
   if(enc_res2 < 0)
      return enc_res2;

   return 0;
}

//=====================================================
//=====================================================
//=====================================================
//=====================================================
//=====================================================

int memxor(unsigned char* dest, const unsigned char* src1, const unsigned char* src2, int size)
{
   for(int i = 0; i < size; i++)
      dest[i] = src1[i] ^ src2[i];
   return 0;
}

//----------------

// flag that shows that static sha224 table is decrypted 
int g_00B9F9B8 = 0;

unsigned char g_zero_array_C90498[0x10] = 
{
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

//decrypted table of sha224 hashes
unsigned char g_00B9F8D8[0x1C * 8] = {0};

//[REVERSED]
int decrypt_sha224_table_get_key_internal_C8D09C(unsigned char* aes_key)
{
   //try to decrypt aes key 1

   portability_input_data dec_input1;
   dec_input1.size = 0x20;
   memcpy(dec_input1.data_1, g_dec_input_C90370, 0x10);
   memcpy(dec_input1.data_2, g_dec_input_C90370 + 0x10, 0x10);

   portability_output_data dec_output;
   dec_output.size = 0x20;
   memset(dec_output.key_name, 0, 0x10);
   memset(dec_output.aes_key, 0, 0x10);

   int kget_res1 = SceSblSsMgrForDriver_sceSblSsMgrDecryptWithPortabilityForDriver_934db6b5(4, g_zero_array_C90498, &dec_input1, &dec_output);   
   if(kget_res1 != 0)
   {
      memset(&dec_output, 0, 0x24);
      return -1; //returns not exactly this, but we dont care here
   }

   //check key name

   int cmp_res = memcmp(dec_output.key_name, g_zero_array_C90498, 0x10);
   if(cmp_res != 0)
   {
      //try to decrypt aes key 2

      portability_input_data dec_input2;
      dec_input2.size = 0x20;
      memcpy(dec_input2.data_1, g_dec_input_C90394, 0x10);
      memcpy(dec_input2.data_2, g_dec_input_C90394 + 0x10, 0x10);      

      int kget_res2 = SceSblSsMgrForDriver_sceSblSsMgrDecryptWithPortabilityForDriver_934db6b5(4, g_zero_array_C90498, &dec_input2, &dec_output);
      if(kget_res2 != 0)
      {
         memset(&dec_output, 0, 0x24);
         return -1; //returns not exactly this, but we dont care here
      }
   }

   memcpy(aes_key, dec_output.aes_key, 0x10);

   //clear sensitive data
   memset(&dec_output, 0, 0x24);

   return 0;
}

//this has to be checked!
int decrypt_sha224_table_internal_C8D09C()
{
   //get aes key

   unsigned char aes_key[0x10];
   int aes_key_res = decrypt_sha224_table_get_key_internal_C8D09C(aes_key);
   if(aes_key_res < 0)
      return aes_key_res;
   
   //perform some data operations

   aes_ctx ctx;
   unsigned char xor_data1[0x10]; //offset 0x3D0
   unsigned char xor_data2[0x10]; //offset 0x3E0 // how is this initialized ?

   int ai_res = SceKernelUtilsForDriver_sceAesInit1ForDriver_f12b6451(&ctx, 0x80, 0x80, aes_key);

   if(ai_res <= 0)
   {
      //clear sensitive data
      memset(aes_key, 0, 0x10);
      memset(&ctx, 0, 0x3C0);
      memset(xor_data1, 0, 0x10);
      memset(xor_data2, 0, 0x10);
      return -1; //returns not exactly this, but we dont care here
   }

   int some_size = ctx.unk_8 << 2;
   if(some_size != 0)
   {
      memcpy(xor_data1, g_zero_array_C90498, some_size);
   }

   unsigned char dec_dst[0x10]; //array for holding single aes dec desult

   unsigned char* next_enc_data = g_enc_sha224_C903B8 + 0x10;
   unsigned char* next_dec_data = g_00B9F8D8 + 0x10; //0xB9F8E8

   unsigned char var_40[0x10]; // how is this initialized ?

   const unsigned char* table_end = g_enc_sha224_C903B8 + sizeof(g_enc_sha224_C903B8) + 0x10; //pointer to end

   do
   {
      unsigned char* curr_enc_data = next_enc_data - 0x10; //current enc data
      unsigned char* curr_dec_data = next_dec_data - 0x10; //current result data

      SceKernelUtilsForDriver_sceAesDecrypt1ForDriver_d8678061(&ctx, curr_enc_data, dec_dst);

      //just check that there is still smth to copy
      int some_size2 = ctx.unk_8 << 2;
      if(some_size2 != 0)
      {
         // devide by 0x10 to get number of blocks left
         int some_size3 = some_size2 >> 4;

         int is_not_tail = (some_size3 != 0) && (some_size2 > 0xF);
         if(is_not_tail > 0)
         {
            //xor current block of decrypted data and store to decrypted table
            //then update xor value with current encrypted block
            memxor(curr_dec_data, dec_dst, xor_data1, 0x10);
            memcpy(xor_data1, curr_enc_data, 0x10);

            //check if there is more than one blocks left
            //this will ignore last block
            if(some_size3 > 1)
            {
               //xor some data and store as next block to decrypted table
               //then update xor value with next encrypted block
               memxor(next_dec_data, var_40, xor_data2, 0x10);
               memcpy(xor_data2, next_enc_data, 0x10);
            }

            //get back original size, however it will be aligned to 0x10
            //if it will not equal to original size - it means that there was tail data
            int some_size4 = some_size3 << 4;
            if(some_size4 != some_size2)
            {
               //copy tail - in this case we have to add some_size4 as main offset
               memxor(curr_dec_data + some_size4, dec_dst + some_size4, xor_data1 + some_size4, some_size2);
               memcpy(xor_data1 + some_size4, curr_enc_data + some_size4, some_size2);
            }
         }
         else
         {
            //copy tail - some_size2 will hold number of bytes left
            memxor(curr_dec_data, dec_dst, xor_data1, some_size2);
            memcpy(xor_data1, curr_enc_data, some_size2);
         }
      }

      next_enc_data = next_enc_data + 0x10;
      next_dec_data = next_dec_data + 0x10;
   }
   while(next_enc_data != table_end);

   //clear sensitive data
   memset(&aes_key, 0, 0x10);
   memset(&ctx, 0, 0x3C0);
   memset(xor_data1, 0, 0x10);
   memset(xor_data2, 0, 0x10);

   return 0;
}

//[REVERSED]
int decrypt_sha224_table_C8D09C(unsigned char* ptr_pair[2], unsigned char* ptr_table[6])
{
   //check that tables is not already decrypted

   if (g_00B9F9B8 == 0)
   {
      //decrypt of not already decrypted

      int dec_res = decrypt_sha224_table_internal_C8D09C();
      if(dec_res < 0)
         return dec_res;

      //set decryption success flag
      g_00B9F9B8 = 1;
   }

   //construct pointer table
   ptr_pair[0] = g_00B9F8D8;
   ptr_pair[1] = g_00B9F8D8 + 0x1C;

   ptr_table[0] = g_00B9F8D8 + 0x38;
   ptr_table[1] = g_00B9F8D8 + 0x54;
   ptr_table[2] = g_00B9F8D8 + 0x70;
   ptr_table[3] = g_00B9F8D8 + 0x8C;
   ptr_table[4] = g_00B9F8D8 + 0xA8;
   ptr_table[5] = g_00B9F8D8 + 0xC4;

   return 0;
}

//================

//this has to be checked!
int decrypt_sha224_table_C8D09C_doublecheck_internal()
{
   /*
   unsigned __int8 **__attribute__((__org_arrdim(0,6))) ptr_table_local; // r9
   int result; // r0
   unsigned __int8 *ptrt_vals[2]; // r1
   unsigned __int8 *data0; // r8
   unsigned __int8 *data1; // r11
   uint32_t some_size; // r7
   unsigned int some_size3; // r2
   char check0; // cf
   char check1; // zf
   unsigned int some_size4; // r3
   int64x2_t v12; // q10
   unsigned __int64 v13; // d19
   int64x2_t v14; // q8
   int64x2_t v15; // q8
   int64x2_t v16; // q10
   unsigned __int64 v17; // d19
   int64x2_t v18; // q8
   int64x2_t v19; // q8
   char *v20; // r2
   char v21; // r1
   unsigned __int8 **__attribute__((__org_arrdim(0,2))) ptr_pair_local; // [sp+Ch] [bp-46Ch]
   portability_output_data pod_res; // [sp+14h] [bp-464h]
   aes_ctx ctx; // [sp+38h] [bp-440h]
   char destination; // [sp+408h] [bp-70h]
   unsigned __int64 v26; // [sp+410h] [bp-68h]
   unsigned __int64 v27; // [sp+418h] [bp-60h]
   unsigned __int64 v28; // [sp+420h] [bp-58h]
   char dst[8]; // [sp+428h] [bp-50h]
   unsigned __int64 v30; // [sp+430h] [bp-48h]
   unsigned __int64 v31; // [sp+438h] [bp-40h]
   unsigned __int64 v32; // [sp+440h] [bp-38h]
   */

   unsigned char aes_key[0x10];
   /*
   int aes_key_res = decrypt_sha224_table_C8D09C_doublecheck_get_key_internal(aes_key);
   if(aes_key_res < 0)
      return aes_key_res;
   */

   //perform decryption

   /*
   if ( SceMsif_SceKernelUtilsForDriver__imp_aes_init_f12b6451(&ctx, 0x80, 0x80, aes_key) >= 0 )
   {
      if ( 4 * ctx.unk_8 )
      {
         SceMsif_SceSysclibForDriver__imp_memcpy_40c88316(&destination, zero_array_C90498, 4 * ctx.unk_8);
      }

      data0 = (unsigned __int8 *)(enc_sha224_C903B8 + 16);
      data1 = (unsigned __int8 *)0xB9F8E8;
   
      while ( 1 )
      {
         SceMsif_SceKernelUtilsForDriver__imp_aes_decrypt_d8678061(&ctx, (const char *)data0 + 0xFFFFFFF0, dst);
         some_size = 4 * ctx.unk_8;

         if ( 4 * ctx.unk_8 )
         {
            some_size3 = some_size >> 4;
            check0 = 1;
            check1 = some_size >> 4 == 0;

            if ( some_size >> 4 )
            {
               check0 = some_size >= 0xF;
               check1 = some_size == 0xF;
            }

            some_size4 = 0x10 * some_size3;
            if ( !check1 & (unsigned __int8)check0 )
            {
               v12.n128_u64[0] = *(_QWORD *)&destination;
               v12.n128_u64[1] = v26;
               v13 = *((_QWORD *)data0 - 1);
               v14.n128_u64[0] = *(_QWORD *)dst;
               v14.n128_u64[1] = v30;
               *(_QWORD *)&destination = *((_QWORD *)data0 - 2);
               v26 = v13;
               v15 = veorq_s64(v14, v12);
               *((_QWORD *)data1 - 2) = v15.n128_u64[0];
               *((_QWORD *)data1 - 1) = v15.n128_u64[1];

               if ( some_size3 > 1 )
               {
                  v16.n128_u64[0] = v27;
                  v16.n128_u64[1] = v28;
                  v17 = *((_QWORD *)data0 + 1);
                  v18.n128_u64[0] = v31;
                  v18.n128_u64[1] = v32;
                  v27 = *(_QWORD *)data0;
                  v28 = v17;
                  v19 = veorq_s64(v18, v16);
                  *(_QWORD *)data1 = v19.n128_u64[0];
                  *((_QWORD *)data1 + 1) = v19.n128_u64[1];
               }

               if ( some_size4 == some_size )
                  goto LABEL_20;
            }
            else
            {
               some_size4 = 0;
            }
            do
            {
               v20 = (char *)&ctx + some_size4;
               v21 = data0[-16 + some_size4];
               data1[-16 + some_size4] = dst[some_size4] ^ *((_BYTE *)&ctx + some_size4 + 0x3D0);
               ++some_size4;
               v20[0x3D0] = v21;
            }
            while ( some_size4 < some_size );
         }

         LABEL_20:
         data0 += 0x10;
         data1 += 0x10;

         if ( data0 == (unsigned __int8 *)ctx_130_part_C904A8 )
         {
            pod_res.size = 0;
            *(_DWORD *)pod_res.key_name = 0;
            *(_DWORD *)&pod_res.key_name[4] = 0;
            *(_DWORD *)&pod_res.key_name[8] = 0;
            *(_DWORD *)&pod_res.key_name[12] = 0;
            *(_DWORD *)pod_res.aes_key = 0;
            *(_DWORD *)&pod_res.aes_key[4] = 0;
            *(_DWORD *)&pod_res.aes_key[8] = 0;
            *(_DWORD *)&pod_res.aes_key[12] = 0;
            SceMsif_SceSysclibForDriver__imp_memset_0ab9bf5c(&ctx, 0, 0x3F0u);

            return 0;
         }
      }
   }

   memset(aes_key, 0, 0x10);
   SceMsif_SceSysclibForDriver__imp_memset_0ab9bf5c(&ctx, 0, 0x3F0u);
   */

   return -1;
}

//================

typedef struct verify_hash_ctx
{
   unsigned char* ptr_4; //most likely the right size
   unsigned char* ptr_20; //most likely the right size
}verify_hash_ctx;


struct locals_C8DA14
{
  unsigned __int8 data0[28];
  unsigned __int8 data1[28];
  unsigned __int8 data2[28];
};

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

int do_smth_with_hashes_7_C8E420(unsigned char **sha_224_0, unsigned char **sha_224_1, unsigned char **sha_224_2, unsigned char *sha_224_3, unsigned char *sha_224_4, unsigned char *sha_224_5, unsigned char *sha_224_6, int key_size_blocks)
{
   return 0;
}

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

#pragma pack(push,1)

typedef struct dmac5_41_req1 //size is 0x28
{
   unsigned char f00d_1C_key[0x10];
   unsigned char card_info[0x8];
   unsigned char challenge[0x8];
   unsigned char session_id[8];
}dmac5_41_req1;

typedef struct dmac5_41_req2 //size is 0x10
{
   unsigned char session_id[0x8];
   unsigned char challenge[0x8];
}dmac5_41_req2;

typedef struct tpc_cmd48_req //size is 0x20
{
   unsigned char session_id[0x8];
   unsigned char f00d_cmd1_data;
   unsigned char reserved[0x17];
}tpc_cmd48_req;

typedef struct tpc_cmd49_resp //size is 0x40
{
   unsigned char f00d_1C_key[0x10]; // this data is constant. it looks like it contains some string and binary numbers (maybe name and serial number, or manufacturing date?)
   unsigned char card_info[0x8]; // this data looks like to be constant. only last byte is not equal to zero
   unsigned char challenge[0x8]; // this data is random each time - i am assuming it depends on session_id
   unsigned char iv[0x08]; // this data is different each time - thats because var_88 and session_id are part of cryptographic material, given to 3des-cbc-cts
   unsigned char reserved[0x18];
}tpc_cmd49_resp;

typedef struct tpc_cmd4A_req //size is 0x20
{
   unsigned char iv[0x8];
   unsigned char reserved[0x18];
}tpc_cmd4A_req;

#pragma pack(pop)

//[REVERSED]
int get_card_key_C8D5FC(SceMsif_subctx* subctx, unsigned char mc_1C_key[0x10])
{
   // execute f00d rm auth cmd 1
   // this probably gets some session ID or smth - have to confirm
   unsigned int f00d_cmd1_res = 0;

   int fdres1 = execute_f00d_command_1_rmauth_sm_C8D908(&f00d_cmd1_res);
   if(fdres1 < 0)
      return fdres1;

   // generate random number - this should be some session ID or smth
   char session_id[8];
   memset(session_id, 0, 8);

   int rdgenres1 = SceSblSsMgrForDriver_sceSblSsMgrGetRandomDataCropForDriver_4dd1b2e5(session_id, 8, 1);
   if(rdgenres1 < 0)
      return rdgenres1;   

   // execute tpc cmd 48 - send request - probably establish session with memory card

   tpc_cmd48_req cmd48_req;
   memcpy(cmd48_req.session_id, session_id, 8); //copy session_id
   cmd48_req.f00d_cmd1_data = f00d_cmd1_res; //copy f00d rm auth cmd1 resp 1 byte
   memset(cmd48_req.reserved, 0, 0x17); //fill rest with 0

   int res48 = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_48, 0x20, (char*)&cmd48_req, 1000);
   if(res48 != 0)
      return res48; //returns not exactly this, but we dont care here

   // execute tpc cmd 49 - get response - probably result of establishing session with memory card

   tpc_cmd49_resp cmd49_resp;
   memset(&cmd49_resp, 0, 0x40);
   
   int res49 = ms_execute_ex_set_cmd_read_short_data_C8A448(subctx, MS_TPC_49, 0x40, (char*)&cmd49_resp, 1000);
   if(res49 != 0)
      return res49; //returns not exactly this, but we dont care here

   // execute f00d rm auth cmd 2
   // this call sets the key that was obtained from memory card into slot 0x1C
   int fdres2 = execute_f00d_command_2_rmauth_sm_C8D988(cmd49_resp.f00d_1C_key);
   if(fdres2 < 0)
      return fdres2;

   // prepare 3des-cbc-cts (dmac5 cmd 0x41 request) data

   char des3_iv_1[0x8];
   memset(des3_iv_1, 0, 0x8);

   dmac5_41_req1 d5req1;
   memcpy(d5req1.f00d_1C_key, cmd49_resp.f00d_1C_key, 0x10); //copy 0x1C slot key from tpc 0x49 response
   memcpy(d5req1.card_info, cmd49_resp.card_info, 0x8); //copy 8 bytes of card info
   memcpy(d5req1.challenge, cmd49_resp.challenge, 0x8); //copy 8 bytes of challenge
   memcpy(d5req1.session_id, session_id, 0x8); //copy session id sent in tpc 0x49 request

   // encrypt prepared buffer with 3des-cbc-cts and obtain IV
   int dmc5res1 = w_dmac5_3des_cbc_cts_iv_C8D2F0((unsigned int*)des3_iv_1, (const unsigned int*)&d5req1, 0x28);
   if(dmc5res1 != 0)
      return dmc5res1;

   // verify that IV matches to the one, given in tpc 0x49 response

   if(memcmp(des3_iv_1, cmd49_resp.iv, 8) != 0)
      return -1; //returns not exactly this, but we dont care here

   // prepare 3des-cbc-cts (dmac5 cmd 0x41 request) data
 
   char des3_iv_2[0x8];
   memset(des3_iv_2, 0, 0x8);

   dmac5_41_req2 d5req2;
   memcpy(d5req2.session_id, d5req1.session_id, 8); //copy session id
   memcpy(d5req2.challenge, cmd49_resp.challenge, 8); //copy 8 bytes of chalenge from tpc 0x49 response

   // encrypt prepared buffer with 3des-cbc-cts and obtain IV
   int dmc5res2 = w_dmac5_3des_cbc_cts_iv_C8D2F0((unsigned int*)des3_iv_2, (const unsigned int*)&d5req2, 0x10);
   if(dmc5res2 != 0)
      return dmc5res2;
   
   // execute tpc cmd 4A - send request - what does it do with the card ?

   tpc_cmd4A_req cmd4A_req;
   memcpy(cmd4A_req.iv, des3_iv_2, 8); //copy IV from second 3des-cbc-cts encryption
   memset(cmd4A_req.reserved, 0, 0x18); //clear all other bytes

   int res4A = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_4A, 0x20, (char*)&cmd4A_req, 1000);
   if(res4A < 0)
      return res4A; //returns not exactly this, but we dont care here
   
   // copy result - return key that was obtained from the memory card and set to 0x1C slot with f00d rm auth 2 service call

   if(mc_1C_key == 0)
      return -1; //returns not exactly this, but we dont care here

   memcpy(mc_1C_key, d5req1.f00d_1C_key, 0x10);
   
   return cmd49_resp.card_info[7]; //interestingly enough this is the only byte in lower part of challenge that is not equal to 0
}

//[REVERSED]
int _byteswap_ulong_C8D78C(char* bytes)
{
   return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | (bytes[3]);
}

//[REVERSED]
int decrypt_sha224_table_and_verify_C8D78C(SceMsif_subctx* subctx, unsigned char master_key[0x10])
{
   //get response from the card

   int res4B = ms_execute_ex_set_cmd_C8A4E8(subctx, MS_TPC_4B, subctx, 1000);
   if(res4B != 0)
      return res4B;

   //probably check error code

   int data_inv = _byteswap_ulong_C8D78C(subctx->error_code);
   if(data_inv != 1)
      return -1; //returns not exactly this, but we dont care here

   //decrypt static list of what is probably sha 224 hash table

   unsigned char* dec_ptr_pair[2];
   unsigned char* dec_ptr_table[6];

   int dec_res = decrypt_sha224_table_C8D09C(dec_ptr_pair, dec_ptr_table);
   if(dec_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //derive secret key from master key that we get during card initialization (use sha 224 for derivation)

   unsigned char secret_key[0x1C];
   memset(secret_key, 0, 0x1C);

   int sha_res = SceKernelUtilsForDriver_sceSha224DigestForDriver_9ea9d4dc(master_key, 0x10, secret_key);
   if(sha_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //verify the data

   verify_hash_ctx vfh_ctx;
   vfh_ctx.ptr_4 = subctx->resp_buffer0; 
   vfh_ctx.ptr_20 = subctx->resp_buffer1;

   int vf_res = verify_hashes_C8DBC0(&vfh_ctx, secret_key, dec_ptr_pair, dec_ptr_table);
   if(vf_res != 0)
      return -1;

   return 0;
}

int SceMsifForDriver__exp_get_sha224_digest_source_718bdfde(char *sha224_digest_source)
{
   return 0;
}