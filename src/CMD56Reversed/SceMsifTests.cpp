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

void test2()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   int res = block_memcmp_C8EADC((unsigned char*)array1, (unsigned char*)array1, 32);
   if(res != 0)
      std::cout << "test2: FAIL" << std::endl;
}

void test4()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   unsigned int array2[32];
   memset(array2, 2, sizeof(array2));

   int res = block_memcmp_C8EADC((unsigned char*)array1, (unsigned char*)array2, 32);
   if(res != 0)
      std::cout << "test4: FAIL" << std::endl;
}

void test6()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   unsigned int array2[32];
   memset(array2, 2, sizeof(array2));

   int res = block_memcmp_C8EADC((unsigned char*)array2, (unsigned char*)array1, 32);
   if(res != 1)
      std::cout << "test6: FAIL" << std::endl;
}

//====

void test1()
{
   unsigned int array0[32];
   memset(array0, 0, sizeof(array0));

   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   int res = block_is_zero_or_memcmp_C8E3EE((unsigned char*)array0, (unsigned char*)array1, 32);
   if(res != 0)
      std::cout << "test1: FAIL" << std::endl;
}

void test3()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   int res = block_is_zero_or_memcmp_C8E3EE((unsigned char*)array1, (unsigned char*)array1, 32);
   if(res != 0)
      std::cout << "test3: FAIL" << std::endl;
}

void test5()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   unsigned int array2[32];
   memset(array2, 2, sizeof(array2));

   int res = block_is_zero_or_memcmp_C8E3EE((unsigned char*)array1, (unsigned char*)array2, 32);
   if(res != 1)
      std::cout << "test5: FAIL" << std::endl;
}

void test7()
{
   unsigned int array1[32];
   memset(array1, 1, sizeof(array1));

   unsigned int array2[32];
   memset(array2, 2, sizeof(array2));

   int res = block_is_zero_or_memcmp_C8E3EE((unsigned char*)array2, (unsigned char*)array1, 32);
   if(res != 0)
      std::cout << "test7: FAIL" << std::endl;
}

void msif_hash_verify_tests()
{
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}