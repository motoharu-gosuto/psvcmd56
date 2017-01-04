#pragma once

int SceCpuForDriver_lock_int_d32ace9e(int *addr);
int SceCpuForDriver_unlock_int_7bb9d5df(int *addr, int prev_state);

int SceCpuForDriver_lock_bf82deb2(int *addr);
int SceCpuForDriver_unlock_d6ed0c46(int *addr);

//number of args confirmed
//return type confirmed

//unk0 - pointer
//unk1 - 0 , 1
//flags - 0xFFFFFFFF , 0

//this looks like some sort of wait primitive
int SceCpuForDriver_cda96e81(void* unk0, int value, int flags);

//number of args confirmed
//return type confirmed - can return 1 or 0

//wrapper for many MRC/MCR instructions
//can be related to physical addresses
int SceCpuForDriver_337cbdf3(void* unk0);