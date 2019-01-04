#include "PmService.h"

using namespace f00d;

int PmService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x3(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x4(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x5(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x6(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x7(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x8(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0x9(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int PmService::service_0xA(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}


int PmService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case PM_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case PM_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   case PM_SERVICE_3:
      return service_0x3(f00d_resp, ctx, size);
   case PM_SERVICE_4:
      return service_0x4(f00d_resp, ctx, size);
   case PM_SERVICE_5:
      return service_0x5(f00d_resp, ctx, size);
   case PM_SERVICE_6:
      return service_0x6(f00d_resp, ctx, size);
   case PM_SERVICE_7:
      return service_0x7(f00d_resp, ctx, size);
   case PM_SERVICE_8:
      return service_0x8(f00d_resp, ctx, size);
   case PM_SERVICE_9:
      return service_0x9(f00d_resp, ctx, size);
   case PM_SERVICE_A:
      return service_0xA(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
