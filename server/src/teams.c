/*
** EPITECH PROJECT, 2022
** server
** File description:
** teams
*/

#include "server.h"

void build_teams(char *str)
{
    team_t *team = NULL;
    char *ptr = NULL;

    while ((ptr = strtok_r(str, "\n", &str))) {
        if (strlen(ptr) > 0) {
            team = calloc(1, sizeof(team_t));
            team->uuid = strdup(strtok_r(ptr, " ", &ptr));
            team->creator_uuid = strdup(strtok_r(ptr, " ", &ptr));
            team->name = strdup(strtok_r(ptr, " ", &ptr));
            team->next = SERVER->teams;
            SERVER->teams = team;
            FOLDER("logs/teams/%s", team->uuid);
            load_threads(&team->threads, team->uuid);
            load_channels(&team->channels, team->uuid);
        }
    }
}

void free_teams(team_t *list)
{
    team_t *tmp = list;
    team_t *tmp2 = NULL;

    while (tmp) {
        tmp2 = tmp->next;
        DESTROY(tmp->uuid);
        DESTROY(tmp->name);
        DESTROY(tmp->creator_uuid);
        free_threads(tmp->threads);
        free_channels(tmp->channels);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void add_team(char *uuid, char *creator_uuid, char *name)
{
    team_t *team = calloc(1, sizeof(team_t));
    team->uuid = strdup(uuid);
    team->name = strdup(name);
    team->creator_uuid = strdup(creator_uuid);
    team->threads = NULL;
    team->channels = NULL;
    team->next = SERVER->teams;
    FOLDER("logs/teams/%s", uuid);
    server_event_team_created(uuid, creator_uuid, name);
    SERVER->teams = team;
}

team_t *get_team(char *uuid)
{
    team_t *team = SERVER->teams;

    while (team) {
        if (!strcmp(team->uuid, uuid))
            return team;
        team = team->next;
    }
    return NULL;
}
