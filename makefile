NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibftwbonus

SRC = main.c
OBJS = $(SRC:.c=.o)

LIBFT = libftwbonus/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libftwbonus

clean:
	rm -f $(OBJS)
	make -C libftwbonus clean
	make -C libftwbonus fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re