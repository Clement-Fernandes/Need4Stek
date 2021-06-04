/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** ai
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "needforstek.h"

static void end_track(info_t *info)
{
    for (int i = 3; info->lidar[i] != NULL; i++) {
        if (my_strcmp(info->lidar[i], "Track Cleared") == true) {
            info->finish = true;
            return;
        }
        else if (my_strcmp(info->lidar[i], "Lap Cleared") == true) {
            info->finish = true;
            return;
        }
    }
}

static void move_wheels(info_t *info)
{
    float dir = atof(info->lidar[LEFT]) - atof(info->lidar[RIGHT]);

    if (dir < 0.0 && touching_wall(info) == false)
        move_right(info);
    else if (dir < 0.0 && touching_wall(info) == true)
        move_left(info);
    else if (dir > 0.0 && touching_wall(info) == false)
        move_left(info);
    else if (dir > 0.0 && touching_wall(info) == false)
        move_right(info);
    else
        print_cmd(info, "WHEELS_DIR:0.0\n");
}

int ai(info_t *info)
{
    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        touching_wall(info);
        move_wheels(info);
        move_speed(info);
        end_track(info);
        free_arr(info->lidar);
    }
    print_cmd(info, "CAR_FORWARD:0.0\n");
    print_cmd(info, "CYCLE_WAIT:2\n");
    return (0);
}

void move_speed(info_t *info)
{
    float speed = 0;

    if (info->dir < 0)
        info->dir *= (-1);
    for (float i = 0; i != 1; i += 0.1)
        if (info->dir >= i && info->dir < (i + 0.1)) {
            speed = 1 - (i + 0.3);
            break;
        }
    if (touching_wall(info) == true)
        print_float_cmd(info, "CAR_BACKWARDS:", speed);
    else
        print_float_cmd(info, "CAR_FORWARD:", speed);
} 