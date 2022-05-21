/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** input
*/

#include "cli.h"

void handle_input(client_t *client, char *line)
{
    for (int i = 0; i != 15; i++)
        if (strcmp(line, client->commands->commands_name[i]) == 0)
            return ((client->commands->commands_func[i])());
    printf("Unkown command.\n");
}

void get_input(client_t *client)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("> ");
    read = getline(&line, &len, stdin);
    if (read != -1) {
        line[strlen(line) - 1] = '\0';
        handle_input(client, line);
    }
    free(line);
}
