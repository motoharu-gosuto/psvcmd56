#include <string>

#include "SceIofilemgr.h"

#include "Constants.h"
#include "SceSysmemGlobalVariables.h"
#include "SceCpu.h"
#include "SceThreadmgr.h"
#include "SceSysmem.h"

int SceDebugForDriver_02b04343(int r0, int* r1, char* r2, int r3)
{
   return 0;
}

//==========================

SceUID get_SceIoVfsHeap_id()
{
   //dereference 0x99C0D8
   return 0;
}

//==========================

//0x99D9D4
typedef struct ctx_19D4 //size is 0x1C
{
   char* unk_0; 
   uint32_t unk_4;
   vfs_node* offset;
   uint32_t size;

   uint32_t count;
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;
}ctx_19D4;

//initializes arrays
int sub_BF3350(ctx_19D4 *buffer, int count, vfs_node* offset1, int size, char* offset2)
{
   if(size == 0)
      return -1;

   buffer->unk_0 = 0;
   buffer->unk_4 = 0;
   buffer->offset = offset1;
   buffer->size = size;
   buffer->count = count;

   int cur_idx = count - 1;

   if(cur_idx < 0)
      return 0;

   vfs_node* array1 = cur_idx * size + offset1;

   char* array2 = offset2 + (count * 8);   

   while(true)
   {
      //array2[-4] = array1;

      while(true)
      {
         //array2[-4] = buffer->unk_0;

         //DMB.W           SY

         buffer->unk_0 = array2 + 4;

         int success = 0; //success immitation

         if(success == 0)
            break;
      }

      cur_idx = cur_idx - 1;

      array1 = array1 - size;

      array2 = array2 + 4;

      if(cur_idx < 0)
         break;
   }

   return 0;
}


//-------------------------------

int sub_BECE80(void* a0)
{
   return 0;
}

int sub_BEC808(char* filesystem)
{
   return 0;
}

int sub_BE5814(vfs_node* a0)
{
   return 0;
}

int SceIofilemgrForDriver_6b3ca9f7(uint32_t* a0)
{
   return 0;
}

int SceIofilemgrForDriver_dc2d8bce(uint32_t* a0)
{
   return 0;
}

int sub_BEC578(vfs_mount* a0, vfs_mount* a1)
{
   return 0;
}

int sub_BEC620(vfs_mount* a0)
{
   return 0;
}

int sub_BEC010(vfs_mount* a0)
{
   return 0;
}

//alloc
void* sub_BECE0C()
{
   return 0;
}

int sub_BE62E8(char* mount, void* a1, uint32_t* a2, uint32_t* a3, int a4)
{
   return 0;
}

int proc_find_vfs_node_BE6788(void* unk0, int unk1, vfs_node** vnode, void* unk3, int unk4)
{
   return 0;
}

int sub_BE5F10(vfs_node* a0, void* a1, void* a2, int a3, vfs_node** a4)
{
   return 0;
}

int sub_BEE364(vfs_node* a0)
{
   return 0;
}

int sub_BEE3C8(vfs_node* n0)
{
   return 0;
}

vfs_mount* g_99D9D0;

vfs_mount* proc_get_arg0_for_sceVfsGetNewNode_BEBAC0()
{
   int prev_state1 = SceCpuForDriver_ksceKernelCpuSuspendIntr_d32ace9e((int*)0x99DA44);

   if(g_99D9D0 == 0)
   {
      SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99DA44, prev_state1);
      return 0;
   }

   vfs_mount* mount_node = g_99D9D0;

   g_99D9D0 = mount_node->unk_78;

   SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99DA44, prev_state1);

   mount_node->fd_lock_ptr = &mount_node->fd_lock; //C8
   
   SceUID mutex_id = SceThreadmgrForDriver_ksceKernelCreateMutex_fbaa026e("SceVfsFdLock", 0, 0, 0);

   if(mutex_id >= 0)
   {
      mount_node->fd_lock.mutex_SceVfsFdLock = mutex_id; // D0

      SceUID cond_id = SceThreadmgrForDriver_sceKernelCreateCondForDriver_db6cd34a("SceVfsFdCond", 0, mutex_id, 0);

      if(cond_id >= 0)
      {
         mount_node->fd_lock.cond_SceVfsFdCond = cond_id; // 4
         mount_node->fd_lock.unk_8 = 0;
         mount_node->fd_lock.unk_C = 0;

         mount_node->unk_CC = &mount_node->unk_E0;

         return mount_node;
      }
      else
      {
         SceThreadmgrForDriver_sceKernelDeleteMutexForKernel_0a912340(mount_node->fd_lock.mutex_SceVfsFdLock);
         mount_node->fd_lock.mutex_SceVfsFdLock = -1;
      }
   }

   int prev_state2 = SceCpuForDriver_ksceKernelCpuSuspendIntr_d32ace9e((int*)0x99DA44);

   if(g_99D9D0 != 0)
   {
      mount_node->unk_78 = g_99D9D0;
   }

   g_99D9D0 = mount_node;
   
   SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99DA44, prev_state2);

   return 0;
}

int proc_init_SceVfsMnt_BEBB84(vfs_mount* arg0, vfs_node* arg1, SceUID heapid, vfs_add_data* arg3)
{
   int r0 = SceThreadmgrForDriver_ksceKernelInitializeFastMutex_af8e1266(&arg0->fast_mutex_SceVfsMnt, "SceVfsMnt", 2, 0);

   arg0->pool = heapid; // 44
   
   arg0->add_data = arg3; // 5C

   arg0->unk_60 = 1;

   arg0->unk_54 = 0;
   arg0->unk_58 = 0;

   arg0->unk_64 = 0;
   arg0->unk_68 = 0;
   arg0->unk_6C = 0;
   arg0->unk_70 = 0;
   arg0->unk_74 = 0;
   arg0->unk_78 = 0;
   arg0->blockDev = 0; // 7C

   memset(arg0->unixMount, 0, 0x40); //0x80

   arg0->unk_40 = arg1;

   if(arg1 != 0)
   {
      arg1->unk_78 = arg1->unk_78 | 0x4000;
      arg1->unk_58++;
   }

   arg0->unk_CC->unk_0 = 0;
   arg0->unk_CC->unk_4 = 0;

   arg0->unk_CC->unk_8 = 0x99C034;
   arg0->unk_CC->unk_C = 0x99C01C;

   return 0;
}

