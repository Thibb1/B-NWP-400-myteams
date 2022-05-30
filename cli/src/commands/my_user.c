/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** my_user
*/

#include "cli.h"

void login_client(void)
{
    CHECK(C_INPUT[1] == NULL || strlen(C_INPUT[1]) > 32, M_SYNTAX);
    CHECK(C_CONNECTED, E_CONNECTED);
    send_input();
    C_NAME = strdup(C_INPUT[1]);
    read_input();
    CHECK(!regex_match(C_BUFFER, "^211 .*"), M_SERVER);
    C_CONNECTED = true;
    C_UUID = strdup(C_REG);
}

void default_func(void)
{
    send_input();
    read_input();
}
