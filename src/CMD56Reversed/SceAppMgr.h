#pragma once

#include "Constants.h"

struct mount_point_data_entry
{
  int mount_id;
  char path[0x124];
  char mount_point[0x10];
  char title_id[0x10];
  SceUInt64 auth_ids[0x10];
  mount_point_data_entry *prev;
  mount_point_data_entry *next;
};

struct mount_ctx_t
{
  mount_point_data_entry *unk0;
  int unk4;
  char gen_mount_point[16];
  int unk18;
  int unk1C;
  mount_ctx_t *next;
};

struct mount_ctx_holder_t
{
  int unk0;
  mount_ctx_t *mount;
};

int AppMgr_decrypt_str_constant_23D59D4(char* input, char* output);

int AppMgr_decrypt_str_constant_23D5998(char *input, char *output);