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

enum LIDAR_POS {LEFT = 3, MIDDLE = 19, RIGHT = 34, TAG};

static void end_track(info_t *info)
{
    if (my_strcmp(info->lidar[TAG], "Track Cleared") == true)
        info->finish = true;
}

static void move_wheels(info_t *info)
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
    print_cmd(info, "CAR_FORWARD:0.3\n");
}

int ai(info_t *info)
{
    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        if (atof(info->lidar[MIDDLE]) > 2000.0)
            print_cmd(info, "CAR_FORWARD:0.5\n");
        else
            move_wheels(info);
        end_track(info);
        free_arr(info->lidar);
    }
    print_cmd(info, "CAR_FORWARD:0.0\n");
    print_cmd(info, "CYCLE_WAIT:5\n");
    return (0);
}