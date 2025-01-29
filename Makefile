NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -Wall -Wextra -g -fsanitize=address

P_LIB = libft/
P_OBJ = .obj/
SRC = ft_stack_utils.c ft_push_swap.c ft_sorting_utils.c ft_sorting_operations.c \
ft_parse_input.c ft_radix_sort.c ft_stack.c ft_simplify_stack.c

OBJ = $(addprefix $(P_OBJ), $(SRC:%.c=%.o))

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(P_LIB)libft.a
	$(MAKE) -C $(P_LIB)
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(P_OBJ)%.o: %.c
	mkdir -p $(P_OBJ)
	$(CC) $(FLAGS) -I libft -c $< -o $@

$(P_OBJ):
	mkdir $(P_OBJ)

$(P_LIB)libft.a:
	$(MAKE) -C $(P_LIB)

clean:
	$(MAKE) clean -C $(P_LIB)
	rm -rf $(P_OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

# DEBUG

view: all
	cd push_swap_visualizer/build
	.bin/visualizer

debug:
	make re FLAGS="$(DEBUG_FLAGS)"

test: all
	./push_swap 85 78 100 91 -12 -48 53 -13 -26 -8 49 13 32 -11 63 61 -62 56 89 -76 -82 18 -63 70 -100 16 59 29 6 -38 87 -80 50 93 -24 92 83 -96 95 -7 -17 38 14 -5 -94 -34 72 65 25 -29 -27 -9 -22 51 43 46 -20 -83 28 8 79 -86 -45 -1 -89 64 76 19 -39 -81 3 -14 -4 60 24 26 -47 1 -30 10 54 -51 -37 21 22 -85 -54 -74 -60 -95 -55 -57 4 81 -87 34 35 7 45 -52 | ./checker_linux 85 78 100 91 -12 -48 53 -13 -26 -8 49 13 32 -11 63 61 -62 56 89 -76 -82 18 -63 70 -100 16 59 29 6 -38 87 -80 50 93 -24 92 83 -96 95 -7 -17 38 14 -5 -94 -34 72 65 25 -29 -27 -9 -22 51 43 46 -20 -83 28 8 79 -86 -45 -1 -89 64 76 19 -39 -81 3 -14 -4 60 24 26 -47 1 -30 10 54 -51 -37 21 22 -85 -54 -74 -60 -95 -55 -57 4 81 -87 34 35 7 45 -52
