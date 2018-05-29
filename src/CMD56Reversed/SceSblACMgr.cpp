#include "SceSblACMgr.h"

#include <cstdint>

int SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd(SceUID pid, std::uint64_t* authid)
{   
   if ( !authid)
      return 0x800F0916;

   SceSelfAuthInfo self_info;
   
   if (SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(pid, &self_info) != 0)
      return 0x800F0916;

   *authid = self_info.auth_id;
   
   return 0;
}

int SceSblACMgrForKernel_sceSblACMgrGetSelfAuthInfoOrDefaultForKernel_7c2af978(SceUID pid, std::uint64_t* authid)
{
   return SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd(pid, authid);
}

int SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7(SceUID pid)
{
  std::uint64_t authid = 0;
  
   if (SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd(pid, &authid) != 0)
      return 0;
    
   if (authid == 0x2800000000000013)
      return 1;

   if (authid == 0x2800000000007009)
      return 1;

   if (authid == 0x2800000000000010)
      return 1;

   if (authid == 0x280000000000002D)
      return 1;
    
   if (authid == 0x2800000000000022)
      return 1;

   if (authid == 0x2800000000000039)
      return 1;
    
   if (authid == 0x2800000000000001)
      return 1;

   return 0;
}

int SceSblACMgrForKernel_sceSblACMgrCheckAuthIdForKernel_f5ad56e4(SceUID pid)
{
   return SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7(pid);
}

int SceSblACMgrForDriver_check_auth_id_4db7f512(SceUID pid)
{
   return 0;
}

int SceSblACMgrForDriver_check_auth_id_456da7ac(SceUID pid)
{
   return 0;
}

int SceSblACMgrForDriver_check_auth_id_c98d82ee(SceUID pid)
{
   return 0;
}

int SceSblACMgrForDriver_sceSblACMgrIsShell_8612b243(SceUID pid)
{
   return 0;
}

int SceSblACMgrForDriver_sceSblACMgrIsNonGameProgram_6c5ab07f(SceUID pid)
{
   return 0;
}

int SceSblACMgrForDriver_sceSblACMgrIsSomething_f5ae24ac(SceUID a1)
{
   return 0;
}