#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <stdint.h>

#include "CMD56Initialization.h"
#include "ResponsePackets.h"
#include "GlobalConstants.h"
#include "Subroutines.h"
#include "Imports.h"
#include "Constants.h"
#include "UnknownImports.h"

int exit_loc_CA91F0(int r6, int var2C)
{
   if(var2C == var_009EA004)
      return r6;
   else
      return STACK_CHECK_FAIL;
}

int exit_loc_CA91DA(int r6, int var2C)
{
   int r0 = SceSblGcAuthMgr_SceThreadmgrForDriver_imp_d270498b(_00BD84D8_THREAD_ID, 0x01);
      
   if(r0 != 0)
      return exit_loc_CA91F0(0x808A0701, var2C);
   else
      return exit_loc_CA91F0(r6, var2C);
}

int exit_loc_CA91D6(int r6, int var2C)
{
   SceSblGcAuthMgr_SceSblGcAuthMgrDrmBBForDriver_exp_bb451e83();
   return exit_loc_CA91DA(r6, var2C);
}

int initialize_sd(int* argument0, int var2C)
{
   //=============================

   //do something with thread manager

   int res0 = SceSblGcAuthMgr_SceThreadmgrForDriver_imp_3c8b55a9(_00BD84D8_THREAD_ID, 0x01, 0x00);

   if(res0 != 0)
     return exit_loc_CA91F0(0x808A0701, var2C);

   if(argument0[0] < 0x10000)
      return exit_loc_CA91D6(0x808A0702, var2C);

   //============================

   //figure out if we need to initialize the card

   //is this order of initialization correct?

   _00BDCBC0_SD_CTX_ELM = SceSblGcAuthMgr_SceSdifForDriver_imp_6a71987f(0x01); //get element
   
   if(_00BDCBC0_SD_CTX_ELM == 0)
   {
      int res1 = SceSblGcAuthMgr_SceSdifForDriver_imp_22c82e79(0x01, &_00BDCBC0_SD_CTX_ELM);
      if(res1 != 0)
         return exit_loc_CA91D6(0x808A0703, var2C);
   }

   return 0;
}  

int packets1_to_6(int var2C)
{
   //================================================
   
   //send packet 1

   _00BDCDF8_WB20[0x00] = 0xC4;
   _00BDCDF8_WB20[0x01] = 0x00;
   _00BDCDF8_WB20[0x02] = 0x03;
   
   sub_CA8C98(_00BDCDF8_WB20, 0x03, 0x13, 0x31, _00BDCBF4_REQBUF); //initialize cmd56 packet

   int res2 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(_00BDCBC0_SD_CTX_ELM, _00BDCBF4_REQBUF, 0x200); //cmd56 request
   if(res2 != 0)
      return exit_loc_CA91D6(0x808A0704, var2C);

   //================================================

   //receive packet 2
         
   int res3 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(_00BDCBC0_SD_CTX_ELM, _00BDD04C_RESPBUF1, 0x200, PACKET_2_INDEX); //cmd56 responce

   //================================================

   //check packet 2

   if(res3 != 0)
      return exit_loc_CA91D6(0x808A0704, var2C);

   if(_00BDD04C_RESPBUF1[0x00] != 0x31)
      return exit_loc_CA91D6(0x808A0704, var2C);

   if(_00BDD04C_RESPBUF1[0x04] != 0x00)
      return exit_loc_CA91D6(0x808A0704, var2C);

   if(_00BDD04C_RESPBUF1[0x0A] != 0x00)
      return exit_loc_CA91D6(0x808A0704, var2C);

   //================================================

   //packet 3 packet 4

   std::pair<char, char> arg20_21;

   int res4 = sub_CA8D30(_00BDCBC0_SD_CTX_ELM, &arg20_21, _00BDCDF8_WB20, _00BDCBF4_REQBUF, _00BDD04C_RESPBUF1); //packet 3 packet 4
   if(res4 != 0)
      return exit_loc_CA91D6(0x808A0705, var2C);

   //================================================

   //check packet 4

   if(arg20_21.second != 0)
      return exit_loc_CA91D6(0x808A0706, var2C);
   
   if(arg20_21.first == 0)
      return exit_loc_CA91D6(0x808A0706, var2C);

   //================================================

   //packet 5

   _00BDCDF8_WB20[0x00] = 0xA1;
   _00BDCDF8_WB20[0x01] = 0x00;
   _00BDCDF8_WB20[0x02] = 0x03;

   sub_CA8C98(_00BDCDF8_WB20, 0x03, 0x2B, 0x02, _00BDCBF4_REQBUF); //initialize cmd56  packet

   int res5 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(_00BDCBC0_SD_CTX_ELM, _00BDCBF4_REQBUF, 0x200); //request
   if(res5 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //================================================

   //packet6

   int r6 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(_00BDCBC0_SD_CTX_ELM, _00BDD04C_RESPBUF1, 0x200, PACKET_6_INDEX);
   if(r6 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //================================================

   //check packet 6

   if(_00BDD04C_RESPBUF1[0x00] != 0x02)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x04] != 0x00)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x0A] != 0x00)
   {
      memset(_00BDCFF8, 0x00, 0x20);
      return exit_loc_CA91D6(0x808A0707, var2C);
   }

   return 0;
}

