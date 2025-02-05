/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:55:41 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/08 18:20:55 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (1);
		else if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
			return (-1);
		++i;
	}
	return (0);
}
/* #include <string.h>
#include <stdio.h>

int	main(void)
{

	printf("%d %d %d %d\n",
	ft_memcmp("hello world", "hello world",10),
	ft_memcmp("hello", "hell",4),
	ft_memcmp("hello", "hell",5),
	ft_memcmp("hello", "hellz",5));
		printf("%d %d %d %d\n",
	memcmp("hello", "hell",2),
	memcmp("hello", "hell",4),
	memcmp("hello", "hell",5),
	memcmp("hello", "hellz",5));
} */
