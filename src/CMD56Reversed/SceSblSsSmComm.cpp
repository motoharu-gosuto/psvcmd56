#include <string>

#include "SceSblSsSmComm.h"

// =============================

int sub_B86218()
{
   
   return 0;
}

int sub_B862A0()
{
   
   return 0;
}

int sub_B864A8()
{
   
   return 0;
}

//assume - init
int SceSblSmCommForKernel_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1)
{
   //many calls and subroutines

   //TODO: imitating size change and encryption - need to figure out what is going on here

   switch(ctx->command)
   {
   case CAC924_COMMAND_1B:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1C:
      ctx->size = 0x33;  // 0x40 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1D:
      //size is ok
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1E:
      ctx->size = 0x33;  //0x51 -> 0x33
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_1F:
      ctx->size = 0x20;  //0xB3 -> 0x20
      memset(ctx->data, 0xBB, ctx->size);
      break;
   case CAC924_COMMAND_20:
      ctx->size = 0x34; //0x116 -> 0x34
      memset(ctx->data, 0xBB, ctx->size);
      break;
   }

   return 0;

   
}

// =============================

//assume - gen/hash
int SceSblSmCommForKernel_db9fc204(int r0, int r1, int* r2, int* r3, int unk0)
{
   //many globals, functionality is simplier

   return 0;
}

// =============================

int sub_B862A0()
{
   //many globals   
   return 0;
}

//assume - deinit
int SceSblSmCommForKernel_0631f8ed(int unk)
{
   
   return 0;
}