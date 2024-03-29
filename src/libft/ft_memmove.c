/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:38:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:13:47 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *) dst + len - 1) = *((char *) src + len - 1);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *) dst + i) = *((char *) src + i);
			i++;
		}
	}
	return (dst);
}
