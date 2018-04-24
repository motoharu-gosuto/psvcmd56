#include "SceAppMgr.h"

#include "Constants.h"

#include "SceThreadmgr.h"
#include "SceSysmem.h"
#include "SceSysmemGlobalVariables.h"
#include "SceIofilemgr.h"
#include "SceSblACMgr.h"
#include "SceSblSsMgr.h"
#include "SceFios2Kernel.h"

#include <string>
#include <cstdint>

//==============================

int loc_23D5220()
{
   /*
   MOV             R0, R5
   BL              sub_23EFA40
   MOVS            R0, #0
   BLX             SceAppMgr.SceKernelSuspendForDriver._imp_2bb92967
   LDR             R2, [SP,#0x88+var_2C]
   MOV             R0, R4
   LDR.W           R3, [R10]
   CMP             R2, R3
   */

   //return r0 or stack fail

   return 0;
}

int loc_23D52BC()
{
   //MOVS            R4, 0x80800034
   return loc_23D5220();
}

int loc_23D518E()
{
   //  more code

   return 0;
}

int loc_23D50A0()
{
   /*
   ADD.W           R8, SP, #0x88+var_78
   ADD             R7, SP, #0x88+var_70
   ADD.W           R9, SP, #0x88+var_68
   MOVW            R1, #(aCategory_0 AND 0xFFFF) ; "CATEGORY"
   MOV             R2, R8
   MOV             R3, R7
   STR.W           R9, [SP,#0x88+arg_0]
   MOVT.W          R1, #high16(aCategory_0) ; "CATEGORY"
   MOV             R0, R5
   BL              sub_23EF8DC
   SUBS            R4, R0, #0
   */

   //if(r4 < 0)
   //{
   //   return loc_23D5220();
   //}
   //else
   //{
      /*
      LDR             R3, [SP,#0x88+var_70]
      */

      //if(r3 <= 2)
      //{
      //   return loc_23D52BC();
      //}
      //else
      //{
         /*
         LDR             R4, [SP,#0x88+var_68]
         */

         //if(r4 != 4)
         //{
         //   return loc_23D52BC();
         //}
         //else
         //{
            /*
            LDR             R3, [SP,#0x88+var_78]
            MOV             R1, dword_24047E0 ; 024047E0 data reference 00007067
            MOV             R2, R4
            MOV             R0, R3
            STR             R3, [SP,#0x88+var_7C]
            BLX             SceAppMgr.SceSysclibForDriver._imp_strncmp_12cee649
            */

            //if(r0 == 0)
            //{
               /*
               LDR.W           R2, [R6,#0x160]
               LSLS            R3, R2, #0x1F
               */

               //if(!true) //NOT BPL
               //{
                  /*
                  MOVW            R1, #(dword_24047E4 AND 0xFFFF) ; 024047E4 data reference 00006467
                  MOV             R2, R4
                  MOVT.W          R1, #high16(dword_24047E4) ; 024047E4 data reference 00006467
                  ADD.W           R0, R6, #0x298
                  BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
                  */
               //}
            //}
            //else
            //{
               /*
               MOVW            R1, #(aGpc AND 0xFFFF) ; "gpc"
               LDR             R0, [SP,#0x88+var_7C]
               MOVT.W          R1, #high16(aGpc) ; "gpc"
               MOV             R2, R4
               BLX             SceAppMgr.SceSysclibForDriver._imp_strncmp_12cee649
               */

               //if(r0 != 0)
               //{
                  /*
                  MOVW            R1, #(aGpd AND 0xFFFF)
                  LDR             R0, [SP,#0x88+var_7C]
                  MOVT.W          R1, #high16(aGpd) ; "gpd"
                  MOV             R2, R4
                  BLX             SceAppMgr.SceSysclibForDriver._imp_strncmp_12cee649
                  */

                  //if(r0 != 0)
                  //{
                     /*
                     LDR             R1, [SP,#0x88+var_7C]
                     MOV             R2, R4
                     ADD.W           R0, R6, #0x298
                     BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
                     MOVS            R3, #0
                     STRB.W          R3, [R6,#0x29B]
                     */
                  //}
                  //else
                  //{
                     /*
                     LDR.W           R3, [R6,#0x160]
                     LSLS            R0, R3, #0x1F
                     */

                     //if(!true) //NOT BPL
                     //{
                        /*
                        MOV             R3, aGdd ; "gdd"
                        LDR             R0, [R3]
                        STR.W           R0, [R6,#0x298]
                        */
                     //}
                  //}
               //}
               //else
               //{
                  /*
                  LDR.W           R3, [R6,#0x160]
                  LSLS            R4, R3, #0x1F
                  */

                  //if(true) //BMI
                  //{
                     /*
                     MOV             R3, aGdc ; "gdc"
                     LDR             R0, [R3]
                     STR.W           R0, [R6,#0x298]
                     */
                  //}
               //}
            //}

            //loc_23D5110:

            /*
            MOVW            R1, #(aTitle_id AND 0xFFFF) ; "TITLE_ID"
            STR.W           R9, [SP,#0x88+arg_0]
            MOVT.W          R1, #high16(aTitle_id) ; "TITLE_ID"
            MOV             R0, R5
            MOV             R2, R8
            MOV             R3, R7
            BL              sub_23EF8DC
            SUBS            R4, R0, #0
            */

            //if(r4 < 0)
            //{
               //return loc_23D5220();
            //}
            //else
            //{
               /*
               LDR             R3, [SP,#0x88+var_70]
               */

               //if(r3 <= 9)
               //{
                  //return  loc_23D52BC();
               //}
               //else
               //{
                  /*
                  LDR             R3, [SP,#0x88+var_68]
                  */
                  //if(r3 != 0x0C)
                  //{
                     //return loc_23D52BC();
                  //}
                  //else
                  //{
                     /*
                     ADD.W           R4, R6, #0x378
                     LDR             R1, [SP,#0x88+var_78]
                     MOVS            R2, #0xA
                     MOV             R0, R4
                     BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
                     MOVS            R3, #0
                     LDR.W           LR, [R6,#0x37C]
                     STRB.W          R3, [R6,#0x381]
                     LDR.W           R1, [R6,#0x384]
                     LDR.W           R0, [R6,#0x380]
                     LDR.W           R12, [R6,#0x378]
                     STR.W           LR, [R6,#0x38C]
                     STR.W           R0, [R6,#0x390]
                     STR.W           R1, [R6,#0x394]
                     LDR.W           LR, [R6,#0x378]
                     LDR.W           R0, [R6,#0x37C]
                     LDR.W           R1, [R6,#0x380]
                     LDR.W           R2, [R6,#0x384]
                     STR.W           R12, [R6,#0x388]
                     STR.W           LR, [R6,#0x498]
                     STR.W           R0, [R6,#0x49C]
                     STR.W           R1, [R6,#0x4A0]
                     STR.W           R2, [R6,#0x4A4]
                     */

                     //return loc_23D518E();
                  //}
               //}
            //}
         //}
      //}
   //}

   return 0;
}

