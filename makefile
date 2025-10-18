NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c little_sort.c op_push.c op_rotate.c op_rewrotate.c op_swap.c big_sort.c index.c libft.c best_b.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re