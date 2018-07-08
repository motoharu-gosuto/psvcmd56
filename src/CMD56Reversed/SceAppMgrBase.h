#pragma once

#include "SceAppMgrTypes.h"

global_ctx_item *__cdecl get_global_ctx_item_23C2DE0(ctx_23C2960 *ctx, SceUID pid);

int check_flags_23D4CE0(int mountId, int flag);

int check_long_titleId(const char * titleId);

int check_short_titleId(const char * titleId);

bool check_title_id_23E00B8(int mountId, const char * titleId, int& error_code);

int set_accoutNo_global_23D58B4(char* accountNo);

int read_keystone_23D6664(SceUID pid, const char *gen_mount_point, char *keystone_data);

int create_pfs_directory_23DFEAC(int mount_id, const char *physical_path, const char *keystone_data);

int get_fake_no_memory_card_23E5660();

int normalize_path_select_mode_create_dir_23D9354(const char *physical_path, int some_flag);

int check_privileges_23D5D54(unsigned int mountId);

void * alloc_mem_23DDFF8(SceSize size);

int verify_copy_23D5A10(const char *src, char *dst);

int read_sealedkey_23D6EA0(const char *mountpoint, char *secret);

int proc_parse_param_sfo_23D5028(SceUID pid, char *param_sfo_path, int ignore_overlay, phys_ctx_t *gdat_ctx);

int clearsign_exists_23D9A4C(const char *mountpoint);

int get_klicensee_23D642C(char *rif_file_path, rif_info *rif_info_arg);

int sceAppMgrCheckRifGD_base_23D9704(char *path, char *titleid, void *dest_with_klicensee);

int check_package_bin_and_clearsign_23D6314(char *physical_path, int *unk1);

int get_patch_path_23D6A48(char *path, char *titleId, int some_flag, char *prefix, char *result_path);

int proc_generate_random_path_23D4FBC(char *prefix, char *result_path);