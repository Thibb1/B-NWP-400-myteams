/*
** EPITECH PROJECT, 2022
** server
** File description:
** teams
*/

#include "server.h"

void create_team(int i)
{
    CHECK(!C_CMD[1] || !C_CMD[3], E_SYNTAX);
    CHECK(get_team_name(C_CMD[1]), E_EXIST);
    add_team(C_UUID, C_CMD[1], C_CMD[3]);
    SEND(i, M_TEAM_C, get_team_name(C_CMD[1])->uuid);
}

void list_team(int i)
{
    team_t *team = SERVER->teams;

    while (team) {
        SEND(i, M_TEAM_L, team->uuid, team->name, team->description);
        team = team->next;
        handle_client(i);
        CHECK(!C_CMD[0] || strcmp(C_CMD[0], "200"), E_KO);
    }
    SEND(i, M_END);
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

void use_nothing(int i)
{
    C_TEAM = NULL;
    C_CHANNEL = NULL;
    C_THREAD = NULL;
}
