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

//TODO

//questions:
//for sub_CA8EA0:
//does 0x116 data overflow _00BDD018 buffer since it is 0x34 bytes long ? or this is generic buffer with variable size

//for sub_CAC924:
//complicated conditional logic - I hope I reimplemented it correctly
//some commands do not match to corresponding sizes (this includes size 0x116)

//initialize_sd - check initialization order
//sub_CA8D30 - does it return -1 ?
//for packet6 - memset(_00BDCFF8, 0x00, 0x20); - is call condition correct?
//packet7 - if((_00BDCDF4_PACKET6_DE & (~0x8000)) != 1) - this condition is weird

int main(int argc, char* argv[])
{
   int arg0 = 0x10000;
   sub_CA919C(&arg0);
   
	return 0;
}