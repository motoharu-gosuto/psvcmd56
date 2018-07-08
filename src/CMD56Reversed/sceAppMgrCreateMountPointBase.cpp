#include "sceAppMgrCreateMountPointBase.h"

#include <string>

#include "SceAppMgrBase.h"
#include "SceSblACMgr.h"
#include "SceProcessmgr.h"
#include "ScePfsMgr.h"
#include "SceSysmem.h"
#include "SceAppMgrGlobals.h"
#include "SceThreadmgr.h"
#include "SceIofilemgr.h"

//======================

int w_unmount_23D5F44(SceUID pid, pfs_mount_t *mnt_entry, int umountArg)
{
   return 0;
}

//======================

//redirect appmgr mount to pfs mount
int proc_fios2kernel_overlay_add_for_process_23D4DDC(SceUID pid, appmgr_mount_t *mctx)
{
   //initialize overlay

   SceFiosOverlay overlay_local;
  
   memset(&overlay_local, 0, sizeof(SceFiosOverlay));

   //assign pid to overlay

   overlay_local.pid = pid != 0 ? pid : SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a();

   //assign type and order of overlay

   if (mctx->this_pfs_mount->mount_id != 0x3E9 && mctx->this_pfs_mount->mount_id != 0x3EB) //not patch and addcont (ux0:, grw0:)
   {
      //makes sense for app and addcont (gro0:, ux0:, grw0:)

      overlay_local.order = 0x81;
      overlay_local.type = SceFiosOverlayType::SCE_FIOS_OVERLAY_TYPE_OPAQUE; //src replaces dest, access to dest is redirected to src
   }
   else
   {
      //makes sense for patch

      overlay_local.order = 0x82;
      overlay_local.type = SceFiosOverlayType::SCE_FIOS_OVERLAY_TYPE_TRANSLUCENT; //src merges with dest, first src, then dest, write is redirected to dst
   }

   //construct source path

   if (mctx->this_pfs_mount->pfs_rnd_drive_id[0] != 0)
   {
      //src overlay path will be pfs random drive

      int len = strnlen(mctx->this_pfs_mount->pfs_rnd_drive_id, 0x10);
      strncpy(overlay_local.src, mctx->this_pfs_mount->pfs_rnd_drive_id, 0x124u);
      overlay_local.src_len = len + 2;

      overlay_local.src[len] = '0';
      overlay_local.src[len + 1] = ':';
      overlay_local.src[len + 2] = 0;
   }
   else
   {
      if (mctx->this_pfs_mount->mount_id == 0x258)
      {
         //src overlay path will be lma0: (for loopback drive)

         overlay_local.src_len = strnlen("lma0:", 292);
         strncpy(overlay_local.src, "lma0:", 0x124u);
      }
      else
      {
         //src will be physical path to app like ux0:app/<TITLEID>

         overlay_local.src_len = strnlen(mctx->this_pfs_mount->path, 292);
         strncpy(overlay_local.src, mctx->this_pfs_mount->path, 0x124u);
      }
   }
   
   overlay_local.src[291] = 0;

   //construct dest path

   if ((mctx->this_pfs_mount->mount_id & 0xFFFFFFFD) != 0x3E9) //not patch (since this is a mask this means not 0x3E9 or not 0x3EB!)
   {
      //app mgr random drive will be dst path

      overlay_local.dst_len = strnlen(mctx->appmgr_rnd_drive_id, 0x10);
      strncpy(overlay_local.dst, mctx->appmgr_rnd_drive_id, 0x124u);
   }
   else
   {
      if (mctx->prev_pfs_mount->pfs_rnd_drive_id[0] != 0)
      {
         //src overlay path will be pfs random drive

         int len = strnlen(mctx->prev_pfs_mount->pfs_rnd_drive_id, 0x10);
         strncpy(overlay_local.dst, mctx->prev_pfs_mount->pfs_rnd_drive_id, 0x124u);
         overlay_local.dst_len = len + 2;

         overlay_local.dst[len] = '0';
         overlay_local.dst[len + 1] = ':';
         overlay_local.dst[len + 2] = 0;  
      }
      else
      {
         //src will be physical path to app like ux0:app/<TITLEID>

         overlay_local.dst_len = strnlen(mctx->prev_pfs_mount->path, 0x10);
         strncpy(overlay_local.dst, mctx->prev_pfs_mount->path, 0x124u);
      }
   }

   overlay_local.dst[0x123] = 0;

   //create overlay

   int prev_perm = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
   int result = SceFios2KernelForDriver_sceFiosKernelOverlayAddForProcessForDriver_17e65a1c(overlay_local.pid, &overlay_local, &mctx->overlay_id);
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm);

   return result;
}

//======================

int select_index(const pfs_mount_t* glb_mpd_entry0)
{
   if (glb_mpd_entry0->auth_ids[0] == 0)
      return 0;
   else if (glb_mpd_entry0->auth_ids[1] == 0)
      return 1;
   else if (glb_mpd_entry0->auth_ids[2] == 0)
      return 2;
   else if (glb_mpd_entry0->auth_ids[3] == 0)
      return 3;
   else if (glb_mpd_entry0->auth_ids[4] == 0)
      return 4;
   else if (glb_mpd_entry0->auth_ids[5] == 0)
      return 5;
   else if (glb_mpd_entry0->auth_ids[6] == 0)
      return 6;
   else if (glb_mpd_entry0->auth_ids[7] == 0)
      return 7;
   else if (glb_mpd_entry0->auth_ids[8] == 0)
      return 8;
   else if (glb_mpd_entry0->auth_ids[9] == 0)
      return 9;
   else if (glb_mpd_entry0->auth_ids[10] == 0)
      return 10;
   else if (glb_mpd_entry0->auth_ids[11] == 0)
      return 11;
   else if (glb_mpd_entry0->auth_ids[12] == 0)
      return 12;
   else if (glb_mpd_entry0->auth_ids[13] == 0)
      return 13;
   else if (glb_mpd_entry0->auth_ids[14] == 0)
      return 14;
   else if (glb_mpd_entry0->auth_ids[15] == 0)
      return 15;
   else
      return -1;
}

