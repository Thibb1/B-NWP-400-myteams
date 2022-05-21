/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

    #include <stdio.h>

    #include "logging_client.h"

    #define RESET "\033[0m"
    #define RED "\033[31m"
    #define GREEN "\033[32m"
    #define BLUE "\033[34m"
    #define ORANGE "\033[38;5;208m"
    #define BOLD "\033[1m"

    #define M_ERROR BOLD RED "[%s:%d] " RESET BOLD "%s " RESET
    #define M_USAGE "USAGE: ./myteams_cli ip port\n" \
    "\tip is the server ip address on which the server socket listens\n" \
    "\tport is the port number on which the server socket listens"

    #define DESTROY(v) \
if (v) { \
    free(v); \
}

    #define DEF_OR_ARG(value, ...) value

    #define P_ERROR(...) \
    fprintf(stderr, M_ERROR, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error"));

    #define ASSERT(value, ...) \
if (value) { \
    P_ERROR(__VA_ARGS__); \
    garbage_delete(); \
    exit(84); \
}


    #define C_INPUT my_client()->input
    #define C_COMMANDS my_client()->commands


#endif /* !MACROS_H_ */
