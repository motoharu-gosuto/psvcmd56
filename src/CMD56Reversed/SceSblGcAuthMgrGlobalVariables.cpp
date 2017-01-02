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
char  _00BDD018[0x34]; // it is very important that this buffer is of size 0x34
                       // it is initialized by sub_CAC924 transforming 0x116 bytes
                       // if 0x116 bytes would not have been transformed into 0x34 bytes
                       // data would overflow to the _00BDD04C
                       // together with the fact that condition in sub_CAC924 for command 0x20 
                       // demands that the size is 0x34 
                       // it proves that SceSblGcAuthMgr_SceSblSmCommForKernel_imp_039c73b1 procedure
                       // changes size of data and the corresponding field in the structure
char  _00BDD04C_RESPBUF1[0x200]; // first response buffer
char  _00BDD24C_RESPBUF2[0x200]; // second response buffer
char  _00BDD44C[0x20]; // result buffer of size 0x20 (not 0xB3!) (initialized after packet 16 but not sent anywhere)
                      