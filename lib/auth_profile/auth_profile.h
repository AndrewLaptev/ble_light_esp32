#ifndef _AUTH_PROFILE_H_
#define _AUTH_PROFILE_H_

#include "common.h"
#include "long_write_msg.h"

#define GATT_AUTH_TAG "GATT_AUTH_PROFILE"

#define GATTS_SERVICE_UUID_AUTH   0x00FF
#define GATTS_CHAR_UUID_AUTH      0xFF01
#define GATTS_DESCR_UUID_AUTH     0x3333
#define GATTS_NUM_HANDLE_AUTH     4

void gatts_profile_auth_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

#endif