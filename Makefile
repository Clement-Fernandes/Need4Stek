##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	source/main.c 			\
			source/init_struct.c	\
			source/print_cmd.c 		\
			source/ai.c				\
			source/move.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

CFLAGS 	=	-W -Wall -Wextra

CPPFLAGS 	=	-I./include/ -I./lib/include/

LDFLAGS 	=	-L./lib

LDLIBS		=	-lmy


CC	=	gcc

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		make -sC lib/my/ libmy
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
		make -sC lib/my/ clean
		$(RM) $(OBJ)

fclean:		clean
		make -sC lib/my/ fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
