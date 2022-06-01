/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-romain.leemans
** File description:
** engine
*/

#include "cli.h"

void close_client(void)
{
    if (C_STREAM != NULL)
        fclose(C_STREAM);
    if (my_client()->input != -1)
        close(my_client()->input);
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
    my_client()->input = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT(my_client()->input == -1, M_SOCKET);
    my_client()->stream = fdopen(my_client()->input, "r");
    my_client()->server = (struct sockaddr_in) {0};
    my_client()->server.sin_family = AF_INET;
    my_client()->server.sin_port = htons(atoi(av[2]));
    my_client()->server.sin_addr.s_addr = inet_addr(av[1]);
    ASSERT(connect(my_client()->input, (struct sockaddr *)&my_client()->server,
        sizeof(my_client()->server)) == -1, M_CONNECT);
}

void create_client(void)
{
    my_client()->connected = false;
    my_client()->name = NULL;
    my_client()->uuid = NULL;
    my_client()->reg = NULL;
    my_client()->cli_input = NULL;
    my_client()->cli_buffer = NULL;
    my_client()->server_buffer = NULL;
    my_client()->commands = init_commands();
}

void run_client(void)
{
    int ret;
    FD_ZERO(&my_client()->read_fds);
    FD_SET(C_FD, &my_client()->read_fds);
    FD_SET(fileno(stdin), &my_client()->read_fds);
    ret = select(C_FD + 1, &my_client()->read_fds, NULL, NULL, NULL);
    ASSERT(ret == -1 && errno != EINTR, M_SELECT);
    if (FD_ISSET(C_FD, &my_client()->read_fds)) {
        read_input();
    } else if (FD_ISSET(fileno(stdin), &my_client()->read_fds)) {
        get_input();
    }
}
