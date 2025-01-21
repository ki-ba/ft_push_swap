/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:59:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/21 16:57:50 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


int ft_get_sd_from_node(t_list *list, int pos)
{
	int cur_pos;
	int number;
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

int ft_nb_nodes_with_sd(t_list **head, int sd, int sd_position)
{
	t_list *current;
	int number;

	number = 0;
	current = *head;
	while (current)
	{
		if(ft_get_sd_from_node(current, sd_position) == sd)
		{
			++number;
		}
		current = current->next;
	}
	return (number);
}

void ft_empty_b_in_a(t_list **list_from, t_list **list_to)
{

	while (*list_from)
	{
		ft_push_list(list_from, list_to, "pb\n");
	}
}

int ft_get_number_of_digits(t_list *list)
{
	int number;
	int number_of_digits;

	number_of_digits = 0;
	number = *(int *)(list->content);
	while (number < -9 || number > 9)
	{
		number /= 10;
		++number_of_digits;
	}
	return number_of_digits;
}

int ft_get_max_sd_position(t_list **list_a)
{
	t_list *current;
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
	return max_number_of_digits;
}

void	ft_radix_sort(t_list **list_a, t_list **list_b)
{
	int current_sd;
	int current_sd_position;
	int nb_nodes_with_sd;
	int	max_sd_position;

	max_sd_position = ft_get_max_sd_position(list_a);
	current_sd_position = 0;
	while(current_sd_position < max_sd_position)
	{
		current_sd = -9;
		while (current_sd <= 9)
		{
			nb_nodes_with_sd = ft_nb_nodes_with_sd(list_a, current_sd, current_sd_position);
			while (nb_nodes_with_sd > 0)
			{
				while (ft_get_sd_from_node(*list_a, current_sd_position) != current_sd)
				{
					ft_rev_rotate_list(list_a, "rra\n");
				}
				ft_push_list(list_a, list_b, "pa\n");
				nb_nodes_with_sd = ft_nb_nodes_with_sd(list_a, current_sd, current_sd_position);
			}
			++current_sd;
		}
		++current_sd_position;
		ft_empty_b_in_a(list_b, list_a);
	}
}
