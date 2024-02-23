/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** set_pwd.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

void set_pwd(char ***env, char *pwd)
{
    char *newpwd = my_strcat("PWD=", pwd);
    int i = 0;

    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], "PWD=", 4) == 0) {
            free((*env)[i]);
            (*env)[i] = my_strdup(newpwd);
            free(newpwd);
            return;
        }
    }
    (*env) = my_realloc_array((*env), newpwd);
    free(newpwd);
}
