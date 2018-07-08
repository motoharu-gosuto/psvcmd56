#pragma once

#include "Constants.h"
#include "SceAppMgrTypes.h"

int special_mount_0x12C_23D8908(SceUID pid, const char *titleId, appmgr_mount_holder_t *appmgr_holder_other_process, appmgr_mount_holder_t *appmgr_holder_current_process, char *mountPoint);