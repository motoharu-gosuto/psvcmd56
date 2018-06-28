#pragma once

#include <stdint.h>

int SceSblSsMgrForDriver_4dd1b2e5(char* buffer, int size, int unk);

int SceSblSsMgrForDriver_ac57f4f0(char* buffer);

int SceSblSsMgrForDriver_sceKernelGetRandomNumberForDriver_4f9bfbe5(char* result, int size);

typedef struct portability_input_data //size is 0x24
{
  uint32_t size;
  uint8_t data_1[0x10];
  uint8_t data_2[0x10];
}portability_input_data;

typedef struct portability_output_data //size is 0x24
{
  uint32_t size;
  uint8_t key_name[0x10];
  uint8_t aes_key_14[0x10];
}portability_output_data;

int SceSblSsMgrForDriver_sceSblSsMgrDecryptWithPortabilityForDriver_934db6b5(int key_id, unsigned char *iv, portability_input_data* in, portability_output_data* out);