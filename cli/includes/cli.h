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

    void default_func();

    void exit_program();

    typedef struct commands_s
    {
        char *commands_name[15];
        void (*commands_funcs[15])(void);
    } commands_t;
    

#endif
