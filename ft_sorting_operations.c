/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:26:48 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/21 08:27:25 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	**ft_switch_list(t_list **head, char *order)
{
	t_list	*first_element;
	t_list	*second_element;

	first_element = *head;
	second_element = first_element->next;
	first_element->next = second_element->next;
	second_element->next = first_element;
	*head = second_element;
	return (head);
	if (ft_strlen(order))
		ft_printf("%s", order);
}

void	ft_push_list(t_list **head_from, t_list **head_to, char *order)
{
	t_list	*new_head_from;
	t_list	*new_list;

	new_head_from = (*head_from)->next;
	if (!*head_to)
	{
		new_list = ft_lstnew((*head_from)->content);
		(*head_to) = new_list;
		(*head_to)->next = NULL;
	}
	else
		ft_lstadd_front(head_to, *head_from);
	*head_from = new_head_from;
	if (ft_strlen(order))
		ft_printf("%s", order);
}

void	ft_rev_rotate_list(t_list **head, char *order)
{
	t_list	*last;
	t_list	*old_first;
	t_list	*second_to_last;

	last = ft_lstlast(*head);
	second_to_last = lst_second_to_last(*head);
	second_to_last->next = NULL;
	lst_second_to_last(*head);
	old_first = *head;
	*head = last;
	last->next = old_first;
	if (ft_strlen(order))
		ft_printf("%s", order);
}

void	ft_rotate_list(t_list **head, char *order)
{
	t_list	*second_element;
	t_list	*second_to_last;
	t_list	*last_element;

	last_element = lst_last(*head);
	second_element = (*head)->next;
	second_to_last = lst_second_to_last(*head);
	last_element->next = (*head);
	(*head)->next = NULL;
	*head = second_element;
	if (ft_strlen(order))
		ft_printf("%s", order);
}
