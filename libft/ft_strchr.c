/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:40:49 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/25 13:44:11 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *) s;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&ps[i]);
		i++;
	}
	if ((char) c == 0)
		return (&ps[i]);
	return (0);
}
/*
int	main(void)
{
	const char *s = "abcdef";
	int c = 99;
	printf("1 is %s\n", strchr(s, c));
	printf("2 is %s", ft_strchr(s, c));
	return (0);
}//*/