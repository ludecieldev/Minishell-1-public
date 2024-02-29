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
		src/shell/custom_args/unsetenv/unsetenv_multiple_args.c	\
		src/shell/custom_args/setenv/error_handling/arg_checker.c	\
		src/shell/custom_args/setenv/error_handling/error_handling.c	\
		src/shell/env/reload_env.c	\
		src/shell/env/update_wd.c	\
		src/shell/env/set_home.c	\
		src/shell/custom_args/setenv/error_handling/is_newenv_allowed.c

OBJ     =   $(SRC:.c=.o)
DEPS    =   $(OBJ:.o=.d)

NAME    =   mysh

CFLAGS  +=  -W -Wall -Wextra -g3 -MMD -MP
LDFLAGS +=

CYAN    =   \033[0;36m
GREEN   =   \033[0;32m
BOLD_GREEN = \033[1;32m
RED     =   \033[1;91m
YELLOW  =   \033[1;33m
NC      =   \033[0m # No Color

TOTAL_FILES = $(words $(SRC))
FILES_COMPILED = 0

.SILENT:

all: clear start_compilation $(NAME) end_compilation

start_compilation:
	@printf "${YELLOW}Lud's Makefile | \
${CYAN}Started compilation of ${RED}$(TOTAL_FILES) files${NC}\n"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@printf "${YELLOW}Lud's Makefile | ${BOLD_GREEN}Compilation done!${NC}\n"

%.o: %.c
	@printf "${CYAN}Compiling $< $(FILES_COMPILED)/$(TOTAL_FILES)...${NC}\r"
	@$(eval FILES_COMPILED=$(shell echo $$(($(FILES_COMPILED)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN}Compiled $< $(FILES_COMPILED)/$(TOTAL_FILES)${NC}\n"

end_compilation:
	@if [ $(FILES_COMPILED) -eq $(TOTAL_FILES) ]; then \
		printf "${YELLOW}Lud's Makefile | ${BOLD_GREEN}All \
files compiled successfully!${NC}\n"; \
	else \
		printf "${YELLOW}Lud's Makefile | No new changes to compile.${NC}\n"; \
	fi

clean:
	@rm -f $(OBJ) $(DEPS)
	@printf "${YELLOW}Lud's Makefile | ${RED}Cleaning object files...${NC}\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${YELLOW}Lud's Makefile | ${RED}Full cleanup complete.\
 Executable removed.${NC}\n"

re: fclean all

clear:
	@clear || cls

help:
	@echo "${BOLD_GREEN}Available targets:${NC}"
	@echo "${BOLD_GREEN}  all: Builds the project.${NC}"
	@echo "${BOLD_GREEN}  clean: Removes object \
files and dependency files.${NC}"
	@echo "${BOLD_GREEN}  fclean: Removes object files, dependency files, \
and the executable.${NC}"
	@echo "${BOLD_GREEN}  re: Rebuilds the project from scratch.${NC}"
	@echo "${BOLD_GREEN}  help: Displays this help.${NC}"
	@echo "${BOLD_GREEN}  clear: Clears the terminal.${NC}"


.PHONY: all clean fclean re start_compilation end_compilation clear help

-include $(DEPS)
