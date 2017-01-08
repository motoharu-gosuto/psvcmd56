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

//this is a pairing end function for event flag that is created with SceThreadmgrForDriver_ksceKernelCreateEventFlag_4336baa4
//int user level there are 2 sce functions for event flags that are both wrappers for sub_BCC19C
//SceKernelThreadMgr.SceThreadmgr._exp_sceKernelDeleteEventFlag_5840162c
//SceKernelThreadMgr.SceThreadmgr._exp_sceKernelCloseEventFlag_9a68f547
//internally sub_BCC19C calls SceKernelThreadMgr.SceSysmemForDriver._imp_sceKernelDeleteUserUid_84a4af5e

//however there are no kernel level ksce functions yet defined in sdk
//SceThreadmgrForDriver_71ecb352 uses SceKernelThreadMgr.SceSysmemForDriver._imp_sceKernelDeleteUserUid_84a4af5e 
//as well and it is a pairing function for evid created with ksce function
//so I would assume that this is close or delete function for event flag

int SceThreadmgrForDriver_ksceKernelDeleteEventFlag_71ecb352(SceUID evid);

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