int proc_parse_param_sfo_23D5028(SceUID pid, char *param_sfo_path, int ignore_overlay, phys_ctx_t *gdat_ctx)
{
   /*
   MOV             R10, 0x9EA004
   MOVS            R4, #0
   MOV             R5, R0  ; arg0
   MOVW            R0, #0x4780 ; 023D5038 : external reference: 022D4780
   LDR.W           R7, [R10]
   SUB             SP, SP, #0x64
   MOV             R8, R1  ; arg1
   MOV             R11, R2 ; arg2
   MOV             R1, R4
   MOVT.W          R0, #0x22D ; 023D5048 : external reference: 022D4780
   MOV.W           R2, #0x124
   MOV             R6, R3  ; arg3
   STR             R7, [SP,#0x88+var_2C]
   STRD.W          R4, R4, [SP,#0x30]
   STR             R4, [SP,#0x88+var_50]
   STR             R4, [SP,#0x88+var_78]
   STR             R4, [SP,#0x88+var_70]
   STR             R4, [SP,#0x88+var_68]
   BLX             SceAppMgr.SceSysclibForDriver._imp_memset_0ab9bf5c
   */

   //if(r5 == 0)
   //{
      //BLX             SceAppMgr.SceThreadmgrForDriver._imp_sceKernelGetProcessId_9dcb4b7a
      //MOV             R5, R0
   //}
   
   /*
   MOVS            R0, #0
   BLX             SceAppMgr.SceKernelSuspendForDriver._imp_4df40893
   */

   //if(r11 == 0)
   //{
      /*
      MOVS            R0, #0x80
      BLX             SceAppMgr.SceThreadmgrForDriver._imp_02eedf17
      MOV.W           R1, #0x124
      MOVW            R3, #0x4780 ; 023D524A : external reference: 022D4780
      MOV             R7, R0
      MOV             R2, R8  ; unk2
      MOV             R0, R5  ; unk0
      STR             R1, [SP,#0x88+arg_0] ; arg_0
      MOVT.W          R3, #0x22D ; 023D5256 : external reference: 022D4780
      MOV             R1, R11 ; unk1
      BLX             SceAppMgr.SceFios2KernelForDriver._imp_sceFiosKernelOverlayResolveSyncForDriver_0f456345
      MOV             R4, R0
      MOV             R0, R7
      BLX             SceAppMgr.SceThreadmgrForDriver._imp_02eedf17
      ADD             R5, SP, #0x88+var_58
      */
      //if(r4 != 0)
      //{
         //return loc_23D5220();
      //}
      //else
      //{
         /*
         MOVW            R0, #0x4780 ; 023D526E : external reference: 022D4780
         MOV             R1, R5
         MOVT.W          R0, #0x22D ; 023D5274 : external reference: 022D4780
         BL              sub_23EF934
         SUBS            R4, R0, #0
         */
         //if(r4 < 0)
         //{
            //return loc_23D5220();
         //}
         //else
         //{
            /*
            LDR.W           R3, [R6,#0x160]
            LSLS            R2, R3, #0x1F
            */
            //if(true) //BMI
            //{
               //return loc_23D50A0();
            //}
            //else
            //{
               /*
               ADD.W           R8, SP, #0x88+var_78
               ADD             R7, SP, #0x88+var_70
               ADD.W           R9, SP, #0x88+var_68
               */

               //return loc_23D518E();
            //}
         //}
      //}
   //}
   //else
   //{
      /*
      MOVW            R0, #0x4780 ; 023D5078 : external reference: 022D4780
      MOV             R1, R8
      MOV.W           R2, #0x124
      MOVT.W          R0, #0x22D ; 023D5082 : external reference: 022D4780
      BLX             SceAppMgr.SceSysclibForDriver._imp_6d286146
      ADD             R5, SP, #0x88+var_58
      MOVW            R0, #0x4780 ; 023D508C : external reference: 022D4780
      MOV             R1, R5
      MOVT.W          R0, #0x22D ; 023D5092 : external reference: 022D4780
      BL              sub_23EF934
      SUBS            R4, R0, #0
      */
      //if(r4 < 0)
      //{
         //return loc_23D5220();
      //}
      //else
      //{
         //return loc_23D50A0();
      //}
   //}

   return 0;
}

