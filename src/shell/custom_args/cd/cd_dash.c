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
    char *oldpwd = my_getenv("OLDPWD", env);

    (void) args;
    update_wd(env);
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
    mini_printf("%s\n", oldpwd);
    free(oldpwd);
}
