/*
** EPITECH PROJECT, 2022
** server.h
** File description:
** TODO
*/

#ifndef MYTEAMS_SERVER_MYTEAMS_SERVER_H
    #define MYTEAMS_SERVER_MYTEAMS_SERVER_H
    #include <sys/socket.h>
    #include <sys/un.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <errno.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include <time.h>
    #include <fcntl.h>
    #include <uuid/uuid.h>

    #include "logging_server.h"
    #include "macros.h"

    #define MAX_CLIENTS 100

    #define USAGE "USAGE: ./myteams_server port\n" \
    "\tport is the port number on which the server socket listens"

    #define IP "(%s,%d,%d)"

typedef struct server_logs_s {
    char *users_uuids_buffer;
} server_logs_t;


// linked list of users
typedef struct user_s {
    char *uuid;
    char *name;
    bool connected;
    struct user_s *next;
} user_t;

typedef struct server_s {
    long port;
    int socket;
    int max_fd;
    int opt;
    struct sockaddr_in addr;
    socklen_t addr_len;
    fd_set read_fds;
    int activity;
    int new_socket;
    bool running;
    user_t *users;
    server_logs_t logs;
} server_t;

typedef struct client_s {
    char *path;
    char *uuid;
    char *name;
    char *out;
    bool connected;
    int socket;
    FILE *stream;
    fd_set read_fds;
    int activity;
    char **cmd;
} client_t;

bool dir_ok(char *path);
void parse_av(char *av[]);
void int_handler(int);

void create_server(void);
void close_server(void);
void run_server(void);
void routine_server(void);

void connect_client(void);
void handle_client(int);
void close_client(int);
void disconnect_client(int);

void handle_command(int);

void to_word_array(int, char *);
int len_array(char *);
char *replace(char *, char, char);

void garbage_delete(void);
server_t *my_server(void);
client_t **my_clients(void);
client_t *my_client(int);

void close_socket(int);
void open_socket(int);

void get_file(char *path, char **dest);
void build_logs(void);
char *create_uuid(void);
char *get_uuid(char *name);

void login_server(int);
void logout_server(int);
void quit_client(int);

void users_server(int);
void user_server(int);

void free_list(user_t *list);
void add_user(char *uuid, char *name);
user_t *get_user(char *uuid);
#endif
