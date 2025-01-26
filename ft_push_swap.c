/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:36 by kbarru            #+#    #+#             */
/*   Updated: 2025/01/26 21:29:10 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

void fail_parsing(t_list **head)
{
	ft_printf("Error\n");
	ft_clean_exit(head, NULL, NULL);
}
int	ft_add_to_list(t_list **head, char *nptr)
{
	int	invert;
	int	*number;

	number = malloc(sizeof(int));
	*number = 0;
	invert = -1;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			invert *= (-1);
		++nptr;
	}
	while (ft_isdigit(*nptr))
	{
		if (*number < INT_MIN / 10 || (*number == INT_MIN / 10 && (*nptr
					- '0') > -(INT_MIN % 10)))
			fail_parsing(head);
		*number = (*number * 10) - (*nptr - '0');
		++nptr;
	}
	if (*number == INT_MIN && invert == -1)
		fail_parsing(head);
	*number = invert * (*number);
	if (get_node_by_value(*head, *number))
		fail_parsing(head);
	ft_lstadd_back(head, ft_lstnew(number));
	return (invert * (int)(*number));
}
int ft_is_int(char *nbr)
{
	size_t	i;

	i = 0;
	if (ft_issign(nbr[i]))
		++i;
	while(nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		++i;
	}
	return (1);
}
void	check_input(char **input)
{
	size_t	i;

	i = 1;
	while (input[i])
	{
		if (!ft_is_int(input[i]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		++i;
	}
}
int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	int	i;

	i = 1;
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (1);
	check_input(argv);
	while (i < argc)
	{
		ft_add_to_list(&list_a, argv[i]);
		++i;
	}
	int success = ft_radix_sort(&list_a, &list_b);
	(void)success;
	// if (success)
	// 	ft_printf("\n\n\033[0;32mSORT SUCCESSFUL : \033[0m\n");
	// else
	// 	ft_printf("\033[0;31mSORT FAILED : \033[0m\n");
	// ft_print_lists_status(&list_a, &list_b);
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
}
