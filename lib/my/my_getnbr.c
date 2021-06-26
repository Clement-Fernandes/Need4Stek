/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get nbr
*/

static int is_num(char c)
{
    if (c == '-' || c == '+')
        return (2);
    else if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int res = 0;
    int p;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == '-' || str[i] == '+') {
            if (str[i] == '-')
                sign *= (-1);
            i++;
        }
        p = is_num(str[i]);
        if (p == 1)
            res = res * 10 + (str[i] - '0');
        if (p == 0)
            return (res * sign);
    }
    return (res * sign);
}