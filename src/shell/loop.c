/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** loop.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

int shell_loop(char **env)
{
    char *line;
    char **args;
    int status = 1;

    do {
        my_putstr("minishell1> ");
        line = read_line();
        args = split_line(line);
        status = execute(args, env);
        free(line);
        free(args);
    } while (status);
    return 0;
}
