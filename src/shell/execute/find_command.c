/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** find_command.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

char *find_command(char *command, char ***env)
{
    char *path = my_getenv("PATH", env);
    char **path_array = str_to_wordarray(path, ':');
    char *command_path = NULL;
    char *tmp = NULL;

    for (int i = 0; path_array[i] != NULL; i++) {
        tmp = my_strcat(path_array[i], "/");
        command_path = my_strcat(tmp, command);
        if (access(command_path, F_OK) == 0)
            return command_path;
    }
    return command;
}
