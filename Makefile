NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c little_sort.c op_push.c op_rotate.c op_rewrotate.c\
	op_swap.c big_sort.c index.c for_little.c libft.c

OBJS = $(SRC:.c=.o)

LIB_DIR = ../libft
LIB = $(LIB_DIR)/libft.a

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
