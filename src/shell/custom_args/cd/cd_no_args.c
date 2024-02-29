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
    char *home;

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
