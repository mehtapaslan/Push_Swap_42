NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c parsing_numbers.c parsing_flags.c parsing_utils.c parsing_errors.c \
		push.c swap.c stack_init.c rotate.c rev_rotate.c \
		compute_disorder.c sort_simple.c sort_medium.c sort_medium_utils.c \
		sort_complex.c sort_complex_utils.c sort_adaptive.c \
		op_counter.c bench.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re