//links 2 nodes
void sub_BEC56C(vfs_mount* r0, vfs_mount* r1)
{
   vfs_mount* temp = r0->unk_70;
   if(temp != 0)
      r1->unk_74 = temp;
   r0->unk_70 = r1;
}

//--------

int sub_BEBD20(int r0)
{
   return 0;
}

int sub_BF2B50(int r0, int r1, vfs_node* r2, int r3)
{
   return 0;
}

int sub_BEBD70(vfs_node* input_node)
{
   vfs_node* r10 = input_node;
   
   if(input_node->unk_7C != 0)
   {
      sub_BEBD20(input_node->unk_7C);
   }

   if(input_node->unk_5C != 0)
   {
      if(input_node->node->unk_48 == 0x10)
      {
         sub_BF2B50(input_node->unk_5C, 0, input_node, input_node->unk_90);
      }
   }

   memset((char*)&input_node->ops, 0, 0x98); //set 0x98 bytes from offset 0x40

   int id0 = SceThreadmgrForDriver_sceKernelGetThreadIdForDriver_59d06540();

   if(id0 != r10->unk_4)
      return id0;
   
   r10->unk_8 = 0;

   int id1 = SceThreadmgrForDriver_sceKernelGetThreadIdForDriver_59d06540();

   if(id1 != r10->unk_4)
      return id1;

   if(r10->unk_8 != 0)
   {
      r10->unk_8--;
      return id1;
   }
   
   if(r10->unk_0 == 0)
   {
      int r6 = r10->unk_0;
      int r7 = r10->unk_4;
      
      //DMB.W SY

      while(true)
      {
         if(r7 != r10->unk_4)
            break;

         if(r6 != r10->unk_0)
            break;

         r10->unk_0 = 0;
         r10->unk_4 = -1;

         int r3 = 0; //immitation of STREXD.W success

         if(r3 != 0)
            continue;
         else
            return id1;
      }
   }

   r10->unk_4 = 0xFFFFFFFD;

   return SceThreadmgrForDriver_ksceKernelSetEventFlag_d4780c3e(r10->event_flag_SceVfsVnode, r10->evid_bits);
}

int sub_BED838(int r0)
{
   return 0;
}

//calculates offset
int proc_findNode_BE9504(vfs_mount* r0, vfs_node** r1)
{
   /*
   int r7 = *99D96C;
   int r0 = 99D9D4;
   int r3 = r0[0x8];
   int r6 = r0[0xC];
   int r11 = r6 * r7 + r3;
   return r11;
   */
   
   return 0;
}

vfs_node* sub_BF33A0(ctx_19D4* r0)
{
   return 0;
}

int get_99DA40()
{
   //*(0x99DA40)
   return 0;
}

int* get_99DA40_ptr()
{
   //0x99DA40
   return 0;
}

int get_99C024()
{
   //*(0x99C024);
   return 0;
}

ctx_19D4* get_0x99D9D4_ptr()
{
   //0x99D9D4
   return 0;
}

int* get_dword_BFD130_ptr()
{
   //&dword_BFD130
   return 0;
}

int nullsub_3(vfs_node* r0, int r1)
{
   return 0;
}

//--------

int SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(vfs_mount* cur_node, node_ops2* ops, int unused, vfs_node** node)
{
   int var_2C = var_009EA004;

   vfs_node* result = 0;

   SceUID node_pool = cur_node->pool;
   if(node_pool == 0)
      node_pool =  get_SceIoVfsHeap_id();

   int value;
   int cond;

   vfs_node* found_node;

   //loc_BED8BA:
   while(true)
   {
      value = get_99DA40();
      cond = get_99DA40();

      if(get_99DA40() < get_99C024())
      {
         //loc_BED900:

         value++;
      
         int atomic_xor_res = SceCpuForDriver_atomic_set_xor_cda96e81(get_99DA40_ptr(), cond, value);
      
         if(atomic_xor_res != cond)
         {
            continue;
         }
         else
         {
            result = sub_BF33A0(get_0x99D9D4_ptr());
         }
      }

      found_node = result;
      if(found_node == 0)
      {
         int r0 = proc_findNode_BE9504(cur_node, &result); //further finds a node
         if(r0 < 0)
         {
            int r11 = sub_BED838(get_99C024());
            if(r11 == 0)
            {
               continue;
            }
            else
            {
               SceDebugForDriver_02b04343(0xF, get_dword_BFD130_ptr(), "::0x10f::001::%d\n", get_99DA40());

               if(var_2C == var_009EA004)
                  return r11;
               else
                  return STACK_CHECK_FAIL;
            }
         }
         else
         {
            //loc_BED9AA:
            sub_BEBD70(result);
            found_node = result;
         }
      }

      //loc_BED930:
      if(found_node->unk_74 != 0)
      {
         //loc_BED99C:

         nullsub_3(found_node, 1);
         
         break;
      }
      else
      {
         break;
      }
   }

   //loc_BED936:
   
   memset((char*)&found_node->ops, 0, 0x98); //set to 0 begginning from offset 0x40

   found_node->unk_74 = 0x8000;

   result->unk_D0 = cur_node->devMajor.w.unk_4E;
   result->ops = ops;
   
   result->node = cur_node;
   result->unk_58++;
   result->pool_uid = node_pool;
   
   SceIofilemgrForDriver_6b3ca9f7(&cur_node->fast_mutex_SceVfsMnt);

   result->unk_54 = 0;

   if(cur_node->unk_54 != 0)
      result->unk_54 = cur_node->unk_54;

   cur_node->unk_54 = result;
   
   cur_node->unk_58++; //counter
   
   SceIofilemgrForDriver_dc2d8bce(&cur_node->fast_mutex_SceVfsMnt);
   
   *node = result;
   
   if(var_2C == var_009EA004)
      return 0;
   else
      return STACK_CHECK_FAIL;
}

