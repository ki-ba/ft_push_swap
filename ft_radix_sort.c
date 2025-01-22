/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:59:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/22 15:29:39 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_sd_from_node(t_list *list, int pos)
{
	int	cur_pos;
	int	number;

	// int is_neg;
	cur_pos = 0;
	number = *(int *)(list->content);
	// is_neg = (-1) * (number < 0);
	while (cur_pos < pos)
	{
		number /= 10;
		++cur_pos;
	}
	return (number % 10);
}

int	ft_nb_nodes_with_sd(t_list **head, int sd, int sd_position)
{
	t_list	*current;
	int		number;

	number = 0;
	current = *head;
	while (current)
	{
		if (ft_get_sd_from_node(current, sd_position) == sd)
		{
			++number;
		}
		current = current->next;
	}
	return (number);
}

void	ft_empty_b_in_a(t_list **list_from, t_list **list_to)
{
	while (*list_from)
	{
		ft_push_list(list_from, list_to, "pa\n");
	}
}

void	ft_rev_empty_b_in_a(t_list **list_from, t_list **list_to)
{
	while (*list_from)
	{
		ft_rev_rotate_list(list_from, "rrb\n");
		ft_push_list(list_from, list_to, "pa\n");
	}
}

int	ft_get_number_of_digits(t_list *list)
{
	int	number;
	int	number_of_digits;

	number_of_digits = 1;
	number = *(int *)(list->content);
	while (number < -9 || number > 9)
	{
		number /= 10;
		++number_of_digits;
	}
	return (number_of_digits);
}

int	ft_get_max_sd_position(t_list **list_a)
{
	t_list	*current;
	int		max_number_of_digits;
	int		number_of_digits;

	max_number_of_digits = 0;
	current = *list_a;
	while (current)
	{
		number_of_digits = ft_get_number_of_digits(current);
		if (number_of_digits > max_number_of_digits)
			max_number_of_digits = number_of_digits;
		current = current->next;
	}
	return (max_number_of_digits);
}

void	rev_rotate_to(t_list **list, t_list *node)
{
	while (*list != node)
		ft_rev_rotate_list(list, "rra");
}

void	ft_radix_pass_a_to_b(t_list **list_from, t_list **list_to,
		int current_sd_position)
{
	int		current_sd;
	t_list	*real_top_element;
	t_list	*real_bottom_element;

	real_top_element = *list_from;
	real_bottom_element = ft_lstlast(*list_from);
	current_sd = 9;
	while (current_sd >= -9)
	{
		while (ft_nb_nodes_with_sd(list_from, current_sd,
				current_sd_position) > 0)
		{
			ft_rev_rotate_list(list_from, "rra\n");
			if (ft_get_sd_from_node(*list_from,
					current_sd_position) == current_sd)
			{
				if (*list_from == real_top_element)
					real_top_element = real_top_element->next;
				ft_push_list(list_from, list_to, "pb\n");
			}
		}
		while (*list_from && *list_from != real_top_element)
			ft_rev_rotate_list(list_from, "rra\n");
		--current_sd;
	}
}

void	ft_radix_pass_b_to_a(t_list **list_from, t_list **list_to,
		int current_sd_position)
{
	int		current_sd;
	t_list	*real_top_element;
	t_list	*real_bottom_element;

	real_top_element = *list_from;
	real_bottom_element = ft_lstlast(*list_from);
	current_sd = 9;
	while (current_sd >= -9)
	{
		while (ft_nb_nodes_with_sd(list_from, current_sd,
				current_sd_position) > 0)
		{
			ft_rev_rotate_list(list_from, "rrb\n");
			if (ft_get_sd_from_node(*list_from,
					current_sd_position) == current_sd)
			{
				if (*list_from == real_top_element)
					real_top_element = real_top_element->next;
				ft_push_list(list_from, list_to, "pa\n");
			}
		}
		while (*list_from && *list_from != real_top_element)
			ft_rev_rotate_list(list_from, "rrb\n");
		--current_sd;
	}
}

void	ft_print_lists_status(t_list **list_a, t_list **list_b)
{
	ft_printf("\n\n- - - - - - - - - -\n\nA : ");
	ft_print_list(list_a);
	ft_printf("B : ");
	ft_print_list(list_b);
	ft_printf("\n\n- - - - - - - - - -\n\n");
}

int	ft_radix_sort(t_list **list_a, t_list **list_b)
{
	int	current_sd_position;
	int	max_sd_position;

	max_sd_position = ft_get_max_sd_position(list_a);
	current_sd_position = 0;
	while ((current_sd_position <= max_sd_position) && !(*list_a
			&& is_sorted(list_a) && !(*list_b)) && !((*list_a) && is_sorted_rotated(list_a)))
	{
		if (*list_a)
			ft_radix_pass_a_to_b(list_a, list_b, current_sd_position);
		else if (*list_b)
			ft_radix_pass_b_to_a(list_b, list_a, current_sd_position);
		++current_sd_position;
	}
	if (*list_a && is_sorted_rotated(list_a))
	{
		while (*list_a && !is_sorted(list_a))
		{
			ft_rotate_list(list_a, "ra\n");
			ft_print_list(list_a);
		}
	}
	return (is_sorted(list_a));
}
