/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:36 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/29 13:38:04 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		success;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	check_input(argv);
	while (++i < argc)
		ft_add_to_stack(&stack_a, argv[i]);
	ft_stack_iter(&stack_a, ft_simplify_node);
	success = ft_radix_sort(&stack_a, &stack_b);
	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	return (!success);
}
