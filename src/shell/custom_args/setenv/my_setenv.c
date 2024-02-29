/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** setenv.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void set_envonearg(char **args, char ***env, char *new_var)
{
    int i = 0;

    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp(args[1], (*env)[i], my_strlen(args[1])) == 0) {
            new_var = my_strcat(args[1], "=");
            (*env)[i] = new_var;
            return;
        }
    }
    *env = my_realloc_array(*env, args[1]);
    (*env)[i] = my_strcat(args[1], "=");
    (*env)[i + 1] = NULL;
}

void my_setenv(char **args, char ***env, int *status)
{
    char *new_var = NULL;

    (void)status;
    if (args[1] == NULL) {
        setenv_no_args(args, env, status);
        return;
    }
    if (setenv_error_handling(args, env, status) == 1)
        return;
    if (args[2] == NULL) {
        set_envonearg(args, env, new_var);
        *status = 0;
        return;
    }
    if (args[3] != NULL) {
        puterror("setenv: Too many arguments.\n");
        *status = 1;
        return;
    }
    setenv_two_args(args, env, status);
}
