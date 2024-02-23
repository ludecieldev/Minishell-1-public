/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** setenv.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void setenv_no_args(char **args,char ***env, int *status)
{
    (void)status;
    (void)args;
    for (int i = 0; (*env)[i] != NULL; i++)
        mini_printf("%s\n", (*env)[i]);
}
