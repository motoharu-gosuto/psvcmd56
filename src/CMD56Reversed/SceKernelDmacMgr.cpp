#include <string>

#include "GlobalVariables.h"
#include "Constants.h"
#include "Errors.h"

#include "SceKernelDmacMgr.h"
#include "SceKernelDmacMgrGlobalConstants.h"
#include "SceKernelDmacMgrGlobalVariables.h"

#include "SceIntrmgr.h"
#include "SceSysmem.h"
#include "SceSysmemGlobalVariables.h"
#include "SceKernelDmacMgr.h"
#include "SceThreadmgr.h"
#include "SceCpu.h"

//==========================================================================

dmac_id SceDmacmgrForDriver_7cd5088a(const char* efName)
{
   /*
   int ctx = SceIntrmgrForDriver_getCurrentCpuUnkData_182ee3e3();
   if(ctx != 0)
      return SCE_KERNEL_ERROR_ILLEGAL_CONTEXT;

   result_c8672a3d* r4 = SceSysmemForKernel_functor_c8672a3d(g_008FE000.unk_20);
   
   if(r4 == 0)
      return SCE_KERNEL_ERROR_NO_MEMORY;

   memset(r4, 0x00, 0x30); //set first 12 fields to 0

   r4->gxor_30 = SCE_DMAC_GXOR(g_008FE000);

   const char* eventFlagName = (efName == 0) ? unk_994808 : efName;

   SceUID eventFlagUid = SceThreadmgrForDriver_ksceKernelCreateEventFlag_4336baa4(eventFlagName, 0x00, 0x00, 0x00);
   if(eventFlagUid < 0)
   {
      SceSysmemForKernel_functor_571660aa(g_008FE000.unk_20, r4);
      return eventFlagUid;
   }

   r4->eventFlagUid_34 = eventFlagUid;
   r4->unk_3C = SceSysmemForDriver_udiv_e655852f(eventFlagUid);
   r4->unk_38 = 0x01;
   
   return SCE_DMAC_PACK_ID(r4);
   */

   return 0;
}

//==========================================================================

int exit_loc_992EAC(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_ALREADY_QUEUED;
   return r0_ret;
}

//default case
int exit_loc_992EC2(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   return r0_ret;
}

int exit_loc_992ED6(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_NOT_UNDER_CONTROL;
   return r0_ret;
}

int exit_loc_992EE8(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_NOT_INITIALIZED;
   return r0_ret;
}

int exit_loc_992EFA(int r2, int* r6)
{
   int* r0 = r6;
   int r1 = r2;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = SCE_KERNEL_ERROR_CANCELING;
   return r0_ret;
}

int SceDmacmgrForDriver_fce4171a(dmac_id unk0, int unk1, int unk2)
{
   /*
   int r0 = r0 >> 1;
   int r5 = _008FE000;
   int r4 = r0 << 2;
   int r0 = r5 | 1;
   int r3 = r4[0x30]
   //SUB		SP, SP,	#0xC

   int r10 = r1;
   int r11 = r2;

   if(r3 != r0)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   int r6 = r4 + 0x2C;
   int r0 = r6;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
   int r3 = r4[0x38];
   int r2 = r0;
   int r0 = r3 << 0x1F;
   if(true) //BPL
      return exit_loc_992EE8();

   int r3 = r4[0x38];
   int r1 = r3 << 0x1C;
   if(true) //BMI
      return exit_loc_992EAC();

   int r3 = r4[0x14];
   if(r3 != 0)
      return exit_loc_992EAC();

   int r3 = r4[0x38];
   int r3 = r3 << 0x19;
   if(true) //BMI
      return exit_loc_992EFA();

   int r3 = r10 - 0x10;
   if(r3 > 0x04)
      return exit_loc_992EC2();

   //this are not exactly switch constants - just imitation for now
   switch(r3)
   {
   case 20: // loc_992E32
      {
         int r3 = r5[0x18];
         if(r3 == 0)
            return exit_loc_992EC2();

         int r3 = var2C;
         int r3 = &_008FE278;
         int r7 = r3;
         var2C = r3;
         r4[0x10] = r3;
      }
      break;
   case 0: //loc_992E6C
      {
         int r9 = &_008FE02C;
         r4[0x10] = r9;
         int r7 = r9;
      }
   case 0: //loc_992E7C
      {
         int r8 = &_008FE060;
         r4[0x10] = r4;
         int r7 = r8;
      }
      break;
   case 18: //loc_992E8C
      {
         if(r11 > 0x0F)
            return exit_loc_992EC2();
         //RSB.W		R11, R11, R11,LSL#3
         int r7 = r5 + (r1 << 2);
         int r7 = r7 + 0x94;
         r4[0x10] = r7;
      }
      break;
   case 0: //loc_992E48
      {
         int r7 = _008FE254;
         r4[0x10] = 74;
      }
      break;
   }
  
	int r3 = r7[0x10];
   if(r3 == 0)
      return exit_loc_992ED6();

   int r5 = r4[0x38];
   int r3 = 0xFFDF;
   int r0 = r6;
   r4[0x3A] = r10;
   int r1 = r2;
   int r3 = r3 & r5;
   r4[0x34] = r3;
   int r0 = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0 = 0;

   return r0;
   */

   return 0;
}

//========================================

result_c8672a3d* sub_99214C()
{
   /*
   while(true)
   {     
      if(g_008FE000.unk_28 == 0)
      {
         result_c8672a3d* res_0 = SceSysmemForKernel_functor_c8672a3d(g_008FE000.unk_20);
         if(res_0 == 0)
            return 0;

         //TODO: I do not understand first argument - it is void**
         SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(&res_0->unk_20, &res_0->unk_10);

         res_0->unk_14 = 0x00;
         res_0->unk_10 = (res_0->unk_10 | 1);

         return res_0;
      }
      else
      {
         //this code looks like going through list elements

         result_c8672a3d** r0 = &g_008FE000.unk_28;
         result_c8672a3d*  r1 = g_008FE000.unk_28;
         result_c8672a3d*  r2 = g_008FE000.unk_28->unk_00;

         result_c8672a3d* res_0 = SceCpuForDriver_atomic_set_xor_cda96e81(r0, r1, r2);
         if(g_008FE000.unk_28 == res_0)
            return res_0;
      }
   }
   
   */
   return 0;
}

