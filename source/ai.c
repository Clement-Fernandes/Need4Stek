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

static const int TAG = 35;
static const int MID = 18;
static const int LEFT = 3;
static const int RIGHT = 34;

static void end_track(info_t *info)
{
    if (my_strcmp(info->lidar[TAG], "Track Cleared") == true)
        info->finish = true;
    else if (my_strcmp(info->lidar[TAG], "Lap Cleared") == true)
        info->finish = true;
}

static void move_wheels(info_t *info)
{
    float dir = atof(info->lidar[LEFT]) - atof(info->lidar[RIGHT]);

    if (dir < 0.0) {
        if(atof(info->lidar[MID]) >= 850)
            print_cmd(info, "WHEELS_DIR:-0.04\n");
        else if (atof(info->lidar[MID]) < 850 && atof(info->lidar[MID]) >= 500)
            print_cmd(info, "WHEELS_DIR:-0.2\n");
        else
            print_cmd(info, "WHEELS_DIR:-0.4\n");
    }
    else {
        if(atof(info->lidar[MID]) >= 850)
            print_cmd(info, "WHEELS_DIR:0.04\n");
        else if (atof(info->lidar[MID]) < 850 && atof(info->lidar[MID]) >= 500)
            print_cmd(info, "WHEELS_DIR:0.2\n");
        else
            print_cmd(info, "WHEELS_DIR:0.4\n");
    }
}

int ai(info_t *info)
{
    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        if (atof(info->lidar[MID]) > 2000.0)
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