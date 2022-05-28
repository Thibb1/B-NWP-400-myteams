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
    CHECK_ARG(C_CMD[1]);
    if (C_ACC && !strcmp(C_CMD[1], C_ACC) && C_CNT) {
        dprintf(C_SOCKET, LOGIN);
        return;
    }
    C_CNT = true;
    DESTROY(C_ACC);
    C_ACC = strdup(C_CMD[1]);
    check_user_uuid(C_CMD[1]);
    dprintf(C_SOCKET, LOGIN);
}

void logout_server(int i)
{
    if (C_CNT) {
        dprintf(C_SOCKET, USER_LOGOUT);
        C_CNT = false;
    } else {
        dprintf(C_SOCKET, LOG_IN);
    }
}
