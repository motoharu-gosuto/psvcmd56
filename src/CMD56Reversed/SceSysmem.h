#pragma once

#include <stdint.h>

#include "Constants.h"

struct input1_c8672a3d;

//arg0 is taken from func struct
//arg1 is initialized internally
typedef void(func_c8672a3d)(int arg_0, input1_c8672a3d* ctx, int arg_1, void* retAddr);

//arg0 is taken from func struct
//arg1 is passed by caller function
typedef void(func_571660aa)(int arg_0, input1_c8672a3d* ctx, int arg_1, void* retAddr);

struct unk_14_pair_0
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
};

struct result_c8672a3d_14_pair
{
   unk_14_pair_0* unk_0;
   int unk_4;
};

struct result_c8672a3d;

struct result_c8672a3d_10_unk
{
   result_c8672a3d* unk_0;
   result_c8672a3d* unk_4;
   int lockable_8;
   int unk_C;
};

struct result_c8672a3d
{
   result_c8672a3d* unk_00; //linked list prev ?
   result_c8672a3d* unk_04; //linked list next ?
   int unk_08;
   int unk_0C;
   result_c8672a3d_10_unk* unk_10;
   result_c8672a3d_14_pair* unk_14; //used
   int unk_18;
   int unk_1C;
   int unk_20; //used - flags?
   int unk_24;
   int* unk_28;
   int lockable_int_2C;
   
   int gxor_30; //(((int)&g_008FE000) | 0x01)
   SceUID eventFlagUid_34;
   short unk_38; //some flag ?
   short unk_3A;
   int unk_3C;   
};

struct func_pair_c8672a3d
{
   int arg_0; //first argument to function
   func_c8672a3d* func_4; //pointer to some function
   func_571660aa* func_8; // function pointer
};

typedef void(func2_c8672a3d)(int* unk0, int unk1);

typedef void(func3_c8672a3d)(input1_c8672a3d* unk0, int unk1, int unk2);

struct input2_c8672a3d
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
   func2_c8672a3d* unk_34; //used
   int unk_38;
};

//it looks like this structure may have an array in the beginning
//array is per CPU ID - meaning that there are 4 elements
//size of each element is 0x10

//however this does not match with overall layout of the structure
struct input1_c8672a3d
{
   int unk_0;
   input2_c8672a3d* unk_4;
   int unk_8;
   int* unk_C; //used is this result_c8672a3d ?

   int unk_10; //used
   int unk_14;
   int unk_18; //used
   int unk_1C; //used

   short unk_20; //used
   short unk_22; //used
   short unk_24; //used
   short unk_26; //used

   int lockable_int_28;
   int unk_2C;

   int unk_30; //used
   int unk_34; //used
   void* unk_38; //used
   int unk_3C; //used

   int* unk_40; //used
   short unk_44; //used
   short unk_46; //used
   int unk_48;
   int unk_4C; //used

   void* unk_50; //used
   int unk_54;
   int unk_58; //used
   int unk_5C;

   int unk_60;
   int unk_64;
   int unk_68;
   int unk_6C;

   int unk_70;
   int unk_74;
   int unk_78;
   int unk_7C;

   int unk_80;
   int unk_84;
   int unk_88;
   int unk_8C;

   int unk_90;
   int unk_94;
   int unk_98;
   func_pair_c8672a3d* unk_9C; //used

   int unk_A0;
};

//number of args confirmed
//return type confirmed

//it looks like this function is some wrapper to a functor
//but it does other functionality as well
result_c8672a3d* SceSysmemForKernel_functor_c8672a3d(input1_c8672a3d* ctx);

//-------------------------------------

//number of args confirmed
//return type confirmed

//this function returns 0
//it looks like this function is some wrapper to a functor
//but it does other functionality as well
int SceSysmemForKernel_functor_571660aa(input1_c8672a3d* ctx, result_c8672a3d* arg_1);

//-------------------------------------

//this looks like wrapper of these functions: __aeabi_uidiv, __aeabi_uidivmod
//numerator can have 0xF bits at max
//denominator is taken internally
//result of devision is likely to be returned
int SceSysmemForDriver_udiv_e655852f(unsigned int numerator_div2);

//------------------------

typedef int SceKernelMemBlockType;

enum 
{
  SCE_KERNEL_MEMBLOCK_TYPE_USER_RW  = 0x0c20d060,
  SCE_KERNEL_MEMBLOCK_TYPE_USER_RW_UNCACHE  = 0x0c208060,
  SCE_KERNEL_MEMBLOCK_TYPE_USER_MAIN_PHYCONT_RW = 0x0c80d060,
  SCE_KERNEL_MEMBLOCK_TYPE_USER_MAIN_PHYCONT_NC_RW  = 0x0d808060,
  SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW  = 0x09408060,
  SCE_KERNEL_MEMBLOCK_TYPE_KERNEL_RX = 0x1020D005,
  SCE_KERNEL_MEMBLOCK_TYPE_KERNEL_RW = 0x1020D006,
  SCE_KERNEL_MEMBLOCK_TYPE_SHARED_RX = 0x390D050,
  SCE_KERNEL_MEMBLOCK_TYPE_USER_RX = 0xC20D050,
  SCE_KERNEL_MEMBLOCK_TYPE_RW_UNK0 = 0x6020D006
};

typedef struct SceKernelAllocMemBlockKernelOpt 
{
  SceSize size;
  SceUInt32 field_4;
  SceUInt32 attr;
  SceUInt32 field_C;
  SceUInt32 paddr;
  SceSize alignment;
  SceUInt32 field_18;
  SceUInt32 field_1C;
  SceUInt32 mirror_blkid;
  SceUID pid;
  SceUInt32 field_28;
  SceUInt32 field_2C;
  SceUInt32 field_30;
  SceUInt32 field_34;
  SceUInt32 field_38;
  SceUInt32 field_3C;
  SceUInt32 field_40;
  SceUInt32 field_44;
  SceUInt32 field_48;
  SceUInt32 field_4C;
  SceUInt32 field_50;
  SceUInt32 field_54;
};

SceUID SceSysmemForDriver_ksceKernelAllocMemBlock_c94850c9(const char *name, SceKernelMemBlockType type, int size, SceKernelAllocMemBlockKernelOpt *optp);

int SceSysmemForDriver_ksceKernelFreeMemBlock_009e1c61(SceUID uid);

int SceSysmemForDriver_ksceKernelGetMemBlockBase_a841edda(SceUID uid, void **basep);

struct addr_pair
{
    uint32_t addr;
    uint32_t length;
};

struct paddr_list_req
{
    uint32_t size; // 0x14
    uint32_t output_buffer_size;
    uint32_t unk;
    uint32_t ret_count;
    addr_pair *output_buffer;
};

//This function takes in two parameters: an array of length 2 specifying the virtual address and the size of the block of memory and a request information. The function will write into output_buffer an array of addr_pair that encompasses the block of memory specified in the input. req->ret_count will contain the number of entries written. If output_buffer is null, it will just write the count. 
int SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(addr_pair* input, paddr_list_req *req);

//This will write the physical address for a virtual address vaddr to memory pointed to by result. Returns <0 on error, values >=0 indicate success. 
int SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(void *vaddr, void **result);

void* SceSysmemForDriver_ksceKernelMemPoolAlloc_7b4cb60a(SceUID pool, SceSize size);

void SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceUID pool, void *ptr);