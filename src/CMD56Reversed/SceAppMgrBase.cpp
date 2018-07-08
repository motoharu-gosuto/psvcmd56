#include "SceAppMgrBase.h"

#include <string>

#include "SceThreadmgr.h"
#include "SceAppMgrGlobals.h"
#include "SceSblSsMgr.h"

global_ctx_item *__cdecl get_global_ctx_item_23C2DE0(ctx_23C2960 *ctx, SceUID pid)
{
   return 0;
}

int check_flags_23D4CE0(int mountId, int flag)
{
   return 0;
}

int check_long_titleId(const char * titleId)
{
   if (titleId == 0
      || (unsigned int)titleId[0] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[1] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[2] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[3] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[4] - 0x30 > 9 //number
      || (unsigned int)titleId[5] - 0x30 > 9 //number
      || (unsigned int)titleId[6] - 0x30 > 9 //number
      || (unsigned int)titleId[7] - 0x30 > 9 //number
      || (unsigned int)titleId[8] - 0x30 > 9 //number
      || (unsigned int)titleId[9] != '_' //underline
      || (unsigned int)titleId[10] - 0x30 > 9 //number
      || (unsigned int)titleId[11] - 0x30 > 9 //number
      || (unsigned int)titleId[12] != 0 ) //terminated
   {
      return false;
   }

   return true;
}

int check_short_titleId(const char * titleId)
{
   if (titleId == 0
      || (unsigned int)titleId[0] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[1] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[2] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[3] - 0x41 > 0x19 //alpha
      || (unsigned int)titleId[4] - 0x30 > 9 //number
      || (unsigned int)titleId[5] - 0x30 > 9 //number
      || (unsigned int)titleId[6] - 0x30 > 9 //number
      || (unsigned int)titleId[7] - 0x30 > 9 //number
      || (unsigned int)titleId[8] - 0x30 > 9 //number
      || (unsigned int)titleId[9] != 0 ) //terminated
   {
      return false;
   }

   return true;
}