int SceIofilemgrForDriver_21d57633(vfs_node* a0)
{
   return 0;
}

//searches some tree
int sub_BE61C4(vfs_node_70* a0)
{
   return 0;
}

int sub_BE5A38(vfs_node_70* a0, int a1)
{
   return 0;
}

int sub_BEE2C4()
{
   return 0;
}

int sub_BEE2D4()
{
   return 0;
}

int sub_BEDEB0(uint32_t* a0, int a1, vfs_node* a2, int a3)
{
   // proc_find_vfs_node_info_node_BEDA18

   return 0;
}

int SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(vfs_node* a0)
{
   return 0;
}

int sub_BE59BC(vfs_node* a0, void* a1)
{
   return 0;
}

int sub_BEDF5C(uint32_t* a0, int a1)
{

   //proc_find_vfs_node_info_node_BEDA18

   return 0;
}

int sub_BE5B30(vfs_node* a0, vfs_node* a1, void* a2, int a3, int a4)
{
   a0->node->add_data->funcs1->func13(0); // call func 13   

   return 0;
}

int sub_BEBC1C()
{
   return 0;
}
    
int sub_BEC51C(vfs_mount* a0)
{
   return 0;
}
    
int sub_BEBC2C()
{
   return 0;
}

int sub_BF18CC(vfs_mount* a0, uint32_t* a1)
{
   return 0;
}

int sub_BEC530(vfs_mount* a0)
{
   return 0;
}

int SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(vfs_node* a0)
{
   return 0;
}

int vfs_func3_BF1AF0(vfs_mount *cur_node, int unk1, vfs_node *node)
{
   node_ops1* r3 = cur_node->add_data->funcs1; //5C then 0
   r3->func3(0);

   return 0;
}

vfs_add_data* proc_findVfsNodeByFilesystem_BEC7C0(char* filesystem)
{
   return 0;
}

//==========================

