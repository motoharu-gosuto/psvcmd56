#include <iostream>
#include <string>

#include "F00D/IF00DService.h"
#include "SceSblSmSchedProxyTypes.h"

int cookie_810928 = 0;

char key0_81277C[0x20] = {0xE1, 0x22, 0x13, 0xB4, 0x80, 0x16, 0xB0, 0xE9, 0x9A, 0xB8, 0x1F, 0x8E, 0xC0, 0x2A, 0xD4, 0xA2, 
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

char key1_81279C[0x20] = {0xA9, 0xFA, 0x5A, 0x62, 0x79, 0x9F, 0xCC, 0x4C, 0x72, 0x6B, 0x4E, 0x2C, 0xE3, 0x50, 0x6D, 0x38, 
                          0xF4, 0xF2, 0xD0, 0x15, 0x5D, 0xB9, 0x13, 0xCD, 0xE4, 0x52, 0xE4, 0xB5, 0x4A, 0xB7, 0x5F, 0x4A};

char key2_8127BC[0x40] = {0xB5, 0xD8, 0x51, 0x12, 0xFE, 0xDF, 0xC9, 0xFD, 0x25, 0xE7, 0xD1, 0xDB, 0x85, 0x8D, 0x76, 0xFD, 
                          0x04, 0x1A, 0xFE, 0xDB, 0x58, 0x2B, 0xEB, 0xB9, 0xA5, 0xE1, 0x67, 0xF3, 0xFD, 0xDD, 0x2E, 0x8E, 
                          0x90, 0x1A, 0x84, 0xFB, 0x13, 0xA7, 0x44, 0xA3, 0x78, 0xC5, 0x01, 0x8A, 0x60, 0xF5, 0x8C, 0x22, 
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

char key3_8127FC[0x20] = {0x61, 0x6F, 0xAD, 0xDF, 0x22, 0x04, 0xAC, 0x7A, 0x24, 0x06, 0x4C, 0xCE, 0xD8, 0xCD, 0x88, 0xA0, 
                          0xDE, 0x07, 0xF0, 0x15, 0x43, 0x45, 0x32, 0x7D, 0xBE, 0x4D, 0x49, 0xE1, 0xCA, 0x87, 0x5D, 0x98};

char key4_81281C[0x20] = {0x5E, 0xF0, 0xE4, 0xAB, 0x2A, 0xCE, 0x26, 0x69, 0x00, 0x96, 0xD9, 0x48, 0xD4, 0xC0, 0x1B, 0x36, 
                          0x8B, 0xB0, 0xB2, 0x1D, 0x45, 0x72, 0x7D, 0x70, 0x91, 0x26, 0xF4, 0xA1, 0x10, 0x77, 0x0C, 0xF9};

//some scrambling
int sub_8102BC(char* ptr, int value, int size)
{
   return 0;
}

//key_id 0x00010001 DMAC5 specific setup
int sub_80D318()
{
   return 0;
}

//maybe crypto
int sub_80E162(char* key1, int key_size, char* key2)
{
   return 0;
}

//maybe crypto
int sub_80E43E(char* key1, int key_size, char* key2, char* key3)
{
   return 0;
}

//maybe crypto
int sub_80E4CC(char* key1, int key_size, char* key2, char* key3)
{
   return 0;
}

int set_dmac5_key_80E26A(char* key, int nblocks, int slot)
{
   return 0;
}

int handle_command_0x50001_0x60001_80E568(int arg1, SceSblSmschedCallFuncCommand* request_buffer)
{
   SceSblSmschedCallFuncCommand raw_buffer;

   memcpy((char*)&raw_buffer, (char*)request_buffer, 0x150);

   SceSblSmCommKprxAuthData_50001* request = (SceSblSmCommKprxAuthData_50001*)raw_buffer.data;

   char key_dest[0x20];

   //check that size is aligned

   if((request->key_size & 0xF) != 0)
   {
      raw_buffer.response = 0x800F0016;
      return -1;
   }

   //check slot id

   if(request->slot_id < 0xC || request->slot_id > 0x17)
   {
      raw_buffer.response = 0x800F0016;
      return -1;
   }

   // do some scrambling - result lost after memcpy ?

   int reg0 = sub_8102BC(key_dest, 0, 0x20);

   //execute command

   if(raw_buffer.service_id == 0x50001)
   {
      if(request->key_size <= 0 || request->key_size > 0x20)
      {
         raw_buffer.response = 0x800F0016;
         return -1;
      }
      
      memcpy(key_dest, request->key, request->key_size);

      //execute command according to specific key id

      switch(request->key_id)
      {
      case 0x00000000:
         {
            raw_buffer.response = sub_80E162(key_dest, request->key_size, key0_81277C); //probably crypto
            if(raw_buffer.response == 0)
               raw_buffer.response = set_dmac5_key_80E26A(key_dest, request->key_size / 4, request->slot_id);
         }
         break;
      case 0x00010000:
         {
            raw_buffer.response = sub_80E162(key_dest, request->key_size, key1_81279C); //probably crypto
            if(raw_buffer.response == 0)
               raw_buffer.response = set_dmac5_key_80E26A(key_dest, request->key_size / 4, request->slot_id);
         }
         break;
      case 0x00010001:
         {
            int reg0 = sub_80D318(); // some dmac setup
            if(reg0 == 0)
            {
               raw_buffer.response = 0x800F0016;
               return -1;
            }

            raw_buffer.response = sub_80E162(key_dest, request->key_size, key2_8127BC); //probably crypto
            if(raw_buffer.response == 0)
               raw_buffer.response = set_dmac5_key_80E26A(key_dest, request->key_size / 4, request->slot_id);
         }
         break;
      case 0x00020000:
         {
            raw_buffer.response = sub_80E43E(key_dest, request->key_size, key3_8127FC, key3_8127FC + 0x10); //probably crypto
            if(raw_buffer.response == 0)
               raw_buffer.response = set_dmac5_key_80E26A(key_dest, request->key_size / 4, request->slot_id);
         }
         break;
      case 0x00020001:
         {
            raw_buffer.response = sub_80E4CC(key_dest, request->key_size, key4_81281C, key4_81281C + 0x20); //probably crypto
            if(raw_buffer.response == 0)
               raw_buffer.response = set_dmac5_key_80E26A(key_dest, request->key_size / 4, request->slot_id);
         }
         break;
      default:
         {
            raw_buffer.response = 0x800F0016;
            return -1;
         }
         break;
      }
   }
   else if(raw_buffer.service_id == 0x60001)
   {
      memset(key_dest, 0, 0x20);

      raw_buffer.response = set_dmac5_key_80E26A(key_dest, 0x20 / 4, request->slot_id);
   }
   else
   {
      raw_buffer.response = 0x800F0016;
      return -1;
   }

   return 0;
}