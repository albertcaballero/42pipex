/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:46:18 by alcaball          #+#    #+#             */
/*   Updated: 2023/06/09 15:32:04 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	long	nb;
	int		neg;
	int		ret;
	int		aux;

	nb = (long) n;
	neg = ft_isneg(nb, 1);
	if (neg == 1)
		nb *= -1;
	ret = ft_isneg(nb, 2);
	if (neg == 1)
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
	if (nb > 9)
	{
		aux = ft_putuns (nb / 10);
		nb = nb % 10;
		if (aux == -1)
			return (-1);
	}
	if (nb <= 9)
		if (ft_putchar_fd(nb + '0', 1) == -1)
			return (-1);
	return (ret + neg);
}
