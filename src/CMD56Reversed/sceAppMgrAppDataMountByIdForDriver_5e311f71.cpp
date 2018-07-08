#include "sceAppMgrAppDataMountByIdForDriver_5e311f71.h"

#include <string>

#include "SceAppMgrBase.h"
#include "SceThreadmgr.h"
#include "SceAppMgrGlobals.h"
#include "sceAppMgrCreateMountPointBase.h"
#include "sceAppMgrUnmountBase.h"

int mount_base_5e311f71(int mountId, const char* physical_path, const char* mount_drive, char* mountPoint)
{
   global_ctx_item * gctxi = get_global_ctx_item_23C2DE0(global_contexts_22A0500, SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a());

   if (gctxi == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80801002;
   }

   if (gctxi->unk_558.phys_ctx_30.flag_160 & 0x30)
   {
      if (check_flags_23D4CE0(mountId, gctxi->unk_558.phys_ctx_30.flag_160) == 0)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return 0x80800048;
      }
   }

   if (mountId == 0x6E)
   {
      int create_res = create_pfs_directory_23DFEAC(0x6E, physical_path, 0);
      if (create_res)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return create_res;
      }
   }
   else
   {
      if (gctxi->unk_558.phys_ctx_30.flag_160 & 0x10)
      {
         if ((mountId & 0xFFFFFFFB) == 0x69)
         {
            if (get_fake_no_memory_card_23E5660())
            {
               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
               return 0x80010013;
            }
         }
      }

      int norm_res = normalize_path_select_mode_create_dir_23D9354(physical_path, 1);
      if (norm_res)
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return norm_res;
      }
   }

   int mnt_res = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, mountId, gctxi->unk_558.titleId, physical_path, mount_drive, 0, mountPoint);

   if (mnt_res != 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return mnt_res;
   }

   if (gctxi->unk_558.phys_ctx_30.flag_160 & 0x30)
   {
      if (mountId == 0x69)
      {
         gctxi->unk_558.phys_ctx_30.flag_160 = gctxi->unk_558.phys_ctx_30.flag_160 | 0x4000000;

         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return mnt_res;
      }
      else if (mountId == 0x6D)
      {
         gctxi->unk_558.phys_ctx_30.flag_160 = gctxi->unk_558.phys_ctx_30.flag_160 | 0x8000000;
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

         return mnt_res;
      }
      else
      {
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return mnt_res;
      }
   }
   else
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return mnt_res;
   }
}

//----------------------------

int sub_5e311f71_mount_0x68(int mountId, const char* titleId, char* mountPoint)
{
   char dec_output[0x40];

   char accountNo[3];
   memset(accountNo, 0, 3);

   set_accoutNo_global_23D58B4(accountNo);

   if (_snprintf(dec_output, 0x40u, "%s/%s/%s/%s", "ur0:user", accountNo, "near/data/gift/received", titleId) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }

   return mount_base_5e311f71(mountId, dec_output, "gift0:", mountPoint);
}

int sub_5e311f71_mount_0x69(int mountId, char* mountPoint)
{  
   return mount_base_5e311f71(mountId, "ux0:music", "music0:", mountPoint);
}

int sub_5e311f71_mount_0x6A(int mountId, const char* titleId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20u, "ux0:psm/%s/RO", titleId);
   
   return mount_base_5e311f71(mountId, buffer, 0, mountPoint);
}

int sub_5e311f71_mount_0x6B(int mountId, const char* titleId, char* mountPoint)
{
   char buffer[0x20];

   _snprintf(buffer, 0x20u, "ux0:psm/%s/RW", titleId);

   return mount_base_5e311f71(mountId, buffer, 0, mountPoint);
}

int sub_5e311f71_mount_0x6C(int mountId, char* mountPoint)
{
   return mount_base_5e311f71(mountId, "ux0:calendar", 0, mountPoint);
}

int sub_5e311f71_mount_0x6D(int mountId, char* mountPoint)
{
   return mount_base_5e311f71(mountId, "ux0:video", "video0:", mountPoint);
}

int sub_5e311f71_mount_0x6E(int mountId, const char* titleId, char* mountPoint)
{
   char dec_output[0x40];

   if (_snprintf(dec_output, 0x40u, "%s/%s", "ux0:appmeta", titleId) > 0x3F)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
   
   return mount_base_5e311f71(mountId, dec_output, 0, mountPoint);
}

//----------------------

int check_titleid_5e311f71(int mountId, const char* titleId, int& error_code)
{
   if(mountId < 0x68 || mountId > 0x6E)
   {
      error_code = 0;
      return true;
   }

   switch ((mountId - 0x68))
   {
   case 0x68:
      {
         if(!check_long_titleId(titleId))
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            error_code = 0x80800001;
            return false;
         }
      }
      break;
   case 0x6A:
   case 0x6B:
      {
         if(!check_short_titleId(titleId))
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            error_code = 0x80800001;
            return false;
         }
      }
      break;
   case 0x6E:
      {
         if (titleId == 0)
         {
            SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
            error_code = 0x80800001;
            return false;
         }
      }
      break;
   default:
      break;
   }
   
   error_code = 0;
   return true;
}

int w_sceAppMgrAppDataMountByIdForDriver_5e311f71(int mountId, const char *titleId, char *mountPoint)
{
   int lock_res0 = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);
   if (lock_res0 < 0)
      return lock_res0;

   if (check_privileges_23D5D54(mountId) == 0)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800009;
   }

   if (!mountPoint)
   {
      lock_res0 = 0x80800001;
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return lock_res0;
   }

   int error_code = 0;
   if(!check_titleid_5e311f71(mountId, titleId, error_code))
      return error_code;

   switch (mountId)
   {
   case 0x68:
      return sub_5e311f71_mount_0x68(mountId, titleId, mountPoint);
   case 0x69:
      return sub_5e311f71_mount_0x69(mountId, mountPoint);
   case 0x6A:
      return sub_5e311f71_mount_0x6A(mountId, titleId, mountPoint);
   case 0x6B:
      return sub_5e311f71_mount_0x6B(mountId, titleId, mountPoint);
   case 0x6C:
      return sub_5e311f71_mount_0x6C(mountId, mountPoint);
   case 0x6D:
      return sub_5e311f71_mount_0x6D(mountId, mountPoint);
   case 0x6E:
      return sub_5e311f71_mount_0x6E(mountId, titleId, mountPoint);
   default:
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return 0x80800001;
   }
}

//it is strange that function does not allow all mountIds that it can handle
//does not mount: music0: ux0:calendar video0:
int SceAppMgrForDriver_sceAppMgrAppDataMountByIdForDriver_5e311f71(int mountId, char *titleId, char *mountPoint)
{
   if(mountId < 0x68 || mountId > 0x6E)
      return 0x80800001;

   switch(mountId)
   {
   case 0x68: //gift0:
   case 0x6A: //ux0:psm/%s/RO
   case 0x6B: //ux0:psm/%s/RW
   case 0x6E: //ux0:appmeta
      return w_sceAppMgrAppDataMountByIdForDriver_5e311f71(mountId, titleId, mountPoint);
   default:
      return 0x80800001;
   }
}