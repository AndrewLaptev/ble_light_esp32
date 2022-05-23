#ifndef _USERS_DB_H_
#define _USERS_DB_H_

#include "common.h"

#define DB_TAG "USERS_DB"

#define PARSER_DELIM_SYMB ';'
#define PARSER_END_SYMB   '#'

#define USERNAME_LENGHT 32
#define PASSWORD_LENGHT 64

typedef struct {
    int id;
    char username[USERNAME_LENGHT];
    char password[PASSWORD_LENGHT];
    uint8_t permissions;
} auth_user_profile;

typedef struct {
    auth_user_profile users[100];
    uint8_t users_count;
} auth_users_db;

auth_users_db database_1;

// void add_user_to_db(auth_users_db *db, char *username, char *password, uint8_t permissions);
void add_user_to_db(auth_users_db *db, auth_user_profile *user);
void show_db(auth_users_db *db);
void users_data_parser(auth_user_profile *user, char *buffer, uint8_t buffer_len);

#endif