#include <stdint.h>
#include <string.h>

#include "SceSblSsMgr.h"

typedef struct SceMsif_subctx
{
   char resp_buffer[0x200]; //some buffer of unknown size

}SceMsif_subctx;

#define MS_TPC_48 0x48
#define MS_TPC_49 0x49
#define MS_TPC_4A 0x4A
#define MS_TPC_4B 0x4B

int SceKernelUtilsForDriver_ksceSha224Digest_9ea9d4dc(char* source, int size, char* result)
{
   return 0;
}

typedef struct dec_aes_key_msif_packet //size is 0x24
{
  uint32_t size;
  uint8_t data_1[0x10];
  uint8_t data_2[0x10];
} dec_aes_key_msif_packet;

int SceSblSsMgrForDriver_dec_aes_key_msif_934db6b5(int num, char* arg1, dec_aes_key_msif_packet* in, dec_aes_key_msif_packet* out)
{
   return 0;
}

typedef struct aes_ctx
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   char data[950]; //not sure about size
}aes_ctx;

int SceKernelUtilsForDriver_aes_init_f12b6451(aes_ctx* ctx, int blocksize, int keysize, const uint8_t* key)
{
   return 0;
}

int SceKernelUtilsForDriver_aes_decrypt_d8678061(aes_ctx* ctx, const char* src, char* dst)
{
   return 0;
}

int SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf(char *src, char *dst, int size, int slot_id, int key_size, int mask_enable)
{
   return 0;
}

int food_execute_f00d_command_1_rmauth_sm_C8D908(int* f00d_data)
{
   return 0;
}

int ms_execute_ex_set_cmd_write_short_data_C8A3A8(SceMsif_subctx *subctx, int cmd, int size, const char* source, int delay)
{
   return 0;
}

int ms_execute_ex_set_cmd_read_short_data_C8A448(SceMsif_subctx *subctx, int cmd, int size, char* dest, int delay)
{
   return 0;
}

int execute_f00d_command_2_rmauth_sm_C8D988(const char input[0x10])
{
   return 0;
}

