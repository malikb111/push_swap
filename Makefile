CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = external/libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -Iinclude
SRC_DIR = src
SRC = $(SRC_DIR)/main/push_swap.c \
      $(SRC_DIR)/errors/errors.c \
      $(SRC_DIR)/commands/swap.c \
      $(SRC_DIR)/stack/stack.c \
      $(SRC_DIR)/stack/stack_init.c \
      $(SRC_DIR)/stack/stack_sort.c \
      $(SRC_DIR)/stack/stack_sort_transfer.c \
      $(SRC_DIR)/stack/stack_sort_reconstruct.c \
      $(SRC_DIR)/stack/stack_sort_utils.c \
      $(SRC_DIR)/utils/utils.c \
      $(SRC_DIR)/commands/push.c \
      $(SRC_DIR)/commands/rotate.c \
      $(SRC_DIR)/commands/reverse.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
