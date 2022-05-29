/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** metadata
*/

#include "cli.h"

client_t *my_client(void) {
    static client_t *client;

    if (!client)
        client = calloc(1, sizeof(client_t));
    return client;
}

void garbage_delete(void) {
    disconnect_client();
    DESTROY(my_client()->cli_buffer);
    DESTROY(my_client()->cli_input);
    DESTROY(my_client()->commands);
    DESTROY(my_client());
}
