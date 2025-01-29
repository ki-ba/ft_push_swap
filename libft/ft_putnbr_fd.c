/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:07 by kbarru            #+#    #+#             */
/*   Updated: 2024/11/15 13:35:16 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			nb *= (-1);
			ft_putchar_fd('-', fd);
		}
		if (nb < 10)
			ft_putchar_fd(nb + 48, fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + 48, fd);
		}
	}
}
/* int	main(void)
{
	// ft_putnbr_fd(2147483647, 1);
	// ft_putnbr_fd(-2147483648, 1);
	// ft_putnbr_fd(-0, 1);
	// ft_putnbr_fd(15, 1);
} */
