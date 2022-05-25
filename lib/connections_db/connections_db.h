#ifndef _CONNECTIONS_DB_H_
#define _CONNECTIONS_DB_H_

#include "common.h"

#define DB_TAG                     "CONNECTIONS_DB"

#define DB_MAX_CONNECTIONS         5
#define DB_MAX_SHOW_ROWS          -1 // -1 show all DB rows

#define ERR_CONNECT_EXIST          0
#define ERR_CONNECT_NOT_EXIST      1
#define ERR_CONNECT_OVER           2

typedef uint8_t err_connect;

typedef struct {
    int id;
    int light_mode;
} connection;

typedef struct {
    int pos_connection;
    int sum_connections;
    connection connections[DB_MAX_CONNECTIONS];
} connections_db;

connections_db connect_db;

void init_connect_db(connections_db *db);
err_connect check_connection_db(connections_db *db, esp_ble_gatts_cb_param_t *param);
const char* err_connect_check(err_connect err);
err_connect add_connection_to_db (connections_db *db, esp_ble_gatts_cb_param_t *param);
err_connect remove_connection_from_db (connections_db *db, esp_ble_gatts_cb_param_t *param);
void show_db(connections_db *db, int sum_rows);

#endif