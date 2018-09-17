#include "RmAuthService.h"

#include "SceSblDMAC5DmacKRBase.h"

using namespace f00d;

int RmAuthService::service_0x1(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommMsifData_1* ctx_cast = (SceSblSmCommMsifData_1*)ctx;

   //this should call shed proxy which will call url executor which will call oracle
   /*
   SceSblSmschedCallFuncCommand cmd;
   cmd.size = 0x40 + size;
   cmd.service_id = service_id;
   cmd.response = 0x00;
   cmd.unk2 = 0x00;

   memcpy(&cmd.data, ctx, size);

   SceSblSmSchedProxyForKernel_smc_133_sceSblSmSchedCallFunc_723b382f(id, 1, &cmd);
   */

   return 0;
}

int RmAuthService::service_0x2(int* f00d_resp, void* ctx, int size) const
{
   SceSblSmCommMsifData_2* ctx_cast = (SceSblSmCommMsifData_2*)ctx;

   //this should call shed proxy which will call url executor which will call oracle
   /*
   SceSblSmschedCallFuncCommand cmd;
   cmd.size = 0x40 + size;
   cmd.service_id = service_id;
   cmd.response = 0x00;
   cmd.unk2 = 0x00;

   memcpy(&cmd.data, ctx, size);

   SceSblSmSchedProxyForKernel_smc_133_sceSblSmSchedCallFunc_723b382f(id, 1, &cmd);
   */

   return 0;
}

int RmAuthService::dispatch(int service_id, int* f00d_resp, void* ctx, int size) const
{
   switch(service_id)
   {
   case RM_AUTH_SM_SERVICE_1:
      return service_0x1(f00d_resp, ctx, size);
   case RM_AUTH_SM_SERVICE_2:
      return service_0x2(f00d_resp, ctx, size);
   default:
      //not implemented command
      *f00d_resp = -1;
      return -1;
   }
}