int clear_authid(pfs_mount_t* glb_mpd_entry0, SceUInt64 auth_id)
{
   if (auth_id == glb_mpd_entry0->auth_ids[0])
      glb_mpd_entry0->auth_ids[0] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[1])
      glb_mpd_entry0->auth_ids[1] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[2])
      glb_mpd_entry0->auth_ids[2] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[3])
      glb_mpd_entry0->auth_ids[3] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[4])
      glb_mpd_entry0->auth_ids[4] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[5])
      glb_mpd_entry0->auth_ids[5] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[6])
      glb_mpd_entry0->auth_ids[6] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[7])
      glb_mpd_entry0->auth_ids[7] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[8])
      glb_mpd_entry0->auth_ids[8] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[9])
      glb_mpd_entry0->auth_ids[9] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[10])
      glb_mpd_entry0->auth_ids[10] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[11])
      glb_mpd_entry0->auth_ids[11] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[12])
      glb_mpd_entry0->auth_ids[12] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[13])
      glb_mpd_entry0->auth_ids[13] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[14])
      glb_mpd_entry0->auth_ids[14] = 0LL;
   else if (auth_id == glb_mpd_entry0->auth_ids[15])
      glb_mpd_entry0->auth_ids[15] = 0LL;

   return 0;
}

//======================

int label_21_cleanup(SceUID pid, const appmgr_mount_t* virt_mount, const void* mem, int error_code)
{
   //remove overlay

   if (virt_mount->overlay_id)
   {
      SceUID pid0 = pid != 0 ? pid : SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a();
      int prev_perm0 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
      SceFios2KernelForDriver_sceFiosKernelOverlayRemoveForProcessForDriver_23247efb(pid0, virt_mount->overlay_id);
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm0);
   }

   //unmount

   if (virt_mount->this_pfs_mount)
   {
      w_unmount_23D5F44(pid, virt_mount->this_pfs_mount, 1);
   }

   //dealloc memory

   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, virt_mount);

   if (mem)
   {
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, mem);
   }

   return error_code;
}

//this function adds an overlay
//copies virt_mount->mountDrive to mount_point_result
//links virt_mount with mount_ctx_holder
int label_115_cleanup(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, char *mount_point_result)
{
   //create overlay

   int result2 = proc_fios2kernel_overlay_add_for_process_23D4DDC(pid, virt_mount);
   if (result2 != 0)
      return label_21_cleanup(pid, virt_mount, 0, result2);

   //get first appmgr mount

   appmgr_mount_t* current_appmgr_mount = mount_ctx_holder->first_virt_mount;
   
   if (current_appmgr_mount)
   {
      //if starting node is initialized

      //if starting node is the same as current node - there is nothing to do

      if (virt_mount == current_appmgr_mount)
         return label_21_cleanup(pid, virt_mount, 0, 0x80800003);

      while (1)
      {
         if (current_appmgr_mount->next == 0)
         {
            current_appmgr_mount->next = virt_mount;

            virt_mount->prev = current_appmgr_mount;
            virt_mount->next = 0;

            //copy appmgr mount point appmgr_rnd_drive_id to result

            memcpy(mount_point_result, virt_mount->appmgr_rnd_drive_id, 0x10);

            return 0;
         }

         if (virt_mount == current_appmgr_mount)
            break;

         current_appmgr_mount = current_appmgr_mount->next;
      }
         
      return label_21_cleanup(pid, virt_mount, 0, 0x80800003);
   }
   else
   {
      //if there is no starting node - assign current appmgr mount point

      mount_ctx_holder->first_virt_mount = virt_mount;

      virt_mount->prev = 0;
      virt_mount->next = 0;

      //copy appmgr mount point appmgr_rnd_drive_id to result

      memcpy(mount_point_result, virt_mount->appmgr_rnd_drive_id, 0x10);
   
      return 0;
   }
}

int special_cleanup(SceUID pid, unsigned int mount_id, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, char *mount_point_result)
{
   //get first appmgr mount

   appmgr_mount_t * appmgr_mount_current = mount_ctx_holder->first_virt_mount;

   if (appmgr_mount_current)
   {
      pfs_mount_t * pfs_mount_current;

      while (1)
      {
         pfs_mount_current = appmgr_mount_current->this_pfs_mount;

         if (pfs_mount_current)
         {
            if (pfs_mount_current->mount_id == mount_id && !strncmp(appmgr_mount_current->appmgr_rnd_drive_id, virt_mount->appmgr_rnd_drive_id, 0x10u))
               break;
         }

         appmgr_mount_current = appmgr_mount_current->next;

         if (!appmgr_mount_current)
            return label_21_cleanup(pid, virt_mount, 0, 0x80800002);
      }

      virt_mount->prev_pfs_mount = pfs_mount_current;

      return label_115_cleanup(pid, mount_ctx_holder, virt_mount, mount_point_result);
   }
   else
   {
      return label_21_cleanup(pid, virt_mount, 0, 0x80800002);
   }
}

