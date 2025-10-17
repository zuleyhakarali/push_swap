NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../libft

SRC = main.c utils.c little_sort.c op_push.c op_rotate.c op_rewrotate.c op_swap.c big_sort.c
OBJS = $(SRC:.c=.o)

LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C ../libft clean

fclean: clean
	rm -f $(NAME)
	make -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re