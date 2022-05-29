/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** commands
*/

#include "cli.h"

void init_commands_func(commands_t *c)
{
    c->commands_func[0] = help_client;
    c->commands_func[1] = login_client;
    c->commands_func[2] = logout_client;
    c->commands_func[3] = users_client;
    c->commands_func[4] = user_client;
    c->commands_func[5] = default_func;
    c->commands_func[6] = default_func;
    c->commands_func[7] = default_func;
    c->commands_func[8] = default_func;
    c->commands_func[9] = default_func;
    c->commands_func[10] = default_func;
    c->commands_func[11] = default_func;
    c->commands_func[12] = default_func;
    c->commands_func[13] = default_func;
    c->commands_func[14] = close_client;
}

commands_t *init_commands(void)
{
    commands_t *c = calloc(1, sizeof(commands_t));
    (void)
    init_commands_func(c);
    return (c);
}
