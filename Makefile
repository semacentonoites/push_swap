CC      	= cc
CFLAGS		= -Wall -Werror -Wextra -g

NAME = push_swap
SRC = push_swap.c operators.c more.c more2.c more3.c more4.c more5.c more6.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
