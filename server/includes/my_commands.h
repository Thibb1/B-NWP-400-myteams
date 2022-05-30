/*
** EPITECH PROJECT, 2022
** my_commands.h
** File description:
** TODO
*/

#ifndef MYTEAMS_SERVER_MY_COMMANDS_H
    #define MYTEAMS_SERVER_MY_COMMANDS_H

static const char *COMMANDS[] = {
    "/help",
    "/login",
    "/logout",
    "/users",
    "/user",
    "/send",
    "/messages",
    "/subscribe",
    "/subscribed",
    "/unsubscribe",
    "/use",
    "/create",
    "/list",
    "/info",
    "/quit",
    NULL
};

static void (*COMMANDS_FUNC[])(int) = {
    NULL,
    login_server,
    logout_server,
    users_server,
    user_server,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    use_server,
    create_state_server,
    list_server,
    info_server,
    quit_client,
    NULL
};

#endif