int label_113_cleanup(SceUID pid, unsigned int mount_id, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, char *mount_point_result)
{
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path);

   if (mount_id != 0x3E9) //patch
   {
      if (mount_id != 0x3EB) //addcont (ux0:, grw0:)
      {
         return label_115_cleanup(pid, mount_ctx_holder, virt_mount, mount_point_result);
      }
      else
      {
         return special_cleanup(pid, 0x3EA, mount_ctx_holder, virt_mount, mount_point_result); //addcont (gro0:, ux0:, grw0:)
      }
   }
   else
   {
      return special_cleanup(pid, 0x3E8, mount_ctx_holder, virt_mount, mount_point_result);  //app
   }  
}

int label_113_cleanup2(SceUID pid, pfs_mount_t *pfs_mount, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, char *mount_point_result)
{
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path);

   if (pfs_mount->mount_id != 0x3E9) //patch
   {
      if (pfs_mount->mount_id != 0x3EB) //addcont
      {
         return label_115_cleanup(pid, mount_ctx_holder, virt_mount, mount_point_result);
      }
      else
      {
         return special_cleanup(pid, 0x3EA, mount_ctx_holder, virt_mount, mount_point_result);
      }
   }
   else
   {
      return special_cleanup(pid, 0x3E8, mount_ctx_holder, virt_mount, mount_point_result);  
   } 
}

bool entries_stuff(SceUID pid, unsigned int mount_id, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, char *mount_point_result, SceUInt64 auth_id, int& error_code)
{
   //search

   pfs_mount_t* glb_mpd_entry0 = mount_point_entries_22D470C;

   while (mount_id != glb_mpd_entry0->mount_id || strncmp(glb_mpd_entry0->path, physical_path, 0x124u) != 0)
   {
      glb_mpd_entry0 = glb_mpd_entry0->next;
      if (glb_mpd_entry0 == 0)
      {
         error_code = 0;
         return true;
      }
   }

   //select index

   int initialized_global_item_index = select_index(glb_mpd_entry0);
   if(initialized_global_item_index < 0)
   {
      error_code = label_21_cleanup(pid, virt_mount, physical_path, 0x8080001E);
      return false;
   }

   //assign authid
   
   glb_mpd_entry0->auth_ids[initialized_global_item_index] = auth_id;

   //other checks

   if(glb_mpd_entry0->pfs_rnd_drive_id[0] == 0)
   {
      virt_mount->this_pfs_mount = glb_mpd_entry0;
      error_code = label_113_cleanup(pid, mount_id, mount_ctx_holder, virt_mount, physical_path, mount_point_result);
      return false;
   }

   SceSelfAuthInfo auth_ctx;

   int res0 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid, &auth_ctx);
   if(res0 >= 0)
   {
      res0 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(glb_mpd_entry0->pfs_rnd_drive_id, auth_ctx.auth_id);

      if(res0 == 0x80010011 || res0 >= 0)
      {
         virt_mount->this_pfs_mount = glb_mpd_entry0;
         error_code = label_113_cleanup(pid, mount_id, mount_ctx_holder, virt_mount, physical_path, mount_point_result);
         return false;
      }
   }

   clear_authid(glb_mpd_entry0, auth_id);

   if (res0 == 0x80800003)
   {
      error_code = label_113_cleanup(pid, mount_id, mount_ctx_holder, virt_mount, physical_path, mount_point_result);
      return false;
   }
   else
   {
      error_code = label_21_cleanup(pid, virt_mount, physical_path, res0);
      return false;
   }
}

int mpd_cleanup(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, pfs_mount_t* pfs_mount, const char *physical_path, char *mount_point_result, bool check0, int result)
{
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, pfs_mount);

   virt_mount->this_pfs_mount = 0;

   if (check0)
      return label_21_cleanup(pid, virt_mount, physical_path, result);
   else
      return label_113_cleanup2(pid, pfs_mount, mount_ctx_holder, virt_mount, physical_path, mount_point_result);
}

int label_154_cleanup(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, pfs_mount_t *pfs_mount, const char *physical_path, char *mount_point_result, bool check0, int result)
{
   int prev_perm = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
   if (pfs_mount->mount_id == 0x258)
   {
      SceIofilemgrForDriver_sceIoUmountForDriver_20574100(0x10000, 0, 0, 0);
   }
   else
   {
      ScePfsMgrForKernel_unmount_680bc384(pfs_mount->pfs_rnd_drive_id);
   }
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm);

   return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check0, result);
}

int select_index_136(pfs_mount_t *pfs_mount)
{
   if (pfs_mount->auth_ids[0] == 0)
      return 0;
   else if (pfs_mount->auth_ids[1] == 0)
      return 1;
   else if (pfs_mount->auth_ids[2] == 0)
      return 2; 
   else if (pfs_mount->auth_ids[3] == 0)
      return 3;
   else if (pfs_mount->auth_ids[4] == 0)
      return 4;
   else if (pfs_mount->auth_ids[5] == 0)
      return 5;
   else if (pfs_mount->auth_ids[6] == 0)
      return 6;
   else if (pfs_mount->auth_ids[7] == 0)
      return 7;
   else if (pfs_mount->auth_ids[8] == 0)
      return 8;
   else if (pfs_mount->auth_ids[9] == 0)
      return 9;
   else if (pfs_mount->auth_ids[10] == 0)
      return 10;
   else if (pfs_mount->auth_ids[11] == 0)
      return 11;
   else if (pfs_mount->auth_ids[12] == 0)
      return 12;
   else if (pfs_mount->auth_ids[13] == 0)
      return 13;
   else if (pfs_mount->auth_ids[14] == 0)
      return 14;
   else if (pfs_mount->auth_ids[15] == 0)
      return 15;
   else 
      return -1;
}

