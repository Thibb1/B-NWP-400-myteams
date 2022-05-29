/*
** EPITECH PROJECT, 2022
** command.c
** File description:
** handle commands input
*/

#include "server.h"
#include "my_commands.h"

void handle_command(int i)
{
    int x = 0;

    if (!C_CMD || !C_CMD[0]) {
        dprintf(C_SOCKET, M_SYNTAX);
        return;
    }
    LOG("Recieved a new message...");
    do {
        LOG("%s", C_CMD[x]);
    } while(C_CMD[++x]);
    x = 0;
    for (; COMMANDS[x] && strcmp(COMMANDS[x], C_CMD[0]); x++);
    if (COMMANDS[x] && COMMANDS_FUNC[x])
        COMMANDS_FUNC[x](i);
    else if (COMMANDS[x])
        dprintf(C_SOCKET, M_IMPLEMENTED);
    else
        dprintf(C_SOCKET, M_SYNTAX);
}

char *commands_with_args(char *cmd, int i)
{
    size_t len = strlen(cmd);
    char *str = NULL;

    for (int j = 1; C_CMD[j]; j++)
        len += strlen(C_CMD[j]) + 1;
    str = calloc(len + 1, sizeof(char));
    strcat(str, cmd);
    for (int j = 1; C_CMD[j]; j++) {
        strcat(str, " ");
        strcat(str, C_CMD[j]);
    }
    return str;
}
