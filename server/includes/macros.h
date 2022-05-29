/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include "server.h"

    #define DELIM " \r\n"

    #define RESET "\033[0m"
    #define RED "\033[31m"
    #define GREEN "\033[32m"
    #define BLUE "\033[34m"
    #define ORANGE "\033[38;5;208m"
    #define BOLD "\033[1m"
    #define CR "\r\n"

    #define M_OK "200 " BOLD GREEN "OK" RESET CR
    #define M_LOGIN "201 " BOLD GREEN "User logged in" RESET CR
    #define M_SENT "202 " BOLD GREEN "Message sent" RESET CR
    #define M_SUBSCRIBED "211 " BOLD GREEN "Subscribed" RESET CR
    #define M_UNSUBSCRIBED "219 " BOLD GREEN "Unsubscribed" RESET CR
    #define M_LOGOUT "250 " BOLD RED "User logged out" RESET CR
    #define M_CLOSED "251 " BOLD RED "Server connection closed" RESET CR
    #define M_DATA "290 " BOLD GREEN "Data sent" RESET CR

    #define M_KO "300 " BOLD RED "KO" RESET CR
    #define M_NOT_LOGGED "301 " BOLD RED "Unauthenticated" RESET CR
    #define M_NOT_FOUND "302 " BOLD RED "Unknown command" RESET CR
    #define M_SYNTAX "303 " BOLD RED "Syntax error" RESET CR
    #define M_IMPLEMENTED "304 " BOLD RED "Command not implemented" RESET CR

    #define DESTROY(v) \
if (v) { \
    free(v); \
}

    #define FCLOSE(f) \
if (f) { \
    close(f); \
}

    #ifndef DEBUG
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


    #define CLIENT my_client(i)
    #define C_SOCKET CLIENT->socket
    #define C_PATH CLIENT->path
    #define C_CMD CLIENT->cmd
    #define C_NAME CLIENT->name
    #define C_CNT CLIENT->connected
    #define C_UUID CLIENT->uuid
    #define SERVER my_server()
    #define S_SOCKET SERVER->socket
    #define S_ADDR SERVER->addr
    #define S_ADLEN SERVER->addr_len
    #define S_OPT SERVER->opt
    #define S_PORT S_ADDR.sin_port

    #define ASSERT(value, ...) \
if (value) { \
    P_ERROR(__VA_ARGS__); \
    garbage_delete(); \
    exit(84); \
}

    #define CHECK(value, error) \
if (value) { \
    dprintf(C_SOCKET, error); \
    return; \
}

#endif /* !MACROS_H_ */
