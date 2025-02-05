/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:02 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/17 21:50:13 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h> // size_t
#include <stdlib.h> // malloc

static size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub;

	i = 0;
	if (start > ft_strlen(s))
		size = 1;
	else
		size = (ft_strnlen(s + start, len) + 1);
	sub = malloc(size);
	if (!sub)
		return (0);
	while (i < size - 1)
	{
		sub[i] = s[start + i];
		++i;
	}
	sub[i] = '\0';
	return (sub);
}

/* 
#include <stdio.h>
int	main(void)
{
	char	*s = "01234";
	char	*sub;

	sub = ft_substr("01234", 10, 10);
	printf("%p : '%s'", sub, sub);
} */
