#pragma once

#include "SceIntrmgr.h"

extern void* var_00C72C90[4];

extern void* PADDR_SceSdif0_00C72C90;
extern void* PADDR_SceSdif1_00C72C94;
extern void* PADDR_SceSdif2_00C72C98;
extern void* PADDR_SceSdif3_00C72C9C;

extern char* aScesdif0_00C72F78;
extern char* aScesdif1_00C72F84;
extern char* aScesdif2_00C72F90;
extern char* aScesdif3_00C72F9C;

extern char* var_00C72CA0[4];

extern char** NAME_SceSdif0_00C72CA0;
extern char** NAME_SceSdif1_00C72CA4;
extern char** NAME_SceSdif2_00C72CA8;
extern char** NAME_SceSdif3_00C72CAC;

extern SceKernelRegisterInterruptOptionsExtended intr_opt2_00C72F50;
extern SceKernelRegisterInterruptOptions intr_opt_C72FA8;