#pragma once

#include <stdint.h>

//--------------------------------------------------

//these 2 functions are wrappers that are built upon 
//SceSysmem.SceCpuForDriver._exp_atomic_add_341b6e81

//they operate on global variable 008B80A8, incrementing or decrementing it by 0x10
//they return value after add/sub operation

//this variable is not used in any other function meaning that it is part of some bigger structure ?

int SceSysrootForDriver_atomic_add_10_to_008B80A8_ee934615();

int SceSysrootForDriver_atomic_sub_10_from_008B80A8_eef091a7();

//-------------------------------------------------

struct input_f10ab792
{
   uint32_t size; //input - must be 0x0C
   uint32_t unk_4_var970; //output
   uint32_t unk_8_var96C; //output
};

int SceSysrootForKernel_f10ab792(int arg0, input_f10ab792* arg1);

//-------------------------------------------------

//TODO: remove this function
void SceSysroot_InitializeContext();