int loc_BE6C96(char* filesystem, int errorCode, void* unk3, void* var_D8, int cookie)
{
   sub_BECE80(unk3);
    
   sub_BECE80(var_D8);
    
   if(errorCode == 0)
   {
      if(cookie == var_009EA004)
         return 0;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
   else
   {
      sub_BEC808(filesystem);
   
      if(cookie == var_009EA004)
         return errorCode;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
}

int loc_BE7252(vfs_node* n0, char* filesystem, int errorCode, vfs_node* unk2, void* unk3, void* var_D8, int cookie)
{
   sub_BE5814(n0);
   
   if(unk2 == 0)
      return loc_BE6C96(filesystem, errorCode, unk3, var_D8, cookie);
    
   sub_BE5814(unk2);
   
   return loc_BE6C96(filesystem, errorCode, unk3, var_D8, cookie);
}

int loc_BE76C8(vfs_node* n0, vfs_mount* r7, char* filesystem, int errorCode, vfs_node* unk2, void* unk3, void* var_D8, int cookie)
{
   SceIofilemgrForDriver_6b3ca9f7(&n0->node->fast_mutex_SceVfsMnt); //4C mutex lock print

   n0->node->unk_60--; //counter
   
   sub_BEC578(n0->node, r7);
   
   SceIofilemgrForDriver_dc2d8bce(&n0->node->fast_mutex_SceVfsMnt); //4C mutex  unlock print

   sub_BEC620(r7);
   
   sub_BEC010(r7);
   
   return loc_BE7252(n0, filesystem, errorCode, unk2, unk3, var_D8, cookie);
}

//==========================

int loc_BE6AA2_default_case(char* filesystem, int cookie)
{
   sub_BEC808(filesystem);
   
   if(cookie == var_009EA004)
      return 0x80010016;
   else
      return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
}

//==========================

//TODO:
//3 - fix function signatures in ida after clarification
//4 - fix locals, especially 'node' which is located on stack - arrange fields properly

//----------
//also procedure BEC56C is used to link two items of same type together

//this means that bnode and n0->node are of same type which is different from vfs_node

//----------

//explanation to type derivation 2
//based on BEC56C code we can derive that there should be fields unk_70 and unk_74 in vfs_node_base which are also of type vfs_node_base
//based on calls sub_BE5A38(n0->unk_70, 1); and sub_BE5A38(vnode->unk_70, 0);
//we can derive that n0->unk_70 has same type as vnode->unk_70 and most likely n0 is same type as vnode

//we can derive that unk2 and n0 are of same type vfs_root
//int result1 = proc_find_vfs_node_BE6788(unk0, unk1 - 1, &unk2, unk3, 0x3000);
//int result2 = proc_find_vfs_node_BE6788(unk0, unk1, &n0, unk3, 0x3000);

//there is also one important assignment:
//vnode->unk_4C = bnode; 
//vnode->unk_50 = unk2;

//it could be usefull to revisit and list global variable
//0x01A8 - array of 96 elements of vfs_node_info 
//used by proc_find_vfs_node_info_node_BEDA18 <- proc_find_vfs_node_BEDF04 <- proc_find_vfs_node_BE584C <- proc_find_vfs_node_BE6788 - used by mount

//NOT EXACTLY SURE IF vfs_node* prev_node; in vfs_node should be vfs_node or vfs_node_base
//currently derrivation is based on the fact that unk2 type is same as n0 type (see above)

//--------------

//TODO:
//check:
//sub_BE4DE4 - SceIofileFlockWaitQueue event flag, SceIofileFlockLock mutex
//proc_SceIoSchedulerDispatcher_BF651C - SceIoSchedulerDispatcher mutex and flag
//sceVfsGetNewNode_BEBAC0 - SceVfsFdLock, SceVfsFdCond
//sub_BED694 - SceVfsFdLock, SceVfsFdCond
//proc_SceIoScheduler_BF8728 - SceIoScheduler mutex and cond and flag

//reverse:
//sub_BEDEB0
//sub_BEDF5C

//sub_BEC808 - ?
//sub_BEC578 - ?

//check:
//vfs functions - that they are passing vfs_node and not vfs_mount

//--------------

//loc_BE6C50 - jumptable 00BE6A86 case 1
int mount_switch_case_1(vfs_mount_point_info_base *mountInfo, vfs_add_data* addData, int cookie)
{
   uint32_t majorIndex = (0x000000FF & mountInfo->devMajor);
   if(majorIndex != 0x03)
   return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

   void* unk3 = sub_BECE0C(); //alloc memory
   
   if(unk3 == 0)
   {
      sub_BEC808(mountInfo->filesystem);
   
      if(cookie == var_009EA004)
         return 0x8001000C;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }

   void* var_D8 = sub_BECE0C(); //alloc memory
    
   if(var_D8 == 0)
   {
      sub_BECE80(unk3);
   
      sub_BEC808(mountInfo->filesystem);
   
      if(cookie == var_009EA004)
         return 0x8001000C;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }

   uint32_t* unk0;
   uint32_t unk1;
   uint32_t str1;
    
   unk0 = &str1;

   int result0 = sub_BE62E8(mountInfo->unk_4, unk3, unk0, &unk1, 0x01);

   if(result0 < 0)
      return loc_BE6C96(mountInfo->filesystem, result0, unk3, var_D8, cookie);

   if(unk1 == 0)
      return loc_BE6C96(mountInfo->filesystem, result0, unk3, var_D8, cookie);

//loc_BE71B0:

    vfs_node* unk2;
    
    void* var_D4 = unk0 + ((unk1 - 1) << 3);

    int result1 = proc_find_vfs_node_BE6788(unk0, unk1 - 1, &unk2, unk3, 0x3000);

    vfs_node* n0;

    if(result1 < 0)
    {
        if(result1 != 0x80010002)
            return loc_BE6C96(mountInfo->filesystem, result1, unk3, var_D8, cookie);

        int result2 = proc_find_vfs_node_BE6788(unk0, unk1, &n0, unk3, 0x3000);
        if(result2 < 0)
            return loc_BE6C96(mountInfo->filesystem, result2, unk3, var_D8, cookie);
            
        unk2 = 0;
    }
    else
    {   
        int result2 = sub_BE5F10(unk2, var_D4, unk3, 0x3000, &n0);
        if(result2 < 0)
        {
           if(unk2 == 0)
               return loc_BE6C96(mountInfo->filesystem, result2, unk3, var_D8, cookie);
    
           sub_BE5814(unk2);
   
           return loc_BE6C96(mountInfo->filesystem, result2, unk3, var_D8, cookie);
        }
    }

//loc_BE71F6:    
    
   if(n0->node->devMajor.b.unk_4C == 3) 
      return loc_BE7252(n0, mountInfo->filesystem, 0x80010010, unk2, unk3, var_D8, cookie);
    
   if((mountInfo->devMinor & 0x1000) == 0)
   {
      //loc_BE7446:
      int result3 = sub_BEE364(n0);
      
      if(result3 < 0)
      {
         if(result3 != 0x800F090D && result3 != 0x8001000D)
            return loc_BE7252(n0, mountInfo->filesystem, result3, unk2, unk3, var_D8, cookie);
         else
            return loc_BE7252(n0, mountInfo->filesystem, 0x8001001E, unk2, unk3, var_D8, cookie);
      }

      if((n0->node->devMinor << 0x13) < 0)
         return loc_BE7252(n0, mountInfo->filesystem, 0x8001001E, unk2, unk3, var_D8, cookie);
   }
   else
   {
      int result3 = sub_BEE3C8(n0);
      if(result3 < 0)
         return loc_BE7252(n0, mountInfo->filesystem, result3, unk2, unk3, var_D8, cookie);
   }
    
   //loc_BE7216:
    
   uint32_t var_28;

   void* r2 = (&var_28) + ((unk1 - 1) << 3);
    
   uint32_t node; // = r2[-0x84];   // D0 - 84 = 4C - can be part of vfs_node ?
   uint32_t var_B8; // = r2[-0x80]; // D0 - 80 = 50 - can be part of vfs_node ?

   void* var_B4 = unk3;
    
   int result4 = sub_BE62E8(mountInfo->unixMount, var_D8, unk0, &unk1, 0x01);
   if(result4 < 0)
      return loc_BE7252(n0, mountInfo->filesystem, result4, unk2, unk3, var_D8, cookie);
        
   int r3 = unk1;
   if(r3 == 0)
      return loc_BE7252(n0, mountInfo->filesystem, result4, unk2, unk3, var_D8, cookie);
        
//loc_BE74F4:        
   vfs_mount* bnode = proc_get_arg0_for_sceVfsGetNewNode_BEBAC0();
   if(bnode == 0)
      return loc_BE7252(n0, mountInfo->filesystem, 0x8001000C, unk2, unk3, var_D8, cookie);    

   proc_init_SceVfsMnt_BEBB84(bnode, n0, get_SceIoVfsHeap_id(), addData); // important initialization function
  
   bnode->blockDev = mountInfo->blockDev1;
    
   strncpy(bnode->unixMount, (char*)var_D8, 0x40); //it should be string since it is terminated with 0 explicitly

   bnode->unixMount[0x3F] = (char)0; //terminate with 0

   bnode->unk_C4 = mountInfo->unk_14;

   bnode->devMajor.dw.unk_4C = mountInfo->devMajor; //0x4C 
   bnode->devMinor = (mountInfo->devMinor & 0xFFFFF); //0x50 - take first 0x14 bits

   bnode->unk_48 = 0x101; //0x48    
    
   SceIofilemgrForDriver_6b3ca9f7(&n0->node->fast_mutex_SceVfsMnt); //0x4C mutex lock print
   
   n0->node->unk_60++; //counter
    
   sub_BEC56C(n0->node, bnode); //link
    
   SceIofilemgrForDriver_dc2d8bce(&n0->node->fast_mutex_SceVfsMnt); //0x4C mutex unlock print
    
   bnode->devMajor.w.unk_4C = bnode->devMajor.w.unk_4C | (n0->node->devMajor.w.unk_4E << 16);
    
   vfs_add_data* r6 = addData;

   node_ops2* ops2 = mountInfo->unk_1C == 0 ? addData->funcs2 : mountInfo->unk_1C;

   vfs_node* vnode;

//loc_BE7576:    
   int result5 = SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(bnode, ops2, 0, &vnode);
   if(result5 < 0)
      return loc_BE76C8(n0, bnode, mountInfo->filesystem, result5, unk2, unk3, var_D8, cookie);
    
   if((bnode->devMinor << 0x0E) < 0) //50
   {
      if((bnode->devMajor.w.unk_4E & 0xF00) != 0x200)
      {
         bnode->devMinor = bnode->devMinor & (~0x20000); //50
      }
   }
    
//loc_BE75A4:    
    
   if((n0->node->devMinor << 0x0E) < 0) //4C 50
   {
      if((n0->node->devMajor.w.unk_4E & 0xF00) == 0x200)
      {
         //this code proves that 'bnode' and 'node' have same type

         bnode->unk_CC->unk_8 = n0->node->unk_CC->unk_8;
         bnode->unk_CC->unk_C = n0->node->unk_CC->unk_C;
         bnode->devMinor = bnode->devMinor | 0x20000; //50
      }
   }
    
//loc_BE75D4:   
    
   //important assignment of nodes
   vnode->node = bnode; //4C
   vnode->prev_node = unk2; //50
    
   vnode->unk_78 = 0x1002;
 
   if(n0->unk_70 != 0)
   {
      int result6 = sub_BE61C4(n0->unk_70);
      if(result6 < 0)
      {
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result6, unk2, unk3, var_D8, cookie);
      }
            
      sub_BE5A38(n0->unk_70, 1);
   }
 
//loc_BE75FA:    

   sub_BEE2C4(); //lock SceVfsRfsLock
    
   if(n0->unk_70 != 0)
   {
      int result7 = sub_BE61C4(n0->unk_70);
      if(result7 < 0)
      {
         sub_BEE2D4(); //unlock SceVfsRfsLock
    
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result7, unk2, unk3, var_D8, cookie);
      }
   }
   
//loc_BE760E:

   int result8 = sub_BEDEB0(unk0, unk1, vnode, 0xD8);
    
   sub_BEE2D4(); //unlock SceVfsRfsLock
    
   if(result8 < 0)
   {
      SceIofilemgrForDriver_21d57633(vnode);
      return loc_BE76C8(n0, bnode, mountInfo->filesystem, result8, unk2, unk3, var_D8, cookie);
   }

   SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(vnode);
     
   if(unk2 == 0)
   {
      //loc_BE79F4:
      
      int result9 = sub_BE59BC(vnode, var_D4);
      if(result9 < 0)
      {
         sub_BEE2C4(); //lock SceVfsRfsLock
    
         sub_BEDF5C(unk0, unk1);

         sub_BEE2D4(); //unlock SceVfsRfsLock
    
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result9, unk2, unk3, var_D8, cookie);
      }
   }
   else
   {
      int result9 = sub_BE5B30(unk2, vnode, var_D4, 1, 1);
      if(result9 < 0)
      {
         sub_BEE2C4(); //lock SceVfsRfsLock
    
         sub_BEDF5C(unk0, unk1);

         sub_BEE2D4(); //unlock SceVfsRfsLock
    
         SceIofilemgrForDriver_21d57633(vnode);
         return loc_BE76C8(n0, bnode, mountInfo->filesystem, result9, unk2, unk3, var_D8, cookie);
      }
   }
    
