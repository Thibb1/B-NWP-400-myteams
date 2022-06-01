/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** replies
*/

#include "server.h"

void create_reply(int i)
{
    CHECK(!C_CMD[1], E_SYNTAX);
    CHECK(strlen(C_CMD[1]) > 512, E_SYNTAX);
    SEND(i, M_REPLY_C, C_THREAD->uuid, add_reply(i, C_CMD[1]));
}

void list_replies(int i)
{
    reply_t *reply = C_THREAD->replies;

    while (C_CONNECTED && reply) {
        SEND(i, M_REPLY_L, C_THREAD->uuid, reply->author_uuid,
            (int)reply->created_at, reply->body);
        handle_client(i);
        reply = reply->next;
    }
}
