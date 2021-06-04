/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** move
*/

#include <stdlib.h>
#include "needforstek.h"

void move_right(info_t *info)
{
    float middle_lidar = atof(info->lidar[MID]);

    if (middle_lidar >= 850) {
        print_cmd(info, "WHEELS_DIR:-0.04\n");
        info->dir = -0.04;
    } else if (middle_lidar < 850 && middle_lidar >= 500) {
        print_cmd(info, "WHEELS_DIR:-0.2\n");
        info->dir = -0.2;
    } else {
        print_cmd(info, "WHEELS_DIR:-0.4\n");
        info->dir = -0.4;
    }
}

void move_left(info_t *info)
{
    float middle_lidar = atof(info->lidar[MID]);

    if (middle_lidar >= 850) {
        print_cmd(info, "WHEELS_DIR:0.04\n");
        info->dir = 0.04;
    } else if (middle_lidar < 850 && middle_lidar >= 500) {
        print_cmd(info, "WHEELS_DIR:0.2\n");
        info->dir = 0.2;
    } else {
        print_cmd(info, "WHEELS_DIR:0.4\n");
        info->dir = 0.4;
    }
}

bool touching_wall(info_t *info)
{
    float middle_lidar = atof(info->lidar[MID]);
    float left_lidar = atof(info->lidar[LEFT]);
    float right_lidar = atof(info->lidar[RIGHT]);

    if (middle_lidar < 5 || left_lidar < 5 || right_lidar < 5)
        return (true);
    else
        return (false);
}