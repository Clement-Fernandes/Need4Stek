##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c		\
		my_puterror.c	\
		my_strlen.c		\
		my_getnbr.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_revstr.c		\
		my_strcat.c		\
		str_tab.c 		\
		free_arr.c		\

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
