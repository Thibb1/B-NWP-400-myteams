##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

OUT 	=	myteams_server
SOURCE	=	src/main.c
CC		=	gcc
CFLAGS	=	-W -Wall -Wshadow -Wextra -I./includes -I../libs/myteams
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

debug:	CFLAGS	+=	-ggdb -DDEBUG
debug:	re

.PHONY: all clean fclean re debug
