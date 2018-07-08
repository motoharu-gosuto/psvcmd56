#include "sceAppMgrGenericDataMount.h"

#include <string>

#include "SceThreadmgr.h"
#include "SceAppMgrGlobals.h"
#include "SceSblACMgr.h"
#include "SceProcessmgr.h"
#include "SceAppMgrBase.h"
#include "sceAppMgrCreateMountPointBase.h"
#include "sceAppMgrUnmountBase.h"
#include "sceAppMgrCreate12CMountPoint.h"

int cleanup_23E1014(int mountId, global_ctx_item* gctxi)
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

int sub_23E1014_label_87(int mountId_local, global_ctx_item* gctxi0_copy, const char* title_id_or_drive, const char* physical_path, const char* mount_drive, char* mountPoint_local)
{
   int mnt_create_res = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi0_copy->unk_558.mctx_hldr_28, mountId_local, title_id_or_drive, physical_path, mount_drive, 0, mountPoint_local);
   if (mnt_create_res > 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return mnt_create_res;
   }

   if (mountId_local - 0x1F4 > 1)
   {
      return cleanup_23E1014(mountId_local, gctxi0_copy);
   }

   char keystone_data_expected[0x60];
   int ks_read_res = read_keystone_23D6664(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), mountPoint_local, keystone_data_expected);
   if (ks_read_res >= 0)
   {
      if (memcmp(0, keystone_data_expected, 0x60) == 0)
      {
         return cleanup_23E1014(mountId_local, gctxi0_copy);
      }
      else
      {
         if (mountPoint_local[0] != 0)
            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi0_copy->unk_558.mctx_hldr_28, mountPoint_local, 0);

         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800006;
      }
   }
   else
   {
      if (mountPoint_local[0] != 0)
         w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi0_copy->unk_558.mctx_hldr_28, mountPoint_local, 0);

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return ks_read_res;
   }
}

int sub_23E1014_label_147(int mountId_local, global_ctx_item* gctxi0_copy, const char* title_id_or_drive, const char* physical_path, const char* mount_drive, char* mountPoint_local)
{
   if (gctxi0_copy->unk_558.phys_ctx_30.flag_160 & 0x10)
   {
      bool check5 = (mountId_local == 0x64) ? true : ((mountId_local & 0xFFFFFFFB) == 0x69);
      if (check5)
      {
         if (get_fake_no_memory_card_23E5660())
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80010013;
         }
      }
   }

   int norm_res = normalize_path_select_mode_create_dir_23D9354(physical_path, 1);
   if (norm_res > 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return norm_res;
   }

   return sub_23E1014_label_87(mountId_local, gctxi0_copy, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
}

