#pragma once

struct rif_info
{
  char content_id[48];
  char version_number[4];
  char rif_lic_flags[4];
  char lic_type0[4];
  char lic_type1[4];
  char account_id[8];
  char rif_data_98[8];
  char lic_start_time[8];
  char lic_exp_time[8];
  char dec_rif_key[16];
};
