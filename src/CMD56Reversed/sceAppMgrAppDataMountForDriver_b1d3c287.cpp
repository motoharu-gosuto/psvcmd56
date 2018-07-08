#include "sceAppMgrAppDataMountForDriver_b1d3c287.h"
#include "sceAppMgrGenericDataMount.h"

int SceAppMgrForDriver_sceAppMgrAppDataMountForDriver_b1d3c287(int mountId, char *mountPoint)
{
   if(mountId < 0x64 || mountId > 0x70)
      return 0x80800001;

   switch(mountId)
   {
      case 0x64:
      case 0x65:
      case 0x66:
      case 0x67:
      case 0x69:
      case 0x6C:
      case 0x6D:
      case 0x6F:
      case 0x70:
         return w_sceAppMgrGenericDataMount_23E1014(0, mountId, mountPoint);
      default:
         return 0x80800001;
   }
}