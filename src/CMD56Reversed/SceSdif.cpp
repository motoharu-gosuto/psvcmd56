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
#include "SceCpu.h"
#include "SceThreadmgr.h"
#include "SceKernelSuspend.h"

//get context from array
sd_context_part_mmc* SceSdifForDriver_get_sd_context_part_validate_mmc_6a71987f(int sd_ctx_index)
{
   return (sd_context_part_mmc*)var_00C78040[sd_ctx_index].ctx_data.ctx;
}

//initialize sd card
int SceSdifForDriver_initialize_mmc_device_22c82e79(int sd_ctx_index, sd_context_part_mmc** result)
{
   return 0;
}

//CMD56_REQUEST
int SceSdifForDriver_gc_cmd56_request_b0996641(sd_context_part_mmc* ctx, char* buffer, int length)
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
int SceSdifForDriver_gc_cmd56_response_134e06c4(sd_context_part_mmc* ctx, char* buffer, int length, int index)
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

int callback_interrupt_handler_DC_DD_DE_C68FF8(int unk, void* userCtx)
{
   return 0;
}

int callback_suspend_eMMC_C6875C(int resume, int eventid, suspend_args_t *args, void *opt)
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

void proc_set_zero_pair_C6AED8(uint32_t* data)
{
   data[0] = 0;
   data[1] = 0;
}

void sub_C6AEE0(sd_context_data* r0, cmd_input* r1)
{
   cmd_input* r3 = r0->cmd_ptr_next;
   r1->next_cmd = 0;
   if(r3 == 0)
   {
      r0->cmd_ptr = r1;
      r0->cmd_ptr_next = r1;
   }
   else
   {
      r3->next_cmd = r1;
      r0->cmd_ptr_next = r1;
   }
}

//init related
void sub_C68598(sd_context_global* ctx, int unk1)
{
   /*
   //some important code

   sd_context_data* r5 = ctx->ctx_data;
   int r0 = unk1 << 0x1F; //31
   int r7 = unk1;

   int r4 = r5->membase_1000;

   if(r0 >= 0)
   {
      //goto loc_C685DE
   }
   else
   {
      int r8 = 0x1FF;
      int r8 = r8 << 8;
      SceSdif.ScePervasiveForDriver._imp_714eefb7();

      int r8 = r0 & r8;
      int r6 = r5->array_idx;

      if(r8 != 0)
      {
         if(r8 == 0x100)
         {
            SceSdif.SceSysconForDriver._imp_cbd6d8bc();

            int r0 = r0 & 0xFF0000;
            if(r0 < 0x800000) //BCC
            {
               if(r6 == 0)
               {
                  int r0 = r6;
                  int r1 = 4;
                  SceSdif.ScePervasiveForDriver._imp_043b33f5();
                  //goto loc_C6865A
               }
               else
               {
                  int r3 = r6 - 1;
                  if(r3 > 1)
                  {
                     int r0 = r6;
                     SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                     //goto loc_C6867A
                  }
                  else
                  {
                     int r0 = r6;
                     int r1 = 2;
                     SceSdif.ScePervasiveForDriver._imp_043b33f5();
                     
                     int r0 = r6;
                     SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                     //goto loc_C6867A
                  }
               }
            }
            else
            {
               if(r6 == 0)
               {
                  int r0 = r6;
                  int r1 = 5;
                  SceSdif.ScePervasiveForDriver._imp_043b33f5();
                  //goto loc_C6865A
               }
               else
               {
                  if(r6 == 1)
                  {
                     SceSdif.SceSysrootForDriver._imp_7b7f8171();
                     if(r0 == 0)
                     {
                        int r0 = r6;
                        int r1 = 3;
                        SceSdif.ScePervasiveForDriver._imp_043b33f5();
                        
                        int r0 = r6;
                        SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                        //goto loc_C6867A
                     }
                     else
                     {
                        int r0 = r6;
                        int r1 = 6;
                        SceSdif.ScePervasiveForDriver._imp_043b33f5();
                        
                        int r0 = r6;
                        SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                        //goto loc_C6867A
                     }
                  }
                  else
                  {
                     if(r6 != 2)
                     {
                        int r0 = r6;
                        SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                        //goto loc_C6867A
                     }
                     else
                     {
                        int r0 = r6;
                        int r1 = 3;
                        SceSdif.ScePervasiveForDriver._imp_043b33f5();
                        
                        int r0 = r6;
                        SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                        //goto loc_C6867A
                     }
                  }
               }
            }
         }
         else
         {
            if(r6 != 0)
            {
               int r0 = r6;
               SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
               //goto loc_C6867A
            }
            else
            {
               //goto loc_C6865A
            }
         }
      }
      else
      {
         SceSdif.SceSblAIMgrForDriver._imp_c6e83f34();
         if(r0 == 0)
         {
            if(r6 <= 1)
            {
               int r0 = r6;
               int r1 = 0x200;
               SceSdif.ScePervasiveForDriver._imp_9f8e589c();

               if(r6 != 0)
               {
                  int r0 = r6;
                  SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
                  //goto loc_C6867A
               }
               else
               {
                  //goto loc_C6865A
               }
            }
            else
            {
               int r0 = r6;
               SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
               //goto loc_C6867A
            }
         }
         else
         {
            if(r6 != 0)
            {
               int r1 = r8;
               int r0 = r6;
               SceSdif.ScePervasiveForDriver._imp_9f8e589c();
               
               int r0 = r6;
               SceSdif.ScePervasiveForDriver._imp_3d8a8712();
                     
               //goto loc_C6867A
            }
            else
            {
               int r0 = r6;
               int r1 = 0x200;
               SceSdif.ScePervasiveForDriver._imp_9f8e589c();
               
               //goto loc_C6865A
            }
         }
      }
   }

   //loc_C6865A:
   {
      int r3 = 0xC78008;
      int r3 = r3[0];

      if(r3 == 1)
      {
         int r1 = dword_C72CB0;
         int r2 = "Skip sdif port[%d] reset\n";
         int r3 = 0;
         int r0 = 0xF;
         SceSdif.SceDebugForDriver._imp_print_02b04343();

         //goto loc_C6867A
      }
      else
      {
         int r0 = 0;
         SceSdif.ScePervasiveForDriver._imp_3d8a8712();
         int r1 = 0;
         int r0 = 3;
         int r2 = r1;
         int r3 = r1;
         SceSdif.SceSblSmSchedProxyForKernel._imp_7894b6f0();
         
         //goto loc_C6867A
      }
   }

   //loc_C6867A:
   {
      int r0 = r6;
      SceSdif.ScePervasiveForDriver._imp_d326e15f();

      int r0 = r6;
      SceSdif.ScePervasiveForDriver._imp_3cf7a012();

      int r3 = 0xE;

      int r5[0x38] = r3;

      if(r6 == 3)
      {
      }
      else
      {
      }
   }
   */
}

