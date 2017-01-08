#pragma once

#include <stdint.h>

#include "Constants.h"

//------------------------------------------------

//number of args confirmed
//return type confirmed - can return error
int SceThreadmgrForDriver_70627f3a(int unk0); // - not critical for now

//number of args confirmed
//return type confirmed - can return error
int SceThreadmgrForDriver_db395782(void* unk0); // - not critical for now

//------------------------------------------------

//number of args confirmed
//return type confirmed - can return error
int SceThreadmgrForDriver_71ecb352(SceUID evid); // - critical

//------------------------------------------------

// Event flag wait types
enum SceEventFlagWaitTypes 
{
	// Wait for all bits in the pattern to be set
	SCE_EVENT_WAITAND = 0,
	// Wait for one or more bits in the pattern to be set
	SCE_EVENT_WAITOR  = 1,
	// Clear all the bits when it matches
	SCE_EVENT_WAITCLEAR = 2,
	// Clear the wait pattern when it matches
	SCE_EVENT_WAITCLEAR_PAT = 4,

   SCE_EVENT_WAIT_5 = 5
};

int SceThreadmgrForDriver_ksceKernelWaitEventFlag_0c1d3f20(SceUID evid, unsigned int bits, unsigned int wait, unsigned int *outBits, SceUInt *timeout);

int SceThreadmgrForDriver_ksceKernelPollEventFlag_76c6555b(SceUID evid, unsigned int bits, unsigned int wait, unsigned int *outBits);

int SceThreadmgrForDriver_ksceKernelWaitSema_3c8b55a9(SceUID semaid, int signal, SceUInt *timeout);

int SceThreadmgrForDriver_ksceKernelSignalSema_d270498b(SceUID semaid, int signal);

struct SceKernelEventFlagOptParam 
{
   SceSize size;
};

SceUID  SceThreadmgrForDriver_ksceKernelCreateEventFlag_4336baa4(const char *name, int attr, int bits, SceKernelEventFlagOptParam *opt);

int SceThreadmgrForDriver_sceKernelDelayThread_4b675d05(SceUInt delay);

//TODO: this type is weid just as the code that uses it
//this needs to be fixed (however this code is not required, just good to know timing restrictions)
struct sce_time
{
   union
   {
      struct
      {
         uint32_t v0;
         uint32_t v1;
      };
      uint64_t value;
   };
};

//number of args confirmed
sce_time SceThreadmgrForDriver_sceKernelGetSystemTimeWideForDriver_f4ee4fa9();