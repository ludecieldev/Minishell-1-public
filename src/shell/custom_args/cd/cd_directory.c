/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd_directory.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

void cd_directory(char **args, char ***env, int *status)
{
    update_wd(env);
    if (chdir(args[1]) == -1) {
        puterror(args[1]);
        puterror(": No such file or directory.\n");
        *status = 1;
        return;
    }
    if (args[2] != NULL) {
        puterror("cd: Too many arguments.\n");
        *status = 1;
        return;
    }
    *status = 0;
}
