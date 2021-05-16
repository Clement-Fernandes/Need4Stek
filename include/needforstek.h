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

typedef struct info_s
{
    char *buff;
    char **lidar;
    size_t size;
    bool finish;
} info_t;

info_t *init_struct(void);

int ai(info_t *info);
int run_cars(info_t *info);
float move_wheels(info_t *info);
int print_cmd(info_t *info, char *str);
void move_speed(info_t *info, float dir);
int print_float_cmd(info_t *info, char *str, float val);

#endif /* !MY_PROG_H_ */