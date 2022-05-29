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
    close_client();
}

int main(int ac, char **av)
{
    ASSERT(ac != 3, M_USAGE);
    ASSERT(!strcmp(av[1], "-h"), M_USAGE);
    ASSERT(!regex_match(av[2], "^[1-9][0-9]{,4}$"), M_PORT);
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    create_client(av);
    run_client();
    return 0;
}