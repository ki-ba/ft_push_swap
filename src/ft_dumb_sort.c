/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumb_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:49:41 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/19 12:50:27 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_lowest_number_index(t_stack *stack)
{
	int		lowest_number_index;
	t_stack	*current_node;

	current_node = stack;
	lowest_number_index = 0;
	while (current_node)
	{
		if ((current_node->value) < (get_node_by_index(stack,
					lowest_number_index)->value))
		{
			lowest_number_index = get_node_index(stack, current_node);
		}
		current_node = current_node->next;
	}
	return (lowest_number_index);
}

void	ft_put_on_top(t_stack **stack, int val, char stack_id)
{
	int	size;

	size = ft_stack_size(*stack);
	if (get_node_index(*stack, get_node_by_value(*stack, val)) >= size - 2)
	{
		while ((*stack)->simpl_val != val)
			ft_rev_rotate_stack(stack, stack_id);
	}
	else
	{
		while ((*stack)->simpl_val != val)
			ft_rotate_stack(stack, stack_id);
	}
}

void	ft_push_lowest_two(t_stack **stack_from, t_stack **stack_to,
		char stack_id_from, char stack_id_to)
{
	ft_put_on_top(stack_from, get_node_by_index(*stack_from,
			get_lowest_number_index(*stack_from))->simpl_val, stack_id_from);
	ft_push_stack(stack_from, stack_to, stack_id_to);
	ft_put_on_top(stack_from, get_node_by_index(*stack_from,
			get_lowest_number_index(*stack_from))->simpl_val, stack_id_from);
	ft_push_stack(stack_from, stack_to, stack_id_to);
}

int	dumb_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	initial_stack_size;

	if (is_sorted(stack_a))
		return (1);
	initial_stack_size = ft_stack_size(*stack_a);
	if (initial_stack_size == 2)
		return (sort_two(stack_a, 'a'));
	else if (initial_stack_size == 3)
		return (sort_three(stack_a, 'a'));
	else
	{
		ft_push_lowest_two(stack_a, stack_b, 'a', 'b');
		if (ft_stack_size(*stack_a) == 2)
			sort_two(stack_a, 'a');
		else if (ft_stack_size(*stack_a) == 3)
			sort_three(stack_a, 'a');
		ft_push_stack(stack_b, stack_a, 'a');
		ft_push_stack(stack_b, stack_a, 'a');
		return (is_sorted(stack_a));
	}
	return (is_sorted(stack_a));
}
