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

int sub_80BB6E(int,int, char* key, int* mode)
{
   
   add3    $sp, $sp, -0x28
   ldc     $11, $lp
   sw      $3, ($sp)       ; key
   movu    $3, 0x8001
   sw      $6, 0x28+var_10($sp)
   sw      $8, 0x28+var_18($sp)
   sw      $5, 0x28+var_C($sp)
   sw      $7, 0x28+var_14($sp)
   sw      $11, 0x28+var_1C($sp)
   mov     $8, $1
   mov     $6, $2
   sw      $4, 0x28+mode_ptr_24($sp) ; mode
   

   if($2 == $3)
   {
      
      mov     $7, 0 
      movu    $1, byte_812400
      
      goto loc_80BBC8;
   }
   else
   {
      if($3 < $2)
      {
         $0 = 1;
      }
      else
      {
         $0 = 0;
      }

      if($0 != 0)
      {
         
         movu    $3, 0x8002
         
         
         if($2 == $3)
         {
            
            mov     $7, 0
            movu    $1, byte_812440
            
            goto loc_80BBC8;
         }
         else
         {
            
            add     $3, 1
            

            if($2 != $3)
            {
               mov     $5, 0xE
               mov     $0, $5
               return $0;
            }
            else
            {
               
               mov     $7, 0
               movu    $1, byte_812480
               
               goto loc_80BBC8;
            }
         }
      }
      else
      {
         if($2 != 1)
         {
            mov     $5, 0xE
            mov     $0, $5
            return $0;
         }
         else
         {
            
            movu    $7, byte_8124D0
            movu    $1, byte_8124C0
            

            goto loc_80BBC8;
         }
      }
   }

loc_80BBC8:

   mov     $2, 0x21
   mov     $3, 0x345
   bsr     bigmac_aes_256_ecb_decrypt_set_keyslot_from_keyslot_80B40C ; (char* buffer, int keyslot_dest, int keyslot_key)
   mov     $5, $0
   
   if($0 != 0)
   {
      mov     $0, $5

      return $0;
   }

   movu    $1, byte_812E48+0x38
   mov     $2, $8
   mov     $3, 0x20
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   movu    $1, byte_812E48+0x838
   movu    $2, byte_812E48+0x38
   mov     $3, 0x20
   mov     $4, 0x21
   bsr     bigmac_cmac_aes_128_with_keyslot_80B87C ; (char* dst, char* src, int size, int keyslot)
   mov     $5, $0
   
   if($0 != 0)
   {
      mov     $0, $5

      return $0;
   }

   lw      $1, ($sp)
   movu    $2, byte_812E48+0x838
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   add     $6, -1          ; $6 - 1
   mov     $8, 2
   sltu3   $0, $8, $6      ; 2 < ($6 - 1)
   
   if($0 != 0)
   {
      mov     $0, $5

      lw      $2, 0x28+mode_ptr_24($sp)
      mov     $3, 1
      sw      $3, ($2)        ; mode = 1
      return $0;
   }
   
   lw      $2, ($sp)
   movu    $1, byte_812E48+0x38
   mov     $3, 0x10
   bsr     memcpy_812196   ; (char* dst,char* src,int size)
   movu    $1, byte_812E48+0x38
   mov     $2, $7
   mov     $3, 0x24
   mov     $4, 0x348
   bsr     bigmac_aes_128_cbc_decrypt_set_keyslot_from_keyslot_80B486 ; (char* src, char* iv, int keyslot_dst, int keyslot_src)
   mov     $5, $0
   
   if($0 != 0)
   {
      mov     $0, $5
      return $0;
   }
   
   lw      $2, 0x28+mode_ptr_24($sp) ; get mode ptr
   sw      $8, ($2)        ; set mode

   mov     $0, $5

   return $0;
}


int GcAuthMgrService::service_0x1000B_1B(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_1B_80BC44();

   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const
{
   //service_handler_0x1000B_command_1C_80C604();

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
