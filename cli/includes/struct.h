/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "cli.h"

    typedef struct commands_s {
        char *commands_name[15];
        void (*commands_func[15])(void);
    } commands_t;

    typedef struct client_s {
        commands_t *commands;
    } client_t;

#endif /* !STRUCT_H_ */
