/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr.c
*/

#include "../include/minishell.h"

int my_putstr(char const *str)
{
    int count = 0;

    write(1, str, my_strlen(str));
    return 0;
}
