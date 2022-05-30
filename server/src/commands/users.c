/*
** EPITECH PROJECT, 2022
** server
** File description:
** users
*/

#include "server.h"

void users_server(int i)
{
    user_t *user = SERVER->users;

    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    while (C_CONNECTED && user) {
        SEND(i, M_USERS, user->uuid, user->connected, user->name);
        user = user->next;
        handle_client(i);
    }
}

void user_server(int i)
{
    user_t *user;

    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    CHECK(!C_CMD[1], E_SYNTAX);
    user = get_user(C_CMD[1]);
    CHECK(!user, E_USER);
    SEND(i, M_USER, user->uuid, user->connected, user->name);
}
