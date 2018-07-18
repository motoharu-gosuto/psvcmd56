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

int SceSblACMgrForDriver_sceSblACMgrHasCapabilityForDriver_c2d1f2fc(SceUID pid, int bit)
{
   PUSH            {R4,R5,LR}
   MOV             R4, #0x9EA004
   SUB             SP, SP, #0x9C
   MOV             R5, R1
   MOV             R1, SP  ; self_info
   LDR             R3, [R4]
   STR             R3, [SP,#0xA8+cookie]
   BLX             SceSblACMgr.SceSysrootForKernel._imp_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066
   
   if(r0 != 0)
   {
      MOVS            R0, #0
   }
   else
   {
      ADD             R2, SP, #0xA8+var_10
      ADD.W           R3, R2, R5,ASR#3
      MVNS            R5, R5
      AND.W           R5, R5, #7
      LDRB.W          R0, [R3,#-0x88]
      ASRS            R0, R5
      AND.W           R0, R0, #1
   }

   LDR             R2, [SP,#0xA8+cookie]
   LDR             R3, [R4]
   
   if(r2 != r3)
   {
      SceSblACMgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
   else
   {
      ADD             SP, SP, #0x9C
      POP             {R4,R5,PC}
   }

   return r0;
}