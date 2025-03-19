/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:03:20 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/19 12:49:53 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	sort_two(t_stack **stack, char stack_id)
{
	if (ft_stack_size(*stack) != 2)
		return (1);
	if (!is_sorted(stack))
		ft_rotate_stack(stack, stack_id);
	return (1);
}

int	sort_three(t_stack **stack, char stack_id)
{
	int	biggest_pos;

	biggest_pos = get_highest_number_index(*stack);
	if (ft_stack_size(*stack) != 3)
		return (1);
	if (biggest_pos == 0)
		ft_rotate_stack(stack, stack_id);
	else if (biggest_pos == 1)
		ft_rev_rotate_stack(stack, stack_id);
	if (!is_sorted(stack))
		ft_swap_stack(stack, stack_id);
	return (is_sorted(stack));
}