SceUID SceAppMgrMount_pool_22A0008;

SceUID SceAppMgrMount_mutex_22A000C;

char* PD_str_2404BBC = "PD";

mount_point_data_entry* mount_point_entries_22D470C;

//this function tries to OverlayResolveSync input path
//then checks that it is not a PD path (temp mount point probably aquired by PFS)
//then takes beginning of path until symbol ":"
//then tries to do a lookup by that path copy in mount_point_entries_22D470C item array
//if item is found then path from mount_point_entries_22D470C item is copied to result
//in any other case OverlayResolveSync result path is copied to result

int iofilemgr_1914_callback_23DDE64(const char *path, SceUID pid, char *result_path, int size)
{
   int result = 0;

   int cookie = var_009EA004;
  
   //clear path copy

   char path_copy[33];
   memset(path_copy,0, 0x21); 
 
   int mutex_res = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);

   if (mutex_res >= 0)
   {
      //allocate buffer for overlay path

      ctx_49D4DD9B alloc_ctx;
      alloc_ctx.unk4 = 0;
      alloc_ctx.unkC = 0;
      alloc_ctx.unk10 = 0;
      alloc_ctx.unk0 = 0x14;
      alloc_ctx.unk8 = 0x20;

      char* overlay_resolve_sync_path = (char*)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx);
    
      if ( overlay_resolve_sync_path )
      {
         //get pid if not specified

         SceUID pid_local = pid;
         if (!pid_local)
            pid_local = SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a();

         //overlay resolve sync - input path

         int prev_perm = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80); //set permission
         int overlay_res = SceFios2KernelForDriver_sceFiosKernelOverlayResolveSyncForDriver_0f456345(pid_local, 0, path, overlay_resolve_sync_path, 0x124);
         SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm); //restore permission

         if (overlay_res >= 0 )
         {
            //limit max size

            unsigned int size_local = size;
            if (size >= 0x124 )
               size_local = 0x124;

            //compare to PD string (PFS temp mount point)

            int pd_cmp_result = strncmp(overlay_resolve_sync_path,PD_str_2404BBC, 2u);
            if (pd_cmp_result)
            {
               // copy path from heap to result path

               strncpy(result_path, overlay_resolve_sync_path, size_local);
               result_path[size_local - 1] = 0;// terminate with 0

               //cleanup

               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);

               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

               if(var_009EA004 == cookie)
                  return 0;
               else
                  return STACK_CHECK_FAIL;
            }

            //clear path copy

            memset(path_copy, 0x21, 0);

            int str_index = 0;

            //copy path till ":"
            while ( 1 )
            {
               char str_symbol = overlay_resolve_sync_path[str_index];
               path_copy[str_index] = str_symbol;
               
               //check end symbol
               if ( str_symbol == ':' )
                  break;

               //check max length
               if (++str_index == 0x21 )
               {
                  // copy path from heap to result path

                  strncpy(result_path, overlay_resolve_sync_path, size_local);
                  result_path[size_local - 1] = 0;// terminate with 0

                  //cleanup

                  SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);

                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

                  if(var_009EA004 == cookie)
                     return 0;
                  else
                     return STACK_CHECK_FAIL;
               }
            }

            //terminate path with 0
            path_copy[15] = 0;

            mount_point_data_entry *global_buffer = mount_point_entries_22D470C;

            // if global item is set
            if (global_buffer)
            {
               // do path lookup while strings are not equal
               while (strncmp(global_buffer->gen_mount_point, path_copy, 0x10u) )
               {
                  global_buffer = global_buffer->next; // get pointer to next item
                  if (!global_buffer)
                  {
                     //when there is no next item

                     // copy path from heap to result path

                     strncpy(result_path, overlay_resolve_sync_path, size_local);
                     result_path[size_local - 1] = 0;// terminate with 0

                     //cleanup

                     SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);

                     SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);

                     if(var_009EA004 == cookie)
                        return 0;
                     else
                        return STACK_CHECK_FAIL;
                  }
               }

               // copy path from global to result path

               strncpy(result_path, global_buffer->path, size_local);
               result = 0;
               result_path[size_local - 1] = 0;// terminate with 0
            }
            else
            {
               // copy path from heap to result path

               strncpy(result_path, overlay_resolve_sync_path, size_local);
               result = 0;
               result_path[size_local - 1] = 0;// terminate with 0
            }
         }
         
         SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, overlay_resolve_sync_path);
      }
      else
      {
         result = 0x80801006;
      }

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
   }
  
   //check cookie and return result

   if(var_009EA004 == cookie)
      return result;
   else
      return STACK_CHECK_FAIL;
}

