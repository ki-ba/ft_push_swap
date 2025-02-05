/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:08:59 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 11:33:00 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
		++i;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, size);
	if (size == dst_len)
		return (dst_len + src_len);
	while (i < size - dst_len - 1 && i < src_len)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// int	main(void)
// {
// 	char	src[] = " World!";
// 	char	dst[500] = "Hello,";
// 	printf("ft_strlcpy : %zu : %s\n", ft_strlcat(dst,src,sizeof(dst)), dst);
// 	char	dst2[500] = "Hello,";
// 	printf("   strlcpy : %zu : %s\n", strlcat(dst2,src,sizeof(dst2)), dst2);
// }
