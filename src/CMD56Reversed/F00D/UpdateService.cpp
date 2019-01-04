#include "UpdateService.h"

using namespace f00d;

int UpdateService::service_10002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_20002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_30002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_40002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_50002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_60002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_70002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_80002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_90002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_A0002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_B0002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_C0002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::service_D0002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UpdateService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case UPDATE_SERVICE_10002:
      return service_10002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_20002:
      return service_20002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_30002:
      return service_30002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_40002:
      return service_40002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_50002:
      return service_50002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_60002:
      return service_60002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_70002:
      return service_70002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_80002:
      return service_80002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_90002:
      return service_90002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_A0002:
      return service_A0002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_B0002:
      return service_B0002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_C0002:
      return service_C0002(f00d_resp, ctx, size);
   case UPDATE_SERVICE_D0002:
      return service_D0002(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
