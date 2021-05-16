/*
** EPITECH PROJECT, 2021
** n4s
** File description:
** move
*/

#include <stdlib.h>
#include "needforstek.h"

enum LIDAR_POS {LEFT = 3, MIDDLE = 19, RIGHT = 34, TAG};

float move_wheels(info_t *info)
{
    float dir = 0;
    float left_value = atof(info->lidar[LEFT]);
    float right_value = atof(info->lidar[RIGHT]);

    if (left_value < 250 || right_value < 250)
        dir = 0.4;
    else if (left_value == right_value)
        dir = 0;
    else
        dir = 0.15;
    if (left_value < right_value)
        dir *= -1;
    print_float_cmd(info, "WHEELS_DIR:", dir);
    return (dir);
}

void move_speed(info_t *info, float dir)
{
    float speed = 0;

    if (dir < 0)
        dir *= (-1);
    for (float i = 0; i != 1; i += 0.1)
        if (dir >= i && dir < (i + 0.1)) {
            speed = 1 - (i + 0.3);
            break;
            }
    print_float_cmd(info, "CAR_FORWARD:", speed);
}