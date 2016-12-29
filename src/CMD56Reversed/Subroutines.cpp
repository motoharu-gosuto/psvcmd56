#include "Subroutines.h"

#include "GlobalConstants.h"
#include "GlobalVariables.h"
#include "Constants.h"
#include "Imports.h"
#include "UnknownImports.h"

//FULLY REVERSED

//initializes cmd56 request packet
void sub_CA8C98(const char* source_ptr, int size, int param1, int param2, char* destination_ptr)
{
   memset(destination_ptr, 0, 0x200);

   memcpy(destination_ptr, dword_CADA7C, 0x20);

   destination_ptr[0x20] = param2;
   destination_ptr[0x21] = param2 >> 8;
   destination_ptr[0x22] = param2 >> 16;
   destination_ptr[0x23] = param2 >> 24;

   destination_ptr[0x24] = size;
   destination_ptr[0x25] = size >> 8;
   destination_ptr[0x26] = size >> 16;
   destination_ptr[0x27] = size >> 24;

   destination_ptr[0x28] = param1 ;
   destination_ptr[0x29] = param1 >> 8;
   destination_ptr[0x2A] = param1 >> 16;
   destination_ptr[0x2B] = param1 >> 24;

   memcpy(destination_ptr + 0x2C, source_ptr, size);
}

//FULLY REVERSED

