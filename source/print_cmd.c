/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** print_cmd
*/

#include <stdio.h>
#include "my.h"
#include "needforstek.h"

int print_cmd(info_t *info, char *str)
{
    my_putstr(str);
    if (getline(&info->buff, &info->size, stdin) == -1)
        return (84);
    return (0);
}

int print_float_cmd(info_t *info, char *str, double val)
{
    char *buff = NULL;

    my_putstr(str);
    my_putchar('\n');
    if (getline(&info->buff, &info->size, stdin) == -1)
        return (84);
    return (0);
}