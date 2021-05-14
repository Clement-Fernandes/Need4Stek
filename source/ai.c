/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** ai
*/

#include <stdlib.h>
#include "needforstek.h"
#include "my.h"

static const int TAG = 35;

enum LIDAR_POS {LEFT = 3, MIDDLE = 19, RIGHT = 34};

static void set_speed(info_t *info)
{
    if (atof(info->lidar[19]) > 500.0)
        print_cmd(info, "CAR_FORWARD:0.5\n");
    else
        print_cmd(info, "CAR_FORWARD:0.0\n");
}

static void turn_wheels(info_t *info)
{
    if (atof(info->lidar[RIGHT]) > atof(info->lidar[LEFT])) {
        print_cmd(info, "WHEELS_DIR:-0.2\n");
        print_cmd(info, "CAR_FORWARD:0.25\n");
    }
    else if (atof(info->lidar[RIGHT]) < atof(info->lidar[LEFT])) {
        print_cmd(info, "WHEELS_DIR:0.2\n");
        print_cmd(info, "CAR_FORWARD:0.25\n");
    }
    else {
        print_cmd(info, "WHEELS_DIR:0\n");
        print_cmd(info, "CAR_FORWARD:0.5\n");
    }
}

int ai(info_t *info)
{
    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        set_speed(info);
        turn_wheels(info);
        if (my_strcmp(info->lidar[TAG], "Track Cleared") == true) {
            info->finish = true;
        }
        free_arr(info->lidar);
    }
    print_cmd(info, "CAR_FORWARD:0.0\n");
    print_cmd(info, "CYCLE_WAIT:5\n");
    return (0);
}