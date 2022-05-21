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


    #define DEF_OR_ARG(value, ...) value

    #define ASSERT(v, ...) \
if (v) { \
    fprintf(stderr, ERROR, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error")); \
    garbage_delete(); \
    exit(84); \
}
    #define LOG(fm, args...) { \
    time_t t = time(NULL); \
    struct tm tm = *localtime(&t); \
    printf(LOG_MESS fm "\n", tm.tm_hour, tm.tm_min, tm.tm_sec, __FILE__, \
    __LINE__, __FUNCTION__, ##args); \
}

#endif /* !STRUCT_H_ */