int sub_23E1014_label_144(int mountId_local, global_ctx_item* gctxi0_copy, const char* title_id_or_drive, const char* physical_path, const char* mount_drive, char* mountPoint_local)
{
   int create_res = create_pfs_directory_23DFEAC(mountId_local, physical_path, 0);
   if (create_res > 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return create_res;
   }

   return sub_23E1014_label_87(mountId_local, gctxi0_copy, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
}

int sub_23E1014_label_78(SceUID pid_local, int mountId_local, const char* physical_path, const char* mount_drive, char* mountPoint_local)
{
   global_ctx_item* gctxi0 = get_global_ctx_item_23C2DE0((ctx_23C2960 *)0x22A0500, SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a());
   
   if (gctxi0 > 0)
   {
      char title_id_or_drive[16];

      strncpy(title_id_or_drive, gctxi0->unk_558.titleId, 0xAu);

      if ( gctxi0->unk_558.phys_ctx_30.flag_160 & 0x30 )
      {
         if (!check_flags_23D4CE0(mountId_local, gctxi0->unk_558.phys_ctx_30.flag_160))
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800048;
         }
      }

      if (mountId_local == 0xCD)
      {
         char buffer[0x20];
         _snprintf(buffer, 0x20u, "ux0:cache/%s", gctxi0->unk_558.phys_ctx_30.unk498);
         return sub_23E1014_label_147(mountId_local, gctxi0, title_id_or_drive, buffer, mount_drive, mountPoint_local);
      }

      if (mountId_local != 0x12C)
      {
         if (mountId_local < 0x1F6)
         {
            if (mountId_local >= 0x1F4
               || mountId_local == 0x6E
               || mountId_local >= 0x6E && mountId_local - 0x12E <= 2)
            {
               return sub_23E1014_label_144(mountId_local, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
            }
         }
         else if (mountId_local >= 0x1F8)
         {
            if (mountId_local >= 0x1FA)
            {
               if (mountId_local == 0x258)
               {
                  return sub_23E1014_label_87(mountId_local, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
               }

               return sub_23E1014_label_147(mountId_local, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
            }

            return sub_23E1014_label_144(mountId_local, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
         }

         return sub_23E1014_label_147(mountId_local, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint_local);
      }

      global_ctx_item* gctxi1 = get_global_ctx_item_23C2DE0((ctx_23C2960 *)0x22A0500, pid_local);
      if (gctxi1 > 0)
      {
         int mnt_res = special_mount_0x12C_23D8908(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), gctxi1->unk_558.titleId, &gctxi1->unk_558.mctx_hldr_28, &gctxi0->unk_558.mctx_hldr_28, mountPoint_local);
         if (mnt_res)
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return mnt_res;
         }

         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0;
      }
   }
   
   SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
   return 0x80801002;
}

bool sub_23E1014_check_mountId(int mountId_local, int& error_code)
{
   if(mountId_local == 0xCF)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      error_code = 0x80800001;
      return false;
   }

   if (mountId_local > 0xCF)
   {
      if (mountId_local >= 0x1F8)
      {
         if (mountId_local == 0x258)
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            error_code = 0x80800001;
            return false;
         }
      }
      else if (mountId_local >= 0x1F4 || mountId_local - 0x12F <= 1)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         error_code = 0x80800001;
         return false;
      }
   }
   else if (mountId_local > 0x6B)
   {
      if (mountId_local == 0x6E || mountId_local == 0xCD)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         error_code = 0x80800001;
         return false;
      }
   }
   else if (mountId_local >= 0x6A || mountId_local == 0x68)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      error_code = 0x80800001;
      return false;
   }

   error_code = 0;
   return true;
}

//------------------------

int sub_23E1014_mount_0x64(SceUID pid_local, int mountId_local, char* mountPoint_local)
{                  
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:picture", "photo0:", mountPoint_local);
}

int sub_23E1014_mount_0x65(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];

   if (_snprintf(buffer, 0x40, "%s/%s/%s", "ur0:user", accountNo, "psnfriend") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x66(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];

   if (_snprintf(buffer, 0x40u, "%s/%s/%s", "ur0:user", accountNo, "psnmsg") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x67(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];
   
   if (_snprintf(buffer, 0x40, "%s/%s/%s", "ur0:user", accountNo, "near/data_sys") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x68(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];

   if (_snprintf(buffer, 0x40u, "%s/%s/%s/%s", "ur0:user", accountNo, "near/data/gift/received", 0) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, "gift0:", mountPoint_local);
}

int sub_23E1014_mount_0x69(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:music", "music0:", mountPoint_local);
}

int sub_23E1014_mount_0x6A(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:psm/%s/RO", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x6B(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:psm/%s/RW", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x6C(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local,  mountId_local, "ux0:calendar", 0, mountPoint_local);
}

int sub_23E1014_mount_0x6D(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:video", "video0:", mountPoint_local);
}

int sub_23E1014_mount_0x6E(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x40];

   if (_snprintf(buffer, 0x40, "%s/%s", "ux0:appmeta", 0) > 0x3F) //not sure why, but zero is indeed passed
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x6F(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "tm0:nphome", 0, mountPoint_local);
}

int sub_23E1014_mount_0x70(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:book", 0, mountPoint_local);
}


int sub_23E1014_mount_0xC8(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ur0:temp/sqlite", 0, mountPoint_local);
}

int sub_23E1014_mount_0xC9(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ur0:temp/attach", 0, mountPoint_local);
}

int sub_23E1014_mount_0xCA(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:pspemu", 0, mountPoint_local);
}

int sub_23E1014_mount_0xCB(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ur0:temp/grief_report", 0, mountPoint_local);
}

int sub_23E1014_mount_0xCC(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ur0:temp/checkout", 0, mountPoint_local);
}

int sub_23E1014_mount_0xCD(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:cache/%s", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0xCE(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ur0:temp/webbrowser", 0, mountPoint_local);
}

