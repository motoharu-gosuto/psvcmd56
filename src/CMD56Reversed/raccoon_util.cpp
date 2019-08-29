#include "raccoon_util.h"

#include <iostream>
#include <iomanip>

int print_byte_array(const unsigned char* data, int size)
{
   for(int i = 0; i < size; i++)
   {
      std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
   }

   std::cout << std::endl;

   return 0;
}