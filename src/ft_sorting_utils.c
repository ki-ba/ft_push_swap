/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:53:37 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/13 09:35:10 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
	@brief returns the index of the node with the highest value.
	@param stack the stack to look in.
	@returns the index of the highest-value node.
*/
int	get_highest_number_index(t_stack *stack)
{
	int		highest_number_index;
	t_stack	*current_node;

	current_node = stack;
	highest_number_index = 0;
	while (current_node)
	{
		if ((current_node->value) > (get_node_by_index(stack,
					highest_number_index)->value))
		{
			highest_number_index = get_node_index(stack, current_node);
		}
		current_node = current_node->next;
	}
	return (highest_number_index);
}

/*
	@brief returns the node with the index given as parameter.
	@param stack the stack to look in.
	@param index the index of the wanted node.
	@returns the index of the highest-value node.
*/
t_stack	*get_node_by_index(t_stack *stack, int index)
{
	int		i;
	t_stack	*current_node;

	current_node = stack;
	i = 0;
	while (current_node->next && i < index)
	{
		current_node = current_node->next;
		++i;
	}
	return (current_node);
}

/*
	@brief returns the 0-index of the node given as parameter.
	@param stack the stack to look in.
	@param node the node to look for.
	@returns the index of `node` in `stack`.
*/
int	get_node_index(t_stack *stack, t_stack *node)
{
	t_stack	*current_node;
	int		index;

	current_node = stack;
	index = 0;
	while (current_node != node)
	{
		if (current_node->next == NULL)
			return (0);
		++index;
		current_node = current_node->next;
	}
	return (index);
}

/*
	@brief returns the first node of the stack with value equal to
	@brief `number`.
	@param stack the stack to look in.
	@param number the wanted value for the node.
	@returns the first node with value `number`.
*/
t_stack	*get_node_by_value(t_stack *stack, int number)
{
	t_stack	*current_node;

	current_node = stack;
	while (current_node)
	{
		if ((current_node->value) == number)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

/*
	@brief returns 1 if `stack` is "sorted", i.e each element
	@brief is _strictly_ inferior to the one after.
	@param stack the stack to inspect.
	@returns 1 if the list is sorted, 0 otherwise.
*/
int	is_sorted(t_stack **stack)
{
	t_stack	*current;
	int		last_number;

	if (!stack ||!(*stack))
		return (1);
	current = *stack;
	last_number = current->value;
	current = current->next;
	while (current)
	{
		if (current->value <= last_number)
			return (0);
		last_number = current->value;
		current = current->next;
	}
	return (1);
}
