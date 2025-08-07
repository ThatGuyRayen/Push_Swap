NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
SRC_DIR = .
OBJ_DIR = objs
SRCS = main.c input_parser.c error.c operations.c operations_r.c operations_rotation.c operations_swap.c utils.c small_sort.c indexing.c radix_sort.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBFT = libft/libft.a
INCLUDES = -I. -Ilibft


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re

