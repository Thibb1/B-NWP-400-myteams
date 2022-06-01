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
}
