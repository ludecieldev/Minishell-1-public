/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** puterror.c
** Author:
** ludeciel
*/

#include "../include/minishell.h"

void puterror(char *str)
{
    write(2, str, my_strlen(str));
}
