/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** execute.c
** Author:
** ludeciel
*/

#include "../../include/minishell.h"

extern char **environ;

int special_args(char **args, char **env)
{
    if (my_strcmp(args[0], "env") == 0) {
        for (int i = 0; env[i] != NULL; i++)
            mini_printf(env[i]);
        return 1;
    }
    if (my_strcmp(args[0], "exit") == 0)
        return 0;
    if (my_strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL)
            chdir(my_getenv("HOME"));
        else
            chdir(args[1]);
        return 1;
    }
}

int execute_bin(char **args)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == 0)
        if (execve(args[0], args, NULL) == -1) {
            mini_printf("Error: command not found\n");
            return 0;
        }
    if (pid < 0) {
        mini_printf("Error: fork failed\n");
        return 0;
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return 1;
    return 0;
}

int execute_check(char **args, char **env)
{
    if (args[0] == NULL)
        return 1;
    if (special_args(args, env) == 0)
        return 0;
    return execute_bin(args);
}
