/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** reload_env.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

void reload_env(char ***env)
{
    int i = 0;
    char **newenv = NULL;

    newenv = malloc(sizeof(char *) * (my_arraylen(*env) + 1));
    for (i = 0; (*env)[i] != NULL; i++) {
        newenv[i] = my_strdup((*env)[i]);
    }
    newenv[i] = NULL;
    *env = newenv;
}
