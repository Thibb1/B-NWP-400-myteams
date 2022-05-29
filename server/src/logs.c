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
    ASSERT(NULL == ptr, "file users_uuids.log can't be opened");
    fseek(ptr, 0L, SEEK_END);
    length = ftell(ptr);
    *dest = calloc(length + 1, sizeof(char));
    fseek(ptr, 0L, SEEK_SET);
    fread(*dest, sizeof(char), length, ptr);
    fclose(ptr);
}

void logs_to_array(char *str, char ***array)
{
    int len = len_array(str);
    char *ptr = NULL;
    int x = 0;

    if (*array)
        free(*array);
    (*array) = calloc(len + 1, sizeof(char *));
    while ((ptr = strtok_r(str, " \n\r", &str)))
        (*array)[x++] = ptr;
    (*array)[x] = NULL;
}

char *create_uuid(void)
{
    char *uuid = calloc(37, sizeof(char));
    uuid_t uuid_t;

    ASSERT(NULL == uuid, "uuid can't be created\n");
    uuid_generate_random(uuid_t);
    uuid_unparse(uuid_t, uuid);
    return (uuid);
}

char *get_uuid(char **array, char *name)
{
    char *uuid = NULL;

    for (int pos = 1; array[pos - 1] != NULL; pos += 2)
        if (strcmp(array[pos], name) == 0) {
            LOG("uuid found : %s", array[pos]);
            return array[pos];
        }
    LOG("uuid not found, need to create new uuid");
    uuid = create_uuid();
    server_event_user_created(uuid, name);
    return uuid;
}

void build_logs(void)
{
    get_file("logs/users_uuids.log", &SERVER->logs.users_uuids_buffer);
    logs_to_array(SERVER->logs.users_uuids_buffer, &SERVER->logs.users_uuids);
}
