/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** is_newenv_already_existing.c
** Author:
** ludeciel
*/

#include "../../../../../include/minishell.h"

int is_newenv_already_existing(char *newenv, char ***env, int *status)
{
    int i = 0;

    for (; (*env)[i] != NULL; i++) {
        if (my_strncmp(newenv, (*env)[i], my_strlen(newenv)) == 0) {
            *status = 1;
            return 1;
        }
    }
    return 0;
}
