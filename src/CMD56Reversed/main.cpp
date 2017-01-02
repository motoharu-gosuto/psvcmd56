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

int main(int argc, char* argv[])
{
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