//this function adds pfs mount mount to a list
int label_136_cleanup(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, pfs_mount_t *pfs_mount, const char *physical_path, char *mount_point_result, SceUInt64 auth_id)
{
   int initialized_allocated_item_index = select_index_136(pfs_mount);
   if(initialized_allocated_item_index < 0)
   {
      return label_154_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x8080001E);
   }
   else
   {
      pfs_mount_t *current_pfs_mount = (pfs_mount_t *)mount_point_entries_22D470C;
      pfs_mount->auth_ids[initialized_allocated_item_index] = auth_id;

      if (current_pfs_mount)
      {
         //if pointers are same - there is no need to rearrange global list
         if (pfs_mount == current_pfs_mount)
            return label_154_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 0, 0x80800003);

         //insert new pfs_mount at the end
         pfs_mount_t * next_pfs_mount;
         while (true)
         {
            next_pfs_mount = current_pfs_mount->next;
            if(next_pfs_mount == 0)
               break;

            if (pfs_mount == current_pfs_mount)
               return label_154_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 0, 0x80800003);

            current_pfs_mount = current_pfs_mount->next;
         }

         current_pfs_mount->next = pfs_mount;

         pfs_mount->prev = current_pfs_mount;
         pfs_mount->next = next_pfs_mount;
      }
      else
      {
         //if mount_point_entries_22D470C was not initialized
         //assign current pfs_mount
         mount_point_entries_22D470C = pfs_mount;

         pfs_mount->prev = 0;
         pfs_mount->next = 0;
      }

      //assign pfs_mount to virtual mount
      virt_mount->this_pfs_mount = pfs_mount;

      return label_113_cleanup2(pid, pfs_mount, mount_ctx_holder, virt_mount, physical_path, mount_point_result);
   }
}

//======================

int create_loopback_mount(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, pfs_mount_t *pfs_mount, const char *physical_path, char *mount_point_result, SceUInt64 auth_id)
{
   pfs_mount->pfs_rnd_drive_id[0] = 0;
   int prev_perm1 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
   int mount_res = SceIofilemgrForDriver_sceIoMountForDriver_d070bc48(0x10000, physical_path, 0, 0, 0, 0);

   if(mount_res >= 0)
   {
      int mkdir_res0 = SceIofilemgrForDriver_sceIoMkdirForDriver_7f710b25("lma0:MPE_ROOT", 0x186);
      if(mkdir_res0 == 0x80010011 || mkdir_res0 >= 0)
      {
         SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm1);
         return label_136_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id);
      }
   }

   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm1);

   bool check0 = mount_res != 0x80800003;
   return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check0, mount_res);
}

int create_pfs_mount_raw(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, pfs_mount_t *pfs_mount, const char *physical_path, char *mount_point_result, SceUInt64 auth_id, char* klicensee0, std::uint16_t mode_index)
{
   if (pfs_mount->pfs_rnd_drive_id[0] == 0)
      return label_136_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id);

   //===============

   //pfs mount

   SceSelfAuthInfo auth_ctx0;

   int prev_perm2 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
   int auth_res = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid, &auth_ctx0);
   if (auth_res < 0)
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_res != 0x80800003, auth_res);

   char* klicensee1 = 0;

   if (klicensee0[0] || klicensee0[1] || klicensee0[2] || klicensee0[3] || klicensee0[4] || klicensee0[5] || klicensee0[6] || klicensee0[7] || 
       klicensee0[8] || klicensee0[9] || klicensee0[10] || klicensee0[11] || klicensee0[12] || klicensee0[13] || klicensee0[14])
   {
      klicensee1 = klicensee0;
   }
   else
   {
      klicensee1 = klicensee0[15] ? klicensee0 : 0;
   }

   int mnt_res = ScePfsMgrForKernel_mount_a772209c(pfs_mount->path, pfs_mount->pfs_rnd_drive_id, auth_ctx0.auth_id, klicensee1, mode_index);
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm2);
   if (mnt_res)
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, mnt_res != 0x80800003, mnt_res);

   //===============

   //check authid

   int check_res0 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(pfs_mount->pfs_rnd_drive_id, 0x2800000000000001); // SceShell
   if (check_res0 != 0x80010011)
   {
      if (check_res0 < 0)
      {
         ScePfsMgrForKernel_unmount_680bc384(pfs_mount->pfs_rnd_drive_id);
         return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check_res0 != 0x80800003, check_res0);
      }
   }

   //===============

   //check authid
   
   int check_res1 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(pfs_mount->pfs_rnd_drive_id, 0x2800000000007001);
   if(check_res1 != 0x80010011)
   {
      if (check_res1 < 0)
      {
         ScePfsMgrForKernel_unmount_680bc384(pfs_mount->pfs_rnd_drive_id);
         return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check_res1 != 0x80800003, check_res1);
      }
   }
   
   //===============

   //check authid
   
   int check_res2 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(pfs_mount->pfs_rnd_drive_id, 0x280000000000002D); // SceContentManager
   if (check_res2 != 0x80010011)
   {
      if (check_res2 < 0)
      {
         ScePfsMgrForKernel_unmount_680bc384(pfs_mount->pfs_rnd_drive_id);
         return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check_res2 != 0x80800003, check_res2);
      }
   }
   
   //===============

   //check authid

   if (mode_index == 0x04)
   {
      int check_res3 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(pfs_mount->pfs_rnd_drive_id, 0x2800000000000010); // SceSettings
      if (check_res3 != 0x80010011)
      {
         if (check_res3 < 0)
         {
            ScePfsMgrForKernel_unmount_680bc384(pfs_mount->pfs_rnd_drive_id);
            return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check_res3 != 0x80800003, check_res3);
         }
      }
   }
   else
   {
      if (mode_index == 0x05)
      {
         int check_res4 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(pfs_mount->pfs_rnd_drive_id, 0x2800000000000039); // SceDailyCheckerBg
         if (check_res4 != 0x80010011)
         {
            if (check_res4 < 0)
            {
               ScePfsMgrForKernel_unmount_680bc384(pfs_mount->pfs_rnd_drive_id);
               return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, check_res4 != 0x80800003, check_res4);
            }
         }
      }
   }

   //===============

   return label_136_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id);
}

