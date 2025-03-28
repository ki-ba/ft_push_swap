/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:26:48 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/13 17:31:33 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
	@brief rotate a: ake the first element at the top of `head_from`
	@brief and put it at the top of `head_to`.
	@param head_from the stack to push from.
	@param head_to the stack to push to.
	@param stack_id the name of the stack to push to ('a' or 'b').
*/
void	ft_push_stack(t_stack **head_from, t_stack **head_to, char stack_id)
{
	t_stack	*new_head_from;

	new_head_from = (*head_from)->next;
	if (!*head_to)
	{
		*head_to = *head_from;
		(*head_to)->next = NULL;
	}
	else
		ft_stack_add_front(head_to, *head_from);
	*head_from = new_head_from;
	ft_printf("p%c\n", stack_id);
}

/*
	@brief rotate a: Shift up all elements of stack a by 1.
	@brief The first element becomes the last one.
	@param head the stack to rotate.
	@param the name of the stack to rotate ('a' or 'b').
*/
void	ft_rotate_stack(t_stack **head, char stack_id)
{
	t_stack	*second_element;
	t_stack	*last_element;

	if (!(*head))
		return ;
	last_element = lst_last(*head);
	second_element = (*head)->next;
	if (last_element == *head)
		return ;
	last_element->next = (*head);
	(*head)->next = NULL;
	*head = second_element;
	ft_printf("r%c\n", stack_id);
}

void	ft_rev_rotate_stack(t_stack **head, char stack_id)
{
	t_stack	*last_element;
	t_stack	*second_to_last;

	if (!(*head) || ft_stack_size(*head) < 2)
		return ;
	last_element = lst_last(*head);
	second_to_last = ft_second_to_last(head);
	last_element->next = (*head);
	second_to_last->next = NULL;
	*head = last_element;
	ft_printf("rr%c\n", stack_id);
}

void	ft_swap_stack(t_stack **head, char stack_id)
{
	t_stack	*second_element;

	if (!head || ft_stack_size(*head) < 2)
		return ;
	second_element = (*head)->next;
	if (!second_element)
		return ;
	(*head)->next = second_element->next;
	second_element->next = *head;
	*head = second_element;
	ft_printf("s%c\n", stack_id);
}
