#include "sceAppMgrWorkDirMountById_58e4cc90.h"

#include "SceSysmem.h"
#include "SceThreadmgr.h"
#include "SceAppMgrGlobals.h"
#include "SceAppMgrBase.h"
#include "sceAppMgrCreateMountPointBase.h"
#include "sceAppMgrUnmountBase.h"
#include "sceAppMgrCreate12CMountPoint.h"

#include <string>

int cleanup_23E00B8(int mountId, global_ctx_item *gctxi)
{
   if (gctxi->unk_558.phys_ctx_30.flag_160 & 0x30)
   {
      switch (mountId)
      {
      case 0x64u:
         gctxi->unk_558.phys_ctx_30.flag_160 = gctxi->unk_558.phys_ctx_30.flag_160 | 0x2000000;
         break;
      case 0x69u:
         gctxi->unk_558.phys_ctx_30.flag_160 = gctxi->unk_558.phys_ctx_30.flag_160 | 0x4000000;
         break;
      case 0x6Du:
         gctxi->unk_558.phys_ctx_30.flag_160 = gctxi->unk_558.phys_ctx_30.flag_160 | 0x8000000;
         break;
      }
   }

   SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
   return 0;
}

int mount_base_23E00B8(int mountId, const char *keystone_data, global_ctx_item *gctxi, const char* titleId, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   int create_res = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, mountId, titleId, physical_path, mount_drive, 0, mountPoint);
   if (create_res != 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return create_res;
   }

   //check if mountId requires keystone check

   if (mountId >= 0x1F6)
   {
      //successfull return
      return cleanup_23E00B8(mountId, gctxi);
   }
   else
   {
      //if mount was successfull - read keystone file
      char keystone_data_expected[0x60];
      int read_res = read_keystone_23D6664(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), mountPoint, keystone_data_expected);
      if(read_res < 0)
      {
         if (mountPoint[0] != 0)
            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, mountPoint, 0);

         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800006;
      }

      //compare keystone file
      if (memcmp(keystone_data, keystone_data_expected, 0x60) != 0)
      {
         if (mountPoint[0] != 0)
            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, mountPoint, 0);

         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800006;
      }

      //successfull return
      return cleanup_23E00B8(mountId, gctxi);
   }
}

//--------------------------

int mount_with_fake_no_memory_card_23E00B8(int mountId, const char *keystone_data, global_ctx_item *gctxi, const char* titleId, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   if (gctxi->unk_558.phys_ctx_30.flag_160 & 0x10)
   {
      bool check3 = (mountId == 0x64) ? true : ((mountId & 0xFFFFFFFB) == 0x69);
      if (check3)
      {
         if (get_fake_no_memory_card_23E5660())
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80010013;
         }
      }
   }

   int lock_res0 = normalize_path_select_mode_create_dir_23D9354(physical_path, 1);
   if (lock_res0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return lock_res0;
   }

   return mount_base_23E00B8(mountId, keystone_data, gctxi, titleId, physical_path, mount_drive, mountPoint);
}

int mount_with_create_dir_23E00B8(int mountId, const char *keystone_data, global_ctx_item *gctxi, const char* titleId, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   int lock_res0 = create_pfs_directory_23DFEAC(mountId, physical_path, keystone_data);
   if (lock_res0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return lock_res0;
   }

   return mount_base_23E00B8(mountId, keystone_data, gctxi, titleId, physical_path, mount_drive, mountPoint);
}

//--------------------------

