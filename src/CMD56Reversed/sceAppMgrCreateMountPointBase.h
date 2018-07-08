#pragma once

#include "Constants.h"
#include "SceAppMgrTypes.h"

int create_mountpoint_base_23D9B50(SceUID pid, appmgr_mount_holder_t *mount_ctx_holder, unsigned int mount_id, const char *title_id, const char *physical_path, const char *mount_drive, const char *klicensee, char *mount_point_result);