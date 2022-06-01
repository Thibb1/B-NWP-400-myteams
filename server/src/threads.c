/*
** EPITECH PROJECT, 2022
** server
** File description:
** threads
*/

#include "server.h"

void free_threads(thread_t *list)
{
    thread_t *tmp = list;
    thread_t *tmp2 = NULL;

    while (tmp) {
        tmp2 = tmp->next;
        free_replies(tmp->replies);
        DESTROY(tmp->uuid);
        DESTROY(tmp->title);
        DESTROY(tmp->body);
        DESTROY(tmp->channel_uuid);
        DESTROY(tmp->author_uuid);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void build_threads(thread_t **threads, char *team_uuid, char *str)
{
    thread_t *thread = NULL;
    char *ptr = NULL;

    while ((ptr = strtok_r(str, "\n", &str))) {
        if (strlen(ptr) > 0) {
            thread = calloc(1, sizeof(thread_t));
            thread->uuid = strdup(strtok_r(ptr, " ", &ptr));
            thread->channel_uuid = strdup(strtok_r(ptr, " ", &ptr));
            thread->author_uuid = strdup(strtok_r(ptr, " ", &ptr));
            thread->created_at = (time_t)atoi(strtok_r(ptr, "\"", &ptr));
            thread->title = strdup(strtok_r(ptr, "\"", &ptr));
            thread->body = strdup(strtok_r(ptr, "\"", &ptr));
            load_replies(&thread->replies, team_uuid, thread->uuid);
            thread->next = *threads;
            *threads = thread;
        }
    }
}

void load_threads(thread_t **threads, char *uuid)
{
    char path[1024];
    char *file = NULL;

    snprintf(path, 1024, "logs/teams/%s/threads_uuids.log", uuid);
    get_file(path, &file);
    build_threads(threads, uuid, file);
    DESTROY(file);
}

void add_thread(int i, char *title, char *body)
{
    thread_t *thread = calloc(1, sizeof(thread_t));
    char path[1024];
    thread->uuid = create_uuid();
    thread->channel_uuid = strdup(C_CHANNEL->uuid);
    thread->author_uuid = strdup(C_UUID);
    thread->title = strdup(title);
    thread->body = strdup(body);
    thread->created_at = time(NULL);
    thread->next = C_TEAM->threads;
    C_TEAM->threads = thread;
    server_event_thread_created(C_CHANNEL->uuid, thread->uuid, C_UUID, title,
        body);
    snprintf(path, 1024, "logs/teams/%s/threads_uuids.log", C_TEAM->uuid);
    APPEND(path, "%s %s %s %d\"%s\"%s\"\n", thread->uuid, thread->channel_uuid,
        thread->author_uuid, (int)thread->created_at, thread->title,
        thread->body);
}

thread_t *get_thread(team_t *team, channel_t *channel, char *uuid)
{
    thread_t *thread = team->threads;
    while (thread) {
        if (strcmp(thread->uuid, uuid) == 0 &&
            strcmp(thread->channel_uuid, channel->uuid) == 0)
            return thread;
        thread = thread->next;
    }
    return NULL;
}
