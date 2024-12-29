CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)
SRC = push_swap.c errors/errors_func.c commands/swap_func.c stack/stack_func.c stack/stack_init.c utils.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o ${<:.c=.o}

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re