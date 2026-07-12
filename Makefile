NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = algorithm_utils.c bench.c check_if_error.c complex.c is_sort.c utils.c medium.c push.c push_swap.c reverse_rotate.c rotate.c select_flag.c simple.c split.c stack_utils.c swap.c

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
