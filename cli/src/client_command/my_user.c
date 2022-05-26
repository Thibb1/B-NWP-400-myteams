/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** my_user
*/

#include "cli.h"

void login_client(void)
{
    if (C_INPUT[1] == NULL || strlen(C_INPUT[1]) > 32) {
        LOG(M_SYNTAX);
        return;
    }
    send_input();
    read_input();
    if (regex_match(C_BUFFER, "^230 .*")) {
        LOG(C_BUFFER);
        C_CONNECTED = true;
    } else {
        P_ERROR(C_BUFFER);
        C_CONNECTED = false;
    }
}

void logout_client(void)
{
    if (C_CONNECTED) {
        send_input();
        read_input();
        if (regex_match(C_BUFFER, "^231 .*")) {
            LOG(C_BUFFER);
            C_CONNECTED = false;
        } else {
            P_ERROR(C_BUFFER);
        }
    } else {
        P_ERROR(M_MUST_BE_LOGGED);
    }
}
