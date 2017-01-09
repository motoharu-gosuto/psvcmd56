#pragma once

//I used documentation from this source to clarify lots of things about gc commands
//https://wiki.henkaku.xyz/vita/F00D_Commands

//There can be some usefull info about SceSblAuthMgr crypto here (not GC):
//https://wiki.henkaku.xyz/vita/SceKernelModulemgr#SELF_Loading

//Some minor things about SceSblGcAuthMgr can be found here:
//https://wiki.henkaku.xyz/vita/SceSblGcAuthMgr

//It turned out that Gc Auth is related to KIRK
//I have used information about original KIRK from here:
//https://github.com/uofw/upspd/wiki/KIRK

//more things about KIRK from Proxima
//http://wololo.net/talk/viewtopic.php?f=6&t=7224

//TODO: there should be some info about this structure in wiki
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

//it turned out that these commands are documented in xyz wiki:
//https://wiki.henkaku.xyz/vita/F00D_Commands

//in particular - these commands are for gcauthmgr_sm.self
//for constant 0x1000B - that I have in the code there are commands listed below.
//what is even more interesting - size of buffers that I have reversed (sub_CAC924_command) - matches to the documentation
//size of 0x800 buffer in _039c73b1_context also matches documentation

#define GC_AUTH_MODE_1000B 0x0001000B

//Original PSP Kirk 4 service for encrypting data
//size is 0x800
#define KIRK_SERVICE_04 0x04

//Original PSP Kirk 7 service for decrypting data
//size is 0x800
#define KIRK_SERVICE_07 0x07

//Original PSP Kirk 0xC service for Generating a 160bit ECC private/public keypair.
//size of response is 0x3C
#define KIRK_SERVICE_0C 0x0C

//Original PSP Kirk 0xD service for multiplying a 160bit ECC curve point with a value.
//size of request is 0x3C
//size of response is 0x28
#define KIRK_SERVICE_0D 0x0D

//Original PSP Kirk 0xE service for 160bit Random number generation. 
//size of response is 0x14
#define KIRK_SERVICE_0E 0x0E

//Original PSP Kirk 0x10 service for 160bit ECC signing.
//size of request is 0x34
//size of response is 0x28
#define KIRK_SERVICE_10 0x10

//Original PSP Kirk 0x11 service for 160bit ECC signature verification.
//size of request is 0x64
#define KIRK_SERVICE_11 0x11

//this is not documented in xyz wiki
//size of request is 0xB8
#define KIRK_SERVICE_12 0x12

//kirk service 0x13 does not exist?

//New Vita Kirk 0x14 service for Generating a 224bit ECC private/public keypair.
//size of response is 0x54
#define KIRK_SERVICE_14 0x14

//New Vita Kirk 0x15 service for multiplying a 224bit ECC curve point with a value.
//size of request is 0x54
//size of response is 0x38
#define KIRK_SERVICE_15 0x15

//New Vita Kirk 0x16 service for 160bit Random number generation.
//size of response is 0x1C
#define KIRK_SERVICE_16 0x16

//New Vita Kirk 0x17 service. Unknown, but buffer length is 0x3C. Almost certainly a 224bit version of 0x10 
//size of request is 0x3C
//size of response is 0x38 ?
#define KIRK_SERVICE_17 0x17

//New Vita Kirk 0x18 service. Unknown, but buffer length is 0x8C. Almost certainly a 224bit version of 0x11 
//size of request is 0x8C
#define KIRK_SERVICE_18 0x18

//New Vita Kirk 0x19 service. Unknown, but buffer length is 0xE8. Related to IdStorage somehow. Almost certainly a 224bit version of 0x12
//size of request is 0xE8
#define KIRK_SERVICE_19 0x19

//New Vita Kirk 0x1B service. Unknown, but buffer length is 0x53. 
//size of request is 0x53
#define KIRK_SERVICE_1B 0x1B

//New Vita Kirk 0x1C service. Unknown, but buffer length is 0x40. 
//size of request is 0x40
//size of response is 0x33 ?
#define KIRK_SERVICE_1C 0x1C

//New Vita Kirk 0x1D service. Unknown, but buffer length is 0xA3. Related to SceSdif somehow. 
//size of request is 0xA3
#define KIRK_SERVICE_1D 0x1D

//New Vita Kirk 0x1E service. Unknown, but buffer length is 0x51. Related to SceSdif somehow. 
//size of request is 0x51
//size of response is 0x33 ?
#define KIRK_SERVICE_1E 0x1E

//New Vita Kirk 0x1F service. Unknown, but buffer length is 0xB3. Related to SceSdif somehow. 
//size of request is 0xB3
//size of response is 0x20 ?
#define KIRK_SERVICE_1F 0x1F

//New Vita Kirk 0x20 service. Unknown, but buffer length is 0x116. Related to SceSdif somehow. 
//size of request is 0x116
//size of response is 0x34 ?
#define KIRK_SERVICE_20 0x20

//New Vita Kirk 0x21 service. Unknown, but buffer length is 0x34. 
//size of request is 0x34
//size of response is 0x28 ?
#define KIRK_SERVICE_21 0x21

//New Vita Kirk 0x22 service. Unknown, but buffer length is 0x3C. 
//size of request is 0x3C
//size of response is 0x38 ?
#define KIRK_SERVICE_22 0x22

//New Vita Kirk 0x23 service. Unknown, but buffer length is 0x20. 
//size of request is 0x20
#define KIRK_SERVICE_23 0x23

//Commands that I am particulary interested in are: 1B - 20
//I know some basic layout of requests and size of responses (assumption about size check in sub_CAC924_command)
//So it would be useful to report this to Team Molecule

//I have also found some interesting info about SMC and how SceSblSmComm functions can communicate with F00D
//From what I have found - SceSblSmComm uses SceSblSmSchedProxy module
//in particular - these SMC services
//smc_12D_1916509b
//smc_133_723b382f
//smc_138_8b84ac2a
//smc_12E_f35efc1a

//There is some info about SMC here:
//https://wiki.henkaku.xyz/vita/SceExcpmgr
//https://wiki.henkaku.xyz/vita/F00D_Processor

//And some related info about interrupts here
//https://wiki.henkaku.xyz/vita/SceKernelIntrMgr

//Turns out that there is something already known about 12D, 133
//They are related to interrupt 0xC8
//Which stands for 'SceSblSmSchedCry2Arm0'

//assume - init
int SceSblSmCommForKernel_039c73b1(int r0, int r1, int r2, int r3, _039c73b1_context* ctx, int* unk1);

//assume - encrypt
int SceSblSmCommForKernel_db9fc204(int r0, int r1, int* r2, int* r3, int unk0);

//assume - deinit
int SceSblSmCommForKernel_0631f8ed(int unk);
