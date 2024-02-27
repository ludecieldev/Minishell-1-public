/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** minishell.h
** Author:
** ludeciel
*/

#ifndef B_PSU_200_LIL_2_1_MINISHELL1_ALEXANDRE_GARBE_MINISHELL_H
    #define B_PSU_200_LIL_2_1_MINISHELL1_ALEXANDRE_GARBE_MINISHELL_H
    #include "include.h"
//STRUCT
typedef struct args_s {
    char *command;
    void (*func)(char **args, char ***env, int *status);
}args_t;
//FUNC
void *my_memset(void *s, int c, size_t n);
int mini_printf(char const *format, ...);
char *my_itoa(int nbr);
int my_getnbr(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
char **str_to_wordarray(char *str, char separator);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *str);
char *my_revstr(char *str);
int my_arraylen(char **array);
char *my_strcat(char *dest, char *src);
void puterror(char *str);
char *my_realloc(char *str, int size);
char **my_realloc_array(char **array, char *str);
char **my_arraydup(char **array);
//SRC
char *read_line(void);
char *my_getenv(char *str, char ***env);
void set_pwd(char ***env, char *pwd);
void set_oldpwd(char ***env, char *oldpwd);
void cd_no_args(char **args, char ***env, int *status);
void cd_tilde(char **args, char ***env, int *status);
int shell_loop(char ***env, int *status);
void setenv_no_args(char **args, char ***env, int *status);
void my_setenv(char **args, char ***env, int *status);
void setenv_two_args(char **args, char ***env, int *status);
void cd_dash(char **args, char ***env, int *status);
void env(char **args, char ***env, int *status);
void my_exit(char **args, char ***env, int *status);
int get_fork_status(int status);
void cd_directory(char **args, char ***env, int *status);
void check_cd(char **args, char ***env, int *status);
int execute_bin(char **args, char ***env);
int executecheck(char **args, char ***env, int *status);
int get_fork_status(int status);
char *get_env_value(char *str);
char *find_command(char *command, char ***env);
void my_unsetenv(char **args, char ***env, int *status);
void unsetenv_onearg(char **args, char ***env, int *status);
void unsetenv_multiple_args(char **args, char ***env, int *status);
int setenv_arg_checker(char **args);
int setenv_error_handling(char **args);
void reload_env(char ***env);
//TAB
static const args_t specialargs[] = {
    {"cd", &check_cd},
    {"env", &env},
    {"exit", &my_exit},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {NULL, NULL}
};

#endif //B_PSU_200_LIL_2_1_MINISHELL1_ALEXANDRE_GARBE_MINISHELL_H
