#include "SceSblSmSchedProxy.h"

#include "SceCpu.h"
#include "SceSysmemGlobalVariables.h"
#include "SceSysmem.h"
#include "SceIntrmgr.h"
#include "SceKernelSuspend.h"
#include "SceSysroot.h"
#include "SceThreadmgr.h"
#include "SceDebug.h"

#include <stdint.h>
#include <cstdint>

//==========================================================================================================

//internal types

struct item_996E0C //size is 0x10
{
  item_996E0C *item0;
  item_996E0C *item1;
  sysbase_shared_block_t *sysbase_block;
  int unkC;
};

struct lock_8F501C
{
  int lock;
};

struct global_lock_t
{
  int lock;
};

struct global_lock_count_t
{
  int value;
};

struct operation_callback_data
{
  int func_arg2;
  int func_arg4;
  int func_arg3;
};

typedef int smc_138_callback(SmOperationId id, int index, int arg2, int arg3, int arg4);

struct shed_proxy_operation_callback_entry_t
{
   smc_138_callback *cb;
   operation_callback_data data;
};

struct shed_proxy_operation_item_t
{
  int is_used;
  SmOperationId operation_id;
  void *maybe_status_secure_world_ptr;
  SceUID SceSblSmsProxy_event_uid;
  SceUID SceSblSmsProxyWait_mutex_uid;
  shed_proxy_operation_callback_entry_t functions[4];
};

struct SceSblSmschedProxyHeap
{
  shed_proxy_operation_item_t items[0x40];
};

struct smc_12D_data_t
{
   int unk0;
   int unk4;
   int unk8;
   int unkC;
   SmOperationId invoke_operation_id;
   void *maybe_status_secure_world_ptr;
   unsigned int self_type;
   uint32_t pathId;
   SceUInt64 program_authority_id;
   uint8_t caller_capability[32];
};

//==========================================================================================================

int g_008F5000; //operation id counter
//g_008F5004
global_lock_count_t g_008F5010;
SceUID g_008F5014;
global_lock_t g_008F5018;
lock_8F501C g_008F501C;
SceSblSmschedProxyHeap * g_008F5020;
//g_008F5024
item_996E0C g_008F5028[8]; //blocks 1 bank
sysbase_shared_block_t* g_008F50A8; //blocks 1 - continuous array
//g_008F50AC
item_996E0C g_008F50B0[8]; //blocks 0 bank
sysbase_shared_block_t* g_008F5130; //blocks 0 - continuous array
sysbase_shared_block40* g_008F5134; 
item_996E0C g_008F5138; //starting item - supposed to be for blocks 1
//g_008F5148
item_996E0C g_008F5150; //starting item with blocks 0
//g_008F5160

//==========================================================================================================

//0x6CBE4B08
//0x71F6D2DB
//0x72C0A929
//0
//0
//0
kernel_message_ctx msg_9978A4;

//==========================================================================================================

int proc_initialize_sysbase_related_list_items_996E0C()
{
   sysbase_shared_buffer_t * sysbase_buffer0 = SceSysrootForKernel_get_sysbase_0x320_shared_tz_region_c8c8c321();
   
   if (!sysbase_buffer0)
      return 0x800F040C;

   g_008F5130 = sysbase_buffer0->blocks0; 
   g_008F50A8 = sysbase_buffer0->blocks1;
   g_008F5134 = &sysbase_buffer0->block40;

   item_996E0C* current_item0 = &g_008F5138;
   g_008F5138.item0 = &g_008F5138;
   g_008F5138.item1 = &g_008F5028[7];
   //sysbase_blocks is not initialized! 

   item_996E0C* current_item1 = &g_008F5150;
   g_008F5150.item0 = &g_008F5150;
   g_008F5150.item1 = &g_008F50B0[7];
   g_008F5150.sysbase_block = sysbase_buffer0->blocks0;

   int blocks_index = 0;

   for(int i = 0; i < 8; i++)
   {
      g_008F5028[blocks_index].item0 = &g_008F5138;
      g_008F5028[blocks_index].item1 = current_item0;
      g_008F5028[blocks_index].sysbase_block = &sysbase_buffer0->blocks1[blocks_index];
      current_item0->item0 = &g_008F5028[blocks_index];
      current_item0 = &g_008F5028[blocks_index];

      g_008F50B0[blocks_index].item0 = &g_008F5150;
      g_008F50B0[blocks_index].item1 = current_item1;
      g_008F50B0[blocks_index].sysbase_block = &sysbase_buffer0->blocks0[blocks_index];
      current_item1->item0 = &g_008F50B0[blocks_index];
      current_item1 = &g_008F50B0[blocks_index];
      
      blocks_index++;
   }

   g_008F501C.lock = 0;

   return 0;
}

