#include "SceIofilemgr.h"

int loc_21A292E(int r9, int var_2C)
{
   if(var_2C == var_009EA004)
      return r9;
   else
      return STACK_CHECK_FAIL;
}

int loc_21A292C(int r0, int var_2C)
{
   return loc_21A292E(r0, var_2C);
}

int proc_SCENGPFS_21A27B8(void *unk0, vfs_node **unk1, void *unk2)
{
   /*
   var_2A0= -0x2A0         ; args to functions
   readBytes= -0x298       ; read bytes ptr
   var_28C= -0x28C         ; read bytes value
   result= -0x288          ; result pair
   var_284= -0x284
   unk0= -0x280            ; 0x14 bytes
   destination= -0x26C     ; size is 0x100
   var_16C= -0x16C         ; 0x140 bytes
   var_2C= -0x2C           ; cookie
   */

   /*
   PUSH.W          {R4-R11,LR}
   MOV             R7, 0x9EA004
   SUB.W           SP, SP, #0x27C ; num0
   MOV             R6, R0  ; arg0
   MOV             R0, R1  ; arg1 - vfs_node **
   LDR             R3, [R7] ; cookie
   MOV             R8, R2  ; arg2
   STR             R1, [R6,#0x14]
   ADD             R1, SP, #0x2A0+result ; result_pair
   STR             R3, [SP,#0x2A0+var_2C]
   BL              sub_2199144 ; call vfs_node_func15 (sceIoGetstatForDriver) - get some string from node field 70
   */

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   /*
   LDRD.W          R4, R5, [SP,#0x18]
   ORRS.W          R3, R4, R5
   */

   if(true) //beq
      return loc_21A292E(0x80140904, var_2C);

   /*
   ADD.W           R11, SP, #0x2A0+destination+0x3F
   MOV.W           R2, #0x200
   BIC.W           R11, R11, #0x3F
   MOVS            R3, #0  ; unk3
   ADD             R4, SP, #0x2A0+var_28C
   LDR             R0, [R6,#0x14] ; unk0 - vfs_node**
   MOV             R1, R11 ; buffer
   STRD.W          R2, R3, [SP]
   STR             R4, [SP,#0x2A0+readBytes] ; readBytes
   MOV.W           R2, #0x200 ; size
   BL              read_wrapper_2199064
   */

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   //LDR             R2, [R4] ; size
   
   if(r2 != 0x200)
      return loc_21A292E(0x8014090A, var_2C);
    
   /*
   LDR.W           R0, [R11,#0x60]
   STR             R0, [R6,#0x68]
   LDR.W           R9, [R6,#0x68]
   */

   if(r9 != 0)
      return loc_21A292E(0x8014090A, var_2C);

   /*
   VMOV.I32        D16, #0x80
   MOV             R1, R11 ; buffer
   LDR             R0, [R6,#0x14] ; unk0 - vfs_node**
   STR             R4, [SP,#0x2A0+readBytes] ; readBytes
   VSTR            D16, [SP,#0x2A0+var_2A0]
   BL              read_wrapper_2199064
   */

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   //LDR             R3, [R4]   

   if(r3 != 0x200)
      return loc_21A292E(0x8014090A, var_2C);

   /*
   ADD.W           R10, R6, #0x70 ; offset in arg0
   MOV.W           R2, #0x160 ; num
   MOV             R1, R11 ; source
   MOV             R0, R10 ; destination - arg0 + 0x70
   BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
   ADR             R3, aScengpfs ; "SCENGPFS"
   LDRD.W          R2, R3, [R3] ; this is a header of files.db
   LDRD.W          R4, R5, [R6,#0x70]
   CMP             R5, R3
   IT EQ
   CMPEQ           R4, R2
   BNE             loc_21A2940 ; goto error 0x8014090A if header is not cor
   */

   if(r5 != r3)
      return loc_21A292E(0x8014090A, var_2C);
   
   if(r4 != r2)
      return loc_21A292E(0x8014090A, var_2C);

   /*
   LDR.W           R3, [R8]
   LDR.W           R4, [R8,#4]
   LDR.W           R0, [R8,#8]
   LDR.W           R2, [R8,#0xC]
   LDR             R1, [R6,#0x18]
   STR             R3, [R6]
   STR             R4, [R6,#4]
   STR             R0, [R6,#8]
   STR             R2, [R6,#0xC]
   LDR.W           R3, [R8,#0x10]
   LDR.W           R5, [R6,#0x80]
   STR             R3, [R6,#0x10]
   LDR             R3, [R1,#4]
   */

   if(r5 != r3)
      return loc_21A292E(0x80140909, var_2C);

   /*
   LDR             R3, [R6,#0x78]
   ADD.W           R4, R6, #0x20
   LDR             R2, [R6,#0x14]
   MOV             R0, R4  ; unk0
   ADD.W           R8, R6, #0xD0
   STR.W           R9, [SP,#0x2A0+var_2A0+4]
   SUBS            R3, #1
   CMP             R3, #1
   IT LS
   MOVLS.W         R5, #0x160
   STR             R5, [SP,#0x2A0+var_2A0]
   ADD.W           R5, R6, #0xBC ; offset in arg0
   BL              sub_21A0E3C
   MOV.W           R2, #0x100 ; num
   MOV             R1, R8  ; source - arg0 + 0xD0
   ADD             R0, SP, #0x2A0+destination ; destination
   BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
   MOV             R1, R5  ; src - arg0 + 0xBC
   ADD             R0, SP, #0x2A0+unk0 ; dst
   BL              proc_copy_14_bytes_219DE1C
   MOV             R1, R9  ; value
   MOVS            R2, #0x14 ; num
   MOV             R0, R5  ; ptr - arg0 + 0xBC
   BLX             ScePfsMgr.SceSysclibForDriver._imp_memset_0ab9bf5c
   MOV             R1, R9  ; value
   MOV.W           R2, #0x100 ; num
   MOV             R0, R8  ; ptr - arg0 + 0xD0
   BLX             ScePfsMgr.SceSysclibForDriver._imp_memset_0ab9bf5c
   MOV             R1, R6  ; unk1 - arg0
   MOV             R0, R5  ; unk0 - arg0 + 0xBC (size 0x14)
   MOV             R2, R10 ; unk2 - arg0 + 0x70 - base (size 0x160)
   MOV.W           R3, #0x160 ; unk3 - size
   BL              proc_crypto_stuff_219DE7C
   ADD             R0, SP, #0x2A0+unk0 ; unk0
   MOV             R1, R5  ; unk1
   BL              proc_verify_14_bytes_219DE44
   */

   if(r0 == 0)
      return loc_21A292E(0x80140902, var_2C);

   /*
   LDRD.W          R10, R11, [R6,#0x98]
   MOV             R0, R4
   LDRD.W          R2, R3, [R6,#0x90]
   STRD.W          R10, R11, [SP]
   BL              sub_21A0E28
   MOV             R2, R4
   LDR             R4, [R6,#0x78]
   LDR.W           R3, [R6,#0x88]
   ADD.W           R0, R6, #0x40
   MOV             R1, R6
   STR             R4, [SP,#0x2A0+var_2A0]
   BL              sub_21A6A10 ; some vfs node functions inside
   */

   if(r0 != 0)
      return loc_21A292C(r0, var_2C);

   /*
   ADD.W           R0, R6, #0xA8
   ADD.W           R1, R6, #0x4C ; offset in arg0
   BL              proc_verify_14_bytes_219DE44
   CBZ             R0, loc_21A2982 ; goto error 0x80140902
   */

   if(r0 == 0)
      return loc_21A292E(0x80140902, var_2C);

   /*
   ADD             R1, SP, #0x2A0+destination ; source
   MOV.W           R2, #0x100 ; num
   MOV             R0, R8  ; destination
   ADD             R4, SP, #0x2A0+unk0
   BLX             ScePfsMgr.SceSysclibForDriver._imp_memcpy_40c88316
   LDMIA           R4!, {R0-R3}
   STR.W           R0, [R6,#0xBC]
   LDR             R0, [R4]
   STR             R1, [R5,#4]
   STR             R2, [R5,#8]
   STR             R0, [R5,#0x10]
   STR             R3, [R5,#0xC]
   */
   
   return loc_21A292E(r9, var_2C); //r9 is 0 - optimization
}