/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** special_args.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

extern char **environ;

static int special_env(char **args)
{
    if (my_strcmp(args[0], "env") == 0) {
        for (int i = 0; environ[i] != NULL; i++){
            mini_printf(environ[i]);
            mini_printf("\n");
        }
        return 1;
    }
    return 0;
}

int special_args(char **args)
{
    if (special_env(args) == 1)
        return 1;
    if (my_strcmp(args[0], "exit") == 0)
        exit(0);
    if (special_cd(args) == 1)
        return 1;
    return 0;
}
