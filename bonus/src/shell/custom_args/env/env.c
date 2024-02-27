/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** env.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void env(char **args, char ***env, int *status)
{
    int i = 0;

    (void)status;
    if (args[1] != NULL) {
        mini_printf("env: '%s': No such file or directory\n", args[1]);
        return;
    }
    for (; (*env)[i] != NULL; i++)
        mini_printf("%s\n", (*env)[i]);
}
