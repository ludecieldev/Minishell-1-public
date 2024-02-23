/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** setenv_twoargs.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void setenv_two_args(char **args, char ***env, int *status)
{
    if (args[3] != NULL) {
        puterror("setenv: Too many arguments.\n");
        *status = 84;
        return;
    }
    my_setenv(args, env, status);
}
