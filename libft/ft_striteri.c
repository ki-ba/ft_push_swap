/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:13:24 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 13:00:45 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		++i;
	}
	return (s);
}

/* #include <stdio.h>

// TESTING FUNCTION
static void	xtoupper(unsigned int i, char *c)
{
		(void)i;
		(*c) = ft_toupper(*c);
}
int	main(int argc, char **argv)
{
	(void)argv;
	argc = 2;
	char var[] = "hi\n\n\nhello";
	while(--argc)
	{
		printf("|%s|\n", var);
		printf("|%s|\n", ft_striteri(var, &xtoupper));
	}
} */
