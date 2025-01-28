/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:00:10 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/28 13:28:06 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_create_list(int *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (content)
		lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*lst_last(t_list *list)
{
	t_list	*current;

	current = list;
	while (current->next)
		current = current->next;
	return (current);
}

t_list	*lst_second_to_last(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while ((current->next))
	{
		next = current->next;
		if (!(next->next))
			return (current);
		current = current->next;
	}
	return (current);
}

void	ft_print_list(t_list **head)
{
	t_list	*current;

	if (!head || !(*head))
	{
		ft_printf("[EMPTY LIST]\n");
		return ;
	}
	current = *head;
	while (current->next)
	{
		ft_printf("%d -> ",*(int *)(current->content));
		current = (current->next);
	}
	ft_printf("%d\n", *(int *)(current->content));
}

void	ft_print_list_bin(t_list **head)
{
	t_list	*current;

	if (!head || !(*head))
	{
		ft_printf("[EMPTY LIST]\n");
		return ;
	}
	current = *head;
	while (current->next)
	{
		decToBinary(*(int *)(current->content));
		ft_printf("-> ");
		current = (current->next);
	}
	decToBinary(*(int *)(current->content));
	ft_printf("\n");
}
int get_value(t_list *list)
{
	return (*(int *)list->content);
}

int	ft_get_minimum(t_list **list)
{
	t_list *current;
	int		minimum;

	minimum = 2147483647;
	current = *list;
	while (current)
	{
		if (get_value(current) < minimum)
			minimum = get_value(current);
		current = current->next;
	}
	return (minimum);
}
