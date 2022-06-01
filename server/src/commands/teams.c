/*
** EPITECH PROJECT, 2022
** server
** File description:
** teams
*/

#include "server.h"

void create_team(int i)
{
    team_t *team = NULL;
    CHECK(!C_CMD[1] || !C_CMD[2] || !C_CMD[3], E_SYNTAX);
    CHECK(strlen(C_CMD[1]) > 32 || strlen(C_CMD[3]) > 255, E_SYNTAX);
    CHECK(get_team_name(C_CMD[1]), E_EXIST);
    add_team(C_UUID, C_CMD[1], C_CMD[3]);
    team = get_team_name(C_CMD[1]);
    SEND(i, M_TEAM_C, team->uuid);
    SEND_ALL(M_TEAM_B, team->uuid, team->name, team->description);
}

void list_team(int i)
{
    team_t *team = SERVER->teams;

    while (C_CONNECTED && team) {
        SEND(i, M_TEAM_L, team->uuid, team->name, team->description);
        team = team->next;
        handle_client(i);
    }
}

void use_team(int i)
{
    team_t *team = get_team(C_CMD[1]);

    CHECK(!team, E_TEAM);
    C_TEAM = team;
    C_CHANNEL = NULL;
    C_THREAD = NULL;
    SEND(i, M_OK);
}

void info_team(int i)
{
    SEND(i, M_TEAM_I, C_TEAM->uuid, C_TEAM->name, C_TEAM->description);
}

void use_nothing(int i)
{
    C_TEAM = NULL;
    C_CHANNEL = NULL;
    C_THREAD = NULL;
}
