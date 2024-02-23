/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_getenv.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

char *my_getenv(char *str, char ***env)
{
    int i = 0;
    char *ret = NULL;

    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp(str, (*env)[i], my_strlen(str)) == 0) {
            ret = my_strdup((*env)[i]);
            return get_env_value(ret);
        }
    }
    return NULL;
}
