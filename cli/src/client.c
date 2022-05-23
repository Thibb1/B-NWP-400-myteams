/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** engine
*/

#include "cli.h"

void disconnect_client(void)
{
    garbage_delete();
    exit(0);
}

void create_client(char **av)
{
    (void) av;
    my_client()->commands = init_commands();
    my_client()->running = true;
}

void run_client(void)
{
    while (my_client()->running) {
        get_input();
        handle_command();
    }
}
