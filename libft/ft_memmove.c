/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:20 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/17 21:54:54 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if ((src < dest))
	{
		i = n - 1;
		while (i >= 0)
		{
			((unsigned char *)(dest))[i] = ((unsigned char *)(src))[i];
			--i;
		}
	}
	if (dest < src)
	{
		i = 0;
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/*  #include <stdio.h>

int	main(void)
{
	char	*src = "lorem ipum dolor sit a";
	char	*dest = "                          ";
	int	i;

	i = 0;
	if (src - dest > 0)
		printf("src is RIGHT of dest\n");
	else
		printf("src is LEFT of dest\n");
	ft_memmove(dest, src, 1);
	printf("&src = %p\n&dest = %p\n", src, dest);

		printf("%s,", dest);

} */
