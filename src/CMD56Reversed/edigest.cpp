#include "edigest.h"

#include <stdlib.h>
#include <string>

int __cdecl sha256_init_413D84(ctx_40A64C *ctx)
{
   signed int result;

   result = 0x80480500;
   if ( ctx )
   {
      ctx->state0[0] = 0x6A09E667;
      result = 0;
      ctx->state0[1] = 0xBB67AE85;
      ctx->state0[2] = 0x3C6EF372;
      ctx->state0[3] = 0xA54FF53A;
      ctx->state0[4] = 0x510E527F;
      ctx->state0[5] = 0x9B05688C;
      ctx->state0[6] = 0x1F83D9AB;
      ctx->state0[7] = 0x5BE0CD19;
      ctx->unk24 = 0;
      ctx->unk26 = 0;
      ctx->unk28 = 0;
      ctx->unk2C = 0;
   }

   return result;
}

int read_file_in_blocks_409BDC(int fd, char *buffer, unsigned int size)
{
   return 0;
}

int maybe_sha256_update_414004(ctx_40A64C *ctx, char *file_data, int size)
{
   return 0;
}

int maybe_sha256_final_413DF4(ctx_40A64C *ctx, char *digest2)
{
   return 0;
}

signed int sub_40A64C(int a1, ctx_40A64C_arg *a3, control_info_type4_t *control_info)
{
   char *v3; // ebx
   int type; // eax
   int v5; // ecx
   unsigned __int64 v6; // kr00_8
   int fd; // eax
   signed int error_code; // edx
   int fd1; // ebx
   char *v10; // eax
   int read_bytes; // eax
   char *v13; // edx
   signed int v14; // eax
   ctx_40A64C ctx; // [esp+0h] [ebp-100A8h]
   char file_data[65536]; // [esp+90h] [ebp-10018h]
   int v17; // [esp+10090h] [ebp-18h]
   char *v18; // [esp+10094h] [ebp-14h]
   char *v19; // [esp+10098h] [ebp-10h]
   int v20; // [esp+1009Ch] [ebp-Ch]

   //sub_4047B0(0x1009Cu, a1, v20);

   control_info->type = 4;
   control_info->size = 0x50;
   control_info->next = 0i64;

  /*
   LOBYTE(v3) = get_endianness_409C7C();
   if ( (_BYTE)v3 != (unsigned __int8)get_endianness_40CB9C() )
   {
      type = maybe_flip_bytes_409CAC(control_info->type);
      v5 = control_info->size;
      control_info->type = type;
      v3 = *(char **)&file_data[65532];
      control_info->size = maybe_flip_bytes_409CAC(v5);
      v6 = control_info->next;
      v17 = v6 >> 32;
      *(_DWORD *)&file_data[65532] = v6;
      control_info->next = maybe_flip_bytes_409CDC(*(__int64 *)&file_data[65532]);
   }
  */

   /*
   v19 = v3;
   v18 = v3;

   fd = open(a3->filepath, 0x8000);
   error_code = 1;
   fd1 = fd;
   if ( fd < 0 )
      return error_code;
   */

   memset(control_info->digest2, 0, 0x20);

   v10 = (char *)sha256_init_413D84(&ctx);

   error_code = 1;

   if ( !v10 )
   {
      /*
      while ( 1 )
      {
         v19 = v10;
      */
         read_bytes = read_file_in_blocks_409BDC(fd1, file_data, 0x10000u);
      /*
         if ( !read_bytes )
            break;
      */

         v19 = v13;
         v10 = (char *)maybe_sha256_update_414004(&ctx, file_data, read_bytes);
      /*
         if ( v10 )
            return 1;
      }
      */

      v19 = file_data;
      v18 = file_data;
      v14 = maybe_sha256_final_413DF4(&ctx, control_info->digest2);
      error_code = 1;

      /*
      if ( !v14 )
      {
         *(_DWORD *)control_info->digest1 = e_static_digest0_405608;
         *(_DWORD *)&control_info->digest1[4] = e_static_digest0_40560C;
         *(_DWORD *)&control_info->digest1[8] = e_static_digest0_405610;
         *(_DWORD *)&control_info->digest1[0xC] = e_static_digest0_405614;
         *(_DWORD *)&control_info->digest1[0x10] = e_static_digest0_405618;
         *(_DWORD *)&control_info->padding[4] = 0;
         *(_DWORD *)&control_info->padding[8] = 0;
         *(_DWORD *)control_info->padding = 0;
         close(fd1);
         error_code = 0;
      }
      */
   }
  
   return error_code;
}