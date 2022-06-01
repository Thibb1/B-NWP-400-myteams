/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** replies
*/

#include "server.h"

void add_reply(int i, char *body)
{
    reply_t *reply = calloc(1, sizeof(reply_t));
    char path[1024];

    reply->author_uuid = strdup(C_UUID);
    reply->body = strdup(body);
    reply->created_at = time(NULL);
    reply->next = C_THREAD->replies;
    C_THREAD->replies = reply;
    server_event_reply_created(C_TEAM->uuid, C_UUID, body);
    snprintf(path, 1024, "logs/teams/%s/%s.log", C_TEAM->uuid, C_THREAD->uuid);
    APPEND(path, "%s %d %s\n", C_UUID, (int)reply->created_at, body);
}

void create_reply(int i)
{
    CHECK(!C_CMD[1], E_SYNTAX);
    CHECK(strlen(C_CMD[1])  > 512, E_SYNTAX);
    add_reply(i, C_CMD[1]);
    SEND(i, M_REPLY_C, C_CMD[1]);
}

void list_replies(int i)
{
    reply_t *reply = C_THREAD->replies;

    while (C_CONNECTED && reply) {
        SEND(i, M_REPLY_L, reply->author_uuid, (int)reply->created_at,
            reply->body);
        handle_client(i);
        reply = reply->next;
    }
}