/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** read_line.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

char *remove_backn(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    for (; str[i] != '\n'; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 1001;

    if (getline(&line, &bufsize, stdin) == -1) {
        free(line);
        return NULL;
    }
    return (remove_backn(line));
}
