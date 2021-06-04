/*
** EPITECH PROJECT, 2021
** B-AIA-200-PAR-2-1-n4s-maxime.carabina
** File description:
** init_struct
*/

#include <stdlib.h>
#include "needforstek.h"

info_t *init_struct(void)
{
    info_t *info = malloc(sizeof(info_t));

    if (info == NULL)
        return (NULL);
    info->buff = NULL;
    info->lidar = NULL;
    info->size = 0;
    info->finish = false;
    info->dir = 0;
    return (info);
}