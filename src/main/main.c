/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    int status = 1;
    char **envp = my_arraydup(env);

    shell_loop(&envp, &status);
    return (status);
}
