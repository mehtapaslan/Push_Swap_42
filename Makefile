NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = main.c \
		parsing/parsing_numbers.c parsing/parsing_flags.c \
		parsing/parsing_utils.c parsing/parsing_errors.c \
		operations/push.c operations/swap.c operations/rotate.c \
		operations/rev_rotate.c \
		utils/stack_init.c utils/compute_disorder.c \
		utils/op_counter.c utils/bench.c \
		sorting/sort_simple.c sorting/sort_medium.c \
		sorting/sort_medium_utils.c sorting/sort_complex.c \
		sorting/sort_complex_utils.c sorting/sort_adaptive.c
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