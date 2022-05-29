/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

    #include <stdio.h>
    #include <stdlib.h>

    #include "cli.h"

    #define RESET "\033[0m"
    #define RED "\033[31m"
    #define GREEN "\033[32m"
    #define BLUE "\033[34m"
    #define ORANGE "\033[38;5;208m"
    #define BOLD "\033[1m"
    #define CR "\r\n"

    #define M_USAGE "USAGE: ./myteams_cli ip port\n" \
    "\tip is the server ip address on which the server socket listens\n" \
    "\tport is the port number on which the server socket listens"
    #define M_PORT "PORT must be a number between 1 and 65535"
    #define M_IP "IP must be a valid IPv4 address"
    #define M_SOCKET "socket() failed"
    #define M_MEMORY "memory allocation failed"
    #define M_CONNECT "connect() failed"
    #define M_HELP "/help [command] : display help for a command"
    #define M_SYNTAX "Syntax error, parameters or arguments are incorrect"
    #define M_MUST_BE_LOGGED "You must be logged in to do this"
    #define M_SERVER "Server error"

    #define DESTROY(v) \
if (v) { \
    free(v); \
}

    #ifdef DEBUG
        #define M_ERROR BOLD RED "[%s:%d] " RESET BOLD "%s " RESET
        #define P_ERROR(f, ...) \
    fprintf(stdout, M_ERROR, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stdout, "(" f ")" CR, ##__VA_ARGS__);
        #define M_LOG BOLD BLUE "[%s:%d] " RESET BOLD "%s " RESET
        #define LOG(f, ...) \
    fprintf(stdout, M_LOG, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stdout, "(" f ")" CR, ##__VA_ARGS__);
    #else
        #define P_ERROR(f, ...) \
    fprintf(stdout, BOLD RED f RESET CR, ##__VA_ARGS__);
        #define LOG(f, ...) \
    fprintf(stdout, BOLD BLUE f RESET CR, ##__VA_ARGS__);
    #endif

    #define ASSERT(value, ...) \
if (value) { \
    P_ERROR(__VA_ARGS__); \
    garbage_delete(); \
    exit(84); \
}

    #define C_INPUT my_client()->cli_input
    #define C_COMMANDS my_client()->commands
    #define C_BUFFER my_client()->cli_buffer
    #define C_CONNECTED my_client()->connected
    #define C_UUID my_client()->uuid
    #define C_NAME my_client()->name

    #define CHECK(value, error) \
if (value) { \
    P_ERROR(error); \
    return; \
}

#endif /* !MACROS_H_ */