bool check_title_id_23E00B8(int mountId, const char * titleId, int& error_code)
{
   if (mountId != 0xCF)
   {
      #pragma region does not fall through

      if (mountId > 0xCF)
      {
         #pragma region does not fall through

         if (mountId >= 0x1F8)
         {
            #pragma region does not fall through

            if (mountId == 0x258)
            {
               #pragma region does not fall through

               if (titleId == 0)
               {
                  error_code = 0x80800001;
                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                  return false;
               }

               int index0 = 0;

               do
               {
                  #pragma region

                  int symbol0 = (unsigned __int8)titleId[index0];
                  unsigned int symbol_diff0 = symbol0 - 0x41;
                  unsigned int symbol_diff1 = symbol0 - 0x30;
                  char check1 = symbol_diff0 >= 5;
                  char check2 = symbol_diff0 == 5;

                  if (symbol_diff0 > 5)
                  {
                     check1 = symbol_diff1 >= 9;
                     check2 = symbol_diff1 == 9;
                  }

                  if (!check2 & (unsigned __int8)check1)
                  {
                     error_code = 0x80800001;
                     SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                     return false;
                  }

                  ++index0;

                  #pragma endregion
               }
               while (index0 != 0x20);

               if (titleId[0x20] != 0)
               {
                  error_code = 0x80800001;
                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                  return false;
               }
               else
               {
                  error_code = 0;
                  return true;
               }

               #pragma endregion
            }
            else
            {
               #pragma region does not fall through

               error_code = 0;
               return true;

               #pragma endregion
            }

            #pragma endregion
         }
         else if (mountId < 0x1F4)
         {
            #pragma region does not fall through

            if (mountId - 0x12F > 1)
            {
               error_code = 0;
               return true;
            }
            else
            {
               #pragma region does not fall through

               if(!check_long_titleId(titleId))
               {
                  error_code = 0x80800001;
                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                  return false;
               }
               else
               {
                  error_code = 0;
                  return true;
               }

               #pragma endregion
            }

            #pragma endregion
         }
         else
         {
            #pragma region does not fall through

            if(!check_short_titleId(titleId))
            {
               error_code = 0x80800001;
               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
               return false;
            }
            else
            {
               error_code = 0;
               return true;
            }

            #pragma endregion
         }

         #pragma endregion
      }
      else
      {
         #pragma region does not fall through

         if (mountId > 0x6B)
         {
            #pragma region does not fall through

            if (mountId == 0x6E)
            {
               #pragma region does not fall through

               if (titleId == 0)
               {
                  error_code = 0x80800001;
                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                  return false;
               }
               else
               {
                  error_code = 0;
                  return true;
               }

               #pragma endregion
            }
            else
            {
               #pragma region does not fall through

               if (mountId != 0xCD)
               {
                  error_code = 0;
                  return true;
               }
               else
               {
                  #pragma region does not fall through

                  if(!check_short_titleId(titleId))
                  {
                     error_code = 0x80800001;
                     SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                     return false;
                  }
                  else
                  {
                     error_code = 0;
                     return true;
                  }

                  #pragma endregion
               }

               #pragma endregion
            }

            #pragma endregion
         }
         else if (mountId < 0x6A)
         {
            #pragma region does not fall through

            if (mountId != 0x68)
            {
               error_code = 0;
               return true;
            }
            else
            {
               #pragma region does not fall through

               if(!check_long_titleId(titleId))
               {
                  error_code = 0x80800001;
                  SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
                  return false;
               }
               else
               {
                  error_code = 0;
                  return true;
               }

               #pragma endregion
            }

            #pragma endregion
         }
         else
         {
            #pragma region does not fall through

            if(!check_short_titleId(titleId))
            {
               error_code = 0x80800001;
               SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
               return false;
            }
            else
            {
               error_code = 0;
               return true;
            }

            #pragma endregion
         }

         #pragma endregion
      }

      #pragma endregion
   }
   else
   {
      #pragma region does not fall through

      if(!check_short_titleId(titleId))
      {
         error_code = 0x80800001;
         SceThreadmgrForDriver_ksceKernelUnlockMutex_1e82e5d0(SceAppMgrMount_mutex_22A000C, 1);
         return false;
      }
      else
      {
         error_code = 0;
         return true;
      }

      #pragma endregion
   }
}

int set_accoutNo_global_23D58B4(char* accountNo)
{
   /*
   var_22D4778[0] = 0;
   var_22D4778[1] = 0;
   var_22D4778[2] = 0;
   */
   return 0;
}

int read_keystone_23D6664(SceUID pid, const char *gen_mount_point, char *keystone_data)
{
   return 0;
}

int create_pfs_directory_23DFEAC(int mount_id, const char *physical_path, const char *keystone_data)
{
   return 0;
}

int get_fake_no_memory_card_23E5660()
{
   return 0;
}

int normalize_path_select_mode_create_dir_23D9354(const char *physical_path, int some_flag)
{
   return 0;
}

int check_privileges_23D5D54(unsigned int mountId)
{
   return 0;
}

void * alloc_mem_23DDFF8(SceSize size)
{
   return 0;
}

int verify_copy_23D5A10(const char *src, char *dst)
{
   return 0;
}

int read_sealedkey_23D6EA0(const char *mountpoint, char *secret)
{
   return 0;
}

int loc_23D518E()
{
   //  more code

   return 0;
}

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

int clearsign_exists_23D9A4C(const char *mountpoint)
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

int proc_generate_random_path_23D4FBC(char *prefix, char *result_path)
{   
   int result;
   char random_buffer[8];

   result = SceSblSsMgrForDriver_sceKernelGetRandomNumberForDriver_4f9bfbe5(random_buffer, 8);
   if(result < 0)
      return result;

   _snprintf(result_path, 0x10u, "%s%02x%02x%02x%02x%02x%02xd", prefix, random_buffer[0], random_buffer[1], random_buffer[2], random_buffer[3], random_buffer[4], random_buffer[5]);
   return 0;
}