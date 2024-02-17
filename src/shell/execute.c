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

static char *find_command(char *command)
{
    char *path = my_getenv("PATH");
    char **path_array = str_to_wordarray(path, ':');
    char *command_path = NULL;
    char *tmp = NULL;

    for (int i = 0; path_array[i] != NULL; i++) {
        tmp = my_strcat(path_array[i], "/");
        command_path = my_strcat(tmp, command);
        if (access(command_path, F_OK) == 0)
            return command_path;
    }
    return NULL;
}

static int cond_shorter(char **args, char **environ)
{
    if (execve(args[0], args, environ) == -1) {
        args[0] = find_command(args[0]);
        if (args[0] == NULL) {
            mini_printf("%s: Command not found.\n", args[0]);
            return 1;
        }
        if (execve(args[0], args, environ) == -1) {
            mini_printf("%s: Permission denied.\n", args[0]);
            return 1;
        }
    }
    return 0;
}

int execute_bin(char **args)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == 0) {
        if (cond_shorter(args, environ) == 1)
            return (0);
    } else {
        waitpid(pid, &status, 0);
    }
    return 1;
}

int execute_check(char **args)
{
    if (args[0] == NULL)
        return 1;
    if (special_args(args) == 1)
        return 1;
    return execute_bin(args);
}
