/*
** EPITECH PROJECT, 2021
** game_of_life
** File description:
** read_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

char *read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    char *buff = NULL;
    int size = 0;

    if (fd == -1)
        return (NULL);
    if (stat(filepath, &st) == - 1)
        return (NULL);
    size = st.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        return (NULL);
    buff[size] = '\0';
    if (read(fd, buff, size) == -1)
        return (NULL);
    close(fd);
    return (buff);
}
