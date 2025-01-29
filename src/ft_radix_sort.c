/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:59:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/29 14:46:50 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_empty_stack(t_stack **stack_from, t_stack **stack_to,
		char stack_to_id)
{
	while (*stack_from)
		ft_push_stack(stack_from, stack_to, stack_to_id);
}

int	ft_get_number_of_digits(t_stack *stack)
{
	int	number;
	int	number_of_digits;

	number_of_digits = 1;
	number = (stack->simpl_val);
	while (number < -(RADIX - 1) || number > (RADIX - 1))
	{
		number /= RADIX;
		++number_of_digits;
	}
	return (number_of_digits);
}

int	ft_get_max_sd_position(t_stack **stack_a)
{
	t_stack	*current;
	int		max_number_of_digits;
	int		number_of_digits;

	max_number_of_digits = 0;
	current = *stack_a;
	while (current)
	{
		number_of_digits = ft_get_number_of_digits(current);
		if (number_of_digits > max_number_of_digits)
			max_number_of_digits = number_of_digits;
		current = current->next;
	}
	return (max_number_of_digits);
}

int	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	current_digit_position;
	int	max_digit_position;
	int	stack_initial_size;
	int	i;

	if (is_sorted(stack_a))
		return (1);
	stack_initial_size = ft_stack_size(*stack_a);
	max_digit_position = ft_get_max_sd_position(stack_a);
	current_digit_position = 0;
	while (current_digit_position < max_digit_position)
	{
		i = 0;
		while (i++ < stack_initial_size)
		{
			if ((((*stack_a)->simpl_val) >> current_digit_position) & 1)
				ft_rotate_stack(stack_a, 'a');
			else
				ft_push_stack(stack_a, stack_b, 'b');
		}
		ft_empty_stack(stack_b, stack_a, 'a');
		++current_digit_position;
	}
	return (is_sorted(stack_a));
}
