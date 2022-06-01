/*
** EPITECH PROJECT, 2022
** my_client.c
** File description:
** connect user with pass
*/

#include "server.h"

void login_server(int i)
{
    CHECK(!C_CMD[1], E_SYNTAX);
    CHECK(C_CONNECTED, E_KO);
    disconnect_client(i);
    C_UUID = get_user_uuid(C_CMD[1]);
    C_CONNECTED = true;
    C_NAME = strdup(C_CMD[1]);
    SEND(i, M_LOGIN, C_UUID);
    server_event_user_logged_in(C_UUID);
}

void disconnect_client(int i)
{
    if (C_CONNECTED) {
        get_user(C_UUID)->connected = false;
        server_event_user_logged_out(C_UUID);
    }
    C_CONNECTED = false;
    DESTROY(C_NAME);
    DESTROY(C_UUID);
    C_UUID = NULL;
    C_NAME = NULL;
}

void logout_server(int i)
{
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    SEND(i, M_LOGOUT);
    disconnect_client(i);
}
