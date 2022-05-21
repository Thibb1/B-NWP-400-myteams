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
    commands_t *commands = init_commands();
    for (;;)
        get_input(commands);
    free(commands);
    return 84;
}
