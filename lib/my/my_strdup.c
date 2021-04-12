/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int n = 0;

    for (; src[n] != '\0'; n++)
        dest[n] = src[n];
    dest[n] = '\0';
    return (dest);
}
