/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** get_fork_status.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

int get_fork_status(int status)
{
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11)
            mini_printf("Segmentation fault\n");
        if (WTERMSIG(status) == 8)
            mini_printf("Floating exception\n");
        return 139;
    }
    return 0;
}
