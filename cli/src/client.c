/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** engine
*/

#include "cli.h"

void close_client(void)
{
    if (my_client()->input != -1) {
        dprintf(my_client()->input, "/quit\n");
        read_input();
        close(my_client()->input);
    }
    garbage_delete();
    LOG(BOLD RED "Client closed" RESET);
    exit(0);
}

void disconnect_client(void)
{
    DESTROY(C_UUID);
    DESTROY(C_NAME);
    C_UUID = NULL;
    C_NAME = NULL;
    C_CONNECTED = false;
}

void create_client_connection(char **av)
{
    create_client();
    my_client()->ip = av[1];
    my_client()->port = av[2];
    my_client()->input = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT(my_client()->input == -1, M_SOCKET);
    my_client()->server = (struct sockaddr_in) {0};
    my_client()->server.sin_family = AF_INET;
    my_client()->server.sin_port = htons(atoi(my_client()->port));
    my_client()->server.sin_addr.s_addr = inet_addr(my_client()->ip);
    LOG("Client created, connecting ...");
    ASSERT(connect(my_client()->input, (struct sockaddr *)&my_client()->server,
        sizeof(my_client()->server)) == -1, M_CONNECT);
    LOG("Connected, please login using /login <username>");
}

void create_client(void)
{
    my_client()->running = true;
    my_client()->connected = false;
    my_client()->name = NULL;
    my_client()->uuid = NULL;
    my_client()->cli_input = NULL;
    my_client()->cli_buffer = calloc(1, 1024);
    ASSERT(!my_client()->cli_buffer, M_MEMORY);
    my_client()->commands = init_commands();
}
