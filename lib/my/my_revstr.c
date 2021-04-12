/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** programme
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    char cpy[length];

    my_strcpy(cpy, str);
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = cpy[length - 1 - i];
    return (str);
}
