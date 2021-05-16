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
int print_cmd(info_t *info, char *str);
int print_float_cmd(info_t *info, char *str, float val);
void move_right(info_t *info);
void move_left(info_t *info);

#endif /* !MY_PROG_H_ */