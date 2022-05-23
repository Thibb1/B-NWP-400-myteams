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

    #define M_USAGE "USAGE: ./myteams_cli ip port\n" \
    "\tip is the server ip address on which the server socket listens\n" \
    "\tport is the port number on which the server socket listens"
    #define M_PORT "PORT must be a number between 1 and 65535"
    #define M_IP "IP must be a valid IPv4 address"
    #define M_SOCKET "socket() failed"
    #define M_CONNECT "connect() failed"

    #define DESTROY(v) \
if (v) { \
    free(v); \
}

    #define DEF_OR_ARG(value, ...) value

    #ifdef DEBUG
        #define M_ERROR BOLD RED "[%s:%d] " RESET BOLD "%s " RESET
        #define P_ERROR(...) \
    fprintf(stderr, M_ERROR, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error"));
        #define M_LOG BOLD BLUE "[%s:%d] " RESET BOLD "%s " RESET
        #define LOG(...) \
    fprintf(stdout, M_LOG, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stdout, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Log"));
    #else
        #define M_ERROR BOLD RED "%s\n" RESET
        #define P_ERROR(...) \
    fprintf(stderr, M_ERROR, DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error"));
        #define M_LOG BOLD BLUE "%s\n" RESET
        #define LOG(...) \
    fprintf(stdout, M_LOG, DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Log"));
    #endif

    #define ASSERT(value, ...) \
if (value) { \
    P_ERROR(__VA_ARGS__); \
    garbage_delete(); \
    exit(84); \
}


    #define C_INPUT my_client()->cli_input
    #define C_COMMANDS my_client()->commands


#endif /* !MACROS_H_ */