//======================

int create_mount_with_klicensee(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, pfs_mount_t *pfs_mount, SceUInt64 auth_id, const char* klicensee, std::uint16_t mode_index, char *mount_point_result)
{
   char klicensee0[16];
   memcpy(klicensee0, klicensee, 0x10);
   return create_pfs_mount_raw(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id, klicensee0, mode_index);
}

int create_mount_with_empty_klicensee(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, pfs_mount_t *pfs_mount, SceUInt64 auth_id, std::uint16_t mode_index, char *mount_point_result)
{
   char klicensee0[16] = {0};
   return create_pfs_mount_raw(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id, klicensee0, mode_index);
}

int create_mount_from_sealedkey(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, pfs_mount_t *pfs_mount, SceUInt64 auth_id, std::uint16_t mode_index, char *mount_point_result)
{
   char klicensee0[16] = {0}; 

   int sk_read_res = read_sealedkey_23D6EA0(pfs_mount->path, klicensee0);
   if (!sk_read_res)
   {
      return create_pfs_mount_raw(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id, klicensee0, mode_index);
   }
   else
   {
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, sk_read_res != 0x80800003, sk_read_res);
   }
}

int create_mount_from_klicensee_or_sealedkey(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, const char *physical_path, pfs_mount_t *pfs_mount, SceUInt64 auth_id, const char* klicensee, std::uint16_t mode_index, char *mount_point_result)
{
   char klicensee0[16] = {0};
   
   if (klicensee)
   {
      memcpy(klicensee0, klicensee, 0x10);
      return create_pfs_mount_raw(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id, klicensee0, mode_index);
   }
   else
   {
      int sk_read_res = read_sealedkey_23D6EA0(pfs_mount->path, klicensee0);
      if (!sk_read_res)
      {
         return create_pfs_mount_raw(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, auth_id, klicensee0, mode_index);
      }
      else
      {
         return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, sk_read_res != 0x80800003, sk_read_res);
      }
   }
}

//===================

int create_mountpoint_core(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, appmgr_mount_t *virt_mount, pfs_mount_t *pfs_mount, const char *physical_path, SceUInt64 auth_id, const char* klicensee, char *mount_point_result)
{   
   if ((pfs_mount->mount_id < 0x64))
   {
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x80800001);
   }
   else if((pfs_mount->mount_id >= 0x64) && (pfs_mount->mount_id <= 0x6A))
   {
      return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x16, mount_point_result); //fake / redirect
   }
   else if ((pfs_mount->mount_id >= 0x6B) && (pfs_mount->mount_id <= 0x6C))
   {
      return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x15, mount_point_result); //fake / redirect
   }
   else if (pfs_mount->mount_id == 0x6D)
   {
      return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x16, mount_point_result); //fake / redirect
   }
   else if (pfs_mount->mount_id == 0x6E)
   {
      return create_mount_from_klicensee_or_sealedkey(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, klicensee, 0x05, mount_point_result); //savedata like
   }
   else if((pfs_mount->mount_id >= 0x6F) && (pfs_mount->mount_id <= 0x70))
   {
      return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x15, mount_point_result); //fake / redirect
   }
   else if((pfs_mount->mount_id > 0x70) && (pfs_mount->mount_id < 0xC8))
   {
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x80800001);
   }
   else if((pfs_mount->mount_id >= 0xC8) && (pfs_mount->mount_id <= 0xCF))
   {
      return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x15, mount_point_result); //fake / redirect
   }
   else if((pfs_mount->mount_id > 0xCF) && (pfs_mount->mount_id <= 0x130))
   {
      return create_mount_from_sealedkey(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x06, mount_point_result); //savedata like
   }
   else if ((pfs_mount->mount_id) > 0x130 && (pfs_mount->mount_id < 0x190))
   {
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x80800001);
   }
   else if ((pfs_mount->mount_id >= 0x190) && (pfs_mount->mount_id <= 0x192))
   {
      return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x16, mount_point_result); //fake / redirect
   }
   else if ((pfs_mount->mount_id >= 0x193) && (pfs_mount->mount_id <= 0x1F5))
   {
      return create_mount_from_sealedkey(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x04, mount_point_result); //ac
   }
   else if((pfs_mount->mount_id > 0x1F5) && (pfs_mount->mount_id < 0x1F8))
   {
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x80800001);
   }
   else if((pfs_mount->mount_id >= 0x1F8) && (pfs_mount->mount_id <= 0x1F9))
   {
      return create_mount_from_sealedkey(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x06, mount_point_result); //savedata like
   }
   else if ((pfs_mount->mount_id > 0x1F9) && (pfs_mount->mount_id < 0x3E8))
   {
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x80800001);
   }
   else if (pfs_mount->mount_id >= 0x3E8)
   {
      switch(pfs_mount->mount_id)
      {
      case 0x3E8:
      case 0x3E9:
         {
            if (clearsign_exists_23D9A4C(pfs_mount->path))
            {
               return create_mount_with_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, klicensee, 0x02, mount_point_result); //game
            }
            else
            {
               return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x14, mount_point_result); //fake / redirect
            }
         }
      case 0x3EA:
      case 0x3EB:
         {
            std::uint16_t mode_index = strncmp(pfs_mount->path, "gro0:", 5u) ? 0x04 : 0x0C; //ac / ac
            return create_mount_from_sealedkey(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, mode_index, mount_point_result);
         }
      case 0x3EC:
         return create_mount_with_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, klicensee, 0x0D, mount_point_result); //game
      case 0x3ED:
         return create_mount_from_klicensee_or_sealedkey(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, klicensee, 0x05, mount_point_result); //savedata like
      case 0x3EE:
         return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x15, mount_point_result); //fake / redirect
      case 0x3EF:
         return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x14, mount_point_result); //fake / redirect
      case 0x3F0:
         return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x14, mount_point_result); //fake / redirect
      case 0x3F1:
         return create_mount_with_empty_klicensee(pid, mount_ctx_holder, virt_mount, physical_path, pfs_mount, auth_id, 0x15, mount_point_result); //fake / redirect
      default:
         return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path, mount_point_result, 1, 0x80800001);
      }
   }
}

