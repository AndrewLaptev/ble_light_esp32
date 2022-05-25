#include "connections_db.h"

connections_db connect_db = {
    .pos_connection = 0,
    .sum_connections = DB_MAX_CONNECTIONS
};

void init_connect_db(connections_db *db) {
    for (int i = 0; i < db->sum_connections; i++) {
        db->connections[i].id = -1;
        db->connections[i].light_mode = -1;
    }
}

void update_connection_pos_db(connections_db *db) {
    for (int i = 0; i < db->sum_connections; i++) {
        if (db->connections[i].id == -1) {
            db->pos_connection = i;
            break;
        }
    }
}

err_connect check_connection_db(connections_db *db, esp_ble_gatts_cb_param_t *param) {
    for (int i = 0; i < db->sum_connections; i++) {
        if (param->connect.conn_id == db->connections[i].id) {
            return ERR_CONNECT_EXIST;
        } else if (param->connect.conn_id >= db->sum_connections) {
            return ERR_CONNECT_OVER;
        }
    }
    return ERR_CONNECT_NOT_EXIST;
}

const char* err_connect_check(err_connect err) {
    switch (err) {
        case ERR_CONNECT_NOT_EXIST:
            return "Connection not exist!";
            break;
            
        case ERR_CONNECT_OVER:
            return "Connections database is overflow!";
            break;

    }
    return "Connection exist";
}

err_connect add_connection_to_db (connections_db *db, esp_ble_gatts_cb_param_t *param) {
    err_connect err;
    err = check_connection_db(db, param);

    if (err == ERR_CONNECT_NOT_EXIST) {
        db->connections[db->pos_connection].id = param->connect.conn_id;
        update_connection_pos_db(db);
    }
    return err;
}

err_connect remove_connection_from_db (connections_db *db, esp_ble_gatts_cb_param_t *param) {
    err_connect err;
    err = check_connection_db(db, param);

    if (err == ERR_CONNECT_EXIST) {
        for (int i = 0; i < db->sum_connections; i++) {
            if (db->connections[i].id == param->connect.conn_id) {
                db->connections[i].id = -1;
                db->connections[i].light_mode = -1;
                update_connection_pos_db(db);
            }
        }
    }
    return err;
}

void show_db(connections_db *db, int sum_rows) {
    if (sum_rows == -1){
        for (int i = 0; i < db->sum_connections; i++) {
            ESP_LOGI(DB_TAG, "connection: %d, light mode: %d, position: %d, sum connections: %d", 
                db->connections[i].id, db->connections[i].light_mode, db->pos_connection, db->sum_connections);
        }
    } else {
        for (int i = 0; i < sum_rows; i++) {
            ESP_LOGI(DB_TAG, "connection: %d, light mode: %d, position: %d, sum connections: %d", 
                db->connections[i].id, db->connections[i].light_mode, db->pos_connection, db->sum_connections);
        }
    }
}

void write_light_mode_to_db(connections_db *db, esp_ble_gatts_cb_param_t *param, int light_mode) {
    db->connections[param->connect.conn_id].light_mode = light_mode;
}