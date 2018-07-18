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

int sub_23E1014_label_87(int mountId, global_ctx_item* gctxi0, const char* title_id_or_drive, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   int mnt_create_res = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi0->unk_558.mctx_hldr_28, mountId, title_id_or_drive, physical_path, mount_drive, 0, mountPoint);
   if (mnt_create_res > 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return mnt_create_res;
   }

   if (mountId - 0x1F4 > 1)
   {
      return cleanup_23E1014(mountId, gctxi0);
   }

   char keystone_data_expected[0x60];
   int ks_read_res = read_keystone_23D6664(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), mountPoint, keystone_data_expected);
   if (ks_read_res >= 0)
   {
      if (memcmp(0, keystone_data_expected, 0x60) == 0)
      {
         return cleanup_23E1014(mountId, gctxi0);
      }
      else
      {
         if (mountPoint[0] != 0)
            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi0->unk_558.mctx_hldr_28, mountPoint, 0);

         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800006;
      }
   }
   else
   {
      if (mountPoint[0] != 0)
         w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi0->unk_558.mctx_hldr_28, mountPoint, 0);

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return ks_read_res;
   }
}

int sub_23E1014_label_147(int mountId, global_ctx_item* gctxi0, const char* title_id_or_drive, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   if (gctxi0->unk_558.phys_ctx_30.flag_160 & 0x10)
   {
      bool check5 = (mountId == 0x64) ? true : ((mountId & 0xFFFFFFFB) == 0x69);
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

   return sub_23E1014_label_87(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
}

int sub_23E1014_label_144(int mountId, global_ctx_item* gctxi0, const char* title_id_or_drive, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   int create_res = create_pfs_directory_23DFEAC(mountId, physical_path, 0);
   if (create_res > 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return create_res;
   }

   return sub_23E1014_label_87(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
}

int sub_23E1014_label_78(SceUID pid, int mountId, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   global_ctx_item* gctxi0 = get_global_ctx_item_23C2DE0((ctx_23C2960 *)0x22A0500, SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a());
   
   if (gctxi0 > 0)
   {
      char title_id_or_drive[16];
      memset(title_id_or_drive, 0, 0x10);

      strncpy(title_id_or_drive, gctxi0->unk_558.titleId, 0xAu);

      if ( gctxi0->unk_558.phys_ctx_30.flag_160 & 0x30 )
      {
         if (!check_flags_23D4CE0(mountId, gctxi0->unk_558.phys_ctx_30.flag_160))
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800048;
         }
      }

      if (mountId == 0xCD)
      {
         char buffer[0x20];
         _snprintf(buffer, 0x20u, "ux0:cache/%s", gctxi0->unk_558.phys_ctx_30.unk498);
         return sub_23E1014_label_147(mountId, gctxi0, title_id_or_drive, buffer, mount_drive, mountPoint);
      }

      if (mountId != 0x12C)
      {
         if (mountId < 0x1F6)
         {
            if (mountId >= 0x1F4
               || mountId == 0x6E
               || mountId >= 0x6E && mountId - 0x12E <= 2)
            {
               return sub_23E1014_label_144(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
            }
         }
         else if (mountId >= 0x1F8)
         {
            if (mountId >= 0x1FA)
            {
               if (mountId == 0x258)
               {
                  return sub_23E1014_label_87(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
               }

               return sub_23E1014_label_147(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
            }

            return sub_23E1014_label_144(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
         }

         return sub_23E1014_label_147(mountId, gctxi0, title_id_or_drive, physical_path, mount_drive, mountPoint);
      }

      global_ctx_item* gctxi1 = get_global_ctx_item_23C2DE0((ctx_23C2960 *)0x22A0500, pid);
      if (gctxi1 > 0)
      {
         int mnt_res = special_mount_0x12C_23D8908(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), gctxi1->unk_558.titleId, &gctxi1->unk_558.mctx_hldr_28, &gctxi0->unk_558.mctx_hldr_28, mountPoint);
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

bool sub_23E1014_check_mountId(int mountId, int& error_code)
{
   if(mountId == 0xCF)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      error_code = 0x80800001;
      return false;
   }

   if (mountId > 0xCF)
   {
      if (mountId >= 0x1F8)
      {
         if (mountId == 0x258)
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            error_code = 0x80800001;
            return false;
         }
      }
      else if (mountId >= 0x1F4 || mountId - 0x12F <= 1)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         error_code = 0x80800001;
         return false;
      }
   }
   else if (mountId > 0x6B)
   {
      if (mountId == 0x6E || mountId == 0xCD)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         error_code = 0x80800001;
         return false;
      }
   }
   else if (mountId >= 0x6A || mountId == 0x68)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      error_code = 0x80800001;
      return false;
   }

   error_code = 0;
   return true;
}

//------------------------

int sub_23E1014_mount_0x64(SceUID pid, int mountId, char* mountPoint)
{                  
   return sub_23E1014_label_78(pid, mountId, "ux0:picture", "photo0:", mountPoint);
}

int sub_23E1014_mount_0x65(SceUID pid, int mountId, char* mountPoint)
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

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x66(SceUID pid, int mountId, char* mountPoint)
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

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x67(SceUID pid, int mountId, char* mountPoint)
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

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x68(SceUID pid, int mountId, char* mountPoint)
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
   
   return sub_23E1014_label_78(pid, mountId, buffer, "gift0:", mountPoint);
}

int sub_23E1014_mount_0x69(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:music", "music0:", mountPoint);
}

int sub_23E1014_mount_0x6A(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:psm/%s/RO", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x6B(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:psm/%s/RW", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x6C(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid,  mountId, "ux0:calendar", 0, mountPoint);
}

int sub_23E1014_mount_0x6D(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:video", "video0:", mountPoint);
}

int sub_23E1014_mount_0x6E(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x40];

   if (_snprintf(buffer, 0x40, "%s/%s", "ux0:appmeta", 0) > 0x3F) //not sure why, but zero is indeed passed
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x6F(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "tm0:nphome", 0, mountPoint);
}

int sub_23E1014_mount_0x70(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:book", 0, mountPoint);
}


int sub_23E1014_mount_0xC8(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ur0:temp/sqlite", 0, mountPoint);
}

int sub_23E1014_mount_0xC9(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ur0:temp/attach", 0, mountPoint);
}

int sub_23E1014_mount_0xCA(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:pspemu", 0, mountPoint);
}

int sub_23E1014_mount_0xCB(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ur0:temp/grief_report", 0, mountPoint);
}

int sub_23E1014_mount_0xCC(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ur0:temp/checkout", 0, mountPoint);
}

int sub_23E1014_mount_0xCD(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:cache/%s", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0xCE(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ur0:temp/webbrowser", 0, mountPoint);
}

