/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:55:27 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 11:34:03 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(long n)
{
	int	neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	return (neg);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		neg;

	nb = (long) n;
	neg = ft_isneg(nb);
	if (neg == 1)
		nb *= -1;
	if (neg == 1)
		ft_putchar_fd('-', fd);
	if (nb > 9)
	{
		ft_putnbr_fd (nb / 10, fd);
		ft_putnbr_fd (nb % 10, fd);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	return ;
}
