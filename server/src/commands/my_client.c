/*
** EPITECH PROJECT, 2022
** my_client.c
** File description:
** connect user with pass
*/

#include "server.h"

void check_user_uuid(char *pseudo)
{
    LOG("Connexion request for ");
    LOG(pseudo);
}

void login_server(int i)
{
    CHECK(!C_CMD[1], COMMAND_ERROR);
    disconnect_client(i);
    C_UUID = get_uuid(SERVER->logs.users_uuids, C_CMD[1]);
    C_CNT = true;
    C_NAME = strdup(C_CMD[1]);
    check_user_uuid(C_CMD[1]);
    dprintf(C_SOCKET, LOGIN);
    dprintf(C_SOCKET, "%s" CR, C_UUID);
    server_event_user_logged_in(C_UUID);
}

void disconnect_client(int i)
{
    C_CNT = false;
    DESTROY(C_NAME);
    DESTROY(C_UUID);
    C_UUID = NULL;
    C_NAME = NULL;
}

void logout_server(int i)
{
    if (C_CNT) {
        server_event_user_logged_out(C_UUID);
        dprintf(C_SOCKET, USER_LOGOUT);
        disconnect_client(i);
    } else {
        dprintf(C_SOCKET, LOG_IN);
    }
}
