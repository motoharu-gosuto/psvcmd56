#include "KprxAuthService.h"

using namespace f00d;

int KprxAuthService::service_0x50001(int* f00d_resp, void* ctx, int size) const
{
   return 0;
}

int KprxAuthService::service_0x60001(int* f00d_resp, void* ctx, int size) const
{
   return 0;
}

int KprxAuthService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case KPRX_AUTH_SERVICE_50001:
      return service_0x50001(f00d_resp, ctx, size);
   case KPRX_AUTH_SERVICE_60001:
      return service_0x60001(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}