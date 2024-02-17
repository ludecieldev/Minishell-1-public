/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** setenv.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

extern char **environ;

int my_setenv(char **args)
{
    if (my_strcmp(args[0], "setenv") == 0) {
        if (args[1] == NULL) {
            my_env();
            return 1;
        }
        if (args[2] == NULL) {
            setenv(args[1], "", 1);
            return 1;
        }
        setenv(args[1], args[2], 1);
        return 1;
    }
    return 0;
}
