#pragma once

#include <stdint.h>

struct f10ab792_input
{
   uint32_t size; //input
   uint32_t unk_4_var970; //output
   uint32_t unk_8_var96C; //output
};

int SceSysrootForDriver_ee934615();
int SceSysrootForDriver_eef091a7();
int SceSysrootForKernel_f10ab792(int arg0, f10ab792_input* arg1);

//======================================

//TODO: remove this function
void SceSysroot_InitializeContext();