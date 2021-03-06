/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <netinet/in.h>
    #include <arpa/inet.h>

    #include "cli.h"

typedef struct commands_s {
    void (*commands_func[15])(void);
} commands_t;

typedef struct client_s {
    bool connected;
    char **cli_input;
    char *cli_buffer;
    char **server_buffer;
    char *reg;
    char *uuid;
    char *name;
    int input;
    FILE *stream;
    struct sockaddr_in server;
    fd_set read_fds;
    commands_t *commands;
} client_t;

#endif /* !STRUCT_H_ */
