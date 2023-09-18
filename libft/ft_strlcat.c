/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:10:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 17:10:16 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	minlen(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	app;
	size_t	aux;

	i = minlen(dst, dstsize);
	aux = i;
	j = 0;
	app = dstsize - i - 1;
	while (j < app && src[j] != '\0' && aux < dstsize)
	{
		dst[i] = (char) src[j];
		i++;
		j++;
	}
	if (j > 0)
		dst[i] = '\0';
	return (aux + ft_strlen(src));
}
/*
int	main(void)
{
	char dst[30] = "CCCCC";
	char src[] = "AAAAAAAAA";
	size_t dstsize = 15;

	printf("Y is %lu\n", ft_strlcat(dst, src, -1));
	ft_strlcat (dst, src, -1);
	printf("%s", dst);
//	printf("O is %s %lu\n", dst, strlcat(dst, src, -1));
	return (0);
}//*/