//========================================


//assign r3 to r0->unk_2C
//assign r0 to end_ptr
int exit_loc_9923E8(result_c8672a3d* r0, result_c8672a3d** end_ptr, int r3)
{
   r0->unk_00 = 0x00;
   r0->unk_2C = r3;
   r0->unk_3C = (local_01a599e0*)-1;
   
   (*end_ptr) = r0;

   return 0;
}

void update_loc_99239C(const local_01a599e0* arg_4, result_c8672a3d* r0, int size, int r9, int& r2)
{
   r0->unk_28 = size;
   r0->unk_30 = arg_4->var_10;
   r0->unk_34 = arg_4->paddr_14;
    
   r2 = arg_4->flag_0C;
  
   if((r2 & 0x07) != 0x03)
      return;
  
   if((r2 & 0xC00) == 0x400)
   {
      if(r9 != 0)
         r2 = r2 | 0xC00;
   }     
   else if((r2 & 0xC00) == 0x800)
   {
      r2 = r2 | 0xC00;
   }
   else if((r2 & 0xC00) == 0x00)
   {
      if(r9 == 0)
      {
         r2 = r2 & (~0xC00);
         r2 = r2 | 0x400;
      }
      else
      {
         r2 = r2 | 0xC00;
      }
   }
}

//this function creates some list of result_c8672a3d elements:

//start_ptr points to the start of the list
//end_ptr points to the end of the list

//each element of the list is linked with arg_4 (original input arguments with dest buffer vaddr)
//and with entry in list1 and list2 (which should contain list of physical addresses for vaddr)
int sub_992288(short unk0, uint32_t size1, addr_pair** list1, uint32_t* size2, addr_pair** list2, const local_01a599e0* arg_4, result_c8672a3d** start_ptr, result_c8672a3d** end_ptr)
{
   int var_38; //some or mask of shorts
   int var_34; //masked size
   int var_30; //masked size
   int var_2C; //masked size
   
   if(size1 == 0)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   if((*size2) == 0)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   
   addr_pair* r12 = (*list1) + (size1 * sizeof(addr_pair)); // end ptr
   addr_pair* r11 = (*list2) + ((*size2) * sizeof(addr_pair)); // end ptr

   var_34 = arg_4->size_08 & 0xFF000000;
   var_30 = arg_4->size_08 & 0xF0000000;
   var_2C = arg_4->size_08 & 0x0F000000;

   int t2 = (arg_4->var_18 == 0) ? arg_4->var_18 : arg_4->var_18 - 1;
   int t1 = ((arg_4->var_18 >> 0x10) == 0) ? (arg_4->var_18 >> 0x10) : ((arg_4->var_18 >> 0x10) - 1);
   var_38 = t1 | t2;

   result_c8672a3d* r5 = 0x00; //ptr 
   int r8 = 0x00; //size
   int r9 = 0x00; //counter

   addr_pair* r4 = *list1; // start ptr
   addr_pair* r6 = *list2; // start ptr
   
   result_c8672a3d* r0 = sub_99214C(); //current element
   if(r0 == 0)
      return SCE_KERNEL_ERROR_NO_MEMORY;
     
   while(true)
   {
      r0->unk_0C = r8; // I suppose this is offset
      r0->unk_20 = r4->addr; //store address from first list
      r0->unk_24 = r6->addr; //store address from second list

      int r2;
       
      if(r4->length >= r6->length)
      {
         if(r4->length > r6->length)
         {
               if(var_2C == 0)
               {
                  r4->addr = (char*)r4->addr + r6->length;
                  r4->length = r4->length - r6->length;
               }

               r8 = r8 + r6->length;

               if(unk0 == 0x13)
               {
                  update_loc_99239C(arg_4, r0, r4->length, r9, r2);
               }
               else
               {
                  if((r4->length & var_38) != 0)
                     return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

                  r0->unk_28 = (r4->length | var_34);
               }

               r6 = r6 + sizeof(addr_pair); //this changes the pointer so everything that accesses it must be done before
         }
         else
         {
               r8 = r8 + r4->length;

               if(unk0 == 0x13)
               {
                  update_loc_99239C(arg_4, r0, r4->length, r9, r2);
               }
               else
               {
                  if((r4->length & var_38) != 0)
                     return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

                  r0->unk_28 = (r4->length | var_34);
               }

               r4 = r4 + sizeof(addr_pair); //this changes the pointer so everything that accesses it must be done before
               r6 = r6 + sizeof(addr_pair); //this changes the pointer so everything that accesses it must be done before
         }
      }
      else
      {
         if(var_30 == 0)
         {
               r6->addr = (char*)r6->addr + r4->length;
               r6->length = r6->length - r4->length;
         }

         r8 = r8 + r4->length;

         if(unk0 == 0x13)
         {
               update_loc_99239C(arg_4, r0, r4->length, r9, r2);
         }
         else
         {
               if((r4->length & var_38) != 0)
                  return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

               r0->unk_28 = (r4->length | var_34);
         }
             
         r4 = r4 + sizeof(addr_pair); //this changes the pointer so everything that accesses it must be done before
      }
       
      r0->unk_04 = r5;
      r0->unk_2C = r2 & ~(0x3000);
      r0->unk_38 = arg_4->var_18;

      if(r5 == 0)
      {
         //assign r0 to start_ptr
         (*start_ptr) = r0;
      }
      else
      {
         r5->unk_00 = r0;
         r5->unk_3C = r0->unk_10;
      }

      r9 = r9 + 1;
      r0->unk_08 = arg_4; //store the only reference to arg_4 to the list

      if(r11 <= r6) //list 2 endptr compare to list 2 current ptr
         break;

      if(r12 <= r4) //list 1 endptr compare to list 1 current ptr
         break;
         
      //reassign pointers
      r5 = r0;
      r0 = sub_99214C();
      if(r0 == 0)
         return SCE_KERNEL_ERROR_NO_MEMORY;
   }
   
   if(unk0 != 0x13)
      return exit_loc_9923E8(r0, end_ptr, arg_4->flag_0C);
        
   int r3_cond = arg_4->flag_0C;

   if((r3_cond & 0x07) != 0x03)
      return exit_loc_9923E8(r0, end_ptr, r3_cond);
       
   if((r3_cond & 0xC00) == 0x400)
   {
      int r3_res = (r9 > 1) ? (r3_cond | 0xC00) : r3_cond;
      return exit_loc_9923E8(r0, end_ptr, r3_res);
   }
   else
   {
      if((r3_cond & 0xC00) != 0x800)
      {
         if((r3_cond & 0xC00) != 0x00)
            return exit_loc_9923E8(r0, end_ptr, r3_cond);
               
         if(r9 <= 1)
            return exit_loc_9923E8(r0, end_ptr, r3_cond);
      }

      int r3_res = r3_cond & (~0xC00);
      r3_res = r3_res | 0x800;
      return exit_loc_9923E8(r0, end_ptr, r3_res);
   }
}

