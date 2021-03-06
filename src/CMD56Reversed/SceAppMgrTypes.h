#pragma once

#include "SceFios2Kernel.h"
#include "SceNpDrm.h"

//size is 0x1D0 (known)
struct pfs_mount_t
{
   int mount_id;
   char path[0x124]; //path used for PFS mount (like ux0:app/<TITLEID>)
   char pfs_rnd_drive_id[0x10]; //used for PFS mount - used internally by iofilemgr to connect to vfs_nodes through vfs_node_info?
   char title_id[0x10];
   SceUInt64 auth_ids[0x10]; // array of auth ids (auth id is required for PFS mount of NPDRM apps)
   pfs_mount_t *prev; //pointer to prev item in the list or 0
   pfs_mount_t *next; //pointer to next item in the list or 0
};

//size is 0x24 (known)
struct appmgr_mount_t
{
   pfs_mount_t *this_pfs_mount;
   SceFiosOverlayID overlay_id; // overlay for redirecting <appmgr_rnd_drive_id> to <this_pfs_mount->pfs_rnd_drive_id>0: (if this_pfs_mount is not a 0x3E9 patch mount point )
                                 // or <mctx->prev_pfs_mount->pfs_rnd_drive_id>0: to <this_pfs_mount->pfs_rnd_drive_id>0: (if this_pfs_mount is a 0x3E9 patch mount point )
                                 // or <mctx->prev_pfs_mount->path> to <this_pfs_mount->path>

   char appmgr_rnd_drive_id[0x10]; //used for appmgr mount - returned when executing appmgr mount function
   pfs_mount_t* prev_pfs_mount; //other pfs mount with same mount_id and appmgr_rnd_drive_id if mount_id is 0x3EA or 0x3E8
   appmgr_mount_t* prev; //pointer to prev item in the list or 0
   appmgr_mount_t* next; //pointer to next item in the list or 0
};

struct appmgr_mount_holder_t
{
   int unk0;
   appmgr_mount_t *first_virt_mount; //start of the list for appmgr mounts
};

struct titleId_item
{
   char titleId[16];
};

//most importantly contains rif_info and keystone
//size is 0x508 (known)
struct phys_ctx_t
{
   int unk0[88];
   int flag_160;
   int unk164;
   int unk168;
   int unk16C;
   int unk170;
   char physical_mountpoint[12];
   int unk180[70];
   char prefix_298[4];
   int flag_29C;
   int unk2A0;
   int unk2A4;
   rif_info rif;
   char keystone_318[96];
   char titleId_378[16];
   char titleid_388[16];
   titleId_item addContTitleIds[8];
   titleId_item saveDataTitleIds[8];
   char unk498[112];
};

struct sub_ctx_23C2960_C
{
   char unk0[296];
   int unk128;
   int unk12C;
   int unk130;
   int unk134;
   int unk138;
   int unk13C;
   char unk140[1016];
   int unk538;
   int unk53C;
   char unk540;
   char unk541;
   char unk542;
   char unk543;
   int unk544;
   int unk548;
};

struct sub_ctx_23C2960_558_548
{
   int unk0;
   int unk4;
   int unk8;
   int unkC;
   int unk10;
   int unk14;
   int unk18;
   int unk1C;
   int unk20;
   int unk24;
   int unk28;
   int unk2C;
};

//most importantly holds appmgr_mount_holder_t
//which is a root for appmgr mountpoints
struct sub_ctx_23C2960_558
{
   char titleId[32];
   SceUID pid;
   int unk24;
   appmgr_mount_holder_t mctx_hldr_28;
   phys_ctx_t phys_ctx_30;
   sub_ctx_23C2960_558_548 unk548;
};

struct sub_ctx_23C2960_AFC_10A4
{
   int unk0;
   int unk4;
   char unk8;
   char unk9;
   char unkA;
   char unkB;
   char unkC;
   char unkD;
   char unkE;
   char unkF;
};

struct sub_ctx_23C2960_AFC
{
   char unk_0[4260];
   sub_ctx_23C2960_AFC_10A4 unk_10A4;
};

struct sub_ctx_23C2960_1BC0_14_7EC
{
   int unk0;
   int unk4;
   int unk8;
   int unkC;
   int unk10;
   int unk14;
   int unk18;
   int unk1C;
   int unk20;
   int unk24;
   int unk28;
   int unk2C;
   int unk30;
   int unk34;
   int unk38;
   int unk3C;
};

struct sub_ctx_23C2960_1BC0_14
{
   char unk0[2028];
   sub_ctx_23C2960_1BC0_14_7EC unk7EC;
};

struct sub_ctx_23C2960_1BC0
{
   __int16 unk0;
   __int16 unk2;
   int unk4;
   int unk8;
   SceUID SceAppMgrAppMutex_uid;
   SceUID current_thread_10;
   sub_ctx_23C2960_1BC0_14 unk14;
};

struct sub_ctx_23C2960_2400
{
   int unk0;
   int unk4;
   int unk8;
   char unkC[4];
};

//size is 0x2410 (known)
struct ctx_23C2960
{
   int appid;
   int unk4;
   int unk8;
   sub_ctx_23C2960_C unkC;
   sub_ctx_23C2960_558 unk_558;
   int flags_AC0;
   int unk_AC4;
   int is_this_process_AC8;
   int unk_ACC;
   int appmgr_0x10000001_event_indicator_AD0;
   int appmgr_0x10000002_event_indicator_AD4;
   int appmgr_0x10000003_event_indicator_AD8;
   int appmgr_0x20000001_event_indicator_ADC;
   int appmgr_0x20000004_event_indicator_AE0;
   int appmgr_0x10000101_0x10000102_event_indicator_AE4;
   int appmgr_0x10000004_event_indicator_AE8;
   int appmgr_0x10000006_event_indicator_AEC;
   int appmgr_0x10000005_event_indicator_AF0;
   int appmgr_0x20000010_event_indicator_AF4;
   int unk_AF8;
   sub_ctx_23C2960_AFC unk_AFC;
   int unk_1BB0;
   int unk_1BB4;
   __int64 timewide_1BB8;
   sub_ctx_23C2960_1BC0 unk_1BC0;
   sub_ctx_23C2960_2400 unk_2400;
};

typedef ctx_23C2960 global_ctx_item;

//=========================

struct generic_mount_ctx
{
  char titleId[16];
  char passCode[32];
  char mountDrive[16];
};