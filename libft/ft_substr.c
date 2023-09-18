/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:13:59 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 17:11:57 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	stt;
	size_t	j;
	char	*sub;

	j = 0;
	stt = (size_t) start;
	if (stt > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s + stt);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (j < len)
	{
		sub[j] = s[stt];
		stt++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char s[] = "hola";
	unsigned int start = 0;
	size_t len = 18446744073709551615;
//	printf("1 is %s\n", substr(s, start, len));
	printf("2 is %s", ft_substr(s, start, len));
}//*/