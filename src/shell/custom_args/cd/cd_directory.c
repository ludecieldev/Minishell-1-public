/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd_directory.c
** Author:
** ludeciel
*/

#include "../../../../include/minishell.h"

static int file_if_arg_is_not_directory(char *arg)
{
    struct stat sb;

    if (stat(arg, &sb) == -1)
        return 1;
    if (!S_ISDIR(sb.st_mode))
        return 1;
    return 0;
}

void cd_directory(char **args, char ***env, int *status)
{
    update_wd(env);
    if (file_if_arg_is_not_directory(args[1]) == 1) {
        if (access(args[1], F_OK) == -1) {
            puterror(args[1]);
            puterror(": No such file or directory.\n");
            *status = 1;
            return;
        }
        puterror(args[1]);
        puterror(": Not a directory.\n");
        *status = 1;
    }
    if (chdir(args[1]) == -1) {
        puterror(args[1]);
        puterror(": No such file or directory.\n");
        *status = 1;
        return;
    }
    *status = 0;
}
