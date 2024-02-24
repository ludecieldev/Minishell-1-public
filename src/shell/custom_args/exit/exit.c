/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void my_exit(char **args, char ***env, int *status)
{
    (void)env;
    (void)args;
    mini_printf("exit\n");
    exit(*status);
}
