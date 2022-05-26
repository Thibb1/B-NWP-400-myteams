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
            LOG(COMMANDS_HELP[y]);
        } else {
            P_ERROR(M_SYNTAX);
        }
    }
}


void get_input(void)
{
    ssize_t read_ret;
    char buffer[1024];

    printf("> ");
    fflush(stdout);
    if ((read_ret = read(STDIN_FILENO, buffer, 1024)) == 0) {
        disconnect_client();
    } else {
        buffer[read_ret] = 0;
        to_word_array(buffer);
        handle_command();
    }
}

void send_input(void)
{
    int len = 0;
    while (C_INPUT[len++]);
    switch (--len) {
        case 2:
            dprintf(my_client()->input, "%s %s\n", C_INPUT[0], C_INPUT[1]);
            break;
        case 3:
            dprintf(my_client()->input, "%s %s %s\n", C_INPUT[0], C_INPUT[1],
                C_INPUT[2]);
            break;
        default:
            dprintf(my_client()->input, "%s\n", C_INPUT[0]);
            break;
    }
}

void read_input(void)
{
    ssize_t read_ret;


    if ((read_ret = read(my_client()->input, C_BUFFER, 1024)) == 0) {
        disconnect_client();
    } else {
        C_BUFFER[read_ret] = 0;
        if (regex_match(C_BUFFER, "^221.*$")) {
            disconnect_client();
        }
    }
}
