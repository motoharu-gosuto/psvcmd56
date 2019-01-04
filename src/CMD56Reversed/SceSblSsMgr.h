#pragma once

#include <stdint.h>

int SceSblSsMgrForDriver_sceSblSsMgrGetRandomDataCropForDriver_4dd1b2e5(char* buffer, int size, int unk);

int SceSblSsMgrForDriver_ac57f4f0(char* buffer);

int SceSblSsMgrForDriver_sceKernelGetRandomNumberForDriver_4f9bfbe5(char* result, int size);

#pragma pack(push,1)

typedef struct ScePortabilityInputData //size is 0x24
{
   uint32_t size;
   uint8_t data[0x20];
}ScePortabilityInputData;

typedef struct ScePortabilityOutputData //size is 0x24
{
   uint32_t size;
   uint8_t data[0x20];
}ScePortabilityOutputData;

#pragma pack(pop)

int SceSblSsMgrForDriver_sceSblSsMgrDecryptWithPortabilityForDriver_934db6b5(int key_id, unsigned char *iv, const ScePortabilityInputData* in, ScePortabilityOutputData* out);