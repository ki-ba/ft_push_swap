/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:36 by kbarru            #+#    #+#             */
/*   Updated: 2025/03/13 17:36:15 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_clean_input(char **input, char **argv)
{
	int	i;

	i = -1;
	if (input == argv)
		return ;
	while (input[++i])
		free(input[i]);
	free(input);
}

void	set_up_input(char ***input, int argc, char **argv)
{
	if (argc != 2)
		*input = argv;
	else
		*input = ft_split((const char *)argv[1], ' ');
}

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
	set_up_input(&input, argc, argv);
	check_input(input, argv);
	while (input[i] && input[i] != argv[0])
		ft_add_to_stack(&stack_a, input, (i++), argv);
	ft_stack_iter(&stack_a, ft_simplify_node);
	ft_clean_input(input, argv);
	if (ft_stack_size(stack_a) <= 5)
		success = dumb_sort(&stack_a, &stack_b);
	else
		success = ft_radix_sort(&stack_a, &stack_b);
	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	return (!success);
}
