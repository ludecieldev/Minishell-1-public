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
//SRC
void shell_loop(char **env);
char *read_line(void);
int execute_check(char **args, char **env);
char *my_getenv(char *str);
char **remove_trail(char **array);
#endif //B_PSU_200_LIL_2_1_MINISHELL1_ALEXANDRE_GARBE_MINISHELL_H
