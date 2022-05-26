/*
** EPITECH PROJECT, 2022
** my_commands.h
** File description:
** TODO
*/

#ifndef MYTEAMS_SERVER_MY_COMMANDS_H
    #define MYTEAMS_SERVER_MY_COMMANDS_H

void login_server(int);
void logout_server(int);
void my_cwd(int);
void my_cdup(int);
void my_quit(int);
void my_dele(int);
void my_pwd(int);
void my_pasv(int);
void my_help(int);
void my_noop(int);
void my_retr(int);
void my_stor(int);
void my_list(int);

static const char *COMMANDS[] = {
    "/login",
    "/logout",
    "CWD",
    "CDUP",
    "/exit",
    "DELE",
    "PWD",
    "PASV",
    "PORT",
    "/help",
    "NOOP",
    "RETR",
    "STOR",
    "LIST",
    NULL
};

static void (*COMMANDS_FUNC[])(int) = {
    login_server,
    logout_server,
    my_cwd,
    my_cdup,
    my_quit,
    my_dele,
    my_pwd,
    my_pasv,
    NULL,
    my_help,
    my_noop,
    my_retr,
    my_stor,
    my_list
};

#endif
