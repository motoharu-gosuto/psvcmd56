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

#include "SceMsifHashTableVerify.h"

//-------- memory card communication --------

typedef struct SceMsif_subctx
{
   char error_code[4];
   ecdsa_signature signature;
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
int decrypt_ecdsa_parameters_C8D09C(unsigned char* ptr_pair[2], unsigned char* ptr_table[6])
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
int ecdsa_verify_C8D78C(SceMsif_subctx* subctx, unsigned char master_key[0x10])
{
   //get response from the card

   int res4B = ms_execute_ex_set_cmd_C8A4E8(subctx, MS_TPC_4B, subctx, 1000);
   if(res4B != 0)
      return res4B;

   //probably check error code

   int data_inv = _byteswap_ulong_C8D78C(subctx->error_code);
   if(data_inv != 1)
      return -1; //returns not exactly this, but we dont care here

   //decrypt static list of ecdsa parameters

   unsigned char* public_key_point_table[2];
   unsigned char* ecdsa_params_table[6];

   int dec_res = decrypt_ecdsa_parameters_C8D09C(public_key_point_table, ecdsa_params_table);
   if(dec_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //derive hash of master key that we get during card initialization (use sha 224 for derivation)

   unsigned char message_hash[0x1C];
   memset(message_hash, 0, 0x1C);

   int sha_res = SceKernelUtilsForDriver_sceSha224DigestForDriver_9ea9d4dc(master_key, 0x10, message_hash);
   if(sha_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //verify the data

   ecdsa_point P;
   memcpy(P.X, public_key_point_table[0], 0x1C);
   memcpy(P.Y, public_key_point_table[1], 0x1C);

   ecdsa_params params;
   memcpy(params.P, ecdsa_params_table[0], 0x1C);
   memcpy(params.A, ecdsa_params_table[1], 0x1C);
   memcpy(params.B, ecdsa_params_table[2], 0x1C);
   memcpy(params.N, ecdsa_params_table[3], 0x1C);
   memcpy(params.G.X, ecdsa_params_table[4], 0x1C);
   memcpy(params.G.Y, ecdsa_params_table[5], 0x1C);

   int vf_res = ecdsa_verify_C8DBC0(&subctx->signature, message_hash, &P, &params);
   if(vf_res != 0)
      return -1;

   return 0;
}

int SceMsifForDriver__exp_get_sha224_digest_source_718bdfde(char *sha224_digest_source)
{
   return 0;
}