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


//DEBUG
    #define OPENING "150 " BOLD GREEN "File status okay; about to open data" \
    " connection." RESET CR
    #define NOOP "200 " BOLD GREEN "Command ok." RESET CR
    #define HELP "214 " BOLD BLUE "%s" RESET CR
    #define HELP_LIST "214 " BOLD BLUE "[USER, PASS, CWD, CDUP, QUIT, DELE," \
    " PWD, PASV, PORT, HELP, NOOP, RETR, STOR, LIST]" RESET CR
    #define SERVICE_READY "220 " BOLD GREEN "Service ready for new user." \
    RESET CR
    #define LOGOUT "221 " BOLD RED "Disconnected" RESET CR
    #define DATA_CLOS "226 " BOLD GREEN "Closing data connection." RESET CR
    #define PASV "227 " BOLD GREEN "Entering Passive Mode " RESET IP CR
    #define LOGIN "230 " BOLD GREEN "User logged in" RESET CR
    #define DELE "250 " BOLD ORANGE "%s deleted" RESET CR
    #define DIR_CHANGED "250 " BOLD GREEN "%s" RESET CR
    #define ACC_OK "331 " BOLD GREEN "User name okay, need password." RESET CR
    #define ACC_KO "332 " BOLD RED "Need account for login." RESET CR
    #define DATA_CONN "425 " BOLD RED "Can't open data connection." RESET CR
    #define FILE_ERR "452 " BOLD RED "File transfer error." RESET CR
    #define SYNTAX_ERROR "500 " BOLD RED "Syntax error, command " \
    "unrecognized." RESET CR
    #define COMMAND_ERROR "501 " BOLD RED "Syntax error in parameters or" \
    " arguments" RESET CR
    #define NOT_IMPL "502 " BOLD RED "Command not implemented. (%s)" RESET CR
    #define LOG_IN "530 " BOLD RED "Not logged in." RESET CR
    #define FOLDER_ERROR "550 " BOLD RED "%s Folder error" RESET CR
    #define FILE_ERROR "550 " BOLD RED "%s File error" RESET CR


    #define DESTROY(v) \
if (v) { \
    free(v); \
}

    #define FCLOSE(f) \
if (f) { \
    close(f); \
}

    #ifdef DEBUG
        #define M_ERROR BOLD RED "[%s:%d] " RESET BOLD "%s " RESET
        #define P_ERROR(...) \
    fprintf(stdout, M_ERROR, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stdout, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error"));
        #define M_LOG BOLD BLUE "[%s:%d] " RESET BOLD "%s " RESET
        #define LOG(...) \
    fprintf(stdout, M_LOG, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stdout, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Log"));
    #else
        #define M_ERROR BOLD RED "%s\n" RESET
        #define P_ERROR(...) \
    fprintf(stdout, M_ERROR, DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error"));
        #define M_LOG BOLD BLUE "%s\n" RESET
        #define LOG(...) \
    fprintf(stdout, M_LOG, DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Log"));
    #endif


    #define CLIENT my_client(i)
    #define C_SOCKET CLIENT->socket
    #define C_DATA CLIENT->data
    #define C_DTSCT CLIENT->data_sock
    #define C_OPT CLIENT->opt
    #define C_ADDR CLIENT->addr
    #define C_ADLEN CLIENT->addr_len
    #define C_PORT C_ADDR.sin_port
    #define C_PATH CLIENT->path
    #define C_CMD CLIENT->cmd
    #define C_ACC CLIENT->acc
    #define C_CNT CLIENT->connected
    #define SERVER my_server()
    #define S_SOCKET SERVER->socket
    #define S_ADDR SERVER->addr
    #define S_ADLEN SERVER->addr_len
    #define S_OPT SERVER->opt
    #define S_PORT S_ADDR.sin_port

    #define DEF_OR_ARG(value, ...) value

    #define ASSERT(value, ...) \
if (value) { \
    P_ERROR(__VA_ARGS__); \
    garbage_delete(); \
    exit(84); \
}

    #define CHECK_ARG(v) \
if (!(v)) { \
    dprintf(C_SOCKET, COMMAND_ERROR); \
    return; \
}

    #define CHECK_LOG \
if (!C_CNT) { \
    dprintf(C_SOCKET, LOG_IN); \
    return; \
}

    #define CHECK_SOCKET \
if (!C_DTSCT) { \
    dprintf(C_SOCKET, DATA_CONN); \
    return; \
}
#endif /* !MACROS_H_ */
