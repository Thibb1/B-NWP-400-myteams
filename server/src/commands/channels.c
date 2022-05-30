/*
** EPITECH PROJECT, 2022
** server
** File description:
** channels
*/

#include "server.h"

void create_channel(int i)
{
    CHECK(!C_CMD[1] || !C_CMD[2] || !C_CMD[3], E_SYNTAX);
    CHECK(strlen(C_CMD[1]) > 32 || strlen(C_CMD[3]) > 255, E_SYNTAX);
    CHECK(get_channel_name(C_TEAM, C_CMD[1]), E_EXIST);
    add_channel(C_TEAM->uuid, C_CMD[1], C_CMD[3]);
    SEND(i, M_CHANNEL_C, get_channel_name(C_TEAM, C_CMD[1])->uuid);
}

void list_channel(int i)
{
    channel_t *channel = C_TEAM->channels;

    while (C_CONNECTED && channel) {
        SEND(i, M_CHANNEL_L, channel->uuid, channel->name,
            channel->description);
        channel = channel->next;
        handle_client(i);
    }
}

void use_channel(int i)
{
    team_t *team = get_team(C_CMD[1]);
    channel_t *channel = NULL;

    CHECK(!team, E_TEAM);
    channel = get_channel(team, C_CMD[3]);
    CHECK(!channel, E_CHANNEL);
    C_TEAM = team;
    C_CHANNEL = channel;
    C_THREAD = NULL;
    SEND(i, M_OK);
}

void info_channel(int i)
{
    SEND(i, M_CHANNEL_I, C_CHANNEL->uuid, C_CHANNEL->name,
        C_CHANNEL->description);
}
