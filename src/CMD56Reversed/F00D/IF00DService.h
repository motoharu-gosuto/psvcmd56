#pragma once

#include <string>

//============== SELF NAMES AND SERVICE CODES =========================

#define KPRX_AUTH_SERVICE "kprx_auth_sm"
#define KPRX_AUTH_SERVICE_10001 0x10001
#define KPRX_AUTH_SERVICE_20001 0x20001
#define KPRX_AUTH_SERVICE_30001 0x30001
#define KPRX_AUTH_SERVICE_40001 0x40001
#define KPRX_AUTH_SERVICE_50001 0x50001
#define KPRX_AUTH_SERVICE_60001 0x60001
#define KPRX_AUTH_SERVICE_70001 0x70001
#define KPRX_AUTH_SERVICE_80001 0x80001

#define ACT_SERVICE "act_sm"
#define ACT_SERVICE_1 0x1
#define ACT_SERVICE_2 0x2
#define ACT_SERVICE_4 0x4
#define ACT_SERVICE_5 0x5
#define ACT_SERVICE_7 0x7
#define ACT_SERVICE_A 0xA
#define ACT_SERVICE_B 0xB
   
#define AIMGR_SERVICE "aimgr_sm"
#define AIMGR_SERVICE_1 0x1
#define AIMGR_SERVICE_2 0x2
#define AIMGR_SERVICE_3 0x3
#define AIMGR_SERVICE_4 0x4
#define AIMGR_SERVICE_5 0x5
   
#define COMPAT_SERVICE "compat_sm"
#define COMPAT_SERVICE_10006 0x10006
#define COMPAT_SERVICE_20006 0x20006 

#define ENCDEC_W_PORTABILITY_SERVICE "encdec_w_portability_sm"
#define ENCDEC_W_PORTABILITY_SERVICE_1000A 0x1000A
#define ENCDEC_W_PORTABILITY_SERVICE_2000A 0x2000A

#define GCAUTHMGR_SERVICE "gcauthmgr_sm"
#define GCAUTHMGR_SERVICE_1000B 0x1000B

#define PM_SERVICE "pm_sm"
#define PM_SERVICE_1 0x1
#define PM_SERVICE_2 0x2
#define PM_SERVICE_3 0x3
#define PM_SERVICE_4 0x4
#define PM_SERVICE_5 0x5
#define PM_SERVICE_6 0x6
#define PM_SERVICE_7 0x7
#define PM_SERVICE_8 0x8
#define PM_SERVICE_9 0x9
#define PM_SERVICE_A 0xA

#define QAF_SERVICE "qaf_sm"
#define QAF_SERVICE_1 0x1
#define QAF_SERVICE_2 0x2
#define QAF_SERVICE_C 0xC
#define QAF_SERVICE_D 0xD

#define RMAUTH_SERVICE "rmauth_sm"
#define RMAUTH_SERVICE_1 0x1
#define RMAUTH_SERVICE_2 0x2
#define RMAUTH_SERVICE_3 0x3

#define SPKG_VERIFIER_SERVICE "spkg_verifier_sm_w_key_2"
#define SPKG_VERIFIER_SERVICE_E0002 0xE0002

#define UPDATE_SERVICE "update_service_sm"
#define UPDATE_SERVICE_10002 0x10002
#define UPDATE_SERVICE_20002 0x20002
#define UPDATE_SERVICE_30002 0x30002
#define UPDATE_SERVICE_40002 0x40002
#define UPDATE_SERVICE_50002 0x50002
#define UPDATE_SERVICE_60002 0x60002
#define UPDATE_SERVICE_70002 0x70002
#define UPDATE_SERVICE_80002 0x80002
#define UPDATE_SERVICE_90002 0x90002
#define UPDATE_SERVICE_A0002 0xA0002
#define UPDATE_SERVICE_B0002 0xB0002
#define UPDATE_SERVICE_C0002 0xC0002
#define UPDATE_SERVICE_D0002 0xD0002

