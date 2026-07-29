NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude
OBJ_DIR = obj

SRCS =	src/main.c \
		src/stack/stack_init.c \
		src/stack/node_new.c \
		src/stack/stack_add_bottom.c \
		src/stack/free_stack.c \
		src/parser/input_utils.c \
		src/parser/validate_number.c \
		src/parser/check_duplicate.c \
		src/parser/parse_number.c \
		src/parser/parse_token.c \
		src/parser/parse_argument.c \
		src/parser/parse_arguments.c \
		src/utils/error_exit.c \
		src/operations/swap.c \
		src/operations/push.c \
		src/operations/rotate.c \
		src/operations/reverse_rotate.c \
		src/index/assign_index.c \
		src/index/index_utils.c \
		src/sort/sort_utils.c \
		src/sort/sort_two.c \
		src/sort/sort_three.c \
		src/sort/sort_small.c \
		src/sort/radix_sort.c \
		src/sort/sort_dispatch.c

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
