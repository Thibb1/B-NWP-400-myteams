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
    #include <stdbool.h>
    #include "logging_client.h"
    #include "client.h"
    #include "macros.h"

//  src/struct_init
//  commands.c

void init_commmands_name(commands_t *c);
void init_commmands_func(commands_t *c);
commands_t *init_commands(void);

//  src
//  client.c

void disconnect_client(void);
void create_client(char **av);
void run_client(void);

//  funcs.c

void default_func(void);
void exit_program(void);

//  input.c

void get_input(void);
void handle_command(void);
void to_word_array(char *buff);
int len_array(char *buff);

//  main.c


// metatdata.c

client_t *my_client(void);
void garbage_delete(void);

#endif