int sub_23E1014_mount_0xCF(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:temp/app_work/%s/rec", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}


int sub_23E1014_mount_0x12C(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, 0, 0, mountPoint_local);
}

int sub_23E1014_mount_0x12E(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];

   if (_snprintf(buffer, 0x40, "%s/%s/%s", "ur0:user", accountNo, "trophy/data/sce_trop") > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x12F(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];

   if (_snprintf(buffer, 0x40u, "%s/%s/%s/%s", "ur0:user", accountNo, "trophy/data", 0) > 0x3F) //not sure why, but zero is indeed passed
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x130(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x40];

   if (_snprintf(buffer, 0x40u, "%s/%s/%s/%s_BK", "ur0:user", accountNo, "trophy/data", 0) > 0x3F) //not sure why, but zero is indeed passed
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}


int sub_23E1014_mount_0x190(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:mms/photo", 0, mountPoint_local);
}

int sub_23E1014_mount_0x191(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:mms/music", 0, mountPoint_local);
}

int sub_23E1014_mount_0x192(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:mms/video", 0, mountPoint_local);
}


int sub_23E1014_mount_0x1F4(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "grw0:addcont/%s", 0); //not sure why, but zero is indeed passed

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x1F5(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20u, "ux0:addcont/%s", 0); //not sure why, but zero is indeed passed

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x1F6(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "%spatch/%s", "grw0:", 0); //not sure why, but zero is indeed passed

   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x1F7(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "%spatch/%s", "ux0:", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x1F8(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x20];
   
   _snprintf(buffer, 0x20, "ux0:user/%s/savedata_vc", accountNo);
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}

int sub_23E1014_mount_0x1F9(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:user/%s/_temp_savedata_vc", accountNo);
   
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}


int sub_23E1014_mount_0x258(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   char buffer[0x20];

   _snprintf(buffer, 0x40u, "ux0:umass/%s.img", 0); //not sure why, but zero is indeed passed
                        
   return sub_23E1014_label_78(pid_local, mountId_local, buffer, 0, mountPoint_local);
}


int sub_23E1014_mount_0x3EF(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "vs0:sys/external", 0, mountPoint_local);
}

int sub_23E1014_mount_0x3F0(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   return sub_23E1014_label_78(pid_local, mountId_local, "vs0:data/external", 0, mountPoint_local);
}

int sub_23E1014_mount_0x3F1(SceUID pid_local, int mountId_local, char* mountPoint_local)
{                           
   return sub_23E1014_label_78(pid_local, mountId_local, "ux0:data/userdata", 0, mountPoint_local);
}

//--------------------------

