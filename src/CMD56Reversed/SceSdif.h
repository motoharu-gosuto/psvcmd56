#pragma once

#include "SceSdifTypes.h"

#define PACKET_2_INDEX 2
#define PACKET_4_INDEX 4
#define PACKET_6_INDEX 6
#define PACKET_8_INDEX 8
#define PACKET_10_INDEX 10
#define PACKET_12_INDEX 12
#define PACKET_14_INDEX 14
#define PACKET_16_INDEX 16
#define PACKET_18_INDEX 18
#define PACKET_20_INDEX 20

sd_context_part* SceSdifForDriver_get_sd_context_part_validate_mmc_6a71987f(int sd_ctx_index);

int SceSdifForDriver_initialize_mmc_device_22c82e79(int sd_ctx_index, sd_context_part** result);

int SceSdifForDriver_gc_cmd56_request_b0996641(sd_context_part* ctx, char* buffer, int length);

int SceSdifForDriver_gc_cmd56_response_134e06c4(sd_context_part* ctx, char* buffer, int length, int index);

int SceSdifForDriver_init_0eb0ef86();

int SceSdif_module_start_935cd196();