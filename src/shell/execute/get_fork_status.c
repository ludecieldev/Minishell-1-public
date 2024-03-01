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
        if (WTERMSIG(status) == SIGSEGV) {
            mini_printf("Segmentation fault\n");
            return 139;
        }
        if (WTERMSIG(status) == SIGFPE) {
            mini_printf("Floating exception\n");
            return 136;
        }
        if (WTERMSIG(status) == SIGILL) {
            mini_printf("Illegal instruction (possible wrong architecture error)\n");
            return 132;
        }
    }
    return 0;
}

