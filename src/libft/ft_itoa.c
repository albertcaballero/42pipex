/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:27:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:13:02 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	neg = (n < 0);
	if (neg == 1)
		nb *= -1;
	count = ft_cntline(nb);
	str = malloc ((sizeof(char) * count) + 1 + neg);
	if (str == NULL)
		return (NULL);
	str[count + neg] = 0;
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
