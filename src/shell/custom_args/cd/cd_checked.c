/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd_checked.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void check_cd(char **args, char ***env, int *status)
{
    char *oldpwd = my_getenv("OLDPWD=", env);

    if (args[2] != NULL) {
        puterror("cd: Too many arguments.\n");
        *status = 1;
        return;
    }
    if (args[1] == NULL) {
        cd_no_args(args, env, status);
        return;
    }
    if (my_strcmp(args[1], "-") == 0) {
        cd_dash(args, env, status, oldpwd);
        return;
    }
    if (args[1][0] == '~') {
        cd_tilde(args, env, status);
        return;
    }
    cd_directory(args, env, status);
}
