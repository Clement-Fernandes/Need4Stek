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
int print_cmd(info_t *info, char *str);
int ai(info_t *info);
int print_float_cmd(info_t *info, char *str, double val);

#endif /* !MY_PROG_H_ */