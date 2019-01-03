#include <iostream>
#include <string>

int cookie_810928 = 0;

char key0_81277C[1];

char key1_81279C[1];

char key2_8127BC[1];

char key3_8127FC[1];

char key4_81281C[1];

int sub_80D318()
{
   return 0;
}

int sub_8102BC(char* ptr, int value, int size)
{
   return 0;
}

int set_dmac5_key_80E26A(char* key, int nblocks, int slot)
{
   return 0;
}

int sub_80E162(char* key1, int key_size, char* key2)
{
   return 0;
}

int sub_80E43E(char*, int, char*, char*)
{
   return 0;
}

int sub_80E4CC(char*, int, char*, char*)
{
   return 0;
}

int handle_command_0x50001_0x60001_80E568(int arg1, char* request_buffer)
{
   int buffer_copy;
   int command_168;
   int return_value_164;
   int unused_160;
   int var_10_15C;
   int var_14_158;
   int var_18_154;
   int var_1C_150;
   int var_20_14C;
   int var_24_148;
   int var_28_144;
   int var_2C_140;
   int var_30_13C;
   int var_34_138;
   int var_38_134;
   int var_3C_130;
   int key_12C;
   int key_128;
   int key_124;
   int key_120;
   int key_11C;
   int key_118;
   int key_114;
   int key_110;

   int key_size_2C;
   int key_id_28;
   int slot_id_24;
   int var_20;

   char* key_dest;
   
   int reg1 = buffer_copy; //add3    $1, $sp, 0x24

   int reg3 = 0x150;
   char* reg5 = request_buffer;

   memcpy((char*)&buffer_copy, request_buffer, 0x150);

   int reg3 = key_size_2C;
   int reg2 = reg3 & 0xF;

   if(reg2 != 0)
   {
      handle_error_80E68E:

      #pragma region handle_error_80E68E

      reg3 = reg3 | 0x800F0000;
      reg3 = reg3 | 0x16;
      
      return_value_164 = reg3;
      
      //int reg2 = cookie_1C;
      //int reg3 = cookie_810928;

      //if (reg2 != reg3)
      //{
      //   sub_80B092();
      //}

      //add3    $sp, $sp, 0x178
   
      //reg6 = prev_state_10;
      //reg5 = prev_state_C;
      //reg11 = prev_state_14;

      //add     $sp, 0x18
      //jmp     $11

      #pragma endregion
   }

   int reg1 = command_168;
   int reg2 = 0x50001;

   if(reg1 == reg2)
   {
      if(reg3 == 0)
      {
         goto handle_error_80E68E;
      }
   }

   int reg3 = key_id_28; // i get the point that we check for 0x00000000, 0x00010000, 0x00010001, 0x00020000, 0x00020001
                         // but why this happens for key_id?

   if (reg3 != 0)
   {
      reg2 = reg2 | 0x10000; // reg2 low part is randomly initialized?

      if(reg3 != reg2)
      {
         reg2 = reg2 + 1;

         if(reg3 != reg2)
         {
            reg2 = reg2 | 0x20000;

            if(reg3 != reg2)
            {
               reg2 = reg2 + 1;

               if(reg3 != reg2)
               {
                  goto handle_error_80E68E;
               }
            }
         }
      }
   }

   //slot id check is relatively strange

   int reg2 = slot_id_24;
   reg2 = reg2 - 0xC;
   
   if(reg2 < 0xC) //unsigned
   {
      reg2 = 1;
   }
   else
   {
      reg2 = 0;
   }

   //allows slots 0,1,2,3,4,5,6,7,8,9,A,B and 19,1A,1B,1C,1D,1E,1F
   if(reg2 == 0)
   {
      goto handle_error_80E68E;
   }

   reg2 = 0x10001;
   
   if(reg3 == reg2) // check for key id
   {
      int reg0 = sub_80D318();
      
      if(reg0 == 0)
      {
         goto handle_error_80E68E;
      }
   }

   char* reg6 = key_dest; //add3    $6, $sp, 4      ; address of the dest buffer for key
   
   int reg0 = sub_8102BC(key_dest, 0, 0x20);

   reg3 = command_168;
   reg2 = 0x50001;

   if(command_168 != 0x50001)
   {
      if(command_168 != 0x60001)
      {
         goto handle_error_80E68E;
      }

      memset(reg6, 0, 0x20);

      return_value_164 = set_dmac5_key_80E26A(key_dest, 0x20 / 4, slot_id_24);
   }
   else
   {
      #pragma region

      int reg3 = key_size_2C;

      if(reg3 < 0x21) // >= 0x20
      {
         reg2 = 1;
      }
      else
      {
         reg2 = 0;
      }

      if(reg2 == 0)
      {
         goto handle_error_80E68E;
      }

      memcpy(reg6, (char*)&key_12C, reg3);

      int reg3 = key_id_28; // i get the point that we check for 0x00000000, 0x00010000, 0x00010001, 0x00020000, 0x00020001
                            // but why this happens for key_id?

      if(reg3 != 0)
      {
         int reg2 = reg2 | 0x10000; // reg2 low part is randomly initialized?
         
         if(reg3 != reg2)
         {
            int reg2 = 0x10001;
            
            if(reg3 != reg2)
            {
               int reg2 = reg2 | 0x20000;
               
               if(reg3 != reg2)
               {
                  int reg2 = 0x20001;
                  
                  if(reg3 !=  reg2)
                  {
                     reg3 = return_value_164; // value is not set!

                     if(reg3 == 0)
                     {
                        return_value_164 = set_dmac5_key_80E26A(key_dest, key_size_2C / 4, slot_id_24);
                     }
                  }
                  else
                  {
                     return_value_164 = sub_80E4CC(reg6, key_size_2C, key4_81281C, key4_81281C + 0x20);

                     if(return_value_164 == 0)
                     {
                        return_value_164 = set_dmac5_key_80E26A(key_dest, key_size_2C / 4, slot_id_24);
                     }
                  }
               }
               else
               {
                  return_value_164 = sub_80E43E(reg6, key_size_2C, key3_8127FC, key3_8127FC + 0x10);

                  if(return_value_164 == 0)
                  {
                     return_value_164 = set_dmac5_key_80E26A(key_dest, key_size_2C / 4, slot_id_24);
                  }
               }
            }
            else
            {
               return_value_164 = sub_80E162(reg6, key_size_2C, key2_8127BC);
            
               if(return_value_164 == 0)
               {
                  return_value_164 = set_dmac5_key_80E26A(key_dest, key_size_2C / 4, slot_id_24);
               }
            }
         }
         else
         {
            return_value_164 = sub_80E162(reg6, key_size_2C, key1_81279C);
            
            if(return_value_164 == 0)
            {
               return_value_164 = set_dmac5_key_80E26A(key_dest, key_size_2C / 4, slot_id_24);
            }
         }
      }
      else
      {
         return_value_164 = sub_80E162(reg6, key_size_2C, key0_81277C);
         
         if(return_value_164 == 0)
         {
            return_value_164 = set_dmac5_key_80E26A(key_dest, key_size_2C / 4, slot_id_24);
         }
      }

      #pragma endregion
   }

   return 0;
}