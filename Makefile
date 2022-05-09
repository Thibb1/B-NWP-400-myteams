##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

all:
	$(MAKE) -C cli/ all
	$(MAKE) -C server/ all
	cp cli/myteams_cli .
	cp server/myteams_server .

clean:
	$(MAKE) -C cli/ clean
	$(MAKE) -C server/ clean

fclean:	clean
	$(MAKE) -C cli/ fclean
	$(MAKE) -C server/ fclean
	$(RM) myteams_cli myteams_server

re:		fclean all

debug:	fclean
	$(MAKE) -C cli/ debug
	$(MAKE) -C server/ debug
	cp cli/myteams_cli .
	cp server/myteams_server .

.PHONY: all clean fclean re debug
