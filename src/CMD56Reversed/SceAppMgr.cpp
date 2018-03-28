#include "Constants.h"

#include "SceThreadmgr.h"
#include "SceSysmem.h"
#include "SceSysmemGlobalVariables.h"

#include <string>
#include <cstdint>

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

int proc_parse_param_sfo_23D5028(SceUID pid, int unk1, int unk2, int unk3)
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


struct mount_point_data_entry
{
  int mount_id;
  char path[0x124];
  char mount_point[0x10];
  char title_id[0x10];
  SceUInt64 auth_ids[0x10];
  mount_point_data_entry *prev;
  mount_point_data_entry *next;
};

SceUID mutex_22A000C;

SceUID pool_22A0008;

char* PD_str_2404BBC = "PD";

mount_point_data_entry* var_22D470C;

int SceFios2KernelForDriver_sceFiosKernelOverlayResolveSyncForDriver_0f456345(SceUID pid, int resolveFlag, const char *pInPath, char *pOutPath, size_t maxPath)
{
   return 0;
}

//this function tries to OverlayResolveSync input path
//then checks that it is not a PD path (temp mount point probably aquired by PFS)
//then takes beginning of path until symbol ":"
//then tries to do a lookup by that path copy in var_22D470C item array
//if item is found then path from var_22D470C item is copied to result
//in any other case OverlayResolveSync result path is copied to result

int iofilemgr_1914_callback_23DDE64(const char *path, SceUID pid, char *result_path, int size)
{
   int result = 0;

   int cookie = var_009EA004;
  
   //clear path copy

   char path_copy[33];
   memset(path_copy,0, 0x21); 
 
   int mutex_res = SceThreadmgrForDriver_ksceKernelLockMutex_16AC80C5(mutex_22A000C, 1, 0);

   if (mutex_res >= 0)
   {
      //allocate buffer for overlay path

      ctx_49D4DD9B alloc_ctx;
      alloc_ctx.unk4 = 0;
      alloc_ctx.unkC = 0;
      alloc_ctx.unk10 = 0;
      alloc_ctx.unk0 = 0x14;
      alloc_ctx.unk8 = 0x20;

      char* overlay_resolve_sync_path = (char*)SceSysmemForDriver_sceKernelAllocHeapMemory3ForDriver_49D4DD9B(pool_22A0008, 0x124u, &alloc_ctx);
    
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

               SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(pool_22A0008, overlay_resolve_sync_path);

               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(mutex_22A000C, 1);

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

                  SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(pool_22A0008, overlay_resolve_sync_path);

                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(mutex_22A000C, 1);

                  if(var_009EA004 == cookie)
                     return 0;
                  else
                     return STACK_CHECK_FAIL;
               }
            }

            //terminate path with 0
            path_copy[15] = 0;

            mount_point_data_entry *global_buffer = var_22D470C;

            // if global item is set
            if (global_buffer)
            {
               // do path lookup while strings are not equal
               while (strncmp(global_buffer->mount_point, path_copy, 0x10u) )
               {
                  global_buffer = global_buffer->next; // get pointer to next item
                  if (!global_buffer)
                  {
                     //when there is no next item

                     // copy path from heap to result path

                     strncpy(result_path, overlay_resolve_sync_path, size_local);
                     result_path[size_local - 1] = 0;// terminate with 0

                     //cleanup

                     SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(pool_22A0008, overlay_resolve_sync_path);

                     SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(mutex_22A000C, 1);

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
         
         SceSysmemForDriver_ksceKernelMemPoolFree_3ebce343(pool_22A0008, overlay_resolve_sync_path);
      }
      else
      {
         result = 0x80801006;
      }

      SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(mutex_22A000C, 1);
   }
  
   //check cookie and return result

   if(var_009EA004 == cookie)
      return result;
   else
      return STACK_CHECK_FAIL;
}

struct mount_ctx_t
{
  mount_point_data_entry *unk0;
  int unk4;
  char gen_path[16];
  int unk18;
  int unk1C;
  mount_ctx_t *next;
};


struct mount_ctx_holder_t
{
  int unk0;
  mount_ctx_t *mount;
};

struct ctx_49d4dd9b
{
  int unk0;
  int unk4;
  int unk8;
  int unkC;
  int unk10;
};

struct process_auth_id_ctx
{
  uint64_t auth_id;
  uint32_t unk_10[20];
  uint32_t unk_60;
  uint32_t unk_64;
  char klicensee[16];
  uint32_t unk_78;
  uint32_t unk_7C;
  uint32_t unk_80;
  uint32_t unk_84;
  uint32_t unk_88;
  uint32_t unk_8C;
  uint32_t unk_90;
  uint32_t unk_94;
};

