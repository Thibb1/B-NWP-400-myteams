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
    regmatch_t match[2];
    char *ret = NULL;

    ASSERT(!str || !pattern, "Invalid arguments");
    regcomp(&regex, pattern, REG_EXTENDED);
    regexec(&regex, str, 2, match, 0);
    regfree(&regex);
    if (match[1].rm_so != -1) {
        ret = strndup(str + match[1].rm_so, match[1].rm_eo - match[1].rm_so);
    }
    return ret;
}
