/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int result;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    result = nb;
    if (nb >= 10) {
        result = nb % 10;
        my_put_nbr(nb / 10);
    }
    my_putchar(result + '0');
    return (0);
}