int sub_23E1014_mount_0xCF(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:temp/app_work/%s/rec", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}


int sub_23E1014_mount_0x12C(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, 0, 0, mountPoint);
}

int sub_23E1014_mount_0x12E(SceUID pid, int mountId, char* mountPoint)
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

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x12F(SceUID pid, int mountId, char* mountPoint)
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

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x130(SceUID pid, int mountId, char* mountPoint)
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

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}


int sub_23E1014_mount_0x190(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:mms/photo", 0, mountPoint);
}

int sub_23E1014_mount_0x191(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:mms/music", 0, mountPoint);
}

int sub_23E1014_mount_0x192(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "ux0:mms/video", 0, mountPoint);
}


int sub_23E1014_mount_0x1F4(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "grw0:addcont/%s", 0); //not sure why, but zero is indeed passed

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x1F5(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20u, "ux0:addcont/%s", 0); //not sure why, but zero is indeed passed

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x1F6(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "%spatch/%s", "grw0:", 0); //not sure why, but zero is indeed passed

   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x1F7(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20, "%spatch/%s", "ux0:", 0); //not sure why, but zero is indeed passed
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x1F8(SceUID pid, int mountId, char* mountPoint)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x20];
   
   _snprintf(buffer, 0x20, "ux0:user/%s/savedata_vc", accountNo);
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}

int sub_23E1014_mount_0x1F9(SceUID pid, int mountId, char* mountPoint)
{
   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   char buffer[0x20];

   _snprintf(buffer, 0x20, "ux0:user/%s/_temp_savedata_vc", accountNo);
   
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}


int sub_23E1014_mount_0x258(SceUID pid, int mountId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x40u, "ux0:umass/%s.img", 0); //not sure why, but zero is indeed passed
                        
   return sub_23E1014_label_78(pid, mountId, buffer, 0, mountPoint);
}


int sub_23E1014_mount_0x3EF(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "vs0:sys/external", 0, mountPoint);
}

int sub_23E1014_mount_0x3F0(SceUID pid, int mountId, char* mountPoint)
{
   return sub_23E1014_label_78(pid, mountId, "vs0:data/external", 0, mountPoint);
}

int sub_23E1014_mount_0x3F1(SceUID pid, int mountId, char* mountPoint)
{                           
   return sub_23E1014_label_78(pid, mountId, "ux0:data/userdata", 0, mountPoint);
}

//--------------------------

