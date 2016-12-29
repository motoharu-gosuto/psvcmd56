#include "GlobalVariables.h"

//stack cookie
int var_009EA004;

//GC AUTH STUFF

//FULLY REVERSED

//this variable is set by sub_CA9078
//by call to SceSblGcAuthMgr_SceThreadmgrForDriver_imp_30e93c31
int _00BD84D8_THREAD_ID; //I would assume this is thread id or something like that

sd_context* _00BDCBC0_SD_CTX_ELM; //size 4
char  _00BDCBC4[0x30]; // temp buffer for storing parts of packets
char  _00BDCBF4_REQBUF[0x200]; //request buffer
int  _00BDCDF4_PACKET6_DE; // some uint16 value from packet 6 - salt ?
char  _00BDCDF8_WB20[0x200];
char  _00BDCFF8[0x20]; // temp buffer for storing parts of packets
char  _00BDD018[0x34]; // result buffer of size 0x116 (initialized after packet 20 but not sent anywhere)
char  _00BDD04C_RESPBUF1[0x200]; // first responce buffer
char  _00BDD24C_RESPBUF2[0x200]; // second response buffer
char  _00BDD44C[0x20]; // result buffer of size 0xB3 (initialized after packet 16 but not sent anywhere)
                       
//other constants

//00BDCFF7 - SceSblGcAuthMgr.SceSblGcAuthMgrDrmBBForDriver._exp_bb451e83
//00BDD017 - SceSblGcAuthMgr.SceSblGcAuthMgrDrmBBForDriver._exp_bb451e83
//0xBDD018 - SceSblGcAuthMgr.SceSblGcAuthMgrDrmBBForDriver._exp_bb70ddc0
//00BDD038 - SceSblGcAuthMgr.SceSblGcAuthMgrDrmBBForDriver._exp_22fd5d23
//00BDD44B - SceSblGcAuthMgr.SceSblGcAuthMgrDrmBBForDriver._exp_bb451e83

//FULLY REVERSED

//this should be completely removed

/*
char* dword_CA9074 = _00BDD04C_RESPBUF1 + 0x08; // 00BDD054 = (00BDD04C + 8) some variable that accesses middle of 00BDD04C cmd56 responce
char* dword_CA968C = _00BDCBF4_REQBUF + 0x31; // 00BDCC25 = some variable that accesses middle of 00BDCBF4 cmd56 request
char* dword_CA9690 = _00BDCDF8_WB20 + 0x03; // 00BDCDFB = (00BDCDF8 + 3) some variable that accesses middle of 00BDCDF8 working buffer
char* dword_CA9694 = _00BDD04C_RESPBUF1 + 0x08; // 0x00BDD054 = (00BDD04C + 8) some variable that accesses middle of 00BDD04C cmd56 responce
char* dword_CA9698 = _00BDD04C_RESPBUF1 + 0x0B; // 00BDD057 = (00BDD04C + B) some variable that accesses middle of 00BDD04C cmd56 responce
char* dword_CA969C = _00BDCBF4_REQBUF + 0x2F; // 00BDCC23 = (00BDCBF4 + 2F) some variable that accesses middle of 00BDCBF4 cmd56 request
char* dword_CA98C8 = _00BDD04C_RESPBUF1 + 0x08; // 00BDD054 = (00BDD04C + 8) some variable that accesses middle of 00BDD04C cmd56 responce
*/