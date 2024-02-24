/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** unsetenv_multiple_args.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void unsetenv_multiple_args(char **args, char ***env, int *status)
{
    for (int i = 1; args[i] != NULL; i++) {
        unsetenv_onearg(&args[i], env, status);
    }
}
