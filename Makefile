CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)
SRC = push_swap.c \
      errors/errors_func.c \
      commands/swap_func.c \
      stack/stack_func.c \
      stack/stack_init.c \
      stack/stack_sort.c \
	  stack/stack_sort_transfer.c \
	  stack/stack_sort_reconstruct.c \
	  stack/stack_sort_utils.c \
      utils.c \
	  commands/push_func.c \
	  commands/rotate_func.c\
	  commands/reverse_func.c
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

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-15000 -n 5000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l