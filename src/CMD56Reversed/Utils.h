#pragma once

int ATOMIC_LOAD(int* var1, int* var2, int* var1_res, int* var2_res);

int ATOMIC_STORE(int* var1, int* var2, int* var1_res, int* var2_res);

#define MRC(a0,a1,a2,a3,a4,a5)