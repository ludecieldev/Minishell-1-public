/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** loop.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

extern char **environ;

void shell_loop(void)
{
    char *line;
    char **args;
    int status = 1;

    for (int i = 0; status; i++) {
        user_prompt();
        line = read_line();
        args = str_to_wordarray(line, ' ');
        status = execute_check(args);
        free(line);
        free(args);
    }
}