int proc_generate_random_path_23D4FBC(char *prefix, char *result_path)
{   
   int result;
   char random_buffer[8]; // [sp+18h] [bp-28h]

   result = SceSblSsMgrForDriver_sceKernelGetRandomNumberForDriver_4f9bfbe5(random_buffer, 8);
   if(result < 0)
      return result;

   _snprintf(result_path, 0x10u, "%s%02x%02x%02x%02x%02x%02xd", prefix, random_buffer[0], random_buffer[1], random_buffer[2], random_buffer[3], random_buffer[4], random_buffer[5]);
   return 0;
}

int AppMgr_decrypt_str_constant_23D59D4(char* input, char* output)
{
   if(output == 0)
      return 0x80800001;

   if(input == 0)
      return 0x80800001;

   memset(output, 0, 0x20);

   int index = 0;

   while(input[index])
   {
      output[index] = ~input[index];
      if (++index == 0x20)
         return 0x80800001;
   }
  
   output[index] = 0;
   return 0;
}

int AppMgr_decrypt_str_constant_23D5998(char *input, char *output)
{
  if(output == 0)
     return 0x80800001;

  if(input == 0)
     return 0x80800001;

  memset(output, 0, 0x40u);

  int index = 0;

  while (input[index])
  {
    output[index] = ~input[index];
    if (++index == 0x40)
      return 0x80800001;
  }
  
  output[index] = 0;
  return 0;
}

