/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** arg_checker.c
** Author:
** ludeciel
*/

#include "../../../../../include/minishell.h"

static int cond_shorter(char **args, char *good, int i)
{
    for (int j = 0; good[j] != '\0'; j++) {
        if (args[1][i] == good[j])
            break;
        if (good[j + 1] == '\0') {
            puterror("setenv: Variable name must contain alphanumeric "
            "characters.\n");
            return 1;
        }
    }
    return 0;
}

int setenv_arg_checker(char **args)
{
    char *good =
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
    char *first = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

    for (int i = 0; first[i] != '\0'; i++) {
        if (args[1][0] == first[i])
            break;
        if (first[i + 1] == '\0') {
            puterror("setenv: Variable name must begin with a letter.\n");
            return 1;
        }
    }
    for (int i = 0; args[1][i] != '\0'; i++) {
        if (cond_shorter(args, good, i) == 1)
            return 1;
    }
    return 0;
}
