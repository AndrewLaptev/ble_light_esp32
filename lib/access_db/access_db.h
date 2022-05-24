#ifndef _ACCESS_DB_H_
#define _ACCESS_DB_H_

#include "common.h"

#define DB_TAG "ACCESS_DB"

#define DB_SUM_CONNECTIONS 50

typedef struct {
    int pos_connection;
    int sum_connections;
    int connections[DB_SUM_CONNECTIONS];
} connections_db;

connections_db access_db;

void init_connect_db(connections_db *db);
bool check_connection_db(connections_db *db, esp_ble_gatts_cb_param_t *param);
bool add_connection_to_db (connections_db *db, esp_ble_gatts_cb_param_t *param);
bool remove_connection_from_db (connections_db *db, esp_ble_gatts_cb_param_t *param);
void show_db(connections_db *db, int sum_rows);

#endif