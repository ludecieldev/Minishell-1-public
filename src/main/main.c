/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

extern char **environ;

int main(int ac, char **av)
{
    if (ac != 1)
        return 84;
    shell_loop(environ);
}
