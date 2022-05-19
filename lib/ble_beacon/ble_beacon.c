/****************************************************************************
*
* This file is for iBeacon. It supports both iBeacon sender and receiver
* which is distinguished by macros IBEACON_SENDER and IBEACON_RECEIVER,
*
* iBeacon is a trademark of Apple Inc. Before building devices which use iBeacon technology,
* visit https://developer.apple.com/ibeacon/ to obtain a license.
*
****************************************************************************/

#include "ble_beacon.h"

extern esp_ble_ibeacon_vendor_t vendor_config;

#if (IBEACON_MODE == IBEACON_RECEIVER)
static esp_ble_scan_params_t ble_scan_params = {
    .scan_type              = BLE_SCAN_TYPE_ACTIVE,
    .own_addr_type          = BLE_ADDR_TYPE_PUBLIC,
    .scan_filter_policy     = BLE_SCAN_FILTER_ALLOW_ALL,
    .scan_interval          = 0x50,
    .scan_window            = 0x30,
    .scan_duplicate         = BLE_SCAN_DUPLICATE_DISABLE
};

#elif (IBEACON_MODE == IBEACON_SENDER)
static esp_ble_adv_params_t ble_adv_params = {
    .adv_int_min        = 0x20,
    .adv_int_max        = 0x40,
    .adv_type           = ADV_TYPE_NONCONN_IND,
    .own_addr_type      = BLE_ADDR_TYPE_PUBLIC,
    .channel_map        = ADV_CHNL_ALL,
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};
#endif

esp_err_t ble_ibeacon_app_register(void) {
    esp_err_t err;
    
    /* set parameters */
    #if (IBEACON_MODE == IBEACON_RECEIVER)
        if((err = esp_ble_gap_set_scan_params(&ble_scan_params))) {
            return err;
        }
    #elif (IBEACON_MODE == IBEACON_SENDER)
        esp_ble_ibeacon_t ibeacon_adv_data;
        if ((err = esp_ble_config_ibeacon_data (&vendor_config, &ibeacon_adv_data))){
            return err;
        } else {
            esp_ble_gap_config_adv_data_raw((uint8_t*)&ibeacon_adv_data, sizeof(ibeacon_adv_data));
        }
    #endif
    return ESP_OK;
}