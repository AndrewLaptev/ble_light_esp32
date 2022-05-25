#ifndef _SERVICE_AUTH_H_
#define _SERVICE_AUTH_H_

#include "common.h"
#include "long_write_msg.h"
#include "connections_db.h"

#define GATT_AUTH_TAG "GATT_AUTH_PROFILE"

#define GATTS_SERVICE_UUID_AUTH   0x0077
#define GATTS_CHAR_UUID_AUTH      0x7701
#define GATTS_DESCR_UUID_AUTH     0x3333
#define GATTS_NUM_HANDLE_AUTH     4

#define AUTH_MSG_BUFFER_LEN       50

#define ACCESS_TOKEN_VAL          12345

int access_token;

void gatts_profile_auth_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

#endif