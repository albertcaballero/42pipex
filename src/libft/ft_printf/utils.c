/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:52:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/02 11:30:29 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	int_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen((const char *) s)));
}

int	ft_isneg(long n, int flag)
{
	int	neg;
	int	len;

	neg = 0;
	len = 0;
	if (flag == 1)
	{
		if (n < 0)
			neg = 1;
		return (neg);
	}
	if (flag == 2)
	{
		if (n == 0)
			return (1);
		while (n > 0)
		{
			n /= 10;
			len++;
		}
		return (len);
	}
	return (0);
}

int	int_putnbr_fd(int n, int fd)
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
		if (int_putchar_fd('-', fd) == -1)
			return (-1);
	if (nb > 9)
	{
		aux = int_putnbr_fd (nb / 10, fd);
		nb = nb % 10;
		if (aux == -1)
			return (-1);
	}
	if (nb <= 9)
		if (int_putchar_fd(nb + '0', fd) == -1)
			return (-1);
	return (ret + neg);
}
