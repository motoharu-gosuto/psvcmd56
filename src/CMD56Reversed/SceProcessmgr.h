#pragma once

struct nothrow_t
{
};

struct mem_callback_table0
{
  int unk0;
  int unk4;
  int (*unk8)(void);
  int unkC;
  void * (*malloc)(int);
  void(*free)(void*);
};

struct mem_callback_table1
{
  int unk0;
  int unk4;
  int(*some_global_init)();
  int(*some_global_deinit)();
  void* (*mspace_malloc)(int);
  void(*mspace_free)(void*);
  int (*mspace_calloc)(int,int);
  int (*mspace_realloc)(int,int);
  int (*mspace_memalign)(int,int);
  int (*mspace_reallocalign)(int,int,int);
  int (*mspace_malloc_stats)(int);
  int (*mspace_malloc_stats_fast)(int);
  int (*mspace_malloc_usable_size)(int);
};

struct mem_callback_table2
{
  int unk0;
  int unk4;
  void*(*malloc)(int);
  void*(*malloc_with_cookie)(int);
  void*(*operator_new)(int);
  void*(*operator_new_no_throw)(int, const nothrow_t *nothrow);
  void*(*free)(void*);
  int (*operator_delete0)(void*);
  int (*operator_delete1)(void*);
  int (*operator_delete_no_throw)(void*, const nothrow_t *nothrow);
};

struct local_8708FC60_ctx_holder
{
  int unk0;
  int unk4;
  int unk8;
  int unkC;
  int unk10;
  int unk14;
  int unk18;
  int unk1C;
  mem_callback_table1 *callback_table1;
  mem_callback_table2 *callback_table2;
  int unk28;
  int unk2C;
  int unk30;
  mem_callback_table0 *callback_table0;
};

struct process_param
{
  int unk0;
  int unk4;
  int unk8;
  int unkC;
  int unk10;
  int unk14;
  int unk18;
  int unk1C;
  int unk20;
  int unk24;
  int unk28;
  local_8708FC60_ctx_holder *hldr_2C; // SceLibcparam
};

int SceProcessmgr_sceKernelCallAbortHandler_eb6e50bb(int, int);

int SceProcessmgr_sceKernelGetStdin_c1727f59();

int SceProcessmgr_sceKernelGetStdout_e5aa625c();

int SceProcessmgr_sceKernelGetStderr_fa5e3ada();

process_param* SceProcessmgr_sceKernelGetProcessParam_2be3e066();