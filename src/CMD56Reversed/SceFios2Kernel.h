#pragma once

#include "Constants.h"

int SceFios2KernelForDriver_sceFiosKernelOverlayResolveSyncForDriver_0f456345(SceUID pid, int resolveFlag, const char *pInPath, char *pOutPath, size_t maxPath);

typedef int SceFiosOverlayID;

int SceFios2KernelForDriver_sceFiosKernelOverlayRemoveForProcessForDriver_23247efb(SceUID pid, SceFiosOverlayID id);