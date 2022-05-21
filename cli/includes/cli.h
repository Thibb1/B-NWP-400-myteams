/*
** EPITECH PROJECT, 2022
** cli.h
** File description:
** TODO
*/

#ifndef MYTEAMS_CLI_H
    #define MYTEAMS_CLI_H

    #include <errno.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "struct.h"

//  src/struct_init
//  client.c

client_t *init_client();

//  commands.c

void init_commmands_name(commands_t *c);

void init_commmands_func(commands_t *c);

commands_t *init_commands();

//  src
//  engine.c

int engine();

//  funcs.c

void default_func();

void exit_program();

//  input.c

void handle_input(client_t *client, char *line);

void get_input(client_t *client);

//  main.c

void garbage_delete();

int display_help(int ret);

int check_args(int ac, char **av);

#endif
