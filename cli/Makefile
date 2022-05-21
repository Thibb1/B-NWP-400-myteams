##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

OUT 	=	myteams_cli
SOURCE	=	src/struct_init/commands.c \
			src/struct_init/client.c \
			src/funcs.c \
			src/input.c \
			src/engine.c \
			src/main.c
CC		=	gcc
CFLAGS	=	-W -Wall -Wshadow -Wextra -I./includes
LDFLAGS	=	-L../libs/myteams '-Wl,-rpath=$$ORIGIN/libs/myteams' -lmyteams
OBJS	=	$(SOURCE:.c=.o)


$(OUT):	$(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS) $(LDFLAGS)

all:	$(OUT)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(OUT)

re:		fclean all

debug:	CFLAGS	+=	-ggdb
debug:	re

.PHONY: all clean fclean re debug
