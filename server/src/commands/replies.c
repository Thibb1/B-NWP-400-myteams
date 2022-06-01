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

void free_replies(reply_t *list)
{
    reply_t *tmp = list;
    reply_t *tmp2 = NULL;

    while (tmp) {
        tmp2 = tmp->next;
        DESTROY(tmp->author_uuid);
        DESTROY(tmp->body);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void build_replies(reply_t **replies, char *str)
{
    reply_t *reply = NULL;
    char *ptr = NULL;

    while ((ptr = strtok_r(str, "\n", &str))) {
        if (strlen(ptr) > 0) {
            reply = calloc(1, sizeof(reply_t));
            reply->author_uuid = strdup(strtok_r(ptr, " ", &ptr));
            reply->created_at = (time_t)atoi(strtok_r(ptr, " ", &ptr));
            reply->body = strdup(strtok_r(ptr, "\n", &ptr));
            reply->next = *replies;
            *replies = reply;
        }
    }
}

void load_replies(reply_t **replies, char *uuid, char *thread_uuid)
{
    char path[1024];
    char *file = NULL;

    snprintf(path, 1024, "logs/teams/%s/%s.log", uuid, thread_uuid);
    get_file(path, &file);
    build_replies(replies, file);
    DESTROY(file);
}