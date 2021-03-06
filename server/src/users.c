/*
** EPITECH PROJECT, 2022
** server
** File description:
** linked_list
*/

#include "server.h"

void build_users(char *str)
{
    char *ptr = NULL;
    char *uuid = NULL;
    char *name = NULL;

    while ((ptr = strtok_r(str, "\n", &str))) {
        if (strlen(ptr) > 0) {
            uuid = strtok_r(ptr, " ", &ptr);
            name = strtok_r(ptr, " ", &ptr);
            add_user(uuid, name);
            server_event_user_loaded(uuid, name);
        }
    }
}

void free_users(user_t *list)
{
    user_t *tmp = list;
    user_t *tmp2 = NULL;
    while (tmp) {
        tmp2 = tmp->next;
        DESTROY(tmp->uuid);
        DESTROY(tmp->name);
        free_subscriptions(tmp->subscriptions);
        free_messages(tmp->messages);
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

    while (user != NULL) {
        if (!strcmp(user->uuid, uuid))
            return user;
        user = user->next;
    }
    return NULL;
}
