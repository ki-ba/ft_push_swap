/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:59:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/28 15:03:41 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_buckets(t_list *buckets[])
{
	int i = 0;

	while (i < RADIX * 2)
	{
		ft_printf("%d : ", i - RADIX - 1);
		ft_print_list(&buckets[i]);
		++i;
	}
}

// TODO : REMOVE
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        ft_printf("%d", binaryNum[j]);
}

void ft_print_bucket(t_list **bucket)
{
	t_list *current;
	t_list node;
	int		number;
	current = *bucket;

	while (current)
	{
		node = *(t_list *)(current->content);
		number = *(int *)node.content;
		ft_printf("%d -> ", number);
		current = current->next;
	}
	ft_printf("NULL\n");
}
int	ft_get_sd_from_node(t_list *list, int pos)
{
	int	cur_pos;
	int	number;

	cur_pos = 0;
	number = *(int *)(list->content);
	while (cur_pos < pos)
	{
		number /= RADIX;
		++cur_pos;
	}
	return ((number % RADIX));
}

int ft_get_nth_bit(t_list *list, int pos)
{
	int number;
	int bit;

	number = *(int *)(list->content);
	bit = (number>>pos)&1;
	return (bit);

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
	while (number < -(RADIX - 1) || number > (RADIX - 1))
	{
		number /= RADIX;
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

void ft_clean_exit(t_list **list_from, t_list **list_to, t_list **bucket)
{
	if (bucket)
		ft_lstclear(bucket, NULL);
	ft_lstclear(list_from, free);
	ft_lstclear(list_to, free);
	exit(EXIT_FAILURE);
}
void	ft_print_lists_status(t_list **list_a, t_list **list_b)
{
	ft_printf("\n\n- - - - - - - - - -\n\nA : ");
	ft_print_list_bin(list_a);
	ft_printf("B : ");
	ft_print_list_bin(list_b);
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

int ft_populate_1bucket(t_list **bucket, t_list **list, int current_digit_position)
{
	t_list *current;
	int bit;

	current = *list;
	while (current)
	{
		bit = ft_get_nth_bit(current, current_digit_position);
		if (bit == 0)
		{
			ft_lstadd_front(bucket, ft_lstnew(current));
			if ((*bucket)->content != current)
				return (1);
		}
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
	while (current_digit_position <= max_digit_position)
	{
		if ((*(int *)(*list_a)->content >> current_digit_position) & 1)
			ft_push_list(list_a, list_b, 'b');
		ft_rotate_list(list_a, 'a');
		++current_digit_position;
	}
	ft_empty_list(list_b, list_a, 'a');
	return (is_sorted(list_a));
}
