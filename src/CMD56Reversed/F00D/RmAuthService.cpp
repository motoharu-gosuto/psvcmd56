#include "RmAuthService.h"

using namespace f00d;

int RmAuthService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   //this should call shed proxy which will call url executor which will call oracle
   /*
   smc_133_input in;
   in.size = 0x40 + size;
   in.service_id = service_id;
   in.smcArg0 = 0x00;
   in.unk = 0x00;

   memcpy(&in.data, ctx, size);

   SceSblSmSchedProxyForKernel_smc_133_723b382f(&in, 1, &in);
   */

   return 0;
}