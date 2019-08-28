#include "raccoon_pc.h"

#include "Crypto/CryptoService.h"

#include "raccoon_bigmac.h"

#include <iostream>

int bruteforce_0xC(const unsigned char* expected_output, const unsigned char* key, unsigned char* key_partials_out, int* num_partials)
{
   unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   unsigned char current_output[0x10] = {0};

   *num_partials = 0;

   auto cryptops = CryptoService::get();

   for(int i0 = 0; i0 <= 0xFF; i0++)
   {
      std::cout << i0 << std::endl;

      current_key[0xC] = i0;

      for(int i1 = 0; i1 <= 0xFF; i1++)
      {
         current_key[0xD] = i1;

         for(int i2 = 0; i2 <= 0xFF; i2++)
         {
            current_key[0xE] = i2;

            for(int i3 = 0; i3 <= 0xFF; i3++)
            {
               current_key[0xF] = i3;

               cryptops->aes_ecb_decrypt(current_key, current_output, 0x10, key, 0x80);

               // only 0xC bytes are known
               if(memcmp(current_output, expected_output, 0xC) == 0)
               {
                  memcpy(key_partials_out, current_key + 0xC, 0x4);
                  (*num_partials)++;
               }
            }
         }
      }
   }

   return 0;
}

int bruteforce_0x8(const unsigned char* expected_output, const unsigned char* key, const unsigned char* key_partial0, unsigned char* key_partials_out, int* num_partials)
{
   unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   unsigned char current_output[0x10] = {0};

   memcpy(current_key + 0xC, key_partial0, 0x4);

   *num_partials = 0;

   auto cryptops = CryptoService::get();

   for(int i0 = 0; i0 <= 0xFF; i0++)
   {
      std::cout << i0 << std::endl;

      current_key[0x8] = i0;

      for(int i1 = 0; i1 <= 0xFF; i1++)
      {
         current_key[0x9] = i1;

         for(int i2 = 0; i2 <= 0xFF; i2++)
         {
            current_key[0xA] = i2;

            for(int i3 = 0; i3 <= 0xFF; i3++)
            {
               current_key[0xB] = i3;

               cryptops->aes_ecb_decrypt(current_key, current_output, 0x10, key, 0x80);

               // only 0x8 bytes are known
               if(memcmp(current_output, expected_output, 0x8) == 0)
               {
                  memcpy(key_partials_out, current_key + 0x8, 0x4);
                  (*num_partials)++;
               }
            }
         }
      }
   }

   return 0;
}

int bruteforce_0x4(const unsigned char* expected_output, const unsigned char* key, const unsigned char* key_partial0, const unsigned char* key_partial1, unsigned char* key_partials_out, int* num_partials)
{
   unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   unsigned char current_output[0x10] = {0};

   memcpy(current_key + 0xC, key_partial0, 0x4);
   memcpy(current_key + 0x8, key_partial1, 0x4);

   *num_partials = 0;

   auto cryptops = CryptoService::get();

   for(int i0 = 0; i0 <= 0xFF; i0++)
   {
      std::cout << i0 << std::endl;

      current_key[0x4] = i0;

      for(int i1 = 0; i1 <= 0xFF; i1++)
      {
         current_key[0x5] = i1;

         for(int i2 = 0; i2 <= 0xFF; i2++)
         {
            current_key[0x6] = i2;

            for(int i3 = 0; i3 <= 0xFF; i3++)
            {
               current_key[0x7] = i3;

               cryptops->aes_ecb_decrypt(current_key, current_output, 0x10, key, 0x80);

               // only 0x4 bytes are known
               if(memcmp(current_output, expected_output, 0x4) == 0)
               {
                  memcpy(key_partials_out, current_key + 0x4, 0x4);
                  (*num_partials)++;
               }
            }
         }
      }
   }

   return 0;
}

