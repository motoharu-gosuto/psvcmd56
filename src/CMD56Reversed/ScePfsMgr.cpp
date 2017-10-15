#include <map>
#include <stdint.h>

#include "SceIofilemgr.h"
#include "SceSysclib.h"

typedef struct ctx_21A27B8_70 //size is 0x160
{
   //8 + 44 + 14 = 60

   char unk_70[0x8]; //header
   
   uint32_t unk_78; //field
   uint32_t unk_7C;

   uint32_t unk_80; //field
   uint32_t unk_84;
   uint32_t unk_88; //field
   uint32_t unk_8C;

   uint32_t unk_90; //field
   uint32_t unk_94; //field
   uint32_t unk_98; //field
   uint32_t unk_9C; //field

   uint32_t unk_A0;
   uint32_t unk_A4;

   char unk_A8[0x14];
   char unk_BC[0x14];
   char unk_D0[0x100];

} ctx_21A27B8_70;

typedef struct ctx_21A27B8_18 //size is unknown
{
   uint32_t unk_0;
   uint32_t unk_4;

}ctx_21A27B8_18;

typedef struct node_holder
{
   vfs_node * node;
   uint32_t unk_4;
} node_holder;

typedef struct ctx_21A27B8_20 //size is 0x20
{
   ctx_21A27B8_18* unk_0;
   node_holder* unk_4;
   uint32_t unk_8;
   uint32_t unk_C;

   uint32_t unk_10;
   uint32_t unk_14;
   uint32_t unk_18;
   uint32_t unk_1C;

}ctx_21A27B8_20;

typedef struct ctx_21A27B8_40 //size is 0x28
{
   uint32_t unk_40;
   uint32_t unk_44;
   uint32_t unk_48;

   char unk_4C[0x14];

   uint32_t unk_60;
   uint32_t unk_64;

}ctx_21A27B8_40;

typedef struct ctx_21A27B8
{
   char data0[0x14];

   node_holder * unk_14;
   ctx_21A27B8_18* unk_18; //field
   uint32_t unk_1C;

   ctx_21A27B8_20 unk_20; //field

   ctx_21A27B8_40 unk_40; //field

   uint32_t unk_68; //field
   uint32_t unk_6C;

   ctx_21A27B8_70 unk_70;
   
   uint32_t unk_1D0;

}ctx_21A27B8;

//this function provides only pair as a responce

int sub_2199144(node_holder* node, std::pair<uint32_t, uint32_t>* result_pair)
{
   //var_D0
   int result_length;
   vfs_node_func15_arg1 arg1;
   vfs_node_func15_arg2 arg2;
   char dest_5C[0x40]; //data from node
   int var_1C = var_009EA004; //cookie
   
   SceIofilemgrForDriver_unk_aa253b68(node->node, dest_5C, 0x40, &result_length); //get dest_5C from vfs_node

   int length = strnlen(dest_5C, 0x3F);

   arg1.data = dest_5C;
   arg1.len = length;
   arg1.unk_8 = 0;

   SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(node->node); //wait - standard wrap

   int result_15 = SceIofilemgrForDriver_vfs_node_func15_50a63acf(node->node, &arg1, &arg2); //execute node function 15

   SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(node->node); //set - standard wrap

   if(result_15 >= 0)
   {
      result_pair->first = arg2.unk_8;
      result_pair->second = arg2.unk_C;
   }

   if(var_1C == var_009EA004)
      return STACK_CHECK_FAIL;
   else
      return result_15;
}

//num0, num1 are probably offset
int read_wrapper_2199064(node_holder* unk0, char *buffer, int size, int ignored, int offsetLo, int offsetHi, uint32_t* readBytes)
{
   /*
   var_3C= -0x3C
   var_38= -0x38
   */

   int var_30 = 0;
   
   int var_2C = var_009EA004;

   /*
   var_28= -0x28
   var_24= -0x24
   var_20= -0x20
   var_1C= -0x1C
   var_18= -0x18
   var_14= -0x14
   var_10= -0x10
   var_C= -0xC
   var_8= -8 
   var_4= -4 
   */

   SceIofilemgrForDriver_sceVfsNodeWaitEventFlag_aa45010b(unk0->node);

   int f_result = SceIofilemgrForDriver_vfs_node_func5_or_19_abbc80e3(unk0->node, unk0->unk_4, buffer, size, offsetLo, offsetHi, &var_30);
   
   SceIofilemgrForDriver_sceVfsNodeSetEventFlag_6048f245(unk0->node);
   
   if(f_result >= 0)
   {
      *readBytes = var_30;

      if(var_2C == var_009EA004)
         return 0;
      else
         return STACK_CHECK_FAIL;
   }
   else
   {
      if(var_2C == var_009EA004)
         return f_result;
      else
         return STACK_CHECK_FAIL;
   }
}

