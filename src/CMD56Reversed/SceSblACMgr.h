#pragma once

#include <cstdint>

#include "SceSysroot.h"

int SceSblACMgrForDriver_sceSblACMgrGetSelfAuthInfoOrDefaultForDriver_96af69bd(SceUID pid, std::uint64_t* authid);

int SceSblACMgrForKernel_sceSblACMgrGetSelfAuthInfoOrDefaultForKernel_7c2af978(SceUID pid, std::uint64_t* authid);

int SceSblACMgrForDriver_sceSblACMgrCheckAuthIdForDriver_0b6e6cd7(SceUID pid);

int SceSblACMgrForKernel_sceSblACMgrCheckAuthIdForKernel_f5ad56e4(SceUID pid);

int SceSblACMgrForDriver_check_auth_id_4db7f512(SceUID pid);

int SceSblACMgrForDriver_check_auth_id_456da7ac(SceUID pid);

int SceSblACMgrForDriver_check_auth_id_c98d82ee(SceUID pid);

int SceSblACMgrForDriver_sceSblACMgrIsShell_8612b243(SceUID pid);

int SceSblACMgrForDriver_sceSblACMgrIsNonGameProgram_6c5ab07f(SceUID pid);

int SceSblACMgrForDriver_sceSblACMgrIsSomething_f5ae24ac(SceUID a1);

int SceSblACMgrForDriver_sceSblACMgrHasCapabilityForDriver_c2d1f2fc(SceUID pid, int bit);