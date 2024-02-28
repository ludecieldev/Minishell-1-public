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

    (void)args;
    (void)status;
    update_wd(env);
    home = my_strcat("/home/", my_getenv("USER", env));
    printf("home = %s\n", home);
    chdir(home);
}
