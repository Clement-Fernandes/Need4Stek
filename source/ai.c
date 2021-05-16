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

    if (dir < 0.0)
        move_right(info);
    else if (dir > 0.0)
        move_left(info);
    else
        print_cmd(info, "WHEELS_DIR:0.0\n");
}

int ai(info_t *info)
{
    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        if (atof(info->lidar[MIDDLE]) > 2000.0)
            print_cmd(info, "CAR_FORWARD:1.0\n");
        else {
            print_cmd(info, "CAR_FORWARD:0.3\n");
            move_wheels(info);
        }
        end_track(info);
        free_arr(info->lidar);
    }
    print_cmd(info, "CAR_FORWARD:0.0\n");
    print_cmd(info, "CYCLE_WAIT:2\n");
    return (0);
}