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
		func/my_arraylen.c	\
		func/my_strcat.c	\
		func/my_strchr.c	\
		func/puterror.c	\
		func/my_arraydup.c	\
		func/my_realloc.c	\
		func/my_realloc_array.c	\
		src/shell/read_line.c	\
		src/shell/shell_loop.c	\
		src/shell/execute/execute_bin.c	\
		src/shell/execute/executecheck.c	\
		src/shell/execute/get_fork_status.c	\
		src/shell/env/my_getenv.c	\
		src/shell/env/set_oldpwd.c	\
		src/shell/env/set_pwd.c	\
		src/shell/custom_args/cd/cd_checked.c	\
		src/shell/custom_args/cd/cd_dash.c	\
		src/shell/custom_args/cd/cd_directory.c	\
		src/shell/custom_args/cd/cd_no_args.c	\
		src/shell/custom_args/cd/cd_tilde.c	\
		src/shell/custom_args/env/env.c	\
		src/shell/custom_args/exit/exit.c	\
		src/shell/custom_args/setenv/my_setenv.c	\
		src/shell/custom_args/setenv/setenv_noarg.c	\
		src/shell/custom_args/setenv/setenv_twoargs.c	\
		src/shell/env/get_env_value.c	\
		src/shell/execute/find_command.c \
		src/shell/custom_args/unsetenv/my_unsetenv.c	\
		src/shell/custom_args/unsetenv/unsetenv_multiple_args.c

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
