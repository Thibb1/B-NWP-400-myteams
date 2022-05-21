/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** TODO
*/

#include "cli.h"

int main(int ac, char **av)
{
    ASSERT(ac != 3, M_USAGE);
    ASSERT(!strcmp(av[1], "-h"), M_USAGE);
    create_client(av);
    run_client();
    return 0;
}