/*
** EPITECH PROJECT, 2021
** n4s
** File description:
** main
*/

#include <stdlib.h>
#include "needforstek.h"

int main(void)
{
    info_t *info = init_struct();

    if (info == NULL)
        return (84);
    if (run_cars(info) == 84) {
        free(info->buff);
        free(info);
        return (84);
    }
    free(info->buff);
    free(info);
    return (0);
}