NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -Wall -Wextra -g
P_LIB = libft/
P_OBJ = .obj/
P_SRC = src/
HEADERS = $(P_SRC)ft_push_swap.h
SRC = ft_small_sort.c ft_dumb_sort.c ft_stack_utils.c ft_push_swap.c ft_sorting_utils.c ft_sorting_operations.c \
ft_parse_input.c ft_radix_sort.c ft_stack.c ft_simplify_stack.c

OBJ = $(addprefix $(P_OBJ), $(SRC:%.c=%.o))

.PHONY = all clean fclean re lib

all: lib $(NAME)

$(NAME): $(OBJ) $(P_LIB)libft.a
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(P_OBJ)%.o: $(P_SRC)%.c Makefile $(HEADERS) | $(P_OBJ)
	$(CC) $(FLAGS) -I libft -c $< -o $@

$(P_OBJ):
	mkdir -p $(P_OBJ)

lib:
	$(MAKE) -C $(P_LIB)

clean:
	$(MAKE) clean -C $(P_LIB)
	rm -rf $(P_OBJ)

fclean: clean
	make fclean -C $(P_LIB)
	rm -f $(NAME)

re: clean all


# DEBUG

view: all
	cd push_swap_visualizer/build
	.bin/visualizer

debug:
	make re FLAGS="$(DEBUG_FLAGS)"
	$(MAKE) clean
