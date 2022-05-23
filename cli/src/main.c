/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** TODO
*/

#include "cli.h"

void signal_handler(int sig)
{
    (void) sig;
    disconnect_client();
}

int main(int ac, char **av)
{
    ASSERT(ac != 3, M_USAGE);
    ASSERT(!strcmp(av[1], "-h"), M_USAGE);
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    create_client(av);
    run_client();
    return 0;
}