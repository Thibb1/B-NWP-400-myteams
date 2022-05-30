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
    #include <sys/stat.h>

    #include "logging_server.h"
    #include "macros.h"

    #define MAX_CLIENTS 100

    #define USAGE "USAGE: ./myteams_server port\n" \
    "\tport is the port number on which the server socket listens"

    #define IP "(%s,%d,%d)"

typedef struct server_logs_s {
    char *users_uuids_buffer;
    char *teams_uuids_buffer;
} server_logs_t;


// linked list of users
typedef struct user_s {
    char *uuid;
    char *name;
    bool connected;
    struct user_s *next;
} user_t;

// linked list of channels
typedef struct channel_s {
    char *uuid;
    char *name;
    char *description;
    struct channel_s *next;
} channel_t;

// linked list of threads
typedef struct thread_s {
    char *uuid;
    char *title;
    char *body;
    time_t created_at;
    char *channel_uuid;
    char *author_uuid;
    struct thread_s *next;
} thread_t;

// linked list of teams
typedef struct team_s {
    char *uuid;
    char *name;
    char *creator_uuid;
    char *description;
    thread_t *threads;
    channel_t *channels;
    struct team_s *next;
} team_t;


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
    team_t *teams;
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
    team_t *team;
    channel_t *channel;
    thread_t *thread;
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
char *get_user_uuid(char *name);

void login_server(int);
void logout_server(int);
void quit_client(int);

void users_server(int);
void user_server(int);

void build_users(char *str);
void free_users(user_t *list);
void add_user(char *uuid, char *name);
user_t *get_user(char *uuid);

void build_teams(char *str);
void free_teams(team_t *list);
void add_team(char *creator_uuid, char *name, char *description);
team_t *get_team(char *uuid);
team_t *get_team_name(char *name);

void build_threads(thread_t **threads, char *str);
void free_threads(thread_t *list);
void load_threads(thread_t **threads, char *uuid);
void add_thread(int i, char *title, char *body);
thread_t *get_thread(team_t *team, channel_t *channel, char *uuid);
thread_t *get_thread_name(team_t *team, channel_t *channel, char *name);

void build_channels(channel_t **channels, char *str);
void free_channels(channel_t *list);
void load_channels(channel_t **channels, char *uuid);
void add_channel(char *team_uuid, char *name, char *description);
channel_t *get_channel(team_t *team, char *uuid);
channel_t *get_channel_name(team_t *team, char *name);

void list_server(int);
void create_state_server(int);
void use_server(int);
void info_server(int);

void create_team(int);
void list_team(int);
void use_team(int);
void use_nothing(int);

void create_channel(int);
void list_channel(int);
void use_channel(int);

void create_thread(int);
void list_thread(int);
void use_thread(int);

void create_reply(int);
void list_reply(int);
#endif
