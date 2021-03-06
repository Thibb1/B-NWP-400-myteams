/*
** EPITECH PROJECT, 2022
** metadata.c
** File description:
** static vars used thorough the program
*/

#include "server.h"

server_t *my_server(void)
{
    static server_t *server;

    if (!server)
        server = calloc(1, sizeof(server_t));
    return server;
}

client_t **my_clients(void)
{
    static client_t **clients;

    if (!clients)
        clients = calloc(MAX_CLIENTS, sizeof(client_t *));
    return clients;
}

client_t *my_client(int idx)
{
    if (!my_clients()[idx])
        my_clients()[idx] = calloc(1, sizeof(client_t));
    return my_clients()[idx];
}

void garbage_delete(void)
{
    DESTROY(SERVER->logs.users_uuids_buffer);
    DESTROY(SERVER->logs.teams_uuids_buffer);
    free_users(SERVER->users);
    free_teams(SERVER->teams);
    DESTROY(my_server());
    for (int i = 0; i < MAX_CLIENTS; i++) {
        DESTROY(C_PATH);
        DESTROY_ARRAY(C_CMD);
        DESTROY(C_NAME);
        DESTROY(C_UUID);
        DESTROY(my_client(i));
    }
    DESTROY(my_clients());
}
