/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_getenv.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

char *get_env_value(char *str)
{
    int i = 0;
    int j = 0;
    char *ret = malloc(sizeof(char) * my_strlen(str) + 1);

    for (; str[i] != '='; i++);
    i++;
    for (; str[i] != '\0'; i++) {
        ret[j] = str[i];
        j++;
    }
    ret[j] = '\0';
    return ret;
}