//===================

bool maybe_find_mount(SceUID pid, const appmgr_mount_holder_t *mount_ctx_holder, unsigned int mount_id, const char *mount_drive, const char* mount_drive_input, char *gen_mount_point, int& error_code)
{  
   //try to find mount ctx with mount_id and copy current_mount->mountDrive to gen_mount_point

   if (mount_id >= 0x3E8)
   {
      #pragma region
      appmgr_mount_t* current_mount = mount_ctx_holder->first_virt_mount;

      while (1)
      {
         if (mount_id == current_mount->this_pfs_mount->mount_id)
         {
            if (strncmp(current_mount->appmgr_rnd_drive_id, mount_drive_input, 0x10u) == 0)
               break;
         }

         current_mount = current_mount->next;

         if (current_mount == 0)
         {
            error_code = 0;
            return true;
         }
      }

      memcpy(gen_mount_point, current_mount->appmgr_rnd_drive_id, 0x10);
      #pragma endregion
   }
   else
   {
      #pragma region
      appmgr_mount_t* current_mount = mount_ctx_holder->first_virt_mount;

      while (1)
      {
         if(mount_id == current_mount->this_pfs_mount->mount_id)
            break;

         current_mount = current_mount->next;

         if (current_mount == 0)
         {
            error_code = 0;
            return true;
         }
      }

      memcpy(gen_mount_point, current_mount->appmgr_rnd_drive_id, 0x10);
      #pragma endregion
   }

   //----

   pfs_mount_t *mpd_entry0;

   if (mount_drive)
   {
      #pragma region

      appmgr_mount_t *mount_ctx_local1 = mount_ctx_holder->first_virt_mount;

      if (!mount_ctx_local1)
      {
         error_code = 0x80800002; 
         return false;
      }

      while (1)
      {
         mpd_entry0 = mount_ctx_local1->this_pfs_mount;

         if (mount_ctx_local1->this_pfs_mount)
         {
            if (mount_id == mpd_entry0->mount_id && !strncmp(mount_ctx_local1->appmgr_rnd_drive_id, mount_drive_input, 0x10u))
               break;
         }

         mount_ctx_local1 = mount_ctx_local1->next;

         if (mount_ctx_local1 == 0)
         {
            error_code = 0x80800002;
            return false;
         }
      }

      #pragma endregion
   }
   else
   {
      #pragma region

      appmgr_mount_t *mount_ctx_local2 = mount_ctx_holder->first_virt_mount;

      if (!mount_ctx_local2)
      {
         error_code = 0x80800002;
         return false;
      }

      while (1)
      {
         mpd_entry0 = mount_ctx_local2->this_pfs_mount;

         if (mount_ctx_local2->this_pfs_mount)
         {
            if (mount_id == mpd_entry0->mount_id)
               break;
         }

         mount_ctx_local2 = mount_ctx_local2->next;

         if (mount_ctx_local2 == 0)
         {
            error_code = 0x80800002;
            return false;
         }
      }

      #pragma endregion
   }

   if(mpd_entry0->pfs_rnd_drive_id[0] == 0)
   {
      error_code = 0x80800003;
      return false;
   }

   SceSelfAuthInfo auth_ctx;

   int res1 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid, &auth_ctx);
   if(res1 < 0)
   {
      error_code = res1;
      return false;
   }

   int res2 = ScePfsMgrForKernel_find_pmi_check_auth_id_d8d0fee5(mpd_entry0->pfs_rnd_drive_id, auth_ctx.auth_id);
   if(res2 == 0x80010011 || res2 >= 0)
   {
      error_code = 0x80800003;
      return false;
   }
   else
   {
      error_code = res2;
      return false;
   }   
}