//loc_BE7646:    

    sub_BEBC1C(); //lock SceVfsMntlistLock
    
    sub_BEC51C(bnode);
    
    sub_BEBC2C(); //unlock SceVfsMntlistLock
       
    int result10 = sub_BF18CC(bnode, &node);
    if(result10 != 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(bnode);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode->unk_70, 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, bnode, mountInfo->filesystem, result10, unk2, unk3, var_D8, cookie);
    }
    
    int result11 = vfs_func3_BF1AF0(bnode, 0, vnode);
    if(result11 < 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(bnode);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode->unk_70, 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, bnode, mountInfo->filesystem, result11, unk2, unk3, var_D8, cookie);
    }
    
    SceIofilemgrForDriver_6b3ca9f7(&bnode->fast_mutex_SceVfsMnt); //print lock
    
    bnode->unk_48 = bnode->unk_48 & (~0x100); //0x48
    bnode->unk_60--; //counter - one of fields that can identify type by logic
    
    SceIofilemgrForDriver_dc2d8bce(&bnode->fast_mutex_SceVfsMnt); //print unlock
    
    vnode->unk_58 = vnode->unk_58 -1; //counter - one of fields that can identify type by logic
    
    SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(vnode);
   
    return loc_BE7252(n0, mountInfo->filesystem, result11, unk2, unk3, var_D8, cookie);
}

