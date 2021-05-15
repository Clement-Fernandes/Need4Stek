/*
** EPITECH PROJECT, 2021
** my_put_float
** File description:
** my_put_float
*/

int my_put_nbr(int nb);

void my_putchar(char c);

void my_put_float(float nbr)
{
    double myfloat;
    int float_part = 0;
    int int_part = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    int_part = (int)nbr;
    my_put_nbr(int_part);
    my_putchar('.');
    nbr -= int_part;
    nbr *= 1000000;
    float_part = (int)(nbr + 0.5);
    my_put_nbr(float_part);
}