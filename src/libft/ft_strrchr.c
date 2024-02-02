/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:57:02 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:31:46 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ps;

	ps = (char *)s;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		len--;
		if (ps[len] == (char) c)
			return (&ps[len]);
	}
	return (NULL);
}
