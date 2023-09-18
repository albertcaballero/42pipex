/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:27:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/25 15:21:57 by alcaball         ###   ########.fr       */
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

int	ft_cntline(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	aux;
	long	nb;
	int		count;
	int		neg;

	nb = (long) n;
	neg = ft_isneg(nb);
	if (neg == 1)
		nb *= -1;
	count = ft_cntline(nb);
	str = malloc ((sizeof(char) * count) + 1 + neg);
	if (str == NULL)
		return (str);
	str[count + neg] = '\0';
	if (neg == 1)
		str[0] = '-';
	while (count > 0)
	{
		count--;
		aux = nb % 10;
		nb /= 10;
		str[count + neg] = aux + 48;
	}
	return (str);
}
/*
int	main(void)
{
	int n = 0;
	printf("num %d\n", n);
	printf("str %s", ft_itoa(n));
	return (0);
}//*/