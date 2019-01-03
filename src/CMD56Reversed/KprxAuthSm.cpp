#include <iostream>
#include <string>

#include "F00D/IF00DService.h"
#include "SceSblSmSchedProxyTypes.h"

int cookie_810928 = 0;

char key0_81277C[1];

char key1_81279C[1];

char key2_8127BC[1];

char key3_8127FC[1];

char key4_81281C[1];

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