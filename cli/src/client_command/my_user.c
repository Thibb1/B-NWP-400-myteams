/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** my_user
*/

#include "cli.h"

void login_client(void)
{
    CHECK(C_INPUT[1] == NULL || strlen(C_INPUT[1]) > 32, M_SYNTAX);
    send_input();
    read_input();
    disconnect_client();
    if (regex_match(C_BUFFER, "^201 .*$")) {
        C_NAME = strdup(C_INPUT[1]);
        C_CONNECTED = true;
        read_input();
        to_word_array(C_BUFFER);
        C_UUID = strdup(C_INPUT[0]);
        client_event_logged_in(C_UUID, C_NAME);
    }
}

void logout_client(void)
{
    CHECK(!C_CONNECTED, M_MUST_BE_LOGGED);
    send_input();
    read_input();
    if (regex_match(C_BUFFER, "^250 .*$")) {
        client_event_logged_out(C_UUID, C_NAME);
        disconnect_client();
    }
}

void users_client(void)
{
    CHECK(!C_CONNECTED, M_MUST_BE_LOGGED);
    send_input();
    read_input();
    CHECK(!regex_match(C_BUFFER, "^200 .*$"), M_SERVER);
    while (true) {
        read_input();
        if (regex_match(C_BUFFER, "^290 .*$"))
            break;
        to_word_array(C_BUFFER);
        client_print_users(C_INPUT[0], C_INPUT[1], atoi(C_INPUT[2]));
    }
}

void user_client(void)
{

}
