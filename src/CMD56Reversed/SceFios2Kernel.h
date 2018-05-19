#pragma once

#include <cstdint>

#include "Constants.h"

int SceFios2KernelForDriver_sceFiosKernelOverlayResolveSyncForDriver_0f456345(SceUID pid, int resolveFlag, const char *pInPath, char *pOutPath, size_t maxPath);

typedef int SceFiosOverlayID;

typedef enum SceFiosOverlayType 
{
   SCE_FIOS_OVERLAY_TYPE_OPAQUE = 0,
   SCE_FIOS_OVERLAY_TYPE_TRANSLUCENT = 1,
   SCE_FIOS_OVERLAY_TYPE_NEWER = 2,
   SCE_FIOS_OVERLAY_TYPE_WRITABLE = 3
} SceFiosOverlayType;

struct SceFiosOverlay
{
  std::uint8_t type;
  std::uint8_t order;
  std::uint16_t dst_len;
  std::uint16_t src_len;
  std::uint16_t unk2;
  SceUID pid;
  SceFiosOverlayID id;
  char dst[292];
  char src[292]; //this is the path that is used insead of dst
};

int SceFios2KernelForDriver_sceFiosKernelOverlayRemoveForProcessForDriver_23247efb(SceUID pid, SceFiosOverlayID id);

int SceFios2KernelForDriver_sceFiosKernelOverlayAddForProcessForDriver_17e65a1c(SceUID pid, SceFiosOverlay *overlay, SceFiosOverlayID *outID);