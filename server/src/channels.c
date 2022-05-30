/*
** EPITECH PROJECT, 2022
** server
** File description:
** channels
*/

#include "server.h"

void free_channels(channel_t *list)
{
    channel_t *tmp = list;
    channel_t *tmp2 = NULL;

    while (tmp) {
        tmp2 = tmp->next;
        DESTROY(tmp->uuid);
        DESTROY(tmp->name);
        DESTROY(tmp->description);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void build_channels(channel_t **channels, char *str)
{
    channel_t *channel = NULL;
    char *ptr = NULL;

    while ((ptr = strtok_r(str, "\n", &str))) {
        if (strlen(ptr) > 0) {
            channel = calloc(1, sizeof(channel_t));
            channel->uuid = strdup(strtok_r(ptr, " ", &ptr));
            channel->name = strdup(strtok_r(ptr, "\"", &ptr));
            channel->description = strdup(strtok_r(ptr, "\"", &ptr));
            channel->next = *channels;
            *channels = channel;
        }
    }
}

void load_channels(channel_t **channels, char *uuid)
{
    char path[1024];
    char *file = NULL;

    snprintf(path, 1024, "logs/teams/%s/channels_uuids.log", uuid);
    get_file(path, &file);
    build_channels(channels, file);
    DESTROY(file);
}

void add_channel(char *team_uuid, char *name, char *description)
{
    team_t *team = get_team(team_uuid);
    char path[1024];
    channel_t *channel = calloc(1, sizeof(channel_t));
    channel->uuid = create_uuid();
    channel->name = strdup(name);
    channel->description = strdup(description);
    channel->next = team->channels;
    team->channels = channel;
    server_event_channel_created(team_uuid, channel->uuid, name);
    snprintf(path, 1024, "logs/teams/%s/channels_uuids.log", team_uuid);
    APPEND(path, "%s %s\"%s\n", channel->uuid, name, description);
}

channel_t *get_channel(team_t *team, char *uuid)
{
    channel_t *channel = team->channels;
    while (channel) {
        if (strcmp(channel->uuid, uuid) == 0)
            return channel;
        channel = channel->next;
    }
    return NULL;
}
