#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

#include <stdint.h>

#include "SceSblGcAuthMgr.h"
#include "SceSysroot.h"
#include "SceSdif.h"

#include "initialize_crypt_engine.h"

#include "SceSblSsMgrDmac5Layer.h"

int test_cmd56()
{
   SceSdif_module_start_935cd196();

   SceSblGcAuthMgr_InitializeContext();
   SceSysroot_InitializeContext();

   int arg0 = 0x10000;
   int res = sub_CA919C(&arg0);

   if(res == 0)
      std::cout << "Initialization succeeded" << std::endl;
   else
      std::cout << "Initialization failed: " << std::hex << std::setfill('0') << std::setw(8) << res << std::endl;
   
	return 0;
}

int test_pfs()
{
   #ifdef USE_PSVDMAC5
   if(initialize_dmac5_context() < 0)
      return -1;
   #endif

   CryptEngineWorkCtx work_ctx;
   crypt_engine_init(&work_ctx);

   ScePfsCryptEngineThread_work_219BF20(&work_ctx);

   std::ofstream out("icon0.png", std::ios::out | std::ios::binary);
   out.write((char*)work_ctx.subctx->work_buffer1, work_ctx.subctx->tail_size);
   out.close();

   #ifdef USE_PSVDMAC5
   deinitialize_dmac5_context();
   #endif

   return 0;
}

int main(int argc, char* argv[])
{
   //test_cmd56();

   test_pfs();

   return 0;
}