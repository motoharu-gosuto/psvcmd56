#pragma once

#include <stdint.h>

#include "Constants.h"

//=========================================================================================

struct result_c8672a3d;

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

struct result_c8672a3d_10_unk //this is some linked list type
{
   result_c8672a3d* unk_0;
   result_c8672a3d* unk_4;
   int lockable_8;
   int unk_C;
};

//looks like this structure is of size 0x0C
//DO NOT ADD FIELDS - code depends on sizeof(input_167079fc)
struct input_167079fc
{
   int unk_0;
   int unk_4;
   input_167079fc* unk_8;
};


//size is 0x20 - DO NOT ADD FIELDS - code depends on sizeof(local_01a599e0)
//size can be proven by stack layout used for struct local variable
struct local_01a599e0
{
   void* source_vaddr_00;  // used - var44 - is this can be pointer to result_c8672a3d
   void* source_paddr_04;  // used - var40 - is this can be pointer to result_c8672a3d
   
   int size_08;            // used - var3C - this size is used as lockable by SceDmacmgrForDriver_543f54cf
   int flag_0C;            // used - var38
   
   int var_10;             // used - var34 arg_4
   void* paddr_14;         // used - var30 - uid ?

   int var_18;             // used - var2C - this value is actually combination of two short values, shomehow related to length of items in paddr list
   local_01a599e0* var_1C; // used - var28 - this is definitely pointer to next element or -1 value - enumerated by sub_992910
};

//check here about physical addresses:
//https://wiki.henkaku.xyz/vita/F00D_Commands#Physical_Address_List
//A common format used in these requests is a list of physical address and size. This simple structure is defined below. See SceSysmem#get_paddr_list for information on creating this list. 
//This data format is used when passing large buffers of data to F00D. This is because the memory manager in kernel could allocate contiguous virtual addresses that corresponds to varying physical addresses. 

/*
struct result_c8672a3d
{
   result_c8672a3d* unk_00; //linked list prev ?
   result_c8672a3d* unk_04; //linked list next ?
   //local_01a599e0* unk_08; // not sure about the type, should be result_c8672a3d ?
   int unk_08;

   int unk_0C;
   //result_c8672a3d_10_unk* unk_10;  //used
   result_c8672a3d* unk_10;

   result_c8672a3d_14_pair* unk_14; //used

   result_c8672a3d* unk_18;
   result_c8672a3d* unk_1C;
   void* unk_20; //used - flags?
   void* unk_24;
   //input_167079fc* unk_28; //used
   int unk_28;
   int lockable_int_2C; //some mutex ?
   
   int gxor_30; //(((int)&g_008FE000) | 0x01)
   SceUID eventFlagUid_34;
   short unk_38; //some flag ?
   short unk_3A;
   //local_01a599e0* unk_3C; // not sure about the type, should be result_c8672a3d ?
   result_c8672a3d* unk_3C;
};
*/

//This is important!
//I may assume that in root element that is created by SceDmacmgrForDriver_167079fc some fields may be used differently ?
//Other procedures also apply
//for examle there are some problems with unk_34 which is used as pointer or as uid
//not sure about unk_30 - can be used as gxor or smth else ? is it a THUMB pointer ?
//field unk_28 can be used as a size, or as a pointer to input_167079fc
//field unk_20 can be used as paddr list element or some other value like 7FC0000

struct result_c8672a3d
{
   result_c8672a3d* unk_00;
   result_c8672a3d* unk_04;

   const local_01a599e0* unk_08; //set by sub_992910 and by sub_992288
   
   int unk_0C; // definitely int - used by sub_992288 - offset field

   local_01a599e0* unk_10; // this should be pointer - set by sub_992288, by sub_992910
   
   int unk_14; // not sure, can be 0x00 - I would assume this is some error state - should be 0x00 if everything is ok

   result_c8672a3d* unk_18; // set by sub_992910 - pointer to start of list created by sub_992288
   result_c8672a3d* unk_1C; // is set by sub_992910 - pointer to end of list created by sub_992288

   void* unk_20; // paddr list element - set by sub_992288
   void* unk_24; // paddr list element - set by sub_992288

