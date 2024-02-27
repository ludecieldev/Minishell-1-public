/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** unsetenv_multiple_args.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

int should_unset(char *env_var, char **args)
{
    for (int i = 1; args[i] != NULL; i++) {
        if (my_strncmp(env_var, args[i], my_strlen(args[i])) == 0) {
            return 1;
        }
    }
    return 0;
}

void unsetenv_multiple_args(char **args, char ***env, int *status)
{
    int j = 0;
    char **newenv = malloc(sizeof(char *) * (my_arraylen(*env) + 1));

    for (int i = 0; (*env)[i] != NULL; i++) {
        if (!should_unset((*env)[i], args)) {
            newenv[j] = my_strdup((*env)[i]);
            j++;
        }
    }
    newenv[j] = NULL;
    free(*env);
    *env = newenv;
    *status = 0;
}
