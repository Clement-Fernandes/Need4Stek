/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** sting cat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int len = dest_len + src_len;

    for (int i = 0; dest_len + i != len; i++)
        dest[dest_len + i] = src[i];
    return (dest);
}
