/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:35:54 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/09 12:28:31 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return ;
}
/*
int	main(void)
{
	char b[] = "jfklasjdkfljkljkl";
	size_t len = 5; 
	printf("1 is %s\n", bzero(b, len));
	printf("2 is %s", ft_bzero(b, len));
	return (0);
}//*/