#pragma once

struct _039c73b1_context
{
   char var968[0x130];
   int var838;
   int command; //var834
   char data[0x800]; //var830
   int packet6_de; //var30
   int size; //var2C
   int var28;
};

#define CAC924_COMMAND_0C 0x0C
#define CAC924_COMMAND_0D 0x0D
#define CAC924_COMMAND_0E 0x0E
#define CAC924_COMMAND_10 0x10
#define CAC924_COMMAND_11 0x11
#define CAC924_COMMAND_12 0x12
#define CAC924_COMMAND_14 0x14
#define CAC924_COMMAND_15 0x15
#define CAC924_COMMAND_16 0x16
#define CAC924_COMMAND_17 0x17
#define CAC924_COMMAND_18 0x18
#define CAC924_COMMAND_19 0x19
#define CAC924_COMMAND_1B 0x1B
#define CAC924_COMMAND_1C 0x1C
#define CAC924_COMMAND_1D 0x1D
#define CAC924_COMMAND_1E 0x1E
#define CAC924_COMMAND_1F 0x1F
#define CAC924_COMMAND_20 0x20
#define CAC924_COMMAND_21 0x21
#define CAC924_COMMAND_22 0x22
#define CAC924_COMMAND_23 0x23

int SceSblSsSmComm_SceSblSmCommForKernel_exp_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1);

int SceSblSsSmComm_SceSblSmCommForKernel_exp_db9fc204(int r0, int r1, int* r2, int* r3, int unk0);

int SceSblSsSmComm_SceSblSmCommForKernel_exp_0631f8ed(int unk);