int sub_23E1014_label_8(SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   if (mountPoint_local == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   int error_code = 0;
   if(!sub_23E1014_check_mountId(mountId_local, error_code))
      return error_code;
  
   if (mountId_local < 0x64)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId_local >= 0x64 && mountId_local <= 0x70)
   {
      #pragma region

      switch(mountId_local)
      {
      case 0x64:
         return sub_23E1014_mount_0x64(pid_local, mountId_local, mountPoint_local);
      case 0x65:
         return sub_23E1014_mount_0x65(pid_local, mountId_local, mountPoint_local);
      case 0x66:
         return sub_23E1014_mount_0x66(pid_local, mountId_local, mountPoint_local);
      case 0x67:
         return sub_23E1014_mount_0x67(pid_local, mountId_local, mountPoint_local);
      case 0x68:
         return sub_23E1014_mount_0x68(pid_local, mountId_local, mountPoint_local);
      case 0x69:
         return sub_23E1014_mount_0x69(pid_local, mountId_local, mountPoint_local);
      case 0x6A:
         return sub_23E1014_mount_0x6A(pid_local, mountId_local, mountPoint_local);
      case 0x6B:
         return sub_23E1014_mount_0x6B(pid_local, mountId_local, mountPoint_local);
      case 0x6C:
         return sub_23E1014_mount_0x6C(pid_local, mountId_local, mountPoint_local);
      case 0x6D:
         return sub_23E1014_mount_0x6D(pid_local, mountId_local, mountPoint_local);
      case 0x6E:
         return sub_23E1014_mount_0x6E(pid_local, mountId_local, mountPoint_local);
      case 0x6F:
         return sub_23E1014_mount_0x6F(pid_local, mountId_local, mountPoint_local);
      case 0x70:
         return sub_23E1014_mount_0x70(pid_local, mountId_local, mountPoint_local);
      }

      #pragma endregion
   }
   else if(mountId_local > 0x70 && mountId_local < 0xC8)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId_local >= 0xC8 && mountId_local <= 0xCF)
   {
      #pragma region

      switch(mountId_local)
      {
      case 0xC8:
         return sub_23E1014_mount_0xC8(pid_local, mountId_local, mountPoint_local);
      case 0xC9:
         return sub_23E1014_mount_0xC9(pid_local, mountId_local, mountPoint_local);
      case 0xCA:
         return sub_23E1014_mount_0xCA(pid_local, mountId_local, mountPoint_local);
      case 0xCB:
         return sub_23E1014_mount_0xCB(pid_local, mountId_local, mountPoint_local);
      case 0xCC:
         return sub_23E1014_mount_0xCC(pid_local, mountId_local, mountPoint_local);
      case 0xCD:
         return sub_23E1014_mount_0xCD(pid_local, mountId_local, mountPoint_local);
      case 0xCE:
         return sub_23E1014_mount_0xCE(pid_local, mountId_local, mountPoint_local);
      case 0xCF:
         return sub_23E1014_mount_0xCF(pid_local, mountId_local, mountPoint_local);
      }

      #pragma endregion
   }
   else if(mountId_local > 0xCF && mountId_local < 0x12C)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId_local >= 0x12C && mountId_local <= 0x130)
   {
      #pragma region

      switch(mountId_local)
      {
      case 0x12C:
         return sub_23E1014_mount_0x12C(pid_local, mountId_local, mountPoint_local);
      case 0x12D:
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800001;
         }
      case 0x12E:
         return sub_23E1014_mount_0x12E(pid_local, mountId_local, mountPoint_local);
      case 0x12F:
         return sub_23E1014_mount_0x12F(pid_local, mountId_local, mountPoint_local);
      case 0x130:
         return sub_23E1014_mount_0x130(pid_local, mountId_local, mountPoint_local);
      }

      #pragma endregion
   }
   else if(mountId_local > 0x130 && mountId_local < 0x190)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId_local >= 0x190 && mountId_local <= 0x192)
   {
      #pragma region

      switch (mountId_local)
      {
      case 0x190:
         return sub_23E1014_mount_0x190(pid_local, mountId_local, mountPoint_local);
      case 0x191:
         return sub_23E1014_mount_0x191(pid_local, mountId_local, mountPoint_local);
      case 0x192:
         return sub_23E1014_mount_0x192(pid_local, mountId_local, mountPoint_local);
      }

      #pragma endregion
   }
   else if(mountId_local > 0x192 && mountId_local < 0x1F4)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId_local >= 0x1F4 && mountId_local <= 0x1F9)
   {
      #pragma region

      switch(mountId_local)
      {
      case 0x1F4:
         return sub_23E1014_mount_0x1F4(pid_local, mountId_local, mountPoint_local);
      case 0x1F5:
         return sub_23E1014_mount_0x1F5(pid_local, mountId_local, mountPoint_local);
      case 0x1F6:
         return sub_23E1014_mount_0x1F6(pid_local, mountId_local, mountPoint_local);
      case 0x1F7:
         return sub_23E1014_mount_0x1F7(pid_local, mountId_local, mountPoint_local);
      case 0x1F8:
         return sub_23E1014_mount_0x1F8(pid_local, mountId_local, mountPoint_local);
      case 0x1F9:
         return sub_23E1014_mount_0x1F9(pid_local, mountId_local, mountPoint_local);
      }

      #pragma endregion
   }
   else if (mountId_local > 0x1F9 && mountId_local < 0x258)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId_local == 0x258)
   {
      return sub_23E1014_mount_0x258(pid_local, mountId_local, mountPoint_local);
   }
   else if(mountId_local > 0x258 && mountId_local < 0x3EF)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId_local >= 0x3EF && mountId_local <= 0x3F1)
   {
      #pragma region

      switch(mountId_local)
      {
      case 0x3EF:
         return sub_23E1014_mount_0x3EF(pid_local, mountId_local, mountPoint_local);
      case 0x3F0:
         return sub_23E1014_mount_0x3F0(pid_local, mountId_local, mountPoint_local);
      case 0x3F1:
         return sub_23E1014_mount_0x3F1(pid_local, mountId_local, mountPoint_local);
      }

      #pragma endregion
   }
   else
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
}