//==========================

//loc_BE6A96 - jumptable 00BE6A86 case 2
int mount_switch_case_2(vfs_mount_point_info_base *mountInfo, int cookie)
{
    uint32_t majorIndex = (0x000000FF & mountInfo->devMajor) - 1;
    
    if(majorIndex > 0x01)
       return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

    return -1; //not implemented
}

//==========================

//loc_BE6CAA - jumptable 00BE6A86 case 3
int mount_switch_case_3(vfs_mount_point_info_base *mountInfo, vfs_add_data* addData, int cookie)
{
    int r3 = addData->unk_10;

    if(r3 != 0x10)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);
    
    return -1; //not implemented
}

//==========================

//loc_BE6D40 - jumptable 00BE6A86 case 4
int mount_switch_case_4(vfs_mount_point_info_base *mountInfo, int cookie)
{
    if(mountInfo->unk_4 == 0x00)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

   if(cookie == var_009EA004)
      return 0;
   else
      return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
}

//==========================

//loc_BE6D4C - case 5
int mount_switch_case_5(vfs_mount_point_info_base *mountInfo, int cookie)
{
    uint32_t majorIndex = (0x000000FF & mountInfo->devMajor) - 1;

    if(majorIndex > 0x01)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);

    if(mountInfo->unk_4 == 0x00)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);
    
    return -1; //not implemented
}

//==========================

//loc_BE6AC2 - case 6
int mount_switch_case_6(vfs_mount_point_info_base *mountInfo, int cookie)
{
    uint32_t majorIndex = (0x000000FF & mountInfo->devMajor);
    if(majorIndex != 0x04)
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie);
    
    return -1; //not implemented
}

//==========================

