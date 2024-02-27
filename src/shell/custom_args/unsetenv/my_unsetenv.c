/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_unsetenv.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void unsetenv_onearg(char **args, char ***env, int *status)
{
    int i = 0;
    int j = 0;
    char **newenv = NULL;

    newenv = malloc(sizeof(char *) * (my_arraylen(*env) + 1));
    for (i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], args[1], my_strlen(args[1])) != 0) {
            newenv[j] = my_strdup((*env)[i]);
            j++;
        }
    }
    newenv[j] = NULL;
    *env = newenv;
    *status = 0;
}

void my_unsetenv(char **args, char ***env, int *status)
{
    if (args[1] == NULL) {
        mini_printf("unsetenv: Too few arguments.\n");
        *status = 1;
        return;
    }
    if (args[2] == NULL) {
        unsetenv_onearg(args, env, status);
        return;
    }
    unsetenv_multiple_args(args, env, status);
    reload_env(env);
    return;
}
