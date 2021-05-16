/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** move
*/

#include <stdlib.h>
#include "needforstek.h"

static const int MID = 18;

void move_right(info_t *info)
{
    if(atof(info->lidar[MID]) >= 850)
        print_cmd(info, "WHEELS_DIR:-0.04\n");
    else if (atof(info->lidar[MID]) < 850 && atof(info->lidar[MID]) >= 500)
        print_cmd(info, "WHEELS_DIR:-0.2\n");
    else
        print_cmd(info, "WHEELS_DIR:-0.4\n");
}

void move_left(info_t *info)
{
    if(atof(info->lidar[MID]) >= 850)
        print_cmd(info, "WHEELS_DIR:0.04\n");
    else if (atof(info->lidar[MID]) < 850 && atof(info->lidar[MID]) >= 500)
        print_cmd(info, "WHEELS_DIR:0.2\n");
    else
        print_cmd(info, "WHEELS_DIR:0.4\n");
}