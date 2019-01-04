#include "UTokenService.h"

using namespace f00d;

int UTokenService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UTokenService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int UTokenService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case UTOKEN_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case UTOKEN_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