#define UTOKEN_SERVICE "utoken"
#define UTOKEN_SERVICE_1 0x1
#define UTOKEN_SERVICE_2 0x2

#define MGKM_SERVICE "mgkm_sm"
#define MGKM_SERVICE_1 0x1
#define MGKM_SERVICE_2 0x2

#pragma pack(push,1)

//=============== KPRX_AUTH TYPES =============

struct SceSblSmCommKprxAuthData_50001
{
   unsigned char key[0x20];
   unsigned char padding[0xE0];
   int key_size;
   int key_id;
   int slot_id;
   int unk;
};

//=============== ACT TYPES =============

struct SceSblCommActDataBase
{
   unsigned char magic[4];
   unsigned int format_version;
   unsigned int issue_number;
   unsigned int start_validity_time;
   unsigned int  end_validity_time;
   unsigned char activation_key[0x10];
   unsigned char padding[0xC];
};

struct SceSblCommActDataDec
{
   SceSblCommActDataBase data;
   unsigned char padding[0x10];
};

struct SceSblCommActDataEnc
{
   SceSblCommActDataBase data;
   unsigned char cmac[0x10];
};

struct SceSblCommActData_0x01_0x02
{
   SceSblCommActDataDec act_data_dec;
   SceSblCommActDataEnc act_data_enc;
};

typedef SceSblCommActData_0x01_0x02 SceSblCommActData_0x01;

typedef SceSblCommActData_0x01_0x02 SceSblCommActData_0x02;

//=============== AIMGR TYPES =============

//NONE

//=============== COMPAT TYPES =============

//NONE

//=============== ENCDEC_W_PORTABILITY TYPES =============

typedef struct SceSblSmCommEncdecWPortabilityData_2000A 
{
   unsigned int key_id;
   unsigned int input_length;
   unsigned char input[0x20];
   unsigned int output_length;
   unsigned char output[0x20];
   unsigned char iv[0x10];
} SceSblSmCommEncdecWPortabilityData_2000A;

#define ENCDEC_W_PORTABILITY_SERVICE_KEY_01 0x01
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_02 0x02
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_03 0x03
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_04 0x04
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_05 0x05
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_06 0x06
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_07 0x07
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_08 0x08
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_09 0x09
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_0A 0x0A
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_0B 0x0B
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_0C 0x0C
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_0D 0x0D
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_0E 0x0E
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_0F 0x0F
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_10 0x10
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_11 0x11
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_12 0x12
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_13 0x13
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_14 0x14

#define ENCDEC_W_PORTABILITY_SERVICE_KEY_MIN 0x01
#define ENCDEC_W_PORTABILITY_SERVICE_KEY_MAX 0x14

//=============== GCAUTHMGR TYPES =============

struct SceSblSmCommGcAuthMgrData_1000B
{
   //this is a structure of size 0x814

   int var838; // set to 1
   int command; //var834
   char data[0x800]; //var830
   int key_id; //var30
   int size; //var2C
   int var28; //is set to 0
};

//It turned out that Gc Auth is related to KIRK
//I have used information about original KIRK from here:
//https://github.com/uofw/upspd/wiki/KIRK

//more things about KIRK from Proxima
//http://wololo.net/talk/viewtopic.php?f=6&t=7224


//in particular - these commands are for gcauthmgr_sm.self
//for constant 0x1000B - that I have in the code there are commands listed below.
//what is even more interesting - size of buffers that I have reversed (sub_CAC924_command) - matches to the documentation
//size of 0x800 buffer in _039c73b1_context also matches documentation

//Original PSP Kirk 4 service for encrypting data
//size is 0x800
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_04 0x04

//Original PSP Kirk 7 service for decrypting data
//size is 0x800
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_07 0x07

//Original PSP Kirk 0xC service for Generating a 160bit ECC private/public keypair.
//size of response is 0x3C
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0C 0x0C

