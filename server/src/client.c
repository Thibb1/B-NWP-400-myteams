/*
** EPITECH PROJECT, 2022
** client.c
** File description:
** TODO
*/

#include "server.h"

void close_client(int i)
{
    disconnect_client(i);
    if (!C_SOCKET)
        return;
    dprintf(C_SOCKET, M_LOGOUT);
    FCLOSE(C_SOCKET);
    LOG("Connection closed");
    C_SOCKET = 0;
    DESTROY(C_CMD);
    DESTROY(C_PATH);
    C_CMD = NULL;
    C_PATH = NULL;
}

void handle_client(int i)
{
    ssize_t read_ret;
    char buffer[1024];

    if (FD_ISSET(C_SOCKET, &SERVER->read_fds)) {
        if ((read_ret = read(C_SOCKET, buffer, 1024)) == 0) {
            close_client(i);
        } else {
            buffer[read_ret] = 0;
            to_word_array(i, buffer);
            handle_command(i);
        }
    }
}

void connect_client(void)
{
    ASSERT((SERVER->new_socket = accept(S_SOCKET, (struct sockaddr *)&S_ADDR,
        &S_ADLEN)) < 0, "accept error");
    LOG("New client connected");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (C_SOCKET == 0) {
            C_SOCKET = SERVER->new_socket;
            C_CNT = false;
            return;
        }
    }
}
