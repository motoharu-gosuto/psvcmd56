#include "raccoon_pc_parallel.h"

#include "Crypto/CryptoService.h"

#include "raccoon_util.h"

#include <iostream>
#include <vector>
#include <memory>

#include <iostream>
#include <iomanip>
#include <mutex>

#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

struct key_partial
{
public:
   unsigned char value[0x4];

public:
   key_partial(unsigned char* data)
   {
      memcpy(value, data, 0x4);
   }
};

typedef std::vector<key_partial> key_partial_vector;
typedef std::shared_ptr<key_partial_vector> key_partial_vector_ptr;

// full bruteforcing of 0x4 bytes takes about 6 minutes

class BruteforceWorker_0xC
{
private:
   unsigned char m_expected_output[0xC];
   unsigned char m_key[0x10];

   mutable key_partial_vector_ptr m_key_partials;
   mutable std::shared_ptr<std::mutex> m_mutex_ptr;

   std::shared_ptr<ICryptoOperations> m_cryptops;
   
public:
   BruteforceWorker_0xC(const unsigned char* expected_output, const unsigned char* key)
   {
      memcpy(m_expected_output, expected_output, 0xC);
      memcpy(m_key, key, 0x10);

      m_key_partials = std::make_shared<key_partial_vector>();
      m_mutex_ptr = std::make_shared<std::mutex>();

      m_cryptops = CryptoService::get();
   }

public:
   void operator()(const tbb::blocked_range<int>& r) const
   {      
      key_partial_vector_ptr local_key_partials_out = std::make_shared<key_partial_vector>();

      unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
      unsigned char current_output[0x10] = {0};

      for(int i0 = r.begin(); i0 < r.end(); i0++)
      {
         std::cout << "task:" << std::hex << std::setw(2) << std::setfill('0') << i0 << std::endl;

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

                  m_cryptops->aes_ecb_decrypt(current_key, current_output, 0x10, m_key, 0x80);

                  // only 0xC bytes are known
                  if(memcmp(current_output, m_expected_output, 0xC) == 0)
                  {
                     key_partial kpv(current_key + 0xC);
                     local_key_partials_out->push_back(kpv);
                  }
               }
            }
         }
      }

      //combine result of this thread into resulting vector

      std::lock_guard<std::mutex> guard(*m_mutex_ptr);
      m_key_partials->insert(m_key_partials->end(), local_key_partials_out->begin(), local_key_partials_out->end());
   }

public:
   const key_partial_vector& get_key_partials() const
   {
      return *m_key_partials;
   }
};

class BruteforceWorker_0x8
{
private:
   unsigned char m_expected_output[0x8];
   unsigned char m_key[0x10];
   unsigned char m_key_partial0[0x4];

   mutable key_partial_vector_ptr m_key_partials;
   mutable std::shared_ptr<std::mutex> m_mutex_ptr;

   std::shared_ptr<ICryptoOperations> m_cryptops;

public:
   BruteforceWorker_0x8(const unsigned char* expected_output, const unsigned char* key, const unsigned char* key_partial0)
   {
      memcpy(m_expected_output, expected_output, 0x8);
      memcpy(m_key, key, 0x10);
      memcpy(m_key_partial0, key_partial0, 0x4);

      m_key_partials = std::make_shared<key_partial_vector>();
      m_mutex_ptr = std::make_shared<std::mutex>();

      m_cryptops = CryptoService::get();
   }

public:
   void operator()(const tbb::blocked_range<int>& r) const
   {
      key_partial_vector_ptr local_key_partials_out = std::make_shared<key_partial_vector>();

      unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
      unsigned char current_output[0x10] = {0};

      memcpy(current_key + 0xC, m_key_partial0, 0x4);

      for(int i0 = r.begin(); i0 < r.end(); i0++)
      {
         std::cout << "task:" << std::hex << std::setw(2) << std::setfill('0') << i0 << std::endl;

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

                  m_cryptops->aes_ecb_decrypt(current_key, current_output, 0x10, m_key, 0x80);

                  // only 0x8 bytes are known
                  if(memcmp(current_output, m_expected_output, 0x8) == 0)
                  {
                     key_partial kpv(current_key + 0x8);
                     local_key_partials_out->push_back(kpv);
                  }
               }
            }
         }
      }

      //combine result of this thread into resulting vector

      std::lock_guard<std::mutex> guard(*m_mutex_ptr);
      m_key_partials->insert(m_key_partials->end(), local_key_partials_out->begin(), local_key_partials_out->end());
   }

