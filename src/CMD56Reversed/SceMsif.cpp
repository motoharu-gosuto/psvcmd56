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

int decrypt_sha224_table_C8D09C(char** ptr_pair, char** ptr_table)
{
   /*
   MOVW            R12, #0xA004 ; 00C8D09C : external reference: 009EA004
   PUSH.W          {R4-R11,LR}
   MOVT.W          R12, #0x9E ; 00C8D0A4 : external reference: 009EA004
   SUBW            SP, SP, #0x454
   MOV             R9, R1  ; arg1
   STR.W           R12, [SP,#0x478+var_474] ; cookie ptr
   MOV             R12, 0xB9F9B8 ; 0xB9F9B8
   STRD.W          R12, R0, [SP,#0x478+var_470] ; store 0xB9F9B8, arg0
   LDR.W           R12, [SP,#0x478+var_474] ; cookie ptr
   LDR.W           R3, [R12] ; store cookie
   LDR.W           R12, [SP,#0x478+var_470]
   STR.W           R3, [SP,#0x478+var_2C] ; store cookie
   LDR.W           R4, [R12]
   */

   if(r4 != 0)
      return exit_loc_C8D0D4();

   /*
   MOVS            R0, #0x20
   MOVW            R1, #(zero_array_C90498 AND 0xFFFF) ; 00C90498 data reference 00000000
   MOVW            R2, #(dec_input_C90370 AND 0xFFFF) ; 00C90370 data reference 00000020
   STR             R0, [SP,#0x478+dec_data_464] ; = 0x20
   ADD             R3, SP, #0x478+dec_data_464 ; res
   MOVT.W          R1, #high16(zero_array_C90498) ; 00C90498 data reference 00000000
   MOVT.W          R2, #high16(dec_input_C90370) ; 00C90370 data reference 00000020
   MOVS            R0, #4  ; num
   STRD.W          R4, R4, [SP,#0x478+dec_data_464+4] ; = 0
   STRD.W          R4, R4, [SP,#0x478+dec_data_464+0xC] ; = 0
   STRD.W          R4, R4, [SP,#0x478+dec_data_464+0x14] ; = 0
   STRD.W          R4, R4, [SP,#0x478+dec_data_464+0x1C] ; = 0
   BLX             SceMsif.SceSblSsMgrForDriver._imp_dec_aes_key_msif_934db6b5
   */

   if(r0 != 0)
      return exit_loc_C8D2AA();

   /*
   MOVW            R1, #(zero_array_C90498 AND 0xFFFF) ; 00C90498 data reference 00000000
   ADD             R0, SP, #0x478+dec_data_464+4 ; ptr1
   MOVT.W          R1, #high16(zero_array_C90498) ; 00C90498 data reference 00000000
   MOVS            R2, #0x10 ; num
   BLX             SceMsif.SceSysclibForDriver._imp_memcmp_f939e83d ; compare dec data to zero chunk
   */

   if(r0 != 0)
   {
      /*
      MOVW            R1, #(zero_array_C90498 AND 0xFFFF)
      MOVW            R2, #(dec_input_C90394 AND 0xFFFF) ; 00C90394 data reference 00000020
      MOVT.W          R1, #high16(zero_array_C90498) ; 00C90498 data reference 00000000
      MOVT.W          R2, #high16(dec_input_C90394) ; 00C90394 data reference 00000020
      MOVS            R0, #4  ; num
      ADD             R3, SP, #0x478+dec_data_464 ; res
      BLX             SceMsif.SceSblSsMgrForDriver._imp_dec_aes_key_msif_934db6b5
      */

      if(r0 != 0)
         return exit_loc_C8D2AA();
   }

   /*
   MOVS            R1, #0x80
   ADD             R6, SP, #0x478+ctx
   MOV             R0, R6  ; ctx
   MOV             R2, R1  ; keysize
   ADD             R3, SP, #0x478+dec_data_464+0x14 ; key
   BLX             SceMsif.SceKernelUtilsForDriver._imp_aes_init_f12b6451 ; initialize aes context
   */

   if(r0 <= 0)
      return exit_loc_C8D2C4();

   /*
   LDR             R3, [R6,#8] ; get smth from ctx
   LSLS            R2, R3, #2
   */

   if(!beq)
   {
      /*
      MOVW            R1, #(zero_array_C90498 AND 0xFFFF) ; 00C90498 data reference 00000000
      ADD.W           R0, SP, #0x478+destination ; destination
      MOVT.W          R1, #high16(zero_array_C90498) ; 00C90498 data reference 00000000
      BLX             SceMsif.SceSysclibForDriver._imp_memcpy_40c88316 ; zero mem
      */
   }
   
   /*
   MOVW            R8, #((enc_sha224_C903B8+0x10) AND 0xFFFF)
   MOVW            R11, #0xF8E8
   MOVT.W          R8, #(high16((enc_sha224_C903B8+0x10))) ; 00C903C8 data reference 8B38DC1C
   MOVT.W          R11, #0xB9 ; 0xB9F8E8 (18E8)
   ADD.W           R10, SP, #0x478+dec_dst
   */

   //loc_C8D1AE 
   while(true)
   {
      /*
      SUB.W           R5, R8, #0x10
      MOV             R0, R6  ; ctx
      MOV             R1, R5  ; src
      MOV             R2, R10 ; dst
      BLX             SceMsif.SceKernelUtilsForDriver._imp_aes_decrypt_d8678061
      LDR             R7, [R6,#8] ; get smth from ctx
      SUB.W           LR, R11, #0x10 ; start will be 0xB9F8D8 (18D8)
      LSLS            R7, R7, #2
      */

      if(!beq)
      {
         /*
         LSRS            R2, R7, #4
         CMP             R2, #0
         IT NE
         CMPNE           R7, #0xF
         MOV.W           R3, R2,LSL#4
         */

         if(!bls)
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

      /*
      MOVW            R1, #(ctx_130_part_C904A8 AND 0xFFFF)
      ADD.W           R8, R8, #0x10
      MOVT.W          R1, #high16(ctx_130_part_C904A8) ; 00C904A8 data reference 00000001 - end pointer
      ADD.W           R11, R11, #0x10
      */

      if(r8 == r1)
         break;
   }

   /*
   MOVS            R3, #0
   MOV             R0, R6  ; ptr
   MOV             R1, R3  ; value
   MOV.W           R2, #0x3F0 ; num
   STR             R3, [SP,#0x478+dec_data_464] ; derived key data
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+4]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0xC]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0x14]
   STRD.W          R3, R3, [SP,#0x478+dec_data_464+0x1C]
   BLX             SceMsif.SceSysclibForDriver._imp_memset_0ab9bf5c ; clear all sensitive data
   LDR.W           R12, [SP,#0x478+var_470] ; get dec flag pointer
   MOVS            R3, #1
   STR.W           R3, [R12] ; setup dec flag
   */

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