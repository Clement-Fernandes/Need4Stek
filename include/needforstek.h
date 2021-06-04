/*
** EPITECH PROJECT, 2021
** my_prog
** File description:
** my_prog
*/

#ifndef MY_PROG_H_
#define MY_PROG_H_

#include <stdbool.h>
#include <stddef.h>

enum LIDAR_POS {LEFT = 3, MID = 18, RIGHT = 34};
typedef struct info_s
{
    char *buff;
    char **lidar;
    size_t size;
    bool finish;
    float dir;
} info_t;

info_t *init_struct(void);

int ai(info_t *info);
int run_cars(info_t *info);
int print_cmd(info_t *info, char *str);
int print_float_cmd(info_t *info, char *str, float val);
void move_right(info_t *info);
void move_left(info_t *info);
void move_speed(info_t *info);
void move_wheels(info_t *info);
bool touching_wall(info_t *info);
void move_wheels_back(info_t *info, float dir);

#endif /* !MY_PROG_H_ */