//generate some 0x10 bytes
int sub_CA8E5C(char* buffer)
{
   char var54[0x40];
   int var14 = var_009EA004;

   int r0;

   for(int i = 0; i != 0x10; i++)
   {
      //this function either generates data per byte or shifts the buffer
      r0 = SceSblGcAuthMgr_SceSblSsMgrForDriver_imp_ac57f4f0(var54);
      
      if(r0 != 0)
      {
         if(var14 == var_009EA004)
            return 0x808A0700;
         else
            return STACK_CHECK_FAIL;
      }

      buffer[i] = var54[0];
   }   

   if(var14 == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

//FULLY REVERSED

//proc_initialize_packet_15_or_17
//originally had 2 arguments
//however I decided to move globals to arguments to make sure I see all the dependencies
//initializes 0x20 + 0x0C + 0x33 = 0x5F bytes of a_00BDCBF4_REQBUF
int sub_CA8DC0(char idx, int packet6_de, const char* a_00BDCFF8, const char* a_00BDCBC4, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF)
{
   char data_buffer[51];

   int var1C = var_009EA004;

   memcpy(data_buffer, a_00BDCFF8, 0x20);

   memcpy(data_buffer + 0x20, a_00BDCBC4, 0x30);

   data_buffer[0x50] = idx;

   //size of data structure is exactly 0x51
   int r0 = sub_CAC924(a_00BDCDF8_WB20, data_buffer, CAC924_COMMAND_1E, 0x51, packet6_de);
      
   if(r0 != 0)
   {
      if(var1C == var_009EA004)
         return -1;
      else
         return STACK_CHECK_FAIL;
   }

   sub_CA8C98(a_00BDCDF8_WB20, 0x33, 0x43, 0x11, a_00BDCBF4_REQBUF); //initialize cmd56

   if(var1C == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

//FULLY REVERSED

//this procedure is used to initialize and send packet 3 then receive packet 4
//also used for packet 11 and packet 12
//originally it had only 2 arguments 
//however I decided to move globals to arguments to make sure I see all the dependencies
char sub_CA8D30(sd_context* ctx, std::pair<char,char>* result_ptr, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF, char* a_00BDD04C_RESPBUF1)
{
   a_00BDCDF8_WB20[0x00] = 0xC2;
   a_00BDCDF8_WB20[0x01] = 0x00;
   a_00BDCDF8_WB20[0x02] = 0x03;

   sub_CA8C98(a_00BDCDF8_WB20, 0x03, 0x05, 0x23, a_00BDCBF4_REQBUF); //initialize cmd56 packet

   int r0_req = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(ctx, a_00BDCBF4_REQBUF, 0x200); //request

   if(r0_req != 0)
      return r0_req;

   int r0_resp = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(ctx, a_00BDD04C_RESPBUF1, 0x200, PACKET_4_INDEX); //response

   if(r0_resp != 0)
      return r0_resp;

   if(a_00BDD04C_RESPBUF1[0x00] != 0x23)
      return -1;

   if(a_00BDD04C_RESPBUF1[0x04] != 0x00)
      return -1;

   if(a_00BDD04C_RESPBUF1[0x0A] != 0x00)
      return a_00BDD04C_RESPBUF1[0x0A];

   result_ptr->first = a_00BDD04C_RESPBUF1[0x0B];
   result_ptr->second = a_00BDD04C_RESPBUF1[0x0C];
   
   return a_00BDD04C_RESPBUF1[0x0A];
}

//FULLY REVERSED

int exit_loc_CA9058(int r3, int var24)
{
   if(var24 == var_009EA004)
      return r3;
   else
      return STACK_CHECK_FAIL;
}

//this procedure is used to initialize and send packets 17 and 19 and get corresponding responces 18 and 20
//originally it had only 2 arguments 
//however I decided to move globals to arguments to make sure I see all the dependencies
int sub_CA8EA0(sd_context* sd_context, int packet6_de, const char* a_00BDCFF8, const char* a_00BDCBC4, char* a_00BDCDF8_WB20, char* a_00BDCBF4_REQBUF, char* a_00BDD04C_RESPBUF1, char* a_00BDD24C_RESPBUF2, char* a_00BDD018)
{
   int var24 = var_009EA004; //stack cookie

   //packet 17
   //initializes 0x5F bytes of _00BDCBF4_REQBUF
   int res0 = sub_CA8DC0(0x03, packet6_de, a_00BDCFF8, a_00BDCBC4, a_00BDCDF8_WB20, a_00BDCBF4_REQBUF); //initialize packet 17
   if(res0 != 0)
      return exit_loc_CA9058(res0, var24);

   //copy 0x10 bytes from request (data will be initialized with sub_CA8DC0)
   char var15C[0x20];
   memcpy(var15C, a_00BDCBF4_REQBUF + 0x2F, 0x20);

   int res1 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(sd_context, a_00BDCBF4_REQBUF, 0x200); //request
   if(res1 != 0)
      return exit_loc_CA9058(res1, var24);

   //packet 18

   int res2 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(sd_context, a_00BDD04C_RESPBUF1, 0x200, PACKET_18_INDEX);
   if(res2 != 0)
      return exit_loc_CA9058(res2, var24);

   //packet 19

   a_00BDCDF8_WB20[0x00] = 0xC1;
   a_00BDCDF8_WB20[0x01] = 0x00;
   a_00BDCDF8_WB20[0x02] = 0x13;

   int res3 = sub_CA8E5C(a_00BDCDF8_WB20 + 0x03); // gen 0x10 bytes
   if(res3 != 0)
      return exit_loc_CA9058(res3, var24);

   a_00BDCDF8_WB20[0x03] = a_00BDCDF8_WB20[0x03] | (~0x7F);

   sub_CA8C98(a_00BDCDF8_WB20, 0x13, 0x53, 0x19, a_00BDCBF4_REQBUF); //initialize cmd56 packet

   //copy another 0x10 bytes from request (data will be different since packet will be initialized with sub_CA8C98)
   char var16C[0x10];
   memcpy(var16C, a_00BDCBF4_REQBUF + 0x2F, 0x10);

   int res4 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(sd_context, a_00BDCBF4_REQBUF, 0x200); //request
   if(res4 != 0)
      return exit_loc_CA9058(res4, var24);

   //packet 20
   
   int res5 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(sd_context, a_00BDD24C_RESPBUF2, 0x200, PACKET_20_INDEX);
   if(res5 != 0)
      return exit_loc_CA9058(res5, var24);

   //check responces

   if(a_00BDD04C_RESPBUF1[0x00] != 0x11)
      return exit_loc_CA9058(-1, var24);

   if(a_00BDD04C_RESPBUF1[0x04] != 0)
      return exit_loc_CA9058(-1, var24);

   if(a_00BDD04C_RESPBUF1[0x0A] != 0)
      return exit_loc_CA9058(a_00BDD04C_RESPBUF1[0x0A], var24);

   if(a_00BDD24C_RESPBUF2[0x00] != 0x19)
      return exit_loc_CA9058(-1, var24);

   if(a_00BDD24C_RESPBUF2[0x04] != 0)
      return exit_loc_CA9058(-1, var24);

   if(a_00BDD24C_RESPBUF2[0x0A] != 0)
      return exit_loc_CA9058(a_00BDD24C_RESPBUF2[0x0A], var24);

   //finalize the data
   //total size would be 0x20 + 0x30 + 0x20 + 0x43 + 0x10 + 0x53 = 0x116

   char generic_buffer[0x116];

   memcpy(generic_buffer, a_00BDCFF8, 0x20);
   memcpy(generic_buffer + 0x20, a_00BDCBC4, 0x30);   
   memcpy(generic_buffer + 0x50, var15C, 0x20);
   memcpy(generic_buffer + 0x70, a_00BDD04C_RESPBUF1 + 0x08, 0x43);
   memcpy(generic_buffer + 0xB3, var16C, 0x10);
   memcpy(generic_buffer + 0xC3, a_00BDD24C_RESPBUF2 + 0x08, 0x53);

   int res6 = sub_CAC924(a_00BDD018, generic_buffer, CAC924_COMMAND_20, 0x116, packet6_de);
   if(res6 != 0)
      return exit_loc_CA9058(-3, var24);

   return exit_loc_CA9058(a_00BDD24C_RESPBUF2[0x0A], var24);
}

//===================================================

//FULLY REVERSED

int sub_CAC8C0(int* var97C, std::pair<int, int>* arg1)
{
   if(var97C != 0 && arg1 != 0)
   {
      arg1->first = -1;
      arg1->second = -1;
      return SceSblGcAuthMgr_SceSblSmCommForKernel_imp_0631f8ed(*var97C);
   }
   else
   {
      return 0x800F1816;
   }
}

int exit_loc_CAC90A(int r0, int var14)
{
   if(var14 == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

int sub_CAC8E4(int* var97C)
{
   std::pair<int, int> var1C;
   int var14 = var_009EA004;

   if(var97C == 0)
      return exit_loc_CAC90A(0x800F1816, var14);

   if(((*var97C) + 1) == 0)
      return exit_loc_CAC90A(0x800F1816, var14);

   int r0 = sub_CAC8C0(var97C, &var1C);
   (*var97C) = -1;
  
   return exit_loc_CAC90A(r0, var14);
}

int exit_loc_CAC9D6(int r4, int var24)
{
   if(var24 == var_009EA004)
      return STACK_CHECK_FAIL;
   else
      return r4;
}

int exit_loc_CACAA8(int var24)
{
   return exit_loc_CAC9D6(0x800F1816, var24);
}

int exit_loc_CAC9CA(int r4, int* var97C, int var24)
{
   if(((*var97C) + 1) == 0)
   {
      return exit_loc_CAC9D6(r4, var24);
   }
   else
   {
      sub_CAC8E4(var97C);
      return exit_loc_CAC9D6(r4, var24);
   }
}

int exit_loc_CACAB2(int* var97C, int var24)
{
   return exit_loc_CAC9CA(0x800F0016, var97C, var24);
}

int finish_CACA88(char* r8, char* var830, int r2, int r4, int* var97C, int var24)
{
   if(r8 == 0)
      return exit_loc_CAC9CA(r4, var97C, var24);

   memcpy(r8, var830, r2);

   return exit_loc_CAC9CA(r4, var97C, var24);
}

//parameters used for this function are:
//0x1B, 0x53 - confirmed
//0x1C, 0x40 -  ! - must be 0x33
//0x1D, 0xA3 - confirmed
//0x1E, 0x51 -  ! - must be 0x33
//0x1F, 0xB3 -  ! - must be 0x20
//0x20, 0x116 - ! - must be 0x34
//some of them do not match the conditions meaning that data will not be copied into resulting buffer
//this raises the question of - does some subroutine actually change size in r2 ?
//since there is a condition that compares r7 and r2

#define CAC924_ERROR_CODE 0x10

int sub_CAC924_command(int r2, int r3, int r7, int* var97C, int var24, char* var830, char* r8)
{
   if(r2 > 0x800)
      return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);

   if(r3 == 0x04 || r3 != 0x07)
   {
      //what is the point of this comparison ?
      //they should be equal - if not then it means that r2 is modified by other function
      //since it is part of structure

      if(r7 != r2) 
         return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);

      //not sure what this shifting means
      //28 is probably number of bits
      //probably not allowing sizes less than 0xFF ? - weird

      if((r7 << 0x1C) == 0)
         return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
   
      if(r7 == 0)
         return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
   }

   //-------------

   switch(r3)
   {
   case CAC924_COMMAND_0C:
      {
         if(r2 == 0x3C)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_0D:
      {
         if(r2 == 0x28)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_0E:
      {
         if(r2 == 0x14)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_10:
      {
         if(r2 == 0x28)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_11:
       {
         if(r2 == 0x64)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_12:
      {
         if(r2 == 0xB8)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_14:
      {
         if(r2 == 0x54)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_15:
       {
         if(r2 == 0x38)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_16:
      {
         if(r2 == 0x1C)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_17:
      {
         if(r2 == 0x38)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24); 
      }
   case CAC924_COMMAND_18:
      {
         if(r2 == 0x8C)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_19:
      {
         if(r2 == 0xE8)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_1B:
      {
         if(r2 == 0x53)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_1C:
      {
         if(r2 == 0x33)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_1D:
      {
         if(r2 == 0xA3)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_1E:
      {
         if(r2 == 0x33)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_1F:
      {
         if(r2 == 0x20)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_20:
      {
         if(r2 == 0x34)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_21:
      {
         if(r2 == 0x28)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   case CAC924_COMMAND_22:
      {
         if(r2 == 0x38)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24); 
      }
   case CAC924_COMMAND_23:
      {
         if(r2 == 0x20)
            return finish_CACA88(r8, var830, r2, 0, var97C, var24);
         else
            return exit_loc_CAC9CA(CAC924_ERROR_CODE, var97C, var24);
      }
   default:
      return finish_CACA88(r8, var830, r2, 0, var97C, var24);
   }
}

//if sizes are so different, can this be some hashing function or something ?
//this algo must be very generic
//source is of size 0x53, 0x40, 0xA3, 0xB3, 0x51, 0x116
//destination is of size 0x200 (it is a_00BDCDF8_WB20 buffer)

//i suspect that this function should also have context because:
//it can be called with destination = 0 - like an initialization step
//then it is called again with actual parameters

//judging by this function - it does not use any globals meaning that it can not store any context
//which means that it can use other internal subroutines that create and store context
//this most likely happens in SceSblSmCommForKernel

int sub_CAC924(char* destination, char* source, int command, int size, int packet6_de)
{
   int var97C = -1; //trigger for some cleanup on exit?
   int var978 = 0x00;

   int var974 = 0x0C;
   int var970 = 0x00;
   int var96C = 0x00;

   //I would assume that var968 is some sort of struct
   //however first 4 bytes (that are probably size) are never set
   //second dword contains value 2
   //starting from third dword - some data is copied from dword_CADC10 - size is 0x90
   //this is in total 0x90 + 0x08 = 0x98 bytes
   //leaving space of another 0x98 bytes
   //meaning this could also be array of 2 elements of size 0x98

   char var968[0x130];

   int var838 = 0x01;
   int var834 = command;

   char var830[0x800]; //working buffer

   int var30 = packet6_de;
   int var2C = size;
   int var28 = 0x00;

   int var24 = var_009EA004; //stack cookie  
    
   if(size > 0x800)
      return exit_loc_CACAA8(var24);

   if(source != 0)
      SceSblGcAuthMgr_SceSysclibForDriver_imp_8a0b0815(var830, source, size, 0x80C); //debug memcpy

   int res0 = SceSblGcAuthMgr_SceSysrootForKernel_imp_f10ab792(0, &var974);
   if(res0 < 0)
      return exit_loc_CACAB2(&var97C, var24);

   memset(var968, 0x00, 0x130);

   memcpy(var968 + 8, dword_CADC10, 0x90); //store to var960

   var968[0x04] = 0x02;
   var968[0x128] = 0x02;

   //I would assume that var970 and var96C are equal to 0 - unless they are modified somehow above which I do not see
   int res1 = SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1(0x00, var970, var96C, 0x00, var968, &var97C);
   if(res1 != 0)
      return exit_loc_CAC9CA(res1, &var97C, var24);

   int res2 = SceSblGcAuthMgr_SceSblSmCommForKernel_imp_db9fc204(var97C, 0x0001000B, &var978, &var838, 0x814);
   if(res2 != 0)
      return exit_loc_CAC9CA(res2, &var97C, var24);

   if(var978 != 0)
      return exit_loc_CAC9CA(var978, &var97C, var24);

   return sub_CAC924_command(var2C, var834, size, &var97C, var24, var830, destination);
}