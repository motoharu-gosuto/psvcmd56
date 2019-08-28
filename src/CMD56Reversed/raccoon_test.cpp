#include "raccoon_test.h"

#include "raccoon_vita.h"
#include "raccoon_pc.h"

// https://www.lolhax.org/2019/01/02/extracting-keys-f00d-crumbs-raccoon-exploit/

int test_raccoon()
{
   // this part has to be executed on vita side

   unsigned char dec_partial0[0xC] = {0};
   unsigned char dec_partial1[0x8] = {0}; 
   unsigned char dec_partial2[0x4] = {0};
   unsigned char dec_partial3[0x10] = {0};

   int dec_res = raccoon_obtain_decryption_partials(dec_partial0, dec_partial1, dec_partial2, dec_partial3);

   //this part has to be executed on pc side

   unsigned char full_key[0x10] = {0};
   int bruteforce_res = raccoon_bruteforce_key_partials(dec_partial0, dec_partial1, dec_partial2, dec_partial3, full_key);

   return 0;
}
