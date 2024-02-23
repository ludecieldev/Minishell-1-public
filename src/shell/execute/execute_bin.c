/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** execute_bin.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

static int cond_shorter(char **args, char ***env)
{
    if (execve(args[0], args, NULL) == -1) {
        args[0] = find_command(args[0], env);
        if (args[0] == NULL) {
            mini_printf("%s: command not found.\n", args[0]);
            return 1;
        }
        if (execve(args[0], args, *env) == -1) {
            mini_printf("%s: Permission denied.\n", args[0]);
            return 1;
        }
    }
    return 0;
}

int execute_bin(char **args, char ***env)
{
    pid_t pid;
    int wstatus;

    pid = fork();
    if (pid == 0) {
        if (cond_shorter(args, env) == 1)
            return 0;
    }
    if (pid < 0) {
        mini_printf("Fork failed.\n");
        return 1;
    } else {
        waitpid(pid, &wstatus, 0);
        return get_fork_status(wstatus);
    }
}
