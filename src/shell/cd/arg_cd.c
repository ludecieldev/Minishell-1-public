/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** arg_cd.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

extern char **environ;

int special_cd(char **args)
{
    if (my_strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            chdir(my_getenv("HOME"));
            return 1;
        }
        if (cd_flag_dash(args) == 1 || cd_flag_tilde(args) == 1)
            return 1;
        chdir(args[1]);
        return 1;
    }
    return 0;
}