void sub_21A0E3C(ctx_21A27B8_20* unk0, ctx_21A27B8_18* unk1, node_holder* unk2, int unk3, int arg_0, int arg_4)
{
   unk0->unk_0 = unk1;
   unk0->unk_4 = unk2;
   unk0->unk_8 = 0xFFFFFFFF;
   unk0->unk_C = 0xFFFFFFFF;
   unk0->unk_10 = 0x80;
   unk0->unk_14 = 0x80;
   unk0->unk_18 = arg_0;
   unk0->unk_1C = arg_4;
}

void proc_copy_14_bytes_219DE1C(char unk0[0x14], char unk1[0x14])
{
   memcpy(unk0, unk1, 0x14);
}

int SceKernelUtilsForDriver_29a28957(ctx_21A27B8* base, int size1, ctx_21A27B8_70* data_base, int size2, char bytes14[0x14])
{
   //this function is powered by table of function pointers that are called indirectly

   //wrapper for sub_9DD908

   //SceSysmem.SceKernelUtilsForDriver._exp_87dc7f2f
   //SceSysmem.SceKernelUtilsForDriver._exp_e4390ffa
   //SceSysmem.SceKernelUtilsForDriver._exp_478a6f3c
   //SceSysmem.SceKernelUtilsForDriver._exp_48f24106

   return 0;
}

/*
sub_219FE44 - returns ctx_21A27B8*

sub_21A27A8
PUSH		{R3,LR}
ADDS		R0, #0x20
BL		sub_21A0E60
POP		{R3,PC}
; End of function sub_21A27A8

;clear - opposite to sub_21A0E3C ?
sub_21A0E60
VMOV.I32	D16, #0x80
MOVS		R3, #0
VMOV.I8		D17, #0xFF
STRD.W		R3, R3,	[R0]
VSTR		D17, [R0,#8]
VSTR		D16, [R0,#0x10]
VSTR		D16, [R0,#0x18]
BX		LR
; End of function sub_21A0E60
*/

int sub_B99C40(int unk0, int unk1, char* dst, int unk3, int arg_0, int arg_4)
{
    /*
    stack_unk0= -0x58
    stack_unk1= -0x54
    stack_unk2= -0x50
    stack_unk3= -0x4C
    var_48=	-0x48
    var_44=	-0x44
    var_21=	-0x21
    id=  4
    var_s8=	 8
    var_sC=	 0xC
    size=  0x14
    arg_0=	0x40
    arg_4=	0x44
    */

    int cookie;

    /*
    MOVW		R5, #0xA004
    ADD		R7, SP,	#0x18
    MOVT.W		R5, #0x9E
    LDR		R6, [R0,#0x28] ; part of some command
    MOV		R4, R0
    LDR.W		R8, [R7,#arg_0]
    SUB		SP, SP,	#0x40 ;	stack_unk0
    LDR		R0, [R5]
    TST.W		R2, #0x1F ; pointer alignment test?
    ADD.W		R10, SP, #0x58+var_21
    ORR.W		R6, R6,	#3 ; part of some command
    MOV		R9, R2
    MOV		R12, R3
    ORR.W		R6, R6,	R8 ; part of some command
    STR		R0, [R7,#size]
    BIC.W		R10, R10, #0x1F
    LDR.W		LR, [R7,#arg_4]
    */
    		
    if(true) //BEQ
    {
        /*
        LDR		R0, [R4,#0x38] ; id
        MOV		R3, R4	; param0
        LDRD.W		R9, R8,	[R4,#0x2C]
        LDR		R4, [R4,#0x34]
        STR.W		R12, [SP,#0x58+stack_unk0] ; stack_unk0
        STR		R6, [SP,#0x58+stack_unk2] ; stack_unk2
        STRD.W		R8, R4,	[SP,#0xC]
        STR.W		LR, [SP,#0x58+var_44]
        STR.W		R9, [SP,#0x58+stack_unk1] ; stack_unk1
        BL		sub_B99674 ; dmac_id id, void* vaddr_0, void* vaddr_1, void* vaddr_2, int arg_0, int arg_4, int arg_8, int arg_C, int arg_10, char* arg_14
        MOV		R4, R0
        
        if(var_009EA004 == cookie)
            return R4;
        else
            return STACK_CHECK_FAIL;
        */
    }
    else
    {
        /*
        LDR		R0, [R4,#0x38]
        MOV		R3, R4	; param0
        MOV		R2, R10	; src for later ?
        STR		R0, [R7,#id]
        LDR		R0, [R4,#0x2C]
        STR		R0, [R7,#var_sC]
        LDR		R0, [R4,#0x34]
        STR		R0, [R7,#var_s8]
        LDR		R0, [R4,#0x30]
        STR.W		R12, [SP,#0x58+stack_unk0] ; stack_unk0
        STR		R6, [SP,#0x58+stack_unk2] ; stack_unk2
        ORR.W		R11, R0, #0x3FC00
        STR.W		LR, [SP,#0x58+var_44]
        ORR.W		R11, R11, #0x200
        LDR		R0, [R7,#id] ; id
        STR.W		R11, [R4,#0x30]
        LDR		R4, [R7,#var_sC]
        STR.W		R11, [SP,#0x58+stack_unk3] ; stack_unk3
        STR		R4, [SP,#0x58+stack_unk1] ; stack_unk1
        LDR		R4, [R7,#var_s8]
        STR		R4, [SP,#0x58+var_48]
        BL		sub_B99674 ; dmac_id id, void* vaddr_0, void* vaddr_1, void* vaddr_2, int arg_0, int arg_4, int arg_8, int arg_C, int arg_10, char* arg_14
        MOV		R4, R0
        BICS.W		R0, R8,	#0x800
        */
        
        if(true) //BEQ
        {
            /*
            int R3 = R6 & 0x07
            int R2 = R6 & 0x38
            
            if(R3 != 3)
            {
                memcpy(R9, R10, 0x800F1516);
                
                if(var_009EA004 == cookie)
                    return R4;
                else
                    return STACK_CHECK_FAIL;
            }
            else
            {
                if(R2 == 0x38)
                {
                    memcpy(R9, R10, 0x10);
                    
                    if(var_009EA004 == cookie)
                        return R4;
                    else
                        return STACK_CHECK_FAIL;
                }
                else
                {
                    if((R6 & 0x18) == 0)
                    {
                        memcpy(R9, R10, 0x14);
                        
                        if(var_009EA004 == cookie)
                            return R4;
                        else
                            return STACK_CHECK_FAIL;
                    }
                    else
                    {
                        if(R6 == 0x10)
                        {
                            memcpy(R9, R10, 0x20);
                            
                            if(var_009EA004 == cookie)
                                return R4;
                            else
                                return STACK_CHECK_FAIL;
                        }
                        else
                        {
                            memcpy(R9, R10, 0x800F1516);
                            
                            if(var_009EA004 == cookie)
                                return R4;
                            else
                                return STACK_CHECK_FAIL;
                        }
                    }
                }
            }
            */
        }
        else
        {
            /*
            if(var_009EA004 == cookie)
                return R4;
            else
                return STACK_CHECK_FAIL;
            */
        }
    }

    return 0;
}

