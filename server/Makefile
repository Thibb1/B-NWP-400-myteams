##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

OUT 	=	myteams_server
SOURCE	=	src/main.c					\
			src/metadata.c				\
			src/server.c				\
			src/client.c				\
			src/users.c					\
			src/teams.c					\
			src/channels.c				\
			src/threads.c				\
			src/command.c				\
			src/messages.c				\
			src/string_util.c			\
			src/subscription.c			\
			src/logs.c					\
			src/uuid.c					\
			src/replies.c				\
			src/commands/my_quit.c		\
			src/commands/my_client.c	\
			src/commands/teams.c		\
			src/commands/threads.c		\
			src/commands/channels.c		\
			src/commands/messages.c		\
			src/commands/call_command.c \
			src/commands/replies.c		\
			src/commands/subscribe.c	\
			src/commands/users.c
CC		=	gcc
CFLAGS	=	-W -Wall -Wshadow -Wextra -I./includes -I../libs/myteams
LDFLAGS	=	-L../libs/myteams -luuid -lmyteams
OBJS	=	$(SOURCE:.c=.o)


$(OUT):	$(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS) $(LDFLAGS)

all:	$(OUT)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(OUT)

re:		fclean all

debug:	CFLAGS	+=	-ggdb -DDEBUG
debug:	re

.PHONY: all clean fclean re debug
