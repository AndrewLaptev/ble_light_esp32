#ifndef _CONNECTIONS_DB_H_
#define _CONNECTIONS_DB_H_

#include "common.h"
#include "light_control.h"

#define DB_TAG                     "CONNECTIONS_DB"

#define DB_MAX_CONNECTIONS         5
#define DB_MAX_SHOW_ROWS          -1 // -1 show all DB rows

#define ERR_CONNECT_EXIST          0
#define ERR_CONNECT_NOT_EXIST      1
#define ERR_CONNECT_OVER           2

typedef uint8_t err_connect;

typedef struct {
    int id;
    light_mode_t light_mode;
} connection_t;

typedef struct {
    int pos_connection;
    int sum_connections;
    connection_t connections[DB_MAX_CONNECTIONS];
} connections_db_t;

connections_db_t connect_db;

void init_connect_db(connections_db_t *db);
err_connect check_connection_db(connections_db_t *db, esp_ble_gatts_cb_param_t *param);
const char* err_connect_check(err_connect err);
err_connect add_connection_to_db (connections_db_t *db, esp_ble_gatts_cb_param_t *param);
err_connect remove_connection_from_db (connections_db_t *db, esp_ble_gatts_cb_param_t *param);
void write_light_mode_to_db(connections_db_t *db, esp_ble_gatts_cb_param_t *param, light_mode_t *light_mode);
void show_db(connections_db_t *db, int sum_rows);

#endif