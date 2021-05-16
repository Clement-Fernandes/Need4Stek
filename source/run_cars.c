/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** run_cars
*/

#include <stdlib.h>
#include "needforstek.h"

int run_cars(info_t *info)
{
    if (print_cmd(info, "START_SIMULATION\n") == 84)
        return (84);
    ai(info);
    if (print_cmd(info, "STOP_SIMULATION\n") == 84)
        return (84);
    return (0);
}