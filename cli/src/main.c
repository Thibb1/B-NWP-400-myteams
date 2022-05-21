/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** TODO
*/

#include "cli.h"

void handle_input(commands_t *commands, char *line)
{
    for (int i = 0; i != 15; i++) {
            printf("%s %i\n", commands->commands_name[i], strcmp(line, commands->commands_name[i]));
        if (strcmp(line, commands->commands_name[i]) == 0)
            return ((commands->commands_funcs[i])());
        }
    printf("Unkown command.\n");
}

void get_input(commands_t *commands)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("> ");
    read = getline(&line, &len, stdin); 
    if (read != -1) {
        line[strlen(line) - 1] = '\0';
        handle_input(commands, line);
    }
    free(line);
}

commands_t *commands_init()
{
    commands_t *c = malloc(sizeof(struct commands_s));
    c->commands_name[0] = "help\0";
    c->commands_name[1] = "login\0";
    c->commands_name[2] = "logout\0";
    c->commands_name[3] = "users\0";
    c->commands_name[4] = "user\0";
    c->commands_name[5] = "send\0";
    c->commands_name[6] = "messages\0";
    c->commands_name[7] = "subscribe\0";
    c->commands_name[8] = "subscribed\0";
    c->commands_name[9] = "unsubscribe\0";
    c->commands_name[10] = "use\0";
    c->commands_name[11] = "create\0";
    c->commands_name[12] = "list\0";
    c->commands_name[13] = "info\0";
    c->commands_name[14] = "exit\0";

    c->commands_funcs[0] = default_func;
    c->commands_funcs[1] = default_func;
    c->commands_funcs[2] = default_func;
    c->commands_funcs[3] = default_func;
    c->commands_funcs[4] = default_func;
    c->commands_funcs[5] = default_func;
    c->commands_funcs[6] = default_func;
    c->commands_funcs[7] = default_func;
    c->commands_funcs[8] = default_func;
    c->commands_funcs[9] = default_func;
    c->commands_funcs[10] = default_func;
    c->commands_funcs[11] = default_func;
    c->commands_funcs[12] = default_func;
    c->commands_funcs[13] = default_func;
    c->commands_funcs[14] = exit_program;
    return (c);
}

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    commands_t *commands = commands_init();
    for (;;)
        get_input(commands);
    free(commands);
    return 84;
}
