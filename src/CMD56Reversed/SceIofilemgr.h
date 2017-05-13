#pragma once

#include <stdint.h>

#include "Constants.h"
#include "SceSysmemGlobalVariables.h"

typedef struct vfs_block_dev_info //size is 0x14
{
  char* vitaMount;
  char* filesystem; // Some name, I guess it is filesystem
  char* blockDevicePrimary;
  char* blockDeviceSecondary; // can be 0
  uint32_t vshMountId; //must be same as in mount_point_info
}vfs_block_dev_info;

//probably vfsops
typedef struct node_ops1 // size is 0x34 (13 pointers)
{
  int (*func1)(void* ctx);
  int (*func2)(void* ctx); // ?
  int (*func3)(void* ctx);
  int (*func4)(void* ctx);
  int (*func5)(void* ctx); // not implemented by all
  int (*func6)(void* ctx); // not implemented by all
  int (*func7)(void* ctx);
  int (*func8)(void* ctx); // not implemented by all
  int (*func9)(void* ctx); // called by sceVfsAddVfs
  int (*func10)(void* ctx); // called by sceVfsDeleteVfs
  int (*func11)(void* ctx); // not implemented by all
  int (*func12)(void* ctx); // sceIoDevctlForDriver
  int (*func13)(void* ctx); // (initialize partition entry in table)(map block device name on numeric name)
} node_ops1;

//probably vnodeops
typedef struct node_ops2 // size is 0x74 (29 pointers)
{
  int (*func1)(void* ctx); // sceIoOpenForDriver (this function creates device handle) (It operates with normal block device name and unix mount)
  int (*func2)(void* ctx); // sceIoOpenForDriver (another one ?)
  int (*func3)(void* ctx); // sceIoOpenForDriver (another one ?) or sceIoCloseForDriver
  int (*func4)(void* ctx); // add partition (add vfsNode) (initialize partition entry in table) (for example happens on card insert exclusively) (operates with numeric names)
  int (*func5)(void* ctx); // sceIoReadForDriver
  int (*func6)(void* ctx); // sceIoWriteForDriver
  int (*func7)(void* ctx); // sceIoLseekForDriver or sceIoLseek32?
  int (*func8)(void* ctx); // sceIoIoctlForDriver
  int (*func9)(void* ctx); // remove partition (remove vfsNode) (deinitialize partition entry in table) (for example happens on card remove exclusively) (operates with numeric names)
  int (*func10)(void* ctx); // sceIoMkdirForDriver
  int (*func11)(void* ctx); // sceIoRmdirForDriver
  int (*func12)(void* ctx); // sceIoDopenForDriver
  int (*func13)(void* ctx); // sceIoDcloseForDriver
  int (*func14)(void* ctx); // sceIoDreadForDriver
  int (*func15)(void* ctx); // sceIoGetstatForDriver or sceIoGetstatByFdForDriver
  int (*func16)(void* ctx); // sceIoChstatForDriver or sceIoChstatByFdForDriver
  int (*func17)(void* ctx); // sceIoRenameForDriver
  int (*func18)(void* ctx); // not implemented by all
  int (*func19)(void* ctx); // sceIoPreadForDriver
  int (*func20)(void* ctx); // sceIoPwriteForDriver
  int (*func21)(void* ctx); // ?
  int (*func22)(void* ctx); // not referenced
  int (*func23)(void* ctx); // not referenced
  int (*func24)(void* ctx); // sceIoSyncForDriver or sceIoSyncByFdForDriver
  int (*func25)(void* ctx); // sceIoGetstatByFdForDriver
  int (*func26)(void* ctx); // sceIoChstatByFdForDriver
  int (*func27)(void* ctx); // ?
  int (*func28)(void* ctx); // ?
  int (*func29)(void* ctx); // not implemented by all
} node_ops2;

typedef struct vfs_mount_point_info_base
{
  char* unixMount;
  char* unk_4; //zero
  uint32_t devMajor;
  uint32_t devMinor;

  char* filesystem;
  uint32_t unk_14; //zero
  vfs_block_dev_info* blockDev1;
  node_ops2* unk_1C; //zero
} vfs_mount_point_info_base;

typedef struct vfs_add_data
{
    node_ops1* funcs1;
    const char *name; //max size is 0x20
    int flags; //0x0E
    int unk_C; //0x01 / 0x00 (root, leaf ?)
    
    int unk_10; //0x10
    node_ops2* funcs2;
    int unk_18; //0x00
    vfs_add_data* next_element; //ptr to next element, confirmed
} vfs_add_data;

typedef struct vfs_mount_cc
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8; // pointer to data section, offset 34
   uint32_t unk_C; // pointer to data section, offset 1C
} vfs_mount_cc;

struct vfs_node;

