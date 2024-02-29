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
    update_wd(env);
    home = my_strcat("/home/", my_getenv("USER", env));
    mini_printf("home = %s\n", home);
    if (chdir(home) == -1) {
        puterror(home);
        puterror(": No such file or directory.\n");
        *status = 1;
        return;
    }
    *status = 0;
}
