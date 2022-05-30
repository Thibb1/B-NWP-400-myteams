/*
** EPITECH PROJECT, 2022
** string_util.c
** File description:
** string utilities
*/

#include "server.h"

int len_array(char *buff)
{
    char *cpy = calloc(strlen(buff) + 1, sizeof(char));
    int len = 0;
    char *left;

    strcpy(cpy, buff);
    left = cpy;
    if (strtok_r(left, " \n", &left) && ++len)
        while (strtok_r(left, "\"\n", &left) && ++len);
    DESTROY(cpy);
    return len;
}

void to_word_array(int i, char *buff)
{
    int len = len_array(buff);
    char *ptr = NULL;
    int x = 0;

    DESTROY_ARRAY(C_CMD);
    C_CMD = calloc(len + 1, sizeof(char *));
        if ((ptr = strtok_r(buff, " \n", &buff))) {
        C_CMD[x++] = strdup(ptr);
        while ((ptr = strtok_r(buff, "\"\n", &buff)))
            C_CMD[x++] = strdup(ptr);
    }
    C_CMD[x] = NULL;
}
