##
## EPITECH PROJECT, 2021
## stumper 2 : game of life
## File description:
## makefile
##

SRC	=	main.c	\
		lib.c	\
		lib2.c	\
		main_loop.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	"gameoflife"

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -I. -g

clean:
	rm $(OBJ)

fclean:	clean
	rm $(NAME)
