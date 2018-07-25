#include "SceMsifTests.h"

#include <string>
#include <iostream>

#include "SceMsifHashTableVerify.h"

void test0()
{
   unsigned int array0[32];
   memset(array0, 0, sizeof(array0));

   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   int res = block_memcmp_C8EADC((unsigned char*)array0, (unsigned char*)array1, 32);
   if(res != 0)
      std::cout << "test0: FAIL" << std::endl;
}

void test1()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   int res = block_memcmp_C8EADC((unsigned char*)array1, (unsigned char*)array1, 32);
   if(res != 0)
      std::cout << "test1: FAIL" << std::endl;
}

void test2()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   unsigned int array2[32];
   memset(array2, 2, sizeof(array2));

   int res = block_memcmp_C8EADC((unsigned char*)array1, (unsigned char*)array2, 32);
   if(res != 0)
      std::cout << "test2: FAIL" << std::endl;
}

void test3()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   unsigned int array2[32];
   memset(array2, 2, sizeof(array2));

   int res = block_memcmp_C8EADC((unsigned char*)array2, (unsigned char*)array1, 32);
   if(res != 1)
      std::cout << "test3: FAIL" << std::endl;
}

void test4()
{
   unsigned char buffer0[0x1C] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B};
   unsigned char buffer1[0x1C] = {0};

   unsigned char expected[0x1C] = {0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0xF, 0xE, 0xD, 0xC, 0xB, 0xA, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0};
   reverse_byte_order_C8E3AA(buffer1, buffer0, 0x1C);

   if(memcmp(buffer1, expected, 0x1C) != 0)
      std::cout << "test4: FAIL" << std::endl;
}

//====

void msif_hash_verify_tests()
{
   test0();
   test1();
   test2();
   test3();
   test4();
}