public:
   const key_partial_vector& get_key_partials() const
   {
      return *m_key_partials;
   }
};

class BruteforceWorker_0x4
{
private:
   unsigned char m_expected_output[0x4];
   unsigned char m_key[0x10];
   unsigned char m_key_partial0[0x4];
   unsigned char m_key_partial1[0x4];

   mutable key_partial_vector_ptr m_key_partials;
   mutable std::shared_ptr<std::mutex> m_mutex_ptr;

   std::shared_ptr<ICryptoOperations> m_cryptops;

public:
   BruteforceWorker_0x4(const unsigned char* expected_output, const unsigned char* key, const unsigned char* key_partial0, const unsigned char* key_partial1)
   {
      memcpy(m_expected_output, expected_output, 0x4);
      memcpy(m_key, key, 0x10);
      memcpy(m_key_partial0, key_partial0, 0x4);
      memcpy(m_key_partial1, key_partial1, 0x4);

      m_key_partials = std::make_shared<key_partial_vector>();
      m_mutex_ptr = std::make_shared<std::mutex>();

      m_cryptops = CryptoService::get();
   }

public:
   void operator()(const tbb::blocked_range<int>& r) const
   {
      key_partial_vector_ptr local_key_partials_out = std::make_shared<key_partial_vector>();

      unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
      unsigned char current_output[0x10] = {0};

      memcpy(current_key + 0xC, m_key_partial0, 0x4);
      memcpy(current_key + 0x8, m_key_partial1, 0x4);

      for(int i0 = r.begin(); i0 < r.end(); i0++)
      {
         std::cout << "task:" << std::hex << std::setw(2) << std::setfill('0') << i0 << std::endl;

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

                  m_cryptops->aes_ecb_decrypt(current_key, current_output, 0x10, m_key, 0x80);

                  // only 0x4 bytes are known
                  if(memcmp(current_output, m_expected_output, 0x4) == 0)
                  {
                     key_partial kpv(current_key + 0x4);
                     local_key_partials_out->push_back(kpv);
                  }
               }
            }
         }
      }

      //combine result of this thread into resulting vector

      std::lock_guard<std::mutex> guard(*m_mutex_ptr);
      m_key_partials->insert(m_key_partials->end(), local_key_partials_out->begin(), local_key_partials_out->end());
   }

public:
   const key_partial_vector& get_key_partials() const
   {
      return *m_key_partials;
   }
};

class BruteforceWorker_0x0
{
private:
   unsigned char m_expected_output[0x10];
   unsigned char m_input[0x10];
   unsigned char m_key_partial0[0x4];
   unsigned char m_key_partial1[0x4];
   unsigned char m_key_partial2[0x4];

   mutable key_partial_vector_ptr m_key_partials;
   mutable std::shared_ptr<std::mutex> m_mutex_ptr;

   std::shared_ptr<ICryptoOperations> m_cryptops;

public:
   BruteforceWorker_0x0(const unsigned char* expected_output, const unsigned char* input, const unsigned char* key_partial0, const unsigned char* key_partial1, const unsigned char* key_partial2)
   {
      memcpy(m_expected_output, expected_output, 0x10);
      memcpy(m_input, input, 0x10);
      memcpy(m_key_partial0, key_partial0, 0x4);
      memcpy(m_key_partial1, key_partial1, 0x4);
      memcpy(m_key_partial2, key_partial2, 0x4);

      m_key_partials = std::make_shared<key_partial_vector>();
      m_mutex_ptr = std::make_shared<std::mutex>();

      m_cryptops = CryptoService::get();
   }

public:
   void operator()(const tbb::blocked_range<int>& r) const
   {
      key_partial_vector_ptr local_key_partials_out = std::make_shared<key_partial_vector>();

      unsigned char current_key[0x10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
      unsigned char current_output[0x10] = {0};

      memcpy(current_key + 0xC, m_key_partial0, 0x4);
      memcpy(current_key + 0x8, m_key_partial1, 0x4);
      memcpy(current_key + 0x4, m_key_partial2, 0x4);

      for(int i0 = r.begin(); i0 < r.end(); i0++)
      {
         std::cout << "task:" << std::hex << std::setw(2) << std::setfill('0') << i0 << std::endl;

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

                  m_cryptops->aes_ecb_decrypt(m_input, current_output, 0x10, current_key, 0x80);

                  // 0x10 bytes are known
                  if(memcmp(current_output, m_expected_output, 0x10) == 0)
                  {
                     key_partial kpv(current_key + 0x0);
                     local_key_partials_out->push_back(kpv);
                  }
               }
            }
         }
      }

      //combine result of this thread into resulting vector

      std::lock_guard<std::mutex> guard(*m_mutex_ptr);
      m_key_partials->insert(m_key_partials->end(), local_key_partials_out->begin(), local_key_partials_out->end());
   }

