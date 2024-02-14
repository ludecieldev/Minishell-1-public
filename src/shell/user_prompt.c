/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** user_prompt.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

extern char **environ;

char *get_username(void)
{
    char *user = my_getenv("USER");
    char *new = malloc(sizeof(char) * (my_strlen(user) - 5));
    int i = 5;
    int j = 0;

    for (; user[i] != '\0'; i++) {
        new[j] = user[i];
        j++;
    }
    new[j] = '\0';
    return (new);
}

void user_prompt(void)
{
    char *user = get_username();

    mini_printf("user" "@%s $ ", user);
    free(user);
}
