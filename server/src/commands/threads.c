/*
** EPITECH PROJECT, 2022
** server
** File description:
** threads
*/

#include "server.h"

void create_thread(int i)
{
    thread_t *thread = NULL;
    CHECK(!C_CMD[1] || !C_CMD[3], E_SYNTAX);
    CHECK(get_thread_name(C_TEAM, C_CHANNEL, C_CMD[1]), E_EXIST);
    add_thread(i, C_CMD[1], C_CMD[3]);
    thread = get_thread_name(C_TEAM, C_CHANNEL, C_CMD[1]);
    SEND(i, M_THREAD_C, thread->uuid, (int)thread->created_at);
}

void list_thread(int i)
{
    thread_t *thread = C_TEAM->threads;

    while (thread) {
        if (!strcmp(thread->channel_uuid, C_CHANNEL->uuid)) {
            SEND(i, M_THREAD_L, thread->uuid, thread->author_uuid,
                thread->title, thread->body, (int)thread->created_at);
            handle_client(i);
            CHECK(!C_CMD[0] || strcmp(C_CMD[0], "200"), E_KO);
        }
        thread = thread->next;
    }
    SEND(i, M_END);
}

void use_thread(int i)
{
    team_t *team = get_team(C_CMD[1]);
    channel_t *channel = NULL;
    thread_t *thread = NULL;

    CHECK(!team, E_TEAM);
    channel = get_channel(team, C_CMD[3]);
    CHECK(!channel, E_CHANNEL);
    thread = get_thread(team, channel, C_CMD[5]);
    CHECK(!thread, E_THREAD);
    C_TEAM = team;
    C_CHANNEL = channel;
    C_THREAD = thread;
    SEND(i, M_OK);
}
