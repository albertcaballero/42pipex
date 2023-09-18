/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:30:18 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 17:10:55 by alcaball         ###   ########.fr       */
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
/*
int	main(void)
{
	char dst[] = "unistd.io";
	char src[] = "string.h";
	size_t dstsize = 70;
	//ft_strlcpy(dst, src, dstsize);
	// strlcpy(dst, src, dstsize);
	printf("orig is %s %lu\n", dst, strlcpy(dst, src, dstsize));
	printf("mine is %s %lu", dst, ft_strlcpy(dst, src, dstsize));
	return (0);
}//*/
