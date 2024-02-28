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
    cd_tilde(args, env, status);
}
