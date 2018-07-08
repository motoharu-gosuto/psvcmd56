#include "sceAppMgrWorkDirMountForDriver_3a0a9b82.h"

#include "SceSblACMgr.h"
#include "sceAppMgrGenericDataMount.h"

int SceAppMgrForDriver_sceAppMgrWorkDirMountForDriver_3a0a9b82(int mountId, char *mountPoint)
{
   if (mountId != 0xCA)
   {
      if(mountId < 0xC8 || mountId > 0xCE)
         return 0x80800001;

      switch(mountId)
      {
         case 0xC8:
         case 0xC9:
         case 0xCB:
         case 0xCC:
         case 0xCE:
            return w_sceAppMgrGenericDataMount_23E1014(0, mountId, mountPoint);
         default:
            return 0x80800001;
      }
   }
   else
   {
      if (SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7(0))
         return w_sceAppMgrGenericDataMount_23E1014(0, mountId, mountPoint);
      return 0x80800009;
   }
}