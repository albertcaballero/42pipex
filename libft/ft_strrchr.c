/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:57:02 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 17:11:33 by alcaball         ###   ########.fr       */
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
/*
int	main(void)
{
	const char *s = "abourno";
	int c = 97;
	printf("1 is %s\n", strrchr(s, c));
	printf("2 is %s", ft_strrchr(s, c));
	return (0);
}//*/
