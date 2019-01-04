#include "SpkgVerifierService.h"

using namespace f00d;

int SpkgVerifierService::service_0xE0002(int* f00d_resp, void* ctx, int size) const
{
   return -1;
}

int SpkgVerifierService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case SPKG_VERIFIER_SERVICE_E0002:
      return service_0xE0002(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}