global_ctx_item *__cdecl get_global_ctx_item_23C2DE0(ctx_23C2960 *ctx, SceUID pid)
{
   return 0;
}

int verify_copy_23D5A10(char *src, char *dst)
{
   return 0;
}

//----------------

int create_mountpoint_base_23D9B50(SceUID pid, mount_ctx_holder_t *mount_ctx_holder, int mount_id, char *title_id, char *physical_path, char *mount_drive, void *klicensee, const char *gen_mount_point)
{
   return 0;
}

//----------------

void * alloc_mem_23DDFF8(SceSize size)
{
   return 0;
}

int clearsign_exists_23D9A4C(char *mountpoint)
{
   return 0;
}

int get_klicensee_23D642C(char *rif_file_path, rif_info *rif_info_arg)
{
   return 0;
}

int sceAppMgrCheckRifGD_base_23D9704(char *path, char *titleid, void *dest_with_klicensee)
{
   return 0;
}

int check_package_bin_and_clearsign_23D6314(char *physical_path, int *unk1)
{
   return 0;
}

int get_patch_path_23D6A48(char *path, char *titleId, int some_flag, char *prefix, char *result_path)
{
   return 0;
}

int w_unmount_23D8E80(SceUID pid, mount_ctx_holder_t *mount_ctx_holder, char *gen_mount_point, int umountArg)
{
   return 0;
}

ctx_23C2960 global_contexts_22A0500[20];

