#include "SceSblAuthMgr.h"

#include "F00D/SceSblDMAC5DmacKRBase.h"

int SceSblAuthMgr_sceSblAuthMgrDecBindDataForDriver_41daea12(void *buffer, int num1, void *keypair, int num2, void *arg_0)
{
   return 0;
}

int SceSblAuthMgr_sceSblAuthMgrSetDmac5KeyForKernel_0x122acdea(const unsigned char *key, int key_size, int slot_id, int key_id)
{
   return f00d::SceSblDMAC5DmacKRBase::set_key(key, key_size, slot_id, key_id);
}