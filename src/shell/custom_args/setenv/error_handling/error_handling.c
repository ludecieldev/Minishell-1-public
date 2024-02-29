/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** error_handling.c
** Author:
** ludeciel
*/

#include "../../../../../include/minishell.h"

int setenv_error_handling(char **args, char ***env, int *status)
{
    if (setenv_arg_checker(args) == 1)
        return 1;
    if (is_newenv_already_existing(args[1], env, status) == 1) {
        mini_printf(args[1]);
        mini_printf(" is already existing\n");
        return 1;
    }
    return 0;
}
