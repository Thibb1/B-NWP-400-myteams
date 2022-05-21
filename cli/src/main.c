/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** TODO
*/

#include "cli.h"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    client_t *client = init_client();
    for (;;)
        get_input(client);
    free(client);
    return 84;
}
