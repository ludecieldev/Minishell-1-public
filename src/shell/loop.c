/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** loop.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"


void shell_loop(char **env)
{
    char *line;
    char **args;
    int status = 1;

    for (int i = 0; status; i++) {
        mini_printf("Minishell > ");
        line = read_line();
        args = str_to_wordarray(line, ' ');
        status = execute_check(args, env);
        free(line);
        free(args);
    }
}