int sub_B99E8C(ctx_21A27B8_70* data_base, char* dest, int size, char* src, int arg_0, int arg_4, int arg_8, int arg_C, int arg_10)
{
   //SceKernelSuspendForDriver_call_func_008B808C_atomic_inc_008BF3FC_4df40893

   //memset - 0x40

   //SceSblSsMgr.SceDmacmgrForDriver_dmac_enter_7cd5088a

   //proc_copy_to_from_B9A578

   //sub_B99C40 -> sub_B99674 - this is generic dmac procedure that is used for example in SceSblSsMgrForDriver_4dd1b2e5 to generate 0x40 random byte sequence

   //proc_copy_from_to_B9A5D8

   //proc_dmac_exit_B99A18 -> SceDmacmgrForDriver_dmac_exit_adff1186

   //SceKernelSuspendForDriver_call_func_008B8084_atomic_dec_008BF3FC_2bb92967

   //sub_B99C40

   return 0;
}

int SceSblSsMgrForDriver_6704d985(ctx_21A27B8_70* data_base, char* dest, int size, char* src, int arg_0, int arg_4, int arg_8)
{
   return sub_B99E8C(data_base, dest, size, src, 0x100, arg_0, arg_4, 0x23, arg_8);
}

//it looks like this procedure takes base->data0 and data_base as input
//and produces bytes14 as output
int proc_crypto_stuff_219DE7C(char bytes14[0x14], ctx_21A27B8* base, ctx_21A27B8_70* data_base, int size)
{
   char buffer0[0x80]; //128
   char buffer1[0x80]; //128

   int var_2C = var_009EA004; //cookie

   if(size == 0)
   {
      SceKernelUtilsForDriver_29a28957(base, 0x14, data_base, size, bytes14);

      if(var_2C == var_009EA004)
         return 0;
      else
         return STACK_CHECK_FAIL;
   }
   else
   {
      char* src = ((0 - (int)buffer0) & 0x3F) + buffer0; //align down?
      char* dst = ((0 - (int)buffer1) & 0x3F) + buffer1; //align down?

      memset((src + 8), 0, 0x18);

      memcpy(src, base->data0, 0x14);

      int result = SceSblSsMgrForDriver_6704d985(data_base, dst, size, src, 0, 1, 0);

      if(result == 0)
      {
         memcpy(bytes14, dst, 0x14);
      }

      if(var_2C == var_009EA004)
         return result;
      else
         return STACK_CHECK_FAIL;
   }
}

//unk1 is ignored
void sub_21A0E28(ctx_21A27B8_20* unk0, char unk1[0x14], int unk2, int unk3, int arg_0, int arg_4)
{
   unk0->unk_8 = unk2;
   unk0->unk_C = unk3;
   unk0->unk_10 = arg_0;
   unk0->unk_14 = arg_4;
}

int sub_21A6A10(ctx_21A27B8_40* unk0, ctx_21A27B8* unk1, ctx_21A27B8_20* unk2, int unk3, int arg_0)
{
   return 0;
}