int packet7_to_8(int var2C)
{
   //packet 7

   //not sure about this check

   _00BDCDF4_PACKET6_DE = ((int)_00BDD04C_RESPBUF1[0x0E]) | (((int)_00BDD04C_RESPBUF1[0x0D]) << 8);
      
   if((_00BDCDF4_PACKET6_DE & (~0x8000)) != 1)
      return exit_loc_CA91D6(0x808A0707, var2C);

   _00BDCDF8_WB20[0x00] = 0xA2;
   _00BDCDF8_WB20[0x01] = 0x00;
   _00BDCDF8_WB20[0x02] = 0x15;
   _00BDCDF8_WB20[0x03] = _00BDCDF4_PACKET6_DE >> 8; //not sure about this
   _00BDCDF8_WB20[0x04] = _00BDCDF4_PACKET6_DE;      //not sure about this

   //copy key from packet 6

   _00BDCFF8[0x00] = _00BDD04C_RESPBUF1[0x13 + 0x00];
   _00BDCFF8[0x04] = _00BDD04C_RESPBUF1[0x13 + 0x04];
   _00BDCFF8[0x08] = _00BDD04C_RESPBUF1[0x13 + 0x08];
   _00BDCFF8[0x0C] = _00BDD04C_RESPBUF1[0x13 + 0x0C];

   _00BDCFF8[0x10 + 0x00] = _00BDD04C_RESPBUF1[0x13 + 0x10];
   _00BDCFF8[0x10 + 0x04] = _00BDD04C_RESPBUF1[0x13 + 0x14];
   _00BDCFF8[0x10 + 0x08] = _00BDD04C_RESPBUF1[0x13 + 0x18];
   _00BDCFF8[0x10 + 0x0C] = _00BDD04C_RESPBUF1[0x13 + 0x1C];

   int res3 = sub_CA8E5C(_00BDCDF8_WB20 + 0x05);
   if(res3 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   _00BDCDF8_WB20[0x05] = (_00BDCDF8_WB20[0x05] | (~0x7F));
   
   sub_CA8C98(_00BDCDF8_WB20, 0x15, 0x23, 0x03, _00BDCBF4_REQBUF); //initialize cmd56 packet

   int res4 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(_00BDCBC0_SD_CTX_ELM, _00BDCBF4_REQBUF, 0x200);
   if(res4 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   // packet 8

   int res5 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(_00BDCBC0_SD_CTX_ELM, _00BDD04C_RESPBUF1, 0x200, PACKET_8_INDEX);
   if(res5 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   return 0;
}

//copies data to arg44 buffer
//layous are: 
//0x20 0x10 0x20 0x3 = 0x53 bytes
//0x20 0x20 = 0x40 bytes
int packet9_to_10(char* arg44, int var2C)
{
   //================================================

   //check packet 8
      
   if(_00BDD04C_RESPBUF1[0x00] != 0x03)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x04] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x0A] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //================================================

   //packet 9

   // copy key from packet 6 - 0x20

   arg44[0x00] = _00BDCFF8[0x00]; 
   arg44[0x04] = _00BDCFF8[0x04];
   arg44[0x08] = _00BDCFF8[0x08];
   arg44[0x0C] = _00BDCFF8[0x0C];

   arg44[0x10 + 0x00] = _00BDCFF8[0x10 + 0x00];
   arg44[0x10 + 0x04] = _00BDCFF8[0x10 + 0x04];
   arg44[0x10 + 0x08] = _00BDCFF8[0x10 + 0x08];
   arg44[0x10 + 0x0C] = _00BDCFF8[0x10 + 0x0C];

   //copy key from packet 7 - 0x10

   arg44[0x20 + 0x00] = _00BDCBF4_REQBUF[0x31 + 0x00];
   arg44[0x20 + 0x04] = _00BDCBF4_REQBUF[0x31 + 0x04];
   arg44[0x20 + 0x08] = _00BDCBF4_REQBUF[0x31 + 0x08];
   arg44[0x20 + 0x0C] = _00BDCBF4_REQBUF[0x31 + 0x0C];

   //copy key from packet 8 - 0x20
   
   arg44[0x30 + 0x00] = _00BDD04C_RESPBUF1[0x08 + 0x00];
   arg44[0x30 + 0x04] = _00BDD04C_RESPBUF1[0x08 + 0x04];
   arg44[0x30 + 0x08] = _00BDD04C_RESPBUF1[0x08 + 0x08];
   arg44[0x30 + 0x0C] = _00BDD04C_RESPBUF1[0x08 + 0x0C];
   
   arg44[0x30 + 0x10 + 0x00] = _00BDD04C_RESPBUF1[0x08 + 0x10 + 0x00];
   arg44[0x30 + 0x10 + 0x04] = _00BDD04C_RESPBUF1[0x08 + 0x10 + 0x04];
   arg44[0x30 + 0x10 + 0x08] = _00BDD04C_RESPBUF1[0x08 + 0x10 + 0x08];
   arg44[0x30 + 0x10 + 0x0C] = _00BDD04C_RESPBUF1[0x08 + 0x10 + 0x0C];

   //this part is a bit cryptic - not sure about it
   //not sure about what exactly is chopped to 0x53 bytes
   arg44[0x50] = _00BDD04C_RESPBUF1[0x08 + 0x20]; 
   arg44[0x50 + 0x02] = _00BDD04C_RESPBUF1[0x08 + 0x20] >> 16;

   int res4 = sub_CAC924(0, arg44, CAC924_COMMAND_1B, 0x53, _00BDCDF4_PACKET6_DE);
   if(res4 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //================================================
   
   //is _00BDCFF8 modified somehow ?
   //or maybe this is just duplicate copy because original is stored in internal context of sub_CAC924 ?

   //copies 0x20 bytes
  
   arg44[0x00] = _00BDCFF8[0x00];
   arg44[0x04] = _00BDCFF8[0x04];
   arg44[0x08] = _00BDCFF8[0x08];
   arg44[0x0C] = _00BDCFF8[0x0C];  

   arg44[0x10 + 0x00] = _00BDCFF8[0x10 + 0x00];
   arg44[0x10 + 0x04] = _00BDCFF8[0x10 + 0x04];
   arg44[0x10 + 0x08] = _00BDCFF8[0x10 + 0x08];
   arg44[0x10 + 0x0C] = _00BDCFF8[0x10 + 0x0C];

   //this key is different but is part of packet 8 (shifted by 3 bytes (8 -> B))

   //copies 0x20 bytes

   arg44[0x20 + 0x00] = _00BDD04C_RESPBUF1[0x0B + 0x00];
   arg44[0x20 + 0x04] = _00BDD04C_RESPBUF1[0x0B + 0x04];
   arg44[0x20 + 0x08] = _00BDD04C_RESPBUF1[0x0B + 0x08];
   arg44[0x20 + 0x0C] = _00BDD04C_RESPBUF1[0x0B + 0x0C];

   arg44[0x20 + 0x10 + 0x00] = _00BDD04C_RESPBUF1[0x0B + 0x10];
   arg44[0x20 + 0x10 + 0x04] = _00BDD04C_RESPBUF1[0x0B + 0x14];
   arg44[0x20 + 0x10 + 0x08] = _00BDD04C_RESPBUF1[0x0B + 0x18];
   arg44[0x20 + 0x10 + 0x0C] = _00BDD04C_RESPBUF1[0x0B + 0x1C];
   
   //================================================
   
   int res5 = sub_CAC924(_00BDCDF8_WB20, arg44, CAC924_COMMAND_1C, 0x40, _00BDCDF4_PACKET6_DE);
   if(res5 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //================================================

   char* start_30 = _00BDCDF8_WB20 + 0x03;
   char* dest_30 = _00BDCBC4;
   char* end_30 = start_30 + 0x30;

   do
   {
      dest_30[0x00] = start_30[0x00];
      dest_30[0x04] = start_30[0x04];
      dest_30[0x08] = start_30[0x08];
      dest_30[0x0C] = start_30[0x0C];

      start_30 = start_30 + 0x10;
      dest_30 = dest_30 + 0x10;
   }
   while(start_30 != end_30);

   //================================================
   
   sub_CA8C98(_00BDCDF8_WB20, 0x33, 0x03, 0x05, _00BDCBF4_REQBUF); //initialize cmd56 packet

   int res6 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(_00BDCBC0_SD_CTX_ELM, _00BDCBF4_REQBUF, 0x200); //request
   if(res6 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //================================================

   //packet 10

   int res7 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(_00BDCBC0_SD_CTX_ELM, _00BDD04C_RESPBUF1, 0x200, PACKET_10_INDEX); //responce
   if(res7 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   return 0;
}

int packet11_to_12(int var2C)
{
   //================================================

   //packet 11 packet 12

   if(_00BDD04C_RESPBUF1[0x00] != 0x05)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x04] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x0A] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   std::pair<char, char> arg20_21;

   int r0 = sub_CA8D30(_00BDCBC0_SD_CTX_ELM, &arg20_21, _00BDCDF8_WB20, _00BDCBF4_REQBUF, _00BDD04C_RESPBUF1); //packet 11 packet 12
   if(r0 != 0)
      return exit_loc_CA91D6(0x808A0705, var2C);

   if(arg20_21.second != 0)
      return exit_loc_CA91D6(0x808A0706, var2C);
   
   if(arg20_21.first != 0)
      return exit_loc_CA91D6(0x808A0706, var2C);

   return 0;
}

enum cycle_state
{
   c_ok,
   c_continue,
   c_error,
};

//copies data to arg24 buffer
//layous are: 
//0x10 = 0x10 bytes
std::pair<cycle_state, int> packet13_to_14(char* arg24, sce_time& time_0, int& varC, int var2C)
{
   //packet 13

   _00BDCDF8_WB20[0x00] = 0xA4;
   _00BDCDF8_WB20[0x01] = 0x00;
   _00BDCDF8_WB20[0x02] = 0x13;

   int res6 = sub_CA8E5C(_00BDCDF8_WB20 + 0x03); //10 byte keygen
   if(res6 != 0) //loc_CA966A
   {
      varC = varC - 1; //dec counter
      if(varC == 0)
      {
         int error = exit_loc_CA91D6(0x808A0707, var2C);
         return std::make_pair(c_error, error);
      }
      return std::make_pair(c_continue, 0); // continue cycle
   }

   _00BDCDF8_WB20[0x03] = (_00BDCDF8_WB20[0x03] | (~0x7F));
      
   sub_CA8C98(_00BDCDF8_WB20, 0x13, 0x43, 0x07, _00BDCBF4_REQBUF); //initialize cmd56 packet

   arg24[0x00] = _00BDCBF4_REQBUF[0x2F + 0x00];
   arg24[0x04] = _00BDCBF4_REQBUF[0x2F + 0x04];
   arg24[0x08] = _00BDCBF4_REQBUF[0x2F + 0x08];
   arg24[0x0C] = _00BDCBF4_REQBUF[0x2F + 0x0C];

   time_0 = SceSblGcAuthMgr_SceThreadmgrForDriver_imp_sceKernelGetSystemTimeWideForDriver_f4ee4fa9();

   int res7 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(_00BDCBC0_SD_CTX_ELM, _00BDCBF4_REQBUF, 0x200); //cmd request
   if(res7 != 0) //loc_CA966A
   {
      varC = varC - 1; //dec counter
      if(varC == 0)
      {
         int error = exit_loc_CA91D6(0x808A0707, var2C);
         return std::make_pair(c_error, error);
      }
      return std::make_pair(c_continue, 0); // continue cycle
   }

   //================================================
      
   //packet 14
      
   int res8 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(_00BDCBC0_SD_CTX_ELM, _00BDD04C_RESPBUF1, 0x200, PACKET_14_INDEX); //responce
   if(res8 != 0) //loc_CA966A
   {
      varC = varC - 1; //dec counter
      if(varC == 0)
      {
         int error = exit_loc_CA91D6(0x808A0707, var2C);
         return std::make_pair(c_error, error);
      }
      return std::make_pair(c_continue, 0); // continue cycle
   }

   return std::make_pair(c_ok, 0);
}

//copies data to arg44 buffer
//layouts are:
//0x20 0x30 0x10 0x43 = 0xA3 bytes
int packet15_preinit(char* arg44, const char* arg24)
{
   int A0_intermediate;

   if(_00BDD04C_RESPBUF1[0x00] != 0x07)
   {
      return -1;
   }
   else
   {
      if(_00BDD04C_RESPBUF1[0x04] != 0)
      {
         return -1;
      }
      else
      {
         if(_00BDD04C_RESPBUF1[0x0A] == 0)
         {
            //copy 0x20 bytes

            arg44[0x00] = _00BDCFF8[0x00];
            arg44[0x04] = _00BDCFF8[0x04];
            arg44[0x08] = _00BDCFF8[0x08];
            arg44[0x0C] = _00BDCFF8[0x0C];

            arg44[0x10 + 0x00] = _00BDCFF8[0x10 + 0x00];
            arg44[0x10 + 0x04] = _00BDCFF8[0x10 + 0x04];
            arg44[0x10 + 0x08] = _00BDCFF8[0x10 + 0x08];
            arg44[0x10 + 0x0C] = _00BDCFF8[0x10 + 0x0C];

            //copy 0x30 bytes
               
            arg44[0x20 + 0x00] = _00BDCBC4[0x00];
            arg44[0x20 + 0x04] = _00BDCBC4[0x04];
            arg44[0x20 + 0x08] = _00BDCBC4[0x08];
            arg44[0x20 + 0x0C] = _00BDCBC4[0x0C];

            arg44[0x20 + 0x10 + 0x00] = _00BDCBC4[0x10 + 0x00];
            arg44[0x20 + 0x10 + 0x04] = _00BDCBC4[0x10 + 0x04];
            arg44[0x20 + 0x10 + 0x08] = _00BDCBC4[0x10 + 0x08];
            arg44[0x20 + 0x10 + 0x0C] = _00BDCBC4[0x10 + 0x0C];

            arg44[0x20 + 0x20 + 0x00] = _00BDCBC4[0x20 + 0x00];
            arg44[0x20 + 0x20 + 0x04] = _00BDCBC4[0x20 + 0x04];
            arg44[0x20 + 0x20 + 0x08] = _00BDCBC4[0x20 + 0x08];
            arg44[0x20 + 0x20 + 0x0C] = _00BDCBC4[0x20 + 0x0C];

            //copy 0x10 bytes

            arg44[0x50 + 0x00] = arg24[0x00];
            arg44[0x50 + 0x04] = arg24[0x04];
            arg44[0x50 + 0x08] = arg24[0x08];
            arg44[0x50 + 0x0C] = arg24[0x0C];

            //copy 0x43 bytes

            memcpy(arg44 + 0x60, _00BDD04C_RESPBUF1 + 0x08, 0x43);

            int res7 = sub_CAC924(0, arg44, CAC924_COMMAND_1D, 0xA3, _00BDCDF4_PACKET6_DE);
            if(res7 != 0)
            {
               return -3;
            }
            else
            {
               //how does it matter at this point? is resp buffer changed?
               //this can probably be optimized to 0 since this value is zero
               return _00BDD04C_RESPBUF1[0x0A];
            }
         }
         else
         {
            return _00BDD04C_RESPBUF1[0x0A];
         }
      }
   }
}

//copies data to arg24 buffer
//layous are: 
//0x20 = 0x20 bytes

//copies data to arg44 buffer
//layouts are:
//0x20 0x30 0x10 0x43 = 0xA3 bytes
std::pair<cycle_state, int> packet15_to_16(const sce_time& time_0, char* arg44, char* arg24, int& varC, int var2C)
{
   //================================================
      
   //packet 15
      
   sce_time time_1 = SceSblGcAuthMgr_SceThreadmgrForDriver_imp_sceKernelGetSystemTimeWideForDriver_f4ee4fa9();
      
   //copies data to arg24 buffer
   //layouts are:
   //0x20 0x30 0x10 0x43 = 0xA3 bytes
   int A0_intermediate = packet15_preinit(arg44, arg24);

   if(time_1.v1 == time_0.v1) //if highest part of time equals
   {
      //not sure if this is >= or > - this is for cmpeq r4,r2,  bcc
      //it would be strange if condition is >= since it would be always true

      if(time_1.v0 >= time_0.v0) //check the lowest part of time
      {
         varC = varC - 1; //dec counter
         if(varC == 0)
         {
            int error = exit_loc_CA91D6(0x808A0707, var2C);
            return std::make_pair(c_error, error);
         }
         return std::make_pair(c_continue, 0); // continue cycle
      }
   }

   //respose time must be > 50000 ms ?

   if((time_1.v1 - time_0.v1) == 0x0000) //highest time difference is 0
   {
      if((time_1.v0 - time_0.v0) <= 0xC350) //lowest time difference is <= 50000
      {
         varC = varC - 1; //dec counter
         if(varC == 0)
         {
            int error = exit_loc_CA91D6(0x808A0707, var2C);
            return std::make_pair(c_error, error);
         }
         return std::make_pair(c_continue, 0); // continue cycle
      }
   }

   //

   if(A0_intermediate != 0)
   {
      varC = varC - 1; //dec counter
      if(varC == 0)
      {
         int error = exit_loc_CA91D6(0x808A0707, var2C);
         return std::make_pair(c_error, error);
      }
      return std::make_pair(c_continue, 0); // continue cycle
   }

   int res7 = sub_CA8DC0(0x02, _00BDCDF4_PACKET6_DE, _00BDCFF8, _00BDCBC4, _00BDCDF8_WB20, _00BDCBF4_REQBUF); //init packet 15
   if(res7 != 0)
   {
      //no continuation here
      int error = exit_loc_CA91D6(0x808A0707, var2C);
      return std::make_pair(c_error, error);
   }

   arg24[0x00] = _00BDCBF4_REQBUF[0x2F + 0x00];
   arg24[0x04] = _00BDCBF4_REQBUF[0x2F + 0x04];
   arg24[0x08] = _00BDCBF4_REQBUF[0x2F + 0x08];
   arg24[0x0C] = _00BDCBF4_REQBUF[0x2F + 0x0C];

   arg24[0x10 + 0x00] = _00BDCBF4_REQBUF[0x2F + 0x10 + 0x10];
   arg24[0x10 + 0x04] = _00BDCBF4_REQBUF[0x2F + 0x10 + 0x14];
   arg24[0x10 + 0x08] = _00BDCBF4_REQBUF[0x2F + 0x10 + 0x18];
   arg24[0x10 + 0x0C] = _00BDCBF4_REQBUF[0x2F + 0x10 + 0x1C];

   int res8 = SceSblGcAuthMgr_SceSdifForDriver_imp_b0996641(_00BDCBC0_SD_CTX_ELM, _00BDCBF4_REQBUF, 0x200); //packet 15
   if(res8 != 0)
   {
      //no continuation here
      int error = exit_loc_CA91D6(0x808A0707, var2C);
      return std::make_pair(c_error, error);
   }

   //================================================

   //packet 16

   int res9 = SceSblGcAuthMgr_SceSdifForDriver_imp_134e06c4(_00BDCBC0_SD_CTX_ELM, _00BDD04C_RESPBUF1, 0x200, PACKET_16_INDEX); //packet 16
   if(res9 != 0)
   {
      //no continuation here
      int error = exit_loc_CA91D6(0x808A0707, var2C);
      return std::make_pair(c_error, error);
   }

   //================================================

   return std::make_pair(c_ok, 0);
}

//copies data to arg44 buffer
//layouts are:
//0x20 0x30 0x20 0x43 = 0xB3
int packet17_to_20(char* arg44, const char* arg24, int var2C)
{
   if(_00BDD04C_RESPBUF1[0x00] != 0x11)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x04] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   if(_00BDD04C_RESPBUF1[0x0A] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //copy 0x20 bytes

   arg44[0x00] = _00BDCFF8[0x00];
   arg44[0x04] = _00BDCFF8[0x04];
   arg44[0x08] = _00BDCFF8[0x08];
   arg44[0x0C] = _00BDCFF8[0x0C];

   arg44[0x10 + 0x00] = _00BDCFF8[0x10 + 0x00];
   arg44[0x10 + 0x04] = _00BDCFF8[0x10 + 0x04];
   arg44[0x10 + 0x08] = _00BDCFF8[0x10 + 0x08];
   arg44[0x10 + 0x0C] = _00BDCFF8[0x10 + 0x0C];

   //copy 0x30 bytes

   arg44[0x20 + 0x00] = _00BDCBC4[0x00];
   arg44[0x20 + 0x04] = _00BDCBC4[0x04];
   arg44[0x20 + 0x08] = _00BDCBC4[0x08];
   arg44[0x20 + 0x0C] = _00BDCBC4[0x0C];
      
   arg44[0x20 + 0x10 + 0x00] = _00BDCBC4[0x10 + 0x00];
   arg44[0x20 + 0x10 + 0x04] = _00BDCBC4[0x10 + 0x04];
   arg44[0x20 + 0x10 + 0x08] = _00BDCBC4[0x10 + 0x08];
   arg44[0x20 + 0x10 + 0x0C] = _00BDCBC4[0x10 + 0x0C];

   arg44[0x20 + 0x20 + 0x00] = _00BDCBC4[0x20 + 0x00];
   arg44[0x20 + 0x20 + 0x04] = _00BDCBC4[0x20 + 0x04];
   arg44[0x20 + 0x20 + 0x08] = _00BDCBC4[0x20 + 0x08];
   arg44[0x20 + 0x20 + 0x0C] = _00BDCBC4[0x20 + 0x0C];

   //arg44.arg94 buffer is used differently - it is 0x10 buffer, however it is overflown to 0x10 bytes to 0xA4 area
      
   //copy 0x20 bytes

   arg44[0x50 + 0x00] = arg24[0x00];
   arg44[0x50 + 0x04] = arg24[0x04];
   arg44[0x50 + 0x08] = arg24[0x08];
   arg44[0x50 + 0x0C] = arg24[0x0C];

   arg44[0x50 + 0x10 + 0x00] = arg24[0x10 + 0x00];
   arg44[0x50 + 0x10 + 0x04] = arg24[0x10 + 0x04];
   arg44[0x50 + 0x10 + 0x08] = arg24[0x10 + 0x08];
   arg44[0x50 + 0x10 + 0x0C] = arg24[0x10 + 0x0C];

   //copy 0x43 bytes

   memcpy(arg44 + 0x70, _00BDD04C_RESPBUF1 + 0x08, 0x43);

   int res8 = sub_CAC924(_00BDD44C, arg44, CAC924_COMMAND_1F, 0xB3, _00BDCDF4_PACKET6_DE);
   if(res8 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //what is the point of checking resp buffer - it was already checked - is it modified?
   if(_00BDD04C_RESPBUF1[0x0A] != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   //packet 17 packet 18 packet 19 packet 20
   int res9 = sub_CA8EA0(_00BDCBC0_SD_CTX_ELM, _00BDCDF4_PACKET6_DE, _00BDCFF8, _00BDCBC4, _00BDCDF8_WB20, _00BDCBF4_REQBUF, _00BDD04C_RESPBUF1, _00BDD24C_RESPBUF2, _00BDD018);
   if(res9 != 0)
      return exit_loc_CA91D6(0x808A0707, var2C);

   return 0;
}

//entrypoint to initialization - this function is started in separate thread by:
//SceSblGcAuthMgr_SceSblGcAuthMgrGcAuthForDriver_exp_initialize_sd_card_async_68781760
int sub_CA919C(int* argument0)
{
   //=============================

   int var2C = var_009EA004; //stack cookie

   int res1 = initialize_sd(argument0, var2C);
   if(res1 != 0)
      return res1;

   int res2 = packets1_to_6(var2C);
   if(res2 != 0)
      return res2;
   
   int res3 = packet7_to_8(var2C);
   if(res3 != 0)
      return res3;

   //=============================

   char arg24[0x20]; //is used as 0x10 buffer and as 0x20 buffer
   
   //0x20 0x10 0x20 0x3 = 0x53 bytes
   //0x20 0x20 = 0x40 bytes
   //0x20 0x30 0x10 0x43 = 0xA3 bytes
   //0x20 0x30 0x20 0x43 = 0xB3
   char generic_buffer[0xB3];

   //=============================

   //copies data to arg44 buffer
   //layous are: 
   //0x20 0x10 0x20 0x3 = 0x53 bytes
   //0x20 0x20 = 0x40 bytes
   int res4 = packet9_to_10(generic_buffer, var2C);
   if(res4 != 0)
      return res4;

   int res5 = packet11_to_12(var2C);
   if(res5 != 0)
      return res5;

   //=============================

   int varC = 0x03; //cycle counter
   
   while(true) //loc_CA95F8
   {
      // packet 13 packet 14

      sce_time time_0;

      //copies data to arg24 buffer
      //layous are: 
      //0x10 = 0x10 bytes
      std::pair<cycle_state, int> res6 = packet13_to_14(arg24, time_0, varC, var2C); 
      if(res6.first == c_continue)
         continue;
      else if(res6.first == c_error)
         return res6.second;

      // packet 15 packet 16

      //copies data to arg24 buffer
      //layous are: 
      //0x20 = 0x20 bytes

      //copies data to arg44 buffer
      //layouts are:
      //0x20 0x30 0x10 0x43 = 0xA3 bytes
      std::pair<cycle_state, int> res7 = packet15_to_16(time_0, generic_buffer, arg24, varC, var2C);
      if(res7.first == c_continue)
         continue;
      else if(res7.first == c_error)
         return res7.second;

      break;   
   }

   //=============================

   //this part can not continue so I moved it outside of cycle

   //packet 17 packet 18 packet 19 packet 20

   //copies data to arg44 buffer
   //layouts are:
   //0x20 0x30 0x20 0x43 = 0xB3
   int res8 = packet17_to_20(generic_buffer, arg24, var2C);
   if(res8 != 0)
      return res8;

   return exit_loc_CA91DA(res8, var2C);
}