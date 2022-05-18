# my Teams

_Collaborative communication application_

**binary name**: myteams_server, myteams_cli<br>
**language**: `C`<br>
**compilation**: `via Makefile, including re, clean and fclean rules`<br>
>- The totality of your source files, except all useless files (binary, temp files, obj files,...), must be included in your delivery.
>- All the bonus files (including a potential specific Makefile) should be in a directory named bonus.
>- Error messages have to be written on the error output, and the program should then exit with the 84 error code (0 if there is no error).

The goal of this project is to create a **server** and a **CLI client**.<br>
You MUST create your own protocol and describe it in an RFC’s style documentation.<br>
You MUST create your own data model in compliance with the given library technical properties.<br>
You MUST implement requested commands in the **CLI client**.<br>
You MUST use the given server and client libraries to print every event and data .<br>
The network communication will be achieved through the use of TCP sockets.<br>
You MUST push the given logging library, and it’s includes at the root of the repo in a sub folder `libs` like follow `NWP_myteams_*$ACADEMICYEAR*/libs/myteams/[extracted files]`.

## Server

```sh
∇ Terminal - + x
∼/B-NWP-400> ./myteams_server –help
USAGE: ./myteams_server port
    port is the port number on which the server socket listens.
```

The server MUST be able to handle several clients at the same time by using select for command management.<br>
When the server shutdown it MUST save its internal information in the current folder. (Think about the Ctrl-c)<br>
When the server start it looks if the save file exist and load it.

> A good use of **select** is expected for both reading and writing on sockets.<br>
> Any bad use of **select** would cause point loss

> The use of **fork** and **threads** are prohibited

> Take a look at **man 3 uuid** and **man 3 queue**.

> Think about **strace** to debug your program.

### Features

Your server MUST be able to manage a collaborative communication application like the well known Microsoft Teams ®.<br>
A collaborative communication application is a service able to manage several communication teams, where discussion are organised like following:
- threads (initial post and additional comments) in a specific channel
- discussion (personal messages)

Here are the features intended to be implemented:
- Creating/Joining/Leaving a team
- Creating a user
- Creating a channel in a team
- Creating a thread in a channel
- Creating a comment in a thread
- Saving & restoring users, teams, channels, threads & associated comments
- Personal discussion (from a user to another)
- Saving & restoring personal discussion

### Log

The server MUST use the given logging library to print EVERY requested events on the standard error output
as described:<br>
Please refer to the library’s header file to see the list of events to handle.

> DO NOT WRITE ANYTHING ON THE ERROR OUTPUT!
> The given library will handle it.

> If you need to display error information use for this project the standard output.

### Security

There is no password authentication required for this subject, but you should always develop with security in mind.<br>
A user that is not logged in should **NOT** be able to see connected users for example.<br>
Someone that is **NOT** subscribed to a team should not be able to create a thread.<br>
Someone that is **NOT** subscribed in a team should not receive events related to that team (new threads etc...).

## Command Line Interface (CLI) Client

```shell
∇ Terminal - + x
∼/B-NWP-400> ./myteams_cli –help
USAGE: ./myteams_cli ip port
    ip is the server ip address on which the server socket listens
    port is the port number on which the server socket listens
```

### Features

Your client will handle the following command from the standard input :
- /help : show help
- /login [“user_name”] : set the user_name used by client
- /logout : disconnect the client from the server
- /users : get the list of all users that exist on the domain
- /user [“user_uuid”] : get information about a user
- /send [“user_uuid”] [“message_body”] : send a message to a user
- /messages [“user_uuid”] : list all messages exchange with a user
- /subscribe [“team_uuid”] : subscribe to the event of a team and its subdirectories (enable reception of all events from a team)
- /subscribed ?[“team_uuid”] : list all subscribed teams or list all users subscribed to a team
- /unsubscribe [“team_uuid”] : unsubscribe from a team
- /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify a context team/channel/thread
- /create : based on what is being used create the sub resource (see below)
- /list : based on what is being used list all the sub resources (see below)
- /info : based on what is being used list the current (see below)

### /create

When the context is not defined (/use):
- /create [“team_name”] [“team_description”] : create a new team

When team_uuid is defined (/use “team_uuid”):
- /create [“channel_name”] [“channel_description”] : create a new channel

When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”):
- /create [“thread_title”] [“thread_message”] : create a new thread

When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”):
- /create [“comment_body”] : create a new reply

### /list

When the context is not defined (/use):
- /list : list all existing teams

When team_uuid is defined (/use “team_uuid”):
- /list : list all existing channels

When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”):
- /list : list all existing threads

When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”):
- /list : list all existing replies

### /info

When the context is not defined (/use):
- /info : display currently logged user infos

When team_uuid is defined (/use “team_uuid”):
- /info : display currently selected team infos

When team_uuid and channel_uuid are defined (/use “team_uuid” “channel_uuid”):
- /info : display currently selected channel infos

When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” “channel_uuid” “thread_uuid”):
- /info : display currently selected thread infos

### General Information

Please note that all arguments of the existing commands should be quoted with double quotes.<br>
A missing quote should be interpreted as an error.<br>
Please note that all the names, descriptions and message bodies have a pre-defined length which will be as follows:
- MAX_NAME_LENGTH 32
- MAX_DESCRIPTION_LENGTH 255
- MAX_BODY_LENGTH 512

You don’t have to spend too much time on the information display.<br>
You MUST therefore use the functions provided by the logging library (and only these) to display the information given by the server.<br>
Please look at the display library header, to find the variables of each data structure.