//----------------

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

int proc_SCENGPFS_21A27B8(ctx_21A27B8* argument0, node_holder* argument1, char argument2[0x14])
{
   //var_294= -0x294         
   //var_290= -0x290
   uint32_t var_28C; //read bytes value
   std::pair<uint32_t, uint32_t> result_p; //size is 0x8 bytes in total
   char unk0[0x14]; //0x14 bytes
   char destination[0x240]; //size is 0x100 or 0x200 aligned to 0x40 (that is why 0x240 in total). this is multipurpose buffer
   int var_2C = var_009EA004; //cookie

   argument0->unk_14 = argument1;

   int result0 = sub_2199144(argument1, &result_p); //call vfs_node_func15 (sceIoGetstatForDriver) - only provides pair responce

   if(result0 != 0)
      return loc_21A292C(result0, var_2C);

   if((result_p.first | result_p.second) == 0)
      return loc_21A292E(0x80140904, var_2C);

   char* aligned_buffer = (char*)(((uint32_t)destination + 0x3F) & (~0x3F)); //align up to 0x40
   
   int result1 = read_wrapper_2199064(argument0->unk_14, aligned_buffer, 0x200, 0, 0x200, 0, &var_28C); // call func5_or_19

   if(result1 != 0)
      return loc_21A292C(result1, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);
    
   int some_value = aligned_buffer[0x60]; //save some value from files.db file
   argument0->unk_68 = some_value;

   if(some_value != 0)
      return loc_21A292E(0x8014090A, var_2C);

   //not sure about 0x80 80
   int result2 = read_wrapper_2199064(argument0->unk_14, aligned_buffer, 0x200, 0, 0x80, 0x80, &var_28C); // call func5_or_19

   if(result2 != 0)
      return loc_21A292C(result2, var_2C);

   if(var_28C != 0x200)
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(&argument0->unk_70, aligned_buffer, 0x160); //copy 0x160 bytes of files.db beginning into buffer

   //-----------

   if(strncmp("SCENGPFS", argument0->unk_70.unk_70, 8) != 0) //verify header
      return loc_21A292E(0x8014090A, var_2C);

   memcpy(argument0->data0, argument2, 0x14); //copy 0x14 bytes of some input data

   int r5 = argument0->unk_70.unk_80; //offset 0x10 in file - some kind of size ?

   if(r5 != argument0->unk_18->unk_4)
      return loc_21A292E(0x80140909, var_2C);

   int r3 = argument0->unk_70.unk_78 - 1; //offset 0x08 in file - some kind of counter ?

   if(r3 <= 1)
      r5 = 0x160;

   //assign values to argument0->unk_20
   sub_21A0E3C(&argument0->unk_20, argument0->unk_18, argument0->unk_14, r3, r5, 0);

   memcpy(destination, argument0->unk_70.unk_D0, 0x100); //offset 0x60 in file - copy 0x100 bytes

   proc_copy_14_bytes_219DE1C(unk0, argument0->unk_70.unk_BC); //offset 0x4C in real file - copy 0x14 bytes

   memset(argument0->unk_70.unk_BC, 0, 0x14); //clear read data

   memset(argument0->unk_70.unk_D0, 0, 0x100); //clear read data

   proc_crypto_stuff_219DE7C(argument0->unk_70.unk_BC, argument0, &argument0->unk_70, 0x160);

   //there can be two problems of why proc_verify_14_bytes_219DE44 returns an error
   //1 - file reading does not work - I do not think this is true since other files are read correctly on sector level in Sdif
   //2 - argument2 data is invalid - I need to check how this data is obtained.
   //                                It is obtained from sub_219E1D8 -> sub_219DE54 -> ScePfsMgr.SceKernelUtilsForDriver._imp_87dc7f2f
   //                                What is interesting here is that 87dc7f2f is one of the functions from function table from SceKernelUtilsForDriver_29a28957 - which is an alternative for SceSblSsMgr call
   //                                478a6f3c and 48f24106 are also part of table but they also are called from 87dc7f2f

   //argument0->unk_70.unk_BC - is produced as the result by crypto procedure
      //crypto procedure takes argument0->data0 and argument0->unk_70 as input
         //argument0->data0 - is copy of argument2 that is passed to this procedure
         //argument0->unk_70 - it is taken from aligned_buffer - which is read from files.db

   //unk0 is taken from previous value of argument0->unk_70.unk_BC - it is taken from aligned_buffer - which is read from files.db
   int result3 = proc_verify_14_bytes_219DE44(unk0, argument0->unk_70.unk_BC);

   if(result3 == 0)
      return loc_21A292E(0x80140902, var_2C);

   sub_21A0E28(&argument0->unk_20, argument0->unk_70.unk_BC, argument0->unk_70.unk_90, argument0->unk_70.unk_94, argument0->unk_70.unk_98, argument0->unk_70.unk_9C);

   int result4 = sub_21A6A10(&argument0->unk_40, argument0, &argument0->unk_20, argument0->unk_70.unk_88, argument0->unk_70.unk_78); //some vfs node functions inside

   if(result4 != 0)
      return loc_21A292C(result4, var_2C);

   int result5 = proc_verify_14_bytes_219DE44(argument0->unk_70.unk_A8, argument0->unk_40.unk_4C);

   if(result5 == 0)
      return loc_21A292E(0x80140902, var_2C);

   memcpy(argument0->unk_70.unk_D0, &destination, 0x100);

   memcpy(argument0->unk_70.unk_BC, unk0, 0x14);
   
   return loc_21A292E(0, var_2C);
}

