#pragma once

#include <string>

#define RM_AUTH_SM_SERVICE "rmauth_sm"
#define RM_AUTH_SM_SERVICE_1 0x1
#define RM_AUTH_SM_SERVICE_2 0x2
#define RM_AUTH_SM_SERVICE_3 0x3

#define GC_AUTH_MGR_SERVICE "gcauthmgr_sm"
#define GC_AUTH_MGR_SERVICE_1000B 0x1000B

#define ENCDEC_W_PORTABILITY_SERVICE "encdec_w_portability_sm"
#define ENCDEC_W_PORTABILITY_SERVICE_1000A 0x1000A
#define ENCDEC_W_PORTABILITY_SERVICE_2000A 0x2000A

#define KPRX_AUTH_SERVICE "kprx_auth_sm"
#define KPRX_AUTH_SERVICE_50001 0x50001
#define KPRX_AUTH_SERVICE_60001 0x60001

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

//it turned out that these commands are documented in xyz wiki:
//https://wiki.henkaku.xyz/vita/F00D_Commands

//in particular - these commands are for gcauthmgr_sm.self
//for constant 0x1000B - that I have in the code there are commands listed below.
//what is even more interesting - size of buffers that I have reversed (sub_CAC924_command) - matches to the documentation
//size of 0x800 buffer in _039c73b1_context also matches documentation

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

struct SceSblSmCommGcData_1000B
{
   //this is a structure of size 0x814

   int var838; // set to 1
   int command; //var834
   char data[0x800]; //var830
   int packet6_de; //var30
   int size; //var2C
   int var28; //is set to 0
};

struct SceSblSmCommMsifData_1
{
   unsigned char data[0x20];
};

struct SceSblSmCommMsifData_2
{
   unsigned char seed[0x20];
};

struct SceSblSmCommKprxAuthData_50001
{
   unsigned char key[0x20];
   unsigned char padding[0xE0];
   int key_size;
   int key_id;
   int slot_id;
   int unk;
};

namespace f00d
{
   class IF00DService
   {
   private:
      std::string m_service_name;

   public:
      IF00DService(std::string service_name)
         : m_service_name(service_name)
      {
      }

      virtual ~IF00DService()
      {
      }

   public:
      virtual int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const = 0;
   };
}