//===================

int generate_mount_drive(unsigned int mount_id, char* mount_drive)
{
   if(mount_id <= 0x70)
   {
      #pragma region
      int res = proc_generate_random_path_23D4FBC("ad", mount_drive);
      if (res)
         return res;

      mount_drive[14] = ':';
      mount_drive[15] = 0;
      return 0;
      #pragma endregion
   }
   else if((mount_id > 0x70) && (mount_id < 0xC8))
   {
      return 0x80800001;
   }
   else if((mount_id >= 0xC8) && (mount_id <= 0xCF))
   {
      #pragma region
      switch(mount_id)
      {
      case 0xC8:
      case 0xC9:
         {
            int res = proc_generate_random_path_23D4FBC("td", mount_drive);
            if (res)
               return res;

            mount_drive[14] = ':';
            mount_drive[15] = 0;
            return 0;
         }
      case 0xCA:
         {
            if (SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7(0))
            {
               strcpy(mount_drive, "ms0:");
               return 0;
            }
            else
            {
               int res = proc_generate_random_path_23D4FBC("ms", mount_drive);
               if (res)
                  return res;
               
               mount_drive[14] = ':';
               mount_drive[15] = 0;
               return 0;
            }
         }
      case 0xCB:
      case 0xCC:
         {
            int res = proc_generate_random_path_23D4FBC("td", mount_drive);
            if (res)
               return res;
            
            mount_drive[14] = ':';
            mount_drive[15] = 0;
            return 0;
         }
      case 0xCD:
         strcpy(mount_drive, "cache0:");
         return 0;
      case 0xCE:
      case 0xCF:
         {
            int res = proc_generate_random_path_23D4FBC("td", mount_drive);
            if (res)
               return res;

            mount_drive[14] = ':';
            mount_drive[15] = 0;
            return 0;
         }
      }
      #pragma endregion
   }
   else if((mount_id > 0xCF) && (mount_id < 0x12E)) //these mounts still should be allowed but mount_drive have to be provided explicitly
   {
      return 0x80800001;
   }
   else if((mount_id >= 0x12E) && (mount_id <= 0x130))
   {
      #pragma region
      switch(mount_id)
      {
      case 0x12E:
         strcpy(mount_drive, "trophy_sys0:");
         return 0;
      case 0x12F:
         strcpy(mount_drive, "trophy_dat0:");
         return 0;
      case 0x130:
         strcpy(mount_drive, "trophy_dbk0:");
         return 0;
      }
      #pragma endregion
   }
   else if((mount_id > 0x130) && (mount_id < 0x190))
   {
      return 0x80800001;
   }
   else if((mount_id >= 0x190) && (mount_id <= 0x192))
   {
      #pragma region
      switch(mount_id)
      {
      case 0x190:
      case 0x191:
      case 0x192:
         {
            int res = proc_generate_random_path_23D4FBC("ad", mount_drive);
            if (res)
               return res;
            
            mount_drive[14] = ':';
            mount_drive[15] = 0;
            return 0;
         }
      }
      #pragma endregion
   }
   else if((mount_id >= 0x193) && (mount_id <= 0x1F5))
   {
      #pragma region
      int res = proc_generate_random_path_23D4FBC("ad", mount_drive);
      if (res)
         return res;

      mount_drive[14] = ':';
      mount_drive[15] = 0;
      return 0;
      #pragma endregion
   }
   else if((mount_id > 0x1F5) && (mount_id < 0x1F8))
   {
      return 0x80800001;
   }
   else if((mount_id >= 0x1F8) && (mount_id <= 0x1F9))
   {
      #pragma region
      switch(mount_id)
      {
      case 0x1F8:
         strcpy(mount_drive, "sdimport0:");
         return 0;
      case 0x1F9:
         strcpy(mount_drive, "sdimport_tmp0:");
         return 0;
      }
      #pragma endregion
   }
   else if ((mount_id > 0x1F9) && (mount_id < 0x258))
   {
      return 0x80800001;
   }
   else if(mount_id == 0x258)
   {
      #pragma region
      int res = proc_generate_random_path_23D4FBC("lm", mount_drive);
      if (res)
         return res;
      
      mount_drive[14] = ':';
      mount_drive[15] = 0;
      return 0;
      #pragma endregion
   }
   else if ((mount_id > 0x258) && (mount_id < 0x3E8))
   {
      return 0x80800001;
   }
   else if((mount_id >= 0x3E8) && (mount_id <= 0x3EB))
   {
      #pragma region
      switch(mount_id)
      {
      case 0x3E8:
      case 0x3E9:
         _snprintf(mount_drive, 0x10u, "app%1u:", 0);
         return 0;
      case 0x3EA:
      case 0x3EB:
         _snprintf(mount_drive, 0x10u, "addcont%1u:", 0);
         return 0;
      }
      #pragma endregion
   }
   else if(mount_id == 0x3EC) //these mounts still should be allowed but mount_drive have to be provided explicitly
   {
      return 0x80800001;
   }
   else if((mount_id >= 0x3ED) && (mount_id <= 0x3F1))
   {
      #pragma region
      switch(mount_id)
      { 
      case 0x3ED:
      case 0x3EE:
         _snprintf(mount_drive, 0x10u, "savedata%1u:", 0);
         return 0;
      case 0x3EF:
      case 0x3F0:
         {
            int res = proc_generate_random_path_23D4FBC("sd", mount_drive);
            if (res)
               return res;
            
            mount_drive[14] = ':';
            mount_drive[15] = 0;
            return 0;
         }
      case 0x3F1:
         {
            int res = proc_generate_random_path_23D4FBC("ud", mount_drive);
            if (res)
               return res;

            mount_drive[14] = ':';
            mount_drive[15] = 0;
            return 0;
         }
      }
      #pragma endregion
   }
   else if(mount_id > 0x3F1)
   {
      return 0x80800001;
   }
}

