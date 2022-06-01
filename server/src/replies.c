/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** replies
*/

#include "server.h"

int add_reply(int i, char *body)
{
    reply_t *reply = calloc(1, sizeof(reply_t));
    char path[1024];

    reply->author_uuid = strdup(C_UUID);
    reply->body = strdup(body);
    reply->created_at = time(NULL);
    reply->next = C_THREAD->replies;
    C_THREAD->replies = reply;
    server_event_reply_created(C_THREAD->uuid, C_UUID, body);
    snprintf(path, 1024, "logs/teams/%s/%s.log", C_TEAM->uuid, C_THREAD->uuid);
    APPEND(path, "%s %d %s\n", C_UUID, (int)reply->created_at, body);
    return ((int)reply->created_at);
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
            reply->body = strdup(strtok_r(ptr, " ", &ptr));
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
