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

char *regex_get_match(char *str, char *pattern)
{
    regex_t regex;
    regmatch_t match;
    char *ret = NULL;

    ASSERT(!str || !pattern, "Invalid arguments");
    regcomp(&regex, pattern, REG_EXTENDED);
    regexec(&regex, str, 1, &match, 0);
    regfree(&regex);
    if (match.rm_so != -1) {
        ret = strndup(str + match.rm_so, match.rm_eo - match.rm_so);
    }
    return ret;
}
