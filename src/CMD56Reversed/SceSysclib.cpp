#include <string>


#include "SceSysclib.h"

//this is wrapper for memcpy with ability to throw breakpoint exception
//throwing condition is size assert
void* SceSysclibForDriver_memcpy_assert_8a0b0815(void * destination, const void * source, size_t num, int assert_size)
{
   if(num >= assert_size)
      throw std::runtime_error("BKPT 0x81");
   else
      return memcpy(destination, source, num);
}

int SceSysclibForDriver_cdf7f155()
{
   return 0;
}