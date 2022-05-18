#ifndef _BLE_BEACON_H_
#define _BLE_BEACON_H_

#include "common.h"
#include "ibeacon_api/ibeacon_api.h"

#define BEACON_TAG "IBEACON"

esp_err_t ble_ibeacon_app_register(void);

#endif