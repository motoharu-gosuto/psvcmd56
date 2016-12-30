#include <stdint.h>
#include <exception>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "Imports.h"
#include "Constants.h"
#include "ResponsePackets.h"
#include "GlobalVariables.h"

// OTHER IMPORTS

//this is wrapper for memcpy with ability to throw breakpoint exception
//throwing condition is size assert
void* SceSblGcAuthMgr_SceSysclibForDriver_imp_8a0b0815(void * destination, const void * source, size_t num, int assert_size)
{
   if(num >= assert_size)
      throw std::runtime_error("BKPT 0x81");
   else
      return memcpy(destination, source, num);
}

//SD CARD IMPORTS

sd_context _C78040_CTX_ARRAY[3];

//get context from array
sd_context* SceSblGcAuthMgr_SceSdifForDriver_imp_6a71987f(int index)
{
   return &_C78040_CTX_ARRAY[index];
}

//initialize sd card
int SceSblGcAuthMgr_SceSdifForDriver_imp_22c82e79(int index, sd_context** element)
{
   return 0;
}

//CMD56_REQUEST
int SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(sd_context* ctx, char* buffer, int size)
{
   //TODO:
   //here will just print to console - this would be useful for observation

   int32_t maxSize = 0x50; //only print part of the packet, ommit zeroes

   std::cout << "packet:";

   for(int32_t i = 0; i < maxSize; i++)
   {
      if((i % 0x10) == 0)
         std::cout << std::endl;
      std::cout << std::hex << std::setfill('0')  << std::setw(2) << (((int)buffer[i]) & 0xFF) << " ";
   }

   std::cout << std::endl;

   return 0;
}

//originally this method had 3 arguments
//I added one more called index to emulate returning of different packets
//CMD56_RESPONSE
int SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(sd_context* ctx, char* buffer, int size, int index)
{
   memset(buffer, 0, size);

   switch(index)
   {
   case PACKET_2_INDEX:
      memcpy(buffer, responce2, sizeof(responce2));
      return 0;
   case PACKET_4_INDEX:
      memcpy(buffer, responce4, sizeof(responce4));
      return 0;
   case PACKET_6_INDEX:
      memcpy(buffer, responce6, sizeof(responce6));
      return 0;
   case PACKET_8_INDEX:
      memcpy(buffer, responce8, sizeof(responce8));
      return 0;
   case PACKET_10_INDEX:
      memcpy(buffer, responce10, sizeof(responce10));
      return 0;
   case PACKET_12_INDEX:
      memcpy(buffer, responce12, sizeof(responce12));
      return 0;
   case PACKET_14_INDEX:
      memcpy(buffer, responce14, sizeof(responce14));
      return 0;
   case PACKET_16_INDEX:
      memcpy(buffer, responce16, sizeof(responce16));
      return 0;
   case PACKET_18_INDEX:
      memcpy(buffer, responce18, sizeof(responce18));
      return 0;
   case PACKET_20_INDEX:
      memcpy(buffer, responce20, sizeof(responce20));
      return 0;
   }

   return STACK_CHECK_FAIL;
}

//initializes some globals

void InitializeImportsContext()
{
   //TODO: figure out how it is initialized

   _00BD84D8_THREAD_ID = 0xFFFFFFFF;
}