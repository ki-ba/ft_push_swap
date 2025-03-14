/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:25 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/14 12:04:41 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define RADIX 2

# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				simpl_val;
}					t_stack;

/* ft_push_swap.c */

void				ft_clean_input(char **input, char **argv);

/* ft_parse_input.c */

void				ft_clean_exit(t_stack **stack_a, t_stack **stack_b,
						char **input, char **argv);
int					ft_str_to_int(char *nptr, int *errno);
void				ft_add_to_stack(t_stack **head, char **input, int i,
						char **argv);
int					ft_is_number(char *nbr);
void				check_input(char **input, char **argv);

/* ft_radix_sort.c */

void				ft_empty_stack(t_stack **stack_from, t_stack **stack_to,
						char stack_to_id);
int					ft_get_number_of_digits(t_stack *stack);
int					ft_get_max_sd_position(t_stack **stack_a);
int					ft_radix_sort(t_stack **stack_a, t_stack **stack_b);

/* ft_simplify_stack.c */
void				ft_stack_iter(t_stack **stack, int (*f)(t_stack **,
							t_stack *));
int					ft_simplify_node(t_stack **stack, t_stack *node);

/* ft_sorting_operations.c */
void				ft_push_stack(t_stack **head_from, t_stack **head_to,
						char stack_id);
void				ft_rotate_stack(t_stack **head, char stack_id);
void				ft_rev_rotate_stack(t_stack **head, char stack_id);
void				ft_swap_stack(t_stack **head, char stack_id);

/* ft_sorting_utils.c */
int					get_highest_number_index(t_stack *stack);
t_stack				*get_node_by_index(t_stack *stack, int index);
int					get_node_index(t_stack *stack, t_stack *node);
t_stack				*get_node_by_value(t_stack *stack, int number);
int					is_sorted(t_stack **stack);
void				ft_print_simpl_stack(t_stack **head, char stack_id);

/* ft_stack_utils.c */
t_stack				*lst_last(t_stack *stack);
t_stack				*ft_second_to_last(t_stack **stack);
void				ft_print_stack(t_stack **head, char stack_id);
int					ft_stack_size(t_stack *stack);

/* ft_stack.c */
void				ft_clearstack(t_stack **stack);
t_stack				*ft_create_node(int value);
t_stack				*ft_stack_last(t_stack **stack);
void				ft_stack_add_front(t_stack **stack, t_stack *new);
void				ft_stack_add_back(t_stack **stack, t_stack *new);

/* ft_dumb_sort.c */
int					sort_two(t_stack **stack, char stack_id);
int					sort_three(t_stack **stack, char stack_id);
int					dumb_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_put_on_top(t_stack **stack, int i, char stack_id);

/* ft_small_sort.c */
int					sort_two(t_stack **stack, char stack_id);
int					sort_three(t_stack **stack, char stack_id);
#endif
