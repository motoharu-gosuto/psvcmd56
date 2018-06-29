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

//-------- memory card communication --------

typedef struct SceMsif_subctx
{
   char resp_buffer[0x200]; //some buffer of unknown size

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

char ctx_130_part_C904A8[0x90] = 
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
int execute_f00d_command_1_rmauth_sm_C8D908(int* f00d_data)
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

   int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(id_B9F9BC, &res);
   if (res1 != 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
      return res1;
   }
   
   *f00d_data = *(int*)(&data.data[0x10]);

   SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
   return f00d_resp;
}

//[REVERSED]
int execute_f00d_command_2_rmauth_sm_C8D988(const char input[0x10])
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

   int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_0631f8ed(id_B9F9BC, &res);
   if (res1 != 0)
   {
      SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
      return res1;
   }
   
   SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967(0);
   return f00d_resp;
}

//-------- bit magic and des ecb --------

//[REVERSED]
void process_block_invert_head(unsigned int& lo, unsigned int& hi, unsigned char value)
{
   lo = value << 8;
   hi = 0;
}

//[REVERSED]
void process_block_invert_body(unsigned int& lo, unsigned int& hi, unsigned char value)
{
   unsigned int v1 = hi | 0;
   unsigned int v2 = v1 << 8;
   unsigned int v4 = lo | value;
   hi = v2 | (v4 >> 24);
   lo = v4 << 8;
}

//[REVERSED]
void process_block_invert_tail(unsigned int& lo, unsigned int& hi, unsigned char value)
{
   lo = lo | value;
   hi = hi | 0;
}

//--------

//[REVERSED]
std::uint32_t adds(std::uint32_t left, std::uint32_t right, std::uint32_t* carry)
{
   std::uint64_t l64 = left;
   std::uint64_t r64 = right;
   std::uint64_t res64 = l64 + r64;

   if((res64 & 0x0000000100000000) > 0)
      *carry = 1;
   else
      *carry = 0;

   return (std::uint32_t)res64;
}

//[REVERSED]
std::uint32_t adcs(std::uint32_t left, std::uint32_t right, std::uint32_t* carry)
{
   std::uint64_t l64 = left;
   std::uint64_t r64 = right;
   std::uint64_t res64 = l64 + r64 + *carry;

   if((res64 & 0x0000000100000000) > 0)
      *carry = 1;
   else
      *carry = 0;

   return (std::uint32_t)res64;
}

//--------

//[REVERSED]
void process_back_inverse_body(unsigned int& lo, unsigned int& hi, unsigned char value)
{
   unsigned int v1 = lo | value;
   unsigned int v2 = hi << 8;
   unsigned int v3 = v2 | (v1 >> 24);
   lo = v1 << 8;
   hi = v3 | 0;
}

//[REVERSED]
void process_back_inverse_head(unsigned int& lo, unsigned int& hi, unsigned char value)
{
   hi = 0;
   lo = 0;

   process_back_inverse_body(lo, hi, value);
}

//[REVERSED]
void process_back_inverse_tail(unsigned int& lo, unsigned int& hi, unsigned char value)
{
   lo = lo | value;
}

//--------

