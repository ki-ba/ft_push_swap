/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:36 by kbarru            #+#    #+#             */
/*   Updated: 2025/02/02 12:41:11 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;
	int		success;
	int		i;

	i = (argc != 2);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (argc != 2)
		input = argv;
	else
		input = ft_split((const char *)argv[1], ' ');
	check_input(input);
	while (input[i] && input[i] != argv[0])
	{
		ft_add_to_stack(&stack_a, input[i]);
		++i;
	}
	// ft_print_stack(&stack_a);
	ft_stack_iter(&stack_a, ft_simplify_node);
	success = ft_radix_sort(&stack_a, &stack_b);
	// ft_print_stack(&stack_a);
	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	return (!success);
}