int sub_23E1014_label_8(SceUID pid, int mountId, char* mountPoint)
{
   if (mountPoint == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   int error_code = 0;
   if(!sub_23E1014_check_mountId(mountId, error_code))
      return error_code;
  
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
         return sub_23E1014_mount_0x64(pid, mountId, mountPoint);
      case 0x65:
         return sub_23E1014_mount_0x65(pid, mountId, mountPoint);
      case 0x66:
         return sub_23E1014_mount_0x66(pid, mountId, mountPoint);
      case 0x67:
         return sub_23E1014_mount_0x67(pid, mountId, mountPoint);
      case 0x68:
         return sub_23E1014_mount_0x68(pid, mountId, mountPoint);
      case 0x69:
         return sub_23E1014_mount_0x69(pid, mountId, mountPoint);
      case 0x6A:
         return sub_23E1014_mount_0x6A(pid, mountId, mountPoint);
      case 0x6B:
         return sub_23E1014_mount_0x6B(pid, mountId, mountPoint);
      case 0x6C:
         return sub_23E1014_mount_0x6C(pid, mountId, mountPoint);
      case 0x6D:
         return sub_23E1014_mount_0x6D(pid, mountId, mountPoint);
      case 0x6E:
         return sub_23E1014_mount_0x6E(pid, mountId, mountPoint);
      case 0x6F:
         return sub_23E1014_mount_0x6F(pid, mountId, mountPoint);
      case 0x70:
         return sub_23E1014_mount_0x70(pid, mountId, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0x70 && mountId < 0xC8)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId >= 0xC8 && mountId <= 0xCF)
   {
      #pragma region

      switch(mountId)
      {
      case 0xC8:
         return sub_23E1014_mount_0xC8(pid, mountId, mountPoint);
      case 0xC9:
         return sub_23E1014_mount_0xC9(pid, mountId, mountPoint);
      case 0xCA:
         return sub_23E1014_mount_0xCA(pid, mountId, mountPoint);
      case 0xCB:
         return sub_23E1014_mount_0xCB(pid, mountId, mountPoint);
      case 0xCC:
         return sub_23E1014_mount_0xCC(pid, mountId, mountPoint);
      case 0xCD:
         return sub_23E1014_mount_0xCD(pid, mountId, mountPoint);
      case 0xCE:
         return sub_23E1014_mount_0xCE(pid, mountId, mountPoint);
      case 0xCF:
         return sub_23E1014_mount_0xCF(pid, mountId, mountPoint);
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
         return sub_23E1014_mount_0x12C(pid, mountId, mountPoint);
      case 0x12D:
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800001;
         }
      case 0x12E:
         return sub_23E1014_mount_0x12E(pid, mountId, mountPoint);
      case 0x12F:
         return sub_23E1014_mount_0x12F(pid, mountId, mountPoint);
      case 0x130:
         return sub_23E1014_mount_0x130(pid, mountId, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0x130 && mountId < 0x190)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId >= 0x190 && mountId <= 0x192)
   {
      #pragma region

      switch (mountId)
      {
      case 0x190:
         return sub_23E1014_mount_0x190(pid, mountId, mountPoint);
      case 0x191:
         return sub_23E1014_mount_0x191(pid, mountId, mountPoint);
      case 0x192:
         return sub_23E1014_mount_0x192(pid, mountId, mountPoint);
      }

      #pragma endregion
   }
   else if(mountId > 0x192 && mountId < 0x1F4)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId >= 0x1F4 && mountId <= 0x1F9)
   {
      #pragma region

      switch(mountId)
      {
      case 0x1F4:
         return sub_23E1014_mount_0x1F4(pid, mountId, mountPoint);
      case 0x1F5:
         return sub_23E1014_mount_0x1F5(pid, mountId, mountPoint);
      case 0x1F6:
         return sub_23E1014_mount_0x1F6(pid, mountId, mountPoint);
      case 0x1F7:
         return sub_23E1014_mount_0x1F7(pid, mountId, mountPoint);
      case 0x1F8:
         return sub_23E1014_mount_0x1F8(pid, mountId, mountPoint);
      case 0x1F9:
         return sub_23E1014_mount_0x1F9(pid, mountId, mountPoint);
      }

      #pragma endregion
   }
   else if (mountId > 0x1F9 && mountId < 0x258)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if(mountId == 0x258)
   {
      return sub_23E1014_mount_0x258(pid, mountId, mountPoint);
   }
   else if(mountId > 0x258 && mountId < 0x3EF)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   else if (mountId >= 0x3EF && mountId <= 0x3F1)
   {
      #pragma region

      switch(mountId)
      {
      case 0x3EF:
         return sub_23E1014_mount_0x3EF(pid, mountId, mountPoint);
      case 0x3F0:
         return sub_23E1014_mount_0x3F0(pid, mountId, mountPoint);
      case 0x3F1:
         return sub_23E1014_mount_0x3F1(pid, mountId, mountPoint);
      }

      #pragma endregion
   }
   else
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
}

