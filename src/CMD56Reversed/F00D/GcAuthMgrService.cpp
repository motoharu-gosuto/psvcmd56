#include "GcAuthMgrService.h"

using namespace f00d;

int GcAuthMgrService::service_0x1000B_04(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_07(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_0C(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_0D(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_0E(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_10(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_11(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_12(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_14(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_15(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_16(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_17(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_18(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_19(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_1B(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1C(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  // 0x40 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1D(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   //size is ok
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1E(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x33;  //0x51 -> 0x33
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_1F(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x20;  //0xB3 -> 0x20
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_20(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   ctx->size = 0x34; //0x116 -> 0x34
   memset(ctx->data, 0xBB, ctx->size);

   return 0;
}

int GcAuthMgrService::service_0x1000B_21(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_22(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}

int GcAuthMgrService::service_0x1000B_23(int* f00d_resp, SceSblSmCommGcData_1000B* ctx, int size) const
{
   return -1;
}


int GcAuthMgrService::service_0x1000B(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommGcData_1000B* ctx_cast = (SceSblSmCommGcData_1000B*)ctx;

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
