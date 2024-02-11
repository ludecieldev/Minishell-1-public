/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_getenv.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

extern char **environ;

char *my_getenv(char *str)
{
    char *env = NULL;

    for (int i = 0; environ[i] != NULL; i++) {
        if (my_strncmp(environ[i], str, my_strlen(str)) == 0) {
            env = my_strdup(environ[i]);
            return env;
        }
    }
    return NULL;
}
