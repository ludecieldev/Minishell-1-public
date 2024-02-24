/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** setenv.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void my_setenv(char **args, char ***env, int *status)
{
    int i = 0;
    char *new_var = NULL;

    (void)status;
    if (args[1] == NULL) {
        setenv_no_args(args, env, status);
        return;
    }
    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp(args[1], (*env)[i], my_strlen(args[1])) == 0) {
            new_var = my_strcat(args[1], "=");
            new_var = my_strcat(new_var, args[2]);
            (*env)[i] = new_var;
            return;
        }
    }
    *env = my_realloc_array(*env, args[1]);
    (*env)[i] = my_strcat(args[1], "=");
    (*env)[i] = my_strcat((*env)[i], args[2]);
    (*env)[i + 1] = NULL;
}
