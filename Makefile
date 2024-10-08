NAME = get_next_line.a
CFLAGS = -Wall -Wextra -Werror -I./include/
DEBUG = -g3 -fsanitize=address
CC = cc

SRC =	./main.c\
		./get_next_line.c

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