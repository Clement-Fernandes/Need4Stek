/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int n = 0; s1[n] != '\0' || s2[n] != '\0'; n++)
        if (s1[n] != s2[n])
            return 0;
    return 1;
}
