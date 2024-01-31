/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impresora.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:15:11 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/02 11:29:26 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isvar(const char c)
{
	int		j;
	char	*varset;

	varset = "cspdiuxX%";
	j = 0;
	while (varset[j] != 0)
	{
		if (c == varset[j])
			return (1);
		j++;
	}
	return (0);
}

int	porc(char id, va_list varg)
{
	int		ret;

	ret = 0;
	if (id == 'c')
		ret = int_putchar_fd((char) va_arg(varg, int), 1);
	else if (id == 's')
		ret = int_putstr_fd(va_arg(varg, char *), 1);
	else if (id == 'p')
		ret = ft_put_add(va_arg(varg, size_t));
	else if (id == 'd')
		ret = int_putnbr_fd(va_arg(varg, int), 1);
	else if (id == 'i')
		ret = int_putnbr_fd(va_arg(varg, int), 1);
	else if (id == 'u')
		ret = ft_putuns(va_arg(varg, unsigned int));
	else if (id == 'x')
		ret = ft_puthex(va_arg(varg, int), MINUS);
	else if (id == 'X')
		ret = ft_puthex(va_arg(varg, int), MAYUS);
	else if (id == '%')
		ret = int_putchar_fd ('%', 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		i;
	int		aux;
	int		ret;

	va_start(var, str);
	i = 0;
	ret = 0;
	while (str[i] != 0)
	{
		if (str[i] == 37 && isvar(str[++i]) == 1)
		{
			aux = porc(str[i++], var);
			if (aux == -1)
				return (-1);
			ret += aux - 2;
		}
		else if (str[i] != 37)
			if (int_putchar_fd(str[i++], 1) == -1)
				return (-1);
	}
	va_end (var);
	return (i + ret);
}
