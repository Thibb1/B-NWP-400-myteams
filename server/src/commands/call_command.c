/*
** EPITECH PROJECT, 2022
** server
** File description:
** info
*/

#include "server.h"

void list_server(int i)
{
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    STATE(C_CHANNEL != NULL, list_thread, i);
    STATE(C_TEAM != NULL, list_channel, i);
    list_team(i);
}

void create_state_server(int i)
{
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    CHECK(!C_CMD[1], E_SYNTAX);
    STATE(C_CHANNEL != NULL, create_thread, i);
    STATE(C_TEAM != NULL, create_channel, i);
    create_team(i);
}

void use_server(int i)
{
    int len = 0;
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    while(C_CMD[len++]);
    STATE(len == 7, use_thread, i);
    STATE(len == 5, use_channel, i);
    STATE(len == 3, use_team, i);
    use_nothing(i);
    SEND(i, M_OK);
}

void info_server(int i)
{
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    STATE(C_THREAD != NULL, info_thread, i);
    STATE(C_CHANNEL != NULL, info_channel, i);
    STATE(C_TEAM != NULL, info_team, i);
    users_server(i);
}