//========================================

int exit_loc_9928F6(int r0, int cookie)
{
   if(cookie == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

int sub_99289C(void* vaddr, int size, paddr_list_req* result)
{
   addr_pair ap; //var_1C, var_18
   ap.addr = vaddr;
   ap.length = size & (~0xFF000000);
   
   int cookie = var_009EA004; //cookie

   result->size = sizeof(paddr_list_req); //0x14
   
   int res_0 = SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(&ap, result);
   if(res_0 < 0)
      return exit_loc_9928F6(res_0, cookie);

   if(result->ret_count == 1)
      return exit_loc_9928F6(0, cookie);

   int poolSize = result->ret_count * sizeof(addr_pair); //0x08
   addr_pair* listPool = (addr_pair*)SceSysmemForDriver_ksceKernelMemPoolAlloc_7b4cb60a(g_008FE000.poolUid_24, poolSize);
   
   if(listPool == 0)
      return exit_loc_9928F6(SCE_KERNEL_ERROR_NO_MEMORY, cookie);

   result->output_buffer = listPool;
   result->output_buffer_size = result->ret_count;

   int res_1 = SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(&ap, result);
   int ret = res_1 & (res_1 >> 0x31); //AND.W R0, R0, R0,ASR#31
   
   return exit_loc_9928F6(ret, cookie);
}

//========================================

int sub_9921FC(result_c8672a3d* unk0, result_c8672a3d* unk1)
{
   /*
   int r5 = r0;
   int r3 = r0[0x14];
   int r6 = &008FE000;
   int r9 = r1;
   int r7 = r0;
   int r8 = r5[0];
   if(r3 == 0)
   {
      //goto loc_99224A
   }
   else
   {
      //loc_992216:
      if(r5 != r9)
      {
         int r3 = r8[0x14];
         if(r3 != 0)
         {
            //goto loc_992240
         }
      }
      
      //loc_992220:
      int r4 = r6[0x28];
      int r0 = 0x008FE028;
      int r2 = r7;
      r5[0] = r4;
      int r1 = r4;
      int r0 = SceCpuForDriver_atomic_set_xor_cda96e81(r0, r1, r2);
      if(r4 != r0)
      {
         //goto loc_992220
      }
      
      if(r5 == r9)
         return r0;

      //loc_99223C:
      int r3 = r8[0x14];

      //loc_992240:
      int r5 = r8;
      int r8 = r5[0];
      if(r3 != 0)
      {
         //goto loc_992216
      }
   }

   //loc_99224A
   int r0 = r6[0x20];
   int r1 = r5;
   int r0 = SceSysmemForKernel_functor_571660aa(r0, r1);
   int r7 = r8;
   if(r5 != r9)
   {
      //goto loc_99223C
   }
   else
   {
      return r0;
   }
   */

   return 0;
}

//========================================

int exit_loc_992A7C(int r0, int cookie)
{
   if(cookie == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

int final_loc_992A56(int r2, result_c8672a3d* var_7C, result_c8672a3d* r6, result_c8672a3d* r5, int cookie)
{
   r6->unk_2C = r2 | 0x1000;

   if(var_7C->unk_18 == 0)
   {
      var_7C->unk_18 = r5;
   }
   else
   {
      result_c8672a3d* r3 = var_7C->unk_1C;
      local_01a599e0* r2 = r5->unk_10;
      r3->unk_00 = r5;
      r3->unk_3C = r2;  
   }

   var_7C->unk_1C = r6;
   return exit_loc_992A7C(0, cookie);
}


//ctx - root element ?
//unk2 is 0x01 or 0x11 (in our case it is 0x11)
//data - input data that is not changed (const modifier) - contains address of buffer that should hold data in the end
int sub_992910(result_c8672a3d* ctx, int unk2, const local_01a599e0* data)
{
   //this four are used for args
   //int** var_90;
   //local_01a599e0* var_8C;
   //int* var_88;
   //int* var_84;

   //locals
   int var_80; // ?????????????????? unreferenced
   result_c8672a3d* var_7C;
   global_008FE000* var_78;
   int* var_74;
   int var_70; // ?????????????????? unreferenced
   
   result_c8672a3d* var_6C;
   result_c8672a3d* var_68;

   paddr_list_req var_64;
   
   //int var_64; - size
   //int var_60; - output_buffer_size
   //int var_5C; - unk
   //int var_58; - ret_count
   //void* ptr_54; - output_buffer
   
   paddr_list_req var_50;
   
   //int var_50; - size
   //int var_4C; - output_buffer_size
   //int var_48; - unk
   //int var_44; - ret_count
   //void* var_40; - output_buffer
   
   addr_pair var_3C;
   
   //int var_3C; - addr
   //int var_38; - length

   addr_pair var_34;
   
   //void* var_34; - addr
   //int var_30; - length

   //-----------------------------

   int var_2C = var_009EA004; //cookie

   //-----------------------------

   const local_01a599e0* r4 = data;

   var_74 = &var_009EA004;
   var_7C = ctx;

   if(data == 0) //original condition was strange - BHI (data - 1 + 3)
      return exit_loc_992A7C(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_2C);

   if(unk2 == 0x10)
   {
      #pragma region

      result_c8672a3d* r5 = 0x00;
      result_c8672a3d* r6 = 0x00;

      var_64.output_buffer_size = 0x01;
      var_64.output_buffer = &var_34;

      var_78 = &g_008FE000;
      
      while(true) //loc_992BB0
      {
         var_50.output_buffer_size = 0x01;
         var_50.output_buffer = &var_3C;

         var_34.addr = r4->source_vaddr_00;
         var_34.length = r4->size_08 & (~0xFF000000);

         int res_0 = sub_99289C(r4->source_paddr_04, r4->size_08, &var_50);
         if(res_0 < 0)
            return exit_loc_992A7C(res_0, var_2C);

         int res_1 = sub_992288(var_7C->unk_3A, var_64.output_buffer_size, &var_64.output_buffer, &var_50.output_buffer_size, &var_50.output_buffer, r4, &var_6C, &var_68);

         if(var_50.output_buffer_size > 1)
            SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(var_78->poolUid_24, var_50.output_buffer);
      
         if(res_1 < 0)
            return exit_loc_992A7C(res_1, var_2C);

         if(r5 != 0)
         {
            result_c8672a3d* r3 = var_6C;
            local_01a599e0* r2 = r3->unk_10;
            r6->unk_00 = r3;
            r6->unk_3C = r2;
            r3->unk_04 = r6;
            r6 = var_68;
         }
         else
         {
            r5 = var_6C;
            r6 = var_68;
         }
      
         r4 = r4->var_1C;  //get pointer to next element or -1
         
         if((r4 + 1) == 0) //r4 will be either pointer to next element or -1 value. adding 1 to -1 value will produce 0
         {
            return final_loc_992A56(r6->unk_2C, var_7C, r6, r5, var_2C);
         }
      }

      #pragma endregion
   }
   else if(unk2 > 0x10)
   {
      if(unk2 == 0x11)
      {
         #pragma region

         result_c8672a3d* r5 = 0x00;
         result_c8672a3d* r6 = 0x00;
         
         while(true) //loc_992ABA
         {            
            var_64.output_buffer_size = 0x01;           
            var_64.output_buffer = &var_3C;

            //get list of physical addresses for source_vaddr_00
            int res_0 = sub_99289C(r4->source_vaddr_00, r4->size_08, &var_64);
            if(res_0 < 0)
               return exit_loc_992A7C(res_0, var_2C);

            var_50.output_buffer_size = 0x01;
            var_50.output_buffer = &var_34;

            //get list of physical addresses for source_paddr_04
            int res_1 = sub_99289C(r4->source_paddr_04, r4->size_08, &var_50);
            if(res_1 < 0)
            {
               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(g_008FE000.poolUid_24, var_64.output_buffer);
               return exit_loc_992A7C(res_1, var_2C);
            }

            //construct new list of result_c8672a3d items 
            //this procedure should take each list of physical addresses and assign each element to newly created result_c8672a3d
            //this item should also be linked with local_01a599e0
            //finally all items together are linked into a list where var_6C is the start and var_68 is the end of the list
            int res_2 = sub_992288(var_7C->unk_3A, var_64.output_buffer_size, &var_64.output_buffer, &var_50.output_buffer_size, &var_50.output_buffer, r4, &var_6C, &var_68);
            
            if(var_64.output_buffer_size > 1)
               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(g_008FE000.poolUid_24, var_64.output_buffer);
            
            if(var_50.output_buffer_size > 1)
               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(g_008FE000.poolUid_24, var_50.output_buffer);

            if(res_2 < 0)
               return exit_loc_992A7C(res_2, var_2C);

            if(r5 != 0)
            {
               result_c8672a3d* r3 = var_6C;
               local_01a599e0* r2 = r3->unk_10;
               r6->unk_00 = r3;
               r6->unk_3C = r2;
               r3->unk_04 = r6;
               r6 = var_68;
            }
            else
            {
               r5 = var_6C;
               r6 = var_68;
            }

            r4 = r4->var_1C; //get pointer to next element or -1
            
            if(r4 + 1 == 0) //r4 will be either pointer to next element or -1 value. adding 1 to -1 value will produce 0
            {
               return final_loc_992A56(r6->unk_2C, var_7C, r6, r5, var_2C);
            }
         }

         #pragma endregion
      }
      else
      {
         #pragma region

         if(unk2 != 0x100)
            return exit_loc_992A7C(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_2C);

         result_c8672a3d* r5 = sub_99214C();
         if(r5 == 0)
            return exit_loc_992A7C(SCE_KERNEL_ERROR_NO_MEMORY, var_2C);

         result_c8672a3d* r6 = sub_99214C();
         if(r6 == 0)
         {
            sub_9921FC(r5, r5);
            return exit_loc_992A7C(SCE_KERNEL_ERROR_NO_MEMORY, var_2C);
         }

         r5->unk_28 = r4->size_08;
         r5->unk_38 = r4->var_18;
         r5->unk_2C = r4->flag_0C;
         r5->unk_3C = r4->var_1C;

         r5->unk_20 = r4->source_vaddr_00;
         r5->unk_24 = r4->source_paddr_04;

         //this part is very strange
         /*
         local_01a599e0* r9 = (r4 + sizeof(local_01a599e0))->var_1C; //what?  + 0x20

         r5->unk_00 = r6;

         r5->unk_08 = r4;
         r5->unk_0C = 0x00;

         r5->unk_04 = 0x00;

         r9->var_1C = r6->unk_10;

         r6->unk_20 = (r4 + sizeof(local_01a599e0))->source_vaddr_00; //what?
         r6->unk_24 = (r4 + sizeof(local_01a599e0))->source_paddr_04; //what?

         r6->unk_28 = (r4 + sizeof(local_01a599e0))->size_08; //what ?
         r6->unk_2C = (r4 + sizeof(local_01a599e0))->flag_0C; //what ?

         r6->unk_38 = (r4 + sizeof(local_01a599e0))->var_18; //what ?;
         r6->unk_0C = 0x00;
            
         r6->unk_00 = 0x00;
         r6->unk_04 = r5;
         
         r6->unk_3C = 0xFFFFFFFF; //looks like end element index ?
         r6->unk_08 = r4 + sizeof(local_01a599e0); //next element ?

         //this will be used later
         int r2 = (r4 + sizeof(local_01a599e0))->flag_0C; //what ?

         return final_loc_992A56(r2, var_7C, r6, r5, var_2C);
         
         */
         return 0;

         #pragma endregion
      }
   }
   else
   {
      if(unk2 == 0x00)
      {
         #pragma region

         //this part is strange

         
         result_c8672a3d* r5 = 0x00;
         result_c8672a3d* r6 = 0x00;
         /*
         while(true) //loc_992B4E
         {
            
            result_c8672a3d* r0 = sub_99214C();
            if(r0 == 0)
               return exit_loc_992A7C(SCE_KERNEL_ERROR_NO_MEMORY, var_2C);

            r0->unk_24 = r4->source_paddr_04;
            r0->unk_38 = r4->var_18;
            r0->unk_28 = r4->size_08;
            r0->unk_2C = r4->flag_0C;

            r0->unk_0C = 0x00;
            r0->unk_20 = r4->source_vaddr_00;

            r0->unk_00 = 0x00;
            r0->unk_04 = r6;
            r0->unk_08 = r4;

            if(r5 != 0)
            {
               int r3 = r0->unk_10;
               r6->unk_00 = r0;
               r6->unk_3C = r3;
            }
            else
            {
               r5 = r0;
            }

            r4 = r4->var_1C; //going to next element in list ?
            r6 = r0;

            if((r4 + 1) == 0)
            {
               r4 = r0->unk_3C; //why is this needed ?
               return final_loc_992A56(r2, var_7C, r6, r5, var_2C);
            }
         }
         
         */
         return 0;

         #pragma endregion
      }
      else
      {
         #pragma region

         if(unk2 != 0x01)
            return exit_loc_992A7C(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_2C);

         result_c8672a3d* r5 = 0x00;
         result_c8672a3d* r6 = 0x00;

         var_78 = &g_008FE000;

         var_50.output_buffer_size = 0x01;
         var_50.output_buffer = &var_34;

         while(true) //loc_99297A
         {
            var_64.output_buffer_size = 0x01;
            var_64.output_buffer = &var_3C;

            var_34.addr = r4->source_paddr_04;
            var_34.length = (r4->size_08) & (~0xFF000000);

            int res_0 = sub_99289C(r4->source_vaddr_00, r4->size_08, &var_64);
            if(res_0 < 0)
               return exit_loc_992A7C(res_0, var_2C);

            int res_1 = sub_992288(var_7C->unk_3A, var_64.output_buffer_size, &var_64.output_buffer, &var_50.output_buffer_size, &var_50.output_buffer, r4, &var_6C, &var_68);

            if(var_64.output_buffer_size > 1)
               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(var_78->poolUid_24, var_64.output_buffer);

            if(res_1 < 0)
               return exit_loc_992A7C(res_1, var_2C);

            if(r5 != 0)
            {
               result_c8672a3d* r3 = var_6C;
               local_01a599e0* r2 = r3->unk_10;
               r6->unk_00 = r3;
               r6->unk_3C = r2;
               r3->unk_04 = r6;
               r6 = var_68;
            }
            else
            {
               r5 = var_6C;
               r6 = var_68;
            }

            r4 = r4->var_1C; //get pointer to next element or -1
            
            if(r4 + 1 == 0) //r4 will be either pointer to next element or -1 value. adding 1 to -1 value will produce 0
            {
               return final_loc_992A56(r6->unk_2C, var_7C, r6, r5, var_2C);
            }
         }

         #pragma endregion
      }
   }
   return -1;
}

//========================================

//id is a packed pointer to structure result_c8672a3d* created by SceSysmemForKernel_functor_c8672a3d
//data is structure - it contains pointer to a buffer that will be copied as a key later in SblGcAuthMgr
//ptr is 0x00
//unk2 is 0x01 or 0x11 (in our case it is 0x11)
int SceDmacmgrForDriver_167079fc(dmac_id id, local_01a599e0* data, input_167079fc* ptr, int unk2)
{
   /*
   result_c8672a3d* ctx = SCE_DMAC_UNPACK_ID(id);

   int gxor = SCE_DMAC_GXOR(g_008FE000);
   
   if(ctx->gxor_30 != gxor)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   int prev_state = SceCpuForDriver_lock_int_d32ace9e(&ctx->lockable_int_2C);
   
   if(ptr != 0)
   {
      if(ctx->unk_3A == 0x13)
      {
         if(ptr->unk_0 != 0x5C) //check structure size ?
         {
            SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
            return SCE_KERNEL_ERROR_INVALID_ARGUMENT_SIZE;
         }
      }
      else
      {
         if(ptr->unk_0 != 0x0C) //check structure size ?
         {
            SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
            return SCE_KERNEL_ERROR_INVALID_ARGUMENT_SIZE;
         }
      }
   } 

   if((ctx->unk_38 << 0x1F) >= 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_NOT_INITIALIZED;
   }

   if(((ctx->unk_38) << 0x1C) < 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_ALREADY_QUEUED;
   }

   if(ctx->unk_14 != 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_ALREADY_QUEUED;
   }

   if((ctx->unk_38 << 0x19) < 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_CANCELING;
   }

   if(ctx->unk_18 != 0)
      sub_9921FC(ctx->unk_18, ctx->unk_1C);

   ctx->unk_18 = 0x00;
   ctx->unk_1C = 0x00;
   ctx->unk_20 = (void*)SCE_DMAC_BITMASK1;

   if(ptr != 0)
   {
      ctx->unk_20 = ptr->unk_4 | SCE_DMAC_BITMASK2 | 0x40000;

      if(ctx->unk_3A == 0x13) //TODO: not sure about this condition
         ctx->unk_28 = ptr + sizeof(input_167079fc); // looks like this is pointer to next element in array;
      else
         ctx->unk_28 = ptr->unk_8;
   }

   int res_0 = sub_992910(ctx, unk2, data);
   if(res_0 < 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
      return res_0;      
   }

   ctx->unk_38 = 0xFFDF & ctx->unk_38;

   SceCpuForDriver_unlock_int_7bb9d5df(&ctx->lockable_int_2C, prev_state);
   */
   return 0;
}

//==========================================================================

int exit_loc_993152(int r0, int var_24)
{
   if(var_24 == var_009EA004)
      return r0;
   else
      return STACK_CHECK_FAIL;
}

//id is a packed pointer to structure result_c8672a3d* created by SceSysmemForKernel_functor_c8672a3d
//data is structure of size 0x6C - it contains pointer to a buffer that will be copied as a key later in SblGcAuthMgr
//unk2 is 0x01 or 0x11 (in our case it is 0x11)
int SceDmacmgrForDriver_01a599e0(dmac_id id, locals_B99674* data, int unk2)
{
   /*
   int var_48; // TODO: is it used ?
   local_01a599e0 local;
   int var_24 = var_009EA004;

   if(data == 0)
      return exit_loc_993152(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_24);

   result_c8672a3d* ptr_9 = SCE_DMAC_UNPACK_ID(id);
   int gxor = SCE_DMAC_GXOR(g_008FE000);
   
   if(ptr_9->gxor_30 != gxor)
      return exit_loc_993152(SCE_KERNEL_ERROR_INVALID_ARGUMENT, var_24);

   if(ptr_9->unk_3A == 0x13)
   {
      local.var_34_10 = data->unk_1C;
      local.paddr_30_14 = data->paddr_20;
   }

   local.source_vaddr_44_00 = data->source_vaddr_0;
   local.source_paddr_40_04 = data->source_paddr_4;
   local.size_3C_08 = data->size_8;
   local.flag_38_0C = data->flag_C;
   local.var_2C_18 = data->unk_10; //TODO: unknown and do not know how it is initialized
   local.var_28_1C = 0xFFFFFFFF;

   int res_0 = SceDmacmgrForDriver_167079fc(id, &local, 0x00, unk2);

   if(res_0 < 0)
      return exit_loc_993152(res_0, var_24);

   if(ptr_9->unk_3A != 0x13)
      ptr_9->unk_28 = data->unk_18;
   else
      ptr_9->unk_28 = (input_167079fc*)&data->unk_1C; //TODO: this is a weird cast. does this mean that input_167079fc is part of structure ?

   int bits = (data->unk_14) & (~SCE_DMAC_BITMASK1); // TODO: need to test this
   ptr_9->unk_20 = (void*)(bits | (int)ptr_9->unk_20); //TODO: weird cast again

   return exit_loc_993152(0, var_24);
   */

   return 0;
}

//========================================

struct input2_992460_r2
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
   int unk_30;
   int unk_34;
   
   //...

   int unk_200[16]; //0x40 bytes
};

struct input2_992460_4
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;
   int unk_10;

   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
   int unk_30;
   int unk_34;
   int unk_38;
   int unk_3C;
   int unk_40;
   int unk_44;
   int unk_48;
   int unk_4C;
};

struct input2_992460_28
{
   int unk_0;
   input2_992460_4* unk_4;
   int unk_8;
   int unk_C;
   int unk_10;
};

struct input2_992460_18
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;

   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
};

struct input2_992460
{
   int unk_0;
   int unk_4;
   int unk_8;
   int unk_C;

   int unk_10;
   int unk_14;
   input2_992460_18* unk_18;
   int unk_1C;

   int unk_20;
   int unk_24;
   input2_992460_28* unk_28;
   int unk_2C;

   int unk_30;
   int unk_34;
   
   char unk_38;
   char unk_39;

   int unk_3A;
};

struct input1_992460 //looks like to be array or contain array at offset 0
{
   input2_992460* unk_0;
   input2_992460* unk_4;
   int unk_8;
   int unk_C;

   // ...

   int unk_10C;
};

void sub_992460(input1_992460* r0, input2_992460* r1)
{
   /*
   int r3 = r0->unk_C;
   if(r3 == 0)
      return;

   //CLZ.W		R2, R3
   int r7 = r0 + 0x10C;
   int r2 = 2;
   int r5 = r1->unk_3A;
   int r2 = r0 + (r2 << 3);
   int lr = 1;
   int r6 = r1->unk_20;
   int r4 = r2 + 4;

   input2_992460_r2* r2 = r2[0x04];
   int r7 = r7 - r4;
   
   //MOV.W		R7, R7,ASR#3
   int r7 = lr << r7;
   int r3 = r3 - r7;

   r0->unk_C = r3;
   r4[0x04] = r1;
   r1->unk_14 = r4;
   r2->unk_2C = r6;

   if(r5 == 0x13)
   {
      #pragma region loc_9924D0
      input2_992460_28* r4 = r1->unk_28;
      int r3 = r4->unk_0;
      int r5 = r4->unk_8;
      int r6 = r4->unk_C;
      int r7 = r4->unk_10;
      input2_992460_4* r4 = r4->unk_4;

      int r5 = r4->unk_10;
      int r6 = r4->unk_8;

      r2->unk_10 = r3;
      r2->unk_14 = r7;
      r2->unk_30 = r6;
      r2->unk_200[0] = r5;

      int r3 = r4->unk_14;
      r2->unk_200[1] = r3;

      int r3 = r4->unk_18;
      r2->unk_200[2] = r3;

      int r3 = r4->unk_1C;
      r2->unk_200[3] = r3;
      
      int r3 = r4->unk_20;
      r2->unk_200[4] = r3;
      
      int r3 = r4->unk_24;
      r2->unk_200[5] = r3;

      int r3 = r4->unk_28;
      r2->unk_200[6] = r3;

      int r3 = r4->unk_2C;
      r2->unk_200[7] = r3;

      int r3 = r4->unk_30;
      r2->unk_200[8] = r3;

      int r3 = r4->unk_34;
      r2->unk_200[9] = r3;

      int r3 = r4->unk_38;
      r2->unk_200[10] = r3;

      int r3 = r4->unk_3C;
      r2->unk_200[11] = r3;

      int r3 = r4->unk_40;
      r2->unk_200[12] = r3;

      int r3 = r4->unk_44;
      r2->unk_200[13] = r3;

      int r5 = r4->unk_48;
      input2_992460_18* r3 = r1->unk_18;

      r2->unk_200[14] = r5;

      int r4 = r4->unk_4C;

      r2->unk_200[15] = r4;
      #pragma endregion
   }
   else
   {
      #pragma region
      input2_992460_18* r3 = r1->unk_18;
      int r4 = r3->unk_2C;
      int r4 = r4 & 0x0C;
      if(r4 == 0x0C)
      {
         r4 = r1->unk_28;
         r2->unk_34 = r4;
      }
      #pragma endregion
   }

   int r3 = r3->unk_10; //input2_992460_18*
   r2->unk_20 = r3; // input2_992460_r2*
   //DSB.W		SY // Data Synchronization Barrier

   int r3 = r1->unk_4; //input2_992460*
   r0->unk_0 = r3;
   if(r3 == 0)
   {
      r0->unk_4 = r3;
   }

   int r0 = r1->unk_38;
   int r3 = 0xFFF7;
   int r2 = 0;
   //STRD.W		R2, R2,	[R1]
   int r2 = r2 & r0;
   r1->unk_38 = r3;
   */
}

//========================================

int exit_loc_99330A(int r4)
{
   int r0 = r4;
   return r0;
}

int exit_loc_993310()
{
   int r4 = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   int r0 = r4;
   return r0;
}

int exit_loc_993352(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_NOT_INITIALIZED;
   int r0_ret = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993386(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_NOT_SETUP;
   int r0_ret = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_99331C(int* r6, int r8)
{
   int r4 = SCE_KERNEL_ERROR_ALREADY_QUEUED;
   int* r0 = r6;
   int r1 = r8;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   int r0_ret = r4;
   return r0_ret;
}  

int exit_loc_993364(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_TRANSFERRED;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993340(int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r4 = SCE_KERNEL_ERROR_CANCELING;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993302(int r4, int* r6, int r8)
{
   int* r0 = r6;
   int r1 = r8;
   int r0_res = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   return exit_loc_99330A(r4);
}

int exit_loc_993376(int* r6, int* r7, int r8)
{
   int* r0 = r7;
   int r4 = SCE_KERNEL_ERROR_NOT_UNDER_CONTROL;
   int r0_res = SceCpuForDriver_unlock_d6ed0c46(r0);
   return exit_loc_993302(r4, r6, r8);
}

int exit_loc_9932FA(int* r6, int* r7, int r8)
{
   int* r0 = r7;
   int r4 = 0;
   int r0_res = SceCpuForDriver_unlock_d6ed0c46(r0);
   return exit_loc_993302(r4, r6, r8);
}

int exit_loc_993332(input1_992460* r5, int* r6, int* r7, int r8)
{
   input2_992460* r4 = r5->unk_4;
   input1_992460* r0 = r5;
   r5->unk_0 = r4;
   input2_992460* r1 = r4;
   sub_992460(r0, r1);
   return exit_loc_9932FA(r6, r7, r8);
}

int exit_loc_9932F4()
{
   /*
   int r4 = r3[4];
   int r3 = r4[0];
   int r4 = r5[4]; //WHAT?
   return exit_loc_9932FA();
   */

   return 0;
}

int SceDmacmgrForDriver_543f54cf(dmac_id id)
{
   /*
   int r0 = r0 >> 1;
   int r3 = &_008FE000;
   int r4 = r0 << 2;
   int r3 = r3 | 1;
   int r2 = r4[0x30];

   if(r2 != r3)
      return exit_loc_993310();

   int r6 = r4 = 0x2C;
   int r0 = r6;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);

   int r3 = r4[0x38];
   int r8 = r0;
   int r0 = r3 << 0x1F;
   if(true) //BPL
      return exit_loc_993352(r0);

   int r3 = r4[0x18];
   if(r3 == 0)
      return exit_loc_993386();

   int r3 = r4[0x38];
   int r1 = r3 << 0x1C;
   if(true) //BMI
      return exit_loc_99331C();

   int r3 = r4[0x14];
   if(r3 != 0)
      return exit_loc_99331C();

   int r3 = r4[0x38];
   int r2 = r3 << 0x1A;
   if(true) // BMI
      return exit_loc_993364();

   int r3 = r4[0x38];
   int r3 = r3 << 0x19;
   if(true) // BMI
      return exit_loc_993340();

   int r5 = r4[0x10];
   int r7 = r5 & 8;
   int r0 = r7;
   int r0 = SceCpuForDriver_lock_bf82deb2(r0);
   int r3 = r5[0x10];
   if(r3 == 0)
      return exit_loc_993376();

   int r2 = r4[0x38];
   int r3 = r5[0];
   int r2 = r2 | 8;
   r4[0x38] = r2;

   if(r3 == 0)
      return exit_loc_993332();

   int r3 = r5[4];
   int r2 = r3[4];
   if(r2 == 0)
      return exit_loc_9932F4();

   r2[0] = r4;
   r4[4] = r2;

   return exit_loc_9932F4();
   */

   return 0;
}

//========================================

int exit_loc_993846(int r0)
{
   return r0;
}

int exit_loc_993840()
{
   int r0 = SCE_KERNEL_ERROR_INVALID_ARGUMENT;
   return exit_loc_993846(r0);
}

int exit_loc_9938DC(int* r5, int r1)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r5, r1);
   return exit_loc_993846(SCE_KERNEL_ERROR_NOT_INITIALIZED);
}

int exit_loc_9938BC(int* r5, int r1)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r5, r1);
   return exit_loc_993846(SCE_KERNEL_ERROR_NOT_SETUP);
}

int exit_loc_9938CC(int* r5, int r1)
{
   SceCpuForDriver_unlock_int_7bb9d5df(r5, r1);
   return exit_loc_993846(SCE_KERNEL_ERROR_CANCELING);
}

int SceDmacmgrForDriver_397a917c(dmac_id id, int num, int unk2, int unk3)
{
   /*

   int var_38;
   int var_2C;

   int r0 = r0 >> 1;
   int r5 = _008FE000;
   int r4 = r0 << 2;
   int r5 = r5 | 1;
   int r7 = r4[0x30];
   var_2C = r2;
   int r6 = r1;
   int r9 = r3;
   if(r7 != r5)
      return exit_loc_993840(); //invalid flags

   int r5 = r4 + 0x2C;
   int r0 = r5;
   int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
   int r3 = r4[0x38];
   int r1 = r0;
   int r2 = r3 << 0x1F;
   if(r2 >=0 )
      return exit_loc_9938DC(); // not initialized

   int r3 = r4[0x18];
   if(r3 == 0)
   {
      int r3 = r4[0x14];
      if(r3 == 0)
      {
         int r3 = r4[0x38];
         int r3 = r3 << 0x1A;
         if(r3 >=0 )
            return exit_loc_9938BC(); //not setup
      }
   }

   //loc_993812:
   short r8 = r4[0x38];
   int r8 = r8 & 0x40;
   if(r8 != 0)
      return exit_loc_9938CC();

   short r3 = r4[0x38];
   int r0 = r5;
   int r10 = r4[0x34];
   int r11 = r3;
   int r0 = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
   if(r6 == 2)
   {
      var_38 = r8;
      int r0 = r10;
      int r3 = r8;
      //goto loc_993854
   }
   else
   {
      if(r6 == 3)
      {
         int r0 = r10;
         int r3 = r8;
         int r2 = &var_2C;
         var_38 = r2;
         //goto loc_993854
      }
      else
      {
         if(r6 == 1)
         {
            int temp_tst =  r11 & 0x20; //r11 is not touched
            if(temp_tst == 0) //not sure
               int r0 = r6;

            if(temp_tst == 0)
            {
               return exit_loc_993846(r0);
            }
            else
            {
               SceUID r0 = r10;
               int r1 = r6;
               unsigned int* r3 = r8;
               int r2 = SCE_EVENT_WAIT_5;
               int r0 = SceThreadmgrForDriver_ksceKernelPollEventFlag_76c6555b(r0, r1, r2, r3);
               if(r0 >= 0)
               {
                  //goto loc_993860
               }
               else
               {
                  return exit_loc_993846(r0);
               }
            }
         }
         else
         {
            return exit_loc_993840();
         }
      }
   }

   //loc_993854:
   {
      int r1 = 1;
      int r2 = SCE_EVENT_WAIT_5;
      int r0 = SceThreadmgrForDriver_ksceKernelWaitEventFlag_0c1d3f20(r0, r1, r2, r3, ?);
      if(r0 == 0)
      {
         return exit_loc_993846(r0);
      }
      else
      {
         //goto loc_993860
      }
   }

   //loc_993860:
   {
      int r0 = r9;
      if(r9 == 0)
      {
         return exit_loc_993846(r0);
      }
      else
      {
         int r0 = r5;
         int r0 = SceCpuForDriver_lock_int_d32ace9e(r0);
         int r3 = r4[0x30];
         int r1 = r0;
         int r0 = r5;

         if(r7 == r3)
         {
            int r3 = r4[0x24];
            r9[0x00] = r3;
         }

         int r0 = SceCpuForDriver_unlock_int_7bb9d5df(r0, r1);
         int r0 = 0;
         return r0;
      }
   }

   */

   return 0;
}

//========================================

void sub_992000(result_c8672a3d* r0)
{
   /*
   int C0 = (int)r0->unk_38 & 0x40; //UXTH
   if(C0 != 0)
      return;

   r0->unk_38 = (r0->unk_38 | 0x40);

   unk_14_pair_0* ptr2 = r0->unk_14->unk_0;
   
   ptr2->unk_1C = C0;
   
   DSB(SY);

   while(true) //this looks like infinite loop that waits for sync ?
   {
      int C1 = ptr2->unk_24 << 0x1F;
      if(C1 >= 0)
         break;
   }

   if(ptr2->unk_28 != 0)
      return;

   result_c8672a3d_10_unk* ptr3 = r0->unk_10;
   result_c8672a3d_14_pair* ptr1 = r0->unk_14;

   int V1 = (int)ptr3 + 0x10C;
   int V2 = V1 - (int)ptr1;
   int V3 = V2 >> 3; //ASRS
   int V4 = 0x01 << (V3);

   ptr3->unk_C = ptr3->unk_C | V4;
   r0->unk_38 = 0xFFBF & r0->unk_38;
   
   ptr1->unk_4 = 0;
   r0->unk_14 = 0;
   */
}

//----------------------

//looks like this procedure does some operations with linked list

void sub_992100(result_c8672a3d* r0)
{  
   local_01a599e0* N5 = r0->unk_10;
   
   SceCpuForDriver_lock_bf82deb2(&N5->size_08);

   //this looks like some linked list operations

   if(N5->source_vaddr_00 == r0)
      N5->source_vaddr_00 = r0->unk_04; // TODO: this cast is strange

   if(N5->source_paddr_04 == r0)
      N5->source_paddr_04 = r0->unk_00; // TODO: this cast is strange

   result_c8672a3d* N3 = r0->unk_00;
   if(N3 != 0)
      N3->unk_04 = r0->unk_04;

   result_c8672a3d* N2 = r0->unk_04;
   if(N2 != 0)
      N2->unk_00 = N3;

   r0->unk_00 = 0x00;
   r0->unk_04 = 0x00;
   SceCpuForDriver_unlock_d6ed0c46(&N5->size_08);

   r0->unk_38 = 0xFFF7 & r0->unk_38;
}

//----------------------

int SceDmacmgrForDriver_adff1186(dmac_id id)
{
   /*
   int ctx = SceIntrmgrForDriver_getCurrentCpuUnkData_182ee3e3();
   if(ctx != 0)
      return SCE_KERNEL_ERROR_ILLEGAL_CONTEXT;

   result_c8672a3d* r4 = SCE_DMAC_UNPACK_ID(id);
   int gxor = SCE_DMAC_GXOR(g_008FE000);

   if(r4->gxor_30 != gxor)
      return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

   int prev_state = SceCpuForDriver_lock_int_d32ace9e(&r4->lockable_int_2C);
   
   int C0 = r4->unk_38 << 0x1F; //what is the point shifting short to 31 bits ?
   if(C0 >= 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_NOT_INITIALIZED;
   }

   int C1 = r4->unk_38 << 0x19; //what is the point shifting short to 25 bits ?
   if(C1 < 0)
   {
      SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);
      return SCE_KERNEL_ERROR_CANCELING;
   }

   if(r4->unk_14 != 0)
   {
      sub_992000(r4);

      int C2 = (r4->unk_38) << 0x19;

      if(C2 < 0)
      {
         SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);

         int ctr = 5;

         while(true)
         {
            SceThreadmgrForDriver_sceKernelDelayThread_4b675d05(0x0A); //10 ms
            
            prev_state = SceCpuForDriver_lock_int_d32ace9e(&r4->lockable_int_2C);

            int C3 = (r4->unk_38) << 0x19;
            if(C3 >= 0)
               break;

            SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);
            ctr = ctr - 1;

            if(ctr == 0)
               return SCE_ERROR_ERRNO_EBUSY;
         }
      }
   }

   int C5 = r4->unk_38 << 0x1C;
   if(C5 < 0)
      sub_992100(r4);
   
   SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(r4->eventFlagUid_34);

   r4->unk_38 = 0x00;
   r4->gxor_30 = 0x00;
   
   SceCpuForDriver_unlock_int_7bb9d5df(&r4->lockable_int_2C, prev_state);

   SceSysmemForKernel_functor_571660aa(g_008FE000.unk_20, r4);
   */
   return 0;
}