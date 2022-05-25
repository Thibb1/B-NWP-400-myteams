/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** input
*/

#include "cli.h"

void handle_command(void)
{
    if (!C_INPUT || !C_INPUT[0] || C_INPUT[0][0] != '/') {
        P_ERROR("No command given");
        return;
    }
    for (int i = 0; i != 15; i++)
        if (!strcmp(C_INPUT[0], C_COMMANDS->commands_name[i]))
            return ((C_COMMANDS->commands_func[i])());
    P_ERROR("Unkown command");
}

int len_array(char *buff)
{
    char *cpy = calloc(strlen(buff) + 1, sizeof(char));
    int len = 0;
    char *left;

    strcpy(cpy, buff);
    left = cpy;
    while (strtok_r(left, " \r\n\t", &left) && ++len);
    DESTROY(cpy);
    return len;
}

void to_word_array(char *buff)
{
    int len = len_array(buff);
    char *ptr = NULL;
    int x = 0;

    DESTROY(C_INPUT);
    C_INPUT = calloc(len + 1, sizeof(char *));
    while ((ptr = strtok_r(buff, " \r\n\t", &buff)))
        C_INPUT[x++] = ptr;
    C_INPUT[x] = NULL;
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
