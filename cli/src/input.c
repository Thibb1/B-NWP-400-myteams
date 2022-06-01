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
    printf("> ");
    fflush(stdout);
    read_stream(stdin);
    CHECK(!regex_match(C_BUFFER, REGEX_INPUT), M_SYNTAX);
    to_word_array(C_BUFFER, &C_INPUT);
    handle_command();
}

void send_input(void)
{
    int len = 0;

    while (C_INPUT[len++]);
    CODE(len, 2, fprintf, C_STREAM, "%s\n", C_INPUT[0]);
    CODE(len, 3, fprintf, C_STREAM, "%s \"%s\"\n", C_INPUT[0], C_INPUT[1]);
    CODE(len, 5, fprintf, C_STREAM, "%s \"%s\" \"%s\"\n", C_INPUT[0],
        C_INPUT[1], C_INPUT[3]);
    CODE(len, 7, fprintf, C_STREAM, "%s \"%s\" \"%s\" \"%s\"\n", C_INPUT[0],
        C_INPUT[1], C_INPUT[3], C_INPUT[5]);
    if (len != 2 && len != 3 && len != 5 && len != 7) {
        fprintf(C_STREAM, "Error\n");
        P_ERROR(M_SYNTAX);
    }
    fflush(C_STREAM);
}

void read_input(void)
{
    int code = 0;

    read_stream(C_STREAM);
    if (!regex_match(C_BUFFER, "[0-9]{3} .*$"))
        return;
    DESTROY(C_REG);
    C_REG = regex_get_match(C_BUFFER, "^([0-9]{3}) .*$");
    CODE(regex_match(C_BUFFER, "^2.*$"), true, LOG, "%s", C_BUFFER);
    CODE(regex_match(C_BUFFER, "^4.*$"), true, P_ERROR, "%s", C_BUFFER);
    to_word_array(C_BUFFER, &C_OUT);
    code = atoi(C_REG);
    parse_uuid();
    handle_server_code(code);
    handle_more_codes(code);
    handle_server_error(code);
}
