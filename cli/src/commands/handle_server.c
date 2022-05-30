/*
** EPITECH PROJECT, 2022
** cli
** File description:
** handle_server
*/

#include "cli.h"

void handle_server_code(int code)
{
    CODE(code, 211, client_event_logged_in, C_REG, C_NAME);
    CODE(code, 212, client_event_logged_out, C_UUID, C_NAME);
    CODE(code, 212, disconnect_client);
    CODE(code, 214, client_print_users, C_OUT[1], C_OUT[5], atoi(C_OUT[3]));
    CODE(code, 215, client_print_user, C_OUT[1], C_OUT[5], atoi(C_OUT[3]));
    CODE(code, 231, client_print_team_created, C_REG, C_INPUT[1], C_INPUT[3]);
    CODE(code, 234, client_print_team, C_OUT[1], C_OUT[3], C_OUT[5]);
    CODE(code, 241, client_print_thread_created, C_REG, C_UUID,
        (time_t)atoi(C_OUT[2]), C_INPUT[1], C_INPUT[3]);
    CODE(code, 244, client_print_thread, C_OUT[1], C_OUT[3],
        (time_t)atoi(C_OUT[9]), C_OUT[5], C_OUT[7]);
    CODE(code, 250, close_client);
    CODE(code, 261, client_print_channel_created, C_REG, C_INPUT[1],
        C_INPUT[3]);
    CODE(code, 264, client_print_channel, C_OUT[1], C_OUT[3], C_OUT[5]);
    CODE(code % 10, 4, get_next);
}

void handle_server_error(int code)
{
    CODE(code, 410, client_error_unauthorized);
    CODE(code, 413, client_error_unknown_user, C_INPUT[1]);
    CODE(code, 423, client_error_unknown_channel, C_INPUT[3]);
    CODE(code, 433, client_error_unknown_team, C_INPUT[1]);
    CODE(code, 443, client_error_unknown_thread, C_INPUT[5]);
    CODE(code, 450, client_error_already_exist);
}

void parse_uuid(void)
{
    DESTROY(C_REG);
    C_REG = NULL;
    if (regex_match(C_BUFFER, "^[0-9]{3} [a-z0-9-]{36}.*")) {
        DESTROY(C_REG);
        C_REG = regex_get_match(C_BUFFER, "^[0-9]{3} ([a-z0-9-]{36}).*");
    }
}

void get_next(void)
{
    SEND("200\n");
    read_input();
}
