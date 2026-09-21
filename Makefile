NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c parsing_parse.c parsing_utils.c push.c stack_init.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re