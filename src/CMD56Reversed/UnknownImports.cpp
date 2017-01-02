#include <string>
#include <chrono>
#include <stdint.h>

#include "UnknownImports.h"
#include "Subroutines.h"
#include "Constants.h"
#include "CryptoLayer.h"

int SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(char* buffer)
{
  return SceSblSsMgr_SceSblSsMgrForDriver_exp_ac57f4f0(buffer);
}

//=========================================

//CRITICAL - buffer init



//assume - init
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1)
{
   return SceSblSsSmComm_SceSblSmCommForKernel_exp_039c73b1(r0, r1, r2, r3, ctx, unk1);
}

//assume - gen/hash
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0)
{
   return SceSblSsSmComm_SceSblSmCommForKernel_exp_db9fc204(r0, r1, r2, r3, unk0);
}

//assume - deinit
int SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(int unk)
{
   return SceSblSsSmComm_SceSblSmCommForKernel_exp_0631f8ed(unk);
}

//=========================================

//NON CRITICAL

//assume - some sort of deinit
int SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83()
{
   return 0;
}



//initializes some globals

void InitializeUnknownContext()
{
   //TODO: figure out how this is initialized in reality
   _8BF5F8_g0.unk_0 = &_8BF5F8_g1;
   _8BF5F8_g1.unk_3A0 = _8BF5F8_g2;

   _8BF5F8_g2[0].unk_0 = 0xFFFFFFFF;
   _8BF5F8_g2[0].unk_4 = 0xFFFFFFFF;
   
   _8BF5F8_g2[1].unk_0 = 0xDDDDDDDD;
   _8BF5F8_g2[1].unk_4 = 0xDDDDDDDD;

   _8BF5F8_g2[2].unk_0 = 0xAAAAAAAA;
   _8BF5F8_g2[2].unk_4 = 0xAAAAAAAA;
}