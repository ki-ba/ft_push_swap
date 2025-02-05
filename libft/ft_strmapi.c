/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:52:42 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 13:10:31 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s2;

	if (!s)
		return (0);
	i = 0;
	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i < ft_strlen(s))
	{
		s2[i] = f(i, s[i]);
		++i;
	}
	s2[i] = '\0';
	return (s2);
}

/* #include <stdio.h>

// TESTING FUNCTION
static char	xtoupper(unsigned int i, char c)
{
	(void)i;
	return (c - 32);
}
int	main(int argc, char **argv)
{
	while(--argc)
		printf("|%s:%s|\n", argv[argc], ft_strmapi(argv[argc], &xtoupper));
} */
