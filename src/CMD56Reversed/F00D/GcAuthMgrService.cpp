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

struct SceSblSmCommGcAuthMgrData_1000B_input
{
   char packet6_chunk[0x20];
   char packet7_chunk[0x10];
   char packet8_chunk[0x23];
};

int service_handler_0x1000B_command_1B_80BC44(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx1)
{
   SceSblSmCommGcAuthMgrData_1000B_input* data = (SceSblSmCommGcAuthMgrData_1000B_input*)ctx1->data;

   char drv_key[0x10];
   int mode;

   int res1 = initialize_keyslot_0x21_0x24_with_cmac_80BB6E(data->packet6_chunk, ctx1->packet6_de, drv_key, &mode);
   if(res1 != 0)
      return res1;

   char dec_res[0x20];
   memcpy(dec_res, data->packet8_chunk + 3, 0x20);
   
   int res2 = bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE(dec_res, 0x20, drv_key, mode);
   
   int res3 = memcmp(data->packet7_chunk + 1, dec_res + 0x11, 0xF);
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

int service_handler_0x1000B_command_1C_80C604(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx)
{
   add     $sp, -0x20
   lw      $3, (cookie_812E40)
   sw      $5, 0x20+var_C($sp)
   mov     $5, $1
   ldc     $11, $lp
   sw      $7, 0x20+var_14($sp)
   sw      $8, 0x20+var_18($sp)
   sw      $6, 0x20+var_10($sp)
   sw      $11, 0x20+var_1C($sp)
   lw      $2, 0x808($5)
   add3    $sp, $sp, -0x90
   add3    $8, $sp, 0x7C
   sw      $3, 0xB0+cookie_24($sp)
   add     $1, 8
   mov     $3, $8
   add3    $4, $sp, 8
   bsr     initialize_keyslot_0x21_0x24_with_cmac_80BB6E ; (char* cmac_input, int key_id, char* cmac_output, int* mode)
   mov     $7, $0
   
   if(&0 != 0)
   {
      mov     $0, $7
      return $0;
   }

   add3    $6, $sp, 0xC
   mov     $1, $6
   add3    $2, $5, 0x28
   mov     $3, 0x20
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   lw      $4, 0xB0+var_A8($sp)
   mov     $1, $6
   mov     $2, 0x20
   mov     $3, $8
   bsr     bigmac_aes_128_cbc_decrypt_with_mode_select_80B9BE ; (char* src_dst, int size, char* key, int enc_mode)
                           ; 1 - with key
                           ; 2 - with keyslot 0x24
   add3    $1, $sp, 0x5C
   mov     $2, $6
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   add3    $1, $sp, 0x6C
   add3    $2, $sp, 0x1C
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   lb      $3, 0xB0+var_54($sp)
   mov     $2, -0x80
   or      $3, $2
   sb      $3, 0xB0+var_54($sp)
   lb      $3, 0xB0+var_44($sp)
   or      $3, $2
   sb      $3, 0xB0+var_44($sp)
   add3    $3, $sp, 0x3C
   mov     $1, $3
   mov     $2, 0x20
   sw      $3, 0xB0+var_AC($sp)
   bsr     bigmac_generate_random_number_80C462 ; (char* dst,int size)
   mov     $7, $0
   lw      $3, 0xB0+var_AC($sp)
   
   if($0 != 0)
   {
      return 5;
   }

   mov     $1, $6
   mov     $2, $3
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   add3    $1, $sp, 0x1C
   add3    $2, $sp, 0x6C
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   add3    $1, $sp, 0x2C
   add3    $2, $sp, 0x5C
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   lw      $4, 0xB0+var_A8($sp)
   mov     $1, $6
   mov     $3, $8
   mov     $2, 0x30
   bsr     bigmac_aes_128_cbc_encrypt_with_mode_select_80B91E ; (char* src_dst, int size, char* key, int enc_mode)
                           ; 1 - with key
                           ; 2 - with keyslot 0x24
   mov     $3, 0x33
   mov     $2, -0x5D
   sw      $3, 0x80C($5)
   sb      $2, 8($5)
   sb      $3, 0xA($5)
   sb      $7, 9($5)
   add3    $1, $5, 0xB
   mov     $2, $6
   mov     $3, 0x30
   bsr     memcpy_812196   ; (char* dst,char* src,int size)

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

int GcAuthMgrService::service_0x1000B_1D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_1D_80BFC0();

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_1E_80C4F6();

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  //0x51 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1F(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_1F_80BEC4();

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
