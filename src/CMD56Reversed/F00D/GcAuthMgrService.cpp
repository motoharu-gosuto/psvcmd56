#include "GcAuthMgrService.h"

using namespace f00d;

int GcAuthMgrService::service_0x1000B_04(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_4_80CF98();

   return -1;
}

int GcAuthMgrService::service_0x1000B_07(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_7_80CC9C();

   return -1;
}

int GcAuthMgrService::service_0x1000B_0C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_C_80C9F4();

   return -1;
}

int GcAuthMgrService::service_0x1000B_0D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_D_80B2C8();

   return -1;
}

int GcAuthMgrService::service_0x1000B_0E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_E_80C9A6();

   return -1;
}

int GcAuthMgrService::service_0x1000B_10(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_10_80C8CA();

   return -1;
}

int GcAuthMgrService::service_0x1000B_11(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_11_80B372();

   return -1;
}

int GcAuthMgrService::service_0x1000B_12(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_12_80D374();

   return -1;
}

int GcAuthMgrService::service_0x1000B_14(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_14_80C828();

   return -1;
}

int GcAuthMgrService::service_0x1000B_15(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_15_80B72A();

   return -1;
}

int GcAuthMgrService::service_0x1000B_16(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_16_80C7DA();

   return -1;
}

int GcAuthMgrService::service_0x1000B_17(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_17_80C6FC();

   return -1;
}

int GcAuthMgrService::service_0x1000B_18(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_18_80B7DA();

   return -1;
}

int GcAuthMgrService::service_0x1000B_19(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_19_80D2E4();

   return -1;
}

char key_812400[0x10] = {0x6F, 0x22, 0x85, 0xED, 0x46, 0x3A, 0x6E, 0x57, 0xC5, 0xF3, 0x55, 0x0D, 0xDC, 0xC8, 0x1F, 0xEB, };
char key_812440[0x10] = {0xDA, 0x96, 0x08, 0xB5, 0x28, 0x82, 0x5D, 0x6D, 0x13, 0xA7, 0xAF, 0x14, 0x46, 0xB8, 0xEC, 0x08, };
char key_812480[0x10] = {0x36, 0x8B, 0x2E, 0xB5, 0x43, 0x7A, 0x82, 0x18, 0x62, 0xA6, 0xC9, 0x55, 0x96, 0xD8, 0xC1, 0x35, };
char key_8124C0[0x10] = {0x7F, 0x1F, 0xD0, 0x65, 0xDD, 0x2F, 0x40, 0xB3, 0xE2, 0x65, 0x79, 0xA6, 0x39, 0x0B, 0x61, 0x6D, };

char iv_8124D0[0x10] = {0x8B, 0x14, 0xC8, 0xA1, 0xE9, 0x6F, 0x30, 0xA7, 0xF1, 0x01, 0xA9, 0x6A, 0x30, 0x33, 0xC5, 0x5B, };

int bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(char* src, int keyslot_dest, int keyslot_src)
{
   return 0;
}

int bigmac_cmac_aes_128_with_keyslot_80B87C(char* dst, const char* src, int size, int keyslot)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_set_keyslot_from_keyslot_80B486(char* src, char* iv, int keyslot_dst, int keyslot_src)
{
   return 0;
}

int bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(char* src_dst, int size, char* key, int enc_mode)
{
   return 0;
}

int bigmac_generate_random_number_80C462(char* dst,int size)
{
   return 0;
}

int bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(char* src_dst, int size, char* key, int enc_mode)
{
   return 0;
}

int bigmac_cmac_aes_128_with_key_80BA5C(char* src, int size, char* key, char* dst)
{
   return 0;
}

