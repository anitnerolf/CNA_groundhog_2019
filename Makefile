##
## EPITECH PROJECT, 2020
## nanotekspice
## File description:
## makefile
##

SRC	=	sources/main.cpp	\
		sources/Groundhog.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	groundhog

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ ./include/*~ $(NAME)

re:		fclean all

message:
		@echo "Successfully compiled!"
