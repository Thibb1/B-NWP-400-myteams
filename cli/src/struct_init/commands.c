/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** commands
*/

#include "cli.h"

void init_commands_name(commands_t *c)
{
    c->commands_name[0] = "/help\0";
    c->commands_name[1] = "/login\0";
    c->commands_name[2] = "/logout\0";
    c->commands_name[3] = "/users\0";
    c->commands_name[4] = "/user\0";
    c->commands_name[5] = "/send\0";
    c->commands_name[6] = "/messages\0";
    c->commands_name[7] = "/subscribe\0";
    c->commands_name[8] = "/subscribed\0";
    c->commands_name[9] = "/unsubscribe\0";
    c->commands_name[10] = "/use\0";
    c->commands_name[11] = "/create\0";
    c->commands_name[12] = "/list\0";
    c->commands_name[13] = "/info\0";
    c->commands_name[14] = "/exit\0";
}

void init_commands_func(commands_t *c)
{
    c->commands_func[0] = default_func;
    c->commands_func[1] = default_func;
    c->commands_func[2] = default_func;
    c->commands_func[3] = default_func;
    c->commands_func[4] = default_func;
    c->commands_func[5] = default_func;
    c->commands_func[6] = default_func;
    c->commands_func[7] = default_func;
    c->commands_func[8] = default_func;
    c->commands_func[9] = default_func;
    c->commands_func[10] = default_func;
    c->commands_func[11] = default_func;
    c->commands_func[12] = default_func;
    c->commands_func[13] = default_func;
    c->commands_func[14] = exit_program;
}

commands_t *init_commands(void)
{
    commands_t *c = calloc(1, sizeof(commands_t));
    init_commands_name(c);
    init_commands_func(c);
    return (c);
}