int SceSblSsMgrForDriver_sceKernelGetRandomNumberForDriver_4f9bfbe5(char* result, int size)
{
   return 0;
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

typedef struct SceSelfAuthInfo // size is 0x90
{
   SceUInt64 auth_id;
   
   uint32_t unk_10[20];
   
   uint32_t unk_60;
   uint32_t unk_64;
   char klicensee[0x10]; // offset 0x68
   
   uint32_t unk_78;
   uint32_t unk_7C;
   
   uint32_t unk_80;
   uint32_t unk_84;
   uint32_t unk_88;
   uint32_t unk_8C;
   
   uint32_t unk_90;
   uint32_t unk_94;
} SceSelfAuthInfo;

int SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(SceUID pid, SceSelfAuthInfo *self_info)
{
   return 0;
}

int SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd_SceSblACMgrForKernel_sceSblACMgrGetSelfAuthInfoOrDefaultForKernel_7c2af978(SceUID pid, std::uint64_t* authid)
{   
   if ( !authid)
      return 0x800F0916;

   SceSelfAuthInfo self_info;
   
   if (SceSysrootForKernel_sceSysrootGetSelfAuthInfoOrDefaultForKernel_4f0a4066(pid, &self_info) != 0)
      return 0x800F0916;

   *authid = self_info.auth_id;
   
   return 0;
}

int SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7_SceSblACMgrForKernel_sceSblACMgrCheckAuthIdForKernel_f5ad56e4(SceUID pid)
{
  std::uint64_t authid = 0;
  
   if (SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd_SceSblACMgrForKernel_sceSblACMgrGetSelfAuthInfoOrDefaultForKernel_7c2af978(pid, &authid) != 0)
      return 0;
    
   if (authid == 0x2800000000000013)
      return 1;

   if (authid == 0x2800000000007009)
      return 1;

   if (authid == 0x2800000000000010)
      return 1;

   if (authid == 0x280000000000002D)
      return 1;
    
   if (authid == 0x2800000000000022)
      return 1;

   if (authid == 0x2800000000000039)
      return 1;
    
   if (authid == 0x2800000000000001)
      return 1;

   return 0;
}

int get_random_path(int mount_id, const char *random_path_init, char* random_path_buffer)
{
   if (random_path_init)
   {
      memcpy(random_path_buffer, random_path_init, 16);
      return 0;
   }
   else if (mount_id <= 0x192)
   {
      if (mount_id >= 0x190)
      {
         int ad_res = proc_generate_random_path_23D4FBC("ad", random_path_buffer);
         if (ad_res)
            return ad_res;
         
         random_path_buffer[14] = ':';
         random_path_buffer[15] = 0;
         return 0;
      }
      else if (mount_id <= 0xCC)
      {
         if (mount_id < 0xCB)
         {
            if (mount_id > 0xC9)
            {
               if (SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7_SceSblACMgrForKernel_sceSblACMgrCheckAuthIdForKernel_f5ad56e4(0))
               {
                  strcpy(random_path_buffer, "ms0:");
                  return 0;
               }
               else
               {
                  int res_ms = proc_generate_random_path_23D4FBC("ms", random_path_buffer);
                  if (res_ms)
                     return res_ms;

                  random_path_buffer[14] = ':';
                  random_path_buffer[15] = 0;
                  return 0;
               }
            }
            else if (mount_id < 0xC8)
            {
               if ((mount_id - 100) > 0xC)
               {
                  return 0x80800001;
               }
               else
               {
                  int ad_res = proc_generate_random_path_23D4FBC("ad", random_path_buffer);
                  if (ad_res)
                     return ad_res;

                  random_path_buffer[14] = ':';
                  random_path_buffer[15] = 0;
                  return 0;
               }
            }
         }
      }
      else
      {
         if (mount_id > 0xCF)
         {
            switch (mount_id)
            {
            case 0x12F:
               {
                  strcpy(random_path_buffer, "trophy_dat0:");
                  return 0;
               }
            case 0x130:
               {
                  strcpy(random_path_buffer, "trophy_dbk0:");
                  return 0;
               }
            case 0x12E:
               {
                  strcpy(random_path_buffer, "trophy_sys0:");
                  return 0;
               }
            default:
               return 0x80800001;
            }
         }
         else if (mount_id < 0xCE )
         {
            strcpy(random_path_buffer, "cache0:");
            return 0;
         }
      }

      int td_res = proc_generate_random_path_23D4FBC("td", random_path_buffer);
      if (td_res)
         return td_res;

      random_path_buffer[14] = ':';
      random_path_buffer[15] = 0;
      return 0;
   }
   else if (mount_id > 0x3E9)
   {
      if (mount_id <= 0x3EE)
      {
         if (mount_id > 0x3EC)
         {
            _snprintf(random_path_buffer, 0x10u, "savedata%1u:", 0);
            return 0;
         }
         else
         {
            if (mount_id >= 0x3EC)
            {
               return 0x80800001;
            }
            else
            {
               _snprintf(random_path_buffer, 0x10u, "addcont%1u:", 0);
               return 0;
            }
         }
      }
      else if (mount_id <= 0x3F0)
      {
         int res_sd = proc_generate_random_path_23D4FBC("sd", random_path_buffer);
         if (res_sd)
            return res_sd;

         random_path_buffer[14] = ':';
         random_path_buffer[15] = 0;
         return 0;
      }
      else if(mount_id == 0x3F1)
      {
         int res_ud = proc_generate_random_path_23D4FBC("ud", random_path_buffer);
         if (res_ud)
            return res_ud;

         random_path_buffer[14] = ':';
         random_path_buffer[15] = 0;
         return 0;
      }
      else
      {
         return 0x80800001;
      }
   }
   else if (mount_id >= 0x3E8)
   {
      _snprintf(random_path_buffer, 0x10u, "app%1u:", 0);
      return 0;
   }
   else if (mount_id == 0x1F8)
   {
      strcpy(random_path_buffer, "sdimport0:");
      return 0;
   }
   else if (mount_id <= 0x1F8)
   {
      if ((mount_id - 0x1F4) > 1)
      {
         return 0x80800001;
      }
      else
      {
         int res_ad = proc_generate_random_path_23D4FBC("ad", random_path_buffer);
         if (res_ad)
            return res_ad;

         random_path_buffer[14] = ':';
         random_path_buffer[15] = 0;
         return 0;
      }
   }
   else if (mount_id != 0x1F9)
   {
      if (mount_id == 0x258)
      {
         int res_lm = proc_generate_random_path_23D4FBC("lm", random_path_buffer);
         if (res_lm)
            return res_lm;

         random_path_buffer[14] = ':';
         random_path_buffer[15] = 0;
         return 0;
      }
      else
      {
         return 0x80800001;
      }
   }
   else
   {
      strcpy(random_path_buffer, "sdimport_tmp0:");
      return 0;
   }
}

int __cdecl proc_mount_PDrnd0_23D9B50(int unk0, mount_ctx_holder_t *mount_ctx_holder, unsigned int some_numeric_id, int *title_id, int arg_0, char *random_path_init, void *klicensee, const char *mount_point)
{
   int *title_id_local; // r10
   unsigned int some_numeric_id_copy; // r4
   //int rnd_init1; // r1
   //int rnd_init2; // r2
   //int rnd_init3; // r3
   mount_ctx_t *mount_ctx_local; // r7
   char *gen_path_local; // r8
   int gen_path_chunk1; // r1
   int gen_path_chunk2; // r2
   int gen_path_chunk3; // r3
   mount_ctx_t *mount_ctx_local2; // r7
   int result2; // r8
   int result; // r0
   mount_ctx_t *v21; // r0
   int v22; // r1
   int v23; // r2
   int v24; // r3
   SceUID v25; // r0
   char *buffer_124; // r0
   int v27; // r4
   mount_point_data_entry *mount_item_var; // r6
   mount_ctx_t *v29; // r3
   int result1; // r0
   __int64 auth_id1; // r1
   int v32; // r5
   int v33; // r7
   mount_point_data_entry *global_mount_path_item_ptr; // r6
   signed int initialized_global_item_index; // r3
   __int64 auth_id2; // r1
   int v37; // r0
   bool v38; // r10
   mount_ctx_t *v39; // r3
   int v40; // r1
   int v41; // r2
   int v42; // r3
   mount_point_data_entry *allocated_buffer; // r0
   mount_point_data_entry *allocated_buffer_copy; // r6
   int title_id_chunk1; // r2
   int title_id_chunk2; // r3
   int title_id_chunk3; // lr
   char *pd_random_path; // r10
   unsigned int v49; // r3
   int klicensee_chunk1; // r1
   unsigned int v51; // r7
   int klicensee_chunk2; // r2
   int klicensee_chunk3; // r3
   signed int initialized_allocated_item_index; // r3
   int v55; // r9
   mount_point_data_entry *v56; // r1
   int v57; // r0
   int v58; // r0
   mount_ctx_t *v59; // r4
   mount_point_data_entry *v60; // r6
   int prev_prem; // r9
   unsigned int v62; // r0
   unsigned int v63; // r2
   int v64; // r3
   mount_point_data_entry *v65; // r6
   mount_point_data_entry *global_mount_item; // r2
   int klicensee_chunk1_1; // r1
   int klicensee_chunk1_2; // r2
   int klicensee_chunk1_3; // r3
   int v70; // r6
   char *v71; // r1
   __int64 auth_id3; // r1
   unsigned int v73; // r0
   __int64 auth_id4; // r1
   unsigned int v75; // r3
   int v76; // r3
   char *pd_random_path1; // r0
   unsigned int v78; // r0
   __int64 auth_id5; // r1
   unsigned int v80; // r3
   signed int v81; // r3
   int v82; // r0
   __int64 auth_id6; // r1
   bool v84; // r3
   char *pd_random_pat2; // r0
   unsigned int v86; // r0
   unsigned int v87; // r3
   int v88; // r1
   int v89; // r2
   int v90; // r3
   mount_ctx_holder_t *mount_ctx_holder_local; // [sp+14h] [bp-124h]
   mount_point_data_entry *allocated_mount_path_item_ptr; // [sp+18h] [bp-120h]
   mount_ctx_t *v93; // [sp+1Ch] [bp-11Ch]
   int pid; // [sp+20h] [bp-118h]
   char *v95; // [sp+28h] [bp-110h]
   char *buffer_124_copy; // [sp+2Ch] [bp-10Ch]
   uint64_t auth_id; // [sp+30h] [bp-108h]
   char *mountpoint; // [sp+38h] [bp-100h]
   ctx_49d4dd9b ctx; // [sp+44h] [bp-F4h]
   char random_path_buffer[16]; // [sp+58h] [bp-E0h]
   char secret[4]; // [sp+68h] [bp-D0h]
   int v102; // [sp+6Ch] [bp-CCh]
   int v103; // [sp+70h] [bp-C8h]
   int v104; // [sp+74h] [bp-C4h]
   process_auth_id_ctx auth_ctx; // [sp+78h] [bp-C0h]
   int cookie; // [sp+10Ch] [bp-2Ch]

   title_id_local = title_id;
   some_numeric_id_copy = some_numeric_id;
   cookie = var_009EA004;
   pid = unk0;
   mount_ctx_holder_local = mount_ctx_holder;

   memset(random_path_buffer, 0, 16);

   if (!mount_point)
      return 0x80800001;

   int grp_res = get_random_path(some_numeric_id, random_path_init, random_path_buffer);
   if(grp_res < 0)
      return grp_res;

LABEL_4:
/*
  mount_ctx_local = mount_ctx_holder_local->mount;
  if ( mount_ctx_local )
  {
    if ( some_numeric_id_copy >= 0x3E8 )
    {
      while ( 1 )
      {
        if ( some_numeric_id_copy == mount_ctx_local->unk0->mount_id )
        {
          gen_path_local = mount_ctx_local->gen_path;
          if ( !SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(
                  mount_ctx_local->gen_path,
                  random_path_buffer,
                  0x10u) )
            break;
        }
        mount_ctx_local = mount_ctx_local->next;
        if ( !mount_ctx_local )
          goto LABEL_18;
      }
    }
    else
    {
      while ( some_numeric_id_copy != mount_ctx_local->unk0->mount_id )
      {
        mount_ctx_local = mount_ctx_local->next;
        if ( !mount_ctx_local )
          goto LABEL_18;
      }
      gen_path_local = mount_ctx_local->gen_path;
    }
    gen_path_chunk1 = *((_DWORD *)gen_path_local + 1);
    gen_path_chunk2 = *((_DWORD *)gen_path_local + 2);
    gen_path_chunk3 = *((_DWORD *)gen_path_local + 3);
    *(_DWORD *)mount_point = *(_DWORD *)gen_path_local;
    *((_DWORD *)mount_point + 1) = gen_path_chunk1;
    *((_DWORD *)mount_point + 2) = gen_path_chunk2;
    *((_DWORD *)mount_point + 3) = gen_path_chunk3;
    if ( random_path_init )
    {
      mount_ctx_local2 = mount_ctx_holder_local->mount;
      if ( !mount_ctx_local2 )
      {
LABEL_12:
        result2 = -2139095038;
        if(var_009EA004 == cookie)
         {
            result = result2;
            return result2;
         }
         else
         {
            return STACK_CHECK_FAIL;
         }

      }
      while ( 1 )
      {
        mount_item_var = mount_ctx_local2->unk0;
        if ( mount_ctx_local2->unk0 )
        {
          if ( some_numeric_id_copy == mount_item_var->mount_id
            && !SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(
                  mount_ctx_local2->gen_path,
                  random_path_buffer,
                  0x10u) )
          {
            break;
          }
        }
        mount_ctx_local2 = mount_ctx_local2->next;
        if ( !mount_ctx_local2 )
          goto LABEL_12;
      }
    }
    else
    {
      v29 = mount_ctx_holder_local->mount;
      if ( !v29 )
        goto LABEL_12;
      while ( 1 )
      {
        mount_item_var = v29->unk0;
        if ( v29->unk0 )
        {
          if ( some_numeric_id_copy == mount_item_var->mount_id )
            break;
        }
        v29 = v29->next;
        if ( !v29 )
          goto LABEL_12;
      }
    }
    if ( !mount_item_var->mount_point[0]
      || (result1 = SceAppMgr_SceProcessmgrForKernel__imp_ksceKernelGetProcessAuthid_e4c83b0d(pid, &auth_ctx),
          result1 >= 0)
      && ((HIDWORD(auth_id1) = auth_ctx.auth_id,
           result1 = SceAppMgr_ScePfsMgrForKernel__imp_mount_d8d0fee5(mount_item_var->mount_point, auth_id1),
           result1 == 0x80010011)
       || result1 >= 0) )
    {
      result2 = -2139095037;
      if(var_009EA004 == cookie)
      {
         result = result2;
         return result2;
      }
      else
      {
         return STACK_CHECK_FAIL;
      }

    }

    result2 = result1;
    if(var_009EA004 == cookie)
   {
      result = result2;
      return result2;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }

  }
LABEL_18:
  ctx.unk4 = 0;
  ctx.unkC = 0;
  ctx.unk10 = 0;
  ctx.unk0 = 20;
  ctx.unk8 = 32;
  v21 = (mount_ctx_t *)SceAppMgr_SceSysmemForDriver__imp_sceKernelAllocHeapMemory3ForKernel_49d4dd9b(
                         MEMORY[0x22A0008],
                         0x24u,
                         &ctx);
  v93 = v21;
  if ( !v21 )
  {
    result2 = 0x80801006;
    if(var_009EA004 == cookie)
   {
      result = result2;
      return result2;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }

  }
  SceAppMgr_SceSysclibForDriver__imp_memset_0ab9bf5c(v21, 0, 0x24u);
  ctx.unk4 = 0;
  v22 = *(_DWORD *)&random_path_buffer[4];
  v23 = *(_DWORD *)&random_path_buffer[8];
  v24 = *(_DWORD *)&random_path_buffer[12];
  v95 = v93->gen_path;
  ctx.unkC = 0;
  ctx.unk10 = 0;
  *(_DWORD *)v93->gen_path = *(_DWORD *)random_path_buffer;
  v25 = MEMORY[0x22A0008];
  ctx.unk0 = 20;
  *((_DWORD *)v95 + 1) = v22;
  *((_DWORD *)v95 + 2) = v23;
  *((_DWORD *)v95 + 3) = v24;
  ctx.unk8 = 32;
  buffer_124 = (char *)SceAppMgr_SceSysmemForDriver__imp_sceKernelAllocHeapMemory3ForKernel_49d4dd9b(v25, 0x124u, &ctx);
  buffer_124_copy = buffer_124;
  if ( !buffer_124 )
  {
    result2 = 0x80801006;
    goto LABEL_21;
  }
  SceAppMgr_SceSysclibForDriver__imp_memset_0ab9bf5c(buffer_124, 0, 0x124u);
  result2 = verify_copy_23D5A10((char *)arg_0, buffer_124_copy);
  if ( result2 > 0 )
  {
LABEL_21:
    v27 = v93->unk4;
    if ( v27 )
    {
      v32 = pid;
      if ( !pid )
        v32 = SceAppMgr_SceThreadmgrForDriver__imp_sceKernelGetProcessId_9dcb4b7a();
      v33 = SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(0x80);
      SceAppMgr_SceFios2KernelForDriver__imp_sceFiosKernelOverlayRemoveForProcessForDriver_23247efb(v32, v27);
      SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(v33);
    }
    if ( v93->unk0 )
      sub_23D5F44(pid, v93->unk0, 1);
    SceAppMgr_SceSysmemForDriver__imp_sceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], v93);
    if ( buffer_124_copy )
      SceAppMgr_SceSysmemForDriver__imp_sceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], buffer_124_copy);
    
    if(var_009EA004 == cookie)
   {
      result = result2;
      return result2;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }

  }
  if ( (unsigned int)SceAppMgr_SceSysclibForDriver__imp_strnlen_cd4bd884(buffer_124_copy, 0x124) >= 0x124 )
  {
    result2 = -2139095039;
    goto LABEL_21;
  }
  result2 = SceAppMgr_SceProcessmgrForKernel__imp_ksceKernelGetProcessAuthid_e4c83b0d(pid, &auth_ctx);
  if ( result2 < 0 )
  {
LABEL_111:
    v38 = result2 != 0x80800003;
    goto LABEL_112;
  }
  auth_id = auth_ctx.auth_id;
  if ( MEMORY[0x22D470C] )
  {
    global_mount_path_item_ptr = (mount_point_data_entry *)MEMORY[0x22D470C];
    while ( some_numeric_id_copy != global_mount_path_item_ptr->mount_id
         || SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(
              global_mount_path_item_ptr->path,
              buffer_124_copy,
              0x124u) )
    {
      global_mount_path_item_ptr = global_mount_path_item_ptr->next;
      if ( !global_mount_path_item_ptr )
        goto LABEL_124;
    }
    if ( global_mount_path_item_ptr->auth_ids[0] )
    {
      if ( global_mount_path_item_ptr->auth_ids[1] )
      {
        if ( global_mount_path_item_ptr->auth_ids[2] )
        {
          if ( global_mount_path_item_ptr->auth_ids[3] )
          {
            if ( global_mount_path_item_ptr->auth_ids[4] )
            {
              if ( global_mount_path_item_ptr->auth_ids[5] )
              {
                if ( global_mount_path_item_ptr->auth_ids[6] )
                {
                  if ( global_mount_path_item_ptr->auth_ids[7] )
                  {
                    if ( global_mount_path_item_ptr->auth_ids[8] )
                    {
                      if ( global_mount_path_item_ptr->auth_ids[9] )
                      {
                        if ( global_mount_path_item_ptr->auth_ids[10] )
                        {
                          if ( global_mount_path_item_ptr->auth_ids[11] )
                          {
                            if ( global_mount_path_item_ptr->auth_ids[12] )
                            {
                              if ( global_mount_path_item_ptr->auth_ids[13] )
                              {
                                if ( global_mount_path_item_ptr->auth_ids[14] )
                                {
                                  if ( global_mount_path_item_ptr->auth_ids[15] )
                                  {
                                    result2 = 0x8080001E;
                                    goto LABEL_21;
                                  }
                                  initialized_global_item_index = 15;
                                }
                                else
                                {
                                  initialized_global_item_index = 14;
                                }
                              }
                              else
                              {
                                initialized_global_item_index = 13;
                              }
                            }
                            else
                            {
                              initialized_global_item_index = 12;
                            }
                          }
                          else
                          {
                            initialized_global_item_index = 11;
                          }
                        }
                        else
                        {
                          initialized_global_item_index = 10;
                        }
                      }
                      else
                      {
                        initialized_global_item_index = 9;
                      }
                    }
                    else
                    {
                      initialized_global_item_index = 8;
                    }
                  }
                  else
                  {
                    initialized_global_item_index = 7;
                  }
                }
                else
                {
                  initialized_global_item_index = 6;
                }
              }
              else
              {
                initialized_global_item_index = 5;
              }
            }
            else
            {
              initialized_global_item_index = 4;
            }
          }
          else
          {
            initialized_global_item_index = 3;
          }
        }
        else
        {
          initialized_global_item_index = 2;
        }
      }
      else
      {
        initialized_global_item_index = 1;
      }
    }
    else
    {
      initialized_global_item_index = 0;
    }
    global_mount_path_item_ptr->auth_ids[initialized_global_item_index] = auth_id;
    if ( !global_mount_path_item_ptr->mount_point[0]
      || (result2 = SceAppMgr_SceProcessmgrForKernel__imp_ksceKernelGetProcessAuthid_e4c83b0d(pid, &auth_ctx),
          result2 >= 0)
      && ((HIDWORD(auth_id2) = auth_ctx.auth_id,
           v37 = SceAppMgr_ScePfsMgrForKernel__imp_mount_d8d0fee5(global_mount_path_item_ptr->mount_point, auth_id2),
           result2 = v37,
           v37 == 0x80010011)
       || v37 >= 0) )
    {
      v93->unk0 = global_mount_path_item_ptr;
      goto LABEL_113;
    }
    if ( auth_id == global_mount_path_item_ptr->auth_ids[0] )
    {
      global_mount_path_item_ptr->auth_ids[0] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[1] )
    {
      global_mount_path_item_ptr->auth_ids[1] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[2] )
    {
      global_mount_path_item_ptr->auth_ids[2] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[3] )
    {
      global_mount_path_item_ptr->auth_ids[3] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[4] )
    {
      global_mount_path_item_ptr->auth_ids[4] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[5] )
    {
      global_mount_path_item_ptr->auth_ids[5] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[6] )
    {
      global_mount_path_item_ptr->auth_ids[6] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[7] )
    {
      global_mount_path_item_ptr->auth_ids[7] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[8] )
    {
      global_mount_path_item_ptr->auth_ids[8] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[9] )
    {
      global_mount_path_item_ptr->auth_ids[9] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[10] )
    {
      global_mount_path_item_ptr->auth_ids[10] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[11] )
    {
      global_mount_path_item_ptr->auth_ids[11] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[12] )
    {
      global_mount_path_item_ptr->auth_ids[12] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[13] )
    {
      global_mount_path_item_ptr->auth_ids[13] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[14] )
    {
      global_mount_path_item_ptr->auth_ids[14] = 0LL;
    }
    else if ( auth_id == global_mount_path_item_ptr->auth_ids[15] )
    {
      global_mount_path_item_ptr->auth_ids[15] = 0LL;
    }
    goto LABEL_111;
  }
LABEL_124:
  ctx.unk4 = 0;
  ctx.unkC = 0;
  ctx.unk10 = 0;
  ctx.unk0 = 20;
  ctx.unk8 = 32;
  allocated_buffer = (mount_point_data_entry *)SceAppMgr_SceSysmemForDriver__imp_sceKernelAllocHeapMemory3ForKernel_49d4dd9b(
                                                 MEMORY[0x22A0008],
                                                 0x1D0u,
                                                 &ctx);
  allocated_mount_path_item_ptr = allocated_buffer;
  if ( !allocated_buffer )
  {
    result2 = 0x80801006;
    v38 = 1;
    goto LABEL_158;
  }
  allocated_buffer_copy = allocated_buffer;
  SceAppMgr_SceSysclibForDriver__imp_memset_0ab9bf5c(allocated_buffer, 0, 0x1D0u);
  allocated_buffer_copy->mount_id = some_numeric_id_copy;
  mountpoint = allocated_buffer_copy->path;
  SceAppMgr_SceSysclibForDriver__imp_strncpy_6d286146(allocated_buffer_copy->path, buffer_124_copy, 0x123u);
  title_id_chunk1 = title_id_local[1];
  title_id_chunk2 = title_id_local[2];
  title_id_chunk3 = title_id_local[3];
  *(_DWORD *)allocated_mount_path_item_ptr->title_id = *title_id_local;
  *(_DWORD *)&allocated_mount_path_item_ptr->title_id[4] = title_id_chunk1;
  *(_DWORD *)&allocated_mount_path_item_ptr->title_id[8] = title_id_chunk2;
  *(_DWORD *)&allocated_mount_path_item_ptr->title_id[12] = title_id_chunk3;
  if ( some_numeric_id_copy == 0x258 )
  {
    allocated_mount_path_item_ptr->mount_point[0] = 0;
    prev_prem = SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(0x80);
    result2 = SceAppMgr_SceIofilemgrForDriver__imp_sceIoMountForDriver_d070bc48(0x10000);
    if ( result2 < 0
      || ((v62 = SceAppMgr_SceIofilemgrForDriver__imp_sceIoMkdirForDriver_7f710b25(
                   aLma0Mpe_root,
                   0x186),                      // lma0:MPE_ROOT
           v63 = v62 >> 31,
           v62 != 0x80010011) ? (v64 = v63 & 1) : (v64 = 0),
          result2 = v62,
          v64) )
    {
      SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(prev_prem);
      v38 = result2 != 0x80800003;
      goto LABEL_157;
    }
    SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(prev_prem);
    goto LABEL_136;
  }
  pd_random_path = allocated_mount_path_item_ptr->mount_point;
  result2 = proc_generate_random_path_23D4FBC(PD_str_2404BBC, allocated_mount_path_item_ptr->mount_point);// PD string
  if ( result2 < 0 )
    goto LABEL_213;
  if ( !SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(mountpoint, aHost0, 6u) )
    allocated_mount_path_item_ptr->mount_point[0] = 0;
  *(_DWORD *)secret = 0;
  v104 = 0;
  v49 = allocated_mount_path_item_ptr->mount_id;
  v102 = 0;
  v103 = 0;
  if ( v49 > 0x192 )
  {
    if ( v49 >= 0x3EC )
    {
      if ( v49 == 0x3EE )
        goto LABEL_319;
      if ( v49 <= 0x3EE )
      {
        if ( v49 == 0x3EC )
        {
          klicensee_chunk1 = *((_DWORD *)klicensee + 1);
          v51 = 13;
          klicensee_chunk2 = *((_DWORD *)klicensee + 2);
          klicensee_chunk3 = *((_DWORD *)klicensee + 3);
          *(_DWORD *)secret = *(_DWORD *)klicensee;
          v102 = klicensee_chunk1;
          v103 = klicensee_chunk2;
          v104 = klicensee_chunk3;
LABEL_135:
          if ( !allocated_mount_path_item_ptr->mount_point[0] )
            goto LABEL_136;
          v70 = SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(0x80);
          result2 = SceAppMgr_SceProcessmgrForKernel__imp_ksceKernelGetProcessAuthid_e4c83b0d(pid, &auth_ctx);
          if ( result2 < 0 )
            goto LABEL_213;
          if ( secret[0]
            || secret[1]
            || secret[2]
            || secret[3]
            || (_BYTE)v102
            || __PAIR__(BYTE1(v102), 0) != BYTE2(v102)
            || __PAIR__(HIBYTE(v102), 0) != (unsigned __int8)v103
            || __PAIR__(BYTE1(v103), 0) != BYTE2(v103)
            || __PAIR__(HIBYTE(v103), 0) != (unsigned __int8)v104
            || __PAIR__(BYTE1(v104), 0) != BYTE2(v104) )
          {
            v71 = secret;
          }
          else
          {
            v71 = HIBYTE(v104) ? secret : 0;
          }
          result2 = SceAppMgr_ScePfsMgrForKernel__imp_mount_a772209c(
                      mountpoint,
                      pd_random_path,
                      auth_ctx.auth_id,
                      v71,
                      v51);
          SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(v70);
          if ( result2 )
            goto LABEL_213;
          HIDWORD(auth_id3) = 1;
          v73 = SceAppMgr_ScePfsMgrForKernel__imp_mount_d8d0fee5(pd_random_path, auth_id3);
          v75 = v73 >> 31;
          result2 = v73;
          if ( v73 == 0x80010011 )
            v76 = 0;
          else
            v76 = v75 & 1;
          pd_random_path1 = allocated_mount_path_item_ptr->mount_point;
          if ( v76 )
            goto LABEL_310;
          HIDWORD(auth_id4) = 0x7001;
          v78 = SceAppMgr_ScePfsMgrForKernel__imp_mount_d8d0fee5(pd_random_path, auth_id4);
          v80 = v78 >> 31;
          result2 = v78;
          v81 = v78 == 0x80010011 ? 0 : v80 & 1;
          pd_random_path1 = allocated_mount_path_item_ptr->mount_point;
          if ( v81 )
            goto LABEL_310;
          HIDWORD(auth_id5) = 0x2D;
          v82 = SceAppMgr_ScePfsMgrForKernel__imp_mount_d8d0fee5(pd_random_path, auth_id5);
          result2 = v82;
          if ( v82 == 0x80010011 )
            v84 = 0;
          else
            v84 = v82 < 0;
          if ( v84 )
          {
LABEL_309:
            pd_random_path1 = allocated_mount_path_item_ptr->mount_point;
LABEL_310:
            SceAppMgr_ScePfsMgrForKernel__imp_unmount_680bc384(pd_random_path1);
            goto LABEL_213;
          }
          if ( v51 == 4 )
          {
            pd_random_pat2 = allocated_mount_path_item_ptr->mount_point;
            HIDWORD(auth_id6) = 0x10;
          }
          else
          {
            if ( v51 != 5 )
              goto LABEL_136;
            pd_random_pat2 = allocated_mount_path_item_ptr->mount_point;
            HIDWORD(auth_id6) = 0x39;
          }
          v86 = SceAppMgr_ScePfsMgrForKernel__imp_mount_d8d0fee5(pd_random_pat2, auth_id6);
          result2 = v86;
          if ( v86 == 0x80010011 )
            v87 = 0;
          else
            v87 = v86 >> 31;
          if ( v87 )
            goto LABEL_309;
LABEL_136:
          if ( allocated_mount_path_item_ptr->auth_ids[0] )
          {
            if ( allocated_mount_path_item_ptr->auth_ids[1] )
            {
              if ( allocated_mount_path_item_ptr->auth_ids[2] )
              {
                if ( allocated_mount_path_item_ptr->auth_ids[3] )
                {
                  if ( allocated_mount_path_item_ptr->auth_ids[4] )
                  {
                    if ( allocated_mount_path_item_ptr->auth_ids[5] )
                    {
                      if ( allocated_mount_path_item_ptr->auth_ids[6] )
                      {
                        if ( allocated_mount_path_item_ptr->auth_ids[7] )
                        {
                          if ( allocated_mount_path_item_ptr->auth_ids[8] )
                          {
                            if ( allocated_mount_path_item_ptr->auth_ids[9] )
                            {
                              if ( allocated_mount_path_item_ptr->auth_ids[10] )
                              {
                                if ( allocated_mount_path_item_ptr->auth_ids[11] )
                                {
                                  if ( allocated_mount_path_item_ptr->auth_ids[12] )
                                  {
                                    if ( allocated_mount_path_item_ptr->auth_ids[13] )
                                    {
                                      if ( allocated_mount_path_item_ptr->auth_ids[14] )
                                      {
                                        if ( allocated_mount_path_item_ptr->auth_ids[15] )
                                        {
                                          result2 = -2139095010;
                                          v38 = 1;
LABEL_154:
                                          v55 = SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(128);
                                          if ( some_numeric_id_copy == 600 )
                                            SceAppMgr_SceIofilemgrForDriver__imp_sceIoUmountForDriver_20574100(
                                              0x10000,
                                              0,
                                              0,
                                              0);
                                          else
                                            SceAppMgr_ScePfsMgrForKernel__imp_unmount_680bc384(allocated_mount_path_item_ptr->mount_point);
                                          SceAppMgr_SceThreadmgrForDriver__imp_ksceKernelSetPermission_02eedf17(v55);
                                          goto LABEL_157;
                                        }
                                        initialized_allocated_item_index = 15;
                                      }
                                      else
                                      {
                                        initialized_allocated_item_index = 14;
                                      }
                                    }
                                    else
                                    {
                                      initialized_allocated_item_index = 13;
                                    }
                                  }
                                  else
                                  {
                                    initialized_allocated_item_index = 12;
                                  }
                                }
                                else
                                {
                                  initialized_allocated_item_index = 11;
                                }
                              }
                              else
                              {
                                initialized_allocated_item_index = 10;
                              }
                            }
                            else
                            {
                              initialized_allocated_item_index = 9;
                            }
                          }
                          else
                          {
                            initialized_allocated_item_index = 8;
                          }
                        }
                        else
                        {
                          initialized_allocated_item_index = 7;
                        }
                      }
                      else
                      {
                        initialized_allocated_item_index = 6;
                      }
                    }
                    else
                    {
                      initialized_allocated_item_index = 5;
                    }
                  }
                  else
                  {
                    initialized_allocated_item_index = 4;
                  }
                }
                else
                {
                  initialized_allocated_item_index = 3;
                }
              }
              else
              {
                initialized_allocated_item_index = 2;
              }
            }
            else
            {
              initialized_allocated_item_index = 1;
            }
          }
          else
          {
            initialized_allocated_item_index = 0;
          }
          global_mount_item = (mount_point_data_entry *)MEMORY[0x22D470C];
          allocated_mount_path_item_ptr->auth_ids[initialized_allocated_item_index] = auth_id;
          if ( global_mount_item )
          {
            if ( allocated_mount_path_item_ptr == global_mount_item )
            {
LABEL_252:
              result2 = 0x80800003;
              v38 = 0;
              goto LABEL_154;
            }
            while ( global_mount_item->next )
            {
              if ( allocated_mount_path_item_ptr == global_mount_item )
                goto LABEL_252;
              global_mount_item = global_mount_item->next;
            }
            global_mount_item->next = allocated_mount_path_item_ptr;
            *(_QWORD *)&allocated_mount_path_item_ptr->prev = (unsigned int)global_mount_item;
          }
          else
          {
            MEMORY[0x22D470C] = allocated_mount_path_item_ptr;
            allocated_mount_path_item_ptr->prev = 0;
            allocated_mount_path_item_ptr->next = 0;
          }
          v38 = 0;
          result2 = 0;
          goto LABEL_158;
        }
        if ( v49 == 1005 )
          goto LABEL_313;
LABEL_262:
        result2 = 0x80800001;
        v38 = 1;
        goto LABEL_157;
      }
      if ( v49 > 0x3F0 )
      {
        if ( v49 != 1009 )
          goto LABEL_262;
LABEL_319:
        v51 = 21;
        goto LABEL_135;
      }
LABEL_267:
      v51 = 20;
      goto LABEL_135;
    }
    if ( v49 >= 0x3EA )
    {
      if ( SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(mountpoint, aGro0_0, 5u) )// gro0:
        v51 = 4;
      else
        v51 = 12;
      result2 = read_sealedkey_23D6EA0(mountpoint, secret);
      goto LABEL_212;
    }
    if ( v49 >= 0x1FA )
    {
      if ( v49 < 0x3E8 )
        goto LABEL_262;
      if ( proc_get_clearsign_stat_23D9A4C(mountpoint) )
      {
        v51 = 2;
        klicensee_chunk1_1 = *((_DWORD *)klicensee + 1);
        klicensee_chunk1_2 = *((_DWORD *)klicensee + 2);
        klicensee_chunk1_3 = *((_DWORD *)klicensee + 3);
        *(_DWORD *)secret = *(_DWORD *)klicensee;
        v102 = klicensee_chunk1_1;
        v103 = klicensee_chunk1_2;
        v104 = klicensee_chunk1_3;
        goto LABEL_135;
      }
      goto LABEL_267;
    }
    if ( v49 < 0x1F8 )
    {
      if ( v49 - 500 <= 1 )
      {
        v51 = 4;
        result2 = read_sealedkey_23D6EA0(mountpoint, secret);
        goto LABEL_212;
      }
      goto LABEL_262;
    }
LABEL_264:
    v51 = 6;
    result2 = read_sealedkey_23D6EA0(mountpoint, secret);
    goto LABEL_212;
  }
  if ( v49 >= 0x190 )
  {
LABEL_324:
    v51 = 22;
    goto LABEL_135;
  }
  if ( v49 != 110 )
  {
    if ( v49 > 0x6E )
    {
      if ( v49 <= 0xCF )
      {
        if ( v49 < 0xC8 && v49 > 0x70 )
          goto LABEL_262;
        goto LABEL_319;
      }
      if ( v49 - 302 > 2 )
        goto LABEL_262;
      goto LABEL_264;
    }
    if ( v49 <= 0x6C )
    {
      if ( v49 >= 0x6B )
        goto LABEL_319;
      if ( v49 < 0x64 )
        goto LABEL_262;
    }
    goto LABEL_324;
  }
LABEL_313:
  if ( klicensee )
  {
    v88 = *((_DWORD *)klicensee + 1);
    v89 = *((_DWORD *)klicensee + 2);
    v51 = 5;
    v90 = *((_DWORD *)klicensee + 3);
    *(_DWORD *)secret = *(_DWORD *)klicensee;
    v102 = v88;
    v103 = v89;
    v104 = v90;
    goto LABEL_135;
  }
  v51 = 5;
  result2 = read_sealedkey_23D6EA0(mountpoint, secret);
LABEL_212:
  if ( !result2 )
    goto LABEL_135;
LABEL_213:
  v38 = result2 != -2139095037;
LABEL_157:
  v56 = allocated_mount_path_item_ptr;
  allocated_mount_path_item_ptr = 0;
  SceAppMgr_SceSysmemForDriver__imp_sceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], v56);
LABEL_158:
  v93->unk0 = allocated_mount_path_item_ptr;
LABEL_112:
  if ( v38 )
    goto LABEL_21;
LABEL_113:
  SceAppMgr_SceSysmemForDriver__imp_sceKernelMemPoolFree_3ebce343(MEMORY[0x22A0008], buffer_124_copy);
  if ( some_numeric_id_copy != 1001 )
  {
    if ( some_numeric_id_copy != 1003 )
      goto LABEL_115;
    v59 = mount_ctx_holder_local->mount;
    if ( v59 )
    {
      while ( 1 )
      {
        v60 = v59->unk0;
        if ( v59->unk0 )
        {
          if ( v60->mount_id == 1002
            && !SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(v59->gen_path, random_path_buffer, 0x10u) )
          {
            break;
          }
        }
        v59 = v59->next;
        if ( !v59 )
          goto LABEL_225;
      }
      v93->unk18 = (int)v60;
      goto LABEL_115;
    }
LABEL_225:
    result2 = -2139095038;
    buffer_124_copy = (char *)v59;
    goto LABEL_21;
  }
  v59 = mount_ctx_holder_local->mount;
  if ( !v59 )
    goto LABEL_225;
  while ( 1 )
  {
    v65 = v59->unk0;
    if ( v59->unk0 )
    {
      if ( v65->mount_id == 1000
        && !SceAppMgr_SceSysclibForDriver__imp_strncmp_12cee649(v59->gen_path, random_path_buffer, 0x10u) )
      {
        break;
      }
    }
    v59 = v59->next;
    if ( !v59 )
      goto LABEL_225;
  }
  v93->unk18 = (int)v65;
LABEL_115:
  result2 = proc_fios2kernel_overlay_add_for_process_23D4DDC(pid, v93);
  if ( result2 )
  {
    buffer_124_copy = 0;
    goto LABEL_21;
  }
  v39 = mount_ctx_holder_local->mount;
  if ( v39 )
  {
    if ( v93 == v39 )
    {
      result2 = -2139095037;
      buffer_124_copy = 0;
    }
    else
    {
      while ( 1 )
      {
        if ( !v39->next )
        {
          v39->next = v93;
          v93->unk1C = (int)v39;
          v93->next = 0;
          goto LABEL_123;
        }
        if ( v93 == v39 )
          break;
        v39 = v39->next;
      }
      result2 = -2139095037;
      buffer_124_copy = 0;
    }
    goto LABEL_21;
  }
  mount_ctx_holder_local->mount = v93;
  v93->unk1C = 0;
  v93->next = 0;
LABEL_123:
  result2 = 0;
  v40 = *(_DWORD *)&v93->gen_path[4];
  v41 = *(_DWORD *)&v93->gen_path[8];
  v42 = *(_DWORD *)&v93->gen_path[12];
  *(_DWORD *)mount_point = *(_DWORD *)v95;
  *((_DWORD *)mount_point + 1) = v40;
  *((_DWORD *)mount_point + 2) = v41;
  *((_DWORD *)mount_point + 3) = v42;
  */

   if(var_009EA004 == cookie)
   {
      result = result2;
      return result2;
   }
   else
   {
      return STACK_CHECK_FAIL;
   }
}