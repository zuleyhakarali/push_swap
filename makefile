NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c free_and_exit.c little_sort.c op_push.c op_rotate.c op_rewrotate.c\
	op_swap.c big_sort.c index.c for_little.c libft.c
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