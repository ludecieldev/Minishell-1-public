/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** cd_flag_dash.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

extern char **environ;

int cd_flag_dash(char **args)
{
    if (my_strcmp(args[1], "-") == 0) {
        chdir(my_getenv("OLDPWD"));
        mini_printf("%s\n", my_getenv("OLDPWD"));
        return 1;
    }
    return 0;
}
