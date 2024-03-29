/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** execute.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

int executecheck(char **args, char ***env, int *status)
{
    for (int i = 0; i < 5; i++)
        if (my_strcmp(args[0], specialargs[i].command) == 0) {
            specialargs[i].func(args, env, status);
            return *status;
        }
    if (args[0] == NULL || args[0][0] == '\0' ||
    args[0][0] == ' ' || args[0][0] == '\t')
        return 0;
    *status = execute_bin(args, env);
    return *status;
}
