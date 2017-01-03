#pragma once

struct result_c8672a3d
{
   int unk_00;
   int unk_04;
   int unk_08;
   int unk_0C;
   int unk_10;
   int unk_14;
   int unk_18;
   int unk_1C;
   int unk_20;
   int unk_24;
   int unk_28;
   int unk_2C;
   int unk_30;
   int unk_34;
   int unk_38;
   int unk_3C;
};

typedef unsigned int SceUID;
typedef unsigned int SceSize;

int SceSysmemForDriver_sceKernelAllocMemBlockForKernel_c94850c9();
int SceSysmemForDriver_sceKernelFreeMemBlockForKernel_009e1c61();
int SceSysmemForDriver_sceKernelGetMemBlockBaseForDriver_a841edda();
int SceSysmemForDriver_sceKernelGetPaddrList_e68beebd(int unk0, int unk1);
int SceSysmemForDriver_sceKernelGetPaddr_8d160e65(void* unk0, void** unk1);
result_c8672a3d* SceSysmemForKernel_c8672a3d(int unk0);
int SceSysmemForKernel_571660aa(int r0, int r1);
int SceSysmemForDriver_e655852f(int unk0);
void* SceSysmemForDriver_sceKernelMemPoolAlloc_7b4cb60a(SceUID pool, SceSize size);
void SceSysmemForDriver_sceKernelMemPoolFree_3ebce343(SceUID pool, void *ptr);