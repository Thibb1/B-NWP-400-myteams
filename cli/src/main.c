/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** TODO
*/

#include "cli.h"

int display_help(int ret)
{
    printf("USAGE: ./myteams_cli ip port\n\
        ip is the server ip address on which the server socket listens\n\
        port is the port number on which the server socket listens\n");
    return (ret);
}

int check_args(int ac, char **av)
{
    if (ac != 3)
        return (display_help(84));
    if (ac > 1 && strcmp(av[1], "-help") == 0)
        return (display_help(0));
    return (1);
}

int main(int ac, char **av)
{
    int ret = check_args(ac, av);
    if (ret != 1)
        return (ret);
    return (engine());
}