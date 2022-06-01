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
    DESTROY_ARRAY(C_CMD);
    DESTROY(C_PATH);
    C_CMD = NULL;
    C_PATH = NULL;
    if (!C_SOCKET)
        return;
    SEND(i, M_CLOSED);
    fclose(C_STREAM);
    close(C_SOCKET);
    C_SOCKET = 0;
    C_STREAM = NULL;
    LOG("Connection closed");
}

void handle_client(int i)
{
    size_t len = 0;
    ssize_t read;
    char *buffer = NULL;

    DESTROY_ARRAY(C_CMD);
    C_CMD = NULL;
    if ((read = getline(&buffer, &len, C_STREAM)) == -1) {
        DESTROY(buffer);
        close_client(i);
    } else {
        to_word_array(i, buffer);
        DESTROY(buffer);
    }
}

void connect_client(void)
{
    ASSERT((SERVER->new_socket = accept(S_SOCKET, (struct sockaddr *)&S_ADDR,
        &S_ADLEN)) < 0, "accept error");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (C_SOCKET == 0) {
            C_SOCKET = SERVER->new_socket;
            C_STREAM = fdopen(C_SOCKET, "r");
            C_CONNECTED = false;
            use_nothing(i);
            return;
        }
    }
}
