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
    if (args[1] == NULL) {
        cd_no_args(args, env, status);
        return;
    }
    if (my_strcmp(args[1], "-") == 0) {
        cd_dash(args, env, status);
        return;
    }
    if (args[1][0] == '~') {
        cd_tilde(args, env, status);
        return;
    }
    cd_directory(args, env, status);
}