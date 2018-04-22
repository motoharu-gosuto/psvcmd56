#pragma once

#include "Constants.h"

struct SceKernelLwMutexWork
{
  int unk0;
  int unk4;
  int lockCount;
  int unkC;
  int unk10;
  int unk14;
  int unk18;
  int unk1C;
};

struct SceKernelLwMutexOptParam
{
  SceSize size;
};

struct SceKernelLwCondWork
{
  SceInt64 data[4];
};

struct SceKernelLwCondOptParam
{
  SceSize size;
};

int SceLibKernel_sceKernelUnlockLwMutex_120afc8c(SceKernelLwMutexWork *work, int unlockCount);

int SceLibKernel_sceKernelUnlockLwMutex_91fa6614(SceKernelLwMutexWork *work, int unlockCount);

int SceLibKernel_sceKernelCreateLwCond_48c7eae6(SceKernelLwCondWork *pWork, const char *pName, unsigned int attr, SceKernelLwMutexWork *pLwMutex, const SceKernelLwCondOptParam *pOptParam);

int SceLibKernel_sceKernelDeleteLwMutex_244e76d2(SceKernelLwMutexWork *work);

int SceLibKernel_sceKernelDeleteLwCond_721f6cb3(SceKernelLwCondWork *pWork);

int SceLibKernel_sceKernelCreateLwMutex_da6ec8ef(SceKernelLwMutexWork *pWork, const char *pName, unsigned int attr, int initCount, const SceKernelLwMutexOptParam *pOptParam);

int SceLibKernel_sceKernelLockLwMutex_46e7be7b(SceKernelLwMutexWork *pWork, int lockCount, unsigned int *pTimeout);

int SceLibKernel_sceKernelCallModuleExit_15e2a45d(int);

void* SceLibKernel_sceKernelGetTLSAddr_b295eb61(int key);