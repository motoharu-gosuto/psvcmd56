#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

#include <stdint.h>

#include "ResponsePackets.h"
#include "GlobalConstants.h"
#include "Subroutines.h"
#include "CMD56Initialization.h"
#include "UnknownImports.h"

int main(int argc, char* argv[])
{
   InitializeImportsContext();
   InitializeUnknownContext();

   int arg0 = 0x10000;
   sub_CA919C(&arg0);
   
	return 0;
}