//[REVERSED]
int w_dmac5_command_0x41_bit_magic_C8D2F0(unsigned int* some_buffer, unsigned int* tweak0_res, unsigned int* tweak1_res)
{
   //---- reverse input buffer ----

   unsigned int lo0;
   unsigned int hi0;
   process_block_invert_head(lo0, hi0, ((unsigned char*)some_buffer)[0]);
   process_block_invert_body(lo0, hi0, ((unsigned char*)some_buffer)[1]);
   process_block_invert_body(lo0, hi0, ((unsigned char*)some_buffer)[2]);
   process_block_invert_body(lo0, hi0, ((unsigned char*)some_buffer)[3]);
   process_block_invert_body(lo0, hi0, ((unsigned char*)some_buffer)[4]);
   process_block_invert_body(lo0, hi0, ((unsigned char*)some_buffer)[5]);
   process_block_invert_body(lo0, hi0, ((unsigned char*)some_buffer)[6]);
   process_block_invert_tail(lo0, hi0, ((unsigned char*)some_buffer)[7]);

   //---- carry add input buffer ----

   std::uint32_t carry0 = 0;
   std::uint32_t au0 = adds(lo0, lo0, &carry0); //technically this is a multiplication by 2
   std::uint32_t bu0 = adcs(hi0, hi0, &carry0); //technically this is a multiplication by 2 (but also with carry)

   //---- retrieve bytes

   unsigned char a[4]; 
   a[0] = (unsigned char)(au0);
   a[1] = (unsigned char)(au0 >>  8);
   a[2] = (unsigned char)(au0 >> 16);
   a[3] = (unsigned char)(au0 >> 24);

   unsigned char b[4]; 
   b[0] = (unsigned char)(bu0);
   b[1] = (unsigned char)(bu0 >>  8);
   b[2] = (unsigned char)(bu0 >> 16);
   b[3] = (unsigned char)(bu0 >> 24);

   //---- mix bytes ----

   unsigned char tweak0[8];

   tweak0[0] = b[3];
   tweak0[1] = b[2];
   tweak0[2] = b[1];
   tweak0[3] = b[0];

   tweak0[4] = (a[3] | b[1]);
   tweak0[5] = (a[2] | b[2]);
   tweak0[6] = (a[1] | b[3]);

   unsigned char value00 = ((char*)some_buffer)[0];
   tweak0[7] = ((value00 & 0x80) > 0) ? (a[0] ^ 0x1B) 
                                      :  a[0];
   
   //---- back reverse buffer ----
   
   unsigned int hi1;
   unsigned int lo1;
   process_back_inverse_head(lo1, hi1, tweak0[0]);
   process_back_inverse_body(lo1, hi1, tweak0[1]);
   process_back_inverse_body(lo1, hi1, tweak0[2]);
   process_back_inverse_body(lo1, hi1, tweak0[3]);
   process_back_inverse_body(lo1, hi1, tweak0[4]);
   process_back_inverse_body(lo1, hi1, tweak0[5]);
   process_back_inverse_body(lo1, hi1, tweak0[6]);
   process_back_inverse_tail(lo1, hi1, tweak0[7]);

   //---- carry add buffer ----

   std::uint32_t carry1 = 0;
   std::uint32_t au1 = adds(lo1, lo1, &carry1); //technically this is a multiplication by 2
   std::uint32_t bu1 = adcs(hi0, hi0, &carry1); //technically this is a multiplication by 2 (but also with carry)

   //---- retrieve bytes

   unsigned char c[4]; 
   c[0] = (unsigned char)(au1);
   c[1] = (unsigned char)(au1 >>  8);
   c[2] = (unsigned char)(au1 >> 16);
   c[3] = (unsigned char)(au1 >> 24);

   unsigned char d[4]; 
   d[0] = (unsigned char)(bu1);
   d[1] = (unsigned char)(bu1 >>  8);
   d[2] = (unsigned char)(bu1 >> 16);
   d[3] = (unsigned char)(bu1 >> 24);

   //---- mix bytes ----

   unsigned char tweak1[8]; //var_40

   tweak1[0] = d[3];
   tweak1[1] = d[2];
   tweak1[2] = d[1];
   tweak1[3] = d[0];

   tweak1[4] = c[3] | d[1];
   tweak1[5] = c[2] | d[2];
   tweak1[6] = c[1] | d[3];

   unsigned char value01 = tweak0[0];
   tweak1[7] = ((value01 & 0x80) > 0) ? (c[0] ^ 0x1B)
                                      :  c[0];
 
   //---- copy results ----

   memcpy((char*)tweak0_res, (char*)tweak0, 8);
   memcpy((char*)tweak1_res, (char*)tweak1, 8);

   return 0;
}

