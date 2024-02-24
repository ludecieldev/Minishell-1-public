/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** setenv_twoargs.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void func_two_args(char **args, char ***env, int *status)
{
    char *new_key = NULL;
    char *new_value = NULL;

    for (int i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp(args[1], (*env)[i], my_strlen(args[1])) == 0) {
            new_key = my_strcat(args[1], "=");
            new_value = my_strcat(new_key, args[2]);
            (*env)[i] = new_value;
            *status = 0;
            return;
        }
    }
    new_key = my_strcat(args[1], "=");
    new_value = my_strcat(new_key, args[2]);
    *env = my_realloc_array(*env, new_value);
    *status = 0;
}

void setenv_two_args(char **args, char ***env, int *status)
{
    func_two_args(args, env, status);
}
