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

//analog of memcmp or str cmp or strcoll, smth like that
//returns -1, 0
int SceSysclibForDriver_b5a4d745(unsigned char* char0, unsigned char* char1, int len)
{
   int res = memcmp(char0, char1, len);
   return (res != 0) ? -1 : 0;
}

unsigned int SceSysclibForDriver_e46c47e6(unsigned int a1, unsigned int a2, char a3)
{
   unsigned long long v0 = (a1 >> a3);
   
   unsigned int sh1 = (a3 - 0x20);
   
   unsigned long long v1 = sh1 >= 0x20 ? 0 : ((unsigned long long)a2 >> sh1);
   
   unsigned int sh2 = (0x20 - a3);
   
   unsigned long long v2 = sh2 >= 0x20 ? 0 : ((unsigned long long)a2 << sh2);

   return v0 | v1 | v2;
}