//===================

int create_mountpoint_base_23D9B50(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, unsigned int mount_id, const char *title_id, const char *physical_path, const char *mount_drive, const char *klicensee, char *mount_point_result)
{
   if (!mount_point_result)
      return 0x80800001;

   char mount_drive_input[16];
   memset(mount_drive_input, 0, 0x10);

   if (mount_drive)
   {
      memcpy(mount_drive_input, mount_drive, 0x10);
   }
   else
   {
      int gen_res = generate_mount_drive(mount_id, mount_drive_input);
      if(gen_res)
         return gen_res;
   }

   //===========================================

   //this may find mountpoint and return with result in mount_point_result

   if (mount_ctx_holder->first_virt_mount)
   {
      int error_code = 0;
      if(!maybe_find_mount(pid, mount_ctx_holder, mount_id, mount_drive, mount_drive_input, mount_point_result, error_code))
         return error_code;
   }

   //===========================================

   //allocate and initialize appmgr_mount

   ctx_49D4DD9B alloc_ctx00;
   alloc_ctx00.unk0 = 0x14;
   alloc_ctx00.unk4 = 0;
   alloc_ctx00.unk8 = 0x20;
   alloc_ctx00.unkC = 0;
   alloc_ctx00.unk10 = 0;

   appmgr_mount_t * virt_mount = (appmgr_mount_t *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x24u, &alloc_ctx00);
   if (virt_mount == 0)
      return 0x80801006;

   memset(virt_mount, 0, 0x24u);

   // copy generated drive to virt_mount

   memcpy(virt_mount->appmgr_rnd_drive_id, mount_drive_input, 0x10); 

   //=========================================== 

   //allocate and initialize physical path copy
   
   ctx_49D4DD9B alloc_ctx01;
   alloc_ctx01.unk0 = 0x14;
   alloc_ctx01.unk4 = 0;
   alloc_ctx01.unk8 = 0x20;
   alloc_ctx01.unkC = 0;
   alloc_ctx01.unk10 = 0;

   char *physical_path_local = (char *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx01);
   if (physical_path_local == 0)
      return label_21_cleanup(pid, virt_mount, physical_path_local, 0x80801006);

   memset(physical_path_local, 0, 0x124u);

   int res0 = verify_copy_23D5A10(physical_path, physical_path_local);
   if (res0 > 0)
      return label_21_cleanup(pid, virt_mount, physical_path_local, res0);

   if (strnlen(physical_path_local, 0x124) >= 0x124)
      return label_21_cleanup(pid, virt_mount, physical_path_local, 0x80800001);

   //===========================================

   SceSelfAuthInfo auth_ctx0;

   int res1 = SceProcessmgrForKernel_sceKernelGetSelfAuthInfoForKernel_e4c83b0d(pid, &auth_ctx0);
   if (res1 < 0)
   {
      if (res1 != 0x80800003)
         return label_21_cleanup(pid, virt_mount, physical_path_local, res1);
      else
         return label_113_cleanup(pid, mount_id, mount_ctx_holder, virt_mount, physical_path_local, mount_point_result);
   }

   SceUInt64 auth_id = auth_ctx0.auth_id;

   //=========================================== 

   if (mount_point_entries_22D470C)
   {
      int error_code = 0;
      if(!entries_stuff(pid, mount_id, mount_ctx_holder, virt_mount, physical_path_local, mount_point_result, auth_id, error_code))
         return error_code;
   }
   
   //=========================================== 

   //allocate and init pfs_mount_t

   ctx_49D4DD9B alloc_ctx02;
   alloc_ctx02.unk4 = 0;
   alloc_ctx02.unkC = 0;
   alloc_ctx02.unk10 = 0;
   alloc_ctx02.unk0 = 20;
   alloc_ctx02.unk8 = 32;

   pfs_mount_t *pfs_mount = (pfs_mount_t *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForKernel_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x1D0u, &alloc_ctx02);
   if (!pfs_mount)
   {
      virt_mount->this_pfs_mount = 0;
      return label_21_cleanup(pid, virt_mount, physical_path_local, 0x80801006);
   }

   memset(pfs_mount, 0, 0x1D0u);

   pfs_mount->mount_id = mount_id;
   strncpy(pfs_mount->path, physical_path_local, 0x123u); //copy physical path to pfs_mount_t
   memcpy(pfs_mount->title_id, title_id, 0x10);

   //===========================================

   if (mount_id == 0x258)
      return create_loopback_mount(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path_local, mount_point_result, auth_id);
   
   //===========================================   

   int result2 = proc_generate_random_path_23D4FBC("PD", pfs_mount->pfs_rnd_drive_id);
   if (result2 < 0)
      return mpd_cleanup(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path_local, mount_point_result, result2 != 0x80800003, result2);

   if (strncmp(pfs_mount->path, "host0:", 6u) == 0)
      pfs_mount->pfs_rnd_drive_id[0] = 0;

   //===========================================

   return create_mountpoint_core(pid, mount_ctx_holder, virt_mount, pfs_mount, physical_path_local, auth_id, klicensee, mount_point_result);
}