//cmac_input - size 0x20
//cmac_output - size 0x10
int initialize_keyslot_0x21_0x24_with_cmac_80BB6E(char* cmac_input, int key_id, char* cmac_output, int* mode)
{
   switch(key_id)
   {
   case 0x8001:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_812400, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         *mode = 1; //with key
         return 0;
      }
      break;
   case 0x8002:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_812440, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         *mode = 1; //with key
         return 0;
      }
      break;
   case 0x8003:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_812480, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         *mode = 1; //with key
         return 0;
      }
      break;
   case 0x0001:
      {
         int res0 = bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C(key_8124C0, 0x21, 0x345);
         if(res0 != 0)
            return res0;

         int res1 = bigmac_cmac_aes_128_with_keyslot_80B87C(cmac_output, cmac_input, 0x20, 0x21);
         if(res1 != 0)
            return res1;

         int res2 = bigmac_aes_128_cbc_decrypt_set_keyslot_from_keyslot_80B486(cmac_output, iv_8124D0, 0x24, 0x348);
         if(res2 != 0)
            return res2;
   
         *mode = 2; //with keyslot 0x24
         return 0;
      }
      break;
   default:
       return 0xE;
   }
}

struct SceSblSmCommGcAuthMgrData_1000B_1B_input
{
   char packet6_chunk[0x20];
   char packet7_chunk[0x10];
   char packet8_chunk[0x23];
};

int service_handler_0x1000B_command_1B_80BC44(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1B_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1B_input*)ctx->data;

   char drv_key[0x10];
   int mode;

   int res1 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(input_data->packet6_chunk, ctx->packet6_de, drv_key, &mode);
   if(res1 != 0)
      return res1;

   char dec_input[0x20];
   memcpy(dec_input, input_data->packet8_chunk + 3, 0x20);
   
   int res2 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input, 0x20, drv_key, mode);
   
   int res3 = memcmp(input_data->packet7_chunk + 1, dec_input + 0x11, 0xF);
   if(res3 != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_1B(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   service_handler_0x1000B_command_1B_80BC44(f00d_resp, ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

struct SceSblSmCommGcAuthMgrData_1000B_1C_input
{
   char packet6_chunk[0x20];
   char packet8_chunk[0x20]; 
};

struct SceSblSmCommGcAuthMgrData_1000B_1C_output
{
   char command;
   char unknown;
   char size;
   char data[0x30];
};

int service_handler_0x1000B_command_1C_80C604(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1C_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1C_input*)ctx->data;

   int mode;
   char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(input_data->packet6_chunk, ctx->packet6_de, drv_key, &mode);
   if(res0 != 0)
      return res0;

   char dec_input[0x20];
   memcpy(dec_input, input_data->packet8_chunk, 0x20);

   int res2 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input, 0x20, drv_key, mode);

   char dec_part0[0x10];
   char dec_part1[0x10];
                           
   memcpy(dec_part0, dec_input + 0x00, 0x10);
   memcpy(dec_part1, dec_input + 0x10, 0x10);

   dec_part0[0] |= 0x80;
   dec_part1[0] |= 0x80;

   char session_id[0x20];
   
   int res3 = bigmac_generate_random_number_80C462(session_id, 0x20);
   if(res3 != 0)
      return 5;

   char enc_output[0x30];
   
   memcpy(enc_output + 0x00, session_id, 0x10);
   memcpy(enc_output + 0x10, dec_part1, 0x10);
   memcpy(enc_output + 0x20, dec_part0, 0x10);

   int res4 = bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(enc_output, 0x30, drv_key, mode);

   int response_size = 0x33;
   
   ctx->size = response_size;

   SceSblSmCommGcAuthMgrData_1000B_1C_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_1C_output*)ctx->data;
   output_data->command = 0xA3;
   output_data->unknown = 0;
   output_data->size = response_size;
   
   memcpy(output_data->data, enc_output, 0x30);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   service_handler_0x1000B_command_1C_80C604(f00d_resp, ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  // 0x40 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int initialize_keyslot_0x21_0x24_with_cmac_and_dec_80BCB6(char* cmac_input, int key_id, char* src, char* dst)
{
   int mode;
   char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(cmac_input, key_id, drv_key, &mode);
   if(res0 != 0)
      return res0;

   memcpy(dst, src, 0x10);
   
   int res1 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dst, 0x10, drv_key, mode);
                           
   return res1;
}

struct SceSblSmCommGcAuthMgrData_1000B_1D_input
{
  char packet6_chunk[0x20];
  char packet9_chunk[0x30];
  char packet13_chunk[0x10];
  char packet14_chunk[0x43];
};

int service_handler_0x1000B_command_1D_80BFC0(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx)
{  
   SceSblSmCommGcAuthMgrData_1000B_1D_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1D_input*)ctx->data;

   char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_80BCB6(input_data->packet6_chunk, ctx->packet6_de, input_data->packet9_chunk, drv_key);
   if(res0 != 0)
      return res0;

   char dec_input[0x40];
   memcpy(dec_input, input_data->packet14_chunk + 3, 0x40);

   bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_input, 0x40, drv_key, 1); //dec with key mode

   int res1 = memcmp(input_data->packet13_chunk + 1, dec_input + 9, 0xF);
   if(res1 != 0)
      return 5;

   int res2 = memcmp(input_data->packet6_chunk, dec_input + 0x18, 0x20);
   if(res2 != 0)
      return 5;

   return 0;
}

