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
   CryptEngineWorkCtx work_ctx;
   crypt_engine_init(&work_ctx);

   derive_keys_ctx drv_ctx;
   memset(&drv_ctx, 0, sizeof(derive_keys_ctx));

   derive_data_ctx_keys(work_ctx.subctx->data, &drv_ctx);

   return 0;
}

int main(int argc, char* argv[])
{
   //test_cmd56();

   test_pfs();

   return 0;
}