/*
** EPITECH PROJECT, 2020
** POOL DAY 09
** File description:
** my.h
*/

#ifndef DICO
#define DICO

#define CTOI(x) (x - '0')
#define ITOC(x) (x + '0')

void my_putchar(char c);
int my_put_nbr(int nb);
void my_put_float(float nbr);
void my_putstr(char const *str);
void my_puterror(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_arr(char const *str, char delim);
void free_arr(char **arr);

#endif