int cache_flush_shared_blocks_996F14()
{
   int ret0 = proc_initialize_sysbase_related_list_items_996E0C();
   if (ret0 >= 0)
   {
      SceCpuForDriver_sceKernelCpuDcacheAndL2CleanMVACRange_1ForDriver_103872a5(g_008F5130, 0x400u);
      SceCpuForDriver_sceKernelCpuDcacheAndL2CleanMVACRange_1ForDriver_103872a5(g_008F50A8, 0x400u);
      SceCpuForDriver_sceKernelCpuDcacheAndL2CleanMVACRange_1ForDriver_103872a5(g_008F5134, 0x40u);
   }
   return ret0;
}

int proc_suspend_callback_9964B0(int resume, int eventid, suspend_args_t *args, void *opt)
{
   int ret0;

   if (resume != 1 || eventid != 0x10004)
      return 0;

   ret0 = cache_flush_shared_blocks_996F14();
   return ret0 & (ret0 >> 31);
}

int proc_enter_SMC_996000(int arg_0, int arg_1, int arg_2, int arg_3, int monitor_api_number)
{
  //__asm { SMC             #0; enters Secure Monitor mode }

  return 0;
}

int proc_smc_13B_heap_free_cleanup_9965C0()
{
   SceUID heap_uid;
   int result = proc_enter_SMC_996000(0, 0, 0, 0, 0x13B);

   if (g_008F5014 > 0)
   {
      if (g_008F5020 > 0)
      {
         SceSysmemForDriver_sceKernelFreeHeapMemoryForDriver_3ebce343(g_008F5014, g_008F5020);
         heap_uid = g_008F5014;
         g_008F5020 = 0;
      }

      SceSysmemForDriver_sceKernelDeleteHeapForDriver_d6437637(g_008F5014);
      g_008F5014 = -1;
   }

   g_008F5010.value = 2;

   return result;
}

int proc_proxy_smc_133_135_136_9962F4(int monitorApiNumber, SmOperationId id, int num_or_index_smcArg1, int smcArg2)
{
   //TODO: not reversed
   return 0;
}

int proc_proxy_smc_134_137_99636C(int monitorApiNumber, SmOperationId id, int num, int *response)
{
   //TODO: not reversed
   return 0;
}

int proc_interrupt_handler_smc_13A_99608C(int intr_code, void *userCtx)
{
   //TODO: not reversed
   return 0;
}

// returns block index
int get_partial_data_block_invalidate_cache_maybe_remove_from_list_996F58(sysbase_shared_block_t *block_base_ptr, unsigned int data_size, void** invalidate_block_pointer, unsigned int *data_size_result)
{
   //check args
   if (!block_base_ptr || data_size > 0x80 || !invalidate_block_pointer || !data_size_result)
      return 0x800F0416;

   //get starting item pointer
   item_996E0C * root_item = &g_008F5138; //starting item - supposed to be for blocks 1
   if (block_base_ptr == g_008F5130) //blocks 0 - continuous array
      root_item = &g_008F5150; //starting item with blocks 0

   //if points to itself - means that it is not initialized
   if (root_item == root_item->item0)
      return 0x800F040C;

   item_996E0C * current_node = root_item->item0;
   item_996E0C * node_item0 = current_node->item0;
   item_996E0C * node_item1 = current_node->item1;
   
   node_item0->item1 = node_item1;
   current_node->item1->item0 = node_item0;

   current_node->item0 = current_node;
   current_node->item1 = current_node;

   *invalidate_block_pointer = current_node->sysbase_block;
   *data_size_result = data_size;

   SceCpuForDriver_sceKernelCpuDcacheAndL2InvalidateMVACRange_1ForDriver_02796361(current_node->sysbase_block, 0x80u);

   return (current_node->sysbase_block - block_base_ptr) / 0x80;
}

