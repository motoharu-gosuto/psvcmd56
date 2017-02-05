#include <string>
#include <stdint.h>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

#include "Constants.h"
#include "SceSysmemGlobalVariables.h"

#include "SceSdif.h"
#include "SceSdifGlobalVariables.h"
#include "SceSdifGlobalConstants.h"

#include "SceSdifResponsePackets.h"

#include "SceSysmem.h"
#include "SceThreadmgr.h"

//get context from array
sd_context_part* SceSdifForDriver_get_sd_context_part_validate_mmc_6a71987f(int sd_ctx_index)
{
   return var_00C78040[sd_ctx_index].ctx_data.ctx;
}

//initialize sd card
int SceSdifForDriver_initialize_mmc_device_22c82e79(int sd_ctx_index, sd_context_part** result)
{
   return 0;
}

//CMD56_REQUEST
int SceSdifForDriver_gc_cmd56_request_b0996641(sd_context_part* ctx, char* buffer, int length)
{
   //TODO:
   //here will just print to console - this would be useful for observation

   int32_t maxSize = 0x50; //only print part of the packet, ommit zeroes

   std::cout << "packet:";

   for(int32_t i = 0; i < maxSize; i++)
   {
      if((i % 0x10) == 0)
         std::cout << std::endl;
      std::cout << std::hex << std::setfill('0')  << std::setw(2) << (((int)buffer[i]) & 0xFF) << " ";
   }

   std::cout << std::endl;

   return 0;
}

//originally this method had 3 arguments
//I added one more called index to emulate returning of different packets
//CMD56_RESPONSE
int SceSdifForDriver_gc_cmd56_response_134e06c4(sd_context_part* ctx, char* buffer, int length, int index)
{
   memset(buffer, 0, length);

   switch(index)
   {
   case PACKET_2_INDEX:
      memcpy(buffer, response2, sizeof(response2));
      return 0;
   case PACKET_4_INDEX:
      memcpy(buffer, response4, sizeof(response4));
      return 0;
   case PACKET_6_INDEX:
      memcpy(buffer, response6, sizeof(response6));
      return 0;
   case PACKET_8_INDEX:
      memcpy(buffer, response8, sizeof(response8));
      return 0;
   case PACKET_10_INDEX:
      memcpy(buffer, response10, sizeof(response10));
      return 0;
   case PACKET_12_INDEX:
      memcpy(buffer, response12, sizeof(response12));
      return 0;
   case PACKET_14_INDEX:
      memcpy(buffer, response14, sizeof(response14));
      return 0;
   case PACKET_16_INDEX:
      memcpy(buffer, response16, sizeof(response16));
      return 0;
   case PACKET_18_INDEX:
      memcpy(buffer, response18, sizeof(response18));
      return 0;
   case PACKET_20_INDEX:
      memcpy(buffer, response20, sizeof(response20));
      return 0;
   }

   return STACK_CHECK_FAIL;
}

int callback_00C680A9(int code, int unk)
{
   return 0;
}

int callback_00C68001(int code, int unk)
{
   return 0;
}

void init_intr_opts()
{
   intr_opt_C72FA8.size = 0x14;
   intr_opt_C72FA8.num = 9;
   intr_opt_C72FA8.opt2 = &intr_opt2_00C72F50;
   intr_opt_C72FA8.unk_C = 0;
   intr_opt_C72FA8.unk_10 = 0;

   intr_opt2_00C72F50.size = 0x28;
   intr_opt2_00C72F50.unk_4 = 0;
   intr_opt2_00C72F50.unk_8 = 0;
   intr_opt2_00C72F50.unk_C = 0;

   intr_opt2_00C72F50.fptr0 = &callback_00C680A9;
   intr_opt2_00C72F50.fptr1 = &callback_00C68001;
   intr_opt2_00C72F50.fptr2 = &callback_00C680A9;

   intr_opt2_00C72F50.unk_1C = 0;
   intr_opt2_00C72F50.unk_20 = 0;
   intr_opt2_00C72F50.unk_24 = 0;
}

void init_constants()
{
   var_00C72C90[0] = PADDR_SceSdif0_00C72C90;
   var_00C72C90[1] = PADDR_SceSdif1_00C72C94;
   var_00C72C90[2] = PADDR_SceSdif2_00C72C98;
   var_00C72C90[3] = PADDR_SceSdif3_00C72C9C;

   var_00C72CA0[0] = aScesdif0_00C72F78;
   var_00C72CA0[1] = aScesdif1_00C72F84;
   var_00C72CA0[2] = aScesdif2_00C72F90;
   var_00C72CA0[3] = aScesdif3_00C72F9C;
}

