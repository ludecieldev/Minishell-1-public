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
        exit(0);
    if (my_strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL)
            chdir(my_getenv("HOME"));
        else
            chdir(args[1]);
        return 1;
    }
    return 0;
}

static char *find_command(char *command, char **env)
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

static cond_shorter(char **args, char **environ)
{
    if (execve(args[0], args, environ) == -1) {
        args[0] = find_command(args[0], environ);
        if (args[0] == NULL) {
            mini_printf("%s: Command not found.\n", args[0]);
            return 1;
        }
        if (execve(args[0], args, environ) == -1) {
            mini_printf("%s: Permission denied.\n", args[0]);
            return 1;
        }
    }
}

int execute_bin(char **args)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == 0) {
        if (cond_shorter(args, environ) == 1)
            return (1);
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

int execute_check(char **args, char **env)
{
    if (args[0] == NULL)
        return 1;
    special_args(args, env);
    return execute_bin(args);
}
