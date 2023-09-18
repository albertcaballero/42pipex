/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:17:29 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/10 11:58:05 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	while ((i < n) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned int	n = 80;
	char s1[] = "\300";
	char s2[] = "\0";
	printf("original is %d\n", strncmp(s1, s2, n));
	printf("yours is %d", ft_strncmp(s1, s2, n));
	
}//*/
