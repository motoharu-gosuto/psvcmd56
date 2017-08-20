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
   return 0;
}

int ms_execute_ex_set_cmd_C8A4E8(SceMsif_subctx *subctx, int cmd, SceMsif_subctx *subctx2, int delay)
{
   return 0;
}

//----------------

int exit_loc_C8D10E()
{
   /*
   LDR.W           R12, [SP,#0x478+var_474] ; get cookie ptr
   LDR.W           R2, [SP,#0x478+var_2C] ; get cookie
   LDR.W           R3, [R12]
   CMP             R2, R3
   */

   //just return r0 or stack fail

   return 0;
}

int exit_loc_C8D0D4()
{
   /*
   LDR.W           R12, [SP,#0x478+ptr_pair_46C] ; void **ptr_pair
   MOV             R3, 0xB9F8D8 ; 0xB9F8D8 (18D8)
   MOVS            R0, #0
   ADD.W           LR, R3, #0x1C ; element 1
   ADD.W           R7, R3, #0x38 ; element 2
   ADD.W           R6, R3, #0x54 ; element 3
   ADD.W           R5, R3, #0x70 ; element 4
   ADD.W           R4, R3, #0x8C ; element 5
   ADD.W           R1, R3, #0xA8 ; element 6
   ADD.W           R2, R3, #0xC4 ; element 7
   STMIA.W         R12, {R3,LR} ; store ptr pair
   STRD.W          R7, R6, [R9] ; store void **ptr_table
   STRD.W          R5, R4, [R9,#8]
   STRD.W          R1, R2, [R9,#0x10]
   */

   return exit_loc_C8D10E();
}

int exit_loc_C8D2AA()
{
   /*
   MOVS            R3, #0
   MOV             R0, 0xFFFFFF34 ; 00C8D2AC : possible external reference: FFFFFF34
   STRD.W          R3, R3, [SP,#0x478+dec_data_464] ; derived key data
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+8]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0x10]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0x18]
   STR             R3, [SP,#0x478+dec_data_464+0x20]
   */

   return exit_loc_C8D10E();
}

int exit_loc_C8D2C4()
{
   /*
   MOVS            R3, #0
   MOV             R0, R6  ; ptr
   MOV             R1, R3  ; value
   MOV.W           R2, #0x3F0 ; num
   STRD.W          R3, R3, [SP,#0x478+dec_data_464] ; derived key data
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+8]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0x10]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0x18]
   STR             R3, [SP,#0x478+dec_data_464+0x20]
   BLX             SceMsif.SceSysclibForDriver._imp_memset_0ab9bf5c ; clear all sensitive data
   MOV             R0, 0xFFFFFF34 ; 00C8D2E4 : possible external reference: FFFFFF34
   */

   return exit_loc_C8D10E();
}

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

