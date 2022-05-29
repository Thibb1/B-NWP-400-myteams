/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** text_utils
*/

#include "cli.h"

int len_array(char *buff)
{
    char *cpy = calloc(strlen(buff) + 1, sizeof(char));
    int len = 0;
    char *left;

    strcpy(cpy, buff);
    left = cpy;
    while (strtok_r(left, " \r\n\t", &left) && ++len);
    DESTROY(cpy);
    return len;
}

void to_word_array(char *buff)
{
    int len = len_array(buff);
    char *ptr = NULL;
    int x = 0;

    DESTROY(C_INPUT);
    C_INPUT = calloc(len + 1, sizeof(char *));
    while ((ptr = strtok_r(buff, " \r\n\t", &buff)))
        C_INPUT[x++] = ptr;
    C_INPUT[x] = NULL;
}
