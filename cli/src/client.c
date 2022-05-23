/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** engine
*/

#include "cli.h"

void disconnect_client(void)
{
    if (my_client()->fd != -1)
        close(my_client()->fd);
    if (my_client()->stream)
        fclose(my_client()->stream);
    garbage_delete();
    exit(0);
}

void create_client(char **av)
{
    my_client()->running = true;
    my_client()->ip = av[1];
    my_client()->port = av[2];
    my_client()->fd = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT(my_client()->fd == -1, M_SOCKET);
    my_client()->server = (struct sockaddr_in) {0};
    my_client()->server.sin_family = AF_INET;
    my_client()->server.sin_port = htons(atoi(my_client()->port));
    my_client()->server.sin_addr.s_addr = inet_addr(my_client()->ip);
    my_client()->stream = fdopen(my_client()->fd, "w+");
    my_client()->input = NULL;
    my_client()->commands = init_commands();
    LOG("Client created, connecting ...");
    ASSERT(connect(my_client()->fd, (struct sockaddr *)&my_client()->server,
        sizeof(my_client()->server)) == -1, M_CONNECT);
}

void run_client(void)
{
    while (my_client()->running) {
        get_input();
        handle_command();
    }
}