int w_SceAppMgrForDriver_sceAppMgrGameDataMountForDriver_ce356b2d(char *app_path, char *patch_path, char *rif_file_path, char *mount_point, char* physical_path_copy, char* alloc_buffer, phys_ctx_t *gdat_ctx)
{
   char md_mount_drive[16];
   char md_mount_point[16];

   memset(md_mount_drive, 0, 0x10);
   memset(md_mount_point, 0, 0x10);

   int last_error;

   global_ctx_item *gctxi = get_global_ctx_item_23C2DE0(global_contexts_22A0500, SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a());

   if (!gctxi)
      return 0x80801002;

   //not sure what this lookup is supposed to do

   last_error = verify_copy_23D5A10(app_path, physical_path_copy);
   if(last_error < 0)
   {
      if (last_error != 0x80800002 )
      {
         //weird check - last_error is already < 0
         if (!last_error)
            return 0x80800017;
         else
            return last_error;
      }
   }
   else
   {
      mount_point_data_entry *mpe = mount_point_entries_22D470C;
      if (mpe)
      {
         bool mpe_found = false;

         // lookup first mpe entry that has id not 0x384 and path not equal to physical path
         while (mpe->mount_id != 0x384 || strncmp(mpe->path, physical_path_copy, 0x124u))
         {
            mpe = mpe->next;
            if (!mpe)
            {
               mpe_found = true;
               break;
            }
         }

         if(!mpe_found)
            return 0x80800017;
      }
   }

   // read and parse param sfo first time - ignore overlay

   char* param_sfo_path = alloc_buffer;
   _snprintf(param_sfo_path, 0x124u, "%s/%s", app_path, "sce_sys/param.sfo");
   
   int prev_perm = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
   last_error = proc_parse_param_sfo_23D5028(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), param_sfo_path, 1, gdat_ctx);
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm);

   if (last_error < 0)
   {
      if (last_error == 0x80010002)
         last_error = 0x8080000D;

      return last_error;
   }

   // check if clearsign exists

   int prev_perm2 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(0x80);
   int clearsign_exists = clearsign_exists_23D9A4C(app_path);
   SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm2);

   // retrieve klicensee if clearsign exists

   if (clearsign_exists)                       
   {
      if (rif_file_path)
      {
         last_error = get_klicensee_23D642C(rif_file_path, &gdat_ctx->rif);
         if (last_error < 0)
            return last_error;
      }
      else
      {
         last_error = sceAppMgrCheckRifGD_base_23D9704(app_path, gdat_ctx->titleId_378, &gdat_ctx->rif);
         if (last_error < 0)
            return last_error;
      }

      //check package - maybe drm free check? (since zeroes dec_rif_key below)

      int package_check_flag = 1;

      int prev_perm3 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
      last_error = check_package_bin_and_clearsign_23D6314(app_path, &package_check_flag);
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm3);
      
      if(last_error < 0)
         return last_error;

      if(package_check_flag)
      {
         memset(gdat_ctx->rif.dec_rif_key, 0, 0x10u);
      }
   }

   // generate random mount drive

   last_error = proc_generate_random_path_23D4FBC("gp", md_mount_drive);
   if (last_error < 0)
      return last_error;

   // if generation was successful

   md_mount_drive[13] = 'd';
   md_mount_drive[14] = ':';
   md_mount_drive[15] = 0;
       
   // mount physical path (probably XX0:app/ variants)

   last_error = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), 
                                               &gctxi->unk_558.mctx_hldr_28, 
                                               0x3E8, 
                                               gdat_ctx->titleId_378, 
                                               app_path, 
                                               md_mount_drive, 
                                               gdat_ctx->rif.dec_rif_key, 
                                               md_mount_point);

   if(last_error < 0)
      return last_error;

   // read and parse param sfo second time - do not ignore overlay

   last_error = proc_parse_param_sfo_23D5028(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), param_sfo_path, 0, gdat_ctx);
   if(last_error < 0)
   {
      w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
      return last_error;
   }

   // finally copy temp mount point to result

   memcpy(mount_point, md_mount_point, 0x10);

   //try to mount patch directory

   char* patch_path_copy = alloc_buffer;

   //if path is provided or not

   if(patch_path)
   {
      strncpy(patch_path_copy, patch_path, 0x124u);
      patch_path_copy[291] = 0;

      // simple check that dir exists

      SceIoStat stat;
      int prev_perm4 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
      int stat_res0 = SceIofilemgrForDriver_sceIoGetstatForDriver_75c96d25(patch_path_copy, &stat);
      SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm4);
      
      //try to mount if directory exists

      if(stat_res0 >= 0)
      {
         last_error = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), 
                                                     &gctxi->unk_558.mctx_hldr_28, 
                                                     0x3E9, 
                                                     gdat_ctx->titleId_378, 
                                                     patch_path_copy, 
                                                     md_mount_drive, 
                                                     gdat_ctx->rif.dec_rif_key, 
                                                     md_mount_point);

         if(last_error < 0)
         {
            //unmount previous app_path if patch directory mount has failed - this is an error

            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
            return last_error;
         }
         else
         {
            //copy new temp mount point - this is success

            memcpy(mount_point, md_mount_point, 0x10);
            return last_error;
         }
      }
      else
      {
         //not sure what is this check for invalid - maybe you can set an argument as invalid?

         int cmp_res = strncmp(patch_path_copy, "invalid:", 9u);
         if (cmp_res)
         {
            //unmount previous app_path if patch directory was invalid

            w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
            return 0x8080000F;
         }
         else
         {
            //do not unmount previous mount of app_path if patch directory did not exist - this is still a success

            return 0;
         }
      }
   }
   else
   {
      //if path is not provided - try to constuct it

      int get_patch_res = get_patch_path_23D6A48(app_path, gdat_ctx->titleid_388, gdat_ctx->flag_29C, gdat_ctx->prefix_298, patch_path_copy);
      if (get_patch_res >= 0)
      {
         // simple check that dir exists

         SceIoStat stat;
         int prev_perm5 = SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(128);
         int stat_res1 = SceIofilemgrForDriver_sceIoGetstatForDriver_75c96d25(patch_path_copy, &stat);
         SceThreadmgrForDriver_ksceKernelSetPermission_02eedf17(prev_perm5);
         
         if (stat_res1 >= 0)
         {
            last_error = create_mountpoint_base_23D9B50(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), 
                                                        &gctxi->unk_558.mctx_hldr_28, 
                                                        0x3E9, 
                                                        gdat_ctx->titleId_378, 
                                                        patch_path_copy, 
                                                        md_mount_drive, 
                                                        gdat_ctx->rif.dec_rif_key, 
                                                        md_mount_point);
            if (last_error < 0)
            {
               //unmount previous app_path if patch directory mount has failed - this is an error

               w_unmount_23D8E80(SceThreadmgrForDriver_ksceKernelGetProcessId_9dcb4b7a(), &gctxi->unk_558.mctx_hldr_28, md_mount_point, 0);
               return last_error;
            }
            else
            {
               //copy new temp mount point - this is success

               memcpy(mount_point, md_mount_point, 0x10);
               return last_error;
            }
         }
         else
         {
            //do not unmount previous mount of app_path if patch directory did not exist - this is still a success

            return 0;
         }
      }
      else
      {
         //do not unmount previous mount of app_path if unable to construct path to patch directory - this is still a success

         return 0;
      }
   }
}

