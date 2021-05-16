/*
** EPITECH PROJECT, 2021
** my_puterror
** File description:
** my_puterror
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
}