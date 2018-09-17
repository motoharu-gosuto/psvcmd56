#include "GcAuthMgrService.h"

using namespace f00d;

int GcAuthMgrService::service_0x1000B(int* f00d_resp, void* ctx, int size) const
{
   //TODO: his code imitates size change and encryption - need to figure out what is going on here

   SceSblSmCommGcData_1000B* ctx_cast = (SceSblSmCommGcData_1000B*)ctx;

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
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }

   //this should call shed proxy which will call url executor which will call oracle
   /*
   SceSblSmschedCallFuncCommand cmd;
   cmd.size = 0x40 + size;
   cmd.service_id = service_id;
   cmd.response = 0x00;
   cmd.unk2 = 0x00;

   memcpy(&cmd.data, ctx, size);

   SceSblSmSchedProxyForKernel_smc_133_sceSblSmSchedCallFunc_723b382f(id, 1, &cmd);
   */

   return 0;
}

int GcAuthMgrService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case GC_AUTH_MGR_SERVICE_1000B:
      return service_0x1000B(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}