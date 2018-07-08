#pragma once

#include "SceAppMgrTypes.h"

struct sceAppMgrWorkDirMountByIdOpt
{
  int reserved0;
  int reserved1;
};

int SceAppMgr_sceAppMgrWorkDirMountById_58e4cc90(int mountId, generic_mount_ctx *data, char *mountPoint, sceAppMgrWorkDirMountByIdOpt *opt);