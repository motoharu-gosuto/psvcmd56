

void loc_1D37F94()
{
   /*
   LDR             R4, [SP,#0x298+var_260]
   MOV             R4, 0x1C8D680 ; 01D37F96 : external reference: 01C8D680 - Secondary Table of act.dat
   STR             R4, [SP,#0x298+var_260] ; = 1C8D680
   LDMIA           R4!, {R0-R3} ; get decrypted RIF key
   STR.W           R0, [R11] ; store decrypted key
   STR.W           R1, [R11,#4]
   STR.W           R2, [R11,#8]
   STR.W           R3, [R11,#0xC]
   B               loc_1D37F58
   */
}

void loc_1D37FFA()
{
   /*
   LDR             R5, [SP,#0x298+var_25C]
   STR             R7, [SP,#0x298+arg_0] ; arg_0 = 0 - optimization
   LDR             R4, [SP,#0x298+unk0] ; 1C8D680
   MOV             R5, 0x1C8C030 ; 01D38000 : external reference: 01C8C030
   LDMIA           R5!, {R0-R3} ; get static key 3
   ADDS            R4, #0x40 ; 1C8D680 + 0x40
   STMIA           R4!, {R0-R3} ; store static key 3
   STR             R5, [SP,#0x298+var_25C] ; 1C8C040
   LDMIA.W         R5, {R0-R3} ; get static key 4
   STMIA.W         R4, {R0-R3} ; store static key 4
   SUB.W           R2, R4, #0x10 ; keypair
   LDR             R0, [SP,#0x298+unk0] ; buffer - 1C8D680
   MOVS            R1, #0x10 ; num1
   MOVS            R3, #0x90 ; num2
   BLX             SceNpDrm.SceSblAuthMgrForDriver._imp_sceSblAuthMgrDecBindData_41daea12
   */

   if(r0 < 0)
   {
      //loc_1D3802A
   }
   else
   {
      //goto loc_1D37F94
   }
}

void loc_1D37F2E()
{
   /*
   MOVW            R0, #0xD680
   MOVS            R3, #0
   MOVT.W          R0, #0x1C8 ; 01D37F34 : external reference: 01C8D680 - Secondary Table of act.dat
   STR             R3, [SP,#0x298+arg_0] ; arg_0 = 0
   ADD.W           R2, R0, #0x40 ; unk2 - 01C8D680 + 0x40 - primary key pair
   MOVS            R1, #0x10 ; num1
   MOVS            R3, #0x90 ; num2
   BLX             SceNpDrm.SceSblAuthMgrForDriver._imp_sceSblAuthMgrDecBindData_41daea12
   */

   if(r0 < 0)
   {
      //goto loc_1D3802A
   }
   else
   {
      //goto loc_1D37F94
   }
}

void get_rif_key_1D37B48_part()
{
   /*
   LDR             R5, [SP,#0x298+unk0]
   MOV.W           R1, #0x100 ; size
   MOV             R5, 0x1C8D680 ; 01D37EF0 : external reference: 01C8D680 - looks like Secondary Table of act.dat
   MOV             R0, R5  ; ptr
   STR             R5, [SP,#0x298+unk0] ; = 1C8D680
   BL              zeromem_1D3AB0C
   ADD             R3, SP, #0x298+rif_data+0xA0
   LDMIA           R3, {R0-R3} ; get 0x10 bytes rif data 0xA0
   STMIA.W         R5, {R0-R3} ; store 0x10 bytes
   MOV             R0, R5  ; 1C8D680
   ADDS            R0, #0x60 ; destination
   ADD             R1, SP, #0x298+rif_data ; source
   MOVS            R2, #0x70 ; num
   BLX             SceNpDrm.SceSysclibForDriver._imp_memcpy_40c88316 ; copy 0x70 bytes of rif data
   */

   if(r7 == 0)
   {
      /*
      loc_1D37FB4             ;
      LDR             R4, [SP,#0x298+value] ; get byte of rif_lic_flags
      */

      if(r4 == 0xD)
      {
         //goto loc_1D37FFA
      }
      else
      {
         /*
         LDR             R4, [SP,#0x298+unk0] ; 1C8D680
         SUB.W           R5, R4, #0x870 ; 1C8CE10 - Primary Key Table
         ADDS            R4, #0x40
         LDMIA           R5!, {R0-R3} ; get primary key 0x10 bytes
         STMIA           R4!, {R0-R3} ; store primary key
         LDMIA.W         R5, {R0-R3} ; get primary key 0x10 bytes
         STMIA.W         R4, {R0-R3} ; store primary
         */

         //goto loc_1D37F2E
      }
   }
   else
   {
      /*
      ADD             R7, SP, #0x298+cmd56_handshake
      LDR             R5, [SP,#0x298+unk0] ; 1C8D680
      LDMIA           R7!, {R0-R3} ; get 0x10 cmd56 bytes
      ADDS            R5, #0x40
      STMIA           R5!, {R0-R3}
      LDMIA.W         R7, {R0-R3} ; get 0x10 cmd56 bytes
      STMIA.W         R5, {R0-R3}
      */

      if(r4 == 0)
      {
         //goto loc_1D37F2E  
      }
      else
      { 
         /*
         LDR             R4, [SP,#0x298+unk0] ; 1C8D680
         LDR             R5, [SP,#0x298+unk0] ; 1C8D680
         ADDS            R4, #0xB0 ; RIF Key offset in copied data
         LDMIA.W         R4, {R0-R3} ; 1C8D680 + 0xB0 - get 0x10 bytes
         STMIA.W         R5, {R0-R3} ; store 0x10 bytes
         MOV             R0, R4  ; ptr
         MOVS            R1, #0x10 ; size
         BL              zeromem_1D3AB0C ; erase RIF Key
         */
         
         //goto loc_1D37F2E
      }
   }
}