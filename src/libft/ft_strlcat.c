/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:10:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:42:08 by alcaball         ###   ########.fr       */
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

//hell, do not use
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
