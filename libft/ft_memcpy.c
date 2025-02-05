/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:56 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/12 16:41:42 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_uc;

	dest_uc = (unsigned char *)dest;
	i = 0;
	if (dest == src)
		return (0);
	while (i < n)
	{
		dest_uc[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}
