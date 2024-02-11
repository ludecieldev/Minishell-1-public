##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main/main.c	\
		func/mini_printf.c	\
		func/my_getnbr.c	\
		func/my_putchar.c	\
		func/my_put_nbr.c	\
		func/my_putstr.c	\
		func/my_strlen.c	\
		func/str_to_wordarray.c	\
		func/my_atoi.c	\
		func/my_strcmp.c	\
		func/my_memset.c	\
		func/my_strdup.c	\
		func/my_revstr.c	\
		func/my_strncmp.c	\
		src/shell/loop.c	\
		src/shell/execute.c	\
		src/shell/my_getenv.c	\
		src/shell/read_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	+=	-W -Wall -Wextra -g3

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f *.o

re: fclean all

.PHONY:
	all clean fclean re