// returns block index
int get_partial_data_block_invalidate_cache_maybe_remove_from_list_996FCC(unsigned int real_data_size, void **block_ptr, unsigned int *data_size_result)
{
   if(!g_008F5150.sysbase_block)
   {
      int res0 = proc_initialize_sysbase_related_list_items_996E0C();
      if(res0 < 0)
         return res0;
   }

   int prev_state = SceCpuForDriver_sceKernelCpuLockSuspendIntrStoreLRForDriver_d32ace9e(&g_008F501C.lock);

   //this assignment is very weird - does it overflow when cpuid > 1?
   int cpuid = SceCpuForDriver_sceKernelCpuGetCpuIdForDriver_5e4d5de1();
   sysbase_shared_block_t ** block_pp = &g_008F5138.sysbase_block;
   *(int*)(block_pp + cpuid) = prev_state;

   int block_index = get_partial_data_block_invalidate_cache_maybe_remove_from_list_996F58(g_008F5130, real_data_size, block_ptr, data_size_result);
   if (block_index < 0)
      SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F501C.lock, prev_state);
   else
      SceCpuForDriver_sceKernelCpuUnlockStoreLRForDriver_d6ed0c46(&g_008F501C.lock);
   
   return block_index;
}

shed_proxy_operation_item_t* get_operation_item_99600C(SmOperationId id, int *error_code)
{
   //check error code ptr
   if (error_code == 0)
      return 0;

   //check operation id
   if (id == -1)
   {
      *error_code = 1;
      return 0;
   }

   //check operation id
   if (id == 0)
   {
      *error_code = 2;
      return 0;
   }

   //find operation item
   shed_proxy_operation_item_t *heap_item;
   int index0 = 0;
   while (1)
   {
      int is_used = g_008F5020->items[index0].is_used;
      heap_item = &g_008F5020->items[index0];
      ++index0;

      //operation item should be in use and operation id should be equal to id
      if (is_used == 1 && heap_item->operation_id == id)
         break;

      //check max number of items
      if (index0 == 0x40)
      {
         *error_code = 3;
         return 0;
      }
   }

   //check that operation id is initialized
   if (heap_item->operation_id == -1)
   {
      *error_code = 5;
      return 0;
   }

   //check that event id is initialized
   if (heap_item->SceSblSmsProxy_event_uid == -1)
   {
      *error_code = 6;
      return 0;
   }

   //check that mutex id is initialized
   if (heap_item->SceSblSmsProxyWait_mutex_uid == -1)
   {
      *error_code = 7;
      return 0;
   }
   
   //return operation item
   *error_code = 0;
   return heap_item;
}

int get_full_data_block_invalidate_cache_997098(sysbase_shared_block_t *base, unsigned int block_index, void **invalidate_addr, unsigned int *invalidate_block_size)
{
   //check arguments
   if (!base || block_index > 7 || !invalidate_addr || !invalidate_block_size )
      return 0x800F0416;

   //fetch block from continuous array of blocks
   *invalidate_addr = &base[block_index];
   *invalidate_block_size = 0x80;
   SceCpuForDriver_sceKernelCpuDcacheAndL2InvalidateMVACRange_1ForDriver_02796361(*invalidate_addr, 0x80u);
   return 0;
}

int get_full_data_block_invalidate_cache_9970C4(int block_index, void **invalidate_addr, unsigned int *invalidate_block_size)
{
   if(!g_008F5150.sysbase_block)
   {
      int res0 = proc_initialize_sysbase_related_list_items_996E0C();
      if(res0 < 0)
         return res0;
   }

   return get_full_data_block_invalidate_cache_997098(g_008F5130, block_index, invalidate_addr, invalidate_block_size);
}

int flush_block40_and_invalidate_from_shared_block_bank1_997100(void **invalidate_data_ptr, unsigned int *invalidate_size_ptr)
{
   if(!g_008F5150.sysbase_block)
   {
      int res0 = proc_initialize_sysbase_related_list_items_996E0C();
      if(res0 < 0)
         return res0;
   }

   SceCpuForDriver_sceKernelCpuDcacheAndL2InvalidateMVACRange_1ForDriver_02796361(g_008F5134, 0x80u);
   return get_full_data_block_invalidate_cache_997098(g_008F50A8, g_008F5134->block_index, invalidate_data_ptr, invalidate_size_ptr);
}

