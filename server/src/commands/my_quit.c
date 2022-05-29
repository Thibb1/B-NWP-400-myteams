/*
** EPITECH PROJECT, 2022
** my_quit.c
** File description:
** disconnect client
*/

#include "server.h"

void quit_client(int i)
{
    close_client(i);
}
