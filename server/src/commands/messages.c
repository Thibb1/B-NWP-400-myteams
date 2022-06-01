/*
** EPITECH PROJECT, 2022
** server
** File description:
** messages
*/

#include "server.h"

void send_server(int i)
{
    user_t *client = get_user(C_UUID);
    user_t *target = NULL;
    char *body = NULL;

    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    CHECK(!C_CMD[1] || !C_CMD[2] || !C_CMD[3], E_SYNTAX);
    body = C_CMD[3];
    CHECK(strlen(body) > 512, E_SYNTAX);
    target = get_user(C_CMD[1]);
    CHECK(!target, E_USER);
    CHECK(!client, E_KO);
    send_message(client->uuid, target->uuid, body);
    server_event_private_message_sended(client->uuid, target->uuid, body);
    for (int y = 0; y < MAX_CLIENTS; y++)
        if (my_client(y)->socket && my_client(y)->connected &&
            !strcmp(target->uuid, my_client(y)->uuid))
            SEND(y, M_MESSAGE_B, client->uuid, body);
}

void messages_server(int i)
{
    (void) i;
}
