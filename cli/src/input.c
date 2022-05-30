/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** input
*/

#include "cli.h"
#include "my_commands.h"

void handle_command(void)
{
    if (!C_INPUT || !C_INPUT[0] || C_INPUT[0][0] != '/') {
        P_ERROR("No command given");
        return;
    }
    for (int i = 0; COMMANDS[i]; i++)
        if (!strcmp(C_INPUT[0], COMMANDS[i]))
            return ((C_COMMANDS->commands_func[i])());
    P_ERROR("Unknown command");
}

void help_client(void)
{
    int y;

    if (!C_INPUT[1]) {
        LOG(M_HELP);
        return;
    }
    for (int x = 1; C_INPUT[x]; x++) {
        y = 0;
        for (; COMMANDS[y] && strcmp(COMMANDS[y], C_INPUT[x]); y++);
        if (COMMANDS_HELP[y]) {
            LOG("%s", COMMANDS_HELP[y]);
        } else {
            P_ERROR(M_SYNTAX);
        }
    }
}

void get_input(void)
{
    size_t len = 0;
    ssize_t read;

    printf("> ");
    fflush(stdout);
    DESTROY(C_BUFFER);
    C_BUFFER = NULL;
    if ((read = getline(&C_BUFFER, &len, stdin)) == -1) {
        close_client();
    } else {
        CHECK(!regex_match(C_BUFFER, REGEX_INPUT), M_SYNTAX);
        to_word_array(C_BUFFER, &C_INPUT);
        handle_command();
    }
}

void send_input(void)
{
    int len = 0;

    while (C_INPUT[len++]);
    CODE(len, 2, fprintf, C_STREAM, "%s\n", C_INPUT[0]);
    CODE(len, 3, fprintf, C_STREAM, "%s \"%s\"\n", C_INPUT[0], C_INPUT[1]);
    CODE(len, 4, fprintf, C_STREAM, "%s \"%s\" \"%s\"\n", C_INPUT[0],
        C_INPUT[1], C_INPUT[2]);
    fflush(C_STREAM);
}

void read_input(void)
{
    size_t len = 0;
    ssize_t read;

    DESTROY(C_BUFFER);
    C_BUFFER = NULL;
    if ((read = getline(&C_BUFFER, &len, C_STREAM)) == -1) {
        close_client();
    } else {
        if (!regex_match(C_BUFFER, "[0-9]{3} .*$"))
            return;
        DESTROY(C_REG);
        C_REG = regex_get_match(C_BUFFER, "^([0-9]{3}) .*$");
        CODE(regex_match(C_BUFFER, "^2.*$"), true, LOG, "%s", C_BUFFER);
        CODE(regex_match(C_BUFFER, "^4.*$"), true, P_ERROR, "%s", C_BUFFER);
        to_word_array(C_BUFFER, &C_SERVER);
        handle_server_code(atoi(C_REG));
    }
}
