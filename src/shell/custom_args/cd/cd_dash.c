/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd_dash.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void cd_dash(char **args, char ***env, int *status)
{
    (void)args;
    char *oldpwd = my_getenv("OLDPWD", env);
    char *pwd = my_getenv("PWD", env);

    if (oldpwd == NULL) {
        puterror("cd: No previous directory.\n");
        *status = 84;
        return;
    }
    if (chdir(oldpwd) == -1) {
        puterror(oldpwd);
        puterror(": No such file or directory.\n");
        *status = 84;
        return;
    }
    set_pwd(env, oldpwd);
    set_oldpwd(env, pwd);
}
