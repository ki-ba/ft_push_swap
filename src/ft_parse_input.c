/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:37 by kbarru            #+#    #+#             */
/*   Updated: 2025/02/05 13:24:35 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
	@brief clears all the lists, then exits.
	@param stack_a first stack to clear
	@param stack_b second stack to clear
*/
void	ft_clean_exit(t_stack **stack_a, t_stack **stack_b, char **input,
		char **argv)
{
	ft_printf("Error\n");
	ft_clean_input(input, argv);
	ft_clearstack(stack_a);
	ft_clearstack(stack_b);
	exit(EXIT_FAILURE);
}

/*
*	@brief Converts a number represented as a `char *` to an `int`.
*	@brief If an integer overflow is detected, sets errno to 1.
*	@param nptr the number as a string.
	@param errno
	@returns the provided number as an integer.
*/
int	ft_str_to_int(char *nptr, int *errno)
{
	int	invert;
	int	number;

	number = 0;
	invert = -1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*(nptr++) == '-')
			invert *= (-1);
	}
	while (ft_isdigit(*nptr))
	{
		if (number < INT_MIN / 10 || (number == INT_MIN / 10 && (*nptr - '0')
				> -(INT_MIN % 10)))
			*errno = 1;
		number = (number * 10) - (*nptr - '0');
		++nptr;
	}
	if (number == INT_MIN && invert == -1)
		*errno = 1;
	return (number = invert * (number));
}

/*
 *	@brief Adds a string representing a correct number to a `t_list`.
 *	@brief If the number would overflow the int, or the number already exists
 *	@brief in the list, properly exit.
 *	@param head the list to add the number to.
 */
void	ft_add_to_stack(t_stack **head, char **input, int i, char **argv)
{
	int		errno;
	int		number;
	t_stack	*node;

	errno = 0;
	number = ft_str_to_int(input[i], &errno);
	if (errno || get_node_by_value(*head, number))
		ft_clean_exit(head, NULL, input, argv);
	node = ft_create_node(number);
	ft_stack_add_back(head, node);
	if (ft_stack_last(head) != node)
		ft_clean_exit(head, NULL, input, argv);
}

/*
 *	@brief checks is a string is a sequence of digits preceded by
 *	@brief an optional sign.
 *	@param nbr the string to verify.
 *	@returns 1 if the string represents a number, 0 if not.
 */
int	ft_is_number(char *nbr)
{
	size_t	i;

	i = 0;
	if (!nbr || !(nbr[0]))
		return (1);
	if (ft_issign(nbr[0]))
		++i;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		++i;
	}
	return (!(i == 0) && !(ft_issign(nbr[0]) && i == 1));
}

/*
 * @brief checks if every argument is a number. If not, prints Error and exits.
 * @param input the array of arguments.
 */
void	check_input(char **input, char **argv)
{
	size_t	i;

	i = -1;
	if (!input || !(*input))
		ft_clean_exit(NULL, NULL, input, argv);
	while (input[++i])
		if (!ft_is_number(input[i]))
			ft_clean_exit(NULL, NULL, input, argv);
}
