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
    if (strtok_r(left, " \n", &left) && ++len)
        while (strtok_r(left, "\"\n", &left) && ++len);
    DESTROY(cpy);
    return len;
}

void to_word_array(char *buff, char ***array)
{
    char *cpy = strdup(buff);
    char *left = cpy;
    int len = len_array(cpy);
    char *ptr = NULL;
    int x = 0;

    DESTROY_ARRAY(*array);
    *array = calloc(len + 2, sizeof(char *));
    if ((ptr = strtok_r(left, " \n", &left))) {
        (*array)[x++] = strdup(ptr);
        while ((ptr = strtok_r(left, "\"\n", &left)))
            (*array)[x++] = strdup(ptr);
    }
    (*array)[x] = NULL;
    DESTROY(cpy);
}
