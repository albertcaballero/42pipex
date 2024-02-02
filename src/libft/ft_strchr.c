/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:40:49 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:20:35 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds a char inside a str and returns the pointer to the str at that char
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
