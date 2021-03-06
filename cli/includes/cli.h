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
    #include <signal.h>
    #include <time.h>

    #include "logging_client.h"
    #include "client.h"
    #include "macros.h"
    #include "my_regex.h"

// src/struct_init
// commands.c

void init_commmands_func(commands_t *c);
commands_t *init_commands(void);

// src
// client.c

void close_client(void);
void disconnect_client(void);
void create_client_connection(char **av);
void create_client(void);
void run_client(void);

// input.c

void get_input(void);
void help_client(void);
void handle_command(void);
void send_input(void);
void read_input(void);

// text_utils.c

void to_word_array(char *buff, char ***array);
int len_array(char *buff);
void read_stream(FILE *stream);


// metatdata.c

client_t *my_client(void);
void garbage_delete(void);

// client_command
// my_user.c

void login_client(void);

// handle_server.c
void handle_server_code(int);
void handle_more_codes(int);
void handle_server_error(int);
void parse_uuid(void);
void get_next(void);
#endif
