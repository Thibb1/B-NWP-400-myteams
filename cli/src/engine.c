/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** engine
*/

#include "cli.h"

int engine()
{
    client_t *client = init_client();
    for (;;)
        get_input(client);
    free(client);
}