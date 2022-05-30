/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** logs
*/

#include "server.h"

void get_file(char *path, char **dest)
{
    FILE *ptr = fopen(path, "a+");
    int length = 0;

    DESTROY(*dest);
    ASSERT(NULL == ptr, "file %s can't be opened", path);
    fseek(ptr, 0, SEEK_END);
    length = ftell(ptr);
    fseek(ptr, 0, SEEK_SET);
    *dest = calloc(length + 1, sizeof(char));
    fread(*dest, sizeof(char), length, ptr);
    fclose(ptr);
}

void build_users(char *str)
{
    char *ptr = NULL;
    char *uuid = NULL;
    char *name = NULL;

    while ((ptr = strtok_r(str, "\n", &str))) {
        if (strlen(ptr) > 0) {
            LOG("%s", ptr);
            uuid = strtok_r(ptr, " ", &ptr);
            name = strtok_r(ptr, " ", &ptr);
            add_user(uuid, name);
            server_event_user_loaded(uuid, name);
        }
    }
}

char *create_uuid(void)
{
    char *uuid = calloc(37, sizeof(char));
    uuid_t uuid_t;

    ASSERT(NULL == uuid, "uuid can't be created\n");
    uuid_generate_random(uuid_t);
    uuid_unparse(uuid_t, uuid);
    return uuid;
}

char *get_uuid(char *name)
{
    char *uuid = NULL;
    user_t *user = SERVER->users;

    while (user) {
        if (!strcmp(user->name, name)) {
            user->connected = true;
            return strdup(user->uuid);
        }
        user = user->next;
    }
    uuid = create_uuid();
    add_user(uuid, name);
    server_event_user_created(uuid, name);
    APPEND("logs/users_uuids.log", "%s %s\n", uuid, name);
    return uuid;
}

void build_logs(void)
{
    get_file("logs/users_uuids.log", &SERVER->logs.users_uuids_buffer);
    build_users(SERVER->logs.users_uuids_buffer);
}
