/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** my_regex
*/

#ifndef MY_REGEX_H_
    #define MY_REGEX_H_
    #include <regex.h>
    #include <stdbool.h>

    #include "macros.h"

bool regex_match(char *str, char *pattern);
char *regex_get_match(char *str, char *pattern);

#endif /* !MY_REGEX_H_ */
