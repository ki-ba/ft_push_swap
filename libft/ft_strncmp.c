/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:25:38 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 08:28:31 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i])
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		++i;
	}
	if (i < n && s2[i])
		return (-1);
	return (0);
}
/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("%d %d %d %d\n",
	ft_strncmp(0, "hello world",10),
	ft_strncmp("hello", 0,4),
	ft_strncmp(0, 0,5),
	ft_strncmp("hello", "hellz",5));
		printf("%d %d %d %d\n",
	strncmp(0, "hello world",10),
	strncmp("hello", 0,4),
	strncmp(0, 0,5),
	strncmp("hello", "hellz",5));
} */