int bruteforce_0x0(const unsigned char* expected_output, const unsigned char* input, const unsigned char* key_partial0, const unsigned char* key_partial1, const unsigned char* key_partial2, unsigned char* key_partials_out, int* num_partials)
{
   unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   unsigned char current_output[0x10] = {0};

   memcpy(current_key + 0xC, key_partial0, 0x4);
   memcpy(current_key + 0x8, key_partial1, 0x4);
   memcpy(current_key + 0x4, key_partial2, 0x4);

   *num_partials = 0;

   auto cryptops = CryptoService::get();

   for(int i0 = 0; i0 <= 0xFF; i0++)
   {
      std::cout << i0 << std::endl;

      current_key[0x0] = i0;

      for(int i1 = 0; i1 <= 0xFF; i1++)
      {
         current_key[0x1] = i1;

         for(int i2 = 0; i2 <= 0xFF; i2++)
         {
            current_key[0x2] = i2;

            for(int i3 = 0; i3 <= 0xFF; i3++)
            {
               current_key[0x3] = i3;

               cryptops->aes_ecb_decrypt(input, current_output, 0x10, current_key, 0x80);

               // 0x10 bytes are known
               if(memcmp(current_output, expected_output, 0x10) == 0)
               {
                  memcpy(key_partials_out, current_key, 0x4);
                  (*num_partials)++;
               }
            }
         }
      }
   }

   return 0;
}

// protection against collisions

int test_full_key(const unsigned char* input, const unsigned char* full_key, const unsigned char* expected_output)
{
   auto cryptops = CryptoService::get();

   unsigned char current_output[0x10] = {0};
   cryptops->aes_ecb_decrypt(input, current_output, 0x10, full_key, 0x80);

   if(memcmp(current_output, expected_output, 0x10) == 0)
      return 0;

   return -1;
}

#define N_PARTIALS_TO_STORE 0x10

// keep in mind that when bruteforcing key partials
// we only know some of the bytes of corresponding decryption partials
// this may lead to collisions

int raccoon_bruteforce_key_partials(const unsigned char* dec_partial0, const unsigned char* dec_partial1, const unsigned char* dec_partial2, const unsigned char* dec_partial3, unsigned char* full_key_out)
{
   // choose keys

   unsigned char key_0x519[0x20] = {0};

   //-------------bruteforce 0xC - 0xF ----------------------

   unsigned char key_partials0[0x4 * N_PARTIALS_TO_STORE] = {0}; // place for 0x10 partials
   int num_partials0 = 0;
   bruteforce_0xC(dec_partial0, key_0x519, key_partials0, &num_partials0);

   //-------------bruteforce 0x8 - 0xB ----------------------

   for(int i = 0; i < num_partials0; i++)
   {
      unsigned char key_partials1[0x4 * N_PARTIALS_TO_STORE] = {0}; // place for 0x10 partials
      int num_partials1 = 0;

      bruteforce_0x8(dec_partial1, key_0x519, key_partials0 + i * 0x4, key_partials1, &num_partials1);

      //-------------bruteforce 0x4 - 0x7 ----------------------

      for(int j = 0; j < num_partials1; j++)
      {         
         unsigned char key_partials2[0x4 * N_PARTIALS_TO_STORE] = {0}; // place for 0x10 partials
         int num_partials2 = 0;

         bruteforce_0x4(dec_partial2, key_0x519, key_partials0 + i * 0x4, key_partials1 + j * 0x4, key_partials2, &num_partials2);

         //-------------bruteforce 0x0 - 0x3 ----------------------

         for(int k = 0; k < num_partials2; k++)
         {
            unsigned char key_partials3[0x4 * N_PARTIALS_TO_STORE] = {0}; // place for 0x10 partials
            int num_partials3 = 0;

            unsigned char input3[0x10] = {0};  // chosen plain text

            bruteforce_0x0(dec_partial3, input3, key_partials0 + i * 0x4, key_partials1 + j * 0x4, key_partials2 + k * 0x4, key_partials3, &num_partials3);

            //------------- print results ----------------------

            for(int m = 0; m < num_partials3; m++)
            {
               unsigned char full_key[0x10] = {0};
               memcpy(full_key + 0x0, key_partials3 + m * 0x4, 0x4);
               memcpy(full_key + 0x4, key_partials2 + k * 0x4, 0x4);
               memcpy(full_key + 0x8, key_partials1 + j * 0x4, 0x4);
               memcpy(full_key + 0xC, key_partials0 + i * 0x4, 0x4);

               if(test_full_key(input3, full_key, dec_partial3) == 0)
               {
                  memcpy(full_key_out, full_key, 0x10);

                  return 0;
               }
            }
         }
      }
   }

   return -1;
}