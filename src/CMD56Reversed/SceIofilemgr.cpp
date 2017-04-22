#include "SceIofilemgr.h"

#include "Constants.h"
#include "SceSysmemGlobalVariables.h"


typedef struct vfs_block_dev_info //size is 0x14
{
  char* vitaMount;
  char* filesystem; // Some name, I guess it is filesystem
  char* blockDevicePrimary;
  char* blockDeviceSecondary; // can be 0
  uint32_t vshMountId; //must be same as in mount_point_info
}vfs_block_dev_info;

typedef struct vfs_mount_point_info_base
{
  char* unixMount;
  uint32_t unk_4; //zero
  uint32_t devMajor;
  uint32_t devMinor;

  char* filesystem;
  uint32_t unk_14; //zero
  vfs_block_dev_info* blockDev1;
  uint32_t unk_1C; //zero
} vfs_mount_point_info_base;

//==========================

int sub_BECE80(int a0)
{
   return 0;
}

int sub_BEC808(int a0)
{
   return 0;
}

int sub_BE5814(int a0)
{
   return 0;
}

int SceIofilemgrForDriver_6b3ca9f7(int a0)
{
   return 0;
}

int SceIofilemgrForDriver_dc2d8bce(int a0)
{
   return 0;
}

int sub_BEC578(int a0, int a1)
{
   return 0;
}

int sub_BEC620(int a0)
{
   return 0;
}

int sub_BEC010(int a0)
{
   return 0;
}

void* sub_BECE0C()
{
   return 0;
}

int sub_BE62E8(int a0, int a1, int a2, int a3, int a4)
{
   return 0;
}

int proc_find_vfs_node_BE6788(int a0, int a1, int a2, int a3, int a4)
{
   return 0;
}

int sub_BE5F10(int a0, int a1, int a2, int a3, int a4)
{
   return 0;
}

int sub_BEE364(int a0)
{
   return 0;
}

int sub_BEE3C8(int a0)
{
   return 0;
}

void* proc_get_arg0_for_sceVfsGetNewNode_BEBAC0()
{
   return 0;
}

int proc_init_SceVfsMnt_BEBB84(int a0, int a1, int a2, int a3)
{
   return 0;
}

int sub_BEC56C(int a0, int a1)
{
   return 0;
}

int SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(int a0, int a1, int a2, int a3)
{
   return 0;
}

int SceIofilemgrForDriver_21d57633(int a0)
{
   return 0;
}

int sub_BE61C4(int a0)
{
   return 0;
}

int sub_BE5A38(int a0, int a1)
{
   return 0;
}

int sub_BEE2C4()
{
   return 0;
}

int sub_BEE2D4()
{
   return 0;
}

int sub_BEDEB0(int a0, int a1, int a2, int a3)
{
   return 0;
}

int SceIofilemgrForDriver_aa45010b(int a0)
{
   return 0;
}

int sub_BE59BC(int a0, int a1)
{
   return 0;
}

int sub_BEDF5C(int a0, int a1)
{
   return 0;
}

int sub_BE5B30(int a0, int a1, int a2, int a3, int a4)
{
   return 0;
}

int sub_BEBC1C()
{
   return 0;
}
    
int sub_BEC51C(int a0)
{
   return 0;
}
    
int sub_BEBC2C()
{
   return 0;
}

int sub_BF18CC(int a0, int a1)
{
   return 0;
}

int sub_BEC530(int a0)
{
   return 0;
}

int SceIofilemgrForDriver_6048f245(int a0)
{
   return 0;
}

int vfs_node_func3_BF1AF0(int a0, int a1, int a2)
{
   return 0;
}

vfs_add_data* proc_findVfsNodeByFilesystem_BEC7C0(int a0)
{
   return 0;
}

//==========================

