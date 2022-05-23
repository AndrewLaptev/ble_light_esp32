#include "users_db.h"

auth_users_db database_1 = {
    .users_count = 0
};

// void add_user_to_db(auth_users_db *db, char *username, char *password, uint8_t permissions) {
//     for (uint8_t i = 0; i < USERNAME_LENGHT; i++) {
//         db->users[db->users_count].username[i] = username[i];
//     }

//     for (uint8_t i = 0; i < PASSWORD_LENGHT; i++) {
//         db->users[db->users_count].password[i] = password[i];
//     }

//     db->users[db->users_count].permissions = permissions;
//     db->users[db->users_count].id = db->users_count;
//     db->users_count++;
// }

void add_user_to_db(auth_users_db *db, auth_user_profile *user) {
    db->users[db->users_count] = *user;
    db->users[db->users_count].id = db->users_count;
    db->users_count++;
}

void show_db(auth_users_db *db) {
    for (uint8_t i = 0; i < db->users_count; i++) {
        ESP_LOGI(DB_TAG, "id: %d, username: %s, password: %s, permissions: %d", 
            db->users[i].id, db->users[i].username, db->users[i].password, db->users[i].permissions);
    }
}

void users_data_parser(auth_user_profile *user, char *buffer, uint8_t buffer_len) {
    char loc_buf[PASSWORD_LENGHT];
    memset(loc_buf, '\0', PASSWORD_LENGHT);
    uint8_t loc_buf_idx = 0;

    bool username_check = false;
    bool password_check = false;
    bool permissions_check = false;

    for (uint8_t i = 0; i < buffer_len; i++) {
        ESP_LOGI("TEST", "PRINT_1");
        if (buffer[i] == PARSER_DELIM_SYMB) {
            ESP_LOGI("TEST", "PRINT_2");
            if(!username_check) {
                ESP_LOGI("TEST", "PRINT_3");
                for (uint8_t idx = 0; idx < USERNAME_LENGHT; idx++) {
                    ESP_LOGI("TEST", "PRINT_4");        
                    user->username[idx] = loc_buf[idx];
                }
                username_check = true;
                loc_buf_idx = 0;
            }
        }
        loc_buf[loc_buf_idx] = buffer[i];
        loc_buf_idx++;
    }
}