/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** set_oldpwd.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

void set_oldpwd(char ***env, char *oldpwd)
{
    char *newoldpwd = my_strcat("OLDPWD=", oldpwd);
    int i = 0;

    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], "OLDPWD=", 7) == 0) {
            free((*env)[i]);
            (*env)[i] = my_strdup(newoldpwd);
            free(newoldpwd);
            return;
        }
    }
    (*env) = my_realloc_array((*env), newoldpwd);
    free(newoldpwd);
}