int data_block_write_back_maybe_remove_from_list_997144(sysbase_shared_block_t *block_base_ptr, unsigned int block_index)
{
   if (!g_008F5150.sysbase_block) 
      return 0x800F040C;

   if (!block_base_ptr || block_index > 7)
      return 0x800F0416;

   //get starting item pointer
   item_996E0C* root_item = &g_008F5138; //starting item - supposed to be for blocks 1
   if (block_base_ptr == g_008F5130) //blocks 0 - continuous array
      root_item = &g_008F5150; //starting item with blocks 0

   //get blocks bank pointer
   item_996E0C* bank_item = g_008F5028; //blocks 1 bank
   if (block_base_ptr == g_008F5130) //blocks 0 - continuous array
      bank_item = g_008F50B0; //blocks 0 bank

   SceCpuForDriver_sceKernelCpuDcacheAndL2CleanMVACRange_1ForDriver_103872a5(&block_base_ptr[block_index], 0x80u);

   item_996E0C* temp_item = root_item->item1;

   bank_item[block_index].item0 = root_item;
   root_item->item1 = &bank_item[block_index];

   bank_item[block_index].item1 = temp_item;
   temp_item->item0 = &bank_item[block_index];

   return 0;
}

int data_block_write_back_maybe_remove_from_list_restore_specific_cpu_state_9971C4(unsigned int block_index)
{
   SceCpuForDriver_sceKernelCpuLockStoreLRForDriver_bf82deb2(&g_008F501C.lock);
   int res = data_block_write_back_maybe_remove_from_list_997144(g_008F5130, block_index);
   
   //this assignment is very weird - does it overflow when cpuid > 1?
   int cpuid = SceCpuForDriver_sceKernelCpuGetCpuIdForDriver_5e4d5de1();
   sysbase_shared_block_t ** block_pp =  &g_008F5138.sysbase_block;
   int prev_state = *(int*)(block_pp + cpuid);

   SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F501C.lock, prev_state);
   return res;
}

int data_block_write_back_99704C(sysbase_shared_block_t *block_base_ptr, unsigned int block_index)
{
   if (!g_008F5150.sysbase_block) 
      return 0x800F040C;

   if (!block_base_ptr || block_index > 7)
      return 0x800F0416;

   SceCpuForDriver_sceKernelCpuDcacheAndL2CleanMVACRange_1ForDriver_103872a5(&block_base_ptr[block_index], 0x80u);
   return 0;
}

int data_block_write_back_997084(unsigned int block_index)
{
   return data_block_write_back_99704C(g_008F5130, block_index);
}

int cleanup_id_operation_996454(SmOperationId id)
{
   int error_code;
   shed_proxy_operation_item_t* op_item0 = get_operation_item_99600C(id, &error_code);
   
   if (op_item0)
   {
      if (op_item0->SceSblSmsProxy_event_uid != -1)
      {
         SceThreadmgrForDriver_sceKernelDeleteEventFlagForDriver_71ecb352(op_item0->SceSblSmsProxy_event_uid);
         op_item0->SceSblSmsProxy_event_uid = -1;
      }

      if (op_item0->SceSblSmsProxyWait_mutex_uid != -1)
      {
         SceThreadmgrForDriver_sceKernelDeleteMutexForDriver_0a912340(op_item0->SceSblSmsProxyWait_mutex_uid);
         op_item0->SceSblSmsProxyWait_mutex_uid = -1;
      }

      op_item0->operation_id = -1;
      op_item0->is_used = 0;
   }

   return 0;
}

//==========================================================================================================

