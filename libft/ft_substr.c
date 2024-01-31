/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:13:59 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:35:32 by alcaball         ###   ########.fr       */
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
		sub[j++] = s[stt++];
	sub[j] = 0;
	return (sub);
}
