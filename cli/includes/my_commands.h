/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** my_commands
*/

#ifndef MY_COMMANDS_H_
    #define MY_COMMANDS_H_

    #include <stdlib.h>

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

static const char *COMMANDS_HELP[] = {
    "/help" RESET ": show help",
    "/login [\"username\"]" RESET " : set the user_name used by client",
    "/logout" RESET " : disconnect the client from the server",
    "/users" RESET " : get the list of all users that exist on the domain",
    "/user [\"user_uuid\"]" RESET " : get information about a user",
    "/send [\"user_uuid\"] [\"message_body\"]"
    RESET " : send a message to a user",
    "/messages [\"user_uuid\"]"
    RESET " : list all messages exchange with a user",
    "/subscribe [\"team_uuid\"]"
    RESET " : subscribe to the event of a team and its subdirectories "
    "(enable reception of all events from a team)",
    "/subscribed ?[\"team_uuid\"]"
    RESET " : list all subscribed teams or list all users subscribed to a team",
    "/unsubscribe [\"team_uuid\"]"
    RESET " : unsubscribe from a team",
    "/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"]"
    RESET " : use specify a context team/channel/thread",
    "/create" RESET
    " : based on what is being used create the sub resource (see below)",
    "/list" RESET
    " : based on what is being used list all the sub resources (see below)",
    "/info" RESET
    " : based on what is being used list the current (see below)",
    NULL
};
#endif /* !MY_COMMANDS_H_ */
