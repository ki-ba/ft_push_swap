/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:46:33 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 18:38:11 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(&((unsigned char *)s)[i]));
		++i;
	}
	return (0);
}
/* #include <stdio.h>
int	main(void)
{
	char *string = "Lorem ipsum dolor sit amet";
	char c = 'd';
	size_t n = 50;

	printf("ft : %p\nC: %p\n", ft_memchr(string,c,n), memchr(string,c,n));
} */
