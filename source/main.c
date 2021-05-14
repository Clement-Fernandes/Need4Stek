/*
** EPITECH PROJECT, 2021
** n4s
** File description:
** main
*/

#include <stdlib.h>
#include "needforstek.h"

static int run_cars(info_t *info)
{
    if (print_cmd(info, "START_SIMULATION\n") == 84)
        return (84);
    ai(info);
    if (print_cmd(info, "STOP_SIMULATION\n") == 84)
        return (84);
    return (0);
}

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