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

    if (!C_CMD || !C_CMD[0])
        return;
    x = 0;
    for (; COMMANDS[x] && strcmp(COMMANDS[x], C_CMD[0]); x++);
    if (COMMANDS[x] && COMMANDS_FUNC[x])
        COMMANDS_FUNC[x](i);
    else if (COMMANDS[x]) {
        SEND(i, "Command not implemented yet");
    } else
        SEND(i, E_SYNTAX);
}
