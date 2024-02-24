/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** shell_loop.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

int shell_loop(char ***env, int *status)
{
    char *line = NULL;
    char **args = NULL;

    for (; status;) {
        mini_printf("$> ");
        line = read_line();
        if (line == NULL)
            exit(*status);
        args = str_to_wordarray(line, ' ');
        *status = executecheck(args, env, status);
    }
    return 0;
}
