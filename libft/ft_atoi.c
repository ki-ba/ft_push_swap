/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:27:11 by kbarru            #+#    #+#             */
/*   Updated: 2025/02/05 13:10:49 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// First, any number of whitespaces
// Then, a single - or + char
// then numbers
// returns the current number on error.
int	ft_isnumber(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_iswhitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	number;
	long	check;

	number = 0;
	sign = 1;
	while (ft_iswhitespace(*nptr))
		++nptr;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign *= (-1);
		++nptr;
	}
	while (ft_isnumber(*nptr))
	{
		check = number;
		number = (number * 10) + (*nptr - 48);
		if (number < check && sign == 1)
			return (-1);
		else if (number < check && sign == -1)
			return (0);
		++nptr;
	}
	return (sign * (int)number);
}

/* #include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{

	if(argc > 1)
	{
		while(--argc)
			printf("ft_atoi : %d\n___atoi : %d\n\n", ft_atoi(argv[argc]),
				atoi(argv[argc]));
	}

	else
	{
		unsigned long long i;
		i = 9223372036854775807;
		while (i < 18446744073709551615llu)
		{
			if (ft_atoi(ft_itoa(i)) != ft_atoi(ft_itoa(i)))
			{
				printf("Error on %llu : %d instead of %d\n", i,
					ft_atoi(ft_itoa(i)), atoi(ft_itoa(i)));
				break ;
			}
			else
			{
				printf("%llu OK\n", i);
			}
			++i;
		}
	}
} */
