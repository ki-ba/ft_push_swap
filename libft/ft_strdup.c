/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:32:10 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/14 09:44:13 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	size;

	size = (ft_strlen(s)+1) * (sizeof(char));
	dup = malloc(size);
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, size);
	return (dup);
}
// int	main(void)
// {
// 	char	*s = "I malloc so I am.";
// 	char	*s2 = ft_strdup(s);

// 	printf("%p : %s\n%p : %s",&s,s,&s2,s2);
// }
