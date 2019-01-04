#include "ActService.h"

using namespace f00d;

int ActService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0x4(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0x5(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0x7(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0xA(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int ActService::service_0xB(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}


int ActService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case ACT_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   case ACT_SERVICE_4:
      return service_0x4(f00d_resp, ctx, size);
   case ACT_SERVICE_5:
      return service_0x5(f00d_resp, ctx, size);
   case ACT_SERVICE_7:
      return service_0x7(f00d_resp, ctx, size);
   case ACT_SERVICE_A:
      return service_0xA(f00d_resp, ctx, size);
   case ACT_SERVICE_B:
      return service_0xB(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