int loc_BE6C96(int r5, int r9, int unk3, int var_D8, int var_2C)
{
   sub_BECE80(unk3);
    
   sub_BECE80(var_D8);
    
   if(r9 == 0)
   {
      if(var_2C == var_009EA004)
         return 0;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
   else
   {
      sub_BEC808(r5);
   
      if(var_2C == var_009EA004)
         return r9;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
   }
}

int loc_BE7252(int r0, int r5, int r9, int unk2, int unk3, int var_D8, int var_2C)
{
   sub_BE5814(r0);
   
   if(unk2 == 0)
      return loc_BE6C96(r5, r9, unk3, var_D8, var_2C);
    
   sub_BE5814(unk2);
   
   return loc_BE6C96(r5, r9, unk3, var_D8, var_2C);
}

int loc_BE76C8(int n0, int r7, int r5, int r9, int unk2, int unk3, int var_D8, int var_2C)
{
   SceIofilemgrForDriver_6b3ca9f7(n0[0x4C]); //lock print

   n0[0x4C][0x60] = n0[0x4C][0x60] - 1; //counter ?
   
   sub_BEC578(n0[0x4C], r7);
   
   SceIofilemgrForDriver_dc2d8bce(n0[0x4C]); //unlock print

   sub_BEC620(r7);

   sub_BEC010(r7);
   
   return loc_BE7252(n0, r5, r9, unk2, unk3, var_D8, var_2C);
}

//==========================

int loc_BE6AA2_default_case(int r5, int var_2C)
{
   sub_BEC808(r5);
   
   if(var_2C == var_009EA004)
      return 0x80010016;
   else
      return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
}

//==========================

//loc_BE6C50 - jumptable 00BE6A86 case 1
int mount_switch_case_1(int r10, int r5, int var_2C)
{
    int r3 = 0x000000FF & r10; //devMajor
    if(r3 != 0x03)
      return loc_BE6AA2_default_case(r5, var_2C);
    
    void* r0 = sub_BECE0C(); //alloc memory
    int unk3 = r0;
    
    if(r0 == 0)
    {
      sub_BEC808(r5);
   
      if(var_2C == var_009EA004)
         return 0x8001000C;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    void* r0 = sub_BECE0C(); //alloc memory
    int var_D8 = r0;
    
    if(r0 == 0)
    {
      sub_BECE80(unk3);
   
      sub_BEC808(r5);
   
      if(var_2C == var_009EA004)
         return 0x8001000C;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    char* r7 = &str1;
    int r1 = 0x01;
    unk0 = r7;
    
    int* r7 = &unk1;
    int r0 = r9;
    
    unk4 = r1;
    
    int r2 = unk0;
    int r3 = R7;
    int r1 = unk3;
    
    int r0 = sub_BE62E8(r0, r1, r2, r3, unk4);
    
    int r9 = r0;
    if(r9 < 0)
       return loc_BE6C96(r5, r9, unk3, var_D8, var_2C, r4);
    
    int r3 = unk1;
    if(r3 == 0)
        return loc_BE6C96(r5, r9, unk3, var_D8, var_2C, r4);
    
//loc_BE71B0:
    int r0 = unk0;
    int lr = r3 + 0xFFFFFFFF;
    int r12 = 0x3000;
    int r1 = lr;
    unk4 = r12;
    
    vfs_node ** r2 = &unk2;
    int r3 = unk3;
    int lr = r0 +  (lr << 3);
    ctx = r12;
    var_D4 = lr;
    int r0 = proc_find_vfs_node_BE6788(r0, r1, r2, r3, unk4);
    int r9 = r0;
    int r12 = ctx;
    
    if(r9 < 0)
    {
        int r3 = 0x80010002;
        if(r9 != r3)
            return loc_BE6C96(r5, r9, unk3, var_D8, var_2C, r4);

        unk4 = r12;
        vfs_node ** r2 = &n0;
        int r0 = unk0;
        int r1 = unk1;
        int r3 = unk3;
        int r0 = proc_find_vfs_node_BE6788(r0, r1, r2, r3, unk4);
        int r9 = r0;		
        if(r9 < 0)
            return loc_BE6C96(r5, r9, unk3, var_D8, var_2C, r4);
            
        int r3 = 0;
        unk2 = r3;
    }
    else
    {
        int r2 = &n0;
        vfs_node* r0 = unk2;
        unk4 = r2;
        int r3 = r12;
        int r1 = var_D4;
        int r2 = unk3;
        int r0 = sub_BE5F10(r0, r1, r2, r3, unk4);
        int r9 = r0;
        if(r9 < 0)
        {
           if(unk2 == 0)
               return loc_BE6C96(r5, r9, unk3, var_D8, var_2C);
    
           sub_BE5814(unk2);
   
           return loc_BE6C96(r5, r9, unk3, var_D8, var_2C);
        }
    }
    
//loc_BE71F6:    
    int r0 = n0;
    int r3 = r0[0x4C];
    char r3 = r3[0x4C];
    
    if(r3 == 3)
        return loc_BE7252(r0, r5, 0x80010010, unk2, unk3, var_D8, var_2C);
    
    if((R8 & 0x1000) == 0)
    {
        //loc_BE7446:
        int r0 = sub_BEE364(r0);
        int r9 = r0;
        if(r9 < 0)
        {
         if(r9 != 0x800F090D && r9 != 0x8001000D)
            return loc_BE7252(n0, r5, r9, unk2, unk3, var_D8, var_2C);
         else
            return loc_BE7252(n0, r5, 0x8001001E, unk2, unk3, var_D8, var_2C);
        }
            
        int r0 = n0;
        int r3 = r0[0x4C];
        int r3 = r3[0x50];
        int r3 = r3 << 0x13;
        if(r3 < 0)
        {
            int r9 = 0x8001001E;
            return loc_BE7252(r0, r5, r9, unk2, unk3, var_D8, var_2C, r4);
        }
    }
    else
    {
        int r0 = sub_BEE3C8(r0);
        int r9 = r0;
        if(r9 < 0)
            return loc_BE7252(n0, r5, r9, unk2, unk3, var_D8, var_2C);
    }
        
    //loc_BE7216:
    int r2 = unk1;
    int r3 = r7;
    int* r9 = &var_28;
    int r7 = unk3;
    int r1 = 1;
    int r0 = var_F4;
    int r2 = r2 - 1;
    unk4 = r1;
    int r2 = r9 + (r2 << 3);
    var_B4 = r7;
    int r1 = var_D8;
    int r7 = r2[-0x84];
    int r2 = r2[-0x80];
    
    //STRD.W		R7, R2,	[SP,#0x4C] //!!!!!!!!!!!!!!!!!!!!
    
    int r2 = unk0;
    
    int r0 = sub_BE62E8(r0, r1, r2, r3, unk4);
    int r9 = r0;
    if(r9 < 0)
        return loc_BE7252(n0, r5, r9, unk2, unk3, var_D8, var_2C);
        
    int r3 = unk1;
    if(r3 == 0)
        return loc_BE7252(n0, r5, r9, unk2, unk3, var_D8, var_2C);
        
//loc_BE74F4:        
    void* r0 = proc_get_arg0_for_sceVfsGetNewNode_BEBAC0();
    
    int r7 = r0;
    if(r0 == 0)
        return loc_BE7252(n0, r5, 0x8001000C, unk2, unk3, var_D8, var_2C);
    
    int r2 = 0x99C0D8; //SceIoVfsHeap SceUID*
    
    int r3 = r6; //vfs_add_data* ?
    int r1 = n0;
    int r2 = *r2;
    
    proc_init_SceVfsMnt_BEBB84(n0, r1, r2, r3); //!!!!!!!!!!!!!!!!
    
    int r0 = var_EC;
    
    int r2 = 0x40;
    int r1 = var_D8;
    
    r7[0x7C] = r0;
    
    int r0 = r7 + 0x80;
    strncpy(r0, r1, r2);
    
    int r1 = var_E8;
    int r3 = 0;
    
    R7[0xBF] = (char)r3;
    
    int r3 = 0x101
    
    R7[0xC4] = r1;
    
    int r1 = UBFX(R8, 0, 0x14); //!!!!!!!!!!!!!!
    
    int r2 = n0;
    
    //STRD.W		R10, R1, [R7,#0x4C]; //!!!!!!!!!!!!!!!!!!!!!
    
    void* r0 = r2[0x4C]; //mutex
    R7[0x48] = r3;
    
    SceIofilemgrForDriver_6b3ca9f7(r0); //lock print
    
    int r3 = n0;
    int r1 = r7;
    int r3 = r3[0x4C];
    int r2 = r3[0x60];
    int r0 = r3;
    int r2 = r2 + 1; //counter ???
    r3[0x60] = r2;
    
    sub_BEC56C(r0, r1);
    
    int r3 = n0;
    void* r0 = R3[0x4C]; //mutex
    SceIofilemgrForDriver_dc2d8bce(r0); //unlock print
    
    int r2 = n0;
    int r3 = r7[0x4C];
    int r2 = r2[0x4C];
    
    short r2 = r2[0x4E];
    
    r3 = r3 | (r2 << 16)
    
    r7[0x4C] = r3;
    
    if(r11 == 0)
    {
        r11 = r6[0x14]; //vfs_add_data* ? node_ops2* ?
    }

//loc_BE7576:    
    node_ops2* r1 = r11;
    vfs_node* r0 = r7;
    int r2 = 0;
    vfs_node** r3 = &vnode;
    int r0 = SceIofilemgrForDriver_sceVfsGetNewNode_d60b5c63(r0, r1, r2, r3);
    int r9 = r0;
    if(r9 < 0)
        return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C, r4);
    
    int r3 = r7[0x50];
    int r0 = r3 << 0x0E
    if(r0 < 0)
    {
       short r2 = r7[0x4E];
       int r2 = r2 & 0xF00;
       if(r2 != 0x200)
       {
         r3 = r3 & (~0x20000);
         r7[0x50] = r3;
       }
    }
    
//loc_BE75A4:    
    int r2 = n0;
    int r3 = r2[0x4C];
    int r1 = r3[0x50];
    int r1 = r1 << 0x0E;
    
    if(r1 < 0)
    {
        short r1 = r3[0x4E];
        int r1 = r1 & 0xF00;
        if(r1 == 0x200)
        {
            int r3 = r3[0xCC];
            int r0 = r7[0x50];
            int r6 = r7[0xCC];
            int r1 = r3[0x08];
            int r3 = r3[0x0C];
            int r0 = r0 | 0x20000;
            
            r6[0x08] = r1;
            r6[0x0C] = r3;
            r7[0x50] = r0;
        }
    }
    
//loc_BE75D4:    
    int r0 = r2[0x70];
    int r1 = 0x1002;
    
    //LDRD.W		R2, R3,	[SP,#0x40] //!!!!!!!!!!!!!!
    
    r3[0x4C] = r7;
    r3[0x50] = r2;
    
    r3[0x78] = r1;
    
    if(r0 != 0)
    {
        int r0 = sub_BE61C4(r0);
        int r9 = r0;
        if(r9 < 0)
        {
            SceIofilemgrForDriver_21d57633(vnode);
            return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
        }
            
        int r3 = n0;
        int r1 = 1;
        int r0 = r3[0x70];
        sub_BE5A38(r0, r1);
    }
    
//loc_BE75FA:    
    sub_BEE2C4() //lock SceVfsRfsLock
    
    int r3 = n0;
    int r0 = r3[0x70];
    if(r0 != 0)
    {
        int r0 = sub_BE61C4(r0);
        int r9 = r0;
        if(r9 < 0)
        {
            sub_BEE2D4(); //unlock SceVfsRfsLock
    
            SceIofilemgrForDriver_21d57633(vnode);
            return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
        }
    }
    
//loc_BE760E:
    int r1 = unk1;
    int r3 = 0xD8;
    int r2 = vnode;
    int r0 = unk0;
    
    int r0 = sub_BEDEB0(r0, r1, r2, r3);
    int r9 = r0;
    
    sub_BEE2D4(); //unlock SceVfsRfsLock
    
    if(r9 < 0)
    {
        SceIofilemgrForDriver_21d57633(vnode);
        return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
    }
    
    vfs_node* r0 = vnode;
    SceIofilemgrForDriver_aa45010b(r0);
    
    int r0 = unk2;
    if(r0 == 0)
    {
        //loc_BE79F4:
        int r1 = var_D4;
        int r0 = vnode;
        int r0 = sub_BE59BC(r0, r1);
        int r9 = r0;
        if(r9 < 0)
        {
          sub_BEE2C4(); //lock SceVfsRfsLock
    
          sub_BEDF5C(unk0, unk1);

          sub_BEE2D4(); //unlock SceVfsRfsLock
    
          SceIofilemgrForDriver_21d57633(vnode);
          return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
        }
    }
    else
    {
        int r3 = 1;
        int r2 = var_D4;
        unk4 = r3;
        int r1 = vnode;
        int r0 = sub_BE5B30(r0, r1, r2, r3, unk4);
        int r9 = r0;
        if(r9 < 0)
        {
             sub_BEE2C4(); //lock SceVfsRfsLock
    
             sub_BEDF5C(unk0, unk1);

             sub_BEE2D4(); //unlock SceVfsRfsLock
    
             SceIofilemgrForDriver_21d57633(vnode);
             return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
        }
    }
    
//loc_BE7646:    
    sub_BEBC1C(); //lock SceVfsMntlistLock
    
    int r0 = r7;
    
    sub_BEC51C(r0);
    
    sub_BEBC2C(); //unlock SceVfsMntlistLock
    
    int r0 = r7;
    int* r1 = &node;
    
    int r0 = sub_BF18CC(r0, r1);
    int r9 = r0;
    if(r9 != 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(r7);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode[0x70], 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
    }
    
    int r1 = r0;
    vfs_node* r2 = vnode;
    vfs_node* r0 = r7;
    int r0 = vfs_node_func3_BF1AF0(r0, r1, r2);
    int r9 = r0;
    if(r9 < 0)
    {
       sub_BEBC1C(); //lock SceVfsMntlistLock
    
       sub_BEC530(r7);
    
       sub_BEBC2C(); //unlock SceVfsMntlistLock
     
       sub_BE5A38(vnode[0x70], 0);
    
       sub_BEE2C4(); //lock SceVfsRfsLock
    
       sub_BEDF5C(unk0, unk1);

       sub_BEE2D4(); //unlock SceVfsRfsLock
    
       SceIofilemgrForDriver_21d57633(vnode);
       return loc_BE76C8(n0, r7, r5, r9, unk2, unk3, var_D8, var_2C);
    }
    
    void* r0 = r7;
    SceIofilemgrForDriver_6b3ca9f7(); //print lock
    
    int r2 = r7[0x48];
    void* r0 = r7;
    int r3 = r7[0x60];
    int r2 = r2 & (~0x100);
    int r3 = r3 - 1;
    r7[0x48] = r2;
    r7[0x60] = r3;
    
    SceIofilemgrForDriver_dc2d8bce(r0); //print unlock
    
    int r3 = vnode;
    int r2 = r3[0x58];
    int r0 = r3;
    int r2 = r2 -1; //counter ?
    r3[0x58] = r2;
    
    SceIofilemgrForDriver_6048f245(r0);
    
    return loc_BE7252(n0, r5, r9, unk2, unk3, var_D8, var_2C);
}

//==========================

//loc_BE6A96 - jumptable 00BE6A86 case 2
int mount_switch_case_2(int r10, int r5, int var_2C, int* r4)
{
    int r3 = 0x000000FF & r10; //devMajor
    int r3 = r3 - 1;
    
    if(r3 > 0x01)
       return loc_BE6AA2_default_case(r5, var_2C, r4)

    return -1; //not implemented
}

//==========================

//loc_BE6CAA - jumptable 00BE6A86 case 3
int mount_switch_case_3(vfs_add_data* r0, int r5, int var_2C, int* r4)
{
    int r3 = r0[0x10];

    if(r3 != 0x10)
        return loc_BE6AA2_default_case(r5, var_2C, r4)
    
    return -1; //not implemented
}

//==========================

//loc_BE6D40 - jumptable 00BE6A86 case 4
int mount_switch_case_4(int r9, int r5, int var_2C, int* r4)
{
    if(r9 == 0x00)
        return loc_BE6AA2_default_case(r5, var_2C, r4)

   if(var_2C == var_009EA004)
      return 0;
   else
      return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
}

//==========================

//loc_BE6D4C - case 5
int mount_switch_case_5(int r10, int r9, int r5, int var_2C, int* r4)
{
    int r3 = 0x000000FF & r10; //devMajor
    int r3 = r3 - 1;

    if(r3 > 0x01)
        return loc_BE6AA2_default_case(r5, var_2C, r4)

    if(r9 == 0x00)
        return loc_BE6AA2_default_case(r5, var_2C, r4)
    
    return -1; //not implemented
}

//==========================

//loc_BE6AC2 - case 6
int mount_switch_case_6(int r10, int r5, int var_2C, int* r4)
{
    int r3 = 0x000000FF & r10; //devMajor
    if(r3 != 0x04)
        return loc_BE6AA2_default_case(r5, var_2C, r4)
    
    return -1; //not implemented
}

//==========================

int sceVfsMount(vfs_mount_point_info_base *mountInfo)
{
    int r0 = mountInfo;
    
    int r4 = var_009EA004
    int r3 = *r4;
    var_2C = r3;

    if(R0 == 0x00) //compare input pointer to 0
    {
      if(var_2C == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
        
    int r6 = r0[0x00]; //unixMount
    int r7 = r0[0x18]; //blockDev1
    int r8 = r0[0x0C]; //devMinor
    
    var_F4 = r6;
    int r6 = r0[0x14]; //unk_14
    int r9 = r0[0x04]; //unk_4
    int r10 = r0[0x08]; //devMajor

    int var_EC = r7;
    int r7 = var_F4;
    var_E8 = r6;
    int r5 = r0[0x10]; //filesystem
    int r11 = r0[0x1C]; //unk_1C
    
    if(r7 == 0x00) //compare unixMount pointer to 0
    {
      if(var_2C == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    int r0 = r5; //filesystem
    vfs_add_data* r0 = proc_findVfsNodeByFilesystem_BEC7C0(r0);
    int r6 = r0;
    
    if(r0 == 0x00) //compare node pointer to 0
    {
      if(var_2C == var_009EA004)
         return 0x80010016;
      else
         return STACK_CHECK_FAIL; //SceIofilemgr.SceSysclibForDriver._imp_sceKernelStackCheckFail_b997493d
    }
    
    int r3 = 0x000000FF & r8; //UXTB devMinor
    int r3 = r3 - 1;
    
    switch(r3)
    {
    case 0:
        return mount_switch_case_1();
    case 1:
        return mount_switch_case_2();
    case 2:
        return mount_switch_case_3();
    case 3:
        return mount_switch_case_4();
    case 4:
        return mount_switch_case_5();
    case 5:
        return mount_switch_case_6();
    default:
        return loc_BE6AA2_default_case(r5, var_2C, r4); //default case
    }
}