int decrypt_sha224_table_C8D09C(char* ptr_pair[2], char* ptr_table[6])
{
   //check that tables is not already decrypted

   if(g_00B9F9B8 != 0)
      return exit_loc_C8D0D4();

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
      return exit_loc_C8D2AA();

   int cmp_res = memcmp(dec_data_464.data_1, g_zero_array_C90498, 0x10);

   //try to decrypt aes key 2

   if(cmp_res != 0)
   {
      dec_aes_key_msif_packet dec_input_C90394;
      memcpy(dec_input_C90394.data_1, g_dec_input_C90394, 0x10);
      memcpy(dec_input_C90394.data_2, g_dec_input_C90394 + 0x10, 0x10);      

      int kget_res2 = SceSblSsMgrForDriver_dec_aes_key_msif_934db6b5(4, g_zero_array_C90498, &dec_input_C90394, &dec_data_464);

      if(kget_res2 != 0)
         return exit_loc_C8D2AA();
   }

   aes_ctx ctx;

   int ai_res = SceKernelUtilsForDriver_aes_init_f12b6451(&ctx, 0x80, 0x80, dec_data_464.data_2);

   if(ai_res <= 0)
      return exit_loc_C8D2C4();

   char destination[?];

   int some_size = ctx.unk_8 << 2;
   if(some_size != 0)
   {
      memcpy(destination, g_zero_array_C90498, some_size);
   }

   //char** r9 = ptr_table;
   //char** ptr_pair_46C = ptr_pair;
   //aes_ctx* r6 = &ctx;
   
   char dec_dst[0x10]; //array for holding single aes dec desult

   char* r8 = g_enc_sha224_C903B8 + 0x10;
   char* r10 = dec_dst;
               
   char* r11 = g_00B9F8D8 + 0x10; //0xB9F8E8

   //loc_C8D1AE 
   while(true)
   {
      char* r5 = r8 - 0x10;
      
      SceKernelUtilsForDriver_aes_decrypt_d8678061(&ctx, r5, r10);

      char* lr = r11 - 0x10;

      int some_size2 = ctx.unk_8 << 2;

      if(some_size2 != 0)
      {
         int some_size3 = some_size2 >> 4; // devide by 0x10

         int is_not_tail = (some_size3 != 0) && (some_size2 > 0xF);

         int r3 = some_size3 << 4; //mul by 0x10

         if(is_not_tail > 0)
         {
            /*
            CMP             R2, #1
            VLDR            D20, [R6,#0x3D0]
            VLDR            D21, [R6,#0x3D8]
            ADD.W           R12, SP, #0x478+dec_dst
            VLDR            D18, [R8,#-0x10]
            VLDR            D19, [R8,#-8]
            VLD1.64         {D16-D17}, [R12@64]
            VSTR            D18, [R6,#0x3D0]
            VSTR            D19, [R6,#0x3D8]
            VEOR            Q8, Q8, Q10
            VSTR            D16, [R11,#-0x10]
            VSTR            D17, [R11,#-8]
            */

            if(!bls)
            {
               /*
               VLDR            D20, [R6,#0x3E0]
               VLDR            D21, [R6,#0x3E8]
               ADD.W           R1, SP, #0x478+var_40
               VLD1.64         {D18-D19}, [R8@64]
               VLD1.64         {D16-D17}, [R1@64]
               VSTR            D18, [R6,#0x3E0]
               VSTR            D19, [R6,#0x3E8]
               VEOR            Q8, Q8, Q10
               VST1.64         {D16-D17}, [R11@64]
               */
            }
            
            if(r3 == r7)
            {
               /*
               MOVW            R1, #(ctx_130_part_C904A8 AND 0xFFFF)
               ADD.W           R8, R8, #0x10
               MOVT.W          R1, #high16(ctx_130_part_C904A8) ; 00C904A8 data reference 00000001 - end pointer
               ADD.W           R11, R11, #0x10
               */

               if(r8 == r1)
                  break;
            }
         }
         else
         {
            /*
            MOVS            R3, #0
            */            
         }

         //loc_C8D22C
         while(true)
         {
            /*
            ADDS            R2, R6, R3
            LDRB.W          R0, [R10,R3] ; get decrypted byte
            LDRB.W          R4, [R2,#0x3D0]
            LDRB            R1, [R5,R3]
            EORS            R0, R4
            STRB.W          R0, [LR,R3] ; store decrypted byte
            ADDS            R3, #1
            CMP             R3, R7
            STRB.W          R1, [R2,#0x3D0]
            */

            if(!bcc)
               break;
         }
      }

      char* table_end = g_enc_sha224_C903B8 + sizeof(g_enc_sha224_C903B8) + 0x10; //pointer to end
      r8 = r8 + 0x10;
      r11 = r11 + 0x10;
      
      if(r8 == table_end)
         break;
   }

   //clear sensitive data

   memset(&dec_data_464, 0, 0x24);
   memset(&ctx, 0, 0x3F0); //size is bigger than 0x3C0 (960) !!!!!!!!!!!!!!!!!!!!!!!!

   //set decryption success flag   
   
   g_00B9F9B8 = 1;

   return exit_loc_C8D0D4();
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