int w_dmac5_command_0x41_C8D2F0(char* result, const char* data, int size)
{
   ((int*)D16)[0] = 0;
   ((int*)D16)[1] = 0;
   r3 = 0x9EA004;
   r4 = r4[r3];

   r8 = r1;
   r10 = buffer;
   var_54 = 0;
   r5 = 0xC0
   r0 = D16[0]
   r1 = D16[1];
   r9 = r2;
   var_58 = r3;
   r3 = 1;
   r10 = r10 - 0x28;
   r10[0] = r0;
   r10[1] = r1;
   r2 = 8;
   arg_4 = r3;
   r1 = some_buffer;
   r0 = r10;
   key_size = r5;
   r3 = 0x1C;
   var_2C = r4;
   r0 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf(r0, r1, r2, r3, arg_0, arg_4);
   
   if(r0 < 0)
   {
      r1 = var_58;
      r2 = var_2C;
      r3 = r1[0];
      if(r2 != r3)
         return STACK_FAIL;
      else
         return r0;
   }

   //--------------------------------------

   r4 = (int)some_buffer[0];
   r3 = (int)some_buffer[1];
   
   r7 = 0;
   r5 = 0;
   
   [var_50 + 4] = (int)r3;
   
   r3 = 0;
   
   ((char*)D16)[0] = (char)r4;
   ((char*)D16)[1] = (char)r4;
   ((char*)D16)[2] = (char)r4;
   ((char*)D16)[3] = (char)r4;
   ((char*)D16)[4] = (char)r4;
   ((char*)D16)[5] = (char)r4;
   ((char*)D16)[6] = (char)r4;
   ((char*)D16)[7] = (char)r4;

   r6 = r4 >> 8;
   r2 = r4 >> 0x10;

   var_50 = (int)r4;

   D16 = D16 >> 0x38;
   
   r6 = (char)r6;

   D17 = D16 << 8;

   r2 = (char)r2;
   
   r0 = ((int*)D17)[0];
   r1 = ((int*)D17)[1];
   
   r4 = r4 >> 0x18;
   r1 = r1 | r7;
   
   lr = (char)[var_50];
   
   r1 = r1 << 8;
   r0 = r0 | r6;
   r4 = (char)r4;
   r6 = (char)[var_50 + 4]
   r1 = r1 | (r0 >> 24);
   r0 = r0 << 8;
   r3 = r3 | r1;
   r2 = r2 | r0;
   r3 = r3 << 8;
   r7 = 0;
   r0 = (char)[var_50 + 5];
   r1 = 0;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r3 = r3 | r5;
   r2 = r2 | r4;
   r3 = r3 << 8;
   r4 = (char)[var_50 + 6]
   r5 = 0;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r3 = r3 | r7;
   r2 = r2 | r6;
   r3 = r3 << 8;
   r6 = (char)[var_50 + 7];
   r7 = 0;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r3 = r3 | r1;
   r2 = r2 | r0;
   r3 = r3 << 8;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r3 = r3 | r5;
   r2 = r2 | r4;
   r3 = r3 << 8;
   r5 = 0;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r6 = r6 | r2;
   r7 = r7 | r3;
   r6 = r6 + r6;
   r7 = r7 + r7; //carry add

   r1 = (char)r6;
   r3 = r7 >> 0x18;
   r0 = r7 >> 8;
   var_41 = (char)r1;
   r2 = r6 >> 0x18;
   var_48 = (char)r3;
   var_46 = (char)r0;

   if(lr < 0)
   {
      r1 = r1 ^ 0x1B;
   }

   r0 = (char)var_48;
   r4 = r7 >> 16;
   
   if(lr < 0)
   {
      var_41 = (char)r1;
   }

   r1 = 0;
   r2 = r2 | (r7 << 8);
   r1 = r1 << 8;
   var_47 = (char)r4;
   r4 = r6 >> 0x10;
   var_44 = (char)r2;
   r3 = 0;
   r1 = r1 | (r0 >> 24);
   r2 = (char)var_47;
   r0 = r0 << 8;
   r4 = r4 | (r7 << 16);
   r6 = r6 >> 8;
   var_45 = (char)r7;
   r3 = r3 | r1;
   var_43 = (char)r4;
   r3 = r3 << 8;
   r2 = r2 | r0;
   r4 = (char)var_46;
   r6 = r6 | (r7 << 24);
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   var_42 = r6;
   r3 = r3 | r5;
   r6 = (char)var_45;
   r3 = r3 << 8;
   r2 = r2 | r4;
   r7 = 0;
   r0 = (char)var_44;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r4 = (char)var_43;
   r3 = r3 | r7;
   r2 = r2 | r6;
   r3 = r3 << 8;
   r1 = 0;
   r5 = 0;
   r6 = (char)var_42;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   lr = (char)var_48;
   r3 = r3 | r1;
   r2 = r2 | r0;
   r3 = r3 << 8; 
   r7 = 0;
   r0 = (char)var_41;
   r1 = 0;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r3 = r3 | r5;
   r2 = r2 | r4;
   r3 = r3 << 8;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r3 = r3 | r7;
   r2 = r2 | r6;
   r3 = r3 << 8;
   r7 = 0;
   r3 = r3 | (r2 >> 24);
   r2 = r2 << 8;
   r0 = r0 | r2;
   r1 = r1 | r3;
   r0 = r0 + r0;
   r1 = r1 + r1; //carry add

   r2 = r2 >> 0x18;
   r6 = r1 >> 0x10;
   r4 = (char)r0;
   r3 = r1 >> 0x18;
   r5 = r1 >> 8;
   var_3F = (char)r6;
   r6 = r0 >> 0x10;
   r2 = r2 | (r1 << 8);
   r6 = r6 | (r1 << 16);
   r0 = r0 >> 8;
   var_39 = (char)r4;

   if(lr < 0)
   {
      r4 = r4 ^ 0x1B;
   }

   var_3D = (char)r1;
   var_40 = (char)r3;
   r0 = r0 | (r1 << 24);
   var_3E = (char)r5;
   var_3C = (char)r2;
   var_3B = (char)r6;
   r6 = 0;
   
   if(lr < 0)
   {
      var_39 = (char)r4;
   }
   
   var_3A = (char)r0;

   if(R9 <= 8)
   {
      r1 = var_58;
      r2 = var_2C;
      r3 = r1[0];
      if(r2 != r3)
         return STACK_FAIL;
      else
         return r0;
   }

   //--------------------------------------

   r11 = 0xC0;

   while(true)
   {
      r8 = r8 + 8;

      key_size = r11;
      
      r4 = ((int*)[r8-8])[0];
      r5 = ((int*)[r8-8])[1];
      
      r1 = 1;
      arg_4 = r1;
      
      r0 = r10;
      r1 = some_buffer;
      r2 = 8;

      r4 = r4 ^ r6;
      r5 = r5 ^ r7;
      r3 = 0x1C;
      
      //PLD.W           [R8,#0x30] ; preload
      
      ((int*)var_50)[0] = r4;
      ((int*)var_50)[1] = r5;
      
      SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf(r0, r1, r2, r3, arg_0, arg_4);

      if(R0 < 0)
      {
         break;
      }
      else
      {
         r9 = r9 - 8;

         r6 = ((int*)some_buffer)[0]
         r7 = ((int*)some_buffer)[1]

         if(R9 <= 8)
         {
            break;
         }
      }
   }

   if(r9 == 8)
   {
      r2 = ((int*)var_48)[0]
      r3 = ((int*)var_48)[1]
      
      r0 = ((int*)r8)[0]
      r1 = ((int*)r8)[1]
      
      r6 = r6 ^ r2;
      r7 = r7 ^ r3;
   }
   else
   {
      r2 = ((int*)r8)[0];
      r3 = ((int*)r8)[1];
      
      r0 = r9 + 1;
      r1 = 0;
      
      ((int*)var_50)[0] = r2;
      ((int*)var_50)[1] = r3;
      
      r3 = buffer;
      r3 = r3 + r9;
      
      ((char)r3[-0x28]) = (char)r1;
      
      if(R0 != 0)
      {
         r0 = r0 + r10;
         r2 = 7 - r9;
         memset(r0, r1, r2);
      }
      
      r2 = ((int*)var_40)[0];
      r3 = ((int*)var_40)[1];

      r0 = ((int*)var_50)[0];
      r1 = ((int*)var_50)[1];
      
      r6 = r6 ^ r2;
      r7 = r7 ^ r3;
   }

   r2 = 0xC0;
   r3 = 1;
   
   arg_0 = r2;
   arg_4 = r3;
   
   r6 = r6 ^ r0;
   r7 = r7 ^ r1;
   
   r0 = r10;
   r1 = some_buffer;
   r2 = 8;
   r3 = 0x1C;

   ((int*)var_50)[0] = r6;
   ((int*)var_50)[1] = r7;
   
   int r0 = SceSblSsMgrForDriver_sceSblSsMgrDES64ECBEncryptForDriver_37dd5cbf(r0, r1, r2, r3, arg_0, arg_4);

   if(r0 < 0)
   {
      r1 = var_58;
      r2 = var_2C;
      r3 = r1[0];
      if(r2 != r3)
         return STACK_FAIL;
      else
         return r0;
   }

   r2 = ((int*)some_buffer)[0];
   r3 = ((int*)some_buffer)[1];

   r0 = 0;

   r1 = var_54;
   
   ((int*)r1)[0] = r2;
   ((int*)r1)[1] = r3;

   r1 = var_58;
   r2 = var_2C;
   r3 = r1[0];
   if(r2 != r3)
      return STACK_FAIL;
   else
      return r0;
}

