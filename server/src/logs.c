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

int get_first_of(char *src, char *char_to_find)
{
    for (int pos = 0; src[pos] != '\0'; pos++)
        for (int pos2 = 0; char_to_find[pos2]; pos2++)
            if (src[pos] == char_to_find[pos2])
                return pos;
    return -1;
}

void build_logs()
{
    get_file("logs/users_uuids.log", &SERVER->logs.users_uuids);
}