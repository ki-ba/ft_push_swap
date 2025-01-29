/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:05:55 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 08:29:08 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*s3;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s3)
		return (0);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		++i;
	}
	i = 0;
	while (i < s2_len)
	{
		s3[s1_len + i] = s2[i];
		++i;
	}
	s3[s1_len + i] = '\0';
	return (s3);
}
/* #include <stdio.h>

int main(void)
{
	//printf("%zu\n%zu\n%zu\n%zu\n%zu", ft_strlen("Hello, World!"),
		ft_strlen("Hello\0Hidden\0"), ft_strlen("\2"), ft_strlen(""),
		ft_strlen("Hello"));
	char *s1 = "Hello, ";
	char *s2 = "World!";

	char *s3 = ft_strjoin(s1,s2);
	printf("%s\n%s\n%s",s1,s2,s3);
} */
