/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** ai
*/

#include <stdlib.h>
#include "needforstek.h"
#include "my.h"

int ai(info_t *info)
{
    while (info->finish == false) {
        print_cmd(info, "GET_INFO_LIDAR\n");
        info->lidar = my_str_to_word_arr(info->buff, ':');
        if (atof(info->lidar[19]) > 500.0)
            print_cmd(info, "CAR_FORWARD:0.5\n");
        else
            print_cmd(info, "CAR_FORWARD:0.0\n");
        if (my_strcmp(info->lidar[35], "Track Cleared") == true)
            info->finish = true;
        free_arr(info->lidar);
    }
    return (0);
}