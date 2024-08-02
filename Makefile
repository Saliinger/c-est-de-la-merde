NAME = gnl
CFLAGS = -Wall -Wextra -Werror -I./include/
DEBUG = -g3 -fsanitize=address
CC = cc

SRC =	./main.c\
		./gnl.c

OBJ =		$(SRC:.c=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all