//------------------------

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
      sd_context_global* r5 = &var_00C78040[0]; // 00C78040 + 0x2400 + 0x44 = 00C7A484;
      int r4 = 0;

      while(true)
      {
         int r7 = r5->ctx_data.array_idx; //[R5,#-0x24]
         int r4 = r4 + 1;

         //TODO: do not really get what this means
         char* r3 = ((char*)&var_00C81260) + 0x40;
         PLD(r3) ; //PLD.W [R3] //preload, caching

         SceIntrmgrForDriver_180435ec(INTR_CODE_SceSdif0 + r7); //calculate intr code

         SceIntrmgrForDriver_d6009b98(INTR_CODE_SceSdif0 + r7); //calculate intr code

         SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(r5->ctx_data.evid); // R0, [R5,#-4]

         SceThreadmgrForDriver_11fe84a1(&r5->ctx_data.sdif_fast_mutex);

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

int exit_loc_C68ADC(int r6, int r11, int cookie_2C, sd_context_global* ctx_B0)
{
   int r8 = r11;
   SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(ctx_B0->ctx_data.uid_1000);
   return exit_loc_C68AEA(r6, r8, cookie_2C);
}

int exit_loc_C68B4E(int r3, int r6, int cookie_2C, sd_context_global* ctx_B0)
{
   return exit_loc_C68ADC(r6, r3, cookie_2C, ctx_B0);
}

int exit_loc_C68AD0(int r6, int r11, int cookie_2C, sd_context_global* ctx_B0)
{
   SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(ctx_B0->ctx_data.uid_10000);
   return exit_loc_C68ADC(r6, r11, cookie_2C, ctx_B0);
}

int exit_loc_C68B52(int r3, int r6, int cookie_2C, sd_context_global* ctx_B0)
{
   return exit_loc_C68AD0(r6, r3, cookie_2C, ctx_B0);
}

int exit_loc_C68ACA(uint32_t* r4, int r6, int r11, int cookie_2C, sd_context_global* ctx_B0)
{
   SceThreadmgrForDriver_11fe84a1(r4);
   return exit_loc_C68AD0(r6, r11, cookie_2C, ctx_B0);
}

int exit_loc_C68BA8(int r0, int r6, uint32_t* r11, int cookie_2C, sd_context_global* ctx_B0)
{
   return exit_loc_C68ACA(r11, r6, r0, cookie_2C, ctx_B0);
}     

int exit_loc_C68ABE(uint32_t* r4, int r6, int r11, int cookie_2C, sd_context_global* ctx_B0)
{
   SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(ctx_B0->ctx_data.evid);
   return exit_loc_C68ACA(r4, r6, r11, cookie_2C, ctx_B0);
}

int exit_loc_C68BAE(int r3, int r6, uint32_t* r11, int cookie_2C, sd_context_global* ctx_B0)
{
   return exit_loc_C68ABE(r11, r6, r3, cookie_2C, ctx_B0);
}

int exit_loc_C68AB4(int r0, int r6, uint32_t* r11, int cookie_2C, sd_context_global* ctx_B0, int code_A8)
{
   SceIntrmgrForDriver_d6009b98(code_A8);
   return exit_loc_C68ABE(r11, r6, r0, cookie_2C, ctx_B0);
}

int SceSdifForDriver_init_0eb0ef86()
{
   init_intr_opts();
   
   int var_2C = var_009EA004; //cookie

   // clear contexts

   memset(&var_00C78040[0], 0, sizeof(sd_context_global) * 3); // clear 0x6E40 = 24C0 * 3

   // cycle preinit

   sd_context_global* ctx_B0 = &var_00C78040[0];
   var_00C78000.max_array_index = 3;
   int main_ctr = 0; //counter r6

   //---------

   //loc_C68942:
   while(true)
   {
      ctx_B0->ctx_data.array_idx = main_ctr; // r4[-0x74] ; store current index

      char* currName = var_00C72CA0[main_ctr];

      SceKernelAllocMemBlockKernelOpt mem_opt;

      memset(&mem_opt, 0, sizeof(SceKernelAllocMemBlockKernelOpt));

      int alloc_size = (main_ctr <= 3) ? 0x1000 : 0;
      void** paddr_ptr = (main_ctr <= 3) ? &var_00C72C90[0] : 0; //pointer to array of physical addresses
   
      mem_opt.size = sizeof(SceKernelAllocMemBlockKernelOpt); //0x58
      mem_opt.paddr = (main_ctr <= 3) ? (SceUInt32)paddr_ptr[main_ctr] : (SceUInt32)0; //get current paddr and set it
      mem_opt.attr = 2; //set attr
      SceUID uid1 = SceSysmemForDriver_ksceKernelAllocMemBlock_c94850c9(currName, 0x201000806, alloc_size, &mem_opt);
      if(uid1 < 0)
         return exit_loc_C68B4A(uid1, main_ctr, var_2C);

      ctx_B0->ctx_data.uid_1000 = uid1; //[R4,#-0x58]

      SceSysmemForDriver_ksceKernelGetMemBlockBase_a841edda(uid1, &ctx_B0->ctx_data.membase_1000); // [R4,#-0x64]

      memset(&mem_opt, 0, sizeof(SceKernelAllocMemBlockKernelOpt));
      
      mem_opt.size = sizeof(SceKernelAllocMemBlockKernelOpt); //0x58
      mem_opt.attr = 0x200000;

      SceUID uid2 = SceSysmemForDriver_ksceKernelAllocMemBlock_c94850c9(currName, SCE_KERNEL_MEMBLOCK_TYPE_KERNEL_RW, 0x10000, &mem_opt);
      if(uid2 < 0)
         return exit_loc_C68B4E(uid2, main_ctr, var_2C, ctx_B0);

      ctx_B0->ctx_data.uid_10000 = uid2; // [R4,#-0x10]
   
      SceSysmemForDriver_ksceKernelGetMemBlockBase_a841edda(uid2, &ctx_B0->ctx_data.membase_10000);

      int res0 = SceThreadmgrForDriver_af8e1266(&ctx_B0->ctx_data.sdif_fast_mutex, currName, 2, 0);

      if(res0 < 0)
         return exit_loc_C68B52(res0, main_ctr, var_2C, ctx_B0);

      int evid = SceThreadmgrForDriver_ksceKernelCreateEventFlag_4336baa4(currName, 0, 0, 0);
      ctx_B0->ctx_data.evid = evid; // [R4,#-0x54]
   
      if(evid < 0)
         return exit_loc_C68BA8(evid, main_ctr, &ctx_B0->ctx_data.sdif_fast_mutex, var_2C, ctx_B0);

      int intrCode = ctx_B0->ctx_data.array_idx + INTR_CODE_SceSdif0; //[R4,#-0x74]
   
      int res1 = SceIntrmgrForDriver_register_interrupt_5c1feb29(intrCode, currName, 0, callback_interrupt_handler_DC_DD_DE_C68FF8, ctx_B0, 0x80, 0xF, &intr_opt_C72FA8);
      if(res1 < 0)
         return exit_loc_C68BAE(res1, main_ctr, &ctx_B0->ctx_data.sdif_fast_mutex, var_2C, ctx_B0);

      sd_context_data* r8 = &ctx_B0->ctx_data;
   
      ctx_B0->ctx_data.cmd_ptr = 0;
      ctx_B0->ctx_data.cmd_ptr_next = 0;
      ctx_B0->ctx_data.unk_8 = 0;
      ctx_B0->ctx_data.unk_C = 0;

      int cmd_ctr = 0;
      cmd_input* r9 = ctx_B0->commands;

      //initialize commands

      //loc_C68A9C:
      while(true)
      {
         r9->unk_64 = 0;
         r9->array_index = cmd_ctr;

         PLD(r9 + 0x724); // (0x240 * 3) + 0x64

         //TODO: I do not quite get where from do the virtual addresses come, should not they be zeroes ?

         int res2 = SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(r9->vaddr_1C0, &r9->paddr_1A8);
         if(res2 < 0)
            return exit_loc_C68AB4(res2, main_ctr, &ctx_B0->ctx_data.sdif_fast_mutex, var_2C, ctx_B0, intrCode);

         int res3 = SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(r9->vaddr_200, &r9->paddr_1AC);
         if(res3 < 0)
            return exit_loc_C68AB4(res3, main_ctr, &ctx_B0->ctx_data.sdif_fast_mutex, var_2C, ctx_B0, intrCode);

         int res4 = SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(r9->vaddr_80, &r9->paddr_184);
         if(res4 < 0)
            return exit_loc_C68AB4(res4, main_ctr, &ctx_B0->ctx_data.sdif_fast_mutex, var_2C, ctx_B0, intrCode);

         cmd_ctr = cmd_ctr + 1;
         r9 = r9 + sizeof(cmd_input); // size of cmd input

         sub_C6AEE0(r8, r9);

         if(cmd_ctr == 0x10)
            break;
      }

      main_ctr = main_ctr + 1;

      int prev_state = SceCpuForDriver_ksceKernelCpuSuspendIntr_d32ace9e(&ctx_B0->ctx_data.lockable_int);

      sub_C68598(ctx_B0, 3);

      SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df(&ctx_B0->ctx_data.lockable_int, prev_state);

      SceIntrmgrForDriver_7117e827(intrCode);

      ctx_B0 = ctx_B0 + sizeof(sd_context_global); //0x24C0

      if(var_00C78000.max_array_index > main_ctr)
         break;
   }

   SceUID suid = suspend_register_callback_04c05d10("SceSdif", &callback_suspend_eMMC_C6875C, 0);
   var_00C78000.suspend_callback_id = suid;

   return exit_loc_C68B38(0, var_2C);
}

int SceSdif_module_start_935cd196()
{
   int res = SceSdifForDriver_init_0eb0ef86();
   return (res >> 0x1F); //31
}

//--------------------------------------------------

int SceCpuForDriver_sceKernelCpuDcacheAndDMAInvalidate_02796361(void *ptr, size_t len)
{
   return 0;
}

int physical_send_command_C6812C(sd_context_global* ctx, cmd_input* cmd_data1)
{
   return 0;
}

int cycle_command_buffer_C6AEE0(void* gctx_2408, cmd_input* cmd_data1)
{
   return 0;
}

int sub_C696B8(cmd_input* cmd)
{
   return 0;
}

int proc_invalidate_and_copy_C7246C(cmd_input* cmd)
{
   if((cmd->state_flags << 0x15) < 0)
   {
      if(cmd->vaddr_100 != cmd->vaddr_80)
      {
         if((cmd->state_flags << 0xB) < 0)
         {
            SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(cmd->mem_188);
         }
      }
   }

   if(cmd->unk_64 != 3)
      return 0;
   
   if(((0x801 << 9) & cmd->state_flags) != 0)
      return 0;

   if(cmd->size_1A0 != 0)
   {
      SceCpuForDriver_sceKernelCpuDcacheAndDMAInvalidate_02796361(cmd->vaddr_1C0, 0x40);
      memcpy(cmd->buffer, cmd->vaddr_1C0, cmd->size_1A0);
   }

   if(cmd->size_1A4 != 0)
   {
      SceCpuForDriver_sceKernelCpuDcacheAndDMAInvalidate_02796361(cmd->vaddr_200, 0x40);
      memcpy(((char*)cmd->base_198 + cmd->offset_19C), cmd->vaddr_200, cmd->size_1A4);
   }

   if(cmd->unk_64 != 3)
      return 0;

   if(((0x801 << 9) & cmd->state_flags) != 0)
      return 0;

   if(cmd->offset_19C == 0)
      return 0;

   SceCpuForDriver_sceKernelCpuDcacheAndDMAInvalidate_02796361(cmd->base_198, cmd->offset_19C);

   return 0;
}

int proc_send_sd_command_C697E8(sd_context_global* ctx, cmd_input* cmd_data1, cmd_input* cmd_data2, int nIter, int numArg)
{
   void* buffer1 = cmd_data1->buffer; //0x20
   int cmd1_state_flags = cmd_data1->state_flags; //0x4

   void* buffer2 = (cmd_data2 == 0) ? 0 : cmd_data2->buffer; //0x20
   int cmd2_state_flags = (cmd_data2 == 0) ? 0 : cmd_data2->state_flags; // 0x4

   int retry = nIter;

   sd_context_global* ctx_glob = ctx;

   //---

   int cycle_result; //r3

   while(true)
   {
      int r11 = SceCpuForDriver_ksceKernelCpuSuspendIntr_d32ace9e(&(ctx_glob->ctx_data.lockable_int));
      int flag_shift = (((char*)ctx_glob->ctx_data.membase_1000)[0x29]) << 0x1F;

      if(flag_shift < 0)
      {
         if(numArg != 0)
         {
            if(ctx_glob->ctx_data.dev_type_idx == 0) //0x10
            {
               SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df(&(ctx_glob->ctx_data.lockable_int), r11);
               cycle_result = 0x8032001A;
               break;
            }  
         }
      }
      else
      {
         if(numArg != 0)
         {
            SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df(&(ctx_glob->ctx_data.lockable_int), r11);
            cycle_result = 0x8032001A;
            break;
         }
      }

      if(ctx_glob->ctx_data.cmd_28 == 0) //0x28
      {
         cycle_result = physical_send_command_C6812C(ctx_glob, cmd_data1);
         
         SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df(&(ctx_glob->ctx_data.lockable_int), r11);

         if(cycle_result != 0)
            break;
      }
      else
      {
         void* gctx_2408 = (void*)(&ctx_glob->ctx_data + 8);
         cycle_command_buffer_C6AEE0(gctx_2408, cmd_data1);

         cmd_data1->unk_64 = 1; //0x64

         SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df(&(ctx_glob->ctx_data.lockable_int), r11);
      }

      cmd_input* cmd_arg = cmd_data1->secondary_cmd; // 0x74
      if(cmd_arg == 0)
         cmd_arg = cmd_data1;

      cycle_result = sub_C696B8(cmd_arg);

      if(cycle_result >= 0)
         break;

      if(cycle_result == 0x8032001A)
         break;

      cmd_data1->buffer = buffer1; // 0x20
      cmd_data1->state_flags = cmd1_state_flags; // 0x4
         
      if(cmd_data2 != 0)
      {
         cmd_data2->buffer = buffer2; // 0x20
         cmd_data2->state_flags = cmd2_state_flags; //0x4
      }
      
      retry = retry - 1;

      if(retry <= 0)
         break;
   }

   //--

   if(ctx_glob->ctx_data.unk_25 == 0) //0x25
      SceThreadmgrForDriver_db395782(&ctx_glob->ctx_data.sdif_fast_mutex); //sceKernelUnlockFastMutexForDriver

   if(cmd_data2 != 0)
   {
      int flag_shift2 = (cmd_data2->state_flags << 0x15);
      if(flag_shift2 < 0)
         proc_invalidate_and_copy_C7246C(cmd_data2);
   }

   int flag_shift3 = (cmd_data1->state_flags) << 0x15;
   if(flag_shift3 < 0)
      proc_invalidate_and_copy_C7246C(cmd_data1);

   return cycle_result;
}