/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:25 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/29 14:53:08 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define RADIX 2

# include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				simpl_val;
}	t_stack;

// FT_PARSE_INPUT

void	ft_clean_exit(t_stack **stack_a, t_stack **stack_b);
int		ft_str_to_int(char *nptr, int *errno);
void	ft_add_to_stack(t_stack **head, char *nptr);
int		ft_is_number(char *nbr);
void	check_input(char **input);

// FT_RADIX_SORT

void	ft_empty_stack(t_stack **stack_from, t_stack **stack_to,
			char stack_to_id);
int		ft_get_number_of_digits(t_stack *stack);
int		ft_get_max_sd_position(t_stack **stack_a);
int		ft_radix_sort(t_stack **stack_a, t_stack **stack_b);

// SIMPLIFY STACK

void	ft_stack_iter(t_stack **stack, int (*f)(t_stack **, t_stack *));
int		ft_simplify_node(t_stack **stack, t_stack *node);

// SORTING BASIC OPERATIONS

void	ft_push_stack(t_stack **head_from, t_stack **head_to, char stack_id);
void	ft_rotate_stack(t_stack **head, char stack_id);

// SORTING_UTILS.C
int		get_highest_number_index(t_stack *stack);
t_stack	*get_node_by_index(t_stack *stack, int index);
int		get_node_index(t_stack *stack, t_stack *node);
t_stack	*get_node_by_value(t_stack *stack, int number);
int		is_sorted(t_stack **stack);

// STACK UTILS

t_stack	*lst_last(t_stack *stack);
t_stack	*ft_second_to_last(t_stack **stack);
void	ft_print_stack(t_stack **head);
int		ft_stack_size(t_stack *stack);

// STACK

void	ft_clearstack(t_stack **stack);
t_stack	*ft_create_node(int value);
t_stack	*ft_stack_last(t_stack **stack);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stack_add_back(t_stack **stack, t_stack *new);

#endif