int sceVfsMount(vfs_mount_point_info_base *mountInfo)
{
    int cookie = var_009EA004;

    if(mountInfo == 0x00) //compare input pointer to 0
    {
      if(cookie == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    if(mountInfo->unixMount == 0x00) //compare unixMount pointer to 0
    {
      if(cookie == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    vfs_add_data* addData = proc_findVfsNodeByFilesystem_BEC7C0(mountInfo->filesystem);
    
    if(addData == 0x00) //compare node pointer to 0
    {
      if(cookie == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    int minorIndex = (0x000000FF & mountInfo->devMinor) - 1;
    
    switch(minorIndex)
    {
    case 0:
        return mount_switch_case_1(mountInfo, addData, cookie);
    case 1:
        return mount_switch_case_2(mountInfo, cookie);
    case 2:
        return mount_switch_case_3(mountInfo, addData, cookie);
    case 3:
        return mount_switch_case_4(mountInfo, cookie);
    case 4:
        return mount_switch_case_5(mountInfo, cookie);
    case 5:
        return mount_switch_case_6(mountInfo, cookie);
    default:
        return loc_BE6AA2_default_case(mountInfo->filesystem, cookie); //default case
    }
}

int proc_lock_SceVfsNcacheLock_mutex_BEBC58()
{
   return 0;
}

int proc_unlock_SceVfsNcacheLock_mutex_BEBC68()
{
   return 0;
}

int sub_BE5F94(vfs_node *node, char *dest, int length, int* result_length)
{
   if(length == 0)
      return 0x80010016;

   SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(node);
   
   proc_lock_SceVfsNcacheLock_mutex_BEBC58();
      
   vfs_node_70* ctx_70 = node->unk_70;

   if(ctx_70 == 0)
   {
      proc_unlock_SceVfsNcacheLock_mutex_BEBC68();
      SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(node);
      return 0x80010016;
   }
   
   if(length <= ctx_70->str_len_18)
   {
      strncpy(dest, ctx_70->str_1C, length);
      dest[length - 1] = 0; //terminate with zero
      *result_length = length - 1;
   }
   else
   {
      strncpy(dest, ctx_70->str_1C, ctx_70->str_len_18);
      dest[ctx_70->str_len_18] = 0; //terminate with zero
      *result_length = ctx_70->str_len_18;
   }

   proc_unlock_SceVfsNcacheLock_mutex_BEBC68();
   SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(node);
   return 0;
}

//get some string from node field 70
int SceIofilemgrForDriver_unk_aa253b68(vfs_node *node, char *dest, int length, int* result_length)
{
   return sub_BE5F94(node, dest, length, result_length);
}

void sub_BECFB4(vfs_mount* mount)
{
   mount->unk_CC->unk_4 = 1;
}

//generic callback function
typedef int (callback_99C050)(int unk0, int unk1, vfs_node* unk2, ...);

callback_99C050* var_99C050;

int loc_BF08FC(int r6, vfs_node_func15_arg2* r7, vfs_node* r10, int var_24)
{
   if(var_99C050 == 0)
   {
      if(var_24 == var_009EA004)
         return r6;
      else
         return STACK_CHECK_FAIL;
   }

   var_99C050(0x27, 6, r10, r6, r7->unk_0, r7->unk_4, r7->unk_C, r7->unk_8);

   if(var_24 == var_009EA004)
      return r6;
   else
      return STACK_CHECK_FAIL;
}

//most likely sceIoGetstatForDriver

int SceIofilemgrForDriver_vfs_node_func15_50a63acf(vfs_node *node, vfs_node_func15_arg1* unk0, vfs_node_func15_arg2* unk1)
{
   int var_24 = var_009EA004;
   
   if(var_99C050 != 0)
   {
      if(unk0->unk_8 == 0)
         var_99C050(0x26, 2, node, unk0->data);
      else
         var_99C050(0x26, 2, node, unk0->unk_8);
   }

   if(unk1 == 0)
   {
      if(var_99C050 == 0)
      {
         if(var_24 == var_009EA004)
            return 0x80010016;
         else
            return STACK_CHECK_FAIL;
      }

      var_99C050(0x27, 6, node, 0x80010016, 0, 0, 0, 0);

      if(var_24 == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL;
   }

   if(node->ops->func15 == 0)
      return loc_BF08FC(0x80010030, unk1, node, var_24);

   vfs_node_func15_args f15_args;
   f15_args.node = node;
   f15_args.arg1 = unk0;
   f15_args.arg2 = unk1;

   int f_result = node->ops->func15(&f15_args);

   sub_BECFB4(node->node);

   if(f_result != 0)
      return loc_BF08FC(f_result, unk1, node, var_24);

   if((unk1->unk_8 == node->unk_80) && (unk1->unk_C == node->unk_84))
      return loc_BF08FC(f_result, unk1, node, var_24);
            
   if(node->unk_5C == 0)
      return loc_BF08FC(f_result, unk1, node, var_24);

   if((node->node->devMinor << 0xD) >= 0)
      return loc_BF08FC(f_result, unk1, node, var_24);

   unk1->unk_8 = node->unk_80; //res
   unk1->unk_C = node->unk_84; //res

   return loc_BF08FC(f_result, unk1, node, var_24);
}

//this corresponds to sceIoPreadForDriver

int SceIofilemgrForDriver_vfs_node_func5_or_19_abbc80e3(vfs_node *n0, int unk1, char *buffer, SceSize size, int offsetLo, int offsetHi, int* readBytes)
{
   return 0;
}

typedef struct t_sceIoIoctlForDriver_ctx
{
   SceUID fd;
   unsigned int cmd;
   void *indata;
   int inlen;

   void *outdata;
   int outlen;
} t_sceIoIoctlForDriver_ctx;

int SceIofilemgrForDriver_t_sceIoIoctlForDriver_c1dd4317(t_sceIoIoctlForDriver_ctx* ctx)
{
   return 0;
}

int proc_BF651C(SceUID fd, void *outdata, int indataValue)
{
   //int var_40;
   int var_3C = indataValue;
   //int var_38;

   t_sceIoIoctlForDriver_ctx locals;

   int var_1C = var_009EA004; //cookie
   
   locals.fd = fd;
   locals.cmd = 0x201;
   locals.indata = &var_3C;
   locals.inlen = 0x4;
   locals.outdata = outdata;
   locals.outlen = 0xC;

   int result = SceIofilemgrForDriver_t_sceIoIoctlForDriver_c1dd4317(&locals);

   if(var_1C == var_009EA004)
      return result;
   else
      return STACK_CHECK_FAIL;
}

enum io_device_code
{
  Internal = 0x100,
  Game_Card = 0x201,
  Removable = 0x202,
  Host_File_System = 0x300,
  Default = 0x0
};

typedef struct io_context //size is 0xB8
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;
   
   uint16_t unk_10;
   uint16_t unk_12;
   uint16_t unk_14;
   uint16_t unk_16;
   void *data_0; //0x18
   uint32_t unk_1C;
   
   SceSize size_0; //0x20
   uint32_t io_op_index; // 0x24
   uint32_t ioctlOutdata0;
   io_device_code device_code; // 0x2C - ioctlOutdata1
   
   char async; //0x30
   char unk_31;
   char unk_32;
   char unk_33;
   uint32_t pid; //0x34 = ksceKernelGetProcessId
   uint32_t tid; //0x38 = ksceKernelGetThreadId
   uint32_t unk_3C; // = SceThreadmgrForDriver_fa54d49a
   
   uint32_t unk_40; // = SceThreadmgrForDriver_332e127c
   uint32_t cpu_mask; // 0x44 = ksceKernelGetThreadCpuAffinityMask
   uint32_t thread_priority; //0x48 = ksceKernelGetThreadCurrentPriority
   void* list0; //0x4C pointer to some linked list with elements of size 0x14 
   
   uint32_t listSize; //0x50 = number of items in linst
   void* list1; //0x54 = pointer to some linked list with elements of size 0x14 
   uint32_t sizeOfList; //0x58 = size of list in bytes
   uint16_t state; // 0x5C = bit 16 of state where state = (MRC p15, 0, state, c13, c0, 3)
   uint16_t unk_5E;
   
   uint32_t unk_60;
   SceUID fd; //0x64
   void *data_1; //0x68
   uint32_t unk_6C;
   
   SceSize size_1; //0x70
   uint32_t unk_74;
   uint32_t unk_78; // = -1
   uint32_t unk_7C; // = -1
   
   uint32_t op_result; // 0x80 - result of i/o operation
   uint32_t unk_84;
   void* unk_88;
   uint32_t unk_8C;
   
   uint32_t unk_90;
   uint32_t unk_94;
   uint32_t unk_98;
   uint32_t unk_9C;
   
   uint32_t unk_A0;
   uint32_t unk_A4;
   uint32_t unk_A8;
   uint32_t unk_AC;
   
   SceInt64 unk_B0; // = ksceKernelGetSystemTimeWide
   
}io_context;

typedef struct param_BFB2A8
{
   uint32_t unk_0;
   void* data;
   uint32_t ofst;
   uint32_t size;

}param_BFB2A8;

int SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(int stack, void* func, void* args)
{
   return 0;
}

struct sceIoPreadForDriver_args
{
  SceUID uid;
  void *data;
  int size;
  int dummy;
  SceOff offset;
};

int sub_BFB2A8(io_context *ioctx, param_BFB2A8* param)
{
   sceIoPreadForDriver_args args;

   int var_18;
   int var_14;

   var_14 = var_009EA004;

   args.uid = ioctx->fd; //64;
   
   if(param == 0)
   {
      args.data = 0;
      args.size = 0;

      args.offset = 0x0000008000000080;
   }
   else
   {
      int ofst_lo = ioctx->unk_78 + param->ofst;
      int ofst_hi = ioctx->unk_7C;
      
      args.data = param->data;
      args.size = param->size;

      args.offset = (ofst_hi << 32) | ofst_lo;
   }

   int dev = ioctx->device_code << 0xF;

   if(dev < 0)
   {
      int res = SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, (void*)0xBF7B3C, &args); //  int __cdecl SceIofilemgr.ScePfsFacadeForKernel._imp_4238d2d2(sceIoPreadForDriver_args *args)
      if(var_14 == var_009EA004)
         return res;
      else
         return STACK_CHECK_FAIL;
   }
   else
   {
      int res = SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, (void*)0xBE7D2D, &args); // int __cdecl SceIofilemgr.SceIofilemgrForDriver._exp_t_sceIoPreadForDriver_0b54f9e0(sceIoPreadForDriver_args *args)
      if(var_14 == var_009EA004)
         return res;
      else
         return STACK_CHECK_FAIL;
   }
}

int SceIofilemgrForDriver_sceIoGetstatForDriver_75c96d25(const char *file, SceIoStat *stat)
{
   return 0;
}

int SceIofilemgrForDriver_sceIoMountForDriver_d070bc48(int vshMountId, const char *path, int permission, int unk3, int arg_0, int arg_4)
{
   return 0;
}

int SceIofilemgrForDriver_sceIoMkdirForDriver_7f710b25(const char *dir, SceMode mode)
{
   return 0;
}

int SceIofilemgrForDriver_sceIoUmountForDriver_20574100(int vshMountId, int unk1, int unk2, int unk3)
{
   return 0;
}

struct callback_BEA5C4_args
{
  const char* drive;
};

int t_callback_BEA5C4(callback_BEA5C4_args* args)
{
   return 0;
}

SceUID SceIoScheduler_99D724;

int normalize_path_and_BF4F1C(const char *file, int normalize)
{
   if (!file)
      return 0x8001000E;

   if (strnlen(file, 0x400u) == 0x400)
      return 0x8001005B;

   const char* semicolon_pos = strchr(file, ':');
   if (semicolon_pos)
   {
      int drive_name_len0 = ((int)semicolon_pos - (int)file);
      if (drive_name_len0 > 0x1E )
         return 0;

      char drive_str[32];

      int drive_len = (int)semicolon_pos - (int)file + 1;
      strncpy(drive_str, file, drive_len);
      drive_str[31] = 0;

      if (!strncmp("sdstor0:", drive_str, 9u) )
      {
         if (SceSysrootForKernel_ksceSysrootIsSafeMode_834439a7() == 1 || SceSysrootForKernel_ksceSysrootIsUpdateMode_b0e1fc67() == 1)
            return 0;

         callback_BEA5C4_args args;
         args.drive = file;
         return SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, t_callback_BEA5C4, &args);
      }

      if (normalize != 1)
      {
         callback_BEA5C4_args args;
         args.drive = file;
         return SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, t_callback_BEA5C4, &args);
      }
      else
      {
         callback_BEA5C4_args args;
         args.drive = drive_str;
         return SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, t_callback_BEA5C4, &args);
      }
   }
   else
   {
      if (normalize != 1)
      {
         callback_BEA5C4_args args;
         args.drive = file;
         return SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, t_callback_BEA5C4, &args);
      }
      else
      {
         if (file[0] != '/' )
            return 0x80010016;

         const char* next_slash_pos = strchr(file + 1, '/');
         if (next_slash_pos == 0)
            return 0;

         char* args_alloc = (char*)SceSysmemForDriver_ksceKernelMemPoolAlloc_7b4cb60a(SceIoScheduler_99D724, 0x400u);
         
         if (args_alloc == 0)
            return 0x8001000C;

         int drive_name_len0 = (int)next_slash_pos - (int)file;
         strncpy(args_alloc, file, drive_name_len0);
         args_alloc[drive_name_len0] = 0;

         callback_BEA5C4_args args;
         args.drive = args_alloc;
         int res0 = SceThreadmgrForDriver_ksceKernelRunWithStack_e54fd746(0x2000, t_callback_BEA5C4, &args);
         SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceIoScheduler_99D724, args_alloc);
         return res0;
      }  
   }
}