//Original PSP Kirk 0xD service for multiplying a 160bit ECC curve point with a value.
//size of request is 0x3C
//size of response is 0x28
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0D 0x0D

//Original PSP Kirk 0xE service for 160bit Random number generation. 
//size of response is 0x14
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_0E 0x0E

//Original PSP Kirk 0x10 service for 160bit ECC signing.
//size of request is 0x34
//size of response is 0x28
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_10 0x10

//Original PSP Kirk 0x11 service for 160bit ECC signature verification.
//size of request is 0x64
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_11 0x11

//this is not documented in xyz wiki
//size of request is 0xB8
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_12 0x12

//kirk service 0x13 does not exist?

//New Vita Kirk 0x14 service for Generating a 224bit ECC private/public keypair.
//size of response is 0x54
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_14 0x14

//New Vita Kirk 0x15 service for multiplying a 224bit ECC curve point with a value.
//size of request is 0x54
//size of response is 0x38
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_15 0x15

//New Vita Kirk 0x16 service for 160bit Random number generation.
//size of response is 0x1C
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_16 0x16

//New Vita Kirk 0x17 service. Unknown, but buffer length is 0x3C. Almost certainly a 224bit version of 0x10 
//size of request is 0x3C
//size of response is 0x38 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_17 0x17

//New Vita Kirk 0x18 service. Unknown, but buffer length is 0x8C. Almost certainly a 224bit version of 0x11 
//size of request is 0x8C
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_18 0x18

//New Vita Kirk 0x19 service. Unknown, but buffer length is 0xE8. Related to IdStorage somehow. Almost certainly a 224bit version of 0x12
//size of request is 0xE8
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_19 0x19

//New Vita Kirk 0x1B service. Unknown, but buffer length is 0x53. 
//size of request is 0x53
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1B 0x1B

//New Vita Kirk 0x1C service. Unknown, but buffer length is 0x40. 
//size of request is 0x40
//size of response is 0x33 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1C 0x1C

//New Vita Kirk 0x1D service. Unknown, but buffer length is 0xA3. Related to SceSdif somehow. 
//size of request is 0xA3
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1D 0x1D

//New Vita Kirk 0x1E service. Unknown, but buffer length is 0x51. Related to SceSdif somehow. 
//size of request is 0x51
//size of response is 0x33 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1E 0x1E

//New Vita Kirk 0x1F service. Unknown, but buffer length is 0xB3. Related to SceSdif somehow. 
//size of request is 0xB3
//size of response is 0x20 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_1F 0x1F

//New Vita Kirk 0x20 service. Unknown, but buffer length is 0x116. Related to SceSdif somehow. 
//size of request is 0x116
//size of response is 0x34 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_20 0x20

//New Vita Kirk 0x21 service. Unknown, but buffer length is 0x34. 
//size of request is 0x34
//size of response is 0x28 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_21 0x21

//New Vita Kirk 0x22 service. Unknown, but buffer length is 0x3C. 
//size of request is 0x3C
//size of response is 0x38 ?
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_22 0x22

//New Vita Kirk 0x23 service. Unknown, but buffer length is 0x20. 
//size of request is 0x20
#define GCAUTHMGR_SERVICE_1000B_KIRK_SERVICE_23 0x23

//Commands that I am particulary interested in are: 1B - 20
//I know some basic layout of requests and size of responses (assumption about size check in sub_CAC924_command)

//=============== PM TYPES =============

//NONE

//=============== QAF TYPES =============

//NONE

//=============== RMAUTH TYPES =============

struct SceSblSmCommRmAuthData_1
{
   unsigned char data[0x20];
};

struct SceSblSmCommRmAuthData_2
{
   unsigned char seed[0x20];
};

//=============== SPKG_VERIFIER TYPES =============

//NONE

//=============== UPDATE TYPES =============

//NONE

//=============== UTOKEN TYPES =============

//NONE

//=============== MGKM TYPES =============

//NONE

//============================================

#pragma pack(pop)

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