int sub_23E1014_label_100(SceSelfInfo& auth_ctx, SceUID pid, int mountId, char* mountPoint)
{
   if(auth_ctx.program_authority_id == 0x2800000000000001)
   {
      return sub_23E1014_label_8(pid, mountId, mountPoint);
   }
   else
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800009;
   }
}

//--------------------------

int sub_23E1014_auth_check_mount(SceUID pid, int mountId, char *mountPoint)
{
   SceSelfInfo auth_ctx;

   if (SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(0, (SceSelfInfo*)&auth_ctx) < 0 )
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800009;
   }

   if (mountId == 0x70)
   {
      #pragma region no fall through

      int authid_check_res0 = SceSblACMgrForDriver_sceSblACMgrIsNonGameProgram_6c5ab07f(0);
      if ( authid_check_res0 )
      {
         return sub_23E1014_label_8(pid, mountId, mountPoint);
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
         return sub_23E1014_label_100(auth_ctx, pid, mountId, mountPoint);
      }
      else
      {
         #pragma region no fall through

         int authid_check_res0;

         if(auth_ctx.program_authority_id == 0x2808000000000001)
         {
            authid_check_res0 = 1;
         }
         else
         {
            authid_check_res0 = 0;
         }

         if (authid_check_res0)
         {
            return sub_23E1014_label_8(pid, mountId, mountPoint);
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
            int authid_check_res0 = SceSblACMgrForDriver_sceSblACMgrIsSomething_f5ae24ac(0) != 0; 
            if ( authid_check_res0 )
            {
               return sub_23E1014_label_8(pid, mountId, mountPoint);
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
            return sub_23E1014_label_100(auth_ctx, pid, mountId, mountPoint);
         }
         #pragma endregion
      }
      else
      {
         #pragma region no fall through

         int v23;

         if(auth_ctx.program_authority_id == 0x2800000000000001)
         {
            v23 = 0;
         }
         else
         {
            v23 = 1;
         }

         int check4;

         if(auth_ctx.program_authority_id == 0x280000000000002D)
         {
            check4 = 0;
         }
         else
         {
            check4 = v23 & 1;
         }
      
         int authid_check_res0 = check4 ^ 1;

         if (authid_check_res0)
         {
            return sub_23E1014_label_8(pid, mountId, mountPoint);
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
}

int w_sceAppMgrGenericDataMount_base_23E1014(SceUID pid, int mountId, char *mountPoint)
{
   if (mountId > 0x130)
   {
      #pragma region no fall through

      if (mountId == 0x258)
      {
         #pragma region no fall through

         int authid_check_res0 = SceSblACMgrForDriver_check_auth_id_4db7f512(0);
         
         if (authid_check_res0)
         {
            return sub_23E1014_label_8(pid, mountId, mountPoint);
         }
         else
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            return 0x80800009;
         }

         #pragma endregion
      }
      else if (mountId > 0x258)
      {
         #pragma region no fall through

         if (mountId - 0x384 > 1)
         {
            return sub_23E1014_label_8(pid, mountId, mountPoint);
         }
         else
         {
            return sub_23E1014_auth_check_mount(pid, mountId, mountPoint);
         }

         #pragma endregion
      }
      else if (mountId - 0x1F4 > 5)
      {
         return sub_23E1014_label_8(pid, mountId, mountPoint);
      }
      else
      {
         return sub_23E1014_auth_check_mount(pid, mountId, mountPoint);
      }

      #pragma endregion
   }
   else if (mountId < 0x12E)
   {
      #pragma region no fall through

      if (mountId > 0x70)
      {
         #pragma region no fall through

         if (mountId != 0xCD)
         {
            return sub_23E1014_label_8(pid, mountId, mountPoint);
         }
         else
         {
            #pragma region no fall through

            int authid_check_res0 = SceSblACMgrForDriver_check_auth_id_456da7ac(0);
         
            if (authid_check_res0)
            {
               return sub_23E1014_label_8(pid, mountId, mountPoint);
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
            return sub_23E1014_label_8(pid, mountId, mountPoint);
         }

         #pragma endregion
      }
      else
      {
         #pragma region no fall through

         return sub_23E1014_auth_check_mount(pid, mountId, mountPoint);

         #pragma endregion
      }

      #pragma endregion
   }
   else
   {
      #pragma region no fall through

      return sub_23E1014_auth_check_mount(pid, mountId, mountPoint);

      #pragma endregion
   }
}

int w_sceAppMgrGenericDataMount_23E1014(SceUID pid, int mountId, char *mountPoint)
{
   int lock_res0 = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);
   if (lock_res0 < 0)
      return lock_res0;

   return w_sceAppMgrGenericDataMount_base_23E1014(pid, mountId, mountPoint);
}