SceUID SceIoVfsHeap_99C0D8;

char* buffers_99C16C[4];

char* proc_alloc_400_from_SceIoVfsHeap_BECE0C()
{
   int prev_state = SceCpuForDriver_ksceKernelCpuSuspendIntr_d32ace9e((int*)0x99D9F8);
   int counter = 0;
   
   do
   {
      char* static_buffer = buffers_99C16C[counter];
      if(static_buffer != 0)
      {
         buffers_99C16C[counter] = 0;
         SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99D9F8, prev_state);
         memset(static_buffer, 0, 0x400);
         return static_buffer;
      }
      else
      {
         counter++;
      }
   }
   while(counter != 4);

   SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99D9F8, prev_state);
   char* buffer = (char*)SceSysmemForDriver_ksceKernelMemPoolAlloc_7b4cb60a(SceIoVfsHeap_99C0D8, 0x400);
   if(buffer == 0)
      return 0;
            
   memset(buffer,0,0x400);
   return buffer;
}

void proc_free_400_from_SceIoVfsHeap_BECE80(char* buffer)
{
   int prev_state = SceCpuForDriver_ksceKernelCpuSuspendIntr_d32ace9e((int*)0x99D9F8);
   int counter = 0;

   do
   {
      char* static_buffer = buffers_99C16C[counter];
      if(static_buffer == 0)
      {
         buffers_99C16C[counter] = buffer;
         SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99D9F8, prev_state);
         return;
      }
      else
      {
         counter++;
      }
   }
   while(counter != 4);

   SceCpuForDriver_ksceKernelCpuResumeIntr_7bb9d5df((int*)0x99D9F8, prev_state);
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceIoVfsHeap_99C0D8, buffer);
}