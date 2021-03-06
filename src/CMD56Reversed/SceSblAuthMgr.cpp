#include "SceSblAuthMgr.h"

#include "SceSblSsSmComm.h"
#include "F00D/IF00DService.h"

int SceSblAuthMgr_sceSblAuthMgrDecBindDataForDriver_41daea12(void *buffer, int num1, void *keypair, int num2, void *arg_0)
{
   return 0;
}

// key_size - in bytes
int SceSblAuthMgr_sceSblAuthMgrSetDmac5KeyForKernel_0x122acdea(const unsigned char *key, int key_size, int slot_id, int key_id)
{
   int id = 0;
   if(SceSblSmCommForKernel_sceSblSmCommStartSm_Emu(KPRX_AUTH_SERVICE, &id) < 0)
      return -1;

   SceSblSmCommKprxAuthData_50001 ctx;
   memset((char*)&ctx, 0, sizeof(SceSblSmCommKprxAuthData_50001));
   
   memcpy(ctx.key, key, key_size);

   ctx.key_size = key_size;
   ctx.key_id = key_id;
   ctx.slot_id = slot_id;

   int f00d_resp = 0;
   int res0 = SceSblSmCommForKernel_sceSblSmCommCallFunc_Emu(id, KPRX_AUTH_SERVICE_50001, &f00d_resp, &ctx, 0x110);
   if(res0 != 0)
      f00d_resp = -1;

   int res1 = SceSblSmCommForKernel_sceSblSmCommStopSm_Emu(id);
   if(res1 != 0)
      return res1;

   return f00d_resp;
}