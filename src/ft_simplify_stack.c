/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:26:50 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/29 14:26:51 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
	@brief assigns to each node of the stack its simplified value
	@brief using the function given as parameter.
	@param stack the stack to simplify.
	@param f the function used to simplify each node.
*/
void	ft_stack_iter(t_stack **stack, int (*f)(t_stack **, t_stack *))
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		current->simpl_val = f(stack, current);
		current = current->next;
	}
}
/*
	@brief associates to `node` a simple positive value according
	@brief to its index in the (ordered) stack.
	@param stack the stack which the node is in.
	@param node the node to simplify.
	@returns the simplified value.
*/

int	ft_simplify_node(t_stack **stack, t_stack *node)
{
	t_stack	*current;
	int		count;

	count = 0;
	current = *stack;
	while (current)
	{
		if (node->value > current->value)
			++count;
		current = current->next;
	}
	return (count);
}
