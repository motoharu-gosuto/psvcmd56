#pragma once

//maybe this api is smth like lock / unlock mutexes / semas ?

//-------------------------------------------------------------------------------
//SceSysmem.._exp_935cd196 - clears all global context including listed globals
//SceSysmem.SceKernelSuspendForDriver._exp_set_008BF3F8_get_008BF3FC_250acd90 - sets 008BF3F8 and gets 008BF3FC
//-------------------------------------------------------------------------------

//this function is a wrapper for atomic_add
//SceSysmem.SceCpuForDriver._exp_atomic_add_1f157dc3
//atomic int is 008BF3FC

//008B8080 this global is also used

//this function also calls function ptr func(int, int, int, int) from 008B808C
//where third argument is arg_2

//this function can be set with SceSysmem.SceKernelSuspendForDriver._exp_set_008B808C_function_c00826ac

//this function also checks 008BF3F8 before deciding to call _exp_atomic_add_1f157dc3
int SceKernelSuspendForDriver_4df40893(int arg_2);

//this function is a wrapper for atomic_dec
//SceSysmem.SceCpuForDriver._exp_atomic_dec_2a71b03c
//atomic int is 008BF3FC

//this function also calls function ptr func(int, int, int, int) from 008B8084
//where first argument is arg_0

//this function can be set with SceSysmem.SceKernelSuspendForDriver._exp_set_008B8084_function_0de3cc02

//this function also checks 008BF3F8 before deciding to call _exp_atomic_dec_2a71b03c
int SceKernelSuspendForDriver_2bb92967(int arg_0);