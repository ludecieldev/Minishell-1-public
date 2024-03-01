/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** update_wd.c
** Author:
** ludeciel
*/

#include "../../../include/minishell.h"

void update_wd(char ***env)
{
    char *pwd = getcwd(NULL, 0);
    char *oldpwd = my_getenv("PWD=", env);

    set_oldpwd(env, oldpwd);
    set_pwd(env, pwd);
    free(pwd);
    free(oldpwd);
}