int SceSblSmschedProxy_module_start_935cd196()
{
   SceKernelHeapCreateOpt opt;
   opt.size = 0x1C;
   opt.uselock = 1;
   
   g_008F5014 = SceSysmemForDriver_sceKernelCreateHeapForDriver_9328e0e8("SceSblSmschedProxy", 0x1000u, &opt);
   if (g_008F5014 < 0)
      return g_008F5014;

   g_008F5020 = (SceSblSmschedProxyHeap *)SceSysmemForDriver_sceKernelAllocHeapMemoryForDriver_7b4cb60a(g_008F5014, 0x1500u);
   if (g_008F5020 <= 0)
      return 0x800F040C;

   int heap_item_index = 0;
   do
   {
      g_008F5020->items[heap_item_index].is_used = 0;
      ++heap_item_index;
   }
   while (heap_item_index != 0x40);

   int res0 = cache_flush_shared_blocks_996F14();
   if (res0 < 0)
      return res0;

   int res1 = SceIntrmgrForDriver_sceKernelRegisterIntrHandlerForDriver_5c1feb29(INTR_CODE_SceSblSmSchedProxySGI, "SceSblSmSchedProxySGI", 0x10, (SceKernelIntrHandler *)proc_interrupt_handler_smc_13A_99608C, 0, 0x80, 0xF, 0);
   if (res1 < 0)
      return res1;
   
   int res2 = SceKernelSuspendForDriver_sceKernelSuspendRegisterCallbackForDriver_04c05d10("SceSblSmSchedProxy", proc_suspend_callback_9964B0, 0);
   if (res2 < 0)
      return res2;
   
   g_008F5018.lock = 0;
   g_008F5010.value = 1;

   return 0;
}

int SceSblSmSchedProxyForKernel_initialize_shed_proxy_a488d604()
{
  if (SceCpuForDriver_sceKernelCpuGetCpuIdForDriver_5e4d5de1())
    return 0;
  else
    return SceSblSmschedProxy_module_start_935cd196();
}

//==========================================================================================================

int SceSblSmSchedProxyForKernel_after_proxy_invoke_smc_138_8b84ac2a(SmOperationId id, int function_index, smc_138_callback *cb, int func_arg2)
{   
   ENTER_SYSCALL();

   if (g_008F5010.value != 1)
   {
      EXIT_SYSCALL();
      return 0x800F0426;
   }

   if(!cb)
   {
      EXIT_SYSCALL();
      return 0x800F0416;
   }

   if(function_index > 3)
   {
      EXIT_SYSCALL();
      return 0x800F0416;
   }

   int prev_state0 = SceCpuForDriver_sceKernelCpuLockSuspendIntrStoreLRForDriver_d32ace9e(&g_008F5018.lock);

   int error_code;
   shed_proxy_operation_item_t* op_item0 = get_operation_item_99600C(id, &error_code);
   if (!op_item0)
   {
      SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F5018.lock, prev_state0);
      EXIT_SYSCALL();
      return 0x800F042B;
   }

   shed_proxy_operation_callback_entry_t* cb_entry0 = &op_item0->functions[function_index];
   if (cb_entry0->cb)
   {
      SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F5018.lock, prev_state0);
      EXIT_SYSCALL();
      return 0x800F042E;
   }

   cb_entry0->cb = cb;
   cb_entry0->data.func_arg2 = func_arg2;

   int prev_func_arg4 = cb_entry0->data.func_arg4;
   int prev_func_arg3 = cb_entry0->data.func_arg3;

   cb_entry0->data.func_arg4 = 0;
   cb_entry0->data.func_arg3 = 0;

   SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F5018.lock, prev_state0);

   if (prev_func_arg3)
      cb(id, function_index, func_arg2, prev_func_arg3, prev_func_arg4);

   int res = proc_enter_SMC_996000((unsigned int)op_item0->maybe_status_secure_world_ptr, function_index, 0, 0, 0x138);
   EXIT_SYSCALL();
   return res;
}

int SceSblSmSchedProxyForKernel_not_implemented_1dfc8624()
{
   ENTER_SYSCALL();
   EXIT_SYSCALL();
   return 0x800F0425;
}

int SceSblSmSchedProxyForKernel_not_implemented_984ec9d1()
{
   ENTER_SYSCALL();
   EXIT_SYSCALL();
   return 0x800F0425;
}

