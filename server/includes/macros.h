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
    #define M_LOGIN "211 %s" BOLD GREEN " logged in" RESET CR
    #define M_LOGOUT "212 " BOLD RED "User logged out" RESET CR
    #define M_USERS "214 \"%s\" \"%d\" \"%s\"" CR
    #define M_USER "215 \"%s\" \"%d\" \"%s\"" CR
    #define M_TEAM_C "231 %s" BOLD GREEN " team created" RESET CR
    #define M_TEAM_L "234 \"%s\" \"%s\" \"%s\"" CR
    #define M_TEAM_I "235 \"%s\" \"%s\" \"%s\"" CR
    #define M_THREAD_C "241 %s \"%d\"" BOLD GREEN " thread created" RESET CR
    #define M_THREAD_L "244 \"%s\" \"%s\" \"%s\" \"%s\" \"%d\"" CR
    #define M_THREAD_I "245 \"%s\" \"%s\" \"%s\" \"%s\" \"%d\"" CR
    #define M_CHANNEL_C "261 %s" BOLD GREEN " channel created" RESET CR
    #define M_CHANNEL_L "264 \"%s\" \"%s\" \"%s\"" CR
    #define M_CHANNEL_I "265 \"%s\" \"%s\" \"%s\"" CR
    #define M_CLOSED "250 " BOLD RED "Connection closed" RESET CR

    #define E_KO "400 " BOLD RED "KO" RESET CR
    #define E_SYNTAX "401 " BOLD RED "Syntax error" RESET CR
    #define E_UNAUTHORIZED "410 " BOLD RED "Unauthorized" RESET CR
    #define E_USER "413 " BOLD RED "Unknown user" RESET CR
    #define E_CHANNEL "423 " BOLD RED "Unknown channel" RESET CR
    #define E_TEAM "433 " BOLD RED "Unknown team" RESET CR
    #define E_THREAD "443 " BOLD RED "Unknown thread" RESET CR
    #define E_EXIST "450 " BOLD RED "Already exists" RESET CR

    #define DESTROY(v) \
if (v) { \
    free(v); \
}

    #define DESTROY_ARRAY(v) \
if (v) { \
    for (int g = 0; v[g]; g++) { \
        DESTROY(v[g]); \
    } \
    DESTROY(v); \
}

    #define FCLOSE(f) \
if (f) { \
    close(f); \
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


    #define CLIENT my_client(i)
    #define C_SOCKET CLIENT->socket
    #define C_STREAM CLIENT->stream
    #define C_PATH CLIENT->path
    #define C_CMD CLIENT->cmd
    #define C_NAME CLIENT->name
    #define C_CONNECTED CLIENT->connected
    #define C_OUT CLIENT->out
    #define C_UUID CLIENT->uuid
    #define C_TEAM CLIENT->team
    #define C_CHANNEL CLIENT->channel
    #define C_THREAD CLIENT->thread

    #define SERVER my_server()
    #define S_SOCKET SERVER->socket
    #define S_ADDR SERVER->addr
    #define S_ADLEN SERVER->addr_len
    #define S_OPT SERVER->opt
    #define S_PORT S_ADDR.sin_port
    #define S_USERS SERVER->users

    #define ASSERT(value, ...) \
if (value) { \
    P_ERROR(__VA_ARGS__); \
    garbage_delete(); \
    exit(84); \
}

    #define CHECK(value, error) \
if (value) { \
    SEND(i, error); \
    return; \
}

    #define STATE(value, func, i) \
if ((value)) { \
    func(i); \
    return; \
}

    #define APPEND(path, f, ...) \
do { \
    FILE *file = fopen(path, "a+"); \
    if (file) { \
        fprintf(file, f, ##__VA_ARGS__); \
        fclose(file); \
    } \
} while (0);

    #define SEND(i, f, ...) \
do { \
    fprintf(C_STREAM, f, ##__VA_ARGS__); \
    fflush(C_STREAM); \
} while (0);

    #define FOLDER(f, ...) \
do { \
    struct stat st; \
    char path[1024]; \
    sprintf(path, f, ##__VA_ARGS__); \
    if (stat(path, &st) == -1) { \
        mkdir(path, 0700); \
    } \
} while (0);

#endif /* !MACROS_H_ */
