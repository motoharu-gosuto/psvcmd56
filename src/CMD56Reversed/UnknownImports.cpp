#include <string>
#include <chrono>
#include <stdint.h>

#include "UnknownImports.h"
#include "Subroutines.h"
#include "Constants.h"
#include "CryptoLayer.h"

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