/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:16:46 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/29 14:52:46 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/*
	@brief frees every node of the given stack, then sets `stack` to NULL.
	@param stack the stack to clear.
*/
void	ft_clearstack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		current->next = NULL;
		free(current);
		current = next;
	}
	*stack = NULL;
}

/*
	@brief allocates a `t_stack` of value `value`.
	@param value the value the new node should have.
*/
t_stack	*ft_create_node(int value)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->value = value;
	head->next = NULL;
	return (head);
}

/*
	@brief returns the last node in the stack given as parameter.
	@param the stack to look in.
	@returns the last node of the stack.
*/
t_stack	*ft_stack_last(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (!current)
		return (0);
	while (current->next)
		current = current->next;
	return (current);
}

/*
	@brief adds a node in first position of a stack.
	@param stack the stack to add the node in.
	@param new the node to add.
*/
void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	new->next = *stack;
	*stack = new;
}

/*
	@brief adds a node in last position of a stack.
	@param stack the stack to add the node in.
	@param new the node to add.
*/
void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	last = ft_stack_last(stack);
	if (!last)
		*stack = new;
	else
		last->next = new;
}
