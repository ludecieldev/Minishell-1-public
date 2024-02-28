/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** set_home.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

void set_home(char ***env)
{
    char *home = my_getenv("HOME", env);
    int i = 0;

    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], "HOME=", 5) == 0) {
            free((*env)[i]);
            (*env)[i] = my_strdup(home);
            free(home);
            return;
        }
    }
    (*env) = my_realloc_array((*env), home);
    free(home);
}
