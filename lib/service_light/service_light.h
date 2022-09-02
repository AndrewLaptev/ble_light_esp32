#ifndef _SERVICE_LIGHT_H_
#define _SERVICE_LIGHT_H_

#include "common.h"
#include "ledc_control.h"
#include "connections_db.h"
#include "string.h"

#define GATT_LIGHT_TAG "GATT_LIGHT_SERVICE"

#define GATTS_SERVICE_UUID_LIGHT   0x0088
#define GATTS_CHAR_UUID_LIGHT      0x8801
#define GATTS_DESCR_UUID_LIGHT     0x2222
#define GATTS_NUM_HANDLE_LIGHT     4

#define PARSER_BUFF_ARR_MAX_LEN    2

#define LIGHT_MSG_BUFFER_LEN       32

light_mode_t light_mode_cons;

/**
 * Handles light service events, also manages consensus
 */
void gatts_profile_light_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

#endif