int ms_execute_ex_set_cmd_C8A4E8(SceMsif_subctx *subctx, int cmd, SceMsif_subctx *subctx2, int delay)
{
   return 0;
}

int memxor(char* dest, const char* src1, const char* src2, int size)
{
   for(int i = 0; i < size; i++)
      dest[i] = src1[i] ^ src2[i];
   return 0;
}

//----------------

// flag that shows that static sha224 table is decrypted 
int g_00B9F9B8 = 0;

char g_zero_array_C90498[0x10] = 
{
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

//encrypted key data 1

char g_dec_input_C90370[0x20] =
{
   0xB0, 0x6C, 0xA2, 0x7E, 0xAF, 0xBE, 0x0C, 0x17, 
   0x3D, 0x8F, 0xA7, 0x8F, 0xD4, 0xE1, 0xE6, 0xB6, 
   0xF0, 0xC8, 0x91, 0x93, 0x6B, 0xB1, 0x95, 0x6E, 
   0x54, 0x7C, 0xFC, 0xC8, 0x32, 0x5C, 0xC1, 0xE2
};

//encrypted key data 2

char g_dec_input_C90394[0x20] =
{
   0x34, 0xCB, 0x9E, 0xF9, 0x3F, 0xDA, 0x96, 0x15, 
   0x7A, 0xB2, 0x0C, 0x2A, 0xB4, 0x87, 0x36, 0x24,
   0x21, 0xB4, 0x07, 0xF2, 0x4F, 0x61, 0x35, 0x85,
   0x5F, 0x8E, 0xF7, 0x72, 0xB3, 0x9A, 0x08, 0x53
};

//encrypted table of sha224 hashes

char g_enc_sha224_C903B8[0x1C * 8] = 
{
   0xF0, 0x8C, 0xF8, 0x29, 0xD7, 0x6E, 0x1B, 0x03, 0xFA, 0xC5, 0x62, 0xF3, 0x38, 0xDF, 0xB2, 0x2A, 0x1C, 0xDC, 0x38, 0x8B, 0x2C, 0x1B, 0xDA, 0x5D, 0x6F, 0x13, 0x8C, 0x0F,
   0x1E, 0x5F, 0xD8, 0xB3, 0x26, 0x9D, 0x0E, 0xA4, 0xE6, 0x94, 0x97, 0xA5, 0x1E, 0x9A, 0x5D, 0x83, 0x56, 0x2D, 0xB9, 0x30, 0xCD, 0xE8, 0x9A, 0xE6, 0xBF, 0x52, 0x0F, 0x91,
   0x60, 0x04, 0xA5, 0x74, 0x44, 0x17, 0x61, 0x03, 0xBD, 0x46, 0x30, 0x13, 0xFB, 0x86, 0x96, 0x2E, 0xC4, 0x3B, 0x09, 0x36, 0x72, 0x55, 0x44, 0x30, 0x6B, 0x57, 0x54, 0x09, 
   0x41, 0xF6, 0xC2, 0xFF, 0x98, 0xF1, 0x16, 0xC8, 0x04, 0x15, 0x84, 0x3B, 0x83, 0xBC, 0xCE, 0xB0, 0xB2, 0x37, 0x2A, 0xE3, 0x65, 0xD5, 0xB1, 0xD8, 0x3C, 0xF7, 0x43, 0xD6, 
   0x13, 0x9F, 0x11, 0xE7, 0x80, 0x75, 0x5A, 0xEC, 0x95, 0x66, 0x1C, 0xE7, 0xC4, 0x35, 0xD6, 0x57, 0x7F, 0xD6, 0xCB, 0x78, 0x52, 0x0A, 0x03, 0x70, 0xEA, 0x11, 0x7B, 0xA2, 
   0xD2, 0x4E, 0x59, 0x87, 0x9B, 0xA0, 0xBB, 0xF1, 0x49, 0x86, 0x2C, 0x2D, 0xF9, 0x20, 0x77, 0x4C, 0xA9, 0x93, 0xAC, 0xD5, 0x5B, 0xB2, 0x9D, 0x93, 0x7E, 0xDB, 0xF7, 0xBF, 
   0xB3, 0x90, 0xE9, 0x6A, 0x44, 0xA9, 0xD8, 0xDC, 0x04, 0x46, 0x19, 0x40, 0xD6, 0x60, 0x9D, 0x8D, 0x2B, 0xE7, 0xD8, 0x4E, 0x4E, 0xCF, 0x44, 0x32, 0x2B, 0x80, 0x0B, 0x00, 
   0x5B, 0xC2, 0xA6, 0x67, 0xE7, 0x48, 0xBF, 0xAA, 0x05, 0x58, 0xE4, 0xDF, 0x7E, 0x91, 0xDF, 0x24, 0xBC, 0x2D, 0xE8, 0x99, 0xF4, 0x5F, 0x5C, 0x94, 0x58, 0x06, 0xFE, 0x30,
};

//decrypted table of sha224 hashes
char g_00B9F8D8[0x1C * 8] = {0};

int decrypt_sha224_table_internal_C8D09C()
{
   //try to decrypt aes key 1

   dec_aes_key_msif_packet dec_input_C90370;
   dec_input_C90370.size = 0x20;
   memcpy(dec_input_C90370.data_1, g_dec_input_C90370, 0x10);
   memcpy(dec_input_C90370.data_2, g_dec_input_C90370 + 0x10, 0x10);

   dec_aes_key_msif_packet dec_data_464;
   dec_data_464.size = 0x20;
   memset(dec_data_464.data_1, 0, 0x10);
   memset(dec_data_464.data_2, 0, 0x10);

   int kget_res1 = SceSblSsMgrForDriver_dec_aes_key_msif_934db6b5(4, g_zero_array_C90498, &dec_input_C90370, &dec_data_464);   

   if(kget_res1 != 0)
   {
      memset(&dec_data_464, 0, 0x24);
      return -1; //returns not exactly this, but we dont care here
   }

   int cmp_res = memcmp(dec_data_464.data_1, g_zero_array_C90498, 0x10);

   //try to decrypt aes key 2

   if(cmp_res != 0)
   {
      dec_aes_key_msif_packet dec_input_C90394;
      memcpy(dec_input_C90394.data_1, g_dec_input_C90394, 0x10);
      memcpy(dec_input_C90394.data_2, g_dec_input_C90394 + 0x10, 0x10);      

      int kget_res2 = SceSblSsMgrForDriver_dec_aes_key_msif_934db6b5(4, g_zero_array_C90498, &dec_input_C90394, &dec_data_464);

      if(kget_res2 != 0)
      {
         memset(&dec_data_464, 0, 0x24);
         return -1; //returns not exactly this, but we dont care here
      }
   }

   aes_ctx ctx;
   char xor_data1[0x10]; //offset 0x3D0
   char xor_data2[0x10]; //offset 0x3E0 // how is this initialized ?

   int ai_res = SceKernelUtilsForDriver_aes_init_f12b6451(&ctx, 0x80, 0x80, dec_data_464.data_2);

   if(ai_res <= 0)
   {
      //clear sensitive data
      memset(&dec_data_464, 0, 0x24);
      memset(&ctx, 0, 0x3C0);
      memset(xor_data1, 0, 0x10);
      memset(xor_data2, 0, 0x10);
      return -1; //returns not exactly this, but we dont care here
   }

   int some_size = ctx.unk_8 << 2;
   if(some_size != 0)
   {
      memcpy(xor_data1, g_zero_array_C90498, some_size);
   }

   char dec_dst[0x10]; //array for holding single aes dec desult

   char* next_enc_data = g_enc_sha224_C903B8 + 0x10;
   char* next_dec_data = g_00B9F8D8 + 0x10; //0xB9F8E8

   char var_40[0x10]; // how is this initialized ?

   const char* table_end = g_enc_sha224_C903B8 + sizeof(g_enc_sha224_C903B8) + 0x10; //pointer to end

   do
   {
      char* curr_enc_data = next_enc_data - 0x10; //current enc data
      char* curr_dec_data = next_dec_data - 0x10; //current result data

      SceKernelUtilsForDriver_aes_decrypt_d8678061(&ctx, curr_enc_data, dec_dst);

      //just check that there is still smth to copy
      int some_size2 = ctx.unk_8 << 2;
      if(some_size2 != 0)
      {
         // devide by 0x10 to get number of blocks left
         int some_size3 = some_size2 >> 4;

         int is_not_tail = (some_size3 != 0) && (some_size2 > 0xF);
         if(is_not_tail > 0)
         {
            //xor current block of decrypted data and store to decrypted table
            //then update xor value with current encrypted block
            memxor(curr_dec_data, dec_dst, xor_data1, 0x10);
            memcpy(xor_data1, curr_enc_data, 0x10);

            //check if there is more than one blocks left
            //this will ignore last block
            if(some_size3 > 1)
            {
               //xor some data and store as next block to decrypted table
               //then update xor value with next encrypted block
               memxor(next_dec_data, var_40, xor_data2, 0x10);
               memcpy(xor_data2, next_enc_data, 0x10);
            }

            //get back original size, however it will be aligned to 0x10
            //if it will not equal to original size - it means that there was tail data
            int some_size4 = some_size3 << 4;
            if(some_size4 != some_size2)
            {
               //copy tail - in this case we have to add some_size4 as main offset
               memxor(curr_dec_data + some_size4, dec_dst + some_size4, xor_data1 + some_size4, some_size2);
               memcpy(xor_data1 + some_size4, curr_enc_data + some_size4, some_size2);
            }
         }
         else
         {
            //copy tail - some_size2 will hold number of bytes left
            memxor(curr_dec_data, dec_dst, xor_data1, some_size2);
            memcpy(xor_data1, curr_enc_data, some_size2);
         }
      }

      next_enc_data = next_enc_data + 0x10;
      next_dec_data = next_dec_data + 0x10;
   }
   while(next_enc_data != table_end);

   //clear sensitive data
   memset(&dec_data_464, 0, 0x24);
   memset(&ctx, 0, 0x3C0);
   memset(xor_data1, 0, 0x10);
   memset(xor_data2, 0, 0x10);

   return 0;
}

int decrypt_sha224_table_C8D09C(char* ptr_pair[2], char* ptr_table[6])
{
   //check that tables is not already decrypted

   if(g_00B9F9B8 == 0)
   {
      int dec_res = decrypt_sha224_table_internal_C8D09C();
      if(dec_res < 0)
         return dec_res;
   }

   //set decryption success flag
   g_00B9F9B8 = 1;

   //construct pointer table
   ptr_pair[0] = g_00B9F8D8;
   ptr_pair[1] = g_00B9F8D8 + 0x1C;

   ptr_table[0] = g_00B9F8D8 + 0x38;
   ptr_table[1] = g_00B9F8D8 + 0x54;
   ptr_table[2] = g_00B9F8D8 + 0x70;
   ptr_table[3] = g_00B9F8D8 + 0x8C;
   ptr_table[4] = g_00B9F8D8 + 0xA8;
   ptr_table[5] = g_00B9F8D8 + 0xC4;

   return 0;
}

//----------------

typedef struct verify_hash_ctx
{
   char* ptr_4;
   char* ptr_20;
}verify_hash_ctx;

int verify_hashes_C8DBC0(verify_hash_ctx* ctx, char sha_224[0x1C], char* dec_ptr_pair[2], char* dec_ptr_table[6])
{
   return 0;
}

#pragma pack(push,1)

typedef struct dmac5_41_req1 //size is 0x28
{
   char f00d_cmd2_buffer[0x10];
   char var_88[0x10];
   char rand_value[8];
}dmac5_41_req1;

typedef struct dmac5_41_req2 //size is 0x10
{
   char data1[0x8];
   char data2[0x8];
}dmac5_41_req2;

typedef struct tpc_cmd49_resp //size is 0x40
{
   char f00d_cmd2_buffer[0x10];
   char var_88[0x10];
   char signature[0x08];
   char reserved[0x18];
}tpc_cmd49_resp;

#pragma pack(pop)

int get_sha224_digest_source_validate_card_init_f00D_C8D5FC(SceMsif_subctx* subctx, char sha224_digest_source[0x10])
{
   // execute f00d command 1

   int f00d_cmd1_res = 0;

   int fdres1 = food_execute_f00d_command_1_rmauth_sm_C8D908(&f00d_cmd1_res);
   if(fdres1 < 0)
      return fdres1;

   // generate random number
   char rand_value[8];
   memset(rand_value, 0, 8);

   int rdgenres1 = SceSblSsMgrForDriver_4dd1b2e5(rand_value, 8, 1);
   if(rdgenres1 < 0)
      return rdgenres1;   

   // prepare cmd 0x48 request

   // 8 + 1 + 0x17 = 0x20 total in bytes
   char cmd48_src[0x20];
   memcpy(cmd48_src, rand_value, 8); //copy rand
   cmd48_src[8] = f00d_cmd1_res; //copy cmd1 resp 1 byte
   memset(cmd48_src + 9, 0, 0x17); //fill rest with 0

   // execute tpc command 48
   int res48 = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_48, 0x20, cmd48_src, 1000);
   if(res48 != 0)
      return res48; //returns not exactly this, but we dont care here

   // execute tpc command 49

   tpc_cmd49_resp cmd49_resp;
   memset(&cmd49_resp, 0, 0x40);
   
   int res49 = ms_execute_ex_set_cmd_read_short_data_C8A448(subctx, MS_TPC_49, 0x40, (char*)&cmd49_resp, 1000); //gets 0x40 bytes of response

   // execute f00d command 2

   int fdres2 = execute_f00d_command_2_rmauth_sm_C8D988(cmd49_resp.f00d_cmd2_buffer); //sends first 0x10 bytes of 0x49 resp to f00d, probably gets response
   if(fdres2 < 0)
      return fdres2;

   // prepare dmac5 command 41 request data

   char dmac5_result_1[0x8];
   memset(dmac5_result_1, 0, 0x8);

   dmac5_41_req1 d5req1;
   memcpy(d5req1.f00d_cmd2_buffer, cmd49_resp.f00d_cmd2_buffer, 0x10);
   memcpy(d5req1.var_88, cmd49_resp.var_88, 0x10); //copy second 0x10 bytes of 0x49 resp  
   memcpy(d5req1.rand_value, rand_value, 0x8);

   // execute dmac5 command 41

   int dmc5res1 = w_dmac5_command_0x41_C8D2F0(dmac5_result_1, (char*)&d5req1, 0x28); //send dmac5 request with 0x20 bytes of 0x49 response and 8 bytes of random data
   if(dmc5res1 != 0)
      return dmc5res1;

   // verify hash, signature ?

   if(memcmp(dmac5_result_1, cmd49_resp.signature, 8) != 0) //verify against last 8 bytes of 0x49 resp
      return -1; //returns not exactly this, but we dont care here

   // prepare dmac5 command 41 request data
 
   char dmac_5_result_2[0x8];
   memset(dmac_5_result_2, 0, 0x8);

   dmac5_41_req2 d5req2;
   memcpy(d5req2.data1, d5req1.rand_value, 8);
   memcpy(d5req2.data2, d5req1.var_88 + 8, 8);

   // execute dmac5 command 41

   int dmc5res2 = w_dmac5_command_0x41_C8D2F0(dmac_5_result_2, (char*)&d5req2, 0x10);
   if(dmc5res2 != 0)
      return dmc5res2;
   
   // execute tpc command 4A

   char cmd4A_src[0x20];
   memcpy(cmd4A_src, dmac_5_result_2, 8); //copy dmac5 result 2 to request
   memset(cmd4A_src + 8, 0, 0x20); //all bytes should be cleared except for first 8 bytes
   
   int res4A = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_4A, 0x20, cmd4A_src, 1000);
   if(res4A < 0)
      return res4A; //returns not exactly this, but we dont care here
   
   // copy result

   if(sha224_digest_source == 0)
      return -1; //returns not exactly this, but we dont care here

   memcpy(sha224_digest_source, d5req1.f00d_cmd2_buffer, 0x10); //copy result
   
   return cmd49_resp.var_88[7];
}

