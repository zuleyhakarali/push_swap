NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c little_sort.c op_push.c op_rotate.c op_rewrotate.c\
	op_swap.c big_sort.c index.c for_little.c libft.c

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