int GcAuthMgrService::service_0x1000B_1D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   service_handler_0x1000B_command_1D_80BFC0(f00d_resp, ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

struct SceSblSmCommGcAuthMgrData_1000B_1E_input
{
   char packet6_chunk[0x20];
   char packet9_chunk[0x30];
   char parameter; // value 2 or 3
};

struct SceSblSmCommGcAuthMgrData_1000B_1E_output
{
   char command;
   char unknown;
   char size;
   char data[0x30];
};

int service_handler_0x1000B_command_1E_80C4F6(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   SceSblSmCommGcAuthMgrData_1000B_1E_input* input_data = (SceSblSmCommGcAuthMgrData_1000B_1E_input*)ctx->data;

   //derive encryption key

   char drv_key[0x10];

   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_80BCB6(input_data->packet6_chunk, ctx->packet6_de, input_data->packet9_chunk, drv_key);
   if(res0 != 0)
      return res0;

   //generate session id

   char session_id[0x20];

   int res1 = bigmac_generate_random_number_80C462(session_id, 0x20);
   if(res1 != 0)
      return 5;

   //construct challenge

   char enc_output[0x20];

   memcpy(enc_output, session_id, 0x10); // copy 0x10 bytes of session_id
   enc_output[0] |= 0x80; // tweak session_id
   memset(enc_output + 0x10, 0, 0x10); // set other 0x10 bytes to 0
   enc_output[0x1F]= input_data->parameter; // tweak other bytes

   //encrypt challenge
   
   bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E(enc_output, 0x20, drv_key, 1); // enc with key mode

   //construct buffer for cmac

   char cmac_input[0x30];

   cmac_input[0] = 0xB1; // set command
   cmac_input[1] = 0; // set unknown
   cmac_input[2] = 0x33; // set size
   memset(cmac_input + 3, 0, 0xD); // set other bytes to 0
   memcpy(cmac_input + 0x10, enc_output, 0x20); // 0x20 bytes of data that was encrypted

   //calculate cmac

   char cmac_output[0x10];

   bigmac_cmac_aes_128_with_key_80BA5C(cmac_input, 0x30, drv_key, cmac_output);

   //update response size in context

   int response_size = 0x33;

   ctx->size = response_size;

   //construct output

   SceSblSmCommGcAuthMgrData_1000B_1E_output* output_data = (SceSblSmCommGcAuthMgrData_1000B_1E_output*)ctx->data;
   output_data->command = 0xB1;
   output_data->unknown = 0;
   output_data->size = response_size;
   memcpy(output_data->data + 3, enc_output, 0x20); // 0x20 bytes of data that was encrypted
   memcpy(output_data->data + 0x23, cmac_output, 0x10); //0x10 bytes of cmac (same packet header + encrypted data)

   return 0;
}

int GcAuthMgrService::service_0x1000B_1E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   service_handler_0x1000B_command_1E_80C4F6(f00d_resp, ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  //0x51 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int service_handler_0x1000B_command_1F_80BEC4(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   int var_94[0x10];
   int var_84[0x30];
   int var_54[0x10];
   int var_44[0x10];
   int var_34[0x10];

   int r6 = ctx;
   int r2 = ctx->packet6_de;
   int r3 = ctx->data;
   
   ($sp) = r3;
   
   int r1 = r3;
   int r4 = var_34;
   int r3 = r6 + 0x28;
   
   int res0 = initialize_keyslot_0x21_0x24_with_cmac_and_dec_80BCB6(r1, r2, r3, r4);
   if(res0 != 0)
      return res0;

   int r7 = var_94;
   int r1 = r7;
   int r2 = r6 + 0x78;
   int r3 = 3;
   
   memcpy(r1, r2, r3);

   int r1 = var_94+3;
   int r2 = 0;
   int r3 = 0xD;
   
   memset(r1, r2, r3);

   int r3 = r6 + 0x7B;
   int r2 = r3;
   
   var_9C = r3;
   
   int r1 = var_84;
   int r3 = 0x30;
   int r5 = var_44;
   
   memcpy(r1, r2, r3);

   int r1 = r7;
   int r2 = 0x40;
   int r3 = var_34;
   int r4 = r5;
   
   bigmac_cmac_aes_128_with_key_80BA5C(r1, r2, r3, r4);

   int r1 = r6 + 0xAB;
   int r2 = r5;
   int r3 = 0x10;
   
   int res1 = memcmp(r1, r2, r3);
   if(res1 != 0)
      return 5;

   int r1 = r7;
   int r2 = r6 + 0x58;
   int r3 = 0x20;
   
   memcpy(r1, r2, r3);

   int r4 = 1;
   int r1 = r7;
   int r2 = 0x20;
   int r3 = var_34;
   
   bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(r1, r2, r3, r4);

   int r1 = var_54;
   int r2 = r7;
   int r3 = 0x10;
   
   memcpy(r1 , r2, r3);

   int r2 = var_9C;
   int r1 = r7;
   int r3 = 0x30;
   char r5 = var_84+0xF;
   
   memcpy(r1, r2, r3);

   int r1 = r7;
   int r2 = 0x30;
   int r3 = var_34;
   int r4 = 1;
   
   bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(r1, r2, r3, r4);  //dec with key mode

   int r1 = var_54+1;
   int r2 = var_94+1;
   int r3 = 0xF;
   
   int res2 = memcmp(r1, r2, r3);
   if(res2 != 0)
      return 5;

   if(r5 == 3)
      return 0x12;

   int r1 = ($sp);
   int r3 = 0x20;
   
   ctx->size = r3;
   
   int r2 = var_84;
   
   memcpy_812196(r1, r2, r3);
   
   return 0;
}

int GcAuthMgrService::service_0x1000B_1F(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   service_handler_0x1000B_command_1F_80BEC4(f00d_resp, ctx);

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x20;  //0xB3 -> 0x20
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_20(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_20_80BD06();

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x34; //0x116 -> 0x34
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_21(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_21_80C36A();

   return -1;
}

int GcAuthMgrService::service_0x1000B_22(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_22_80C256();

   return -1;
}

int GcAuthMgrService::service_0x1000B_23(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_23_80C04A();

   return -1;
}


int GcAuthMgrService::service_0x1000B(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommGcAuthMgrData_1000B* ctx_cast = (SceSblSmCommGcAuthMgrData_1000B*)ctx;

   switch(ctx_cast->command)
   {
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_04:
      return service_0x1000B_04(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_07:
      return service_0x1000B_07(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0C:
      return service_0x1000B_0C(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0D:
      return service_0x1000B_0D(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0E:
      return service_0x1000B_0E(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_10:
      return service_0x1000B_10(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_11:
      return service_0x1000B_11(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_12:
      return service_0x1000B_12(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_14:
      return service_0x1000B_14(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_15:
      return service_0x1000B_15(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_16:
      return service_0x1000B_16(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_17:
      return service_0x1000B_17(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_18:
      return service_0x1000B_18(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_19:
      return service_0x1000B_19(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1B:
      return service_0x1000B_1B(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1C:
      return service_0x1000B_1C(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1D:
      return service_0x1000B_1D(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1E:
      return service_0x1000B_1E(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1F:
      return service_0x1000B_1F(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_20:
      return service_0x1000B_20(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_21:
      return service_0x1000B_21(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_22:
      return service_0x1000B_22(f00d_resp, ctx_cast, size);
   case GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_23:
      return service_0x1000B_23(f00d_resp, ctx_cast, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }

   return 0;
}

int GcAuthMgrService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case GCAUTHMGR_SERVICE_1000B:
      return service_0x1000B(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
