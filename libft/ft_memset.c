/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:04:59 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/09 12:32:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char b[7] = "";
	int	c = 49;
	size_t len = 19;
	printf("1 is %s\n", memset(b, c, len));
	printf("2 is %s", ft_memset(b, c, len));
	return (0);
}//*/
