/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_strncmp.c
** Author:
** ludeciel
*/

#include "../include/minishell.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] && s2[i] && i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (i == n)
        return 0;
    return s1[i] - s2[i];
}
