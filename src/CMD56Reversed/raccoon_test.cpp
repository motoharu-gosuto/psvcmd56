#include "raccoon_test.h"

#include "raccoon_bigmac.h"
#include "raccoon_vita.h"
#include "raccoon_pc.h"

#include <iostream>
#include <iomanip>

// https://www.lolhax.org/2019/01/02/extracting-keys-f00d-crumbs-raccoon-exploit/

int print_byte_array(const unsigned char* data, int size)
{
   for(int i = 0; i < size; i++)
   {
      std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
   }

   std::cout << std::endl;

   return 0;
}

int test_raccoon()
{
   // this part has to be executed on vita side

   unsigned char encrypted_key[0x10] = {0xdf, 0x9f, 0xe0, 0xd7, 0xcc, 0xc3, 0xb7, 0x0b, 0xea, 0xae, 0xf5, 0x7b, 0xb8, 0x87, 0x0a, 0x92};

   unsigned char dec_partial0[0xC] = {0};
   unsigned char dec_partial1[0x8] = {0}; 
   unsigned char dec_partial2[0x4] = {0};
   unsigned char dec_partial3[0x10] = {0};

   int dec_res = raccoon_obtain_decryption_partials(encrypted_key, KEYSLOT_0x204, KEYSLOT_0x0, dec_partial0, dec_partial1, dec_partial2, dec_partial3);

   //this part has to be executed on pc side

   unsigned char full_key[0x10] = {0};
   int bruteforce_res = raccoon_bruteforce_key_partials(dec_partial0, dec_partial1, dec_partial2, dec_partial3, full_key);

   print_byte_array(full_key, 0x10);

   return 0;
}