typedef struct vfs_fd_lock
{
   SceUID mutex_SceVfsFdLock; // 0
   SceUID cond_SceVfsFdCond; // 4
   uint32_t unk_8;
   uint32_t unk_C;

} vfs_fd_lock;

typedef struct vfs_mount //size is not known exactly, at least 0xD0
{
   uint32_t fast_mutex_SceVfsMnt;

   uint32_t unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   uint8_t data1[0x30];

   vfs_node* unk_40; // child ?

   SceUID pool;     // 0x44 - SceIoVfsHeap

   uint32_t unk_48; // = 0x101
   
   union _devMajor
   {
      struct _dmDword
      {
         uint32_t unk_4C;
      } dw;
      struct _dmWord
      {
         uint16_t unk_4C;
         uint16_t unk_4E;
      } w;
      struct _dmByte
      {
         uint8_t unk_4C;
         uint8_t unk_4D;
         uint8_t unk_4E;
         uint8_t unk_4F;
      } b;
   } devMajor;

   uint32_t devMinor; // 0x50

   vfs_node* unk_54;
   uint32_t unk_58;   // counter
   vfs_add_data* add_data; // 0x5C

   uint32_t unk_60;   // counter

   uint32_t unk_64;
   uint32_t unk_68;
   uint32_t unk_6C;

   vfs_mount* unk_70; // next ?
   vfs_mount* unk_74; // prev ?

   vfs_mount* unk_78; //singly linked list related to pointer 19D0 in data section

   vfs_block_dev_info* blockDev; // 0x7C

   char unixMount[0x40]; // 0x80 /gro/exfat, ux/exfat etc

   uint32_t unk_C0;   

   uint32_t unk_C4; // = mountInfo->unk_14

   vfs_fd_lock* fd_lock_ptr; // C8 - points to area in this structure

   vfs_mount_cc* unk_CC; // CC - points to area in this structure

   vfs_fd_lock fd_lock; // D0

   vfs_mount_cc unk_E0; //E0;

} vfs_mount;

typedef struct vfs_node_70
{
   uint32_t unk_0;
   uint32_t unk_4;
   uint32_t unk_8;
   vfs_node_70* unk_C; //zero or pointer to next element

   void* unk_10; //pointer to struct of at least size 0x94
   uint32_t unk_14; //number
   
   uint32_t unk_18;
   uint32_t unk_1C;
} vfs_node_70;

typedef struct vfs_node //size is 0x40 + 0x98 = D8
{
   uint32_t unk_0;
   uint32_t unk_4;  // most likely SceUID of current thread
   uint32_t unk_8;  // counter
   SceUID event_flag_SceVfsVnode; // 0xC - event flag SceVfsVnode

   uint32_t evid_bits; // 0x10
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;

   uint8_t data1[0x20];
   
   node_ops2 *ops;  // 0x40
   uint32_t unk_44;
   void* dev_info;  //allocated on heap with uid from uid field
                    //this is device specific / node specific data
                    //for partition node this will be vfs_device_info*

   vfs_mount* node; // 0x4C

   vfs_node* prev_node; // 0x50

   vfs_node* unk_54; // copied from node base
   uint32_t unk_58;  // counter - probably counter of nodes
   uint32_t unk_5C;

   uint32_t unk_60;
   uint32_t unk_64;
   uint32_t unk_68;
   SceUID pool_uid;  // 0x6C - SceIoVfsHeap or other pool

   vfs_node_70* unk_70;
   uint32_t unk_74; // = 0x8000
   uint32_t unk_78; // some flag
   uint32_t unk_7C;

   uint32_t unk_80;
   uint32_t unk_84;
   uint32_t unk_88;
   uint32_t unk_8C;

   uint32_t unk_90;
   uint32_t unk_94;
   uint32_t unk_98;
   uint32_t unk_9C;

   uint8_t data2[0x30];
   
   uint32_t unk_D0; //cur_node->devMajor.w.unk_4E

   uint8_t data3[0x2C];

} vfs_node;

int SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(vfs_node* a0);

int SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(vfs_node* a0);

//get some string from node field 70
int SceIofilemgrForDriver_unk_aa253b68(vfs_node *node, char *dest, int size, int* result);

typedef struct vfs_node_func15_arg1 //size is 0x10
{
   char* var_C8;
   int var_C4;
   int var_C0;
   int var_BC;

}vfs_node_func15_arg1;

typedef struct vfs_node_func15_arg2 //size is 0x5C
{
   int var_B8;
   int var_B4;
   int var_B0; //res1
   int var_AC; //res2

   char data[0x4C];

}vfs_node_func15_arg2;

int SceIofilemgrForDriver_vfs_node_func15_50a63acf(vfs_node *node, vfs_node_func15_arg1* unk0, vfs_node_func15_arg2* unk1);