int loc_219CB8C()
{
   /*
   LDR             R5, [SP,#0x1E8+var_1C0]
   LDR             R2, [SP,#0x1E8+var_2C]
   LDR             R3, [R5]
   */

//   if(r2 == r3)
//      return r0;
//   else
      return STACK_CHECK_FAIL;
}

int crypto_ioctl_219C9E8(SceUID fd, int unk1, int unk2, SceOff offset, int dispatcherFlag)
{
   /*
   MOVW            R5, #0xA004
   SUB             SP, SP, #0x1C4 ; arg_0
   MOVT.W          R5, #0x9E
   MOV             R8, R0  ; SceUID fd
   MOVS            R3, #0  ; ignored
   STR             R2, [SP,#0x1E8+var_1D0] ; store int unk2
   STR             R5, [SP,#0x1E8+var_1C0]
   LDR             R2, [R5]
   LDR             R5, [SP,#0x1E8+dispatcherFlag]
   STR             R1, [SP,#0x1E8+var_1CC]
   LDRD.W          R0, R1, [SP,#0x1E8+offset] ; get offset ?
   STR             R5, [SP,#0x1E8+var_1B4]
   LDR             R5, [SP,#0x1E8+var_1D0] ; get int unk2
   STR             R3, [SP,#0x1E8+dst] ; =0
   STR             R2, [SP,#0x1E8+var_2C]
   STRD.W          R0, R1, [SP,#0x20]
   */

//   if(r5 == 0)
   {
      //LDR.W           R10, [SP,#0x1E8+var_1D0]
   }
//   else
   {
      /*
      ADD             R5, SP, #0x1E8+unk0 ; void *outdata;
      ADD             R4, SP, #0x1E8+var_198
      STR             R5, [SP,#0x1E8+var_1BC] ; store void *outdata;
      ADD             R5, SP, #0x1E8+var_170
      MOV             R11, R4 ; void *indata;
      MOV             R10, R3 ; =0
      STR             R5, [SP,#0x1E8+var_1B8]
      MOV             R6, R3  ; =0
      MOV             R9, R3  ; =0
      LDR             R7, [SP,#0x1E8+var_1BC] ; get void *outdata;
      MOV             R4, R8  ; SceUID fd
      */

      while(true)
      {
         /*
         LDR             R2, [SP,#0x1E8+var_1D0]
         MOV.W           R8, #0x100
         LDR             R0, [SP,#0x1E8+var_1CC]
         STR.W           R4, [R11] ; store SceUID fd
         SUBS            R1, R2, R6 ; R6 = 0
         LDRD.W          R2, R3, [SP,#0x20]
         ADD             R0, R6  ; R6 = 0
         STRD.W          R9, R9, [R11,#0x18] ; =0
         STRD.W          R0, R1, [R11,#4]
         ADDS            R2, R2, R6
         STR.W           R9, [R11,#0x20]
         ADC.W           R3, R3, #0
         STRD.W          R2, R3, [R11,#0x10]
         MOVS            R3, #4
         ADD             R2, SP, #0x1E8+dst
         STR.W           R3, [R11,#0xC]
         STR.W           R2, [R11,#0x24]
         BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
         */

//         if(r0 != 0)
         {
            /*
            LDR.W           R8, [R0,#0x2C]
            CMP.W           R8, #0
            IT GE
            UXTHGE.W        R8, R8
            */
         }

         /*
         BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
         MOVS            R1, #0xF
         */

 //        if(r0 != 0)
         {
            //LDR             R1, [R0,#0x28] ; unk1
         }

         /*
         ADD             R2, SP, #0x1E8+var_198+0x18
         ADD             R3, SP, #0x1E8+var_198+0x20
         STR             R2, [SP,#0x1E8+arg_4] ; arg_4
         MOVS            R2, #1
         STR             R3, [SP,#0x1E8+arg_0] ; arg_0
         MOV             R0, R8  ; unk0
         ADD             R3, SP, #0x1E8+var_198+0x1C ; unk3
         STR             R2, [SP,#0x1E8+arg_8] ; arg_8
         LDR.W           R2, [R11,#0xC] ; unk2
         BL              crypto_ScePfsCryptBufVC_21A179C
         MOV             R3, R0
         */

//         if(r0 != 0)
         {
            /*
            MOV             R8, R4
            MOV             R4, R11
            MOV             R11, R3
            */

            //CMP.W           R10, #1

            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R11
            */

            return loc_219CB8C();
         }

         /*
         MOVW            R1, #0x4420 ; cmd
         MOVS            R2, #0x28 ; int inlen
         MOVS            R3, #0x58 ; outlen
         ADD             R0, SP, #0x1E8+args ; args
         STR             R4, [SP,#0x1E8+args] ;  SceUID fd;
         STR.W           R11, [SP,#0x1E8+args.indata] ; void *indata;
         STR             R7, [SP,#0x1E8+args.outdata] ; void *outdata;
         STR             R1, [SP,#0x1E8+args.cmd] ; unsigned int cmd;
         STR             R2, [SP,#0x1E8+args.inlen] ; int inlen;
         STR             R3, [SP,#0x1E8+args.outlen] ; int outlen;
         BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
         */

//         if(r0 != 0)
         {
            /*
            MOV             R8, R4
            MOV.W           R5, #0x100
            MOV             R4, R11
            MOV             R11, R0
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
            */

//            if(r0 != 0)
            {
               /*
               LDR             R5, [R0,#0x2C]
               CMP             R5, #0
               IT GE
               UXTHGE          R5, R5
               */
            }

            /*
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
            MOVS            R1, #0xF
            */

//            if(r0 != 0)
            {
               //LDR             R1, [R0,#0x28] ; unk1
            }

            /*
            LDR             R6, [R4,#0x18]
            MOV             R0, R5  ; unk0
            LDRD.W          R3, R5, [R4,#0x1C]
            LDR             R2, [R4,#0xC] ; unk2
            STMEA.W         SP, {R5,R6}
            BL              crypto_ScePfsCryptBufVC_21A19A8
            */

            //CMP.W           R10, #1

            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R11
            */

            return loc_219CB8C();
         }

         //LDR             R2, [R7,#0x28]

//         if(r2 != 0)
         {
            /*
            STR             R0, [SP,#0x1E8+var_1D4]
            BLX             ScePfsMgr.SceThreadmgrForDriver._imp_sceKernelGetThreadIdForDriver_59d06540
            LDR             R3, [SP,#0x1E8+var_1D4]
            STR             R0, [R5,#0x10]
            MOV             R0, R5  ; unk0
            STR             R3, [R5,#0x14]
            STRD.W          R7, R3, [R5,#8]
            BL              signal_ScePfsCryptEngineTodoMtx_219BD88
            MOV             R3, R0
            */

  //          if(r3 != 0)
            {
               /*
               MOV             R8, R4
               MOV             R4, R11
               MOV             R11, R3
               */

               //CMP.W           R10, #1

               /*
               ADD             R0, SP, #0x1E8+dst
               BL              proc_memset_96_219B5C4
               MOV             R0, R11
               */

               return loc_219CB8C();
            }

            /*
            LDR             R3, [R7,#0x28]
            ADD             R6, R3
            */

//            if(r10 != 1)
            {
               /*
               LDR             R0, [SP,#0x1E8+var_1D0]
               ADDS            R7, #0x58
               ADDS            R5, #0x18
               */

//               if(r0 <= r6)
               {
                  /*
                  MOV             R8, R4
                  MOV.W           R10, #1
                  */

                  break;
               }
//               else
               {
                  //MOV.W           R10, #1

                  continue;
               }
            }
 //           else
            {
               /*
               MOV             R8, R4
               MOV.W           R10, #2
               */

               break;
            }
         }
//         else
         {
            /*
            MOV             R8, R4
            MOV.W           R5, #0x100
            MOV             R4, R11
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
            */

//            if(r0 != 0)
            {
               /*
               LDR             R5, [R0,#0x2C]
               CMP             R5, #0
               IT GE
               UXTHGE          R5, R5
               */
            }

            /*
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e
            MOVS            R1, #0xF
            */
         
//            if(r0 != 0)
            {
               //LDR             R1, [R0,#0x28] ; unk1
            }

            /*
            MOV             R0, R5
            LDR             R6, [R4,#0x18]
            LDRD.W          R3, R5, [R4,#0x1C]
            LDR             R2, [R4,#0xC] ; unk2
            STMEA.W         SP, {R5,R6}
            BL              crypto_ScePfsCryptBufVC_21A19A8
            MOV             R11, R0
            */

//            if(r0 != 0)
            {
               //CMP.W           R10, #1

               /*
               ADD             R0, SP, #0x1E8+dst
               BL              proc_memset_96_219B5C4
               MOV             R0, R11
               */

               return loc_219CB8C();
            }
  //          else
            {
               break;
            }
         }
      }
   }   

   //LDR             R5, [SP,#0x1E8+var_1B4]

//   if(r5 != 0)
   {
      //BLX             ScePfsMgr.SceIofilemgrForDriver._imp_thread_related_12f8d58e

//      if(r0 == 0)
      {
         /*
         loc_219CD30             ; Internal
         MOV.W           R0, #0x100
         */
      }
//      else
      {
         /*
         LDR             R0, [R0,#0x2C]
         CMP             R0, #0
         IT GE
         UXTHGE          R0, R0
         */
      }

      /*
      BLX             ScePfsMgr.SceIofilemgrForDriver._imp_io_dispatcher_signal_15c17487
      MOV             R7, R0
      */

 //     if(r0 != 0)
      {
         /*
         ADD             R5, SP, #0x1E8+unk0
         MOVS            R4, #0
         */

 //        if(r10 != 0)
         {
            while(true)
            {
               /*
               MOV             R0, R5
               ADDS            R4, #1
               BL              crypto_ScePfsCryptBufVC_219BB70
               ADD.W           R5, R5, #0x58
               */

 //              if(r4 == r10)
                  break;
            }
         }

         /*
         ADD             R0, SP, #0x1E8+dst
         BL              proc_memset_96_219B5C4
         MOV             R0, R7
         */

         return loc_219CB8C();
      }
   }

 //  if(r10 == 0)
   {
      //MOV             R11, R10

      /*
      ADD             R0, SP, #0x1E8+dst
      BL              proc_memset_96_219B5C4
      MOV             R0, R11
      */

      return loc_219CB8C();
   }

   /*
   ADD             R5, SP, #0x1E8+var_170
   MOV.W           R11, #0
   STR             R5, [SP,#0x1E8+var_1B8]
   ADD             R5, SP, #0x1E8+unk0
   STR             R5, [SP,#0x1E8+var_1BC]
   MOV             R6, R11
   LDRD.W          R7, R5, [SP,#0x2C]
   ADD             R4, SP, #0x1E8+var_198
   MOV             R9, R7
   MOV             R7, R8
   MOV             R8, R11
   */
   
   while(true)
   {
      /*
      MOV             R0, R5
      BL              wait_ScePfsCryptEngineDone_219BEA0
      MOV             R3, R0
      */

 //     if(r0 != 0)
      {
         /*
         LDR             R0, [SP,#0x1E8+var_1BC]
         MOVS            R2, #0x58
         STR             R2, [R4,#0x14]
         MOVW            R1, #0x4422
         MOV             R9, R3
         STRD.W          R7, R1, [R4]
         MOV             R8, R7
         MLA.W           R5, R2, R6, R0
         MOVS            R2, #0
         MOV             R0, R4  ; args
         STR             R2, [R4,#8]
         STRD.W          R2, R5, [R4,#0xC]
         BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
         MOV             R0, R5  ; unk0
         BL              crypto_ScePfsCryptBufVC_219BB70
         */

         //ADDS            R6, #1

  //       if(r10 <= r6)
         {
            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
//         else
         {
            /*
            LDR             R5, [SP,#0x1E8+var_1B8]
            ADD.W           R0, R6, R6,LSL#1
            ADD.W           R0, R5, R0,LSL#3 ; unk0
            BL              wait_ScePfsCryptEngineDone_219BDD4
            LDR             R5, [SP,#0x1E8+var_1BC]
            MOVS            R2, #0x58
            STR             R2, [R4,#0x14]
            MOVW            R1, #0x4422
            MOV             R0, R4  ; args
            STRD.W          R8, R1, [R4]
            MLA.W           R6, R2, R6, R5
            MOVS            R2, #0
            STR             R2, [R4,#8]
            STRD.W          R2, R6, [R4,#0xC]
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
            MOV             R0, R6  ; unk0
            BL              crypto_ScePfsCryptBufVC_219BB70
            */

            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
      }

      //LDR             R3, [R5,#0xC] //?????????????????????????

  //    if(r3 != 0)
      {
         /*
         LDR             R0, [SP,#0x1E8+var_1BC]
         MOVS            R2, #0x58
         STR             R2, [R4,#0x14]
         MOVW            R1, #0x4422
         MOV             R9, R3
         STRD.W          R7, R1, [R4]
         MOV             R8, R7
         MLA.W           R5, R2, R6, R0
         MOVS            R2, #0
         MOV             R0, R4  ; args
         STR             R2, [R4,#8]
         STRD.W          R2, R5, [R4,#0xC]
         BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
         MOV             R0, R5  ; unk0
         BL              crypto_ScePfsCryptBufVC_219BB70
         */

         //ADDS            R6, #1

   //      if(r10 <= r6)
         {
            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
  //       else
         {
            /*
            LDR             R5, [SP,#0x1E8+var_1B8]
            ADD.W           R0, R6, R6,LSL#1
            ADD.W           R0, R5, R0,LSL#3 ; unk0
            BL              wait_ScePfsCryptEngineDone_219BDD4
            LDR             R5, [SP,#0x1E8+var_1BC]
            MOVS            R2, #0x58
            STR             R2, [R4,#0x14]
            MOVW            R1, #0x4422
            MOV             R0, R4  ; args
            STRD.W          R8, R1, [R4]
            MLA.W           R6, R2, R6, R5
            MOVS            R2, #0
            STR             R2, [R4,#8]
            STRD.W          R2, R6, [R4,#0xC]
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
            MOV             R0, R6  ; unk0
            BL              crypto_ScePfsCryptBufVC_219BB70
            */

            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
      }

      /*
      LDR.W           R0, [R9,#0x10]
      MOV             R11, R3
      LDR.W           R1, [R9,#0x28]
      LDRD.W          R2, R3, [R9,#0x20]
      STR.W           R11, [SP,#0x1E8+var_198+0xC]
      STRD.W          R11, R11, [SP,#0x54]
      STRD.W          R11, R11, [SP,#0x60]
      STRD.W          R7, R0, [R4]
      STRD.W          R2, R3, [R4,#0x10]
      STR             R1, [R4,#8]
      BL              proc_threadmgr_3a72c6d8_219C9D4
      STR.W           R9, [R0]
      MOV             R0, R4  ; args
      BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoPreadForDriver_0b54f9e0
      STR             R0, [SP,#0x1E8+var_1D4]
      BL              proc_threadmgr_3a72c6d8_219C9D4
      LDR             R3, [SP,#0x1E8+var_1D4]
      STR.W           R11, [R0]
      */

   //   if(r3 < 0)
      {
         /*
         MOV             R8, R7
         MOVS            R1, #0x58
         MOV             R7, R9
         MOVW            R5, #0x4422
         MOV             R0, R4  ; args
         STRD.W          R11, R11, [R4,#8]
         MOV             R9, R3 // result if pread
         STR.W           R8, [R4]
         STR             R7, [R4,#0x10]
         STR             R5, [R4,#4]
         STR             R1, [R4,#0x14]
         BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
         MOV             R0, R7  ; unk0
         BL              crypto_ScePfsCryptBufVC_219BB70
         */

          //ADDS            R6, #1

    //     if(r10 <= r6)
         {
            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
//         else
         {
            /*
            LDR             R5, [SP,#0x1E8+var_1B8]
            ADD.W           R0, R6, R6,LSL#1
            ADD.W           R0, R5, R0,LSL#3 ; unk0
            BL              wait_ScePfsCryptEngineDone_219BDD4
            LDR             R5, [SP,#0x1E8+var_1BC]
            MOVS            R2, #0x58
            STR             R2, [R4,#0x14]
            MOVW            R1, #0x4422
            MOV             R0, R4  ; args
            STRD.W          R8, R1, [R4]
            MLA.W           R6, R2, R6, R5
            MOVS            R2, #0
            STR             R2, [R4,#8]
            STRD.W          R2, R6, [R4,#0xC]
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
            MOV             R0, R6  ; unk0
            BL              crypto_ScePfsCryptBufVC_219BB70
            */

            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
      }

      /*
      MOVW            R1, #0x4422
      MOVS            R2, #0x58
      MOV             R0, R4  ; args
      STRD.W          R1, R11, [R4,#4]
      STRD.W          R11, R9, [R4,#0xC]
      ADD             R8, R3
      STR             R7, [R4]
      STR             R2, [R4,#0x14]
      BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
      SUBS            R3, R0, #0
      */

  //    if(r3 < 0)
      {
         /*
         MOV             R8, R7
         MOV             R7, R9
         MOV             R0, R7  ; unk0
         MOV             R9, R3
         BL              crypto_ScePfsCryptBufVC_219BB70
         */

         //ADDS            R6, #1

//         if(r10 <= r6)
         {
            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
 //        else
         {
            /*
            LDR             R5, [SP,#0x1E8+var_1B8]
            ADD.W           R0, R6, R6,LSL#1
            ADD.W           R0, R5, R0,LSL#3 ; unk0
            BL              wait_ScePfsCryptEngineDone_219BDD4
            LDR             R5, [SP,#0x1E8+var_1BC]
            MOVS            R2, #0x58
            STR             R2, [R4,#0x14]
            MOVW            R1, #0x4422
            MOV             R0, R4  ; args
            STRD.W          R8, R1, [R4]
            MLA.W           R6, R2, R6, R5
            MOVS            R2, #0
            STR             R2, [R4,#8]
            STRD.W          R2, R6, [R4,#0xC]
            BLX             ScePfsMgr.SceIofilemgrForDriver._imp_t_sceIoIoctlForDriver_c1dd4317
            MOV             R0, R6  ; unk0
            BL              crypto_ScePfsCryptBufVC_219BB70
            */

            /*
            ADD             R0, SP, #0x1E8+dst
            BL              proc_memset_96_219B5C4
            MOV             R0, R9
            */

            return loc_219CB8C();
         }
      }

      /*
      MOV             R0, R9  ; unk0
      ADDS            R6, #1
      BL              crypto_ScePfsCryptBufVC_219BB70
      ADD.W           R5, R5, #0x18
      ADD.W           R9, R9, #0x58
      */

//      if(r6 == r10)
      {
         //MOV             R11, R8
         
         /*
         ADD             R0, SP, #0x1E8+dst
         BL              proc_memset_96_219B5C4
         MOV             R0, R11
         */

         return loc_219CB8C();
      }
   }
}