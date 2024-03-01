/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** execute_bin.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

static int is_dir(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
        return 1;
    if (!S_ISDIR(sb.st_mode))
        return 1;
    return 0;
}

static int cond_shorter(char **args, char ***env)
{
    args[0] = find_command(args[0], env);
    if (execve(args[0], args, *env) == -1) {
        if (access(args[0], F_OK) == -1) {
            puterror(args[0]);
            puterror(": Command not found.\n");
            return 1;
        }
        if (access(args[0], X_OK) == -1 ||
        access(args[0], R_OK) == -1 ||
        is_dir(args[0]) == 0) {
            puterror(args[0]);
            puterror(": Permission denied.\n");
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
            return 1;
    }
    if (pid < 0) {
        mini_printf("Fork failed.\n");
        return 0;
    } else {
        waitpid(pid, &wstatus, 0);
        return get_fork_status(wstatus);
    }
}
