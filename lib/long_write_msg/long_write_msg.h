#ifndef _LONG_WRITE_MSG_H_
#define _LONG_WRITE_MSG_H_

#include "common.h"

#define GATT_LONG_WRITE_TAG "GATT_LONG_WRITE"

typedef struct {
    uint8_t                 *prepare_buf;
    int                     prepare_len;
} prepare_type_env_t;

prepare_type_env_t auth_prepare_write_env;
prepare_type_env_t light_prepare_write_env;

void example_write_event_env(esp_gatt_if_t gatts_if, prepare_type_env_t *prepare_write_env, esp_ble_gatts_cb_param_t *param);
void example_exec_write_event_env(prepare_type_env_t *prepare_write_env, esp_ble_gatts_cb_param_t *param);

#endif