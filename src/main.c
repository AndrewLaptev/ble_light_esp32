#include "common.h"
#include "light_control.h"
#include "access_db.h"

#define MAIN_TAG "MAIN"

void app_main(void) {
    esp_err_t err;

    // Initialize NVS.
    err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);

    ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT));

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();

    if ((err = esp_bt_controller_init(&bt_cfg))) {
        ESP_LOGE(MAIN_TAG, "%s: initialize controller failed: %s\n", __func__, esp_err_to_name(err));
        return;
    }
    if ((err = esp_bt_controller_enable(ESP_BT_MODE_BLE))) {
        ESP_LOGE(MAIN_TAG, "%s: enable controller failed: %s\n", __func__, esp_err_to_name(err));
        return;
    }

    if ((err = esp_bluedroid_init())) {
        ESP_LOGE(MAIN_TAG, "%s: init bluetooth failed: %s\n", __func__, esp_err_to_name(err));
        return;
    }
    if ((err = esp_bluedroid_enable())) {
        ESP_LOGE(MAIN_TAG, "%s: enable bluetooth failed: %s\n", __func__, esp_err_to_name(err));
        return;
    }

    if ((err = esp_ble_gatts_register_callback(gatts_event_handler))){
        ESP_LOGE(MAIN_TAG, "%s: gatts register error: %s\n", __func__, esp_err_to_name(err));
        return;
    }
    if ((err = esp_ble_gap_register_callback(gap_event_handler))){
        ESP_LOGE(MAIN_TAG, "%s: gap register error: %s\n", __func__, esp_err_to_name(err));
        return;
    }
    if ((err = esp_ble_gatts_app_register(PROFILE_AUTH_APP_ID))){
        ESP_LOGE(MAIN_TAG, "%s: gatts app register error: %s\n", __func__, esp_err_to_name(err));
        return;
    }
    if ((err = esp_ble_gatts_app_register(PROFILE_LIGHT_APP_ID))){
        ESP_LOGE(MAIN_TAG, "%s: gatts app register error: %s\n", __func__, esp_err_to_name(err));
        return;
    }

    if ((err = esp_ble_gatt_set_local_mtu(500))){
        ESP_LOGE(MAIN_TAG, "%s: set local  MTU failed: %s\n", __func__, esp_err_to_name(err));
        return;
    }

    
    ledc_init();

    init_connect_db(&access_db);

    return;
}