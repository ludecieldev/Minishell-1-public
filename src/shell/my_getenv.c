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

char *get_env_value(char *env)
{
    char *value = NULL;
    int i = 0;
    int j = 0;

    for (; env[i] != '='; i++);
    i++;
    value = malloc(sizeof(char) * (my_strlen(env) - i + 1));
    for (; env[i] != '\0'; i++) {
        value[j] = env[i];
        j++;
    }
    value[j] = '\0';
    return value;
}

char *my_getenv(char *str)
{
    char *env = NULL;

    for (int i = 0; environ[i] != NULL; i++) {
        if (my_strncmp(environ[i], str, my_strlen(str)) == 0) {
            env = get_env_value(environ[i]);
            return env;
        }
    }
    return NULL;
}
