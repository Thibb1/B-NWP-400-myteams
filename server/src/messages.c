/*
** EPITECH PROJECT, 2022
** server
** File description:
** messages
*/

#include "server.h"

void send_message(char *client, char *target, char *body)
{
    message_t *message = calloc(1, sizeof(message_t));
    message_t *message_target = calloc(1, sizeof(message_t));
    message->uuid = strdup(client);
    message_target->uuid = strdup(target);
    message->target_uuid = strdup(target);
    message_target->target_uuid = strdup(client);
    message->body = strdup(body);
    message_target->body = strdup(body);
    message->created_at = time(NULL);
    message_target->created_at = message->created_at;
    add_message(&get_user(client)->messages, message);
    add_message(&get_user(target)->messages, message_target);
}

void free_messages(message_t *list)
{
    message_t *tmp = list;
    message_t *tmp2 = NULL;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        DESTROY(tmp->uuid);
        DESTROY(tmp->target_uuid);
        DESTROY(tmp->body);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void add_message(message_t **messages, message_t *message)
{
    message->next = *messages;
    *messages = message;
}
