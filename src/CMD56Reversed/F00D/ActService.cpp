#include "ActService.h"

using namespace f00d;

unsigned char cmd0x02_key_4C430[0x20] = {0x84, 0x6D, 0x2D, 0xFD, 0x77, 0xD3, 0xC2, 0xE5, 0xF0, 0xE1, 0x7E, 0xB1, 0x8C, 0xC7, 0x86, 0x92,
                                         0x8B, 0x88, 0x1E, 0x2E, 0x17, 0xAE, 0x0C, 0xD8, 0xFD, 0xE8, 0x88, 0x09, 0xD0, 0xD0, 0x33, 0xC5 };

unsigned char cmd0x02_iv_4C450[0x10] = {0xC8, 0xA0, 0x40, 0x66, 0x2B, 0x10, 0xA1, 0x98, 0x6A, 0x18, 0x94, 0xE9, 0x4F, 0xBE, 0xFC, 0xF0 };

unsigned char cmd0x01_key_4C460[0x20] = {0x3D, 0x1E, 0xFB, 0x3C, 0xFE, 0xD4, 0x2A, 0x5F, 0x87, 0x12, 0x13, 0xD4, 0xCF, 0x1E, 0x3B, 0x7A,
                                         0x65, 0xF9, 0x27, 0xE2, 0x38, 0x11, 0xB5, 0x94, 0x21, 0x5D, 0x61, 0x6B, 0xE5, 0x9D, 0xA4, 0xD8 };

unsigned char cmd0x01_iv_4C480[0x10] ={0xD5, 0x7E, 0x36, 0x99, 0x98, 0x33, 2, 0x61, 0x16, 0x32, 0xDE, 0x33, 0xB1, 0x97, 0xA4, 0x3C };

unsigned char cmd0x01_0x02_key_tmp_4E000[0x20] = {0};

unsigned char cmd0x01_0x02_iv_tmp_4E020[0x10] = {0};

unsigned char act_str_4C428[4] = {'a', 'c', 't', 0};

unsigned char act_str_80CE10[4] = {'a', 'c', 't', 0};

unsigned char key_80CF24[0x20] = {0x84, 0x6D, 0x2D, 0xFD, 0x77, 0xD3, 0xC2, 0xE5, 0xF0, 0xE1, 0x7E, 0xB1, 0x8C, 0xC7, 0x86, 0x92,
                                  0x8B, 0x88, 0x1E, 0x2E, 0x17, 0xAE, 0xC, 0xD8, 0xFD, 0xE8, 0x88, 9, 0xD0, 0xD0, 0x33, 0xC5};

unsigned char iv_80CF44[0x10] = {0xC8, 0xA0, 0x40, 0x66, 0x2B, 0x10, 0xA1, 0x98, 0x6A, 0x18, 0x94, 0xE9, 0x4F, 0xBE, 0xFC, 0xF0};

unsigned char new_service_key_80CF54[0x20] = {0x5A, 0x91, 0xFC, 0x74, 0xA8, 0x2B, 0xE3, 0xF2, 0xB8, 0xF4, 0xDB, 0x60, 0x70, 0xA0, 0x99, 0xA2,
                                              0xBD, 0xF0, 0xE, 0x7B, 0xF0, 0xE, 0x7B, 0xF0, 0x8B, 0x68, 0x55, 0x34, 0xA0, 0x64, 0x6D, 0x87 };

