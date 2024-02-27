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
    if (chdir(args[1]) == -1) {
        puterror(args[1]);
        puterror(": No such file or directory.\n");
        *status = 1;
        return;
    }
    set_pwd(env, args[1]);
}
