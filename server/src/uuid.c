/*
** EPITECH PROJECT, 2022
** server
** File description:
** uuid
*/

#include "server.h"

char *create_uuid(void)
{
    char *uuid = calloc(37, sizeof(char));
    uuid_t uuid_t;

    ASSERT(NULL == uuid, "uuid can't be created\n");
    uuid_generate_random(uuid_t);
    uuid_unparse(uuid_t, uuid);
    return uuid;
}

char *get_user_uuid(char *name)
{
    char *uuid = NULL;
    user_t *user = SERVER->users;

    while (user) {
        if (!strcmp(user->name, name)) {
            user->connected = true;
            return strdup(user->uuid);
        }
        user = user->next;
    }
    uuid = create_uuid();
    add_user(uuid, name);
    server_event_user_created(uuid, name);
    APPEND("logs/users_uuids.log", "%s %s\n", uuid, name);
    return uuid;
}

channel_t *get_channel_name(team_t *team, char *name)
{
    channel_t *channel = team->channels;
    while (channel) {
        if (strcmp(channel->name, name) == 0)
            return channel;
        channel = channel->next;
    }
    return NULL;
}

thread_t *get_thread_name(team_t *team, channel_t *channel, char *name)
{
    thread_t *thread = team->threads;
    while (thread) {
        if (strcmp(thread->title, name) == 0 &&
            strcmp(thread->channel_uuid, channel->uuid) == 0)
            return thread;
        thread = thread->next;
    }
    return NULL;
}