unsigned char byte_80CE18[0x100] = {0xA8, 0x44, 0xCC, 0x0E, 0x30, 0x8B, 0x55, 0xE9, 0x11, 0x3F, 0xA5, 0x11, 0xFF, 0x25, 0x7F, 0xA6,
                                    0x43, 0x1A, 0xFE, 0xCF, 0xC3, 0x60, 0x26, 0x43, 0x55, 0xDC, 0xDD, 0x07, 0xB5, 0xD9, 0x61, 0x0E,
                                    0x92, 0xBB, 0xA8, 0x84, 0x22, 0x26, 0xB0, 0x27, 0xBB, 0x18, 0xB5, 0xA5, 0x96, 0xB1, 0xFF, 0xAF,
                                    0x41, 0x46, 0x6E, 0x16, 0x7B, 0x6B, 0xB7, 0xCE, 0xE8, 0xB6, 0xAD, 0x26, 0x44, 0x69, 0xD5, 0x8E,
                                    0x9E, 0x1C, 0xC8, 0xDC, 0x86, 0x77, 0xA0, 0xAC, 0xFF, 0xC6, 0xCD, 0x6B, 0x60, 0x60, 0xE9, 0x6B,
                                    0x97, 0x1D, 0x54, 0x06, 0x3C, 0x6C, 0x38, 0x48, 0x4C, 0x2C, 0x8D, 0x2F, 0x9C, 0xD1, 0xEC, 0x70,
                                    0xAC, 0xB8, 0x08, 0xC5, 0x77, 0xEF, 0xA7, 0x07, 0x85, 0xF8, 0x6C, 0x86, 0x97, 0x7D, 0x7A, 0x0C,
                                    0x69, 0x39, 0xE7, 0x22, 0x19, 0x39, 0x51, 0x24, 0x84, 0xDC, 0x39, 0x99, 0x66, 0xEA, 0x6E, 0xE2,
                                    0x28, 0xDB, 0xCD, 0x99, 0xF7, 0x4C, 0xBC, 0x17, 0x9B, 0xCE, 0x59, 0xFC, 0x76, 0xCA, 0xF6, 0xFC,
                                    0xD9, 0xB6, 0x5F, 0xA6, 0xB3, 0xEB, 0x11, 0x3A, 0x58, 0xF7, 0x1F, 0xDD, 0x16, 0xB2, 0x49, 0xB6,
                                    0x1C, 0x8A, 0xF8, 0x59, 0x81, 0x9F, 0x5E, 0x31, 0x1E, 0x87, 0x1E, 0x47, 0x5B, 0x42, 0x42, 0x63,
                                    0x5A, 0x79, 0xB0, 0xC8, 0xDE, 0x27, 0x13, 0xE6, 0xD5, 0x84, 0x72, 0x15, 0xB2, 0x8E, 0x03, 0x7C,
                                    0x51, 0x81, 0xE5, 0x1C, 0xC7, 0xA3, 0xE8, 0xA6, 0x5B, 0xD4, 0x04, 0x1A, 0x6F, 0xD7, 0x42, 0x77,
                                    0xFC, 0x2A, 0x3E, 0x63, 0x43, 0x4B, 0x54, 0x9B, 0xB6, 0x2B, 0xDC, 0x64, 0x9F, 0xA2, 0x12, 0xA0,
                                    0x3F, 0xFE, 0xA5, 0xA3, 0x89, 0x3B, 0x93, 0xC6, 0x20, 0xC2, 0x64, 0x2A, 0x71, 0x79, 0x28, 0x9B,
                                    0x98, 0x1B, 0x7C, 0xFB, 0x68, 0x1E, 0x05, 0x77, 0xDD, 0x3E, 0xBC, 0x17, 0x47, 0x24, 0x52, 0x39};

unsigned char byte_80CF1C[0x4] = {0};

int bigmac_aes_256_cbc_decrypt_4B730(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, unsigned char* iv)
{
   return 0;
}

int bigmac_aes_256_cbc_decrypt_80BDE6(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, unsigned char* iv)
{
   return 0;
}

//0x10 - CMAC-AES-128
//0x18 - CMAC-AES-192 
//0x20 - CMAC-AES-256
int bigmac_execute_cmac_command_4B756(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, int command)
{
   return 0;
}

//0x10 - CMAC-AES-128
//0x18 - CMAC-AES-192 
//0x20 - CMAC-AES-256
int bigmac_execute_cmac_command_80BE98(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, int command)
{
   return 0;
}

int bigmac_read_key_80C64C(int key_slot, unsigned char* key)
{
   return 0;
}

int bigmac_read_key_80B206(int key_slot, unsigned char* key)
{
   return 0;
}

int bigmac_write_key(int key_slot, unsigned char* key)
{
   return 0;
}

int bigmac_sha_256_80BE0C(unsigned char* dst, const unsigned char* src, int size)
{
   return 0;
}

//=====================================

int decrypt_act_4B2E2(const SceSblCommActDataAct* src, SceSblCommActDataAct* dst, const unsigned char* key, const unsigned char* iv)
{
   SceSblCommActDataAct src_copy;
   unsigned char iv_copy[0x20];
   
   memcpy(&src_copy, src, sizeof(SceSblCommActDataAct));

   memcpy(iv_copy, iv, 0x10); // copies 0x20 bytes in original even though AES block size (as well as IV) is always 128 bit!

   int res0 = bigmac_aes_256_cbc_decrypt_4B730((unsigned char*)&src_copy.act_data_enc, (const unsigned char*)&src_copy.act_data_enc, sizeof(SceSblCommActDataEnc), key, iv_copy);
   if(res0 != 0)
      return res0;

   memcpy(dst, &src_copy, sizeof(SceSblCommActDataAct));

   return 0;
}

