/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** read_line.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return (line);
}
