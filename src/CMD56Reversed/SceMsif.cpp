#include <stdint.h>
#include <string.h>

#include "SceSblSsMgr.h"

typedef struct SceMsif_subctx
{
}SceMsif_subctx;

#define MS_TPC_48 0x48
#define MS_TPC_49 0x49
#define MS_TPC_4A 0x4A
#define MS_TPC_4B 0x4B

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

int execute_f00d_command_2_rmauth_sm_C8D988(const char input[8])
{
   return 0;
}

int w_dmac5_command_0x41_C8D2F0(char* result, const char* data, int size)
{
   return 0;
}

int get_sha224_digest_source_validate_card_init_f00D_C8D5FC(SceMsif_subctx *subctx, char *sha224_digest_source)
{
   int cmd1_res = 0;

   int fdres1 = food_execute_f00d_command_1_rmauth_sm_C8D908(&cmd1_res);
   if(fdres1 < 0)
      return fdres1;

   //----------------

   //generate random number
   char rand_value[8];
   memset(rand_value, 0, 8);

   int rdgenres1 = SceSblSsMgrForDriver_4dd1b2e5(rand_value, 8, 1);
   if(rdgenres1 < 0)
      return rdgenres1;

   //----------------

   //save rand to temp
   char rand_B8[8];
   memset(rand_B8, 0, 8);
   memcpy(rand_B8, rand_value, 0);

   //prepare cmd 0x48 request
   char cmd48_src[0x20];
   memset(cmd48_src, 0, 0x20);

   //8 + 1 + 0x17 = 0x20 total in bytes
   memcpy(cmd48_src, rand_B8, 8); //copy rand
   cmd48_src[8] = cmd1_res; //copy cmd1 resp 1 byte
   memset(cmd48_src + 9, 0, 0x17); //fill rest with 0

   //execute command 48
   int res48 = ms_execute_ex_set_cmd_write_short_data_C8A3A8(subctx, MS_TPC_48, 0x20, cmd48_src, 1000);
   if(res48 != 0)
      return res48; //returns not exactly this, but we dont care here

   //----------------

   char cmd49_dest[0x40];
   memset(cmd49_dest, 0, 0x40);
   
   int res49 = ms_execute_ex_set_cmd_read_short_data_C8A448(subctx, MS_TPC_49, 0x40, cmd49_dest, 1000);

   //----------------

   char F00D_cmd2_buffer_98[0x10];
   memset(F00D_cmd2_buffer_98, 0, 0x10);

   char* r11 = F00D_cmd2_buffer_98;
   char* r6 = cmd49_dest;

   int r0 = cmd49_dest[0];
   int r1 = cmd49_dest[1];
   int r2 = cmd49_dest[2];
   int r3 = cmd49_dest[3];

   char* r4 = cmd49_dest + 0x10;

   char var_88[0x10];
   memset(var_88, 0, 0x10);

   char* lr = var_88;

   char* r9 = cmd49_dest + 0x18;

   char* var_E0 = r4;

   char* r12 = var_88 + 8;

   char* r4 = cmd49_dest + 0x20;

   r11[0] = r0;
   r11[4] = r1; 
   r11[8] = r2;
   r11[C] = r3;

   char var_C8[8];
   memset(var_C8, 0, 8);

   char* r3 = var_C8;

   char* r2 = var_E0;

   int r0 = r2[0];
   int r1 = r2[4];

   lr[0] = r0;
   lr[4] = r1;

   int r0 = r9[0];
   int r1 = r9[4];
   
   int r2 = *(var_88 + 7);
   int var_DC = r2;

   r12[0] = r0;
   r12[4] = r1;
   
   int r0 = r4[0];
   int r1 = r4[4];

   r3[0] = r0;
   r3[4] = r1;

   int fdres2 = execute_f00d_command_2_rmauth_sm_C8D988(r11);
   if(fdres2 < 0)
      return fdres2;

   //----------------

   char cmd4A_src[0x20];
   memset(cmd4A_src, 0, 0x20);


   return 0;
}