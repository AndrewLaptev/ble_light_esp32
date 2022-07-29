#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gatt_common_api.h"

////////////////////////MAIN OPTIONS////////////////////////
#define DEVICE_NAME                 CONFIG_DEVICE_NAME
#define ACCESS_TOKEN_VAL            CONFIG_ACCESS_TOKEN
#define DB_MAX_CONNECTIONS          CONFIG_DB_MAX_CONNECTIONS
#define LEDC_COLOR_TEMP_MIN         CONFIG_LEDC_COLOR_TEMP_MIN                  // effective 3400
#define LEDC_COLOR_TEMP_MAX         CONFIG_LEDC_COLOR_TEMP_MAX                  // effective 5900
////////////////////////////////////////////////////////////

#define MANUFACTURER_DATA_LEN       17

#define GATTS_DEMO_CHAR_VAL_LEN_MAX 0x40

#define SERVICE_NUM                 2
#define SERVICE_AUTH_APP_ID         0
#define SERVICE_LIGHT_APP_ID        1

#define GATTS_HANDLER_TAG           "GATTS_HANDLER"
#define GAP_HANDLER_TAG             "GAP_HANDLER"

#define ADV_CONFIG_FLAG             (1 << 0)
#define SCAN_RSP_CONFIG_FLAG        (1 << 1)

uint8_t char1_str[3];
esp_gatt_char_prop_t a_property;
esp_gatt_char_prop_t b_property;
esp_attr_value_t gatts_demo_char1_val;

uint8_t adv_config_done;
uint8_t adv_service_uuid128[32];
esp_ble_adv_data_t adv_data;
esp_ble_adv_data_t scan_rsp_data;

esp_ble_adv_params_t adv_params;

struct gatts_service_inst {
    esp_gatts_cb_t gatts_cb;
    uint16_t gatts_if;
    uint16_t app_id;
    uint16_t conn_id;
    uint16_t service_handle;
    esp_gatt_srvc_id_t service_id;
    uint16_t char_handle;
    esp_bt_uuid_t char_uuid;
    esp_gatt_perm_t perm;
    esp_gatt_char_prop_t property;
    uint16_t descr_handle;
    esp_bt_uuid_t descr_uuid;
};

struct gatts_service_inst gl_service_tab[SERVICE_NUM];

void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);

#endif