   int unk_28; // definitely int - used by sub_992288 - size field
   int unk_2C; // used by sub_992288, by sub_992910. used by SceDmacmgrForDriver_167079fc and 
               //                                            SceDmacmgrForDriver_543f54cf and 
               //                                            SceDmacmgrForDriver_397a917c as lockable int

   int unk_30; // used by sub_992288
   SceUID unk_34; // paddr - is not it SceUID ? - set by sub_992288 but can be wrong? - proved by SceDmacmgrForDriver_397a917c that it is UID
   
   short unk_38; // definitely short - this is error state flag heavily checked by SceDmacmgrForDriver_543f54cf
   short unk_3A; // definitely short

   local_01a599e0* unk_3C; //set by sub_992910 - this is definitely pointer at 
                           //least because it is initialized by sub_992288 with -1 value
};

//=========================================================================================

struct input1_c8672a3d;

//arg0 is taken from func struct
//arg1 is initialized internally
typedef void(func_c8672a3d)(int arg_0, input1_c8672a3d* ctx, int arg_1, void* retAddr);

//arg0 is taken from func struct
//arg1 is passed by caller function
typedef void(func_571660aa)(int arg_0, input1_c8672a3d* ctx, int arg_1, void* retAddr);

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

struct SceKernelAllocMemBlockKernelOpt 
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

//size is 0x08 - DO NOT ADD FIELDS as code depends on sizeof(addr_pair)
struct addr_pair
{
    void* addr;
    uint32_t length;
};

//size is 0x14 - DO NOT ADD FIELDS as code depends on sizeof(paddr_list_req)
struct paddr_list_req
{
    uint32_t size; // = 0x14     // 0x00
    uint32_t output_buffer_size; // 0x04
    uint32_t unk;                // 0x08
    uint32_t ret_count;          // 0x0C
    addr_pair* output_buffer;    // 0x10
};

//This function takes in two parameters: an array of length 2 specifying the virtual address and the size of the block of memory and a request information. The function will write into output_buffer an array of addr_pair that encompasses the block of memory specified in the input. req->ret_count will contain the number of entries written. If output_buffer is null, it will just write the count. 
int SceSysmemForDriver_ksceKernelGetPaddrList_e68beebd(addr_pair* input, paddr_list_req *req);

//This will write the physical address for a virtual address vaddr to memory pointed to by result. Returns <0 on error, values >=0 indicate success. 
int SceSysmemForDriver_ksceKernelGetPaddr_8d160e65(void *vaddr, void **result);

void* SceSysmemForDriver_sceKernelAllocHeapMemoryForDriver_7b4cb60a(SceUID pool, SceSize size);

void SceSysmemForDriver_sceKernelFreeHeapMemoryForDriver_3ebce343(SceUID pool, const void *ptr);

struct ctx_49D4DD9B
{
   int unk0;
   int unk4;
   int unk8;
   int unkC;
   int unk10;
};

void* SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceUID uid, SceSize size, ctx_49D4DD9B* unk2);

void* SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(SceUID uid, SceSize size, ctx_49D4DD9B* unk2);

int SceSysrootForKernel_ksceSysrootIsSafeMode_834439a7();

int SceSysrootForKernel_ksceSysrootIsUpdateMode_b0e1fc67();

int SceSysmemForDriver_sceKernelMemcpyUserToKernel_bc996a7a(void *dst, uintptr_t src, size_t len);

int SceSysmemForDriver_sceKernelMemcpyKernelToUser_6d88ef8a(uintptr_t dst, const void *src, size_t len);

int SceSysmemForDriver_sceKernelStrncpyUserToKernel_db3ec244(void *dst, uintptr_t src, size_t len);

struct SceKernelHeapCreateOpt
{
  SceSize size; //28
  SceUInt32 uselock;
  SceUInt32 field_8;
  SceUInt32 field_C;
  SceUInt32 block_type;
  SceUInt32 field_14;
  SceUInt32 field_18;
};

int SceSysmemForDriver_sceKernelCreateHeapForDriver_9328e0e8(const char *name, SceSize size, SceKernelHeapCreateOpt *opt);

int SceSysmemForDriver_sceKernelDeleteHeapForDriver_d6437637(SceUID pool_uid);