public:
   const key_partial_vector& get_key_partials() const
   {
      return *m_key_partials;
   }
};

// protection against collisions

int test_full_key_parallel(const unsigned char* input, const unsigned char* full_key, const unsigned char* expected_output)
{
   auto cryptops = CryptoService::get();

   unsigned char current_output[0x10] = {0};
   cryptops->aes_ecb_decrypt(input, current_output, 0x10, full_key, 0x80);

   if(memcmp(current_output, expected_output, 0x10) == 0)
      return 0;

   return -1;
}

int raccoon_bruteforce_key_partials_parallel(const unsigned char* dec_partial0, const unsigned char* dec_partial1, const unsigned char* dec_partial2, const unsigned char* dec_partial3, unsigned char* full_key_out)
{
   // choose keys

   unsigned char key_0x519[0x20] = {0};
   unsigned char input3[0x10] = {0};  // chosen plain text

   //-------------bruteforce 0xC - 0xF ----------------------

   BruteforceWorker_0xC worker_0xC(dec_partial0, key_0x519);
   tbb::parallel_for(tbb::blocked_range<int>(0, 0xFF), worker_0xC);

   auto& key_partials0 = worker_0xC.get_key_partials();
   for(auto& key_partial0: key_partials0)
   {
      std::cout << "found first key partial:" << std::endl;
      print_byte_array(key_partial0.value, 0x4);

      BruteforceWorker_0x8 worker_0x8(dec_partial1, key_0x519, key_partial0.value);
      tbb::parallel_for(tbb::blocked_range<int>(0, 0xFF), worker_0x8);

      auto& key_partials1 = worker_0x8.get_key_partials();
      for(auto& key_partial1: key_partials1)
      {
         std::cout << "found second key partial:" << std::endl;
         print_byte_array(key_partial1.value, 0x4);

         BruteforceWorker_0x4 worker_0x4(dec_partial2, key_0x519, key_partial0.value, key_partial1.value);
         tbb::parallel_for(tbb::blocked_range<int>(0, 0xFF), worker_0x4);

         auto& key_partials2 = worker_0x4.get_key_partials();
         for(auto& key_partial2: key_partials2)
         {
            std::cout << "found third key partial:" << std::endl;
            print_byte_array(key_partial2.value, 0x4);

            BruteforceWorker_0x0 worker_0x0(dec_partial3, input3, key_partial0.value, key_partial1.value, key_partial2.value);
            tbb::parallel_for(tbb::blocked_range<int>(0, 0xFF), worker_0x0);

            auto& key_partials3 = worker_0x0.get_key_partials();
            for(auto& key_partial3: key_partials3)
            {
               std::cout << "found fourth key partial:" << std::endl;
               print_byte_array(key_partial3.value, 0x4);

               unsigned char full_key[0x10] = {0};
               memcpy(full_key + 0x0, key_partial3.value, 0x4);
               memcpy(full_key + 0x4, key_partial2.value, 0x4);
               memcpy(full_key + 0x8, key_partial1.value, 0x4);
               memcpy(full_key + 0xC, key_partial0.value, 0x4);

               if(test_full_key_parallel(input3, full_key, dec_partial3) == 0)
               {
                  memcpy(full_key_out, full_key, 0x10);

                  return 0;
               }
            }
         }
      }
   }

   std::cout << "done" << std::endl;

   return -1;
}