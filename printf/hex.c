/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/06/09 15:45:34 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(size_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(int num, int cse)
{
	int				ret;
	unsigned int	unum;
	int				aux;

	unum = (unsigned int) num;
	ret = ft_hexlen(unum);
	if (unum >= 16)
	{
		aux = ft_puthex (unum / 16, cse);
		if (aux == -1)
			return (-1);
		unum = unum % 16;
	}
	if (unum <= 9)
	{
		if (ft_putchar_fd (unum + 48, 1) == -1)
			return (-1);
	}
	else if (unum > 9 && unum < 16 && cse == 1)
		aux = ft_putchar_fd (unum + 55, 1);
	else if (unum > 9 && unum < 16 && cse == 0)
		aux = ft_putchar_fd (unum + 87, 1);
	if (aux == -1)
		return (-1);
	return (ret);
}

int	ft_puthexadd(size_t num, int cse)
{
	int	ret;
	int	aux;

	ret = ft_hexlen(num);
	aux = 0;
	if (num >= 16)
	{
		ft_puthexadd (num / 16, cse);
		ft_puthexadd (num % 16, cse);
	}
	if (num <= 9)
	{
		aux = ft_putchar_fd (num + 48, 1);
		if (aux == -1)
			return (-1);
	}
	else if (num > 9 && num < 16 && cse == 1)
		aux = ft_putchar_fd (num + 55, 1);
	else if (num > 9 && num < 16 && cse == 0)
		aux = ft_putchar_fd (num + 87, 1);
	if (aux == -1)
		return (-1);
	return (ret);
}

int	ft_put_add(size_t ad)
{
	int	ret;

	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	ret = ft_puthexadd(ad, 0);
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
