/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** handle input and call functions
*/

#include "server.h"

void int_handler(int a)
{
    (void) a;
    close_server();
    garbage_delete();
    exit(0);
}

int main(int ac, char *av[])
{
    ASSERT(ac != 2, USAGE);
    ASSERT(!strcmp(av[1], "-help"), USAGE);
    parse_av(av);
    create_server();
    signal(SIGINT, int_handler);
    signal(SIGPIPE, SIG_IGN);
    run_server();
    close_server();
    garbage_delete();
    return 0;
}

bool dir_ok(char *path)
{
    DIR *dir = opendir(path);
    bool open = dir;

    closedir(dir);
    return open;
}

void parse_av(char *av[])
{
    char *ptr;

    my_server()->port = strtol(av[1], &ptr, 10);
    ASSERT(av[1] == ptr || my_server()->port < 0, "port");
}