int work_dir_mount_23E00B8(SceUID pid, int mountId, const char *keystone_data, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   global_ctx_item * gctxi0 = get_global_ctx_item_23C2DE0(global_contexts_22A0500, SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a());
   if (gctxi0 == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80801002;
   }

   if (gctxi0->unk_558.phys_ctx_30.flag_160 & 0x30)
   {
      if (check_flags_23D4CE0(mountId, gctxi0->unk_558.phys_ctx_30.flag_160) == 0)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800048;
      }
   }

   if (mountId == 0xCD)
   {
      char buffer[0x20];
      memset(buffer, 0, 0x20);

      _snprintf(buffer, 0x20u, "ux0:cache/%s", gctxi0->unk_558.phys_ctx_30.unk498);

      return mount_with_fake_no_memory_card_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, buffer, mount_drive, mountPoint);
   }
   else if(mountId == 0x12C)
   {
      global_ctx_item * gctxi1 = get_global_ctx_item_23C2DE0(global_contexts_22A0500, pid);

      if (gctxi1 == 0)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80801002;
      }

      int lock_res0 = special_mount_0x12C_23D8908(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), gctxi1->unk_558.titleId, &gctxi1->unk_558.mctx_hldr_28, &gctxi0->unk_558.mctx_hldr_28, mountPoint);
      if (lock_res0)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return lock_res0;
      }

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0;
   }
   else
   {
      if (mountId < 0x1F6)
      {
         if (mountId >= 0x1F4 || mountId == 0x6E || mountId >= 0x6E && mountId - 0x12E <= 2 )
         {
            return mount_with_create_dir_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, physical_path, mount_drive, mountPoint);
         }
         else
         {
            return mount_with_fake_no_memory_card_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, physical_path, mount_drive, mountPoint);
         }
      }
      else if (mountId >= 0x1F8)
      {
         if (mountId >= 0x1FA)
         {
            if (mountId == 0x258)
            {
               return mount_base_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, physical_path, mount_drive, mountPoint);
            }
            else
            {
               return mount_with_fake_no_memory_card_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, physical_path, mount_drive, mountPoint);
            }
         }
         else
         {
            return mount_with_create_dir_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, physical_path, mount_drive, mountPoint);
         }
      }
      else
      {
         return mount_with_fake_no_memory_card_23E00B8(mountId, keystone_data, gctxi0, gctxi0->unk_558.titleId, physical_path, mount_drive, mountPoint);
      }
   }
}

//--------------------------

//for mount subroutines - mount_drive is optional. if not specified, it will be generated by base mount function

int sub_23E00B8_mount_0x64(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:picture", "photo0:", mountPoint);
}