//a user probably have to setup an overlay with fios2 prior to calling this function
//if he wants to use a patch_path argument

int SceAppMgrForDriver_sceAppMgrGameDataMountForDriver_ce356b2d(char *app_path, char *patch_path, char *rif_file_path, char *mount_point)
{ 
   int cookie = var_009EA004;

   //check args

   if (mount_point == 0 || app_path == 0)
      return var_009EA004 == cookie ? 0x80800001 : STACK_CHECK_FAIL;

   //lock mutex

   int lock_res = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(SceAppMgrMount_mutex_22A000C, 1, 0);
   if (lock_res < 0)
      return var_009EA004 == cookie ? lock_res : STACK_CHECK_FAIL;

   //allocate buffer

   ctx_49D4DD9B alloc_ctx0;
   alloc_ctx0.unk0 = 0x14;
   alloc_ctx0.unk4 = 0;
   alloc_ctx0.unkC = 0;
   alloc_ctx0.unk10 = 0;
   alloc_ctx0.unk8 = 0x20;

   char* physical_path_copy = (char*)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx0);
   if (!physical_path_copy)
   {
      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return var_009EA004 == cookie ? 0x80801006 : STACK_CHECK_FAIL;
   }

   //allocate buffer

   ctx_49D4DD9B alloc_ctx1;
   alloc_ctx1.unk0 = 20;
   alloc_ctx1.unk4 = 0;
   alloc_ctx1.unk8 = 32;
   alloc_ctx1.unkC = 0;
   alloc_ctx1.unk10 = 0;
   
   char* alloc_buffer = (char *)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(SceAppMgrMount_pool_22A0008, 0x124u, &alloc_ctx1);
   if (!alloc_buffer)
   {
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path_copy);

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return var_009EA004 == cookie ? 0x80801006 : STACK_CHECK_FAIL;
   }

   //allocate object

   phys_ctx_t *gdat_ctx = (phys_ctx_t *)alloc_mem_23DDFF8(0x508u);
   if(!gdat_ctx)
   {
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path_copy);
      SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, alloc_buffer);

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
      return var_009EA004 == cookie ? 0x80801006 : STACK_CHECK_FAIL;
   }

   memset(gdat_ctx, 0, 0x508u);

   int result = w_SceAppMgrForDriver_sceAppMgrGameDataMountForDriver_ce356b2d(app_path, patch_path, rif_file_path, mount_point, physical_path_copy, alloc_buffer, gdat_ctx);

   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, physical_path_copy);
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, alloc_buffer);
   SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(SceAppMgrMount_pool_22A0008, gdat_ctx);

   SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
   return var_009EA004 == cookie ? result : STACK_CHECK_FAIL;
}

