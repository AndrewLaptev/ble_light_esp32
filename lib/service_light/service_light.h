#ifndef _SERVICE_LIGHT_H_
#define _SERVICE_LIGHT_H_

#include "common.h"
#include "long_write_msg.h"
#include "light_control.h"
#include "connections_db.h"

#define GATT_LIGHT_TAG "GATT_LIGHT_PROFILE"

#define GATTS_SERVICE_UUID_LIGHT   0x0088
#define GATTS_CHAR_UUID_LIGHT      0x8801
#define GATTS_DESCR_UUID_LIGHT     0x2222
#define GATTS_NUM_HANDLE_LIGHT     4

#define LIGHT_MSG_BUFFER_LEN 32

void gatts_profile_light_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

#endif