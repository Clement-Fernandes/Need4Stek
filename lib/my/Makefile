##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	free_arr.c		\
			my_getnbr.c		\
			my_put_float.c	\
			my_put_nbr.c	\
			my_putchar.c	\
			my_puterror.c	\
			my_putstr.c		\
			my_revstr.c		\
			my_strcat.c		\
			my_strcmp.c		\
			my_strcpy.c		\
			my_strdup.c		\
			my_strlen.c		\
			read_file.c		\
			str_tab.c 		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS =	-W -Wall -Wextra

RM	=	rm -f

libmy:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) ../$(NAME)

re:     fclean all

.PHONY: libmy clean flclean re
