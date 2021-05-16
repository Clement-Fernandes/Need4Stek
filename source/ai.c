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

int ai(info_t *info)
{
    float dir = 0;

    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        dir = move_wheels(info);
        move_speed(info, dir);
        end_track(info);
        free_arr(info->lidar);
    }
    print_cmd(info, "CAR_FORWARD:0.0\n");
    print_cmd(info, "CYCLE_WAIT:5\n");
    return (0);
}