int decrypt_sha224_table_and_verify_C8D78C(SceMsif_subctx* subctx, char sha224_digest_source[0x10])
{
   //get response from card

   int res4B = ms_execute_ex_set_cmd_C8A4E8(subctx, MS_TPC_4B, subctx, 1000);
   if(res4B != 0)
      return res4B;

   //check some field

   int data_inv =  (subctx->resp_buffer[0] << 24) | (subctx->resp_buffer[1] << 16) | (subctx->resp_buffer[2] << 8) | (subctx->resp_buffer[3]);
   if(data_inv != 1)
      return -1; //returns not exactly this, but we dont care here

   //decrypt static list of what is probably sha 224 hash table

   char* dec_ptr_pair[2];
   char* dec_ptr_table[6];

   int dec_res = decrypt_sha224_table_C8D09C(dec_ptr_pair, dec_ptr_table);
   if(dec_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //calculate sha 224 digest from data that we aquired on first step of initialization

   char sha_224_digest[0x1C];
   memset(sha_224_digest, 0, 0x1C);

   int sha_res = SceKernelUtilsForDriver_ksceSha224Digest_9ea9d4dc(sha224_digest_source, 0x10, sha_224_digest);
   if(sha_res != 0)
      return -1; //returns not exactly this, but we dont care here

   //verify the data

   verify_hash_ctx vfh_ctx;
   vfh_ctx.ptr_4 = subctx->resp_buffer + 4; 
   vfh_ctx.ptr_20 = subctx->resp_buffer + 0x20;

   int vf_res = verify_hashes_C8DBC0(&vfh_ctx, sha_224_digest, dec_ptr_pair, dec_ptr_table);
   if(vf_res != 0)
      return -1;

   return 0;
}