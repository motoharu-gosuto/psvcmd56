#include "ActService.h"

using namespace f00d;

unsigned char cmd0x02_key_4C430[0x20] = { 0x84, 0x6D, 0x2D, 0xFD, 0x77, 0xD3, 0xC2, 0xE5, 0xF0, 0xE1, 0x7E, 0xB1, 0x8C, 0xC7, 0x86, 0x92,
                                          0x8B, 0x88, 0x1E, 0x2E, 0x17, 0xAE, 0x0C, 0xD8, 0xFD, 0xE8, 0x88, 0x09, 0xD0, 0xD0, 0x33, 0xC5 };

unsigned char cmd0x02_iv_4C450[0x10] = { 0xC8, 0xA0, 0x40, 0x66, 0x2B, 0x10, 0xA1, 0x98, 0x6A, 0x18, 0x94, 0xE9, 0x4F, 0xBE, 0xFC, 0xF0 };

unsigned char cmd0x01_key_4C460[0x20] = { 0x3D, 0x1E, 0xFB, 0x3C, 0xFE, 0xD4, 0x2A, 0x5F, 0x87, 0x12, 0x13, 0xD4, 0xCF, 0x1E, 0x3B, 0x7A,
                                          0x65, 0xF9, 0x27, 0xE2, 0x38, 0x11, 0xB5, 0x94, 0x21, 0x5D, 0x61, 0x6B, 0xE5, 0x9D, 0xA4, 0xD8 };

unsigned char cmd0x01_iv_4C480[0x10] ={ 0xD5, 0x7E, 0x36, 0x99, 0x98, 0x33, 2, 0x61, 0x16, 0x32, 0xDE, 0x33, 0xB1, 0x97, 0xA4, 0x3C };

unsigned char cmd0x01_0x02_key_tmp_4E000[0x20] = {0};

unsigned char cmd0x01_0x02_iv_tmp_4E020[0x10] = {0};

unsigned char act_str_4C428[4] = {'a', 'c', 't', 0};

int bigmac_aes_256_cbc_decrypt_4B730(unsigned char* dst, const unsigned char* src, int size, const unsigned char* key, unsigned char* iv)
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

int decrypt_act_4B2E2(const SceSblCommActData_0x01_0x02* src, SceSblCommActData_0x01_0x02* dst, const unsigned char* key, const unsigned char* iv)
{
   SceSblCommActData_0x01_0x02 src_copy;
   unsigned char iv_copy[0x20];
   
   memcpy(&src_copy, src, sizeof(SceSblCommActData_0x01_0x02));

   memcpy(iv_copy, iv, 0x10); // copies 0x20 bytes in original even though AES block size (as well as IV) is always 128 bit!

   int res0 = bigmac_aes_256_cbc_decrypt_4B730((unsigned char*)&src_copy.act_data_enc, (const unsigned char*)&src_copy.act_data_enc, sizeof(SceSblCommActDataEnc), key, iv_copy);
   if(res0 != 0)
      return res0;

   memcpy(dst, &src_copy, sizeof(SceSblCommActData_0x01_0x02));

   return 0;
}

int compute_and_verify_act_cmac_aes_256_4B3A2(SceSblCommActData_0x01_0x02* src, unsigned char* key)
{  
   unsigned char act_cmac[0x20] = {0};

   int res0 = bigmac_execute_cmac_command_4B756(act_cmac, (unsigned char*)src, 0x70, key,0x20);
   if(res0 != 0)
      return res0;
   
   int res1 = memcmp(act_cmac, src->act_data_enc.cmac, 0x10);
   
   if(res1 != 0)
      return 0x800F1327;
   
   return 0;
}

int act_sm_cmd_0x01_0x02_impl_4B43C(const SceSblCommActData_0x01_0x02* ctx)
{
   SceSblCommActData_0x01_0x02 act_buffer;

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
   
   *f00d_resp = act_sm_cmd_0x01_0x02_impl_4B43C((SceSblCommActData_0x01*)ctx);

   return 0;
}

int ActService::service_0x2(int* f00d_resp, void* ctx, int size) const
{  
   memcpy(cmd0x01_0x02_key_tmp_4E000, cmd0x02_key_4C430, 0x20);

   memcpy(cmd0x01_0x02_iv_tmp_4E020, cmd0x02_iv_4C450, 0x10);

   *f00d_resp = act_sm_cmd_0x01_0x02_impl_4B43C((SceSblCommActData_0x02*)ctx);
   
   return 0;
}

int service_0x4_impl(SceSblCommActData_0x04* ctx, const unsigned char* key)
{
   SceSblCommActData_0x04_data cmac_input;
   unsigned char actual_cmac[0x10] = {0};

   memcpy(&cmac_input, &ctx->data, sizeof(SceSblCommActData_0x04_data));
   memcpy(actual_cmac, ctx->cmac, 0x10);

   unsigned char result_cmac[0x20] = {0}; // original size is only 0x10

   int res0 = bigmac_execute_cmac_command_80BE98(result_cmac, (const unsigned char*)&cmac_input, sizeof(SceSblCommActData_0x04_data), key, 0x20);
   if(res0 != 0)
      return res0;

   int res2 = memcmp(result_cmac, actual_cmac, 0x10);
   if(res2 != 0)
      return 0x800F1327;

   return 0;
}

unsigned char new_service_key_80CF54[0x20] = { 0x5A, 0x91, 0xFC, 0x74, 0xA8, 0x2B, 0xE3, 0xF2, 0xB8, 0xF4, 0xDB, 0x60, 0x70, 0xA0, 0x99, 0xA2,
                                               0xBD, 0xF0, 0xE, 0x7B, 0xF0, 0xE, 0x7B, 0xF0, 0x8B, 0x68, 0x55, 0x34, 0xA0, 0x64, 0x6D, 0x87 };

int ActService::service_0x4(int* f00d_resp, void* ctx, int size) const
{
   *f00d_resp = service_0x4_impl((SceSblCommActData_0x04*)ctx, new_service_key_80CF54);

   return -1;
}

int ActService::service_0x5(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0x7(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0xA(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0xB(int* f00d_resp, void* ctx, int size) const
{
   return -1;
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
