/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** client
*/

#include "cli.h"

client_t *init_client()
{
    client_t *client = malloc(sizeof(client_t));
    client->commands = init_commands();
    return(client);
}