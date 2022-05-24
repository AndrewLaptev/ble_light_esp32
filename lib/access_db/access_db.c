#include "access_db.h"

connections_db access_db = {
    .pos_connection = 0,
    .sum_connections = DB_SUM_CONNECTIONS
};

void init_connect_db(connections_db *db) {
    for (int i = 0; i < db->sum_connections; i++) {
        db->connections[i] = -1;
    }
}

void update_connection_pos_db(connections_db *db) {
    for (int i = 0; i < db->sum_connections; i++) {
        if (db->connections[i] == -1) {
            db->pos_connection = i;
            break;
        }
    }
}

bool check_connection_db(connections_db *db, esp_ble_gatts_cb_param_t *param) {
    for (int i = 0; i < db->sum_connections; i++) {
        if (param->connect.conn_id == db->connections[i]) {
            return true;
        }
    }
    return false;
}

bool add_connection_to_db (connections_db *db, esp_ble_gatts_cb_param_t *param) {
    bool ans;
    if((ans = check_connection_db(db, param))) {
        return false;
    }
    db->connections[db->pos_connection] = param->connect.conn_id;
    update_connection_pos_db(db);
    return true;
}

bool remove_connection_from_db (connections_db *db, esp_ble_gatts_cb_param_t *param) {
    for (int i = 0; i < db->sum_connections; i++) {
        if (db->connections[i] == param->connect.conn_id) {
            db->connections[i] = -1;
            update_connection_pos_db(db);
            return true;
        }
    }
    return false;
}

void show_db(connections_db *db, int sum_rows) {
    if (sum_rows == -1){
        for (int i = 0; i < db->sum_connections; i++) {
            ESP_LOGI(DB_TAG, "connection: %d, position: %d, sum connections: %d", 
                db->connections[i], db->pos_connection, db->sum_connections);
        }
    } else {
        for (int i = 0; i < sum_rows; i++) {
            ESP_LOGI(DB_TAG, "connection: %d, position: %d, sum connections: %d", 
                db->connections[i], db->pos_connection, db->sum_connections);
        }
    }
}