#include "SceSblACMgr.h"

#include <cstdint>

int SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd(SceUID pid, std::uint64_t* authid)
{   
   if ( !authid)
      return 0x800F0916;

   SceSelfInfo self_info;
   
   if (SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(pid, &self_info) != 0)
      return 0x800F0916;

   *authid = self_info.program_authority_id;
   
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
   SceSelfInfo self_info;
   
   int r0 = SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(pid, &self_info);
   if(r0 != 0)
      return 0;

   int bytePosition = (bit >> 3); // divide by 8
   unsigned char cpByte = *(self_info.capability + bytePosition); //start from offset 0x10

   int shiftValue = ((~bit) & 7); // number of bits to shift to get proper bit in big endian style
   int cpBit = cpByte >> shiftValue; // place bit at proper place by shifting
   int cpBitMasked = cpBit & 1; // apply masking to extract bit

   return cpBitMasked;
}

int sub_8F8570(SceUID pid, int bit)
{
   SceSelfInfo self_info;
   int padding;
   int cookie;
   char dummy;

   int r5 = bit;
   
   int r0 = SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(bit, &self_info);
   if(r0 != 0)
      return r0;
   
   char* r2 = &dummy;
   int r3 = r2 + (r5 >> 3);
   int r5 = ~r5;
   int r5 = r5 & 7;
   int r0 = r3[-0x68];
   int r0 = r0 >> r5;
   int r0 = r0 & 1;   
   
   

   return r0;
}