int compute_and_verify_act_cmac_aes_256_4B3A2(SceSblCommActDataAct* src, unsigned char* key)
{  
   unsigned char act_cmac[0x10] = {0};

   int res0 = bigmac_execute_cmac_command_4B756(act_cmac, (unsigned char*)src, 0x70, key, 0x20);
   if(res0 != 0)
      return res0;
   
   int res1 = memcmp(act_cmac, src->act_data_enc.cmac, 0x10);
   
   if(res1 != 0)
      return 0x800F1327;
   
   return 0;
}

int act_sm_cmd_0x01_0x02_impl_4B43C(const SceSblCommActDataAct* ctx)
{
   SceSblCommActDataAct act_buffer;

   // decrypt part of the buffer

   int res0 = decrypt_act_4B2E2(ctx, &act_buffer, cmd0x01_0x02_key_tmp_4E000, cmd0x01_0x02_iv_tmp_4E020);
   if(res0 != 0)
      return 0x800F1328;

   // check magic

   int res1 = memcmp(act_buffer.act_data_dec.data.magic, act_str_4C428, 4);   
   if(res1 != 0)
      return 0x800F1327;

   // compute cmac of the buffer

   int res2 = compute_and_verify_act_cmac_aes_256_4B3A2(&act_buffer, cmd0x01_0x02_key_tmp_4E000);   
   if(res2 != 0)
      return res2;

   // verify activation key

   int res3 = memcmp(act_buffer.act_data_dec.data.activation_key, act_buffer.act_data_enc.data.activation_key, 0x10);   
   if(res3 != 0)
      return 0x800F1327;

   // verify start validity time
   
   if(act_buffer.act_data_dec.data.start_validity_time != act_buffer.act_data_enc.data.start_validity_time)
      return 0x800F1327;

   return 0;
}

int ActService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   memcpy(cmd0x01_0x02_key_tmp_4E000, cmd0x01_key_4C460, 0x20);

   memcpy(cmd0x01_0x02_iv_tmp_4E020, cmd0x01_iv_4C480, 0x10);
   
   const SceSblCommActData_0x01* ctx_typed = (SceSblCommActData_0x01*)ctx;

   *f00d_resp = act_sm_cmd_0x01_0x02_impl_4B43C(&ctx_typed->act_data);

   return 0;
}

int ActService::service_0x2(int* f00d_resp, void* ctx, int size) const
{  
   memcpy(cmd0x01_0x02_key_tmp_4E000, cmd0x02_key_4C430, 0x20);

   memcpy(cmd0x01_0x02_iv_tmp_4E020, cmd0x02_iv_4C450, 0x10);

   const SceSblCommActData_0x02* ctx_typed = (SceSblCommActData_0x02*)ctx;

   *f00d_resp = act_sm_cmd_0x01_0x02_impl_4B43C(&ctx_typed->act_data);
   
   return 0;
}

int act_sm_cmd_0x04_impl_80B450(SceSblCommActData_0x04* ctx, const unsigned char* key)
{
   SceSblCommActData_0x04_data cmac_input;
   unsigned char actual_cmac[0x10] = {0};

   memcpy(&cmac_input, &ctx->data, sizeof(SceSblCommActData_0x04_data));
   memcpy(actual_cmac, ctx->cmac, 0x10);

   unsigned char result_cmac[0x10] = {0};

   int res0 = bigmac_execute_cmac_command_80BE98(result_cmac, (const unsigned char*)&cmac_input, sizeof(SceSblCommActData_0x04_data), key, 0x20);
   if(res0 != 0)
      return res0;

   int res1 = memcmp(result_cmac, actual_cmac, 0x10);
   if(res1 != 0)
      return 0x800F1327;

   return 0;
}

int ActService::service_0x4(int* f00d_resp, void* ctx, int size) const
{
   *f00d_resp = act_sm_cmd_0x04_impl_80B450((SceSblCommActData_0x04*)ctx, new_service_key_80CF54);

   return 0;
}

