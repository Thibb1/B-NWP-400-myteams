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

    typedef struct commands_s {
        char *commands_name[15];
        void (*commands_func[15])(void);
    } commands_t;

//  src/struct_init
    //  commands.c

    void init_commmands_name(commands_t *c);

    void init_commmands_func(commands_t *c);

    commands_t *init_commands();

//  src
    //  input.c

    void handle_input(commands_t *commands, char *line);

    void get_input(commands_t *commands);

    //  funcs.c

    void default_func();

    void exit_program();

#endif
