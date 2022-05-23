/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** regex
*/

#include "my_regex.h"

bool regex_match(char *str, char *pattern)
{
    regex_t regex;
    int ret;

    ASSERT(!str || !pattern, "Invalid arguments");
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        P_ERROR("Error compiling regex");
        return false;
    }
    ret = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex);
    return ret == 0;
}
