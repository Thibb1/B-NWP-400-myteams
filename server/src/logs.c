/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** logs
*/

#include "server.h"

void get_file(char *path, char **dest)
{
    FILE* ptr = fopen(path, "r");
    int length = 0;

    if (*dest)
        free(*dest);
    ASSERT(NULL == ptr, "file users_uuids.log can't be opened \n");
    fseek(ptr, 0L, SEEK_END);
    length = ftell(ptr);
    *dest = malloc(sizeof(char) * (length + 1));
    (*dest)[length] = '\0';
    fseek(ptr, 0, SEEK_SET);
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

char *get_uuid(char **array, char *name)
{
    for (int pos = 1; array[pos - 1] != NULL; pos += 2)
        if (strcmp(array[pos], name) == 0) {
            printf("uuid found : %s\n", array[pos]);
            return array[pos];
        }
    printf("uuid not found, need to create new uuid\n");
    return NULL;
}

void build_logs()
{
    get_file("logs/users_uuids.log", &SERVER->logs.users_uuids_buffer);
    logs_to_array(SERVER->logs.users_uuids_buffer, &SERVER->logs.users_uuids);
}