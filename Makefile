NAME = push_swap
CC = cc
FLAGS = -Werror -Wall -Wextra -g

P_LIB = libft/
P_OBJ = .obj/
SRC = ft_lst_utils.c ft_push_swap.c ft_sorting_utils.c ft_sorting_operations.c ft_radix_sort.c
OBJ = $(addprefix $(P_OBJ), $(SRC:%.c=%.o))

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(P_LIB)libft.a
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(P_OBJ)%.o: %.c | $(P_OBJ)
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