int sub_23E00B8_mount_0x65(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);
  
   if(_snprintf(dec_buffer0, 0x40u, "%s/%s/%s", "ur0:user", accountNo, "psnfriend") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x66(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   if (_snprintf(dec_buffer0, 0x40u, "%s/%s/%s", "ur0:user", accountNo, "psnmsg") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x67(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   if (_snprintf(dec_buffer0, 0x40u, "%s/%s/%s", "ur0:user", accountNo, "near/data_sys") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x68(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   if (_snprintf(dec_buffer0, 0x40u, "%s/%s/%s/%s", "ur0:user", accountNo, "near/data/gift/received", titleId) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, "gift0:", mountPoint);
}

int sub_23E00B8_mount_0x69(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:music", "music0:", mountPoint);
}

int sub_23E00B8_mount_0x6A(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer[0x20];
   memset(buffer, 0, 0x20);
   
   _snprintf(buffer, 0x20u, "ux0:psm/%s/RO", titleId);
   
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer, 0, mountPoint);  
}

int sub_23E00B8_mount_0x6B(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer[0x20];
   memset(buffer, 0, 0x20);
   
   _snprintf(buffer, 0x20u, "ux0:psm/%s/RW", titleId);

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer, 0, mountPoint);
}

int sub_23E00B8_mount_0x6C(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:calendar", 0, mountPoint);
}

int sub_23E00B8_mount_0x6D(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:video", "video0:", mountPoint);
}

int sub_23E00B8_mount_0x6E(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   if(_snprintf(dec_buffer0, 0x40u, "%s/%s", "ux0:appmeta", titleId) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x6F(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "tm0:nphome", 0, mountPoint);
}

int sub_23E00B8_mount_0x70(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:book", 0, mountPoint);
}


int sub_23E00B8_mount_0xC8(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ur0:temp/sqlite", 0, mountPoint);
}

int sub_23E00B8_mount_0xC9(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ur0:temp/attach", 0, mountPoint);
}

int sub_23E00B8_mount_0xCA(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:pspemu", 0, mountPoint);
}

int sub_23E00B8_mount_0xCB(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ur0:temp/grief_report", 0, mountPoint);
}

int sub_23E00B8_mount_0xCC(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ur0:temp/checkout", 0, mountPoint);
}

int sub_23E00B8_mount_0xCD(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   _snprintf(buffer0, 0x20u, "ux0:cache/%s", titleId);

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0xCE(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ur0:temp/webbrowser", 0, mountPoint);
}

int sub_23E00B8_mount_0xCF(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);
   
   _snprintf(buffer0, 0x20u, "ux0:temp/app_work/%s/rec", titleId);
   
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x12C(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, 0, 0, mountPoint);
}

int sub_23E00B8_mount_0x12E(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   if (_snprintf(dec_buffer0, 0x40u, "%s/%s/%s", "ur0:user", accountNo, "trophy/data/sce_trop") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x12F(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   if (_snprintf(dec_buffer0, 0x40u, "%s/%s/%s/%s", "ur0:user", accountNo, "trophy/data", titleId) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x130(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);
    
   if (_snprintf(dec_buffer0, 0x40u, "%s/%s/%s/%s_BK", "ur0:user", accountNo, "trophy/data", titleId) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}


int sub_23E00B8_mount_0x190(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:mms/photo", 0, mountPoint);
}

int sub_23E00B8_mount_0x191(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:mms/music", 0, mountPoint);
}

int sub_23E00B8_mount_0x192(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:mms/video", 0, mountPoint);
}

int sub_23E00B8_mount_0x1F4(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   _snprintf(buffer0, 0x20u, "grw0:addcont/%s", titleId);
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x1F5(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   _snprintf(buffer0, 0x20u, "ux0:addcont/%s", titleId);
   
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x1F6(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   _snprintf(buffer0, 0x20u, "%spatch/%s", "grw0:", titleId);
   
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x1F7(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   _snprintf(buffer0, 0x20u, "%spatch/%s", "ux0:", titleId);
   
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x1F8(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   _snprintf(buffer0, 0x20u, "ux0:user/%s/savedata_vc", accountNo);

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}

int sub_23E00B8_mount_0x1F9(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   char buffer0[0x20];
   memset(buffer0, 0, 0x20);

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   _snprintf(buffer0, 0x20u, "ux0:user/%s/_temp_savedata_vc", accountNo);

   return work_dir_mount_23E00B8(pid, mountId, keystone_data, buffer0, 0, mountPoint);
}


int sub_23E00B8_mount_0x258(SceUID pid, int mountId, const char * titleId, const char *keystone_data, char* mountPoint)
{
   char dec_buffer0[0x40];
   memset(dec_buffer0, 0, 0x40);

   _snprintf(dec_buffer0, 0x40u, "ux0:umass/%s.img", titleId);
   
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, dec_buffer0, 0, mountPoint);
}


int sub_23E00B8_mount_0x3EF(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "vs0:sys/external", 0, mountPoint);
}

int sub_23E00B8_mount_0x3F0(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "vs0:data/external", 0, mountPoint);
}

int sub_23E00B8_mount_0x3F1(SceUID pid, int mountId, const char *keystone_data, char* mountPoint)
{
   return work_dir_mount_23E00B8(pid, mountId, keystone_data, "ux0:data/userdata", 0, mountPoint);
}

//--------------------------


int w_sceAppMgrWorkDirMountByIdForKernel_23E00B8(SceUID pid, unsigned int mountId, const char *titleId, const char *keystone_data, char *mountPoint)
{
   int lock_res = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);
   if (lock_res < 0)
      return lock_res;
       
   if (check_privileges_23D5D54(mountId) == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800009;
   }

   if (mountPoint == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   int error_code0 = 0;
   if(!check_title_id_23E00B8(mountId, titleId, error_code0))
      return error_code0;
    
   if (mountId < 0x64)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId >= 0x64 && mountId <= 0x70)
   {
      #pragma region

      switch(mountId)
      {
      case 0x64:
         return sub_23E00B8_mount_0x64(pid, mountId, keystone_data, mountPoint);
      case 0x65:
         return sub_23E00B8_mount_0x65(pid, mountId, keystone_data, mountPoint);
      case 0x66:
         return sub_23E00B8_mount_0x66(pid, mountId, keystone_data, mountPoint);
      case 0x67:
         return sub_23E00B8_mount_0x67(pid, mountId, keystone_data, mountPoint);
      case 0x68:
         return sub_23E00B8_mount_0x68(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x69:
         return sub_23E00B8_mount_0x69(pid, mountId, keystone_data, mountPoint);
      case 0x6A:
         return sub_23E00B8_mount_0x6A(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x6B:
         return sub_23E00B8_mount_0x6B(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x6C:
         return sub_23E00B8_mount_0x6C(pid, mountId, keystone_data, mountPoint);
      case 0x6D:
         return sub_23E00B8_mount_0x6D(pid, mountId, keystone_data, mountPoint);
      case 0x6E:
         return sub_23E00B8_mount_0x6E(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x6F:
         return sub_23E00B8_mount_0x6F(pid, mountId, keystone_data, mountPoint);
      case 0x70:
         return sub_23E00B8_mount_0x70(pid, mountId, keystone_data, mountPoint);
      }

      #pragma endregion
   }
   else if (mountId > 0x70 && mountId < 0xC8)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId >= 0xC8 && mountId <= 0xCF)
   {
      #pragma region

      switch(mountId)
      {
      case 0xC8:
         return sub_23E00B8_mount_0xC8(pid, mountId, keystone_data, mountPoint);
      case 0xC9:
         return sub_23E00B8_mount_0xC9(pid, mountId, keystone_data, mountPoint);
      case 0xCA:
         return sub_23E00B8_mount_0xCA(pid, mountId, keystone_data, mountPoint);
      case 0xCB:
         return sub_23E00B8_mount_0xCB(pid, mountId, keystone_data, mountPoint);
      case 0xCC:
         return sub_23E00B8_mount_0xCC(pid, mountId, keystone_data, mountPoint);
      case 0xCD:
         return sub_23E00B8_mount_0xCD(pid, mountId, titleId, keystone_data, mountPoint);
      case 0xCE:
         return sub_23E00B8_mount_0xCE(pid, mountId, keystone_data, mountPoint);
      case 0xCF:
         return sub_23E00B8_mount_0xCF(pid, mountId, titleId, keystone_data, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0xCF && mountId < 0x12C)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId >= 0x12C && mountId <= 0x130)
   {
      #pragma region

      switch(mountId)
      {
      case 0x12C:
         return sub_23E00B8_mount_0x12C(pid, mountId, keystone_data, mountPoint);
      case 0x12D:
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800001;
         }
      case 0x12E:
         return sub_23E00B8_mount_0x12E(pid, mountId, keystone_data, mountPoint);
      case 0x12F:
         return sub_23E00B8_mount_0x12F(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x130:
         return sub_23E00B8_mount_0x130(pid, mountId, titleId, keystone_data, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0x130 && mountId < 0x190)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId >= 0x190 && mountId <= 0x192)
   {
      #pragma region

      switch (mountId)
      {
      case 0x191:
         return sub_23E00B8_mount_0x191(pid, mountId, keystone_data, mountPoint);
      case 0x192:
         return sub_23E00B8_mount_0x192(pid, mountId, keystone_data, mountPoint);
      case 0x190:
         return sub_23E00B8_mount_0x190(pid, mountId, keystone_data, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0x192 && mountId < 0x1F4)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId >= 0x1F4 && mountId <= 0x1F9)
   {
      #pragma region

      switch(mountId)
      {
      case 0x1F4:
         return sub_23E00B8_mount_0x1F4(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x1F5:
         return sub_23E00B8_mount_0x1F5(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x1F6:
         return sub_23E00B8_mount_0x1F6(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x1F7:
         return sub_23E00B8_mount_0x1F7(pid, mountId, titleId, keystone_data, mountPoint);
      case 0x1F8:
         return sub_23E00B8_mount_0x1F8(pid, mountId, keystone_data, mountPoint);
      case 0x1F9:
         return sub_23E00B8_mount_0x1F9(pid, mountId, keystone_data, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0x1F9 && mountId < 0x258)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId == 0x258)
   {
      return sub_23E00B8_mount_0x258(pid, mountId, titleId, keystone_data, mountPoint);
   }
   else if(mountId > 0x258 && mountId < 0x3EF)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId >= 0x3EF && mountId <= 0x3F1)
   {
      #pragma region

      switch(mountId)
      {
      case 0x3EF:
         return sub_23E00B8_mount_0x3EF(pid, mountId, keystone_data, mountPoint);
      case 0x3F0:
         return sub_23E00B8_mount_0x3F0(pid, mountId, keystone_data, mountPoint);
      case 0x3F1:
         return sub_23E00B8_mount_0x3F1(pid, mountId, keystone_data, mountPoint);
      }

      #pragma endregion
   }
   else
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
}

int w_sceAppMgrWorkDirMountByIdForKernel_23E0F90(int mount_id, char *titleid, char *mount_point)
{
   if (mount_id != 0xCD && mount_id != 0xCF)
   return 0x80800001;
   
   return w_sceAppMgrWorkDirMountByIdForKernel_23E00B8(0, mount_id, titleid, 0, mount_point);
}

int w_sceAppMgrWorkDirMountByIdForKernel_23F214C(int mount_id, char *titleid, char *mountPoint)
{
   return w_sceAppMgrWorkDirMountByIdForKernel_23E0F90(mount_id, titleid, mountPoint);
}

int SceAppMgr_sceAppMgrWorkDirMountById_58e4cc90(int mountId, generic_mount_ctx *data, char *mountPoint, sceAppMgrWorkDirMountByIdOpt *opt)
{
   sceAppMgrWorkDirMountByIdOpt opt_local;
   int result0 = SceSysmemForDriver_sceKernelMemcpyUserToKernel_bc996a7a(&opt_local, (uintptr_t)opt, 8u);
   if(result0 < 0)
      return result0;

   if (data == 0)
   {
      generic_mount_ctx * data_kernel_copy = 0;

      if (mountPoint == 0)
      {
         return w_sceAppMgrWorkDirMountByIdForKernel_23F214C(mountId, data_kernel_copy->titleId, 0);
      }
      else
      {
         char mountPoint_kernel[16];
         memset(mountPoint_kernel, 0, 0x10);

         int mount_res = w_sceAppMgrWorkDirMountByIdForKernel_23F214C(mountId, data_kernel_copy->titleId, mountPoint_kernel);
         int copy_res = SceSysmemForDriver_sceKernelMemcpyKernelToUser_6d88ef8a((uintptr_t)mountPoint, mountPoint_kernel, 0x10u);
         int result1 = copy_res < 0;
         int result2 = copy_res & (copy_res >> 32);

         if (result1 != 0)
            return result2;
         
         return mount_res;
      }
   }
   else
   {
      generic_mount_ctx data_kernel;

      int result0 = SceSysmemForDriver_sceKernelStrncpyUserToKernel_db3ec244(&data_kernel, (uintptr_t)data, 0x40u);
      if (result0 < 0)
         return result0;

      if (result0 == 0x40 && data_kernel.mountDrive[15])
         return 0x8002710B;

      if (mountPoint == 0)
      {
         return w_sceAppMgrWorkDirMountByIdForKernel_23F214C(mountId, data_kernel.titleId, 0);
      }
      else
      {
         char mountPoint_kernel[16];
         memset(mountPoint_kernel, 0, 0x10);

         int mount_res = w_sceAppMgrWorkDirMountByIdForKernel_23F214C(mountId, data_kernel.titleId, mountPoint_kernel);
         int copy_res = SceSysmemForDriver_sceKernelMemcpyKernelToUser_6d88ef8a((uintptr_t)mountPoint, mountPoint_kernel, 0x10u);
         int result1 = copy_res < 0;
         int result2 = copy_res & (copy_res >> 32);

         if (result1 != 0)
            return result2;
      
         return mount_res;
      }
   }
}