int SceSblSmSchedProxyForKernel_smc_12D_sceSblSmSchedProxyInvokeForKernel_1916509b(int priority, void *sm_self_data_paddr, unsigned int num_pairs, sm_invoke_data_block_input *invoke_input, SceSblSmCommContext130 *ctx, SmOperationId *id)
{
   void *kp_msg_adr;
   
   ENTER_SYSCALL();

   if (g_008F5010.value == 1 )
   {
      if (id)
      {
         int prev_state0 = SceCpuForDriver_sceKernelCpuLockSuspendIntrStoreLRForDriver_d32ace9e(&g_008F5018.lock);
         int op_item_index0 = 0;
      
         shed_proxy_operation_item_t* op_item0;
         while (true)
         {
            op_item0 = &g_008F5020->items[op_item_index0];

            if ( !g_008F5020->items[op_item_index0].is_used )
               break;

            ++op_item_index0;

            if ( op_item_index0 == 0x40 )
            {
               SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F5018.lock, prev_state0);
               EXIT_SYSCALL();
               return 0x800F040C;
            }
         }

         SmOperationId id_internal = g_008F5000;
         op_item0->is_used = 1;                    // allocate new op item
         g_008F5000 = id_internal + 1;

         SceCpuForDriver_sceKernelCpuUnlockResumeIntrStoreLRForDriver_7bb9d5df(&g_008F5018.lock, prev_state0);

         int function_index = 0;
         op_item0->operation_id = id_internal;
         op_item0->maybe_status_secure_world_ptr = (void *)-1;

         //BOGUS!
         do
         {
            shed_proxy_operation_item_t* op_item0_part0 = (shed_proxy_operation_item_t *)((char *)op_item0 + 0x10 * function_index++);
            op_item0_part0->functions[0].cb = 0;
            op_item0_part0->functions[0].data.func_arg2 = 0;
            int * op_item0_part1 = &op_item0_part0->functions[0].data.func_arg2;
            op_item0_part1[1] = 0;
            op_item0_part1[2] = 0;
         }
         while ( function_index != 4 );

         op_item0->SceSblSmsProxy_event_uid = -1;
         op_item0->SceSblSmsProxyWait_mutex_uid = -1;

         SceUID event_uid = SceThreadmgrForDriver_sceKernelCreateEventFlagForDriver_4336baa4("SceSblSmsProxy", 0, 0, 0);

         SceUID mutex_uid;
         if ( event_uid < 0 || (op_item0->SceSblSmsProxy_event_uid = event_uid, mutex_uid = SceThreadmgrForDriver_sceKernelCreateMutexForDriver_fbaa026e("SceSblSmsProxyWait", 0, 0, 0), mutex_uid < 0) )
         {
            cleanup_id_operation_996454(id_internal);
            EXIT_SYSCALL();
            return 0x800F040C;
         }

         op_item0->SceSblSmsProxyWait_mutex_uid = mutex_uid;

         if ( id_internal == -1 )
         {
            EXIT_SYSCALL();
            return 0x800F040C;
         }

         *id = id_internal;

         smc_12D_data_t* data_block_ptr0;
         unsigned int data_size;

         int block_index0 = get_partial_data_block_invalidate_cache_maybe_remove_from_list_996FCC(0x48u, (void **)&data_block_ptr0, &data_size);

         if ( block_index0 < 0 )
         {
            cleanup_id_operation_996454(id_internal);
            EXIT_SYSCALL();
            return block_index0;
         }

         smc_12D_data_t* data_block_ptr1 = data_block_ptr0;

         smc_12D_data_t* data_block_ptr2;
         if (invoke_input)
         {
            data_block_ptr2 = data_block_ptr0;
            data_block_ptr0->unk0 = invoke_input->unk0;
            data_block_ptr1->unk4 = invoke_input->unk4;
            data_block_ptr1->unk8 = invoke_input->unk8;
            data_block_ptr1->unkC = invoke_input->unkC;
         }
         else
         {
            data_block_ptr0->unk0 = 0;
            data_block_ptr2 = data_block_ptr1;
            data_block_ptr1->unk4 = 0;
            data_block_ptr1->unk8 = 0;
            data_block_ptr1->unkC = 0;
         }

         unsigned int self_type = ctx->self_type;

         int caller_caps0 = *(_DWORD *)ctx->caller_self_info.capability;
         int caller_caps1 = *(_DWORD *)&ctx->caller_self_info.capability[4];
         int caller_caps2 = *(_DWORD *)&ctx->caller_self_info.capability[8];
         int caller_caps3 = *(_DWORD *)&ctx->caller_self_info.capability[12];

         uint32_t pathId = ctx->pathId;
         SceUInt64 program_authority_id = ctx->caller_self_info.program_authority_id;
         int* caller_caps_res0 = (int *)data_block_ptr2->caller_capability;

         data_block_ptr2->invoke_operation_id = id_internal;
         data_block_ptr2->self_type = self_type;
         data_block_ptr2->pathId = pathId;
         data_block_ptr2->program_authority_id = program_authority_id;

         *caller_caps_res0 = caller_caps0;
         caller_caps_res0[1] = caller_caps1;
         caller_caps_res0[2] = caller_caps2;
         caller_caps_res0[3] = caller_caps3;

         int* caller_caps_res1 = (int *)&data_block_ptr2->caller_capability[16];
         int caller_caps5 = *(_DWORD *)&ctx->caller_self_info.capability[20];
         int caller_caps6 = *(_DWORD *)&ctx->caller_self_info.capability[24];
         int caller_caps7 = *(_DWORD *)&ctx->caller_self_info.capability[28];

         *caller_caps_res1 = *(_DWORD *)&ctx->caller_self_info.capability[16];
         caller_caps_res1[1] = caller_caps5;
         caller_caps_res1[2] = caller_caps6;
         caller_caps_res1[3] = caller_caps7;
         int res0 = data_block_write_back_997084(block_index0);

         if ( res0 < 0 )
         {
            data_block_write_back_maybe_remove_from_list_restore_specific_cpu_state_9971C4(block_index0);
            cleanup_id_operation_996454(id_internal);
            EXIT_SYSCALL();
            return res0;
         }
         else
         {
            int res1 = proc_enter_SMC_996000(priority, (unsigned int)sm_self_data_paddr, num_pairs, block_index0, 0x12D);
            int res2 = get_full_data_block_invalidate_cache_9970C4(block_index0, (void **)&data_block_ptr0, &data_size);

            if ( res2 >= 0 )
            {
               if ( data_size <= 0x47 )
                  SceDebugForDriver_sceKernelCpuPrintKernelPanicForDriver_391b5b74((kernel_message_ctx *)&msg_9978A4, kp_msg_adr);

               op_item0->maybe_status_secure_world_ptr = data_block_ptr0->maybe_status_secure_world_ptr;
               block_index0 = data_block_write_back_maybe_remove_from_list_restore_specific_cpu_state_9971C4(block_index0);

               if ( block_index0 >= 0 )
               {
                  EXIT_SYSCALL();
                  return res1;
               }

               cleanup_id_operation_996454(id_internal);
               EXIT_SYSCALL();
               return block_index0;
            }

            data_block_write_back_maybe_remove_from_list_restore_specific_cpu_state_9971C4(block_index0);
            cleanup_id_operation_996454(id_internal);
            EXIT_SYSCALL();
            return res2;
         }
      }
      else
      {
         EXIT_SYSCALL();
         return 0x800F0416;
      }
   }
   else
   {
      EXIT_SYSCALL();
      return 0x800F0426;
   }
}

