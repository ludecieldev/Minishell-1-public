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
    int status = 1;
    char **envp = my_arraydup(env);

    (void)ac;
    (void)av;
    shell_loop(&envp, &status);
    return (status);
}
