/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:10 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/13 17:31:59 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
	@brief returns the last node of the stack given as parameter.
	@param stack the stack to draw the node from.
	@returns the last node of the stack.
*/
t_stack	*lst_last(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

/*
	@brief returns the penultimate (!) node of the stack given as parameter.
	@param stack the stack to draw the node from.
	@returns the second node of the stack, starting from the end.
*/
t_stack	*ft_second_to_last(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while ((current->next))
	{
		next = current->next;
		if (!(next->next))
			return (current);
		current = current->next;
	}
	return (current);
}

/*
	@debugging function. Used to print a stack.
	@param head the stack to print.
*/
void	ft_print_stack(t_stack **head, char stack_id)
{
	t_stack	*current;

	ft_printf("%c : ", stack_id);
	if (!head || !(*head))
	{
		ft_printf("[EMPTY STACK]\n");
		return ;
	}
	current = *head;
	while (current)
	{
		ft_printf("%d -> ", (current->value));
		current = (current->next);
	}
	ft_printf("NULL\n");
}

void	ft_print_simpl_stack(t_stack **head, char stack_id)
{
	t_stack	*current;

	ft_printf("%c : ", stack_id);
	if (!head || !(*head))
	{
		ft_printf("[EMPTY STACK]\n");
		return ;
	}
	current = *head;
	while (current)
	{
		ft_printf("%d -> ", (current->simpl_val));
		current = (current->next);
	}
	ft_printf("NULL\n");
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}
