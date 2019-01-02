
int handle_command_0x50001_0x60001_80E568(int arg1, int arg2)
{
   /*
   add     $sp, -0x18
   lw      $3, (cookie_810928) ; get cookie
   ldc     $11, $lp
   sw      $5, 0x18+prev_state_C($sp) ; + 0xC
   sw      $6, 0x18+prev_state_10($sp) ; + 0x8
   sw      $11, 0x18+prev_state_14($sp) ; + 0x4
   add3    $sp, $sp, -0x178
   add3    $1, $sp, 0x24   ; copy of f00d buffer
   sw      $3, 0x190+cookie_1C($sp) ; store cookie
   mov     $3, 0x150       ; size
   mov     $5, $2          ; get f00d buffer ptr (src)
   bsr     memcpy_810312   ; copy f00d buffer (request)
   lw      $3, 0x190+key_size_2C($sp)
   and3    $2, $3, 0xF
   */

   if($2 != 0)
   {
      #pragma region handle_error_80E68E

      movh    $3, 0x800F
      or3     $3, $3, 0x16
      sw      $3, 8($5)       ; store error
      
      lw      $2, 0x190+cookie_1C($sp) ; get cookie
      lw      $3, (cookie_810928) ; check cookie
      
      if ($2 != $3)
      {
         bsr     sub_80B092
      }

      add3    $sp, $sp, 0x178
      lw      $6, 0x18+prev_state_10($sp)
      lw      $5, 0x18+prev_state_C($sp)
      lw      $11, 0x18+prev_state_14($sp)
      add     $sp, 0x18
      jmp     $11

      #pragma endregion
   }

   /*
   lw      $1, 0x190+command_168($sp)
   movu    $2, 0x50001     ; command
   */

   if($1 == $2)
   {
      if($3 == 0)
      {
         goto handle_error_80E68E
      }
   }

   //lw      $3, 0x190+key_id_28($sp)

   if ($3 != 0)
   {
      movh    $2, 1

      if($3 != $2)
      {
         add     $2, 1

         if($3 != $2)
         {
            movh    $2, 2

            if($3 != $2)
            {
               add     $2, 1

               if($3 != $2)
               {
                  goto handle_error_80E68E
               }
            }
         }
      }
   }

   /*
   lw      $2, 0x190+slot_id_24($sp)
   add     $2, -0xC
   sltu3   $2, $2, 0xC
   */

   if($2 == 0)
   {
      goto handle_error_80E68E
   }

   //movu    $2, 0x10001     ; command

   if($3 == $2)
   {
      bsr     sub_80D318
      
      if($0 == 0)
      {
         goto handle_error_80E68E
      }
   }

   /*
   add3    $6, $sp, 4      ; address of the dest buffer for key
   mov     $2, 0
   mov     $3, 0x20
   mov     $1, $6
   bsr     sub_8102BC
   lw      $3, 0x190+command_168($sp)
   movu    $2, 0x50001     ; command
   */

   if($3 != $2)
   {
      #pragma region

      movu    $2, 0x60001
      
      if($3 != $2)
      {
         goto handle_error_80E68E
      }

      /*
      mov     $2, 0
      mov     $1, $6          ; dest buffer for key
      mov     $3, 0x20
      bsr     memset_810368   ; (char* dest, int value, int size)
      mov     $2, 0x20
      */

      lw      $3, 0x190+slot_id_24($sp)
      add3    $1, $sp, 4      ; key (probably modified)
      srl     $2, 2           ; / 4 = nblocks
      bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
      sw      $0, 8($5)       ; store error state = 0

      #pragma endregion
   }
   else
   {
      #pragma region

      /*
      lw      $3, 0x190+key_size_2C($sp)
      sltu3   $2, $3, 0x21
      */

      if($2 == 0)
      {
         goto handle_error_80E68E
      }

      /*
      mov     $1, $6          ; dest buffer for key = sp + 4
      add3    $2, $sp, 0x64   ; address of the key
      bsr     memcpy_810312   ; copy key
      lw      $3, 0x190+key_id_28($sp)
      */

      if($3 != 0)
      {
         movh    $2, 1
         
         if($3 != $2)
         {
            movu    $2, 0x10001
            
            if($3 != $2)
            {
               movh    $2, 2
               
               if($3 != $2)
               {
                  movu    $2, 0x20001
                  
                  if($3 !=  $2)
                  {
                     #pragma region

                     lw      $3, 8($5)

                     if($3 == 0)
                     {
                        lw      $2, 0x190+key_size_2C($sp)
                        
                        lw      $3, 0x190+slot_id_24($sp)
                        add3    $1, $sp, 4      ; key (probably modified)
                        srl     $2, 2           ; / 4 = nblocks
                        bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
                        sw      $0, 8($5)       ; store error state = 0
                     }

                     #pragma endregion
                  }
                  else
                  {
                     #pragma region

                     lw      $2, 0x190+key_size_2C($sp)
                     movu    $3, key4_81281C
                     mov     $1, $6          ; key

                     add3    $4, $3, 0x20
                     
                     bsr     sub_80E4CC

                     sw      $0, 8($5)

                     lw      $3, 8($5)

                     if($3 == 0)
                     {
                        lw      $2, 0x190+key_size_2C($sp)
                        
                        lw      $3, 0x190+slot_id_24($sp)
                        add3    $1, $sp, 4      ; key (probably modified)
                        srl     $2, 2           ; / 4 = nblocks
                        bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
                        sw      $0, 8($5)       ; store error state = 0
                     }

                     #pragma endregion
                  }
               }
               else
               {
                  #pragma region

                  lw      $2, 0x190+key_size_2C($sp)
                  movu    $3, key3_8127FC
                  mov     $1, $6          ; key

                  add3    $4, $3, 0x10

                  bsr     sub_80E43E

                  sw      $0, 8($5)

                  lw      $3, 8($5)

                  if($3 == 0)
                  {
                     lw      $2, 0x190+key_size_2C($sp)
                     
                     lw      $3, 0x190+slot_id_24($sp)
                     add3    $1, $sp, 4      ; key (probably modified)
                     srl     $2, 2           ; / 4 = nblocks
                     bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
                     sw      $0, 8($5)       ; store error state = 0
                  }

                  #pragma endregion
               }
            }
            else
            {
               #pragma region

               mov     $1, $6          ; key
               lw      $2, 0x190+key_size_2C($sp)
               movu    $3, key2_8127BC
               
               bsr     sub_80E162
            
               sw      $0, 8($5)

               lw      $3, 8($5)

               if($3 == 0)
               {
                  lw      $2, 0x190+key_size_2C($sp)
                  
                  lw      $3, 0x190+slot_id_24($sp)
                  add3    $1, $sp, 4      ; key (probably modified)
                  srl     $2, 2           ; / 4 = nblocks
                  bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
                  sw      $0, 8($5)       ; store error state = 0
               }

               #pragma endregion
            }
         }
         else
         {
            #pragma region

            lw      $2, 0x190+key_size_2C($sp)
            mov     $1, $6          ; key
            movu    $3, key1_81279C

            bsr     sub_80E162
            
            sw      $0, 8($5)

            lw      $3, 8($5)

            if($3 == 0)
            {
               lw      $2, 0x190+key_size_2C($sp)
               
               lw      $3, 0x190+slot_id_24($sp)
               add3    $1, $sp, 4      ; key (probably modified)
               srl     $2, 2           ; / 4 = nblocks
               bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
               sw      $0, 8($5)       ; store error state = 0
            }

            #pragma endregion
         }
      }
      else
      {
         #pragma region

         mov     $1, $6          ; key
         lw      $2, 0x190+key_size_2C($sp)
         movu    $3, key0_81277C
         
         bsr     sub_80E162
         
         sw      $0, 8($5)

         lw      $3, 8($5)

         if($3 == 0)
         {
            lw      $2, 0x190+key_size_2C($sp)
            
            lw      $3, 0x190+slot_id_24($sp)
            add3    $1, $sp, 4      ; key (probably modified)
            srl     $2, 2           ; / 4 = nblocks
            bsr     set_dmac5_key_80E26A ; (char* key, int nblocks, int slot)
            sw      $0, 8($5)       ; store error state = 0
         }

         #pragma endregion
      }

      #pragma endregion
   }

   /*
   lw      $2, 0x190+cookie_1C($sp) ; get cookie
   lw      $3, (cookie_810928) ; check cookie
      
   if ($2 != $3)
   {
      bsr     sub_80B092
   }

   add3    $sp, $sp, 0x178
   lw      $6, 0x18+prev_state_10($sp)
   lw      $5, 0x18+prev_state_C($sp)
   lw      $11, 0x18+prev_state_14($sp)
   add     $sp, 0x18
   jmp     $11
   */

   return 0;
}