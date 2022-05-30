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

void build_logs(void)
{
    FOLDER("logs");
    FOLDER("logs/teams");
    FOLDER("logs/users");
    get_file("logs/users_uuids.log", &SERVER->logs.users_uuids_buffer);
    get_file("logs/teams_uuids.log", &SERVER->logs.teams_uuids_buffer);
    build_users(SERVER->logs.users_uuids_buffer);
    build_teams(SERVER->logs.teams_uuids_buffer);
}
