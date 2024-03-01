/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd_tilde.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void cd_tilde(char **args, char ***env, int *status)
{
    char *home;

    if (args[2] != NULL) {
        puterror("cd: Too many arguments.\n");
        *status = 1;
        return;
    }
    (void)args;
    (void)status;
    home = my_getenv("HOME", env);
    update_wd(env);
    if (chdir(home) == -1) {
        puterror(home);
        puterror(": No such file or directory.\n");
        *status = 1;
        return;
    }
    *status = 0;
}