//[REVERSED]
int w_dmac5_command_0x41_C8D2F0(int* result, const int* data, int size)
{
   int tmp_src0[2];
   tmp_src0[0] = 0;
   tmp_src0[1] = 0;

   unsigned int tmp_dst0[2];

   int enc_res0 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf((unsigned char*)tmp_src0, (unsigned char*)tmp_dst0, 8, 0x1C, 0xC0, 1);
   if(enc_res0 < 0)
      return enc_res0;

   //calculate tweak keys?

   unsigned int tweak_key0[2];
   unsigned int tweak_key1[2];
   int r0 = w_dmac5_command_0x41_bit_magic_C8D2F0(tmp_dst0, tweak_key0, tweak_key1);

   //---- process data in blocks of 8 bytes ----

   if(size <= 8)
      return r0;

   const int* current_ptr = data;
   int current_size = size;

   int round_buffer[2];
   round_buffer[0] = 0;
   round_buffer[1] = 0;

   while(true)
   {
      current_ptr = current_ptr + 2;
      
      //perform xor operation with input data
      int current_round[2];
      current_round[0] = (current_ptr - 2)[0] ^ round_buffer[0];
      current_round[1] = (current_ptr - 2)[1] ^ round_buffer[1];

      //perform encryption, write back to round_buffer
      int enc_res1 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf((unsigned char*)current_round, (unsigned char*)round_buffer, 8, 0x1C, 0xC0, 1);
      if(enc_res1 < 0)
         break;

      current_size = current_size - 8;
      if(current_size <= 8)
         break;
   }

   //---- process tail of the data (is this cipher text stealing?) ----

   int tail_tweak[2];
   int tail_data[2];

   if(current_size == 8)
   {
      //write last chunk of data
      tail_data[0] = current_ptr[0];
      tail_data[1] = current_ptr[1];
      
      //perform xor operation of current buffer with some data
      tail_tweak[0] = round_buffer[0] ^ tweak_key0[0];
      tail_tweak[1] = round_buffer[1] ^ tweak_key0[1];
   }
   else
   {
      //I assume this code pads the tail with zeroes (but not sure)

      int temp_src2[2];
      temp_src2[0] = current_ptr[0];
      temp_src2[1] = current_ptr[1];
      
      //zero first byte of tail
      char* ptr1 = ((char*)temp_src2) + current_size;
      ptr1[0] = 0;

      //not sure how this code works !
      int size1 = current_size + 1;
      if(size1 != 0)
      {
         char* ptr3 = ((char*)temp_src2) + size1;
         memset(ptr3, 0, 7 - current_size);
      }
      
      //write last padded chunk of data
      tail_data[0] = temp_src2[0];
      tail_data[1] = temp_src2[1];
      
      //perform xor operation of current buffer with some data
      tail_tweak[0] = round_buffer[0] ^ tweak_key1[0];
      tail_tweak[1] = round_buffer[1] ^ tweak_key1[1];
   }

   //perform xor operation with input data
   int final_round[2];
   final_round[0] = tail_tweak[0] ^ tail_data[0];
   final_round[1] = tail_tweak[1] ^ tail_data[1];

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

int decrypt_sha224_table_internal_C8D09C()
{
   //try to decrypt aes key 1

   portability_input_data dec_input_C90370;
   dec_input_C90370.size = 0x20;
   memcpy(dec_input_C90370.data_1, g_dec_input_C90370, 0x10);
   memcpy(dec_input_C90370.data_2, g_dec_input_C90370 + 0x10, 0x10);

   portability_output_data dec_data_464;
   dec_data_464.size = 0x20;
   memset(dec_data_464.key_name, 0, 0x10);
   memset(dec_data_464.aes_key_14, 0, 0x10);

   int kget_res1 = SceSblSsMgrForDriver_sceSblSsMgrDecryptWithPortabilityForDriver_934db6b5(4, g_zero_array_C90498, &dec_input_C90370, &dec_data_464);   

   if(kget_res1 != 0)
   {
      memset(&dec_data_464, 0, 0x24);
      return -1; //returns not exactly this, but we dont care here
   }

   int cmp_res = memcmp(dec_data_464.key_name, g_zero_array_C90498, 0x10);

   //try to decrypt aes key 2

   if(cmp_res != 0)
   {
      portability_input_data dec_input_C90394;
      memcpy(dec_input_C90394.data_1, g_dec_input_C90394, 0x10);
      memcpy(dec_input_C90394.data_2, g_dec_input_C90394 + 0x10, 0x10);      

      int kget_res2 = SceSblSsMgrForDriver_sceSblSsMgrDecryptWithPortabilityForDriver_934db6b5(4, g_zero_array_C90498, &dec_input_C90394, &dec_data_464);

      if(kget_res2 != 0)
      {
         memset(&dec_data_464, 0, 0x24);
         return -1; //returns not exactly this, but we dont care here
      }
   }

   aes_ctx ctx;
   unsigned char xor_data1[0x10]; //offset 0x3D0
   unsigned char xor_data2[0x10]; //offset 0x3E0 // how is this initialized ?

   int ai_res = SceKernelUtilsForDriver_sceAesInit1ForDriver_f12b6451(&ctx, 0x80, 0x80, dec_data_464.aes_key_14);

   if(ai_res <= 0)
   {
      //clear sensitive data
      memset(&dec_data_464, 0, 0x24);
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
   memset(&dec_data_464, 0, 0x24);
   memset(&ctx, 0, 0x3C0);
   memset(xor_data1, 0, 0x10);
   memset(xor_data2, 0, 0x10);

   return 0;
}

int decrypt_sha224_table_C8D09C(unsigned char* ptr_pair[2], unsigned char* ptr_table[6])
{
   //check that tables is not already decrypted

   if(g_00B9F9B8 == 0)
   {
      int dec_res = decrypt_sha224_table_internal_C8D09C();
      if(dec_res < 0)
         return dec_res;
   }

   //set decryption success flag
   g_00B9F9B8 = 1;

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

//----------------

typedef struct verify_hash_ctx
{
   char* ptr_4;
   char* ptr_20;
}verify_hash_ctx;

int verify_hashes_C8DBC0(verify_hash_ctx* ctx, unsigned char sha_224[0x1C], unsigned char* dec_ptr_pair[2], unsigned char* dec_ptr_table[6])
{
   return 0;
}

#pragma pack(push,1)

typedef struct dmac5_41_req1 //size is 0x28
{
   char f00d_cmd2_buffer[0x10];
   char var_88[0x10];
   char rand_value[8];
}dmac5_41_req1;

typedef struct dmac5_41_req2 //size is 0x10
{
   char data1[0x8];
   char data2[0x8];
}dmac5_41_req2;

//need to add type to tpc_cmd48

typedef struct tpc_cmd49_resp //size is 0x40
{
   char f00d_cmd2_buffer[0x10];
   char var_88[0x10];
   char signature[0x08];
   char reserved[0x18];
}tpc_cmd49_resp;

#pragma pack(pop)

int get_sha224_digest_source_validate_card_init_f00D_C8D5FC(SceMsif_subctx* subctx, char sha224_digest_source[0x10])
{
   // execute f00d command 1

   int f00d_cmd1_res = 0;

   int fdres1 = execute_f00d_command_1_rmauth_sm_C8D908(&f00d_cmd1_res);
   if(fdres1 < 0)
      return fdres1;

   // generate random number
   char rand_value[8];
   memset(rand_value, 0, 8);

   int rdgenres1 = SceSblSsMgrForDriver_4dd1b2e5(rand_value, 8, 1);
   if(rdgenres1 < 0)
      return rdgenres1;   

   // prepare cmd 0x48 request

   // 8 + 1 + 0x17 = 0x20 total in bytes
   char cmd48_src[0x20];
   memcpy(cmd48_src, rand_value, 8); //copy rand
   cmd48_src[8] = f00d_cmd1_res; //copy cmd1 resp 1 byte
   memset(cmd48_src + 9, 0, 0x17); //fill rest with 0

   // execute tpc command 48
   int res48 = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_48, 0x20, cmd48_src, 1000);
   if(res48 != 0)
      return res48; //returns not exactly this, but we dont care here

   // execute tpc command 49

   tpc_cmd49_resp cmd49_resp;
   memset(&cmd49_resp, 0, 0x40);
   
   int res49 = ms_execute_ex_set_cmd_read_short_data_C8A448(subctx, MS_TPC_49, 0x40, (char*)&cmd49_resp, 1000); //gets 0x40 bytes of response

   // execute f00d command 2

   int fdres2 = execute_f00d_command_2_rmauth_sm_C8D988(cmd49_resp.f00d_cmd2_buffer); //sends first 0x10 bytes of 0x49 resp to f00d, probably gets response
   if(fdres2 < 0)
      return fdres2;

   // prepare dmac5 command 41 request data

   char dmac5_result_1[0x8];
   memset(dmac5_result_1, 0, 0x8);

   dmac5_41_req1 d5req1;
   memcpy(d5req1.f00d_cmd2_buffer, cmd49_resp.f00d_cmd2_buffer, 0x10);
   memcpy(d5req1.var_88, cmd49_resp.var_88, 0x10); //copy second 0x10 bytes of 0x49 resp  
   memcpy(d5req1.rand_value, rand_value, 0x8);

   // execute dmac5 command 41

   int dmc5res1 = w_dmac5_command_0x41_C8D2F0((int*)dmac5_result_1, (int*)&d5req1, 0x28); //send dmac5 request with 0x20 bytes of 0x49 response and 8 bytes of random data
   if(dmc5res1 != 0)
      return dmc5res1;

   // verify hash, signature ?

   if(memcmp(dmac5_result_1, cmd49_resp.signature, 8) != 0) //verify against last 8 bytes of 0x49 resp
      return -1; //returns not exactly this, but we dont care here

   // prepare dmac5 command 41 request data
 
   char dmac_5_result_2[0x8];
   memset(dmac_5_result_2, 0, 0x8);

   dmac5_41_req2 d5req2;
   memcpy(d5req2.data1, d5req1.rand_value, 8);
   memcpy(d5req2.data2, d5req1.var_88 + 8, 8);

   // execute dmac5 command 41

   int dmc5res2 = w_dmac5_command_0x41_C8D2F0((int*)dmac_5_result_2, (int*)&d5req2, 0x10);
   if(dmc5res2 != 0)
      return dmc5res2;
   
   // execute tpc command 4A

   char cmd4A_src[0x20];
   memcpy(cmd4A_src, dmac_5_result_2, 8); //copy dmac5 result 2 to request
   memset(cmd4A_src + 8, 0, 0x20); //all bytes should be cleared except for first 8 bytes
   
   int res4A = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_4A, 0x20, cmd4A_src, 1000);
   if(res4A < 0)
      return res4A; //returns not exactly this, but we dont care here
   
   // copy result

   if(sha224_digest_source == 0)
      return -1; //returns not exactly this, but we dont care here

   memcpy(sha224_digest_source, d5req1.f00d_cmd2_buffer, 0x10); //copy result
   
   return cmd49_resp.var_88[7];
}

int decrypt_sha224_table_and_verify_C8D78C(SceMsif_subctx* subctx, unsigned char sha224_digest_source[0x10])
{
   //get response from card

   int res4B = ms_execute_ex_set_cmd_C8A4E8(subctx, MS_TPC_4B, subctx, 1000);
   if(res4B != 0)
      return res4B;

   //check some field

   int data_inv =  (subctx->resp_buffer[0] << 24) | (subctx->resp_buffer[1] << 16) | (subctx->resp_buffer[2] << 8) | (subctx->resp_buffer[3]);
   if(data_inv != 1)
      return -1; //returns not exactly this, but we dont care here

   //decrypt static list of what is probably sha 224 hash table

   unsigned char* dec_ptr_pair[2];
   unsigned char* dec_ptr_table[6];

   int dec_res = decrypt_sha224_table_C8D09C(dec_ptr_pair, dec_ptr_table);
   if(dec_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //calculate sha 224 digest from data that we aquired on first step of initialization

   unsigned char sha_224_digest[0x1C];
   memset(sha_224_digest, 0, 0x1C);

   int sha_res = SceKernelUtilsForDriver_sceSha224DigestForDriver_9ea9d4dc(sha224_digest_source, 0x10, sha_224_digest);
   if(sha_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //verify the data

   verify_hash_ctx vfh_ctx;
   vfh_ctx.ptr_4 = subctx->resp_buffer + 4; 
   vfh_ctx.ptr_20 = subctx->resp_buffer + 0x20;

   int vf_res = verify_hashes_C8DBC0(&vfh_ctx, sha_224_digest, dec_ptr_pair, dec_ptr_table);
   if(vf_res != 0)
      return -1;

   return 0;
}

int SceMsifForDriver__exp_get_sha224_digest_source_718bdfde(char *sha224_digest_source)
{
   return 0;
}