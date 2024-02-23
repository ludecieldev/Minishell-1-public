/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** mycd.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void cd_no_args(char **args, char ***env, int *status)
{
    (void)args;
    char *home = my_getenv("HOME", env);
    char *oldpwd = my_getenv("OLDPWD", env);

    if (home == NULL) {
        puterror("cd: No home directory.\n");
        *status = 84;
        return;
    }
    if (chdir(home) == -1) {
        puterror(home);
        puterror(": No such file or directory.\n");
        *status = 84;
        return;
    }
    set_pwd(env, home);
    set_oldpwd(env, oldpwd);
}
