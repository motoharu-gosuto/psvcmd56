#include "GcAuthMgrService.h"

using namespace f00d;

int GcAuthMgrService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   context_db9fc204* ctx_cast = (context_db9fc204*)ctx;

   switch(ctx_cast->command)
   {
   case KIRK_SERVICE_1B:
      //size is ok
      memset(ctx_cast->data, 0xBB, ctx_cast->size);
      break;
   case KIRK_SERVICE_1C:
      ctx_cast->size = 0x33;  // 0x40 -> 0x33
      memset(ctx_cast->data, 0xBB, ctx_cast->size);
      break;
   case KIRK_SERVICE_1D:
      //size is ok
      memset(ctx_cast->data, 0xBB, ctx_cast->size);
      break;
   case KIRK_SERVICE_1E:
      ctx_cast->size = 0x33;  //0x51 -> 0x33
      memset(ctx_cast->data, 0xBB, ctx_cast->size);
      break;
   case KIRK_SERVICE_1F:
      ctx_cast->size = 0x20;  //0xB3 -> 0x20
      memset(ctx_cast->data, 0xBB, ctx_cast->size);
      break;
   case KIRK_SERVICE_20:
      ctx_cast->size = 0x34; //0x116 -> 0x34
      memset(ctx_cast->data, 0xBB, ctx_cast->size);
      break;
   }

   return 0;
}