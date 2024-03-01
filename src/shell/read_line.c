/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** read_line.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

char *remove_useless_spaces(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;

    if (!new_str)
        return NULL;
    while (str[i] == ' ')
        i++;
    for (; str[i] != '\0'; i++)
        if (!(str[i] == ' ' && str[i + 1] == ' ')) {
            new_str[j] = str[i];
            j++;
        }
    new_str[j] = '\0';
    return new_str;
}

char *replace_backt(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return remove_useless_spaces(str);
}

char *remove_backn(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    for (; str[i] != '\n'; i++)
        new[i] = str[i];
    new[i] = '\0';
    return replace_backt(new);
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
