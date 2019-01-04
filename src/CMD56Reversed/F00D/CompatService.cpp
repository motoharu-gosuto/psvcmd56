#include "CompatService.h"

using namespace f00d;

int CompatService::service_0x10006(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int CompatService::service_0x20006(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int CompatService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case COMPAT_SERVICE_10006:
      return service_0x10006(f00d_resp, ctx, size);
   case COMPAT_SERVICE_20006:
      return service_0x20006(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