int sub_23E1014_label_100(SceSelfAuthInfo& auth_ctx, SceUID pid_local, int mountId_local, char* mountPoint_local)
{
   if(auth_ctx.auth_id == 0x2800000000000001)
   {
      return sub_23E1014_label_8(pid_local, mountId_local, mountPoint_local);
   }
   else
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800009;
   }
}

//--------------------------

//need to reverse this
int w_sceAppMgrGenericDataMount_23E1014(SceUID pid, int mountId, char *mountPoint)
{
   return 0;

   //vars
   /*
   unsigned int v6; // r11
   signed int lock_res0; // r7
   int result; // r0
   int authid_check_res0; // r0
   int index0; // r10
   int index1; // r3
   char *symbol0; // r2
   char check0; // zf
   const char *phys_path0; // r2
   SceUID pid0; // r0
   global_ctx_item *gctxi0; // r0
   global_ctx_item *gctxi0_copy; // r10
   int flag0; // r1
   SceUID pid1; // r0
   int flag1; // r3
   char check1; // zf
   char check2; // zf
   char v23; // r0
   char check3; // zf
   int check4; // r0
   const char *format0; // r2
   char check5; // zf
   int index3; // r3
   global_ctx_item *gctxi1; // r0
   global_ctx_item *gctxi1_copy; // r5
   SceUID pid2; // r0
   char *phys_drive0; // r3
   signed int dec_res0; // r0
   const char *phys_path1; // r2
   unsigned int bytes_printed0; // r0
   char *symbol1; // r3
   int index4; // r7
   SceUID pid3; // r0
   SceUID pid4; // r0
   char *dec_str_src0; // r0
   char *physical_path; // [sp+14h] [bp-11Ch]
   char *mount_drive; // [sp+18h] [bp-118h]
    // [sp+20h] [bp-110h]
   process_auth_id_ctx auth_ctx; // [sp+30h] [bp-100h]
   char dec_buffer0[64]; // [sp+C4h] [bp-6Ch]
   char v47; // [sp+108h] [bp-28h]
   */

   /*
   char* mountPoint_local = mountPoint;
   unsigned int mountId_local = mountId;
   SceUID pid_local = pid;

   char title_id_or_drive[16];

   memset(title_id_or_drive, 0, 0x10);

   int lock_res0 = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);
   if (lock_res0 < 0)
      return lock_res0;

   if (mountId > 0x130)
   {
      if (mountId == 0x258)
      {
         #pragma region no fall through

         authid_check_res0 = SceSblACMgrForDriver_check_auth_id_4db7f512(0);
         
         if ( authid_check_res0 )
         {
            return sub_23E1014_label_8();
         }
         else
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800009;
         }

         #pragma endregion
      }

      if (mountId > 0x258)
      {
         if (mountId - 0x384 > 1)
         {
            return sub_23E1014_label_8();
         }
      }
      else if (mountId - 0x1F4 > 5)
      {
         return sub_23E1014_label_8();
      }
   }
   else if (mountId < 0x12E)
   {
      if (mountId > 0x70)
      {
         #pragma region no fall through

         if (mountId != 0xCD)
         {
            return sub_23E1014_label_8();
         }
         else
         {
            #pragma region no fall through

            authid_check_res0 = SceSblACMgrForDriver_check_auth_id_456da7ac(0);
         
            if (authid_check_res0)
            {
               return sub_23E1014_label_8();
            }
            else
            {
               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
               return 0x80800009;
            }

            #pragma endregion
         }

         #pragma endregion
      }
      else if (mountId < 0x6E)
      {
         #pragma region no fall through

         if (mountId - 106 <= 1
            && !SceSblACMgrForDriver_check_auth_id_c98d82ee(0)
            && !SceSblACMgrForDriver_sceSblACMgrIsShell_8612b243(0))
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800009;
         }
         else
         {
            return sub_23E1014_label_8();
         }

         #pragma endregion
      }
   }

   if (SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(0, (SceSelfAuthInfo *)&auth_ctx) < 0 )
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800009;
   }

   if (mountId == 0x70)
   {
      #pragma region no fall through

      authid_check_res0 = SceSblACMgrForDriver_sceSblACMgrIsNonGameProgram_6c5ab07f(0);
      if ( authid_check_res0 )
      {
         return sub_23E1014_label_8();
      }
      else
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800009;
      }

      #pragma endregion
   }
   if (mountId > 0x70)
   {
      #pragma region no fall through

      if (mountId - 0x384 > 1)
      {
         return sub_23E1014_label_100();
      }
      else
      {
         #pragma region no fall through

         if(auth_ctx.auth_id == 0x2808000000000001)
         {
            authid_check_res0 = 1
         }
         else
         {
            authid_check_res0 = 0;
         }

         if (authid_check_res0)
         {
            return sub_23E1014_label_8();
         }
         else
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800009;
         }

         #pragma endregion
      }

      #pragma endregion
   }
   else
   {
      #pragma region no fall through

      if (mountId != 0x6E)
      {
         #pragma region no fall through
         if (mountId == 0x6F)
         {
            #pragma region no fall through
            authid_check_res0 = SceSblACMgrForDriver_sceSblACMgrIsSomething_f5ae24ac(0) != 0; 
            if ( authid_check_res0 )
            {
               return sub_23E1014_label_8();
            }
            else
            {
               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
               return 0x80800009;
            }
            #pragma endregion
         }
         else
         {
            return sub_23E1014_label_100();
         }
         #pragma endregion
      }
      else
      {
         #pragma region no fall through

         if(auth_ctx.auth_id == 0x2800000000000001)
         {
            v23 = 0;
         }
         else
         {
            v23 = 1;
         }

         if(auth_ctx.auth_id == 0x280000000000002D)
         {
            check4 = 0;
         }
         else
         {
            check4 = v23 & 1;
         }
      
         authid_check_res0 = check4 ^ 1;

         if (authid_check_res0)
         {
            return sub_23E1014_label_8();
         }
         else
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800009;
         }

         #pragma endregion
      }

      #pragma endregion
   }
   */
}