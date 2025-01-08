NAME = push_swap
CC = cc
FLAGS = -Werror -Wall -Wextra

P_LIB = libft/
P_OBJ = .obj/
SRC = ft_lst_utils.c ft_push_swap.c ft_sorting_utils.c

OBJ = $(addprefix $(P_OBJ), $(SRC:%.o=%.c))


all: $(NAME)

$(NAME): lib
	$(CC) $(FLAGS) -Llibft -lft $(SRC)

$(P_OBJ)%.o: %.c | $(P_OBJ)
	$(CC) $(FLAGS)

$(P_OBJ):
	mkdir $(P_OBJ)

lib:
	$(MAKE) -C $(P_LIB)

clean:
	$(MAKE) clean -C $(P_LIB)
	rm -rf $(P_OBJ)/

fclean: clean
	rm -f $(NAME)