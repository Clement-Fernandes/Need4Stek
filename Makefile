##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	source/main.c			\

SRC_UT	=	tests/test.c		\

OBJ	=	$(SRC:.c=.o)

OBJ_UT 	=	$(SRC_UT:.c=.o)

NAME	=	ai

UNIT_NAME	=	unit_tests

LIB_A	=	libmy.a

CFLAGS =	-W -Wall -Wextra

CPPFLAGS =	-I./include/ -I./lib/include/

LDFLAGS =	-L./lib -lmy

CRITERION	=	--coverage -lcriterion

LIB_A = make -sC lib/my/

CC	=	gcc

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(LIB_A) libmy
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(LIB_A) clean
		$(RM) $(OBJ)

fclean:		clean
		$(LIB_A) fclean
		$(RM) $(NAME)

re:		fclean all

unit_tests: re $(OBJ_UT)
	$(CC) -o $(UNIT_NAME) $(OBJ_UT) $(LDFLAGS) $(CRITERION)

tests_run: unit_tests
	./$(UNIT_NAME)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: $(NAME) all clean fclean re unit_tests tests_run
