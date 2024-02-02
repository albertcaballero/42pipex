/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:30:18 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:23:12 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	i = 0;
	pdst = (char *) dst;
	psrc = (char *) src;
	if (dstsize == 0)
		return (ft_strlen(src));
	dstsize--;
	while (i < dstsize && psrc[i] != '\0')
	{
		pdst[i] = psrc[i];
		i++;
	}
	pdst[i] = '\0';
	return (ft_strlen(src));
}
