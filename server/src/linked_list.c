/*
** EPITECH PROJECT, 2022
** server
** File description:
** linked_list
*/

#include "server.h"

void free_list(user_t *list)
{
    user_t *tmp = list;
    user_t *tmp2 = NULL;
    while (tmp) {
        tmp2 = tmp->next;
        DESTROY(tmp->uuid);
        DESTROY(tmp->name);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void add_user(char *uuid, char *name)
{
    user_t *user = calloc(1, sizeof(user_t));
    user->uuid = strdup(uuid);
    user->name = strdup(name);
    user->next = SERVER->users;
    user->connected = false;
    SERVER->users = user;
}

user_t *get_user(char *uuid)
{
    user_t *user = SERVER->users;

    while (user) {
        if (!strcmp(user->uuid, uuid))
            return user;
        user = user->next;
    }
    return NULL;
}