int exit_loc_C68B38(int r8, int cookie_2C)
{
   if(cookie_2C == var_009EA004)
      return r8;
   else
      return STACK_CHECK_FAIL;
}

int exit_loc_C68AEA(int r6, int r8, int cookie_2C)
{
   if(r6 == 0)
   {
      return exit_loc_C68B38(r8, cookie_2C);
   }
   else
   {
      //loc_C68AF6;

      sd_context_global* r5 = &var_00C78040[0]; //(char*)(&var_00C78040[0]) + 0x2400 + 0x44 ; // 00C78040 + 0x2400 + 0x44 = 00C7A484;
      int r4 = 0;

      while(true)
      {
         int r7 = r5->ctx_data.array_idx; //[R5,#-0x24]
         int r4 = r4 + 1;

         char* r3 = ((char*)&var_00C81260) + 0x40;
         PLD(r3) ; //PLD.W [R3] //preload, caching

         SceIntrmgrForDriver_180435ec(INTR_CODE_SceSdif0 + r7); //calculate intr code

         SceIntrmgrForDriver_d6009b98(INTR_CODE_SceSdif0 + r7); //calculate intr code

         SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(r5->ctx_data.evid_40); // R0, [R5,#-4]

         SceThreadmgrForDriver_11fe84a1(&r5->ctx_data.unk_44);

         SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(r5->ctx_data.uid_10000); //[R5,#0x40]

         SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(r5->ctx_data.uid_1000); //[R5,#-8]

         r5 = r5 + 1; //R5, R5, #0x24C0

         if(r4 == r6)
            break;
      }

      return exit_loc_C68B38(r8, cookie_2C);
   }
}     

int exit_loc_C68B4A(int r3, int r6, int cookie_2C)
{
   return exit_loc_C68AEA(r6, r3, cookie_2C);
}

int SceSdifForDriver_init_0eb0ef86()
{
   init_intr_opts();
   
   int* var_A0;
   reg_intr_opt* var_A4;
   void** var_AC;
   sd_context_global* ctx_B0;
   uint32_t* var_9C;
   SceKernelAllocMemBlockKernelOpt opt_ptr_84;
   

   int var_2C = var_009EA004; //cookie

   //---------

   var_A0 = &var_009EA004;
   var_AC = &var_00C72C90[0];
   var_A4 = &intr_opt_C72FA8;
   var_9C = &var_00C78000.max_array_index;

   memset(&var_00C78040[0], 0, sizeof(sd_context_global) * 3); // clear 0x6E40 = 24C0 * 3

   //---------

   char* r4 = (char*)(&var_00C78040[0]) + 0x2480 + 0x14 ; // var_00C78040 + 0x2480 + 0x14 = C7A4D4
   char** r10 = &var_00C72CA0[0]; //pointer to array of names
   sd_context_global* curr_gc = &var_00C78040[0]; // r4 - 0x2480 - 0x14;

   var_00C78000.max_array_index = 3;
   int r6 = 0; //counter

   //---------

   //loc_C68942: - beginning of cycle

   char* r8 = (*r10)++; //this is a bit different in original code (preincrement and not post increment)
   ctx_B0 = curr_gc; // store current context global

   curr_gc->ctx_data.array_idx = r6; // r4[-0x74] ; store current index
   
   //--------

   memset(&opt_ptr_84, 0, sizeof(SceKernelAllocMemBlockKernelOpt));
   opt_ptr_84.size = sizeof(SceKernelAllocMemBlockKernelOpt); //0x58

   int r2 = (r6 <= 3) ? 0x1000 : 0;
   
   void** r7 = (r6 <= 3) ? var_AC : 0; //pointer to array of physical addresses
   
   opt_ptr_84.paddr = (r6 <= 3) ? (SceUInt32)r7[r6] : (SceUInt32)0; //get current paddr and set it
   opt_ptr_84.attr = 2; //set attr
   int r0 = SceSysmemForDriver_ksceKernelAllocMemBlock_c94850c9(r8, 0x201000806, r2, &opt_ptr_84);
   int r3 = r0 - 0;

   if(r3 < 0)
      return exit_loc_C68B4A(r3, r6, var_2C);

   int r9 = 2;

   return 0;
}

int SceSdif_module_start_935cd196()
{
   int res = SceSdifForDriver_init_0eb0ef86();
   return (res >> 0x1F); //31
}