int SceSblSmSchedProxyForKernel_smc_12E_sceSblSmSchedProxyWait_f35efc1a(SmOperationId id, int result[2])
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_12F_sceSblSmSchedProxyGetStatus_27eb92f1(SmOperationId id, int status[2])
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_130_de4eac3c(SmOperationId id)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_133_sceSblSmSchedCallFunc_723b382f(SmOperationId id, int f00d_cmd_fifo_idx, SceSblSmschedCallFuncCommand *cmd_paddr)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_134_f70c04ec(SmOperationId id, int smcArg1, int *result)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_135_3ce17233(SmOperationId id, int smcArg1, int smcArg2)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_136_15b0e4df(SmOperationId id, int num_or_index, int res_from_smc0x137)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_137_973a4a7d(SmOperationId id, int num, int *result)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_139_85eda5fc(SmOperationId id, int smcArg1)
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_13B_uninitialize_shed_proxy_33a3a1e2()
{
   //TODO: not reversed
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_13C_7894b6f0(int smcArg0, int smcArg1, int smcArg2, int smcArg3)
{
   //TODO: not reversed
   return 0;
}

//==========================================================================================================

//old api

int SceSblSmSchedProxyForKernel_smc_12D_1916509b(int smcArg0, int smcArg1, int smcArg2, input_1916509b* unk3)
{
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_133_723b382f(smc_133_input* vaddr, int smcArg1_num, smc_133_input* smcArg2_paddr)
{
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_138_8b84ac2a(input_8b84ac2a* basePtr, int smcArg1_funcArg1, func_8b84ac2a* func, int funcArg2)
{
   return 0;
}

int SceSblSmSchedProxyForKernel_smc_12E_f35efc1a(input_f35efc1a* ptr, output_f35efc1a* result)
{
   return 0;
}