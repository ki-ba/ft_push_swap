/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:53:37 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/22 15:07:49 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_highest_number_index(t_list *lst)
{
	int		highest_number_index;
	t_list	*current_node;

	current_node = lst;
	highest_number_index = 0;
	while (current_node)
	{
		if (*(int *)(current_node->content) > *(int *)(get_node_by_index(lst,
					highest_number_index)->content))
		{
			highest_number_index = get_node_index(lst, current_node);
		}
		current_node = current_node->next;
	}
	return (highest_number_index);
}

t_list	*get_node_by_index(t_list *lst, int index)
{
	int		i;
	t_list	*current_node;

	current_node = lst;
	i = 0;
	while (current_node->next && i < index)
	{
		current_node = current_node->next;
		++i;
	}
	return (current_node);
}

int	get_node_index(t_list *lst, t_list *node)
{
	t_list	*current_node;
	int		index;

	current_node = lst;
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

t_list	*get_node_by_value(t_list *lst, int number)
{
	int		i;
	t_list	*current_node;

	current_node = lst;
	i = 0;
	while (current_node )
	{
        if (*(int *)(current_node->content) == number)
            return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

int is_sorted(t_list **lst)
{
	t_list	*current;
	int		last_number;
	current = *lst;

	last_number = *(int *)current->content;
	current = current->next;
	while (current)
	{
		if (*(int *)current->content <= last_number)
			return (0);
		last_number = *(int *)current->content;
		current = current->next;
	}
	return (1);
}

int	is_sorted_rotated(t_list **list)
{
	t_list *current;
	int		minimum;
	int		last;

	minimum = ft_get_minimum(list);
	current = *list;
	last = get_value(current);
	current = current->next;
	while (current)
	{
		if (get_value(current) <= last && get_value(current) != minimum)
			return (0);
		last = get_value(current);
		current = current->next;
	}
	return (1);
}
