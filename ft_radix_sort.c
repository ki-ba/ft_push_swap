/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:59:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/26 21:29:47 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_buckets(t_list *buckets[])
{
	size_t i = 0;

	while (i < 20)
	{
		ft_printf("%d : ", i - 9);
		ft_print_list(&buckets[i]);
		++i;
	}
}
int	ft_get_sd_from_node(t_list *list, int pos)
{
	int	cur_pos;
	int	number;

	cur_pos = 0;
	number = *(int *)(list->content);
	while (cur_pos < pos)
	{
		number /= 10;
		++cur_pos;
	}
	return ((number % 10));
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

void	ft_empty_list(t_list **list_from, t_list **list_to, char list_to_id)
{
	while (*list_from)
		ft_push_list(list_from, list_to, list_to_id);
}

void	ft_rev_empty_list(t_list **list_from, t_list **list_to, char list_from_id, char list_to_id)
{
	while (*list_from)
	{
		ft_rev_rotate_list(list_from, list_from_id);
		ft_push_list(list_from, list_to, list_to_id);
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
// FIXME : infinite loop if node is not in list
void	ft_rev_rotate_to(t_list **list, t_list *node, char list_id)
{
	int i = 0;
	while (*list != node && i++ < 700)
		ft_rev_rotate_list(list, list_id);
}
 // FIXME : infinite loop if node is not in list
void	ft_rotate_to(t_list **list, t_list *node, char list_id)
{
	int i = 0;
	while (*list != node && i++ < 700)
		ft_rotate_list(list, list_id);
}

void ft_clean_exit(t_list **list_from, t_list **list_to, t_list *buckets[])
{
	int	i;

	if (buckets)
	{
		i = -1;
		while (i < 9)
			ft_lstclear(&buckets[++i], NULL);
	}
	ft_lstclear(list_from, free);
	ft_lstclear(list_to, free);
	exit(EXIT_FAILURE);
}
void	ft_print_lists_status(t_list **list_a, t_list **list_b)
{
	ft_printf("\n\n- - - - - - - - - -\n\nA : ");
	ft_print_list(list_a);
	ft_printf("B : ");
	ft_print_list(list_b);
	ft_printf("\n\n- - - - - - - - - -\n\n");
}


void ft_put_on_top(t_list **list, t_list *node, char list_id)
{
	size_t	i;
	t_list	*current;

	i = 0;
	current = *list;
	while (current && current != node)
	{
		++i;
		current = current->next;
	}
	while (current && i > 0)
	{
		--i;
		current = current->next;
	}
	if (i > 0)
		ft_rev_rotate_to(list, node->content, list_id);
	else
		ft_rotate_to(list, node->content, list_id);
}
int ft_populate_buckets(t_list *buckets[], t_list **list, int current_digit_position)
{
	t_list *current;
	int		digit;

	digit = 0;
	while (digit < 19)
	{
		buckets[digit] = NULL;
		++digit;
	}
	current = *list;

	while (current)
	{
		digit = ft_get_sd_from_node(current, current_digit_position);
		ft_lstadd_front(&buckets[digit + 9], ft_lstnew(current));
		if (buckets[digit + 9]->content != current)
			return (1);
		current = current->next;
	}
	return (0);
}

int ft_radix_sort(t_list **list_a, t_list **list_b)
{
	int	current_digit_position;
	int	max_digit_position;

	max_digit_position = ft_get_max_sd_position(list_a);
	current_digit_position = 0;
	while (current_digit_position < max_digit_position)
	{
		if (*list_a)
			ft_radix_pass(list_a, list_b, current_digit_position, 'a', 'b');
		else if (*list_b)
			ft_radix_pass(list_b, list_a, current_digit_position, 'b', 'a');
		++current_digit_position;
	}
	if (*list_b && is_sorted(list_b))
		ft_rev_empty_list(list_b, list_a, 'b', 'a');
	else if (*list_b)
		ft_empty_list(list_b, list_a, 'a');
	return (is_sorted(list_a));
}

void ft_radix_pass(t_list **list_from, t_list **list_to, int pos, char from_char, char to_char)
{
	t_list	*buckets[19];
	t_list	*current;
	int		errno;
	int		i;
	errno = ft_populate_buckets(buckets, list_from, pos);
	if (errno)
		ft_clean_exit(list_from, list_to, buckets);
	i = 9;
	while (i >= -9)
	{
		current = buckets[i + 9];
		while (current)
		{
			ft_put_on_top(list_from, current, from_char);
			ft_push_list(list_from, list_to, to_char);
			current = current->next;
		}
		ft_lstclear(&buckets[i + 9], NULL);
		--i;
	}
}
