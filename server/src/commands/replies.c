/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** replies
*/

#include "server.h"

void create_reply(int i)
{
    team_t *team = C_TEAM;
    thread_t *thread = C_THREAD;
    char *uuid = C_UUID;
    char *body = NULL;
    CHECK(!C_CMD[1], E_SYNTAX);
    body = C_CMD[1];
    CHECK(strlen(C_CMD[1]) > 512, E_SYNTAX);
    SEND(i, M_REPLY_C, C_THREAD->uuid, add_reply(i, C_CMD[1]));
    SEND_SUBSCRIBERS(M_REPLY_B, team, team->uuid, thread->uuid, uuid, body);
}

void list_replies(int i)
{
    thread_t *thread = C_THREAD;
    reply_t *reply = thread->replies;

    SEND(i, M_REPLY_L, thread->uuid, thread->author_uuid,
        (int)thread->created_at, thread->body);
    handle_client(i);
    while (C_CONNECTED && reply) {
        SEND(i, M_REPLY_L, C_THREAD->uuid, reply->author_uuid,
            (int)reply->created_at, reply->body);
        handle_client(i);
        reply = reply->next;
    }
}