int ActService::service_0x5(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0x7(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int bigmac_aes_cbc_256_decrypt_act_buffer_80B3E4(const SceSblCommActDataAct* src, SceSblCommActDataAct* dst, const unsigned char* key, const unsigned char* iv)
{
   unsigned char iv_copy[0x10] = {0};

   memcpy(dst, src, 0x80);

   memcpy(iv_copy, iv, 0x10);

   return bigmac_aes_256_cbc_decrypt_80BDE6((unsigned char*)&dst->act_data_enc, (unsigned char*)&dst->act_data_enc, 0x40, key, iv_copy);
}

int bigmac_cmac_256_verify_act_buffer_80B56E(SceSblCommActDataAct* data, unsigned char* key)
{
   unsigned char cmac[0x10];

   int res0 = bigmac_execute_cmac_command_80BE98(cmac, (const unsigned char*)data, 0x70, key, 0x20);
   if(res0 != 0)
      return res0;

   int res1 = memcmp(cmac, data->act_data_enc.cmac, 0x10);
   if(res1 != 0)
      return 0x800F1327;

   return 0;
}

int bigmac_key_slot_0x509_read_key_part_80C6A6(unsigned char* dst)
{
   unsigned char key_part[0x20];
   
   bigmac_read_key_80C64C(0x509, key_part);
   
   memcpy(dst, key_part, 0x10);
   
   return 0;
}

int bigmac_key_slot_0x50D_read_key_part_80C982(unsigned char* dst)
{
   unsigned char key_part[0x20];

   bigmac_read_key_80C64C(0x50D, key_part);
  
   memcpy(dst, key_part, 0x10);

   return 0;
}

//decrypts act buffer
//verifies cmac
//verifies activation_key in dec vs enc
//verifies activation_key in enc vs key 0x50D
//verifies start_validity_time in dec vs start_validity_time in enc
int bigmac_verify_act_buffer_80B5E6(const SceSblCommActDataAct* src, int* format_version)
{
   SceSblCommActDataAct dec_buffer;

   int res0 = bigmac_aes_cbc_256_decrypt_act_buffer_80B3E4(src, &dec_buffer, key_80CF24, iv_80CF44);
   
   if(res0 != 0)
      return 0x800F1328;

   int res1 = memcmp(dec_buffer.act_data_dec.data.magic, act_str_80CE10, 4);
   if(res1 != 0)
      return 0x800F1327;

   int res2 = bigmac_cmac_256_verify_act_buffer_80B56E(&dec_buffer, key_80CF24);
   if(res2 != 0)
      return res2;

   unsigned char key_0x509[0x10];

   int res3 =  bigmac_key_slot_0x509_read_key_part_80C6A6(key_0x509); //not sure why this key is read - it is not used

   unsigned char key_0x50D[0x10];

   int res4 = bigmac_key_slot_0x50D_read_key_part_80C982(key_0x50D);
   if(res4 != 0)
   {
      memset(key_0x509, 0, 0x10);
      return res4;
   }

   int res5 = memcmp(key_0x50D, dec_buffer.act_data_enc.data.activation_key, 0x10);
   if(res5 != 0)
   {
      memset(key_0x509, 0, 0x10);
      return 0x800F1339;
   }

   int res6 = memcmp(dec_buffer.act_data_dec.data.activation_key, dec_buffer.act_data_enc.data.activation_key, 0x10);
   if(res6 != 0)
   {
      memset(key_0x509, 0, 0x10);
      return 0x800F1327;
   }

   if(dec_buffer.act_data_dec.data.start_validity_time != dec_buffer.act_data_enc.data.start_validity_time)
   {
      memset(key_0x509, 0, 0x10);
      return 0x800F1327;
   }

   *format_version = dec_buffer.act_data_enc.data.format_version1;
   
   memset(key_0x509, 0, 0x10);

   return 0;
}

struct rsa_impl_params
{
   unsigned char* unk0;
   int unk4;
   unsigned char* unk8;
   int unkC;
};

int verify_rsa_impl_80BE46(unsigned char* rsa_work, const unsigned char* rsa_input, const rsa_impl_params* params, const unsigned char* hash, int unk)
{
   return 0;
}

int verify_rsa_80B350(unsigned char* rsa_input, SceSblCommActDataAct* act_buffer)
{
   unsigned char rsa_work[0x100] = {0};

   memset(rsa_work, 0, 0x100);

   unsigned char hash[0x20] = {0};

   int res0 = bigmac_sha_256_80BE0C(hash, (const unsigned char*)&act_buffer, sizeof(SceSblCommActDataAct));
   if(res0 != 0)
      return 0x800F0027;

   rsa_impl_params params;
   
   params.unk0 = byte_80CE18;
   params.unk4 = 0x40;
   params.unk8 = byte_80CF1C;
   params.unkC = 1;
   
   int res1 = verify_rsa_impl_80BE46(rsa_work, rsa_input, &params, hash, 4);
   if(res1 != 0)
      return res1;

   return 0;
}

int bigmac_update_act_data_cmac_80B4EE(SceSblCommActData_0x04* output, const unsigned char* key)
{
   SceSblCommActData_0x04 output_copy;

   memcpy(&output_copy, output, sizeof(SceSblCommActData_0x04));

   unsigned char cmac[0x10] = {0};

   int res0 = bigmac_execute_cmac_command_80BE98(cmac, (const unsigned char*)&output_copy.data, sizeof(SceSblCommActData_0x04_data), key, 0x20);
   if(res0 != 0)
      return res0;

   memcpy(output_copy.cmac, cmac, 0x10);

   memcpy(output, &output_copy, sizeof(SceSblCommActData_0x04));

   return 0;
}

int update_cmac_80B77A(int* f00d_resp, SceSblCommActData_0x0A* input_data)
{
   memset(&input_data->cmd4_output, 0, sizeof(SceSblCommActData_0x04));

   //not sure why fields are swapped. 
   //maybe because new start_validity_time time starts from the old end_validity_time
   //and new end_validity_time does not matter

   memcpy(input_data->cmd4_output.data.magic, act_str_80CE10, 4);
   input_data->cmd4_output.data.issue_number = input_data->new_act_data.act_data_dec.data.issue_number;
   input_data->cmd4_output.data.start_validity_time = input_data->new_act_data.act_data_dec.data.end_validity_time;
   input_data->cmd4_output.data.end_validity_time = input_data->new_act_data.act_data_dec.data.start_validity_time;
   
   int res5 = bigmac_update_act_data_cmac_80B4EE(&input_data->cmd4_output, new_service_key_80CF54);

   *f00d_resp = res5;

   return 0;
}

int ActService::service_0xA(int* f00d_resp, void* ctx, int size) const
{
   int format_version = 0;
   SceSblCommActData_0x0A* input_data = (SceSblCommActData_0x0A*)ctx;

   int res0 = bigmac_verify_act_buffer_80B5E6(&input_data->new_act_data, &format_version);
   if(res0 != 0)
   {
      *f00d_resp = res0;
      return 0;
   }

   int res1 = verify_rsa_80B350(input_data->new_act_data_rsa, &input_data->new_act_data);
   if(res1 != 0)
   {
      if(format_version != 0)
      {
         *f00d_resp = res1;
         return 0;
      }
      else
      {
         *f00d_resp = 0x800F1311;
         return 0;
      }
   }

   //check if cmd4 data is valid - if not then cmac update is required
   int res4 = act_sm_cmd_0x04_impl_80B450(&input_data->cmd4_output, new_service_key_80CF54);
   if(res4 != 0)
      return update_cmac_80B77A(f00d_resp, input_data);

   int res2 = bigmac_verify_act_buffer_80B5E6(&input_data->prev_act_data, &format_version);

   int res3 = verify_rsa_80B350(input_data->prev_act_data_rsa, &input_data->prev_act_data);

   //check if act buffer is valid and rsa is valid and issue numbers are equal
   //if any of this conditions is not met - cmac update is required
   if(res3 != 0 || res2 != 0 || input_data->prev_act_data.act_data_dec.data.issue_number != input_data->cmd4_output.data.issue_number)
      return update_cmac_80B77A(f00d_resp, input_data);

   if(input_data->cmd4_output.data.issue_number >= input_data->new_act_data.act_data_dec.data.issue_number)
   {
      if(input_data->new_act_data.act_data_dec.data.issue_number != 0)
      {
         *f00d_resp = 0x800F1311;
         return 0;
      }
   }

   int start_validity_time = input_data->new_act_data.act_data_dec.data.start_validity_time;
   int end_validity_time = input_data->new_act_data.act_data_dec.data.end_validity_time;
 
   if((end_validity_time - start_validity_time) < 0x02AD8C01)
   {
      return update_cmac_80B77A(f00d_resp, input_data);
   }
   else
   {
      *f00d_resp = 0x800F1311;
      return 0;
   }
}

int bigmac_tweak_key_slot_0x517_80B2BE(int tweak_value, int tweak_index)
{
   unsigned char key[0x20] = {0};

   bigmac_read_key_80B206(0x517, key);

   ((unsigned int*)key)[tweak_index] = tweak_value;
   
   bigmac_write_key(0x517, key);

   return 0;
}

unsigned int bigmac_key_slot_0x50A_get_byte_mix_80B278()
{
   unsigned char key[0x20] = {0};

   bigmac_read_key_80B206(0x50A, key);

   unsigned int v0 = ((unsigned int*)key)[0];
   unsigned int v1 = ((unsigned int*)key)[1];
   unsigned int v2 = ((unsigned int*)key)[2];
   unsigned int v3 = ((unsigned int*)key)[3];
   
   unsigned int val = v0 | v1 | v2 | v3;

   unsigned int interm = (val < 1) ? 1 : 0;

   unsigned int result = interm ^ 1;

   return result;
}

unsigned int bigmac_key_slot_0x50B_get_masked_byte_80B2A2()
{
   unsigned char key[0x20] = {0};

   bigmac_read_key_80B206(0x50B, key);

   return ((unsigned int)key[0]) & 1;
}

int loc_80B93C(int* f00d_resp, SceSblCommActData_0x0B* var_2C, int r8, int r6, int r7)
{
   int r8_local = r8;

   int res0 = bigmac_key_slot_0x50A_get_byte_mix_80B278();
   if(res0 != 0)
   {
      bigmac_tweak_key_slot_0x517_80B2BE(3, 0);

      r8_local = 0;
   }
   else
   {
      
      int res1 = bigmac_key_slot_0x50B_get_masked_byte_80B2A2();
      if(res1 != 0)
      {
         bigmac_tweak_key_slot_0x517_80B2BE(3, 0);

         r8_local = 0;
      }
   }

   var_2C->unkC = r6;
   var_2C->unk8 = r8_local;
   
   *f00d_resp = r7;
   
   return 0;
}

int ActService::service_0xB(int* f00d_resp, void* ctx, int size) const
{
   SceSblCommActData_0x0B* input_data = (SceSblCommActData_0x0B*)ctx;

   int format_version = 0;

   if(input_data->error == 0x800F1329)
      return loc_80B93C(f00d_resp, input_data, 2, 0, 0);

   if(input_data->error != 0)
      return loc_80B93C(f00d_resp, input_data, 1, 0, 0);

   int res0 = bigmac_verify_act_buffer_80B5E6(&input_data->act_data, &format_version);      
   if(res0 != 0)
      return loc_80B93C(f00d_resp, input_data, 1, 0, res0);

   int res1 = verify_rsa_80B350(input_data->act_data_rsa, &input_data->act_data);         
   if(res1 != 0)
      return loc_80B93C(f00d_resp, input_data, 1, 0, res1);

   int res2 = act_sm_cmd_0x04_impl_80B450(&input_data->cmd4_output, new_service_key_80CF54);   
   if(res2 != 0)
      return loc_80B93C(f00d_resp, input_data, 1, 0, res2);

   if(input_data->cmd4_output.data.start_validity_time != input_data->act_data.act_data_dec.data.end_validity_time)
      return loc_80B93C(f00d_resp, input_data, 1, 0, 0);

   if(input_data->cmd4_output.data.issue_number != input_data->act_data.act_data_dec.data.issue_number)
      return loc_80B93C(f00d_resp, input_data, 1, 0, 0);

   //why check time difference? should not it be equal to 0 ?
   int time1 = input_data->act_data.act_data_dec.data.start_validity_time;
   int time2 = input_data->cmd4_output.data.start_validity_time;
   
   int time3;
   if(0x02AD8C00 < time2 - time1)
   {
      time3 = 0;
   }
   else
   {
      time3 = input_data->cmd4_output.data.start_validity_time;
   }
   
   if(input_data->unk4 < time3)
   {
      bigmac_tweak_key_slot_0x517_80B2BE(3, 0);
      return loc_80B93C(f00d_resp, input_data, 0, time3, 0);
   }
   else
   {
      return loc_80B93C(f00d_resp, input_data, 1, 0, 0);
   }
}


int ActService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case ACT_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case ACT_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   case ACT_SERVICE_4:
      return service_0x4(f00d_resp, ctx, size);
   case ACT_SERVICE_5:
      return service_0x5(f00d_resp, ctx, size);
   case ACT_SERVICE_7:
      return service_0x7(f00d_resp, ctx, size);
   case ACT_SERVICE_A:
      return service_0xA(f00d_resp, ctx, size);
   case ACT_SERVICE_B:
      return service_0xB(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
