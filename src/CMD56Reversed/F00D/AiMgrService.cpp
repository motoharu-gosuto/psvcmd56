#include "AiMgrService.h"

using namespace f00d;

int AiMgrService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int AiMgrService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int AiMgrService::service_0x3(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int AiMgrService::service_0x4(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int AiMgrService::service_0x5(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}


int AiMgrService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case AIMGR_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case AIMGR_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   case AIMGR_SERVICE_3:
      return service_0x3(f00d_resp, ctx, size);
   case AIMGR_SERVICE_4:
      return service_0x4(f00d_resp, ctx, size);
   case AIMGR_SERVICE_5:
      return service_0x5(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}

