/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:35:21 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/13 18:35:21 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	while (i < size - 1 && i < src_len)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char	src[] = "lorem ipsum";
// 	char	dst[500] = "Hello";
// 	printf("ft_strlcpy : %zu : %s\n", ft_strlcpy(dst,src,0), dst);
// 	char	dst2[500] = "Hello";
// 	printf("   strlcpy : %zu : %s\n", strlcpy(dst2,src,0), dst2);
// }
