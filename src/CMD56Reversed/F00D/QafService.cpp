#include "QafService.h"

using namespace f00d;


int QafService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int QafService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int QafService::service_0xC(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int QafService::service_0xD(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int QafService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case QAF_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case QAF_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   case QAF_SERVICE_C:
      return service_0xC(f00d_resp, ctx, size);
   case QAF_SERVICE_D:
      return service_0xD(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}
