/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** error_handling.c
** Author:
** ludeciel
*/

#include "../../../../../include/minishell.h"

int setenv_error_handling(char **args)
{
    if (setenv_arg_checker(args) == 1)
        return 1;
    return 0;
}
