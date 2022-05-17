#ifndef _LIGHT_PROFILE_H_
#define _LIGHT_PROFILE_H_

#include "common.h"
#include "long_write_msg.h"

#define GATT_LIGHT_TAG "GATT_LIGHT_PROFILE"

#define GATTS_SERVICE_UUID_LIGHT   0x00EE
#define GATTS_CHAR_UUID_LIGHT      0xEE01
#define GATTS_DESCR_UUID_LIGHT     0x2222
#define GATTS_NUM_HANDLE_LIGHT     4

void gatts_profile_light_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

#endif